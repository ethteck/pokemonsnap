"""Extract and rebuild the complete Snap ALSeqFile region, with indexed MIDI overrides."""
import argparse
import json
import struct
from pathlib import Path

from audio_seq import decode_sbk, encode, decode
from audio_midi import import_midi, export_midi


def extract(data, rom_start=0xAEFC10):
    count = struct.unpack_from('>H', data, 2)[0]
    table_size = 4 + count * 8
    table = decode_sbk(data[:table_size], rom_start)
    entries = table['entries']
    starts = [entry['offset'] for entry in entries]
    if count != 37 or starts != sorted(set(starts)) or starts[0] < table_size:
        raise ValueError('expected 37 ordered Snap sequence slots')
    fragments = []
    for i, entry in enumerate(entries):
        stop = starts[i + 1] if i + 1 < count else len(data)
        if entry['length'] <= 0 or entry['offset'] + entry['length'] > len(data):
            raise ValueError('invalid sequence logical extent')
        fragments.append({'logical_length': entry['length'], 'source': decode(data[entry['offset']:stop])})
    return {'format': 'snap_sequence_region', 'revision': table['revision'],
            'prefix': data[table_size:starts[0]].hex(), 'slots': fragments}


def discover(directory):
    result = {}
    if not directory.exists():
        return result
    for path in sorted(directory.iterdir()):
        if not path.is_file() or path.suffix.lower() not in ('.mid', '.midi'):
            raise ValueError(f'unsupported MIDI override path: {path}')
        if not path.stem.isdecimal() or str(int(path.stem)) != path.stem or not 0 <= int(path.stem) < 37:
            raise ValueError(f'MIDI override must use a song ID 0..36: {path}')
        slot = int(path.stem)
        if slot in result:
            raise ValueError(f'duplicate MIDI override for song {slot}')
        result[slot] = path
    return result


def write_changed(path, data):
    path.parent.mkdir(parents=True, exist_ok=True)
    if not path.exists() or path.read_bytes() != data:
        path.write_bytes(data)


def inventory(directory, output):
    files = discover(directory)
    records = [(slot, str(path), path.stat().st_mtime_ns, path.stat().st_size) for slot, path in files.items()]
    write_changed(output, (json.dumps(records) + '\n').encode())


def build(spec, overrides=None):
    if spec['format'] != 'snap_sequence_region' or len(spec['slots']) != 37:
        raise ValueError('expected complete 37-slot sequence manifest')
    overrides = overrides or {}
    prefix = bytes.fromhex(spec['prefix'])
    cursor = 4 + 37 * 8 + len(prefix)
    entries = []
    payload = bytearray(prefix)
    for index, slot in enumerate(spec['slots']):
        if index in overrides:
            data = import_midi(overrides[index])
            length = len(data)
            data += bytes((-len(data)) % 4)
        else:
            data = encode(slot['source'])
            length = slot['logical_length']
        entries.append((cursor, length))
        cursor += len(data)
        payload.extend(data)
    # The following linked bank requires sixteen-byte ROM alignment. Stock
    # padding belongs to the final fragment, so absent overrides add no bytes.
    payload.extend(bytes((-cursor) % 16))
    return struct.pack('>HH', spec['revision'], 37) + b''.join(struct.pack('>Ii', *entry) for entry in entries) + payload


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=['inventory', 'build', 'export'])
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--overrides', type=Path, default=Path('src/audio/midis'))
    parser.add_argument('--slot', type=int, choices=range(37))
    args = parser.parse_args()
    if args.command == 'inventory':
        inventory(args.input, args.output)
    elif args.command == 'export':
        if args.slot is None:
            parser.error('export requires --slot 0..36')
        spec = json.loads(args.input.read_text())
        args.output.parent.mkdir(parents=True, exist_ok=True)
        export_midi(encode(spec['slots'][args.slot]['source'])).save(args.output)
    else:
        write_changed(args.output, build(json.loads(args.input.read_text()), discover(args.overrides)))


if __name__ == '__main__':
    main()
