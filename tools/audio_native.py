"""Reachable compact-MIDI semantics, independent of first-pass byte boundaries.

``to_interchange`` materializes the first pass, a stable repeated pass, and the
reachable finite tail. ``semantic_trace`` instead executes the original mutable
stream. Its dictionaries contain tick/track and native channel or tempo fields;
NoteOn durations describe release scheduling origins, not generated NoteOffs.
"""
import struct
import heapq
from collections import deque

from audio_seq import _Reader, _read_event


def _header(data):
    if len(data) < 68:
        raise ValueError('compact MIDI header requires 68 bytes')
    division = struct.unpack_from('>I', data, 64)[0]
    if not division:
        raise ValueError('compact MIDI division must be positive')
    offsets = struct.unpack_from('>16I', data)
    for index, offset in enumerate(offsets):
        if offset and not 0 <= offset < len(data):
            raise ValueError(f'track {index}: entrypoint outside sequence')
    return division, offsets


class _NativeReader(_Reader):
    """Keep backup *addresses*: SDK backup reads observe mutable source bytes."""
    def __init__(self, data, offset):
        super().__init__(data, offset, set())
        self.back = deque()
        self.reads = set()
        self.pending_delta = None
        self.observations = None
        self.stamp = None

    def observe(self, offset, value):
        self.reads.add(offset)
        if self.observations is not None:
            self.observations.append((self.stamp, offset, value))

    def raw(self):
        if not 0 <= self.pos < len(self.data):
            raise ValueError('track exceeds sequence')
        self.observe(self.pos, self.data[self.pos])
        return super().raw()

    def byte(self):
        if self.back:
            offset = self.back.popleft()
            value = self.data[offset]
            self.observe(offset, value)
            self.logical += 1
            return value
        start, logical = self.pos, self.logical
        value = self.raw()
        if value != 254:
            return value
        high = self.raw()
        if high == 254:
            self.logical = logical + 1
            return 254
        low, length = self.raw(), self.raw()
        target = start - ((high << 8) | low)
        if not length or target < 0 or target + length > len(self.data):
            raise ValueError('invalid physical backreference')
        self.back.extend(range(target, target + length))
        self.logical = logical
        return self.byte()

    def vlq(self):
        if self.pending_delta is not None:
            result, self.pending_delta = self.pending_delta, None
            return result
        return super().vlq()


class _Track:
    def __init__(self, data, index, offset, *, observe=False):
        self.index = index
        self.reader = _NativeReader(data, offset)
        self.status = 0
        self.tick = 0
        self.writes = set()
        self.order = 0
        self.write_observations = []
        self.periodic_reads = []
        self.period = None
        if observe:
            self.reader.observations = []
        self.done = False
        self.delta = None
        self.delta_position = None

    def read(self):
        self.reader.stamp = (self.tick, 1, self.index, self.order + 1, 0)
        try:
            event, self.status = _read_event(self.reader, self.status, include_positions=True)
        except ValueError as error:
            raise ValueError(f'track {self.index}: {error}') from error
        self.order += 1
        return event

    def control(self, event):
        """Apply LOOPEND after reading it; do not invent a backup-buffer reset."""
        offset = event['loop_state_offset']
        current = event['current']
        value = event['count'] if current == 0 else current - 1 if current != 255 else 255
        if value != self.reader.data[offset]:
            self.reader.data[offset] = value
            self.writes.add(offset)
            if self.reader.observations is not None:
                self.write_observations.append(((self.tick, 1, self.index, self.order, 1), offset, value))
        if current:
            target = event['target']
            if not 0 <= target < len(self.reader.data):
                raise ValueError(f'track {self.index}: reachable loop target outside sequence')
            self.reader.pos = target
        return bool(current)

    def prime(self):
        self.reader.stamp = ((0, 0, self.index, 0, 0) if not self.order
                             else (self.tick, 1, self.index, self.order, 2))
        self.delta_position = None if self.reader.back else self.reader.pos
        try:
            self.delta = self.reader.vlq()
        except ValueError as error:
            raise ValueError(f'track {self.index}: {error}') from error
        self.tick += self.delta['value']

    def due(self):
        self.reader.pending_delta = self.delta
        event = self.read()
        event['physical_offset'] = self.delta_position
        if event['kind'] == 'loop_end':
            self.control(event)
        elif event['kind'] == 'end':
            self.done = True
        if not self.done:
            self.prime()
        return event

    def position(self):
        return self.reader.pos, tuple(self.reader.back), self.status


