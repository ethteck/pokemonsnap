#!/usr/bin/env python3
"""Plan existing-slot AIFC overrides and emit IDO-compiled SDK bank aggregates.

Only padding is emitted as byte arrays. All disk pointers are offsetof constants,
not relocations; samples remain in the separately linked native table object.
"""
from __future__ import annotations

import argparse
import copy
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from audio_bank import INSTRUMENT_FIELDS, KEY_FIELDS, encode, read_aifc


def write_changed(path: Path, data: bytes) -> None:
    if path.exists() and path.read_bytes() == data:
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)


def overrides_in(directory: Path, sample_ids: set[str]) -> dict[str, Path]:
    """Reject typo/unsupported names instead of silently ignoring authored audio."""
    if not directory.exists():
        return {}
    result = {}
    for path in sorted(directory.iterdir()):
        if not path.is_file() or path.suffix != ".aifc" or path.stem not in sample_ids:
            raise ValueError(f"unsupported bank override {path}; use an existing sample ID with .aifc")
        result[path.stem] = path
    return result


def inventory(table_path: Path, directory: Path, output: Path) -> None:
    table = json.loads(table_path.read_text())
    paths = overrides_in(directory, {s["id"] for s in table["samples"]})
    entries = []
    for sample_id, path in paths.items():
        stat = path.stat()
        entries.append([sample_id, path.name, stat.st_mtime_ns, stat.st_size])
    write_changed(output, (json.dumps(entries, separators=(",", ":")) + "\n").encode())


def align(value: int, alignment: int) -> int:
    return (value + alignment - 1) & -alignment


def record_size(record: dict) -> int:
    kind = record["type"]
    if kind == "ALBank":
        return 12 + 4 * len(record["instruments"])
    if kind == "ALInstrument":
        return 16 + 4 * len(record["sounds"])
    if kind == "ALADPCMBook":
        return 8 + 2 * len(record["_metadata"]["coefficients"])
    return {"ALSound": 16, "ALEnvelope": 16, "ALKeyMap": 6,
            "ALWaveTable": 20, "ALADPCMloop": 44, "ALRawLoop": 12}[kind]


