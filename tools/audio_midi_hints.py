"""Editable Type 1 previews with protected, versioned native CSeq semantics.

Players hear one linearized pass, not executable SDK loops. SNAP_NATIVE\0 JSON
sequencer-specific records and snap_native_v1_cseq_track_NN names must survive
editing for native reconstruction. Bindings identify scheduling origins, never
voices; visible MIDI channel data and loop markers remain the source of truth.
"""
import json
import re

import mido

_MAGIC = b'SNAP_NATIVE\x00'
_VERSION = 1
_NAME = re.compile(r'snap_native_v1_cseq_track_(\d{2})\Z')
_MAX_DELTA = 0x0FFFFFFF
_IGNORED_META = {'track_name', 'instrument_name', 'text', 'copyright', 'lyrics',
                 'cue_marker', 'time_signature', 'key_signature', 'channel_prefix',
                 'midi_port', 'sequence_number', 'device_name'}


def _integer(value, name, maximum=None):
    if type(value) is not int or value < 0 or (maximum is not None and value > maximum):
        raise ValueError(f'invalid native {name}')
    return value


def _fields(record, *names):
    if set(record) != {'v', 'type', *names}:
        raise ValueError(f'invalid native {record.get("type", "hint")} fields')


def _hint(record_type, **fields):
    data = _MAGIC + json.dumps({'v': _VERSION, 'type': record_type, **fields},
                              separators=(',', ':'), sort_keys=True).encode('ascii')
    return mido.MetaMessage('sequencer_specific', data=data)


def _is_hint(msg):
    return (msg.is_meta and msg.type == 'sequencer_specific'
            and bytes(msg.data).startswith(b'SNAP_NATIVE'))


def _unique_object(items):
    result = {}
    for key, value in items:
        if key in result:
            raise ValueError('duplicate native hint JSON field')
        result[key] = value
    return result


def _parse_hint(msg):
    data = bytes(msg.data)
    if not data.startswith(_MAGIC):
        raise ValueError('malformed native hint prefix')
    try:
        record = json.loads(data[len(_MAGIC):].decode('ascii'), object_pairs_hook=_unique_object)
    except (UnicodeError, json.JSONDecodeError) as exc:
        raise ValueError('malformed native hint JSON') from exc
    if not isinstance(record, dict) or type(record.get('v')) is not int or record['v'] != _VERSION:
        raise ValueError('unsupported native hint version')
    if not isinstance(record.get('type'), str):
        raise ValueError('missing native hint type')
    return record


def _ids(value, name):
    if not isinstance(value, list) or any(not isinstance(item, str) or not item for item in value):
        raise ValueError(f'invalid native {name} IDs')
    if len(set(value)) != len(value):
        raise ValueError(f'duplicate native {name} IDs')
    return set(value)


def _control(record):
    kind = record['kind']
    if kind == 'native_loop_start':
        ignored = record.get('ignored')
        if not isinstance(ignored, list) or len(ignored) != 2:
            raise ValueError('native LOOPSTART requires two ignored bytes')
        return {'kind': kind, 'ignored': [_integer(item, 'LOOPSTART byte', 255) for item in ignored]}
    if kind == 'native_loop_end':
        count = _integer(record.get('count'), 'LOOPEND count', 255)
        current = _integer(record.get('current'), 'LOOPEND current', 255)
        back_offset = _integer(record.get('back_offset'), 'LOOPEND back offset', 0xFFFFFFFF)
        if current and back_offset:
            raise ValueError('native passthrough LOOPEND must be inert or have a zero back offset')
        return {'kind': kind, 'count': count, 'current': current, 'back_offset': back_offset}
    raise ValueError(f'unsupported native control {kind!r}')


def _block(events, end, offset):
    if not isinstance(events, list):
        raise ValueError('native block events must be a list')
    result = []
    previous = 0
    for event in events:
        if not isinstance(event, dict):
            raise ValueError('invalid native event')
        tick = _integer(event.get('tick'), 'event tick')
        if tick < previous or tick > end:
            raise ValueError('native block events lie outside their ordered timing bounds')
        result.append((offset + tick, event))
        previous = tick
    return result