def _musical(event):
    kind = event['kind']
    if kind == 'channel':
        result = {'kind': kind, 'status': event['status'], 'parameters': list(event['parameters'])}
        if event['status'] & 240 == 144:
            result['duration'] = {'value': event['duration']['value']}
        return result
    if kind == 'tempo':
        if not event['microseconds_per_quarter']:
            raise ValueError('compact MIDI tempo must be positive')
        return {'kind': kind, 'microseconds_per_quarter': event['microseconds_per_quarter']}
    if kind == 'loop_start':
        return {'kind': 'native_loop_start', 'ignored': list(event['ignored'])}
    if kind == 'loop_end' and (event['current'] == 0 or event['back_offset'] == 0):
        return {'kind': 'native_loop_end', 'count': event['count'], 'current': event['current'],
                'back_offset': event['back_offset']}
    return None


def _append(events, event, tick):
    value = _musical(event)
    if value is not None:
        events.append(dict(value, tick=tick))


def _linear(track, *, terminal=None):
    """Read to EOT, the first active loop, or a particular raw LOOPEND."""
    events, tick = [], 0
    while True:
        track.prime()
        track.reader.pending_delta = track.delta
        event = track.read()
        tick += event['delta']['value']
        kind = event['kind']
        if kind == 'end':
            return events, tick, None
        if kind == 'loop_end':
            if terminal is not None and event['loop_state_offset'] == terminal:
                return events, tick, event
            if event['current']:
                if terminal is not None:
                    raise ValueError(f'track {track.index}: unsupported non-flat loop dependency at current byte {event["loop_state_offset"]}')
                return events, tick, event
            # Preserve the callback even when its jump is inert: dispatching the
            # next sequence reference after it affects equal-time release order.
            _append(events, event, tick)
            track.control(event)
        else:
            _append(events, event, tick)


def _normalize(track):
    index = track.index
    prefix, prefix_end, first = _linear(track)
    result = {'index': index, 'prefix': prefix, 'prefix_end': prefix_end,
              'loop': None, 'tail': [], 'tail_end': 0}
    if first is None:
        return result
    current, count = first['current'], first['count']
    terminal = first['loop_state_offset']
    track.control(first)
    body_reads = len(track.reader.observations)
    body, body_end, end = _linear(track, terminal=terminal)
    if end is None:
        # A jump reaching EOT without returning is not a repeat cycle. Its
        # callback remains, but the already-decoded path is emitted linearly.
        _append(prefix, dict(first, back_offset=0), prefix_end)
        prefix.extend(dict(event, tick=prefix_end + event['tick']) for event in body)
        result['prefix_end'] = prefix_end + body_end
        return result
    expected = 255 if current == 255 else current - 1
    if (end['count'], end['target'], end['current']) != (count, first['target'], expected):
        raise ValueError(f'track {index}: unsupported mutation of terminal LOOPEND fields')
    if current == 255 and not body_end:
        raise ValueError(f'track {index}: reachable zero-time infinite loop must advance ticks')
    result['loop'] = {'body': body, 'body_end': body_end, 'count': count, 'current': current}
    if current == 255:
        track.periodic_reads = track.reader.observations[body_reads:]
        track.period = body_end
        # A flat forever loop never mutates its own current byte. Any other
        # changing control in its body would become active on the next visit.
        changed = set(track.writes)
        track.control(end)
        again, again_end, again_terminal = _linear(track, terminal=terminal)
        if (again, again_end, again_terminal['count'], again_terminal['target'], again_terminal['current']) != (body, body_end, count, first['target'], 255):
            raise ValueError(f'track {index}: unsupported repeat body dependent on mutable loop state')
        if track.writes != changed:
            raise ValueError(f'track {index}: unsupported repeat mutation outside terminal counter')
        return result
    # Prove stability over every actual remaining finite counter value, rather
    # than extrapolating one decode across mutable-source reads.
    while track.control(end):
        expected -= 1
        again, again_end, end = _linear(track, terminal=terminal)
        if (again, again_end, end['count'], end['target'], end['current']) != (body, body_end, count, first['target'], expected):
            raise ValueError(f'track {index}: unsupported repeat body dependent on mutable loop state at byte {terminal}')
    tail, tail_end, another = _linear(track)
    if another is not None:
        raise ValueError(f'track {index}: unsupported additional reachable loop in finite tail')
    result['tail'], result['tail_end'] = tail, tail_end
    return result


