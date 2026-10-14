#!/usr/bin/env python3
"""Lossless, editable SDK ALBankFile graphs and Nintendo VADPCM AIFC waves.

Layout authority: ultralib/include/PR/libaudio.h:171-267 and the linked
fixups in src/sys/audio.c:377-456. N64 pointers are four-byte big-endian
bank-relative offsets. ALWaveTable is TWENTY bytes: two bytes of alignment
at 10, loop at 12, book at 16 (not the reverse). Its raw union retains the
unused word. All visited flags and C structure padding are explicit.

bankN.json contains offset-addressed, ID-referenced records, preserving
physical order and sharing. tableN.json places standard, self-contained
AIFC files and explicit fill runs, including the zero byte after an odd
ADPCM frame stream when the native wavetable length includes it. COMM's
sample count is the complete coded frame count * 16: precompression trim
counts are not stored in these SDK banks and must not be fabricated.

Books and loops have ONE authoritative source: the record's sourceSample
AIFC APPL chunk. Other AIFCs using that record carry their own standard
self-contained metadata, but the encoder rejects divergent copies. Edit
all dependent AIFCs together when changing shared metadata. Numeric book
coefficients/loop states are deliberately not duplicated in JSON.

AIFC uses FVER, COMM, SSND and Nintendo stoc VADPCMCODES/VADPCMLOOPS APPL
chunks, version 1. NONE samples additionally use standard MARK/INST loops.
No encoder reads the ROM, legacy .bin files, or an embedded raw bank blob.
Every output byte must be accounted for by a native record, audio, or fill;
conflicting overlaps and non-padding orphan bytes are errors, not fallbacks.
"""
from __future__ import annotations

import argparse
import json
import math
import struct
from pathlib import Path
from typing import Callable


INSTRUMENT_FIELDS = (
    "volume", "pan", "priority", "flags", "tremType", "tremRate",
    "tremDepth", "tremDelay", "vibType", "vibRate", "vibDepth", "vibDelay",
)
KEY_FIELDS = ("velocityMin", "velocityMax", "keyMin", "keyMax", "keyBase", "detune")


def _chunk(tag: bytes, payload: bytes) -> bytes:
    return tag + struct.pack(">I", len(payload)) + payload + b"\0" * (len(payload) & 1)


def _pstring(text: bytes) -> bytes:
    if len(text) > 255:
        raise ValueError("AIFC Pascal string too long")
    value = bytes([len(text)]) + text
    return value + b"\0" * (len(value) & 1)


def _extended(rate: int) -> bytes:
    if rate <= 0:
        raise ValueError("sample rate must be positive")
    fraction, exponent = math.frexp(rate)
    return struct.pack(">HQ", exponent + 16382, int(fraction * (1 << 64)))


def _read_extended(data: bytes) -> float:
    exponent, mantissa = struct.unpack(">HQ", data)
    if exponent & 0x8000 or exponent == 0x7FFF:
        raise ValueError("invalid AIFC sample rate")
    return math.ldexp(mantissa, exponent - 16383 - 63)


