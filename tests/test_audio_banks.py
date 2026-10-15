"""Synthetic native graphs only: no copyrighted ROM/sample fixtures required."""
import copy
import yaml
import struct
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools/build"))
from audio_bank import INSTRUMENT_FIELDS, encode, read_aifc, write_aifc
from audio_banks import align, inventory, plan, record_size


BOOK = {"order": 2, "npredictors": 1, "coefficients": [0] * 16}
LOOP = {"start": 0, "end": 16, "count": 0xFFFFFFFF, "state": [0] * 16}


def fixture(alias=False):
    first = write_aifc(bytes(18), 0, 22050, BOOK, LOOP)
    assets = {"one.aifc": first, "two.aifc": first}
    records = [
        dict(id="bank", type="ALBank", flags=1, padding=7, sampleRate=22050,
             percussion=None, instruments=["instrument"]),
        dict(id="instrument", type="ALInstrument", **{f: i for i, f in enumerate(INSTRUMENT_FIELDS)},
             bendRange=200, sounds=["sound_one", "sound_two"]),
        dict(id="sound_one", type="ALSound", envelope="envelope", keyMap="key", wavetable="wave_one",
             samplePan=32, sampleVolume=111, flags=3, padding=0xA5),
        dict(id="sound_two", type="ALSound", envelope="envelope", keyMap="key", wavetable="wave_two",
             samplePan=96, sampleVolume=77, flags=5, padding=0x5A),
        dict(id="envelope", type="ALEnvelope", attackTime=120, decayTime=340, releaseTime=560,
             attackVolume=127, decayVolume=64, padding=0xABCD),
        dict(id="key", type="ALKeyMap", velocityMin=1, velocityMax=127, keyMin=12, keyMax=108,
             keyBase=60, detune=-5),
        dict(id="wave_one", type="ALWaveTable", base=0, length=19, waveType="ADPCM", flags=1,
             padding=0x1234, loop="loop", book="book", sample="one"),
        dict(id="wave_two", type="ALWaveTable", base=0 if alias else 24, length=18,
             waveType="ADPCM", flags=2, padding=0x5678, loop="loop", book="book", sample="two"),
        dict(id="book", type="ALADPCMBook", sourceSample="one", _metadata=copy.deepcopy(BOOK)),
        dict(id="loop", type="ALADPCMloop", sourceSample="one", _metadata=copy.deepcopy(LOOP)),
    ]
    cursor = 8
    padding = []
    for record in records:
        alignment = 8 if record["type"] == "ALADPCMBook" else 1 if record["type"] == "ALKeyMap" else 4
        offset = align(cursor, alignment)
        if cursor != offset:
            padding.append(dict(offset=cursor, length=offset - cursor, value=0))
        record["offset"] = offset
        cursor = offset + record_size(record)
        record.pop("_metadata", None)
    size = align(cursor, 16)
    if size > cursor:
        padding.append(dict(offset=cursor, length=size - cursor, value=0))
    bank = dict(format="snap-sdk-bank-v1", size=size, header=dict(revision=0x4231, banks=["bank"]),
                records=records, padding=padding)
    table = dict(format="snap-sdk-table-v1", size=32 if alias else 48,
                 samples=[dict(id="one", offset=0, asset="one.aifc"),
                          dict(id="two", offset=0 if alias else 24, asset="two.aifc")],
                 padding=([dict(offset=18, length=14, value=0)] if alias else
                          [dict(offset=18, length=6, value=0), dict(offset=42, length=6, value=0)]))
    return bank, table, assets


def standard_pcm_loop(mode=1, release_mode=0):
    source = write_aifc(bytes(range(8)), 1, 22050, None, None)
    markers = struct.pack(">H", 2)
    for marker, position in ((3, 1), (7, 4)):
        markers += struct.pack(">hI", marker, position) + b"\x01x"
    instrument = struct.pack(">6Bh6h", 60, 0, 0, 127, 1, 127, 0,
                             mode, 3, 7, release_mode, 3, 7)
    for tag, payload in ((b"MARK", markers), (b"INST", instrument)):
        source += tag + struct.pack(">I", len(payload)) + payload
    return source[:4] + struct.pack(">I", len(source) - 8) + source[8:]


def materialize(bank, table, samples):
    by_asset = {s["asset"]: samples[s["id"]] for s in table["samples"]}
    def loader(asset):
        audio = by_asset[asset]
        return write_aifc(audio["audio"], audio["type"], int(audio["sampleRate"]), audio["book"], audio["loop"])
    return encode(bank, table, read_asset=loader)


