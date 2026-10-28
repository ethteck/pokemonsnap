import io
import json
import struct
import sys
import tempfile
import unittest
from functools import partial
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import mido
from audio_midi import import_midi, export_midi, _compact_file
from audio_seq import decode, encode
from audio_sequence_bank import build, extract, inventory, discover
from audio_native import semantic_trace, note_lifetimes as native_note_lifetimes

note_lifetimes = partial(native_note_lifetimes, max_ticks=10000)



class MidiTests(unittest.TestCase):
    def midi(self, events, division=480):
        midi = mido.MidiFile(type=1, ticks_per_beat=division)
        midi.tracks.append(mido.MidiTrack(events))
        return midi

    def test_fifo_running_status_and_eot(self):
        midi = self.midi([
            mido.Message('note_on', note=60, velocity=90),
            mido.Message('note_on', note=60, velocity=70, time=10),
            mido.Message('note_off', note=60, time=20),
            mido.Message('note_on', note=60, velocity=0, time=10),
            mido.MetaMessage('end_of_track', time=100),
        ])
        data = import_midi(midi)
        self.assertEqual(note_lifetimes(data), [(0, 60, 0, 30), (0, 60, 10, 40)])
        self.assertEqual(sum(e['delta']['value'] for e in decode(data)['tracks'][0]['events']), 140)
        exported = export_midi(data)
        self.assertEqual(sum(m.time for m in exported.tracks[0]), 140)
        stream = io.BytesIO()
        exported.save(file=stream)
        stream.seek(0)
        self.assertEqual(semantic_trace(import_midi(mido.MidiFile(file=stream)), max_ticks=10000),
                         semantic_trace(data, max_ticks=10000))

    def test_conductor_and_sixteen_slots(self):
        midi = mido.MidiFile(type=1)
        midi.tracks.append(mido.MidiTrack([
            mido.MetaMessage('set_tempo', tempo=400000, time=100),
            mido.MetaMessage('end_of_track', time=200),
        ]))
        for index in range(16):
            midi.tracks.append(mido.MidiTrack([
                mido.MetaMessage('track_name', name=f'cseq_track_{index:02d}'),
                mido.Message('program_change', program=index),
                mido.MetaMessage('end_of_track', time=50),
            ]))
        spec = decode(import_midi(midi))
        self.assertEqual(len(spec['tracks']), 16)
        first = spec['tracks'][0]['events']
        self.assertEqual([e['microseconds_per_quarter'] for e in first if e['kind'] == 'tempo'], [500000, 400000])
        self.assertEqual(sum(e['delta']['value'] for e in first), 300)

    def test_loop_offsets_use_escaped_physical_bytes(self):
        midi = self.midi([
            mido.MetaMessage('marker', text='loop_start'),
            mido.Message('program_change', program=12, time=126),
            mido.Message('control_change', control=1, value=3, time=16128),
            mido.MetaMessage('marker', text='loop_end:254', time=20),
            mido.MetaMessage('end_of_track'),
        ])
        data = import_midi(midi)
        self.assertIn(b'\xfe\xfe', data)
        spec = decode(data)
        loop = next(e for e in spec['tracks'][0]['events'] if e['kind'] == 'loop_end')
        start = data.index(b'\xff\x2e\x00\x00') + 4
        self.assertEqual(loop['target'], start)
        self.assertEqual(loop['count'], 254)
        self.assertEqual(encode(spec), data)
        self.assertEqual(semantic_trace(import_midi(export_midi(data)), max_ticks=40000),
                         semantic_trace(data, max_ticks=40000))

    def test_channels_and_cross_track_pairing(self):
        midi = self.midi([mido.Message('note_on', channel=3, note=65, velocity=60)])
        midi.tracks.append(mido.MidiTrack([
            mido.Message('pitchwheel', channel=3, pitch=-200, time=10),
            mido.Message('aftertouch', channel=3, value=50),
            mido.Message('polytouch', channel=3, note=65, value=80),
            mido.Message('note_off', channel=3, note=65, time=20),
        ]))
        spec = decode(import_midi(midi))
        self.assertEqual(note_lifetimes(import_midi(midi)), [(3, 65, 0, 30)])
        controls = [e for e in spec['tracks'][1]['events']
                    if e['kind'] == 'channel' and e['status'] & 240 not in (128, 144)]
        self.assertEqual([e['status'] for e in controls], [0xE3, 0xD3, 0xA3])

    def test_unsupported_and_unpaired(self):
        for midi in [mido.MidiFile(type=2), mido.MidiFile(ticks_per_beat=-24),
                     self.midi([mido.Message('sysex', data=[1])]),
                     self.midi([mido.Message('note_on', note=60)]),
                     self.midi([mido.Message('note_off', note=60)]),
                     self.midi([mido.MetaMessage('marker', text='loop_end')])]:
            with self.assertRaises(ValueError):
                import_midi(midi)

    def test_infinite_loop_requires_time_progress(self):
        midi = self.midi([
            mido.MetaMessage('marker', text='loop_start'),
            mido.Message('program_change', program=1),
            mido.MetaMessage('marker', text='loop_end:255'),
            mido.MetaMessage('end_of_track', time=480),
        ])
        with self.assertRaises(ValueError):
            import_midi(midi)
        zero_tempo = self.midi([mido.MetaMessage('set_tempo', tempo=0)])
        with self.assertRaises(ValueError):
            import_midi(zero_tempo)

    def test_conductor_tempo_remains_reachable_with_infinite_music_loop(self):
        midi = mido.MidiFile(type=1)
        midi.tracks.append(mido.MidiTrack([
            mido.MetaMessage('set_tempo', tempo=400000),
            mido.MetaMessage('set_tempo', tempo=600000, time=150),
            mido.MetaMessage('end_of_track', time=50),
        ]))
        midi.tracks.append(mido.MidiTrack([
            mido.MetaMessage('marker', text='loop_start'),
            mido.Message('program_change', program=1),
            mido.MetaMessage('marker', text='loop_end:255', time=100),
        ]))
        trace = semantic_trace(import_midi(midi), max_ticks=500)
        self.assertEqual([(e['tick'], e['microseconds_per_quarter'])
                          for e in trace if e['kind'] == 'tempo'],
                         [(0, 400000), (150, 600000)])
        for slot in range(1, 16):
            midi.tracks.append(mido.MidiTrack([
                mido.MetaMessage('marker', text='loop_start'),
                mido.Message('program_change', program=slot),
                mido.MetaMessage('marker', text='loop_end:255', time=100),
            ]))
        with self.assertRaises(ValueError):
            import_midi(midi)

    def test_explicit_releases_preserve_zero_duration_and_sustain_order(self):
        immediate = self.midi([
            mido.Message('note_on', note=60, velocity=90),
            mido.Message('note_off', note=60),
            mido.MetaMessage('end_of_track', time=480),
        ])
        self.assertEqual(note_lifetimes(import_midi(immediate)), [(0, 60, 0, 0)])
        sustained = self.midi([
            mido.Message('note_on', note=60, velocity=90),
            mido.Message('control_change', control=64, value=127, time=480),
            mido.Message('note_off', note=60),
            mido.Message('control_change', control=64, value=0, time=480),
            mido.MetaMessage('end_of_track', time=240),
        ])
        data = import_midi(sustained)
        self.assertEqual(note_lifetimes(data), [(0, 60, 0, 960)])
        self.assertEqual(note_lifetimes(import_midi(export_midi(data))), [(0, 60, 0, 960)])

    def test_tick_zero_conductor_after_music_is_not_repeated_by_loop(self):
        midi = self.midi([
            mido.MetaMessage('marker', text='loop_start'),
            mido.Message('program_change', program=1),
            mido.MetaMessage('marker', text='loop_end:255', time=100),
        ])
        midi.tracks.append(mido.MidiTrack([mido.MetaMessage('set_tempo', tempo=400000)]))
        trace = semantic_trace(import_midi(midi), max_ticks=350)
        self.assertEqual([(e['tick'], e['microseconds_per_quarter'])
                          for e in trace if e['kind'] == 'tempo'], [(0, 400000)])

    def test_native_duration_release_crosses_infinite_loop_jump(self):
        data = _compact_file({0: ([
            (0, {'kind': 'loop_start'}),
            (0, {'kind': 'channel', 'status': 0x90, 'parameters': [60, 90], 'duration': 100}),
            (50, {'kind': 'loop_end', 'count': 255, 'current': 255}),
        ], 50)}, 480)
        stream = io.BytesIO()
        export_midi(data).save(file=stream)
        stream.seek(0)
        rebuilt = import_midi(mido.MidiFile(file=stream))
        expected = [(0, 60, 0, 100), (0, 60, 50, 150),
                    (0, 60, 100, 200), (0, 60, 150, 250)]
        self.assertEqual(native_note_lifetimes(data, max_ticks=260), expected)
        self.assertEqual(native_note_lifetimes(rebuilt, max_ticks=260), expected)

    def test_native_scheduled_release_precedes_other_track_pedal_at_same_tick(self):
        data = _compact_file({
            0: ([(100, {'kind': 'channel', 'status': 0xB0, 'parameters': [64, 127]}),
                 (200, {'kind': 'channel', 'status': 0xB0, 'parameters': [64, 0]})], 200),
            1: ([(0, {'kind': 'channel', 'status': 0x90, 'parameters': [60, 90],
                     'duration': 100})], 200),
        }, 480)
        midi = export_midi(data)
        rebuilt = import_midi(midi)
        tick = 0
        visible_at_release = []
        for msg in mido.merge_tracks(midi.tracks):
            tick += msg.time
            if tick == 100 and not msg.is_meta:
                visible_at_release.append(msg.type)
        self.assertEqual(visible_at_release, ['note_off', 'control_change'])
        self.assertEqual(native_note_lifetimes(data, max_ticks=250), [(0, 60, 0, 100)])
        self.assertEqual(native_note_lifetimes(rebuilt, max_ticks=250), [(0, 60, 0, 100)])

    def test_pinned_slot_must_not_reverse_source_order_on_shared_channel(self):
        midi = self.midi([
            mido.Message('note_on', note=60, velocity=90),
            mido.Message('note_off', note=60, time=100),
        ])
        midi.tracks.append(mido.MidiTrack([
            mido.MetaMessage('track_name', name='cseq_track_00'),
            mido.Message('control_change', control=64, value=127, time=100),
            mido.Message('control_change', control=64, value=0, time=100),
        ]))
        with self.assertRaises(ValueError):
            import_midi(midi)
        midi.tracks[1][0] = mido.MetaMessage('track_name', name='cseq_track_01')
        self.assertEqual(note_lifetimes(import_midi(midi)), [(0, 60, 0, 100)])

    def test_ordinary_loop_requires_balanced_explicit_releases(self):
        crossed = self.midi([
            mido.MetaMessage('marker', text='loop_start'),
            mido.Message('note_on', note=60, velocity=90),
            mido.MetaMessage('marker', text='loop_end:255', time=100),
            mido.Message('note_off', note=60, time=20),
        ])
        with self.assertRaises(ValueError):
            import_midi(crossed)
        prefix = self.midi([
            mido.Message('note_on', note=60, velocity=90),
            mido.MetaMessage('marker', text='loop_start', time=10),
            mido.Message('note_off', note=60, time=10),
            mido.MetaMessage('marker', text='loop_end:255', time=10),
        ])
        with self.assertRaises(ValueError):
            import_midi(prefix)
        balanced = self.midi([
            mido.MetaMessage('marker', text='loop_start'),
            mido.Message('note_on', note=60, velocity=90),
            mido.Message('note_off', note=60, time=50),
            mido.MetaMessage('marker', text='loop_end:255', time=50),
        ])
        self.assertEqual(native_note_lifetimes(import_midi(balanced), max_ticks=260),
                         [(0, 60, 0, 50), (0, 60, 100, 150), (0, 60, 200, 250)])


