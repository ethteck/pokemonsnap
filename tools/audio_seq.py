"""Editable Nintendo compact MIDI and ALSeqFile sources.

Compression positions count decoded bytes, not events; references replay physical
bytes without recursively interpreting FE. Loop-end fields bypass the SDK byte
reader. Tracks may share physical storage, which is checked when assembling.
"""
import argparse
import json
import struct
from pathlib import Path


def _vlq(value, width=None):
    if not isinstance(value, int) or value < 0 or value > 0xFFFFFFFF:
        raise ValueError('VLQ value outside u32')
    groups = [value & 127]
    value >>= 7
    while value:
        groups.append(value & 127)
        value >>= 7
    if width is not None:
        if width < len(groups) or width > 5:
            raise ValueError('invalid VLQ width')
        groups.extend([0] * (width - len(groups)))
    groups.reverse()
    return bytes(v | (128 if i + 1 < len(groups) else 0) for i, v in enumerate(groups))


class _Reader:
    def __init__(self, data, offset, used):
        self.data, self.pos, self.used = data, offset, used
        self.back = []
        self.logical = 0
        self.plan = []

    def raw(self):
        if self.pos >= len(self.data):
            raise ValueError('track exceeds sequence')
        value = self.data[self.pos]
        self.used.add(self.pos)
        self.pos += 1
        self.logical += 1
        return value

    def byte(self):
        if self.back:
            self.logical += 1
            return self.back.pop(0)
        start, logical = self.pos, self.logical
        value = self.raw()
        if value != 254:
            return value
        second = self.raw()
        if second == 254:
            self.logical = logical + 1
            self.plan.append({'at': logical, 'kind': 'literal_fe'})
            return 254
        low, length = self.raw(), self.raw()
        target = start - ((second << 8) | low)
        if not length or target < 0 or target + length > len(self.data):
            raise ValueError('invalid physical backreference')
        self.plan.append({'at': logical, 'kind': 'backreference', 'target': target, 'length': length})
        self.back = list(self.data[target:target + length])
        self.logical = logical
        return self.byte()

    def vlq(self):
        value, width = 0, 0
        while True:
            b = self.byte()
            width += 1
            if width > 5:
                raise ValueError('overlong VLQ')
            value = (value << 7) | (b & 127)
            if not b & 128:
                break
        result = {'value': value}
        if len(_vlq(value)) != width:
            result['width'] = width
        return result


def _read_event(reader, status, include_positions=False):
    """Parse one SDK event without following its control-flow jump."""
    physical_offset = None if reader.back else reader.pos
    event = {'delta': reader.vlq()}
    if include_positions:
        event['physical_offset'] = physical_offset
    first = reader.byte()
    if first == 255:
        kind = reader.byte()
        status = 0
        if kind == 81:
            event.update(kind='tempo', microseconds_per_quarter=(reader.byte() << 16) | (reader.byte() << 8) | reader.byte())
        elif kind == 47:
            event['kind'] = 'end'
        elif kind == 46:
            event.update(kind='loop_start', ignored=[reader.byte(), reader.byte()])
        elif kind == 45:
            if reader.back:
                raise ValueError('loop fields encountered inside backreference')
            current_offset = reader.pos + 1
            count, current = reader.raw(), reader.raw()
            # An inert SDK LOOPEND skips these four bytes. Capture them for
            # lossless storage without reporting them as execution reads.
            back = int.from_bytes(bytes(reader.raw() if current else _Reader.raw(reader)
                                        for _ in range(4)), 'big')
            event.update(kind='loop_end', count=count, current=current,
                         back_offset=back, target=reader.pos - back)
            if include_positions:
                event['loop_state_offset'] = current_offset
        else:
            raise ValueError(f'unsupported compact meta {kind:02x}')
    else:
        explicit = bool(first & 128)
        if explicit:
            status = first
            first = reader.byte()
        if not 128 <= status < 240:
            raise ValueError('invalid running/channel status')
        event.update(kind='channel', status=status, explicit_status=explicit, parameters=[first])
        if status & 240 not in (192, 208):
            event['parameters'].append(reader.byte())
        if status & 240 == 144:
            event['duration'] = reader.vlq()
    if include_positions:
        event['physical_end'] = reader.pos
    return event, status


