import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audio_native import note_lifetimes, semantic_trace, to_interchange
from audio_seq import _vlq


def _escaped(data):
    return data.replace(b'\xfe', b'\xfe\xfe')


def _event(delta, payload):
    return _escaped(_vlq(delta) + payload)


def _program(delta, value, channel=0):
    return _event(delta, bytes([0xC0 | channel, value]))


def _note(delta, key, duration, velocity=90, channel=0):
    return _event(delta, bytes([0x90 | channel, key, velocity]) + _vlq(duration))


def _end(delta=0):
    return _event(delta, b'\xff\x2f')


def _loop(prefix, delta, count, current, target=0):
    lead = _event(delta, b'\xff\x2d')
    back = len(prefix) + len(lead) + 6 - target
    return lead + bytes([count, current]) + struct.pack('>I', back)


def _backreference(position, target, length):
    offset = position - target
    if not 0 <= offset <= 65535 or offset >> 8 == 254:
        raise ValueError('fixture backreference is not encodable')
    return bytes([254, offset >> 8, offset & 255, length])


def _sequence(tracks, division=480):
    data = bytearray(68)
    struct.pack_into('>I', data, 64, division)
    for slot, track in sorted(tracks.items()):
        struct.pack_into('>I', data, slot * 4, len(data))
        data.extend(track)
    return bytes(data)


