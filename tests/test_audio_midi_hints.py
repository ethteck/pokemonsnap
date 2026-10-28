import io
import json
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import mido
from audio_midi_hints import from_midi, to_midi
from audio_midi import import_midi
from audio_native import semantic_trace, note_lifetimes


_MAGIC = b'SNAP_NATIVE\x00'


def channel(tick, status, parameters, duration=None):
    event = {'tick': tick, 'kind': 'channel', 'status': status, 'parameters': parameters}
    if duration is not None:
        event['duration'] = {'value': duration}
    return event


def source(prefix, end, *, index=0, loop=None, tail=None, tail_end=0):
    return {'division': 480, 'tracks': [{'index': index, 'prefix': prefix,
            'prefix_end': end, 'loop': loop, 'tail': tail or [], 'tail_end': tail_end}]}


def serialized(midi):
    data = io.BytesIO()
    midi.save(file=data)
    return mido.MidiFile(file=io.BytesIO(data.getvalue()))


def timed(track):
    tick = 0
    result = []
    for msg in track:
        tick += msg.time
        result.append((tick, msg))
    return result


def record(msg):
    if msg.is_meta and msg.type == 'sequencer_specific' and bytes(msg.data).startswith(_MAGIC):
        return json.loads(bytes(msg.data)[len(_MAGIC):].decode('ascii'))
    return None


def replace_record(track, index, value):
    track[index] = mido.MetaMessage('sequencer_specific',
                                   data=_MAGIC + json.dumps(value).encode('ascii'),
                                   time=track[index].time)


def remove(track, index):
    msg = track.pop(index)
    if index < len(track):
        track[index] = track[index].copy(time=track[index].time + msg.time)




def bound_track(midi, kind):
    return next(track for track in midi.tracks
                if any(record(msg) and record(msg)['type'] == kind for msg in track))