def decode(data, *, include_positions=False):
    if len(data) < 68:
        raise ValueError('compact MIDI header requires 68 bytes')
    offsets = list(struct.unpack_from('>16I', data))
    used = set(range(68))
    tracks = []
    for index, offset in enumerate(offsets):
        if not offset:
            continue
        reader = _Reader(data, offset, used)
        events, status = [], 0
        while True:
            event, status = _read_event(reader, status, include_positions)
            events.append(event)
            if event['kind'] == 'end':
                if reader.back:
                    raise ValueError('unused backreference bytes after EOT')
                break
        tracks.append({'index': index, 'offset': offset, 'events': events, 'compression': reader.plan})
    fills = []
    cursor = 68
    while cursor < len(data):
        if cursor in used:
            cursor += 1
            continue
        start, value = cursor, data[cursor]
        while cursor < len(data) and cursor not in used and data[cursor] == value:
            cursor += 1
        fills.append({'offset': start, 'length': cursor - start, 'value': value})
    return {'format': 'snap_compact_midi', 'size': len(data), 'division': struct.unpack_from('>I', data, 64)[0], 'track_offsets': offsets, 'tracks': tracks, 'fill': fills}


def _events(track):
    out = bytearray()
    raw_ranges = []
    status = 0
    loop_targets = []
    for event in track['events']:
        out.extend(_vlq(**event['delta']))
        kind = event['kind']
        if kind == 'channel':
            new = event['status']
            if not 128 <= new < 240:
                raise ValueError('invalid channel status')
            if event['explicit_status']:
                out.append(new)
            elif status != new:
                raise ValueError('running status differs from preceding event')
            status = new
            params = event['parameters']
            if len(params) != (1 if new & 240 in (192, 208) else 2) or any(not 0 <= p < 128 for p in params):
                raise ValueError('invalid channel parameters')
            out.extend(params)
            if new & 240 == 144:
                out.extend(_vlq(**event['duration']))
        else:
            status = 0
            out.append(255)
            if kind == 'tempo':
                out.append(81)
                out.extend(event['microseconds_per_quarter'].to_bytes(3, 'big'))
            elif kind == 'end':
                out.append(47)
            elif kind == 'loop_start':
                out.append(46)
                if len(event['ignored']) != 2:
                    raise ValueError('loop-start requires two ignored fields')
                out.extend(event['ignored'])
            elif kind == 'loop_end':
                out.append(45)
                start = len(out)
                out.extend([event['count'], event['current']])
                out.extend(event['back_offset'].to_bytes(4, 'big'))
                raw_ranges.append((start, len(out)))
                loop_targets.append((len(out), event['back_offset'], event['target']))
            else:
                raise ValueError(f'unknown event kind {kind}')
    if not track['events'] or track['events'][-1]['kind'] != 'end':
        raise ValueError('track requires EOT')
    return bytes(out), raw_ranges, loop_targets