class PlacementTests(unittest.TestCase):
    def stock(self):
        midi = mido.MidiFile(type=0)
        midi.tracks.append(mido.MidiTrack([mido.Message('program_change', program=1), mido.MetaMessage('end_of_track', time=20)]))
        data = import_midi(midi)
        fragment = data + bytes((-len(data)) % 4)
        slots = [{'logical_length': len(data), 'source': decode(fragment)} for _ in range(37)]
        manifest = {'format': 'snap_sequence_region', 'revision': 0, 'prefix': '', 'slots': slots}
        return build(manifest), midi

    def test_stock_and_variable_repack_restoration(self):
        stock, midi = self.stock()
        spec = extract(stock)
        self.assertEqual(build(spec), stock)
        before = json.dumps(spec)
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / '0.mid'
            for i in range(100):
                midi.tracks[0].insert(0, mido.Message('control_change', control=1, value=i % 128))
            midi.save(path)
            grown = build(spec, {0: path})
            self.assertGreater(len(grown), len(stock))
            old_offset = struct.unpack_from('>I', stock, 12)[0]
            new_offset = struct.unpack_from('>I', grown, 12)[0]
            self.assertGreater(new_offset, old_offset)
            old_length = struct.unpack_from('>i', stock, 16)[0]
            self.assertEqual(grown[new_offset:new_offset + old_length], stock[old_offset:old_offset + old_length])
            midi.tracks[0] = mido.MidiTrack([mido.MetaMessage('end_of_track')])
            midi.save(path)
            self.assertLess(len(build(spec, {0: path})), len(grown))
        self.assertEqual(json.dumps(spec), before)
        self.assertEqual(build(spec), stock)

    def test_inventory_add_edit_remove_and_restat(self):
        _, midi = self.stock()
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            directory = root / 'midis'
            output = root / 'inventory'
            inventory(directory, output)
            stamp = output.stat().st_mtime_ns
            inventory(directory, output)
            self.assertEqual(output.stat().st_mtime_ns, stamp)
            directory.mkdir()
            path = directory / '36.midi'
            midi.save(path)
            inventory(directory, output)
            original = output.read_bytes()
            self.assertEqual(set(discover(directory)), {36})
            midi.tracks[0].insert(0, mido.Message('program_change', program=2))
            midi.save(path)
            inventory(directory, output)
            self.assertNotEqual(output.read_bytes(), original)
            path.unlink()
            inventory(directory, output)
            self.assertEqual(json.loads(output.read_text()), [])
            (directory / '37.mid').write_bytes(b'')
            with self.assertRaises(ValueError):
                discover(directory)


if __name__ == '__main__':
    unittest.main()