def write_aifc(audio: bytes, wave_type: int, rate: int,
               book: dict | None, loop: dict | None) -> bytes:
    """Package complete VADPCM frames or big-endian PCM16 in genuine AIFC."""
    divisor = 9 if wave_type == 0 else 2
    if wave_type not in (0, 1) or len(audio) % divisor:
        raise ValueError("audio is not a complete native sample frame stream")
    count = len(audio) // divisor * (16 if wave_type == 0 else 1)
    compression = b"VAPC" if wave_type == 0 else b"NONE"
    name = b"VADPCM ~4-1" if wave_type == 0 else b"not compressed"
    chunks = [_chunk(b"FVER", struct.pack(">I", 0xA2805140)),
              _chunk(b"COMM", struct.pack(">hIh", 1, count, 16) + _extended(rate)
                     + compression + _pstring(name))]
    if wave_type == 0:
        if book is None:
            raise ValueError("VAPC requires a codebook")
        payload = struct.pack(">HHH", 1, book["order"], book["npredictors"])
        coefficients = book["coefficients"]
        if len(coefficients) != book["order"] * book["npredictors"] * 8:
            raise ValueError("incorrect VADPCM codebook coefficient count")
        payload += struct.pack(">" + str(len(coefficients)) + "h", *coefficients)
        chunks.append(_chunk(b"APPL", b"stoc" + _pstring(b"VADPCMCODES") + payload))
    if loop is not None:
        state = loop.get("state", [0] * 16)
        payload = struct.pack(">HHIII16h", 1, 1, loop["start"], loop["end"],
                              loop["count"], *state)
        chunks.append(_chunk(b"APPL", b"stoc" + _pstring(b"VADPCMLOOPS") + payload))
        if wave_type == 1:
            markers = struct.pack(">H", 2)
            for marker, position, name in ((1, loop["start"], b"loop start"),
                                           (2, loop["end"], b"loop end")):
                markers += struct.pack(">hI", marker, position) + _pstring(name)
            chunks.append(_chunk(b"MARK", markers))
            chunks.append(_chunk(b"INST", struct.pack(">6Bh6h", 60, 0, 0, 127,
                          1, 127, 0, 1, 1, 2, 0, 0, 0)))
    chunks.append(_chunk(b"SSND", struct.pack(">II", 0, 0) + audio))
    payload = b"AIFC" + b"".join(chunks)
    return b"FORM" + struct.pack(">I", len(payload)) + payload


def read_aifc(data: bytes) -> dict:
    """Read native audio and authoritative standard Nintendo AIFC metadata."""
    if len(data) < 12 or data[:4] != b"FORM" or data[8:12] != b"AIFC":
        raise ValueError("expected a self-contained AIFC FORM")
    if struct.unpack_from(">I", data, 4)[0] + 8 != len(data):
        raise ValueError("AIFC FORM size mismatch")
    result = {"book": None, "loop": None}
    seen = set()
    offset = 12
    while offset < len(data):
        if offset + 8 > len(data):
            raise ValueError("truncated AIFC chunk")
        tag, length = struct.unpack_from(">4sI", data, offset)
        end = offset + 8 + length
        if end + (length & 1) > len(data):
            raise ValueError("AIFC chunk exceeds FORM")
        payload = data[offset + 8:end]
        if tag in (b"COMM", b"SSND", b"FVER"):
            if tag in seen:
                raise ValueError("duplicate required AIFC chunk")
            seen.add(tag)
        if tag == b"FVER" and payload != struct.pack(">I", 0xA2805140):
            raise ValueError("unsupported AIFC version")
        if tag == b"COMM":
            if length < 23:
                raise ValueError("truncated AIFC COMM")
            channels, count, bits = struct.unpack_from(">hIh", payload)
            compression = payload[18:22]
            if channels != 1 or bits != 16 or compression not in (b"VAPC", b"NONE"):
                raise ValueError("expected mono VAPC or big-endian PCM16 AIFC")
            result.update(type=0 if compression == b"VAPC" else 1,
                          sampleCount=count, sampleRate=_read_extended(payload[8:18]))
        elif tag == b"SSND":
            skip, block = struct.unpack_from(">II", payload)
            if block or 8 + skip > len(payload):
                raise ValueError("unsupported or truncated AIFC SSND block layout")
            result["audio"] = payload[8 + skip:]
        elif tag == b"APPL" and payload[:4] == b"stoc":
            if len(payload) < 5:
                raise ValueError("truncated stoc APPL chunk")
            n = payload[4]
            name = payload[5:5 + n]
            start = 4 + ((1 + n + 1) & ~1)
            body = payload[start:]
            if name == b"VADPCMCODES":
                if result["book"] is not None:
                    raise ValueError("duplicate VADPCMCODES")
                version, order, predictors = struct.unpack_from(">HHH", body)
                if version != 1 or not order or not predictors or len(body) != 6 + 16 * order * predictors:
                    raise ValueError("invalid VADPCMCODES")
                result["book"] = {"order": order, "npredictors": predictors,
                    "coefficients": list(struct.unpack_from(">" + str(order * predictors * 8) + "h", body, 6))}
            elif name == b"VADPCMLOOPS":
                if result["loop"] is not None or len(body) != 48:
                    raise ValueError("expected one complete VADPCMLOOPS record")
                version, count, loop_start, loop_end, repeats, *state = struct.unpack(">HHIII16h", body)
                if version != 1 or count != 1:
                    raise ValueError("unsupported VADPCMLOOPS version/count")
                result["loop"] = {"start": loop_start, "end": loop_end, "count": repeats, "state": state}
        offset = end + (length & 1)
    if seen != {b"COMM", b"SSND", b"FVER"}:
        raise ValueError("AIFC missing required chunks")
    divisor = 9 if result["type"] == 0 else 2
    expected = len(result["audio"]) // divisor * (16 if result["type"] == 0 else 1)
    if len(result["audio"]) % divisor or result["sampleCount"] > expected:
        raise ValueError("AIFC audio frame geometry mismatch")
    if result["type"] == 0 and result["book"] is None:
        raise ValueError("VAPC missing codebook")
    if result["type"] == 1 and result["loop"] is not None:
        result["loop"].pop("state")
    return result