def _flatten(source):
    prefix_end = _integer(source.get('prefix_end'), 'prefix end')
    result = _block(source.get('prefix'), prefix_end, 0)
    tail_end = _integer(source.get('tail_end'), 'tail end')
    loop = source.get('loop')
    if loop is None:
        if source.get('tail') or tail_end:
            raise ValueError('non-looping native track cannot have a tail')
        return result, prefix_end
    if not isinstance(loop, dict):
        raise ValueError('invalid native loop')
    body_end = _integer(loop.get('body_end'), 'loop period')
    count = _integer(loop.get('count'), 'loop count', 255)
    current = _integer(loop.get('current'), 'loop current', 255)
    if not current:
        raise ValueError('active native loop requires a nonzero current count')
    if current == 255 and not body_end:
        raise ValueError('infinite native loop must advance ticks')
    result.append((prefix_end, {'kind': 'loop_start'}))
    result.extend(_block(loop.get('body'), body_end, prefix_end))
    exit_tick = prefix_end + body_end
    result.append((exit_tick, {'kind': 'loop_end', 'count': count,
                               'current': 255 if current == 255 else current - 1}))
    if current == 255:
        if source.get('tail') or tail_end:
            raise ValueError('infinite native loop has no reachable tail')
        return result, exit_tick
    result.extend(_block(source.get('tail'), tail_end, exit_tick))
    return result, exit_tick + tail_end


def _channel(event):
    status = _integer(event.get('status'), 'channel status', 239)
    if status < 128:
        raise ValueError('invalid native channel status')
    params = event.get('parameters')
    size = 1 if status & 240 in (192, 208) else 2
    if not isinstance(params, list) or len(params) != size:
        raise ValueError('invalid native channel parameters')
    raw = [status, *[_integer(item, 'channel parameter', 127) for item in params]]
    return mido.Message.from_bytes(raw)


def _duration(event):
    duration = event.get('duration')
    if isinstance(duration, dict):
        duration = duration.get('value')
    return _integer(duration, 'note duration', 0xFFFFFFFF)


def _append(track, messages, tick, previous):
    # Standard MIDI limits each delta to four VLQ bytes, unlike native u32 VLQs.
    delta = tick - previous
    while delta > _MAX_DELTA:
        track.append(mido.MetaMessage('text', text='', time=_MAX_DELTA))
        delta -= _MAX_DELTA
    for msg in messages:
        track.append(msg.copy(time=delta))
        delta = 0
    return tick


def to_midi(interchange):
    """Return a DAW-readable one-pass preview, preserving editable native hints."""
    division = _integer(interchange.get('division'), 'PPQN division', 32767)
    if not division:
        raise ValueError('native division must be positive MIDI PPQN')
    sources = interchange.get('tracks')
    if not isinstance(sources, list) or not sources:
        raise ValueError('native MIDI preview requires at least one track')
    slots = [_integer(source.get('index'), 'track slot', 15) for source in sources]
    if len(set(slots)) != len(slots):
        raise ValueError('duplicate native track slot')
    roster = sorted(slots)
    midi = mido.MidiFile(type=1, ticks_per_beat=division)
    release_track = mido.MidiTrack()
    midi.tracks.append(release_track)
    preview_releases = []
    preview_end = 0
    for source in sorted(sources, key=lambda item: item['index']):
        slot = source['index']
        native, native_end = _flatten(source)
        events, event_ids, release_ids = [], [], []
        for order, (tick, event) in enumerate(native):
            identity = f'{slot:02d}:{order}'
            event_ids.append(identity)
            kind = event['kind']
            if kind == 'channel':
                msg = _channel(event)
                if msg.type == 'note_on':
                    duration = _duration(event)
                    binding = _hint('duration', id=identity, duration=duration)
                    if duration and msg.velocity:
                        release = f'{identity}:release'
                        release_ids.append(release)
                        # Earlier onsets enqueue releases first. These IDs track
                        # origins, not which same-key voice an SDK release affects.
                        preview_releases.append((tick + duration, tick, slot, order, release,
                                                 [_hint('release', id=release, origin=identity),
                                                  mido.Message('note_off', channel=msg.channel,
                                                               note=msg.note, velocity=0)]))
                else:
                    binding = _hint('event', id=identity, kind='channel')
                messages = [binding, msg]
            elif kind == 'tempo':
                tempo = _integer(event.get('microseconds_per_quarter'), 'tempo', 0xFFFFFF)
                if not tempo:
                    raise ValueError('native tempo must be positive')
                messages = [_hint('event', id=identity, kind='tempo'),
                            mido.MetaMessage('set_tempo', tempo=tempo)]
            elif kind == 'loop_start':
                messages = [_hint('event', id=identity, kind=kind),
                            mido.MetaMessage('marker', text='loop_start')]
            elif kind == 'loop_end':
                messages = [_hint('event', id=identity, kind=kind),
                            mido.MetaMessage('marker', text=f"loop_end:{event['count']}:{event['current']}")]
            elif kind in ('native_loop_start', 'native_loop_end'):
                messages = [_hint('native_control', id=identity, **_control(event))]
            else:
                raise ValueError(f'unsupported native event kind {kind!r}')
            events.append((tick, 1, (tick, order), messages))
        track = mido.MidiTrack()
        midi.tracks.append(track)
        track.append(mido.MetaMessage('track_name', name=f'snap_native_v1_cseq_track_{slot:02d}'))
        track.append(_hint('track', slot=slot, slots=roster, division=division,
                           native_end=native_end, event_ids=event_ids, release_ids=release_ids))
        previous = 0
        for tick, _, _, messages in sorted(events, key=lambda item: item[:3]):
            previous = _append(track, messages, tick, previous)
        track_end = max(native_end, previous, *(item[0] for item in preview_releases if item[2] == slot))
        preview_end = max(preview_end, track_end)
        _append(track, [mido.MetaMessage('end_of_track')], track_end, previous)
    # MIDI merges equal-time events by track order. Native duration releases
    # precede sequence callbacks, including controllers on other tracks.
    release_track.append(mido.MetaMessage('track_name', name='snap_native_v1_preview_releases'))
    release_track.append(_hint('release_track', slots=roster, division=division,
                               preview_end=preview_end,
                               release_ids=[item[4] for item in preview_releases]))
    previous = 0
    for tick, _, _, _, _, messages in sorted(preview_releases, key=lambda item: item[:4]):
        previous = _append(release_track, messages, tick, previous)
    _append(release_track, [mido.MetaMessage('end_of_track')], preview_end, previous)
    return midi