def plan(bank: dict, table: dict, read_asset, overrides: dict[str, bytes] | None = None):
    """Return an isolated layout and parsed samples; absent/self overrides are exact.

    Metadata retains original identities when equal. A divergent shared book or
    loop receives a new typed record rather than mutating its other users.
    """
    encode(bank, table, read_asset=read_asset)  # Validate the authoritative stock layout.
    bank, table = copy.deepcopy(bank), copy.deepcopy(table)
    samples = {s["id"]: read_aifc(read_asset(s["asset"])) for s in table["samples"]}
    original = copy.deepcopy(samples)
    records = {r["id"]: r for r in bank["records"]}
    for record in bank["records"]:
        if record["type"] in ("ALADPCMBook", "ALADPCMloop", "ALRawLoop"):
            key = "book" if record["type"] == "ALADPCMBook" else "loop"
            record["_metadata"] = copy.deepcopy(samples[record["sourceSample"]][key])
    rates = {r["sampleRate"] for r in bank["records"] if r["type"] == "ALBank"}
    if len(rates) != 1:
        raise ValueError("bank requires one unambiguous sample rate")
    rate = next(iter(rates))
    changed = set()
    for sample_id, data in (overrides or {}).items():
        if sample_id not in samples:
            raise ValueError(f"unknown existing sample ID {sample_id}")
        audio = read_aifc(data)
        if audio["sampleRate"] != rate:
            raise ValueError(f"{sample_id}: sample rate must remain {rate}; overrides do not retune sounds")
        # The disk format stores coded frame lengths, not precompression trim.
        capacity = len(audio["audio"]) // (9 if audio["type"] == 0 else 2) * (16 if audio["type"] == 0 else 1)
        loop = audio["loop"]
        if loop and not 0 <= loop["start"] <= loop["end"] <= capacity:
            raise ValueError(f"{sample_id}: loop exceeds native sample frames")
        if loop and loop["count"] and loop["start"] == loop["end"]:
            raise ValueError(f"{sample_id}: active loop must have positive length")
        native_fields = ("type", "sampleRate", "audio", "book", "loop")
        if any(audio[key] != original[sample_id][key] for key in native_fields):
            samples[sample_id] = audio
            changed.add(sample_id)
    if not changed:
        return bank, table, samples

    # Repack every sample in stable extracted order, keeping physical aliases
    # only when their original storage identity AND replacement bytes agree.
    cursor = 0
    placements = {}
    by_sample = {s["id"]: s for s in table["samples"]}
    waves = [r for r in bank["records"] if r["type"] == "ALWaveTable"]
    padding = []
    for sample in table["samples"]:
        sample_id = sample["id"]
        audio = samples[sample_id]
        related = [r for r in waves if r["sample"] == sample_id]
        native_length = (len(audio["audio"]) if sample_id in changed else max(r["length"] for r in related))
        identity = (sample["offset"], audio["audio"], native_length)
        if identity in placements:
            sample["offset"] = placements[identity]
            continue
        start = align(cursor, 8)
        if start > cursor:
            padding.append({"offset": cursor, "length": start - cursor, "value": 0})
        sample["offset"] = start
        placements[identity] = start
        tail = native_length - len(audio["audio"])
        if tail:
            padding.append({"offset": start + len(audio["audio"]), "length": tail, "value": 0})
        cursor = start + native_length
    size = align(cursor, 16)
    if size > cursor:
        padding.append({"offset": cursor, "length": size - cursor, "value": 0})
    table.update(size=size, padding=padding)

    # Prefer the referenced original record, then an equal existing record.
    # This both retains stock sharing and re-shares identical authored metadata.
    def metadata_ref(kind: str, value, preferred: str | None) -> str | None:
        if value is None:
            return None
        if preferred in records:
            record = records[preferred]
            if record["type"] == kind and record["_metadata"] == value:
                return preferred
        for record in bank["records"]:
            if record["type"] == kind and record["_metadata"] == value:
                return record["id"]
        record_id = f"{kind}_override_{len(bank['records']):06x}"
        record = {"id": record_id, "type": kind, "_metadata": copy.deepcopy(value)}
        bank["records"].append(record)
        records[record_id] = record
        return record_id

    for wave in waves:
        sample_id = wave["sample"]
        audio = samples[sample_id]
        wave["base"] = by_sample[sample_id]["offset"]
        if sample_id in changed:
            wave["length"] = len(audio["audio"])
        wave["waveType"] = "ADPCM" if audio["type"] == 0 else "RAW16"
        wave["loop"] = metadata_ref("ALADPCMloop" if audio["type"] == 0 else "ALRawLoop",
                                     audio["loop"], wave["loop"])
        if audio["type"] == 0:
            wave["book"] = metadata_ref("ALADPCMBook", audio["book"], wave.get("book"))
            wave.pop("unusedUnionWord", None)
        else:
            wave.pop("book", None)
            wave.setdefault("unusedUnionWord", 0)

    # Drop metadata made unreachable by a replacement, retain every sound,
    # envelope, keymap, instrument and all of their original fields.
    used = {w.get(key) for w in waves for key in ("book", "loop")}
    bank["records"] = [r for r in bank["records"] if r["type"] not in
                       ("ALADPCMBook", "ALADPCMloop", "ALRawLoop") or r["id"] in used]
    cursor = 4 + 4 * len(bank["header"]["banks"])
    padding = []
    for record in bank["records"]:
        alignment = 8 if record["type"] == "ALADPCMBook" else 1 if record["type"] == "ALKeyMap" else 4
        start = align(cursor, alignment)
        if start > cursor:
            padding.append({"offset": cursor, "length": start - cursor, "value": 0})
        record["offset"] = start
        cursor = start + record_size(record)
    size = align(cursor, 16)
    if size > cursor:
        padding.append({"offset": cursor, "length": size - cursor, "value": 0})
    bank.update(size=size, padding=padding)
    return bank, table, samples