class NativeInterchangeTests(unittest.TestCase):
    def test_plain_timed_events_and_eot_silence(self):
        data = _sequence({3: _note(3, 60, 0) + _event(4, b'\xff\x51\x07\xa1\x20') + _end(7)})
        spec = to_interchange(data)
        self.assertEqual(spec['division'], 480)
        track = spec['tracks'][0]
        self.assertEqual(track['index'], 3)
        self.assertEqual(track['prefix_end'], 14)
        self.assertIsNone(track['loop'])
        self.assertEqual(track['tail'], [])
        self.assertEqual(track['tail_end'], 0)
        self.assertEqual(track['prefix'], [
            {'kind': 'channel', 'status': 144, 'parameters': [60, 90], 'duration': {'value': 0}, 'tick': 3},
            {'kind': 'tempo', 'microseconds_per_quarter': 500000, 'tick': 7},
        ])

    def test_current_zero_is_inert_even_with_infinite_count_and_bad_target(self):
        before = _program(2, 1)
        inert = _event(3, b'\xff\x2d') + b'\xff\x00\xff\xff\xff\xff'
        data = _sequence({0: before + inert + _program(4, 2) + _end(5)})
        track = to_interchange(data)['tracks'][0]
        self.assertIsNone(track['loop'])
        self.assertEqual(track['prefix_end'], 14)
        self.assertEqual(track['prefix'][1], {'kind': 'native_loop_end', 'count': 255, 'current': 0,
                                            'back_offset': 0xFFFFFFFF, 'tick': 5})
        self.assertEqual([event['tick'] for event in semantic_trace(data, max_ticks=20)], [2, 9])

    def test_inert_offset_capture_is_not_an_sdk_dependency(self):
        data = bytearray(_sequence({
            1: bytes.fromhex('00 ff 2d 00 00 ff 2d 07 00 00 ff 2f 00 00 ff 2f'),
        }))
        struct.pack_into('>I', data, 0, 72)
        data = bytes(data)
        self.assertEqual(semantic_trace(data, max_ticks=20), [])
        from audio_midi import export_midi, import_midi
        self.assertEqual(semantic_trace(import_midi(export_midi(data)), max_ticks=20), [])

    def test_noncyclic_loop_jump_reaching_eot_is_linear_control(self):
        from audio_midi import export_midi, import_midi
        for current in (1, 255):
            with self.subTest(current=current):
                track = _program(0, 1) + _event(5, b'\xff\x2d') + bytes([7, current])
                track += bytes(4) + _program(2, 2) + _end()
                data = _sequence({0: track})
                expected = [
                    {'kind': 'channel', 'status': 192, 'parameters': [1], 'tick': 0, 'track': 0},
                    {'kind': 'channel', 'status': 192, 'parameters': [2], 'tick': 7, 'track': 0},
                ]
                self.assertEqual(semantic_trace(data, max_ticks=20), expected)
                self.assertEqual(semantic_trace(import_midi(export_midi(data)), max_ticks=20), expected)

    def test_finite_current_is_not_reset_count_and_tail_time_is_exact(self):
        for current in (1, 2, 254):
            with self.subTest(current=current):
                prefix = _program(5, 8)
                data = _sequence({0: prefix + _loop(prefix, 10, 7, current) + _program(4, 9) + _end(6)})
                track = to_interchange(data)['tracks'][0]
                self.assertEqual(track['prefix_end'], 15)
                self.assertEqual(track['loop'], {'body': [{'kind': 'channel', 'status': 192, 'parameters': [8], 'tick': 5}],
                                                'body_end': 15, 'count': 7, 'current': current})
                self.assertEqual(track['tail'][0]['tick'], 4)
                self.assertEqual(track['tail_end'], 10)
                trace = semantic_trace(data, max_ticks=15 * (current + 1) + 10)
                self.assertEqual([event['tick'] for event in trace],
                                 [5 + 15 * repeat for repeat in range(current + 1)] + [15 * (current + 1) + 4])

    def test_current_forever_ignores_count_and_unreachable_malformed_suffix(self):
        prefix = _note(5, 60, 40)
        data = _sequence({0: prefix + _loop(prefix, 10, 0, 255) + b'\x00\xff\x2d\x00\xff\xff\xff\xff\xff\xfe'})
        track = to_interchange(data)['tracks'][0]
        self.assertEqual(track['loop']['count'], 0)
        self.assertEqual(track['loop']['current'], 255)
        self.assertEqual(track['loop']['body_end'], 15)
        self.assertEqual(track['tail'], [])
        self.assertEqual([event['tick'] for event in semantic_trace(data, max_ticks=40)], [5, 20, 35])
        self.assertEqual([event['duration'] for event in semantic_trace(data, max_ticks=40)], [40, 40, 40])

    def test_real_repeat_target_inside_firstpass_tempo_payload(self):
        prefix = _event(0, b'\xff\x51\x00\xc0\x07')
        data = _sequence({0: prefix + _loop(prefix, 4, 6, 2, target=3) + _end(9)})
        track = to_interchange(data)['tracks'][0]
        self.assertEqual(track['prefix'], [{'kind': 'tempo', 'microseconds_per_quarter': 49159, 'tick': 0}])
        self.assertEqual(track['prefix_end'], 4)
        self.assertEqual(track['loop']['body'], [{'kind': 'channel', 'status': 192, 'parameters': [7], 'tick': 0}])
        self.assertEqual(track['loop']['body_end'], 4)
        self.assertEqual(track['tail_end'], 9)
        trace = semantic_trace(data, max_ticks=17)
        self.assertEqual([(event['tick'], event['kind']) for event in trace], [(0, 'tempo'), (4, 'channel'), (8, 'channel')])

    def test_original_header_backreferences_are_not_rewritten_for_repeat_entry(self):
        # Division bytes 65..67 are a complete delta/status/program event.
        prefix = _program(0, 5)
        target = len(prefix)
        prefix += _backreference(68 + target, 65, 3)
        data = _sequence({0: prefix + _loop(prefix, 4, 1, 1, target) + _end()}, division=49159)
        track = to_interchange(data)['tracks'][0]
        self.assertEqual([event['parameters'] for event in track['prefix']], [[5], [7]])
        self.assertEqual(track['loop']['body'], [{'kind': 'channel', 'status': 192, 'parameters': [7], 'tick': 0}])
        self.assertEqual([event['parameters'] for event in semantic_trace(data, max_ticks=8)], [[5], [7], [7]])

    def test_backup_fe_is_literal_not_recursively_compressed(self):
        prefix = _event(0, b'\xff\x51\x00\x01')
        prefix += _backreference(68 + len(prefix), 67, 1)
        data = _sequence({0: prefix + _end()}, division=510)
        self.assertEqual(to_interchange(data)['tracks'][0]['prefix'][0]['microseconds_per_quarter'], 510)
        self.assertEqual(semantic_trace(data, max_ticks=0)[0]['microseconds_per_quarter'], 510)

    def test_escaped_delta_and_tempo_bytes(self):
        data = _sequence({0: _event(254, b'\xff\x51\x00\x01\xfe') + _end(7)})
        track = to_interchange(data)['tracks'][0]
        self.assertEqual(track['prefix'][0]['tick'], 254)
        self.assertEqual(track['prefix'][0]['microseconds_per_quarter'], 510)
        self.assertEqual(track['prefix_end'], 261)

    def test_loopstart_preserved_without_treating_it_as_jump_target(self):
        start = _event(2, b'\xff\x2e\x12\x34')
        prefix = start + _program(5, 8)
        data = _sequence({0: prefix + _loop(prefix, 10, 1, 1, target=len(start)) + _end()})
        track = to_interchange(data)['tracks'][0]
        self.assertEqual(track['prefix'][0], {'kind': 'native_loop_start', 'ignored': [18, 52], 'tick': 2})
        self.assertEqual(track['prefix_end'], 17)
        self.assertEqual(track['loop']['body_end'], 15)
        self.assertEqual(track['loop']['body'][0]['tick'], 5)

    def test_running_status_is_reset_at_real_jump(self):
        prefix = _program(0, 1) + _event(0, b'\x02')
        data = _sequence({0: prefix + _loop(prefix, 3, 1, 1, target=3) + _end()})
        with self.assertRaises(ValueError):
            to_interchange(data)
        with self.assertRaises(ValueError):
            semantic_trace(data, max_ticks=10)

    def test_delay_only_self_target_and_finite_zero_delay(self):
        for current in (1, 2, 255):
            with self.subTest(current=current):
                data = _sequence({0: _loop(b'', 7, 4, current) + _end(9)})
                track = to_interchange(data)['tracks'][0]
                self.assertEqual(track['prefix_end'], 7)
                self.assertEqual(track['loop']['body'], [])
                self.assertEqual(track['loop']['body_end'], 7)
                self.assertEqual(track['tail_end'], 0 if current == 255 else 9)
                self.assertEqual(semantic_trace(data, max_ticks=30), [])
        zero = _sequence({0: _loop(b'', 0, 255, 2) + _end(4)})
        self.assertEqual(to_interchange(zero)['tracks'][0]['loop']['body_end'], 0)
        self.assertEqual(to_interchange(zero)['tracks'][0]['tail_end'], 4)

    def test_zero_time_infinite_self_cycle_rejected(self):
        data = _sequence({0: _loop(b'', 0, 0, 255) + _end()})
        for call in (lambda: to_interchange(data), lambda: semantic_trace(data, max_ticks=0),
                     lambda: note_lifetimes(data, max_ticks=0)):
            with self.assertRaises(ValueError):
                call()

    def test_finite_tail_observes_reset_current_byte(self):
        prefix = _program(0, 1)
        loop = _loop(prefix, 5, 7, 1)
        current_offset = 68 + len(prefix) + len(_event(5, b'\xff\x2d')) + 1
        tail = _event(2, b'\xff\x51\x00\x01')
        tail += _backreference(68 + len(prefix) + len(loop) + len(tail), current_offset, 1)
        data = _sequence({0: prefix + loop + tail + _end(3)})
        track = to_interchange(data)['tracks'][0]
        self.assertEqual(track['tail'], [{'kind': 'tempo', 'microseconds_per_quarter': 263, 'tick': 2}])
        self.assertEqual(track['tail_end'], 5)
        self.assertEqual(semantic_trace(data, max_ticks=15)[-1]['microseconds_per_quarter'], 263)

    def test_residual_backup_at_raw_loop_fields_rejected_explicitly(self):
        data = bytearray(68)
        struct.pack_into('>I', data, 0, 72)
        struct.pack_into('>I', data, 64, 480)
        data.extend(b'\x00\xff\x2d\x63')
        data.extend(_backreference(72, 68, 4))
        data.extend(b'\x00' * 6 + _end())
        with self.assertRaises(ValueError):
            to_interchange(bytes(data))
        with self.assertRaises(ValueError):
            semantic_trace(bytes(data), max_ticks=0)

    def test_finite_tail_additional_active_loop_is_precisely_unsupported(self):
        prefix = _program(0, 1)
        first = prefix + _loop(prefix, 5, 1, 1)
        data = _sequence({0: first + _loop(first, 3, 0, 255, target=len(first)) + _end()})
        with self.assertRaises(ValueError):
            to_interchange(data)

    def test_repeat_encountering_other_active_loop_is_not_terminal_substitution(self):
        first = _loop(b'', 1, 1, 0)
        prefix = first + _program(0, 1)
        data = _sequence({0: prefix + _loop(prefix, 5, 1, 1) + _end()})
        with self.assertRaises(ValueError):
            to_interchange(data)

    def test_shared_mutating_loop_state_is_not_normalized_independently(self):
        prefix = _program(0, 1)
        data = bytearray(_sequence({0: prefix + _loop(prefix, 5, 1, 1) + _program(0, 9) + _end()}))
        struct.pack_into('>I', data, 4, 68)
        with self.assertRaises(ValueError):
            to_interchange(bytes(data))
        trace = semantic_trace(bytes(data), max_ticks=5)
        self.assertEqual([(event['track'], event['tick'], event['parameters']) for event in trace],
                         [(0, 0, [1]), (1, 0, [1]), (0, 5, [1]), (1, 5, [9])])

    def test_shared_immutable_forever_counter_is_safe(self):
        prefix = _program(0, 1)
        data = bytearray(_sequence({0: prefix + _loop(prefix, 5, 0, 255) + _end()}))
        struct.pack_into('>I', data, 4, 68)
        self.assertEqual(len(to_interchange(bytes(data))['tracks']), 2)

    def test_backup_reads_current_memory_not_a_priming_snapshot(self):
        prefix = _program(0, 1)
        first = prefix + _loop(prefix, 5, 7, 193) + _end()
        count_offset = 68 + len(prefix) + len(_event(5, b'\xff\x2d'))
        second_offset = 68 + len(first)
        second = _backreference(second_offset, count_offset, 3) + _end()
        data = _sequence({0: first, 1: second})
        trace = semantic_trace(data, max_ticks=7)
        other = [event for event in trace if event['track'] == 1]
        self.assertEqual(other, [{'kind': 'channel', 'status': 192, 'parameters': [0], 'tick': 7, 'track': 1}])
        with self.assertRaises(ValueError):
            to_interchange(data)

    def test_shared_read_completed_before_mutation_is_not_a_dependency(self):
        prefix = _program(0, 1)
        first = prefix + _loop(prefix, 100, 7, 193) + _end()
        count_offset = 68 + len(prefix) + len(_event(100, b'\xff\x2d'))
        second_offset = 68 + len(first)
        second = _backreference(second_offset, count_offset, 3) + _end()
        data = _sequence({0: first, 1: second})
        spec = to_interchange(data)
        self.assertEqual(spec['tracks'][1]['prefix'],
                         [{'kind': 'channel', 'status': 193, 'parameters': [0], 'tick': 7}])

    def test_required_mutation_diagnostic_precedes_isolated_parse_failure(self):
        first = _loop(b'', 5, 192, 0) + _end()
        current_offset = 68 + len(_event(5, b'\xff\x2d')) + 1
        second_offset = 68 + len(first)
        second = _vlq(7) + _backreference(second_offset + 1, current_offset, 2) + _end()
        data = _sequence({0: first, 1: second})
        self.assertEqual(semantic_trace(data, max_ticks=7),
                         [{'kind': 'channel', 'status': 192, 'parameters': [0], 'tick': 7, 'track': 1}])
        with self.assertRaises(ValueError):
            to_interchange(data)

    def test_future_periodic_read_observes_mutation_after_first_two_repeats(self):
        prefix = _program(0, 1)
        first = prefix + _loop(prefix, 100, 7, 193) + _end()
        count_offset = 68 + len(prefix) + len(_event(100, b'\xff\x2d'))
        second_offset = 68 + len(first)
        body = _backreference(second_offset, count_offset, 3)
        second = body + _loop(body, 5, 0, 255) + _end()
        data = _sequence({0: first, 1: second})
        with self.assertRaises(ValueError):
            to_interchange(data)
        last = [event for event in semantic_trace(data, max_ticks=103) if event['track'] == 1][-1]
        self.assertEqual((last['tick'], last['status']), (103, 192))

    def test_trace_same_tick_order_is_track_slot_not_local_ordinal(self):
        data = _sequence({2: _program(0, 1) + _program(0, 2) + _end(), 14: _program(0, 3) + _end()})
        trace = semantic_trace(data, max_ticks=0)
        self.assertEqual([(event['track'], event['parameters']) for event in trace], [(2, [1]), (2, [2]), (14, [3])])

    def test_horizon_is_inclusive_and_event_limit_counts_controls(self):
        data = _sequence({0: _program(5, 1) + _end(3)})
        self.assertEqual(semantic_trace(data, max_ticks=4), [])
        self.assertEqual(len(semantic_trace(data, max_ticks=5)), 1)
        controls = _sequence({0: _loop(b'', 1, 0, 255) + _end()})
        with self.assertRaises(ValueError):
            semantic_trace(controls, max_ticks=100, max_events=2)
        with self.assertRaises(ValueError):
            to_interchange(_sequence({0: _end()}, division=0))