def _loop_marker(msg, kind):
    if msg.type != 'marker':
        raise ValueError('native loop hint must bind a visible marker')
    if kind == 'loop_start':
        if msg.text != 'loop_start':
            raise ValueError('stale native loop_start binding')
        return {'kind': kind}
    fields = msg.text.split(':')
    if len(fields) not in (2, 3) or fields[0] != 'loop_end':
        raise ValueError('stale native loop_end binding')
    try:
        count = int(fields[1])
        current = count if len(fields) == 2 else int(fields[2])
    except ValueError as exc:
        raise ValueError('invalid visible native loop counters') from exc
    return {'kind': kind, 'count': _integer(count, 'loop count', 255),
            'current': _integer(current, 'loop current', 255)}


def _bound_event(binding, msg):
    if binding['type'] == 'duration':
        if msg.is_meta or msg.type != 'note_on':
            raise ValueError('native duration hint must bind the next NoteOn at the same tick')
        raw = msg.bytes()
        return {'kind': 'channel', 'status': raw[0], 'parameters': raw[1:],
                'duration': _integer(binding['duration'], 'note duration', 0xFFFFFFFF)}
    kind = binding['kind']
    if kind == 'channel':
        if msg.is_meta or not hasattr(msg, 'channel') or msg.type == 'note_on':
            raise ValueError('stale native channel event binding')
        raw = msg.bytes()
        return {'kind': kind, 'status': raw[0], 'parameters': raw[1:]}
    if kind == 'tempo':
        if not msg.is_meta or msg.type != 'set_tempo' or not 0 < msg.tempo <= 0xFFFFFF:
            raise ValueError('stale or invalid native tempo binding')
        return {'kind': kind, 'tempo': msg.tempo}
    if kind in ('loop_start', 'loop_end'):
        return _loop_marker(msg, kind)
    raise ValueError(f'unsupported native bound event kind {kind!r}')


def _validate_loops(events, native_end):
    start = None
    seen = False
    infinite_end = None
    for tick, event in events:
        if tick > native_end:
            raise ValueError('native event exceeds protected native end timing')
        kind = event['kind']
        if infinite_end is not None:
            raise ValueError('native events follow an unreachable infinite loop end')
        if kind == 'loop_start':
            if start is not None or seen:
                raise ValueError('nested or multiple native normalized loops are unsupported')
            start = tick
            seen = True
        elif kind == 'loop_end':
            if start is None:
                raise ValueError('native loop_end without loop_start')
            if event['current'] == 255:
                if tick == start:
                    raise ValueError('infinite native loop must advance ticks')
                if tick != native_end:
                    raise ValueError('stale native end timing at infinite loop_end')
                infinite_end = tick
            start = None
    if start is not None:
        raise ValueError('native loop_start without loop_end')


