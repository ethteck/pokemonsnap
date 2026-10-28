"""Standard MIDI interchange for the SDK's sixteen-track compact sequences."""
import re
import struct
from collections import defaultdict, deque

import mido

from audio_seq import _vlq
from audio_native import to_interchange
from audio_midi_hints import from_midi, to_midi

_SLOT = re.compile(r'cseq_track_(\d{2})\Z')
_IGNORED_META = {'track_name', 'instrument_name', 'text', 'copyright', 'lyrics',
                 'cue_marker', 'time_signature', 'key_signature', 'channel_prefix',
                 'midi_port', 'sequence_number'}


def _track_bytes(events):
    out = bytearray()
    previous = 0
    status = None
    loop = None
    for tick, event in events:
        def escaped(payload):
            out.extend(payload.replace(b'\xfe', b'\xfe\xfe'))
        escaped(_vlq(tick - previous))
        previous = tick
        kind = event['kind']
        if kind == 'channel':
            new = event['status']
            if new != status:
                escaped(bytes([new]))
            escaped(bytes(event['parameters']))
            if new & 240 == 144:
                escaped(_vlq(event['duration']))
            status = new
        else:
            status = None
            if kind == 'tempo':
                escaped(b'\xff\x51' + event['tempo'].to_bytes(3, 'big'))
            elif kind == 'end':
                escaped(b'\xff\x2f')
            elif kind == 'native_loop_start':
                escaped(b'\xff\x2e' + bytes(event['ignored']))
            elif kind == 'native_loop_end':
                if event['current'] and event['back_offset']:
                    raise ValueError('standalone native loop control must be inert')
                escaped(b'\xff\x2d')
                out.extend(bytes([event['count'], event['current']]))
                out.extend(struct.pack('>I', event['back_offset']))
            elif kind == 'loop_start':
                if loop is not None:
                    raise ValueError('nested compact loops are unsupported')
                escaped(b'\xff\x2e\x00\x00')
                loop = (len(out), tick)
            elif kind == 'loop_end':
                if loop is None:
                    raise ValueError('loop_end without loop_start')
                escaped(b'\xff\x2d')
                count, current = event['count'], event['current']
                if current == 255 and tick == loop[1]:
                    raise ValueError('infinite compact loop must advance ticks')
                out.extend(bytes([count, current]))
                out.extend(struct.pack('>I', len(out) + 4 - loop[0]))
                loop = None
            else:
                raise ValueError(f'unsupported compact event {kind!r}')
    if loop is not None:
        raise ValueError('loop_start without loop_end')
    return bytes(out)


def _compact_file(tracks, division):
    offsets = [0] * 16
    payload = bytearray()
    for slot, (events, end) in sorted(tracks.items()):
        offsets[slot] = 68 + len(payload)
        ordered = list(events)
        ordered.append((end, {'kind': 'end'}))
        payload.extend(_track_bytes(ordered))
    return struct.pack('>16II', *offsets, division) + payload