class NativeLifetimeTests(unittest.TestCase):
    def test_prefix_only_release_does_not_repeat_with_body(self):
        first = _note(0, 60, 20) + _event(10, b'\xff\x2e\x00\x00')
        target = len(first)
        prefix = first + _note(5, 60, 10)
        data = _sequence({0: prefix + _loop(prefix, 15, 0, 255, target) + _end()})
        self.assertEqual(note_lifetimes(data, max_ticks=65),
                         [(0, 60, 0, 20), (0, 60, 15, 25), (0, 60, 35, 45), (0, 60, 55, 65)])

    def test_duration_spans_multiple_loop_periods(self):
        prefix = _note(90, 60, 250)
        data = _sequence({0: prefix + _loop(prefix, 10, 0, 255) + _end()})
        self.assertEqual(note_lifetimes(data, max_ticks=450), [(0, 60, 90, 340), (0, 60, 190, 440)])

    def test_finite_final_iteration_releases_into_tail(self):
        prefix = _note(8, 60, 15)
        data = _sequence({0: prefix + _loop(prefix, 2, 7, 1) + _end(20)})
        self.assertEqual(note_lifetimes(data, max_ticks=40), [(0, 60, 8, 23), (0, 60, 18, 33)])

    def test_release_lookup_uses_oldest_voice_not_scheduling_note_identity(self):
        data = _sequence({0: _note(0, 60, 100) + _note(10, 60, 20) + _end(110)})
        self.assertEqual(note_lifetimes(data, max_ticks=120), [(0, 60, 0, 30), (0, 60, 10, 100)])

    def test_queued_release_precedes_later_cross_track_sustain_reference(self):
        data = _sequence({0: _event(100, b'\xb0\x40\x7f') + _event(100, b'\xb0\x40\x00') + _end(),
                          1: _note(0, 60, 100) + _end(250)})
        self.assertEqual(note_lifetimes(data, max_ticks=250), [(0, 60, 0, 100)])

    def test_zero_duration_queues_nothing_and_real_explicit_off_survives(self):
        data = _sequence({0: _note(0, 60, 0) + _event(20, b'\x80\x3c\x00') + _end()})
        self.assertEqual(note_lifetimes(data, max_ticks=20), [(0, 60, 0, 20)])

    def test_sustain_releases_held_voices_at_pedal_up(self):
        data = _sequence({0: _event(0, b'\xb0\x40\x7f') + _note(0, 60, 10) +
                             _note(5, 60, 10) + _event(25, b'\xb0\x40\x00') + _end()})
        self.assertEqual(note_lifetimes(data, max_ticks=30), [(0, 60, 0, 30), (0, 60, 5, 30)])

    def test_release_at_terminal_callback_time_is_not_wrapped(self):
        prefix = _note(0, 60, 10)
        data = _sequence({0: prefix + _loop(prefix, 10, 0, 255) + _end()})
        self.assertEqual(note_lifetimes(data, max_ticks=30), [(0, 60, 0, 10), (0, 60, 10, 20), (0, 60, 20, 30)])

    def test_tempo_in_repeat_and_other_track_preserves_tick_release_deadline(self):
        prefix = _note(0, 60, 30) + _event(5, b'\xff\x51\x09\x27\xc0')
        data = _sequence({0: prefix + _loop(prefix, 5, 0, 255) + _end(),
                          1: _event(7, b'\xff\x51\x06\x1a\x80') + _end(40)})
        self.assertEqual(note_lifetimes(data, max_ticks=45), [(0, 60, 0, 30), (0, 60, 10, 40)])

    def test_lifetime_limit_includes_release_dispatch(self):
        data = _sequence({0: _note(0, 60, 5) + _end(10)})
        with self.assertRaises(ValueError):
            note_lifetimes(data, max_ticks=10, max_events=2)


if __name__ == '__main__':
    unittest.main()