def _fill_runs(data: bytes, covered: bytearray, label: str) -> list[dict]:
    fills = []
    offset = 0
    while offset < len(data):
        if covered[offset]:
            offset += 1
            continue
        end = offset + 1
        while end < len(data) and not covered[end]:
            end += 1
        # These native banks have only zero alignment and tail fills. An
        # unexplained record/sample is a diagnosis error, never a byte dump.
        if any(data[offset:end]):
            raise ValueError(f"{label}: non-padding orphan at {offset:#x}..{end:#x}")
        fills.append({"offset": offset, "length": end - offset, "value": 0})
        offset = end
    return fills


def decode(bank: bytes, table: bytes, wave_prefix: str = "waves/bank") -> tuple[dict, dict, dict[str, bytes]]:
    """Decode entire native pair; return bank/table specs and relative AIFCs."""
    records: dict[int, dict] = {}
    covered = bytearray(len(bank))
    def claim(offset: int, size: int) -> None:
        if offset < 0 or size < 0 or offset + size > len(bank):
            raise ValueError(f"bank record exceeds bounds at {offset:#x}")
        if any(covered[offset:offset + size]):
            raise ValueError(f"overlapping bank records at {offset:#x}")
        covered[offset:offset + size] = b"\1" * size

    def record(kind: str, offset: int) -> str | None:
        if not offset:
            return None
        if offset in records:
            if records[offset]["type"] != kind:
                raise ValueError(f"inconsistent record alias at {offset:#x}")
            return records[offset]["id"]
        r = {"id": f"{kind}_{offset:06x}", "type": kind, "offset": offset}
        records[offset] = r
        def unpack(fmt: str):
            return struct.unpack_from(">" + fmt, bank, offset)
        def refs(kind: str, count: int, start: int):
            if count < 0:
                raise ValueError("negative native pointer-array count")
            return [record(kind, p) for p in struct.unpack_from(">" + str(count) + "I", bank, offset + start)]
        if kind == "ALBank":
            count, flags, pad, rate, percussion = unpack("hBBiI")
            claim(offset, 12 + 4 * count)
            r.update(flags=flags, padding=pad, sampleRate=rate,
                     percussion=record("ALInstrument", percussion), instruments=refs("ALInstrument", count, 12))
        elif kind == "ALInstrument":
            *values, bend, count = unpack("12Bhh")
            claim(offset, 16 + 4 * count)
            r.update(zip(INSTRUMENT_FIELDS, values))
            r.update(bendRange=bend, sounds=refs("ALSound", count, 16))
        elif kind == "ALSound":
            env, key, wave, pan, volume, flags, pad = unpack("IIIBBBB")
            claim(offset, 16)
            r.update(envelope=record("ALEnvelope", env), keyMap=record("ALKeyMap", key),
                     wavetable=record("ALWaveTable", wave), samplePan=pan, sampleVolume=volume,
                     flags=flags, padding=pad)
        elif kind == "ALEnvelope":
            attack, decay, release, av, dv, pad = unpack("iiiBBH")
            claim(offset, 16)
            r.update(attackTime=attack, decayTime=decay, releaseTime=release,
                     attackVolume=av, decayVolume=dv, padding=pad)
        elif kind == "ALKeyMap":
            claim(offset, 6)
            r.update(zip(KEY_FIELDS, unpack("5Bb")))
        elif kind == "ALWaveTable":
            base, length, typ, flags, pad, loop, book = unpack("IiBBHII")
            claim(offset, 20)
            if typ not in (0, 1) or length < 0 or base + length > len(table):
                raise ValueError(f"invalid wavetable at {offset:#x}")
            r.update(base=base, length=length, waveType="ADPCM" if typ == 0 else "RAW16",
                     flags=flags, padding=pad, loop=record("ALADPCMloop" if typ == 0 else "ALRawLoop", loop))
            if typ == 0:
                r["book"] = record("ALADPCMBook", book)
            else:
                r["unusedUnionWord"] = book
        elif kind == "ALADPCMBook":
            order, predictors = unpack("ii")
            if order <= 0 or predictors <= 0:
                raise ValueError("invalid native codebook geometry")
            claim(offset, 8 + 16 * order * predictors)
            r["_metadata"] = {"order": order, "npredictors": predictors,
                "coefficients": list(struct.unpack_from(">" + str(order * predictors * 8) + "h", bank, offset + 8))}
        elif kind in ("ALADPCMloop", "ALRawLoop"):
            size = 44 if kind == "ALADPCMloop" else 12
            claim(offset, size)
            start, end, count = unpack("III")
            r["_metadata"] = {"start": start, "end": end, "count": count}
            if kind == "ALADPCMloop":
                r["_metadata"]["state"] = list(struct.unpack_from(">16h", bank, offset + 12))
        return r["id"]

    revision, count = struct.unpack_from(">hh", bank)
    if count < 0:
        raise ValueError("negative bank count")
    claim(0, 4 + count * 4)
    banks = [record("ALBank", p) for p in struct.unpack_from(">" + str(count) + "I", bank, 4)]
    by_id = {r["id"]: r for r in records.values()}
    rates = {r["sampleRate"] for r in records.values() if r["type"] == "ALBank"}
    if len(rates) != 1:
        raise ValueError("AIFC extraction needs one unambiguous bank sample rate")
    rate = next(iter(rates))
    table_covered = bytearray(len(table))
    samples = []
    assets = {}
    sharing = {}
    for r in sorted(records.values(), key=lambda r: r["offset"]):
        if r["type"] != "ALWaveTable":
            continue
        key = (r["base"], r["length"], r["waveType"], r.get("book"), r["loop"])
        if key in sharing:
            r["sample"] = sharing[key]
            continue
        sample_id = f"sample_{r['base']:06x}_{r['offset']:06x}"
        sharing[key] = sample_id
        r["sample"] = sample_id
        typ = 0 if r["waveType"] == "ADPCM" else 1
        divisor = 9 if typ == 0 else 2
        audio_length = r["length"] - r["length"] % divisor
        start = r["base"]
        tail = table[start + audio_length:start + r["length"]]
        if any(tail):
            raise ValueError(f"non-padding incomplete wave frame at {start + audio_length:#x}")
        book = by_id[r["book"]]["_metadata"] if typ == 0 else None
        loop = by_id[r["loop"]]["_metadata"] if r["loop"] else None
        asset = f"{wave_prefix}/{sample_id}.aifc"
        assets[asset] = write_aifc(table[start:start + audio_length], typ, rate, book, loop)
        samples.append({"id": sample_id, "offset": start, "asset": asset})
        table_covered[start:start + audio_length] = b"\1" * audio_length
        for ref in (r.get("book"), r["loop"]):
            if ref:
                by_id[ref].setdefault("sourceSample", sample_id)
    for r in records.values():
        r.pop("_metadata", None)
    bank_spec = {"format": "snap-sdk-bank-v1", "size": len(bank),
                 "header": {"revision": revision, "banks": banks},
                 "records": sorted(records.values(), key=lambda r: r["offset"]),
                 "padding": _fill_runs(bank, covered, "bank")}
    table_spec = {"format": "snap-sdk-table-v1", "size": len(table), "samples": samples,
                  "padding": _fill_runs(table, table_covered, "table")}
    return bank_spec, table_spec, assets