class BankOverrideTests(unittest.TestCase):
    def test_absent_and_self_override_preserve_every_physical_byte(self):
        bank, table, assets = fixture()
        expected = encode(bank, table, read_asset=assets.__getitem__)
        for overrides in ({}, {"one": assets["one.aifc"]}, {"two": assets["two.aifc"]}):
            planned = plan(bank, table, assets.__getitem__, overrides)
            self.assertEqual(materialize(*planned), expected)
        # The stock partial ADPCM tail is a real native length byte.
        self.assertEqual(expected[1][18], 0)

    def test_authoritative_sample_divergence_does_not_mutate_other_users(self):
        bank, table, assets = fixture()
        book = copy.deepcopy(BOOK)
        book["npredictors"] = 2
        book["coefficients"] += [123] * 16
        loop = dict(start=16, end=48, count=2, state=[7] * 16)
        replacement = write_aifc(bytes([0x10]) * 27, 0, 22050, book, loop)
        out_bank, out_table, samples = plan(bank, table, assets.__getitem__, {"one": replacement})
        records = {r["id"]: r for r in out_bank["records"]}
        one, two = records["wave_one"], records["wave_two"]
        self.assertNotEqual(one["book"], two["book"])
        self.assertNotEqual(one["loop"], two["loop"])
        self.assertEqual(records[two["book"]]["_metadata"], BOOK)
        self.assertEqual(records[two["loop"]]["_metadata"], LOOP)
        self.assertEqual(records[one["book"]]["_metadata"], book)
        self.assertEqual(one["length"], 27)
        self.assertEqual(two["length"], 18)
        for sample in out_table["samples"]:
            self.assertEqual(sample["offset"] % 8, 0)
        for record in out_bank["records"]:
            if record["type"] == "ALADPCMBook":
                self.assertEqual(record["offset"] % 8, 0)
        for original in bank["records"]:
            if original["type"] in ("ALSound", "ALEnvelope", "ALKeyMap", "ALInstrument", "ALBank"):
                actual = copy.deepcopy(records[original["id"]])
                actual["offset"] = original["offset"]
                self.assertEqual(actual, original)
        _, data = materialize(out_bank, out_table, samples)
        second = next(s for s in out_table["samples"] if s["id"] == "two")
        self.assertEqual(data[second["offset"]:second["offset"] + 18], bytes(18))
        self.assertEqual(encode(bank, table, read_asset=assets.__getitem__),
                         materialize(*plan(bank, table, assets.__getitem__)))

    def test_equal_metadata_stays_shared_despite_different_audio_length(self):
        bank, table, assets = fixture()
        replacement = write_aifc(bytes(36), 0, 22050, BOOK, LOOP)
        out_bank, out_table, samples = plan(bank, table, assets.__getitem__, {"two": replacement})
        records = {r["id"]: r for r in out_bank["records"]}
        self.assertEqual(records["wave_one"]["book"], records["wave_two"]["book"])
        self.assertEqual(records["wave_one"]["loop"], records["wave_two"]["loop"])
        self.assertEqual(records["wave_one"]["length"], 19)
        materialize(out_bank, out_table, samples)

    def test_overlapping_stock_storage_diverges_safely(self):
        bank, table, assets = fixture(alias=True)
        replacement = write_aifc(bytes([0x20]) * 9, 0, 22050, BOOK, None)
        out_bank, out_table, samples = plan(bank, table, assets.__getitem__, {"one": replacement})
        offsets = [s["offset"] for s in out_table["samples"]]
        self.assertNotEqual(offsets[0], offsets[1])
        _, data = materialize(out_bank, out_table, samples)
        self.assertEqual(data[offsets[0]:offsets[0] + 9], bytes([0x20]) * 9)
        self.assertEqual(data[offsets[1]:offsets[1] + 18], bytes(18))

    def test_equal_authored_metadata_reshared_without_changing_baseline(self):
        bank, table, assets = fixture()
        baseline = copy.deepcopy((bank, table))
        book = copy.deepcopy(BOOK)
        book["coefficients"][0] = 456
        loop = dict(start=0, end=16, count=4, state=[9] * 16)
        replacement = write_aifc(bytes(9), 0, 22050, book, loop)
        out_bank, out_table, samples = plan(
            bank, table, assets.__getitem__, {"one": replacement, "two": replacement})
        records = {r["id"]: r for r in out_bank["records"]}
        self.assertEqual(records["wave_one"]["book"], records["wave_two"]["book"])
        self.assertEqual(records["wave_one"]["loop"], records["wave_two"]["loop"])
        self.assertNotIn("book", records)
        self.assertNotIn("loop", records)
        self.assertEqual((bank, table), baseline)
        materialize(out_bank, out_table, samples)

    def test_raw16_switch_keeps_other_adpcm_sample_intact(self):
        bank, table, assets = fixture()
        raw_loop = dict(start=1, end=4, count=3)
        replacement = write_aifc(bytes(range(8)), 1, 22050, None, raw_loop)
        out_bank, out_table, samples = plan(bank, table, assets.__getitem__, {"one": replacement})
        records = {r["id"]: r for r in out_bank["records"]}
        self.assertEqual(records["wave_one"]["waveType"], "RAW16")
        self.assertNotIn("book", records["wave_one"])
        self.assertEqual(records[records["wave_one"]["loop"]]["type"], "ALRawLoop")
        self.assertEqual(records["wave_two"]["book"], "book")
        materialize(out_bank, out_table, samples)

    def test_wrong_rate_and_unknown_id_fail(self):
        bank, table, assets = fixture()
        replacement = write_aifc(bytes(18), 0, 32000, BOOK, LOOP)
        with self.assertRaises(ValueError):
            plan(bank, table, assets.__getitem__, {"one": replacement})
        with self.assertRaises(ValueError):
            plan(bank, table, assets.__getitem__, {"typo": assets["one.aifc"]})

    def test_active_zero_length_loop_is_rejected(self):
        bank, table, assets = fixture()
        loop = dict(start=0, end=0, count=0xFFFFFFFF, state=[0] * 16)
        replacement = write_aifc(bytes(18), 0, 22050, BOOK, loop)
        with self.assertRaises(ValueError):
            plan(bank, table, assets.__getitem__, {"one": replacement})
        loop["count"] = 0
        replacement = write_aifc(bytes(18), 0, 22050, BOOK, loop)
        planned, _, _ = plan(bank, table, assets.__getitem__, {"one": replacement})
        records = {r["id"]: r for r in planned["records"]}
        self.assertEqual(records[records["wave_one"]["loop"]]["_metadata"], loop)

    def test_comm_trim_does_not_change_native_self_override(self):
        bank, table, assets = fixture()
        expected = encode(bank, table, read_asset=assets.__getitem__)
        replacement = bytearray(assets["one.aifc"])
        comm = replacement.index(b"COMM")
        struct.pack_into(">I", replacement, comm + 10, 31)
        planned = plan(bank, table, assets.__getitem__, {"one": bytes(replacement)})
        self.assertEqual(materialize(*planned), expected)
        wave = next(r for r in planned[0]["records"] if r["id"] == "wave_one")
        self.assertEqual(wave["length"], 19)

    def test_standard_pcm_sustain_loop_becomes_native_forward_loop(self):
        bank, table, assets = fixture()
        planned, _, _ = plan(bank, table, assets.__getitem__, {"one": standard_pcm_loop()})
        records = {r["id"]: r for r in planned["records"]}
        wave = records["wave_one"]
        self.assertEqual(wave["waveType"], "RAW16")
        self.assertEqual(records[wave["loop"]]["_metadata"],
                         {"start": 1, "end": 4, "count": 0xFFFFFFFF})
        self.assertEqual(records[records["wave_two"]["loop"]]["_metadata"], LOOP)
        for replacement in (standard_pcm_loop(mode=2), standard_pcm_loop(release_mode=1)):
            with self.assertRaises(ValueError):
                plan(bank, table, assets.__getitem__, {"one": replacement})

    def test_inventory_handles_creation_edit_removal_without_rewriting_unchanged(self):
        _, table, assets = fixture()
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            source = root / "table.yaml"
            source.write_text(yaml.safe_dump(table, sort_keys=False))
            directory = root / "overrides"
            output = root / "inventory.json"
            inventory(source, directory, output)
            empty = output.read_bytes()
            unchanged_time = output.stat().st_mtime_ns
            inventory(source, directory, output)
            self.assertEqual(output.stat().st_mtime_ns, unchanged_time)
            directory.mkdir()
            override = directory / "one.aifc"
            override.write_bytes(assets["one.aifc"])
            inventory(source, directory, output)
            populated = output.read_bytes()
            self.assertNotEqual(populated, empty)
            override.write_bytes(override.read_bytes() + b"extra")
            inventory(source, directory, output)
            self.assertNotEqual(output.read_bytes(), populated)
            override.unlink()
            inventory(source, directory, output)
            self.assertEqual(output.read_bytes(), empty)
            (directory / "typo.aifc").write_bytes(b"")
            with self.assertRaises(ValueError):
                inventory(source, directory, output)


if __name__ == "__main__":
    unittest.main()