def _read_release_track(track):
    tick, header, pending = 0, None, None
    names, releases, ids = [], {}, set()
    ended = False
    for msg in track:
        _integer(msg.time, 'MIDI delta', _MAX_DELTA)
        tick += msg.time
        if ended:
            raise ValueError('MIDI events after preview release EOT')
        if pending is not None and tick != pending[0]:
            raise ValueError('stale native release binding timing')
        if _is_hint(msg):
            if pending is not None:
                raise ValueError('missing event for native preview release binding')
            record = _parse_hint(msg)
            if record['type'] == 'release_track':
                _fields(record, 'slots', 'division', 'preview_end', 'release_ids')
                if header is not None or tick or ids:
                    raise ValueError('duplicate or misplaced native release track header')
                _integer(record['division'], 'PPQN division', 32767)
                _integer(record['preview_end'], 'preview end timing')
                _ids(record['release_ids'], 'release')
                header = record
            elif record['type'] == 'release' and header is not None:
                _fields(record, 'id', 'origin')
                identity, origin = record['id'], record['origin']
                if (not isinstance(identity, str) or not identity or identity in ids
                        or not isinstance(origin, str) or not origin or origin in releases):
                    raise ValueError('invalid or duplicate native preview release binding')
                ids.add(identity)
                pending = tick, identity, origin
            else:
                raise ValueError('unsupported or incomplete native release track metadata')
            continue
        if msg.is_meta and msg.type in _IGNORED_META:
            if msg.type == 'track_name' and msg.name.startswith('snap_native_'):
                names.append(msg.name)
            continue
        if pending is not None:
            _, identity, origin = pending
            if msg.is_meta or msg.type != 'note_off' or msg.velocity:
                raise ValueError('stale native preview release binding')
            releases[origin] = identity, tick, msg.channel, msg.note
            pending = None
        elif msg.is_meta and msg.type == 'end_of_track':
            ended = True
        else:
            raise ValueError('unbound MIDI event in protected preview release track')
    if header is None or names != ['snap_native_v1_preview_releases'] or pending is not None:
        raise ValueError('incomplete protected native release track metadata')
    if ids != _ids(header['release_ids'], 'release'):
        raise ValueError('missing, added, or stale native release binding IDs')
    if not ended or tick != header['preview_end']:
        raise ValueError('stale native preview release EOT timing')
    return header, releases


def _read_track(track, release_stream):
    tick = 0
    header = None
    protected_names = []
    pending = None
    events, notes = [], {}
    seen_ids = set()
    ended = False
    musical = False
    for msg in track:
        _integer(msg.time, 'MIDI delta', _MAX_DELTA)
        tick += msg.time
        if ended:
            raise ValueError('MIDI events after native preview EOT')
        if pending is not None and tick != pending[0]:
            raise ValueError('stale native binding timing: hint and event ticks differ')
        if _is_hint(msg):
            if pending is not None:
                raise ValueError('missing event for native binding')
            record = _parse_hint(msg)
            kind = record['type']
            if kind == 'track':
                _fields(record, 'slot', 'slots', 'division', 'native_end', 'event_ids', 'release_ids')
                if header is not None or tick or musical:
                    raise ValueError('duplicate or misplaced native track header')
                _integer(record['slot'], 'track slot', 15)
                _integer(record['division'], 'PPQN division', 32767)
                _integer(record['native_end'], 'end timing')
                slots = record['slots']
                if (not isinstance(slots, list) or not slots
                        or any(type(slot) is not int or not 0 <= slot < 16 for slot in slots)
                        or slots != sorted(set(slots)) or record['slot'] not in slots):
                    raise ValueError('invalid native track roster')
                event_ids = _ids(record['event_ids'], 'event')
                release_ids = _ids(record['release_ids'], 'release')
                if event_ids & release_ids:
                    raise ValueError('duplicate native binding IDs')
                header = record
                continue
            if header is None:
                raise ValueError('native binding without track header')
            identity = record.get('id')
            if not isinstance(identity, str) or not identity or identity in seen_ids:
                raise ValueError('invalid or duplicate native binding ID')
            seen_ids.add(identity)
            musical = True
            if kind == 'duration':
                _fields(record, 'id', 'duration')
                _integer(record['duration'], 'note duration', 0xFFFFFFFF)
                pending = tick, record
            elif kind == 'event':
                _fields(record, 'id', 'kind')
                pending = tick, record
            elif kind == 'native_control':
                if record.get('kind') == 'native_loop_start':
                    _fields(record, 'id', 'kind', 'ignored')
                elif record.get('kind') == 'native_loop_end':
                    _fields(record, 'id', 'kind', 'count', 'current', 'back_offset')
                else:
                    raise ValueError('unsupported native control hint')
                events.append((tick, _control(record)))
            else:
                raise ValueError(f'unsupported native hint type {kind!r}')
            continue
        if msg.is_meta and msg.type in _IGNORED_META:
            if msg.type == 'track_name' and msg.name.startswith('snap_native_'):
                match = _NAME.fullmatch(msg.name)
                if match is None:
                    raise ValueError('unsupported or malformed protected native track name')
                protected_names.append(int(match[1]))
            continue
        if pending is not None:
            _, binding = pending
            pending = None
            identity = binding['id']
            event = _bound_event(binding, msg)
            events.append((tick, event))
            if binding['type'] == 'duration':
                # SDK velocity-zero NoteOn consumes duration but posts no timer.
                timed_duration = event['duration'] if msg.velocity else 0
                notes[identity] = (tick, timed_duration, msg.channel, msg.note, len(events))
            continue
        if msg.is_meta and msg.type == 'end_of_track':
            ended = True
            continue
        raise ValueError('unbound MIDI event in protected native mode; preserve all native bindings')
    if pending is not None:
        raise ValueError('missing event for native binding')
    if header is None or protected_names != [header['slot']]:
        raise ValueError('incomplete protected native track metadata')
    if not ended or tick < header['native_end']:
        raise ValueError('missing or shortened native preview EOT')
    expected_events = _ids(header['event_ids'], 'event')
    expected_releases = _ids(header['release_ids'], 'release')
    releases = {origin: release for origin, release in release_stream.items()
                if release[0] in expected_releases}
    if seen_ids != expected_events or {item[0] for item in releases.values()} != expected_releases:
        raise ValueError('missing, added, or stale native binding IDs')
    for identity, (on_tick, duration, channel, key, _) in notes.items():
        release = releases.get(identity)
        if duration:
            if release is None:
                raise ValueError('missing native preview release')
            _, off_tick, off_channel, off_key = release
            if (off_tick, off_channel, off_key) != (on_tick + duration, channel, key):
                raise ValueError('stale native preview release timing or channel/key binding')
        elif release is not None:
            raise ValueError('untimed native note must not have a preview release')
    if set(releases) != {identity for identity, note in notes.items() if note[1]}:
        raise ValueError('native preview release has an unknown or untimed origin')
    expected_order = sorted(releases, key=lambda identity:
                            (releases[identity][1], notes[identity][0], notes[identity][4]))
    if list(releases) != expected_order:
        raise ValueError('stale native preview release enqueue ordering')
    preview_end = max([header['native_end'], *[release[1] for release in releases.values()]])
    if tick != preview_end:
        raise ValueError('stale native preview EOT timing')
    _validate_loops(events, header['native_end'])
    return header, events