def encode(spec):
    if spec['format'] == 'snap_audio_fill':
        return bytes([spec['value']]) * spec['size']
    if spec['format'] != 'snap_compact_midi':
        raise ValueError('unknown sequence source format')
    out = bytearray(spec['size'])
    assigned = set()
    references = []
    def put(offset, payload):
        if offset < 0 or offset + len(payload) > len(out):
            raise ValueError('sequence layout exceeds declared size')
        for i, value in enumerate(payload, offset):
            if i in assigned and out[i] != value:
                raise ValueError('overlapping tracks disagree')
            out[i] = value
            assigned.add(i)
    offsets = spec['track_offsets']
    if len(offsets) != 16:
        raise ValueError('requires sixteen track offsets')
    put(0, struct.pack('>16II', *offsets, spec['division']))
    indices = set()
    for track in spec['tracks']:
        index = track['index']
        if index in indices or not 0 <= index < 16 or offsets[index] != track['offset'] or not offsets[index]:
            raise ValueError('track identity/offset mismatch')
        indices.add(index)
        data, raw_ranges, loops = _events(track)
        plan = {item['at']: item for item in track['compression']}
        if len(plan) != len(track['compression']):
            raise ValueError('duplicate compression position')
        pos, logical = track['offset'], 0
        positions = {0: pos}
        while logical < len(data):
            item = plan.pop(logical, None)
            raw = any(a <= logical < b for a, b in raw_ranges)
            if item:
                if raw:
                    raise ValueError('compression in raw loop fields')
                if item['kind'] == 'literal_fe':
                    if data[logical] != 254:
                        raise ValueError('literal FE does not match event data')
                    put(pos, b'\xfe\xfe')
                    pos += 2
                    logical += 1
                elif item['kind'] == 'backreference':
                    length, target = item['length'], item['target']
                    backup = pos - target
                    if not 1 <= length <= 255 or not 0 <= backup <= 65535 or backup >> 8 == 254 or logical + length > len(data) or any(a < logical + length and b > logical for a, b in raw_ranges):
                        raise ValueError('invalid compression reference')
                    put(pos, bytes([254, backup >> 8, backup & 255, length]))
                    references.append((target, data[logical:logical + length]))
                    pos += 4
                    logical += length
                else:
                    raise ValueError('unknown compression choice')
            else:
                if data[logical] == 254 and not raw:
                    raise ValueError('FE requires explicit compression choice')
                put(pos, data[logical:logical + 1])
                pos += 1
                logical += 1
            positions[logical] = pos
        if plan:
            raise ValueError('compression position outside encoded stream')
        for end, back, target in loops:
            if positions[end] - back != target:
                raise ValueError('loop target/back-offset disagree with physical layout')
    if indices != {i for i, offset in enumerate(offsets) if offset}:
        raise ValueError('missing declared tracks')
    for fill in spec['fill']:
        put(fill['offset'], bytes([fill['value']]) * fill['length'])
    if len(assigned) != len(out):
        raise ValueError('uncovered sequence storage')
    for target, expected in references:
        if target < 0 or bytes(out[target:target + len(expected)]) != expected:
            raise ValueError('backreference no longer matches semantic events')
    return bytes(out)


def decode_sbk(data, rom_start=0xAEFC10):
    revision, count = struct.unpack_from('>HH', data)
    if len(data) != 4 + count * 8:
        raise ValueError('ALSeqFile count/size mismatch')
    return {'format': 'snap_sequence_bank', 'revision': revision, 'rom_start': rom_start, 'entries': [{'name': f'audio/seq/{rom_start + offset:06X}', 'rom_address': rom_start + offset, 'offset': offset, 'length': length} for offset, length in (struct.unpack_from('>Ii', data, 4 + i * 8) for i in range(count))]}


def encode_sbk(spec):
    if spec['format'] != 'snap_sequence_bank':
        raise ValueError('unknown sequence bank format')
    out = bytearray(struct.pack('>HH', spec['revision'], len(spec['entries'])))
    for entry in spec['entries']:
        if entry['rom_address'] != spec['rom_start'] + entry['offset'] or entry['name'] != f"audio/seq/{entry['rom_address']:06X}" or entry['length'] < 0:
            raise ValueError('sequence entry identity/address mismatch')
        out.extend(struct.pack('>Ii', entry['offset'], entry['length']))
    return bytes(out)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=['extract', 'build'])
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--kind', choices=['sequence', 'sbk', 'fill'], default='sequence')
    parser.add_argument('--rom-start', type=lambda value: int(value, 0), default=0xAEFC10)
    args = parser.parse_args()
    if args.command == 'extract':
        data = args.input.read_bytes()
        if args.kind == 'sbk':
            spec = decode_sbk(data, args.rom_start)
        elif args.kind == 'fill':
            if not data or len(set(data)) != 1:
                raise ValueError('fill must have one repeated value')
            spec = {'format': 'snap_audio_fill', 'size': len(data), 'value': data[0]}
        else:
            spec = decode(data)
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(spec, indent=2) + '\n')
    else:
        spec = json.loads(args.input.read_text())
        data = encode_sbk(spec) if spec['format'] == 'snap_sequence_bank' else encode(spec)
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_bytes(data)


if __name__ == '__main__':
    main()