# SDK types with implicit padding need explicit disk wrappers so nonzero native
# padding remains representable. Variable SDK arrays likewise need exact counts.
PREAMBLE = '''/* Generated from ignored native graph/AIFC assets. Do not edit. */
#include <ultra64.h>
#include <PR/libaudio.h>
#include <macros.h>

typedef struct {
    ALMicroTime attackTime, decayTime, releaseTime;
    u8 attackVolume, decayVolume;
    u16 padding;
} DiskEnvelope;
typedef struct {
    ALEnvelope *envelope;
    ALKeyMap *keyMap;
    ALWaveTable *wavetable;
    ALPan samplePan;
    u8 sampleVolume, flags, padding;
} DiskSound;
typedef struct {
    u8 *base;
    s32 len;
    u8 type, flags;
    u16 padding;
    union {
        ALADPCMWaveInfo adpcmWave;
        struct { ALRawLoop *loop; u32 unused; } rawWave;
    } waveInfo;
} DiskWave;
#define CHECK(name, expr) typedef char check_##name[(expr) ? 1 : -1]
CHECK(pointer_size, sizeof(void *) == 4);
CHECK(envelope_size, sizeof(DiskEnvelope) == sizeof(ALEnvelope));
CHECK(envelope_volume, offsetof(DiskEnvelope, attackVolume) == offsetof(ALEnvelope, attackVolume));
CHECK(sound_size, sizeof(DiskSound) == sizeof(ALSound));
CHECK(sound_flags, offsetof(DiskSound, flags) == offsetof(ALSound, flags));
CHECK(wave_size, sizeof(DiskWave) == sizeof(ALWaveTable));
CHECK(wave_union, offsetof(DiskWave, waveInfo) == offsetof(ALWaveTable, waveInfo));
CHECK(key_size, sizeof(ALKeyMap) == 6);
CHECK(loop_size, sizeof(ALADPCMloop) == 44);
CHECK(raw_loop_size, sizeof(ALRawLoop) == 12);
'''


def emit_c(bank: dict, symbol: str) -> str:
    """Emit one typed .data aggregate, including all physical padding inline."""
    if not symbol.isidentifier():
        raise ValueError("invalid C aggregate symbol")
    lines = [PREAMBLE]
    count = len(bank["header"]["banks"])
    lines.append(f"typedef struct {{ s16 revision, bankCount; ALBank *bankArray[{count}]; }} DiskHeader;")
    lines.append("CHECK(header_array, offsetof(DiskHeader, bankArray) == offsetof(ALBankFile, bankArray));")
    declarations = []
    initializers = []
    assertions = []

    def pointer(ref, kind):
        return f"({kind} *)offsetof(AudioBankImage, {ref})" if ref else f"({kind} *)0"

    def values(items):
        return "{ " + ", ".join(str(x) for x in items) + " }"

    def refs(items, kind):
        return values(pointer(ref, kind) for ref in items)

    def add(name, typ, offset, size, initializer):
        declarations.append(f"    {typ} {name};")
        initializers.append("    " + initializer + ",")
        assertions.append(f"CHECK(offset_{name}, offsetof(AudioBankImage, {name}) == {offset});")
        assertions.append(f"CHECK(size_{name}, sizeof(((AudioBankImage *)0)->{name}) == {size});")

    header = bank["header"]
    add("header", "DiskHeader", 0, 4 + count * 4,
        values([header["revision"], count, refs(header["banks"], "ALBank")]))
    spans = [(r["offset"], "record", r) for r in bank["records"]]
    spans += [(p["offset"], "padding", p) for p in bank["padding"]]
    for offset, category, r in sorted(spans, key=lambda item: item[0]):
        if category == "padding":
            name = f"padding_{offset:06x}"
            declarations.append(f"    u8 {name}[{r['length']}];")
            initializers.append("    " + ("{ 0 }" if r["value"] == 0 else values([r["value"]] * r["length"])) + ",")
            assertions.append(f"CHECK(offset_{name}, offsetof(AudioBankImage, {name}) == {offset});")
            continue
        kind, name = r["type"], r["id"]
        if not name.isidentifier():
            raise ValueError(f"invalid record identifier {name}")
        typ = kind
        if kind == "ALBank":
            typ = f"Disk_{name}"
            n = len(r["instruments"])
            array = f"ALInstrument *instArray[{n}];" if n else ""
            lines.append(f"typedef struct {{ s16 instCount; u8 flags, pad; s32 sampleRate; ALInstrument *percussion; {array} }} {typ};")
            fields = [n, r["flags"], r["padding"], r["sampleRate"], pointer(r["percussion"], "ALInstrument")]
            if n:
                lines.append(f"CHECK(array_{name}, offsetof({typ}, instArray) == offsetof(ALBank, instArray));")
                fields.append(refs(r["instruments"], "ALInstrument"))
            init = values(fields)
        elif kind == "ALInstrument":
            typ = f"Disk_{name}"
            n = len(r["sounds"])
            fields = "; ".join("u8 " + field for field in INSTRUMENT_FIELDS)
            array = f"ALSound *soundArray[{n}];" if n else ""
            lines.append(f"typedef struct {{ {fields}; s16 bendRange, soundCount; {array} }} {typ};")
            fields = [*(r[f] for f in INSTRUMENT_FIELDS), r["bendRange"], n]
            if n:
                lines.append(f"CHECK(array_{name}, offsetof({typ}, soundArray) == offsetof(ALInstrument, soundArray));")
                fields.append(refs(r["sounds"], "ALSound"))
            init = values(fields)
        elif kind == "ALADPCMBook":
            typ = f"Disk_{name}"
            book = r["_metadata"]
            lines.append(f"typedef struct {{ s32 order, npredictors; s16 book[{len(book['coefficients'])}]; }} {typ};")
            lines.append(f"CHECK(array_{name}, offsetof({typ}, book) == offsetof(ALADPCMBook, book));")
            init = values([book["order"], book["npredictors"], values(book["coefficients"])])
        elif kind in ("ALADPCMloop", "ALRawLoop"):
            loop = r["_metadata"]
            fields = [loop["start"], loop["end"], loop["count"]]
            if kind == "ALADPCMloop":
                fields.append(values(loop["state"]))
            init = values(fields)
        elif kind == "ALKeyMap":
            init = values(r[f] for f in KEY_FIELDS)
        elif kind == "ALEnvelope":
            typ = "DiskEnvelope"
            init = values(r[f] for f in ("attackTime", "decayTime", "releaseTime", "attackVolume", "decayVolume", "padding"))
        elif kind == "ALSound":
            typ = "DiskSound"
            init = values([pointer(r["envelope"], "ALEnvelope"), pointer(r["keyMap"], "ALKeyMap"), pointer(r["wavetable"], "ALWaveTable"), r["samplePan"], r["sampleVolume"], r["flags"], r["padding"]])
        elif kind == "ALWaveTable":
            typ = "DiskWave"
            # Initialize the union's first (ADPCM) member for both disk types;
            # its second pointer word preserves RAW16's otherwise unused word.
            raw = r["waveType"] == "RAW16"
            loop_type = "ALRawLoop" if raw else "ALADPCMloop"
            loop = pointer(r["loop"], loop_type)
            if raw:
                loop = f"(ALADPCMloop *)({loop})"
            book = f"(ALADPCMBook *){r['unusedUnionWord']}" if raw else pointer(r["book"], "ALADPCMBook")
            init = values([f"(u8 *){r['base']}", r["length"], 1 if raw else 0, r["flags"], r["padding"], values([values([loop, book])])])
        else:
            raise ValueError(f"unknown bank record {kind}")
        add(name, typ, offset, record_size(r), init)
    lines += ["typedef struct {", *declarations, "} AudioBankImage;", *assertions,
              f"CHECK(image_size, sizeof(AudioBankImage) == {bank['size']});",
              f"AudioBankImage {symbol} = {{", *initializers, "};", ""]
    return "\n".join(lines)