class _Image:
    def __init__(self, size: int):
        self.data = bytearray(size)
        self.covered = bytearray(size)

    def put(self, offset: int, data: bytes, label: str, overlap: bool = False) -> None:
        if offset < 0 or offset + len(data) > len(self.data):
            raise ValueError(f"{label} exceeds native image bounds")
        for i, value in enumerate(data, offset):
            if self.covered[i] and (not overlap or self.data[i] != value):
                raise ValueError(f"{label}: conflicting overlap at {i:#x}")
        self.data[offset:offset + len(data)] = data
        self.covered[offset:offset + len(data)] = b"\1" * len(data)

    def finish(self, padding: list[dict]) -> bytes:
        for fill in padding:
            self.put(fill["offset"], bytes([fill["value"]]) * fill["length"], "padding")
        if not all(self.covered):
            raise ValueError(f"unrepresented physical byte at {self.covered.index(0):#x}")
        return bytes(self.data)


def encode(bank: dict, table: dict, wave_root: Path | str = ".",
           read_asset: Callable[[str], bytes] | None = None) -> tuple[bytes, bytes]:
    """Build both complete native images solely from JSON and AIFC sources."""
    if bank["format"] != "snap-sdk-bank-v1" or table["format"] != "snap-sdk-table-v1":
        raise ValueError("unsupported native audio source format")
    loader = read_asset if read_asset is not None else lambda asset: (Path(wave_root) / asset).read_bytes()
    records = {r["id"]: r for r in bank["records"]}
    if len(records) != len(bank["records"]):
        raise ValueError("duplicate bank record ID")
    samples = {}
    table_image = _Image(table["size"])
    for sample in table["samples"]:
        if sample["id"] in samples:
            raise ValueError("duplicate table sample ID")
        audio = read_aifc(loader(sample["asset"]))
        samples[sample["id"]] = (sample, audio)
        table_image.put(sample["offset"], audio["audio"], sample["id"], overlap=True)
    table_data = table_image.finish(table["padding"])
    def pointer(ref: str | None, kind: str) -> int:
        if ref is None:
            return 0
        r = records[ref]
        if r["type"] != kind or r["offset"] == 0:
            raise ValueError(f"invalid {kind} reference {ref}")
        return r["offset"]
    def ptrs(refs: list, kind: str) -> bytes:
        return struct.pack(">" + str(len(refs)) + "I", *(pointer(ref, kind) for ref in refs))
    def metadata(r: dict) -> dict:
        key = "book" if r["type"] == "ALADPCMBook" else "loop"
        value = samples[r["sourceSample"]][1][key]
        if value is None:
            raise ValueError(f"missing authoritative {key} in {r['sourceSample']}")
        return value
    image = _Image(bank["size"])
    header = bank["header"]
    image.put(0, struct.pack(">hh", header["revision"], len(header["banks"]))
              + ptrs(header["banks"], "ALBank"), "ALBankFile")
    for r in bank["records"]:
        kind = r["type"]
        if kind == "ALBank":
            data = struct.pack(">hBBiI", len(r["instruments"]), r["flags"], r["padding"],
                               r["sampleRate"], pointer(r["percussion"], "ALInstrument"))
            data += ptrs(r["instruments"], "ALInstrument")
        elif kind == "ALInstrument":
            data = struct.pack(">12Bhh", *(r[f] for f in INSTRUMENT_FIELDS),
                               r["bendRange"], len(r["sounds"])) + ptrs(r["sounds"], "ALSound")
        elif kind == "ALSound":
            data = struct.pack(">IIIBBBB", pointer(r["envelope"], "ALEnvelope"),
                               pointer(r["keyMap"], "ALKeyMap"), pointer(r["wavetable"], "ALWaveTable"),
                               r["samplePan"], r["sampleVolume"], r["flags"], r["padding"])
        elif kind == "ALEnvelope":
            data = struct.pack(">iiiBBH", r["attackTime"], r["decayTime"], r["releaseTime"],
                               r["attackVolume"], r["decayVolume"], r["padding"])
        elif kind == "ALKeyMap":
            data = struct.pack(">5Bb", *(r[f] for f in KEY_FIELDS))
        elif kind == "ALWaveTable":
            if r["waveType"] not in ("ADPCM", "RAW16"):
                raise ValueError("unknown native wavetable type")
            typ = 0 if r["waveType"] == "ADPCM" else 1
            sample, audio = samples[r["sample"]]
            if sample["offset"] != r["base"] or audio["type"] != typ:
                raise ValueError(f"wavetable/sample layout mismatch in {r['id']}")
            tail = r["length"] - len(audio["audio"])
            divisor = 9 if typ == 0 else 2
            if not 0 <= tail < divisor or r["base"] + r["length"] > len(table_data):
                raise ValueError(f"wavetable length does not fit sample in {r['id']}")
            if any(table_data[r["base"] + len(audio["audio"]):r["base"] + r["length"]]):
                raise ValueError("non-padding partial sample frame")
            for key, expected_kind in (("book", "ALADPCMBook"),
                                       ("loop", "ALADPCMloop" if typ == 0 else "ALRawLoop")):
                if key == "book" and typ == 1:
                    continue
                ref = r.get(key)
                expected = metadata(records[ref]) if ref else None
                if audio[key] != expected:
                    raise ValueError(f"divergent shared {key} metadata in {r['sample']}; authority: {ref}")
                pointer(ref, expected_kind)
            data = struct.pack(">IiBBHII", r["base"], r["length"], typ, r["flags"], r["padding"],
                    pointer(r["loop"], "ALADPCMloop" if typ == 0 else "ALRawLoop"),
                    pointer(r["book"], "ALADPCMBook") if typ == 0 else r["unusedUnionWord"])
        elif kind == "ALADPCMBook":
            book = metadata(r)
            data = struct.pack(">ii", book["order"], book["npredictors"])
            data += struct.pack(">" + str(len(book["coefficients"])) + "h", *book["coefficients"])
        elif kind in ("ALADPCMloop", "ALRawLoop"):
            loop = metadata(r)
            data = struct.pack(">III", loop["start"], loop["end"], loop["count"])
            if kind == "ALADPCMloop":
                data += struct.pack(">16h", *loop["state"])
        else:
            raise ValueError(f"unknown SDK record type {kind}")
        image.put(r["offset"], data, r["id"])
    return image.finish(bank["padding"]), table_data