class NativeMidiHintsTests(unittest.TestCase):
    def preview(self):
        return to_midi(source([channel(0, 0x90, [60, 90], 12),
                               channel(3, 0x90, [62, 80], 0),
                               channel(7, 0x80, [62, 40])], 10))

    def hint_index(self, track, kind):
        return next(index for index, msg in enumerate(track)
                    if record(msg) is not None and record(msg)['type'] == kind)

    def test_serialization_reconstructs_zero_nonzero_and_explicit_releases(self):
        midi = serialized(self.preview())
        self.assertEqual(midi.type, 1)
        audible = [(tick, msg.type, getattr(msg, 'note', None))
                   for tick, msg in timed(mido.merge_tracks(midi.tracks)) if not msg.is_meta]
        self.assertEqual(audible, [(0, 'note_on', 60), (3, 'note_on', 62),
                                  (7, 'note_off', 62), (12, 'note_off', 60)])
        self.assertEqual(from_midi(midi), [(0, [
            (0, {'kind': 'channel', 'status': 0x90, 'parameters': [60, 90], 'duration': 12}),
            (3, {'kind': 'channel', 'status': 0x90, 'parameters': [62, 80], 'duration': 0}),
            (7, {'kind': 'channel', 'status': 0x80, 'parameters': [62, 40]})], 10)])
        self.assertEqual(timed(midi.tracks[0])[-1][0], 12)

    def test_velocity_zero_native_note_on_keeps_native_duration(self):
        midi = serialized(to_midi(source([channel(0, 0x93, [65, 0], 4)], 2)))
        event = from_midi(midi)[0][1][0][1]
        self.assertEqual(event, {'kind': 'channel', 'status': 0x93,
                                 'parameters': [65, 0], 'duration': 4})
        self.assertEqual([(msg.type, msg.velocity) for msg in mido.merge_tracks(midi.tracks) if not msg.is_meta],
                         [('note_on', 0)])
        self.assertEqual(timed(midi.tracks[0])[-1][0], 2)

    def test_visible_pitch_channel_velocity_and_native_off_are_editable(self):
        midi = self.preview()
        for track in midi.tracks:
            for index, msg in enumerate(track):
                if not msg.is_meta and msg.note == 60:
                    changes = {'note': 67, 'channel': 5}
                    if msg.type == 'note_on':
                        changes['velocity'] = 111
                    track[index] = msg.copy(**changes)
                elif not msg.is_meta and msg.type == 'note_off' and msg.note == 62:
                    track[index] = msg.copy(velocity=22)
        events = from_midi(serialized(midi))[0][1]
        self.assertEqual(events[0][1], {'kind': 'channel', 'status': 0x95,
                                       'parameters': [67, 111], 'duration': 12})
        self.assertEqual(events[-1][1]['parameters'], [62, 22])

    def test_release_is_not_original_voice_identity(self):
        midi = serialized(to_midi(source([
            channel(0, 0x90, [60, 90], 8),
            channel(2, 0x80, [60, 0]),
            channel(4, 0x90, [60, 80], 0),
            channel(8, 0xB0, [64, 127]),
            channel(10, 0xB0, [64, 0]),
        ], 12)))
        events = from_midi(midi)[0][1]
        self.assertEqual(note_lifetimes(import_midi(midi), max_ticks=20),
                         [(0, 60, 0, 2), (0, 60, 4, 8)])
        preview = [(tick, msg.type) for tick, msg in timed(mido.merge_tracks(midi.tracks)) if not msg.is_meta]
        self.assertLess(preview.index((8, 'note_off')), preview.index((8, 'control_change')))
        self.assertEqual(events[0][1]['duration'], 8)
        self.assertEqual(events[2][1]['duration'], 0)

    def test_duration_crosses_loop_and_native_end_is_not_preview_release_end(self):
        spec = source([channel(0, 0x90, [60, 90], 33)], 10,
                      loop={'body': [channel(2, 0x90, [62, 80], 21)],
                            'body_end': 10, 'count': 2, 'current': 2},
                      tail=[channel(5, 0xB0, [7, 100])], tail_end=5)
        midi = serialized(to_midi(spec))
        slot, events, end = from_midi(midi)[0]
        self.assertEqual((slot, end), (0, 25))
        self.assertEqual(events[1], (10, {'kind': 'loop_start'}))
        self.assertEqual(events[2][1]['duration'], 21)
        self.assertEqual(events[3], (20, {'kind': 'loop_end', 'count': 2, 'current': 1}))
        self.assertEqual([event['tick'] for event in semantic_trace(import_midi(midi), max_ticks=100)
                          if event['kind'] == 'channel'], [0, 12, 22, 35])
        self.assertEqual(timed(midi.tracks[0])[-1][0], 33)
        release_notes = [msg.note for tick, msg in timed(midi.tracks[0])
                         if tick == 33 and not msg.is_meta and msg.type == 'note_off']
        self.assertEqual(release_notes, [60, 62])
        self.assertEqual(len([record(msg) for msg in midi.tracks[0]
                              if record(msg) and record(msg)['type'] == 'release']), 2)

    def test_reordered_same_tick_preview_releases_are_stale_not_voice_edits(self):
        midi = to_midi(source([channel(0, 0x90, [60, 90], 12),
                               channel(4, 0x90, [62, 80], 8)], 15))
        track = midi.tracks[0]
        first = self.hint_index(track, 'release')
        pairs = track[first:first + 4]
        self.assertEqual([record(pairs[0])['type'], record(pairs[2])['type']],
                         ['release', 'release'])
        track[first:first + 4] = [pairs[2].copy(time=pairs[0].time), pairs[3],
                                 pairs[0].copy(time=0), pairs[1]]
        with self.assertRaises(ValueError):
            from_midi(serialized(midi))

    def test_same_key_overlapping_loop_releases_are_fifo_actions(self):
        spec = source([channel(0, 0x90, [60, 90], 13), channel(2, 0x80, [60, 0])], 5,
                      loop={'body': [channel(1, 0x90, [60, 80], 0)],
                            'body_end': 5, 'count': 1, 'current': 2},
                      tail=[channel(4, 0x80, [60, 0])], tail_end=4)
        midi = serialized(to_midi(spec))
        self.assertEqual(note_lifetimes(import_midi(midi), max_ticks=30),
                         [(0, 60, 0, 2), (0, 60, 6, 13), (0, 60, 11, 19)])

    def test_infinite_loop_keeps_period_and_excludes_unreachable_tail(self):
        spec = source([channel(0, 0x90, [60, 90], 100)], 8,
                      loop={'body': [channel(1, 0xC0, [4])],
                            'body_end': 6, 'count': 255, 'current': 255})
        midi = serialized(to_midi(spec))
        _, events, end = from_midi(midi)[0]
        self.assertEqual(end, 14)
        self.assertEqual(events[-1], (14, {'kind': 'loop_end', 'count': 255, 'current': 255}))
        self.assertEqual(timed(midi.tracks[0])[-1][0], 100)
        self.assertEqual([event['tick'] for event in semantic_trace(import_midi(midi), max_ticks=23)
                          if event['kind'] == 'channel'], [0, 9, 15, 21])
        spec['tracks'][0]['tail'] = [channel(0, 0xC0, [7])]
        with self.assertRaises(ValueError):
            to_midi(spec)

    def test_visible_loop_counters_are_not_hidden_snapshots(self):
        midi = to_midi(source([], 3, loop={'body': [channel(0, 0xC0, [4])],
                                         'body_end': 4, 'count': 2, 'current': 1}))
        track = bound_track(midi, 'event')
        for index, msg in enumerate(track):
            if msg.is_meta and msg.type == 'marker' and msg.text.startswith('loop_end:'):
                track[index] = msg.copy(text='loop_end:7:3')
        events = from_midi(serialized(midi))[0][1]
        self.assertEqual(events[-1][1], {'kind': 'loop_end', 'count': 7, 'current': 3})

    def test_native_controls_tempo_membership_and_sparse_slots_survive(self):
        first = source([
            {'tick': 0, 'kind': 'tempo', 'microseconds_per_quarter': 600000},
            {'tick': 2, 'kind': 'native_loop_start', 'ignored': [254, 255]},
            {'tick': 3, 'kind': 'native_loop_end', 'count': 7, 'current': 0, 'back_offset': 1234},
            channel(3, 0xE2, [0, 64]),
        ], 9, index=3)
        second = source([channel(0, 0xD4, [75])], 4, index=14)['tracks'][0]
        first['tracks'].append(second)
        midi = serialized(to_midi(first))
        result = from_midi(midi)
        self.assertEqual([item[0] for item in result], [3, 14])
        self.assertEqual(result[0][1][:3], [
            (0, {'kind': 'tempo', 'tempo': 600000}),
            (2, {'kind': 'native_loop_start', 'ignored': [254, 255]}),
            (3, {'kind': 'native_loop_end', 'count': 7, 'current': 0, 'back_offset': 1234}),
        ])
        self.assertFalse(any(msg.is_meta and msg.type == 'marker'
                             for track in midi.tracks for msg in track))

    def test_long_native_silence_and_duration_use_standard_four_byte_deltas(self):
        duration = 0x10000005
        midi = serialized(to_midi(source([channel(0, 0x90, [60, 90], duration)], 0x10000000)))
        self.assertTrue(all(0 <= msg.time <= 0x0FFFFFFF for msg in midi.tracks[0]))
        self.assertEqual(from_midi(midi)[0][2], 0x10000000)
        self.assertEqual(from_midi(midi)[0][1][0][1]['duration'], duration)

    def test_ordinary_unhinted_midi_returns_none(self):
        midi = mido.MidiFile(type=0)
        midi.tracks.append(mido.MidiTrack([mido.MetaMessage('track_name', name='cseq_track_03'),
                                          mido.Message('note_on', note=60),
                                          mido.Message('note_off', note=60, time=12)]))
        self.assertIsNone(from_midi(midi))

    def test_stripped_partial_metadata_is_not_an_ordinary_fallback(self):
        for strip_names in (False, True):
            with self.subTest(strip_names=strip_names):
                midi = self.preview()
                track = midi.tracks[0]
                if strip_names:
                    remove(track, 0)
                else:
                    for index in reversed(range(len(track))):
                        if record(track[index]) is not None:
                            remove(track, index)
                with self.assertRaises(ValueError):
                    from_midi(serialized(midi))

    def test_deleted_binding_event_or_release_is_rejected(self):
        for target in ('duration_hint', 'native_pair', 'preview_off'):
            with self.subTest(target=target):
                midi = self.preview()
                track = bound_track(midi, 'release' if target == 'preview_off' else 'duration')
                if target == 'duration_hint':
                    remove(track, self.hint_index(track, 'duration'))
                elif target == 'native_pair':
                    index = self.hint_index(track, 'duration')
                    remove(track, index + 1)
                    remove(track, index)
                else:
                    remove(track, self.hint_index(track, 'release') + 1)
                with self.assertRaises(ValueError):
                    from_midi(serialized(midi))

    def test_missing_preview_off_cannot_swallow_identical_native_explicit_off(self):
        midi = to_midi(source([channel(0, 0x90, [60, 90], 8),
                               channel(8, 0x80, [60, 0])], 10))
        track = midi.tracks[0]
        remove(track, self.hint_index(track, 'release') + 1)
        with self.assertRaises(ValueError):
            from_midi(serialized(midi))

    def test_unbound_new_notes_or_controllers_are_rejected_without_silent_loss(self):
        for msg in (mido.Message('note_on', note=70), mido.Message('control_change', control=1, value=20)):
            midi = self.preview()
            midi.tracks[0].insert(2, msg)
            with self.assertRaises(ValueError):
                from_midi(serialized(midi))

    def test_stale_release_time_key_velocity_and_duration_are_rejected(self):
        for edit in ('time', 'key', 'velocity', 'duration'):
            with self.subTest(edit=edit):
                midi = self.preview()
                track = bound_track(midi, 'duration' if edit == 'duration' else 'release')
                index = self.hint_index(track, 'duration' if edit == 'duration' else 'release') + 1
                if edit == 'time':
                    track[index] = track[index].copy(time=1)
                elif edit == 'key':
                    track[index] = track[index].copy(note=61)
                elif edit == 'velocity':
                    track[index] = track[index].copy(velocity=12)
                else:
                    index = self.hint_index(track, 'duration')
                    changed = record(track[index])
                    changed['duration'] += 1
                    replace_record(track, index, changed)
                with self.assertRaises(ValueError):
                    from_midi(serialized(midi))

    def test_duplicate_ids_unknown_versions_and_malformed_payloads_are_rejected(self):
        for edit in ('id', 'version', 'json', 'prefix'):
            with self.subTest(edit=edit):
                midi = self.preview()
                track = bound_track(midi, 'duration')
                index = self.hint_index(track, 'duration')
                if edit == 'id':
                    second = next(i for i in range(index + 1, len(track))
                                  if record(track[i]) and record(track[i])['type'] == 'duration')
                    changed = record(track[second])
                    changed['id'] = record(track[index])['id']
                    replace_record(track, second, changed)
                elif edit == 'version':
                    changed = record(track[index])
                    changed['v'] = 2
                    replace_record(track, index, changed)
                else:
                    payload = _MAGIC + b'{' if edit == 'json' else b'SNAP_NATIVE-broken'
                    track[index] = mido.MetaMessage('sequencer_specific', data=payload, time=track[index].time)
                with self.assertRaises(ValueError):
                    from_midi(serialized(midi))

    def test_missing_track_and_mixed_ordinary_tracks_are_rejected(self):
        spec = source([], 3, index=2)
        spec['tracks'].append(source([], 4, index=8)['tracks'][0])
        midi = to_midi(spec)
        midi.tracks.pop()
        with self.assertRaises(ValueError):
            from_midi(serialized(midi))
        midi = self.preview()
        midi.tracks.append(mido.MidiTrack([mido.MetaMessage('end_of_track')]))
        with self.assertRaises(ValueError):
            from_midi(serialized(midi))

    def test_changed_division_and_extended_preview_eot_are_rejected(self):
        midi = self.preview()
        midi.ticks_per_beat = 960
        with self.assertRaises(ValueError):
            from_midi(serialized(midi))
        midi = self.preview()
        midi.tracks[0][-1] = midi.tracks[0][-1].copy(time=1)
        with self.assertRaises(ValueError):
            from_midi(serialized(midi))

    def test_infinite_loop_marker_cannot_silently_move_away_from_native_end(self):
        midi = to_midi(source([], 0, loop={'body': [channel(0, 0xC0, [1])],
                                         'body_end': 8, 'count': 255, 'current': 255}))
        track = bound_track(midi, 'event')
        index = next(i for i, msg in enumerate(track)
                     if record(msg) and record(msg).get('kind') == 'loop_end')
        track[index] = track[index].copy(time=track[index].time - 1)
        track[-1] = track[-1].copy(time=1)
        with self.assertRaises(ValueError):
            from_midi(serialized(midi))

    def test_empty_native_source_and_active_raw_passthrough_are_rejected(self):
        with self.assertRaises(ValueError):
            to_midi({'division': 480, 'tracks': []})
        with self.assertRaises(ValueError):
            to_midi(source([{'tick': 0, 'kind': 'native_loop_end', 'count': 1,
                             'current': 1, 'back_offset': 4}], 3))


if __name__ == '__main__':
    unittest.main()