def from_midi(midi):
    """Return native compiler tracks, or None only for genuinely unhinted MIDI.

    Result items are (slot, [(absolute_tick, compiler_event), ...], native_end).
    Partial native metadata is an error, never an ordinary-MIDI fallback.
    """
    protected = any(_is_hint(msg) or (msg.is_meta and msg.type == 'track_name'
                                     and msg.name.startswith('snap_native_'))
                    for track in midi.tracks for msg in track)
    if not protected:
        return None
    if midi.type != 1 or type(midi.ticks_per_beat) is not int or not 0 < midi.ticks_per_beat <= 32767:
        raise ValueError('protected native preview requires Type 1 MIDI with PPQN timing')
    if len(midi.tracks) < 2:
        raise ValueError('incomplete protected native track roster')
    release_header, releases = _read_release_track(midi.tracks[0])
    parsed = [_read_track(track, releases) for track in midi.tracks[1:]]
    slots = [header['slot'] for header, _ in parsed]
    if len(set(slots)) != len(slots):
        raise ValueError('duplicate native track slot')
    roster = sorted(slots)
    if release_header['slots'] != roster or release_header['division'] != midi.ticks_per_beat:
        raise ValueError('incomplete or stale native release roster or division')
    expected_releases = set().union(*(set(header['release_ids']) for header, _ in parsed))
    if expected_releases != {item[0] for item in releases.values()}:
        raise ValueError('unknown or missing native preview release origin')
    expected_end = max([header['native_end'] for header, _ in parsed] +
                       [item[1] for item in releases.values()])
    if release_header['preview_end'] != expected_end:
        raise ValueError('stale native preview EOT timing')
    all_ids = set()
    for header, events in parsed:
        if header['slots'] != roster:
            raise ValueError('incomplete or stale native track roster')
        if header['division'] != midi.ticks_per_beat:
            raise ValueError('stale native PPQN division hint')
        identities = set(header['event_ids']) | set(header['release_ids'])
        if identities & all_ids:
            raise ValueError('duplicate native binding IDs across tracks')
        all_ids.update(identities)
    return sorted((header['slot'], events, header['native_end']) for header, events in parsed)