def extract(rom: bytes, bank_start: int, table_start: int, table_end: int,
            bank_path: Path, table_path: Path) -> tuple[dict, dict]:
    """Split from authoritative ROM bounds, never from old extracted blobs."""
    if not 0 <= bank_start < table_start < table_end <= len(rom):
        raise ValueError("invalid audio pair ROM bounds")
    if bank_path.parent != table_path.parent:
        raise ValueError("bank/table JSON must share their relative asset root")
    bank, table, assets = decode(rom[bank_start:table_start], rom[table_start:table_end],
                                 f"waves/{bank_path.stem}")
    bank_path.parent.mkdir(parents=True, exist_ok=True)
    bank_path.write_text(json.dumps(bank, indent=2) + "\n", encoding="utf-8")
    table_path.write_text(json.dumps(table, indent=2) + "\n", encoding="utf-8")
    for relative, data in assets.items():
        path = bank_path.parent / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)
    return bank, table


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    split = commands.add_parser("extract", help="extract a complete bank/table pair from ROM")
    split.add_argument("rom", type=Path)
    split.add_argument("bank_json", type=Path)
    split.add_argument("table_json", type=Path)
    for name in ("bank-start", "table-start", "table-end"):
        split.add_argument("--" + name, required=True, type=lambda value: int(value, 0))
    build = commands.add_parser("build", help="build native images from JSON and AIFC only")
    build.add_argument("bank_json", type=Path)
    build.add_argument("table_json", type=Path)
    build.add_argument("bank_bin", type=Path)
    build.add_argument("table_bin", type=Path)
    args = parser.parse_args()
    if args.command == "extract":
        extract(args.rom.read_bytes(), args.bank_start, args.table_start, args.table_end,
                args.bank_json, args.table_json)
    else:
        if args.bank_json.parent != args.table_json.parent:
            parser.error("bank/table JSON must share their relative asset root")
        bank, table = encode(json.loads(args.bank_json.read_text(encoding="utf-8")),
                             json.loads(args.table_json.read_text(encoding="utf-8")), args.bank_json.parent)
        for path, data in ((args.bank_bin, bank), (args.table_bin, table)):
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(data)


if __name__ == "__main__":
    main()