def _check_aliases(data, states):
    """Prove cross-track byte reads match independent execution, causally.

    A shared address alone is not a dependency: readers may finish before it
    changes, or see the original value after reset. Replay only aliased byte
    observations in native dispatch order; then check periodic reads against
    each finite mutation interval without expanding arbitrarily long loops.
    """
    shared = set()
    for writer in states:
        for reader in states:
            if writer is not reader:
                shared.update(writer.writes & reader.reader.reads)
    if not shared:
        return
    observations = []
    for state in states:
        observations.extend((stamp, 0, state.index, offset, value)
                            for stamp, offset, value in state.reader.observations if offset in shared)
        observations.extend((stamp, 1, state.index, offset, value)
                            for stamp, offset, value in state.write_observations if offset in shared)
    values = {offset: data[offset] for offset in shared}
    writers = {offset: None for offset in shared}
    intervals = {offset: [(None, data[offset], None)] for offset in shared}

    def dependent(reader, offset, writer):
        raise ValueError(f'track {reader}: unsupported shared mutable loop-state dependency at byte {offset} written by track {writer}')

    for stamp, kind, index, offset, value in sorted(observations):
        if kind == 0:
            if values[offset] != value:
                dependent(index, offset, writers[offset])
        elif values[offset] != value:
            values[offset], writers[offset] = value, index
            intervals[offset].append((stamp, value, index))
    for state in states:
        for stamp, offset, expected in state.periodic_reads:
            if offset not in shared:
                continue
            changes = intervals[offset]
            for position, (start, value, writer) in enumerate(changes):
                if value == expected:
                    continue
                end = changes[position + 1][0] if position + 1 < len(changes) else None
                repeat = 0 if start is None else max(0, (start[0] - stamp[0]) // state.period)
                occurrence = (stamp[0] + repeat * state.period, *stamp[1:])
                if start is not None and occurrence < start:
                    occurrence = (occurrence[0] + state.period, *occurrence[1:])
                if end is None or occurrence < end:
                    dependent(state.index, offset, writer)


def to_interchange(data: bytes) -> dict:
    """Normalize reachable flat stable loops without relocating physical input.

    ``loop.current`` is the initial current, not the reset count and not the
    remaining count after the materialized body. Times in each block are local;
    prefix_end includes the first LOOPEND delta and body_end includes both the
    target delta and the repeated terminal delta. Infinite tails are unreachable.
    Shared bytes are rejected only when another track's mutation changes an
    observed value, including future periodic reads.
    """
    division, offsets = _header(data)
    tracks, states, errors = [], [], []
    for index, offset in enumerate(offsets):
        if offset:
            state = _Track(bytearray(data), index, offset, observe=True)
            states.append(state)
            try:
                tracks.append(_normalize(state))
            except ValueError as error:
                # An independently invalid read can itself be evidence that
                # another track supplies a required mutable byte. Preserve its
                # observations so alias diagnostics take precedence when real.
                errors.append(error)
    _check_aliases(data, states)
    if errors:
        raise errors[0]
    return {'division': division, 'tracks': tracks}


class _Execution:
    def __init__(self, data, max_ticks, max_events):
        if not isinstance(max_ticks, int) or max_ticks < 0:
            raise ValueError('max_ticks must be a nonnegative integer')
        if not isinstance(max_events, int) or max_events <= 0:
            raise ValueError('max_events must be a positive integer')
        _, offsets = _header(data)
        self.data = bytearray(data)
        self.tracks = [_Track(self.data, index, offset) for index, offset in enumerate(offsets) if offset]
        for track in self.tracks:
            track.prime()
        self.max_ticks, self.max_events = max_ticks, max_events
        self.processed, self.last_tick, self.zero_states = 0, None, set()

    def next_track(self):
        return min((track for track in self.tracks if not track.done),
                   key=lambda track: (track.tick, track.index), default=None)

    def dispatch(self, track):
        tick = track.tick
        if tick != self.last_tick:
            self.zero_states.clear()
            self.last_tick = tick
        changed = set().union(*(item.writes for item in self.tracks))
        state = (tuple((item.index, item.tick, item.position(), item.delta['value'])
                       for item in self.tracks if not item.done),
                 tuple((offset, self.data[offset]) for offset in sorted(changed)))
        if state in self.zero_states:
            raise ValueError(f'track {track.index}: reachable zero-time infinite cycle must advance ticks')
        self.zero_states.add(state)
        if self.processed >= self.max_events:
            raise ValueError('native semantic trace exceeds max_events limit')
        self.processed += 1
        return track.due()


def semantic_trace(data, *, max_ticks: int, max_events: int = 100000) -> list:
    """Execute native events through inclusive ``max_ticks`` in CSeq order.

    Return dictionaries ``{tick,track,kind,status,parameters,duration}`` for
    channel events (duration is an integer on NoteOn only), or
    ``{tick,track,kind,microseconds_per_quarter}`` for tempos. No controls, EOT,
    or generated releases are emitted. Native durations, including zero, remain
    scheduling origins for the caller's player/lifetime oracle. ``max_events``
    bounds all executed events, including controls; exceeding it raises.
    """
    execution = _Execution(data, max_ticks, max_events)
    trace = []
    while True:
        track = execution.next_track()
        if track is None or track.tick > max_ticks:
            return trace
        tick = track.tick
        event = execution.dispatch(track)
        if event['kind'] in ('channel', 'tempo'):
            value = _musical(event)
            if 'duration' in value:
                value['duration'] = value['duration']['value']
            trace.append(dict(value, tick=tick, track=track.index))


def note_lifetimes(data, *, max_ticks: int, max_events: int = 100000) -> list:
    """Logical-tick release-onset oracle: sorted (channel,key,on_tick,off_tick).

    Model one outstanding SEQ reference, native control callbacks, FIFO
    equal-time queue insertion, oldest eligible key/channel voice lookup, and
    sustain. Positive NoteOn durations post independent releases; zero posts
    none. Releases survive jumps and EOT. Tempo changes keep remaining logical
    tick deadlines but reproduce the SDK's temporary-list repost order.

    This deliberately measures release *onset*, not bank-dependent envelope
    completion, voice allocation limits, or microsecond rounding. Voices still
    sounding at the inclusive horizon do not produce a completed lifetime.
    ``max_events`` bounds sequence/control and duration-release dispatches.
    """
    execution = _Execution(data, max_ticks, max_events)
    queue, serial, dispatched = [], 0, 0
    active, held, pedal, result = {}, {}, {}, []

    def post(tick, kind, payload):
        nonlocal serial
        heapq.heappush(queue, (tick, serial, kind, payload))
        serial += 1

    def next_sequence():
        track = execution.next_track()
        if track is not None:
            post(track.tick, 'sequence', None)

    def release(channel, key, tick):
        voices = active.get((channel, key))
        if not voices:
            return
        start = voices.popleft()
        if pedal.get(channel, False):
            held.setdefault(channel, []).append((start, key))
        else:
            result.append((channel, key, start, tick))

    next_sequence()
    while queue:
        tick, _, kind, payload = heapq.heappop(queue)
        if tick > max_ticks:
            break
        if dispatched >= max_events:
            raise ValueError('native lifetime oracle exceeds max_events limit')
        dispatched += 1
        if kind == 'release':
            release(*payload, tick)
            continue
        track = execution.next_track()
        event = execution.dispatch(track)
        if event['kind'] == 'channel':
            status, params = event['status'], event['parameters']
            channel, message = status & 15, status & 240
            if message == 144 and params[1]:
                active.setdefault((channel, params[0]), deque()).append(tick)
                duration = event['duration']['value']
                if duration:
                    post(tick + duration, 'release', (channel, params[0]))
            elif message == 128 or (message == 144 and not params[1]):
                release(channel, params[0], tick)
            elif message == 176 and params[0] == 64:
                pedal[channel] = params[1] >= 64
                if not pedal[channel]:
                    result.extend((channel, key, start, tick)
                                  for start, key in held.pop(channel, []))
        elif event['kind'] == 'tempo':
            _musical(event)
            # SDK removal keeps the first timer at the temporary-list head,
            # inserts later timers behind it, then reposts that resulting list.
            timers = sorted(queue)
            queue.clear()
            if timers:
                for deadline, _, timer_kind, timer_payload in [timers[0], *reversed(timers[1:])]:
                    post(deadline, timer_kind, timer_payload)
        next_sequence()
    return sorted(result)