def import_midi(source):
    """Return compact bytes; source is a filename or a Mido MidiFile."""
    midi = source if isinstance(source, mido.MidiFile) else mido.MidiFile(source)
    if midi.type not in (0, 1) or not 0 < midi.ticks_per_beat <= 32767:
        raise ValueError('only synchronous Type 0/1 MIDI with PPQN timing is supported')
    if midi.type == 0 and len(midi.tracks) != 1:
        raise ValueError('Type 0 MIDI requires one track')
    hinted = from_midi(midi)
    if hinted is not None:
        tracks = {slot: (events, end) for slot, events, end in hinted}
        return _compact_file(tracks, midi.ticks_per_beat)
    parsed = []
    active = defaultdict(deque)
    ends = []
    serial = 0
    for track_id, track in enumerate(midi.tracks):
        tick = 0
        events = []
        slot = None
        for msg in track:
            if not isinstance(msg.time, int) or msg.time < 0:
                raise ValueError('MIDI deltas must be nonnegative integer ticks')
            tick += msg.time
            serial += 1
            if msg.is_meta:
                if msg.type == 'track_name':
                    match = _SLOT.fullmatch(msg.name)
                    if match:
                        named = int(match[1])
                        if named >= 16 or (slot is not None and slot != named):
                            raise ValueError('invalid or conflicting compact track slot')
                        slot = named
                elif msg.type == 'set_tempo':
                    if msg.tempo <= 0:
                        raise ValueError('MIDI tempo must be positive')
                    events.append((tick, serial, {'kind': 'tempo', 'tempo': msg.tempo}))
                elif msg.type == 'marker':
                    if msg.text == 'loop_start':
                        events.append((tick, serial, {'kind': 'loop_start'}))
                    elif msg.text == 'loop_end' or msg.text.startswith('loop_end:'):
                        fields = msg.text.split(':')
                        if len(fields) > 3:
                            raise ValueError('loop_end accepts count and optional current count')
                        count = 255 if len(fields) == 1 else int(fields[1])
                        current = count if len(fields) < 3 else int(fields[2])
                        if not 0 <= count <= 255 or not 0 <= current <= 255:
                            raise ValueError('loop count outside byte range')
                        events.append((tick, serial, {'kind': 'loop_end',
                                                    'count': count, 'current': current}))
                    else:
                        raise ValueError(f'unsupported MIDI marker {msg.text!r}')
                elif msg.type != 'end_of_track' and msg.type not in _IGNORED_META:
                    raise ValueError(f'unsupported MIDI meta event {msg.type}')
                continue
            if not hasattr(msg, 'channel'):
                raise ValueError(f'unsupported MIDI system event {msg.type}')
            key = (msg.channel, getattr(msg, 'note', None))
            if msg.type == 'note_off' or (msg.type == 'note_on' and msg.velocity == 0):
                # Pairing is global across synchronous tracks, in absolute-time order below.
                events.append((tick, serial, {'kind': 'off', 'key': key,
                                            'velocity': msg.velocity}))
            else:
                raw = msg.bytes()
                event = {'kind': 'channel', 'status': raw[0], 'parameters': raw[1:]}
                if msg.type == 'note_on':
                    event['key'] = key
                    event['duration'] = None
                events.append((tick, serial, event))
        parsed.append((slot, events))
        ends.append(tick)
    regions = {}
    for source_index, (_, events) in enumerate(parsed):
        start, loops = None, []
        for _, order, event in events:
            if event['kind'] == 'loop_start':
                start = order
            elif event['kind'] == 'loop_end' and start is not None:
                if event['current']:
                    loops.append((start, order, event['current']))
                start = None
        for _, order, _ in events:
            body = next(((source_index, first) for first, last, _ in loops
                         if first < order < last), None)
            unreachable = any(current == 255 and order > last for _, last, current in loops)
            regions[order] = body, unreachable
    for tick, order, event in sorted(item for _, events in parsed for item in events):
        if event['kind'] == 'off':
            queue = active[event['key']]
            if not queue:
                raise ValueError('unpaired MIDI note-off')
            _, on_order, note = queue.popleft()
            if regions[on_order] != regions[order]:
                raise ValueError('notes crossing active compact loop boundaries require native duration hints')
            # Duration-scheduled releases enter the SDK queue at note-on time,
            # ahead of later same-tick pedal/controllers. Preserve source order
            # with explicit releases; duration zero means no automatic release.
            note['duration'] = 0
            event.update(kind='channel', status=0x80 | event['key'][0],
                         parameters=[event['key'][1], event['velocity']])
        elif 'duration' in event:
            active[event['key']].append((tick, order, event))
    if any(active.values()):
        raise ValueError('MIDI note-on has no matching note-off')
    tracks = {}
    pending = []
    tempos = []
    conductor_end = 0
    source_slots = {}
    for source_index, ((slot, events), end) in enumerate(zip(parsed, ends)):
        if slot is None and all(item[2]['kind'] == 'tempo' for item in events):
            tempos.extend(events)
            conductor_end = max(conductor_end, end)
            continue
        if not events and slot is None:
            continue
        if slot is None:
            pending.append((events, end, source_index))
        else:
            if slot in tracks:
                raise ValueError('duplicate compact track slot')
            tracks[slot] = (events, end)
            source_slots[source_index] = slot
    for events, end, source_index in pending:
        slot = next((i for i in range(16) if i not in tracks), None)
        if slot is None:
            raise ValueError('MIDI requires more than sixteen playable tracks')
        tracks[slot] = (events, end)
        source_slots[source_index] = slot
    # Pinning a later source track into an earlier compact slot must not
    # silently reverse simultaneous events on a shared MIDI channel.
    simultaneous = {}
    for tick, order, channel, slot in sorted(
            (tick, order, event['status'] & 15, source_slots[index])
            for index, (_, events) in enumerate(parsed) if index in source_slots
            for tick, order, event in events if event['kind'] == 'channel'):
        key = tick, channel
        if key in simultaneous and slot < simultaneous[key]:
            raise ValueError('compact slot names conflict with source-order simultaneous channel events')
        simultaneous[key] = slot
    if not tracks:
        tracks[0] = ([], max(ends, default=0))
    if tempos:
        candidates = [slot for slot, (events, _) in tracks.items()
                      if not any(event['kind'].startswith('loop_') for _, _, event in events)]
        if candidates:
            tempo_slot = min(candidates)
        elif all(tick == 0 for tick, _, _ in tempos):
            tempo_slot = min(tracks)
        else:
            tempo_slot = next((i for i in range(16) if i not in tracks), None)
            if tempo_slot is None:
                raise ValueError('conductor tempo changes require a non-looping compact track')
            tracks[tempo_slot] = ([], conductor_end)
        events, end = tracks[tempo_slot]
        # A tick-zero conductor must be outside any musical loop, even when
        # its source track followed the music track in the MIDI file.
        events.extend((tick, -len(tempos) + i, event) if tick == 0
                      else (tick, order, event)
                      for i, (tick, order, event) in enumerate(tempos))
        tracks[tempo_slot] = (events, max(end, conductor_end))
    first = min(tracks)
    events, end = tracks[first]
    if not any(tick == 0 and event['kind'] == 'tempo'
               for events, _ in tracks.values() for tick, _, event in events):
        events.append((0, -1, {'kind': 'tempo', 'tempo': 500000}))
    tracks[first] = (events, max(end, max(ends, default=0)))
    return _compact_file(
        {slot: ([(tick, event) for tick, _, event in sorted(events)], end)
         for slot, (events, end) in tracks.items()},
        midi.ticks_per_beat,
    )


def export_midi(data):
    """Return a DAW-readable preview with validated native timing hints."""
    return to_midi(to_interchange(data))


def main():
    import argparse
    from pathlib import Path
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=['import', 'export'])
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    args.output.parent.mkdir(parents=True, exist_ok=True)
    if args.command == 'import':
        args.output.write_bytes(import_midi(args.input))
    else:
        export_midi(args.input.read_bytes()).save(args.output)


if __name__ == '__main__':
    main()