def generate(bank_path: Path, table_path: Path, directory: Path, c_path: Path, table_bin: Path) -> None:
    bank = json.loads(bank_path.read_text())
    table = json.loads(table_path.read_text())
    paths = overrides_in(directory, {s["id"] for s in table["samples"]})
    stock_loader = lambda asset: (table_path.parent / asset).read_bytes()
    bank, table, samples = plan(bank, table, stock_loader,
                                {sample_id: path.read_bytes() for sample_id, path in paths.items()})
    # Reuse strict physical-layout validation; production bank bytes are NOT
    # emitted here. Its linker object comes only from compiling emit_c's types.
    from audio_bank import write_aifc
    by_asset = {s["asset"]: samples[s["id"]] for s in table["samples"]}
    def loader(asset):
        audio = by_asset[asset]
        return write_aifc(audio["audio"], audio["type"], int(audio["sampleRate"]), audio["book"], audio["loop"])
    _, table_data = encode(bank, table, read_asset=loader)
    write_changed(c_path, emit_c(bank, "audio_" + bank_path.stem).encode())
    write_changed(table_bin, table_data)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    scan = sub.add_parser("inventory")
    scan.add_argument("table_json", type=Path)
    scan.add_argument("overrides", type=Path)
    scan.add_argument("output", type=Path)
    build = sub.add_parser("generate")
    build.add_argument("bank_json", type=Path)
    build.add_argument("table_json", type=Path)
    build.add_argument("overrides", type=Path)
    build.add_argument("bank_c", type=Path)
    build.add_argument("table_bin", type=Path)
    args = parser.parse_args()
    try:
        if args.command == "inventory":
            inventory(args.table_json, args.overrides, args.output)
        else:
            generate(args.bank_json, args.table_json, args.overrides, args.bank_c, args.table_bin)
    except (ValueError, KeyError) as error:
        parser.exit(1, f"audio bank: {error}\n")


if __name__ == "__main__":
    main()
