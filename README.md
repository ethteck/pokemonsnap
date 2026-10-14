# pokemonsnap

[![US Bytes]](https://decomp.dev/ethteck/pokemonsnap/us)
[![US Functions]](https://decomp.dev/ethteck/pokemonsnap/us)

[US Bytes]: https://decomp.dev/ethteck/pokemonsnap/us.svg?mode=shield&label=US+Bytes&measure=matched_code_percent
[US Functions]: https://decomp.dev/ethteck/pokemonsnap/us.svg?mode=shield&label=US+Functions&measure=matched_functions_percent

A WIP decomp of Pokemon Snap.

Note: To use this repository, you must already have a rom for the game.

For Python dependencies:
`uv sync`

## Setup

1. Place the US Pokemon Snap rom (sha1: `edc7c49cc568c045fe48be0d18011c30f393cbaf`) into the root of the repository as "pokemonsnap.z64".
2. (one-time) Set up tools: `uv run configure.py --setup`
3. Run extraction and disassembly: `uv run configure.py`
4. Rebuild the rom: `ninja`

## Effect script banks

Extraction also decodes the nine particle-script banks (`common`, `beach`,
`tunnel`, `cave`, `river`, `volcano`, `valley`, `rainbow`, and `intro`) into
`assets/fx/script/<bank>.json`. These ROM-derived sources are ignored by Git;
do not commit them. Effect sprite extraction and rebuilding are unchanged.

The JSON describes the pointer table (including aliases), named script headers,
and semantic commands. It retains record offsets, padding fill runs, floating-point
bit patterns, and compact/extended command encodings so unedited sources rebuild
the original bank bytes. Preserve offsets and total bank size when editing.

`ninja` rebuilds each JSON source into its original `.bin` and `.bin.o` linker
input. The encoder reads only JSON, without consulting the ROM or an extracted
reference binary. The codec can also be used independently:

```sh
uv run tools/effect_scripts.py extract bank.bin bank.json
uv run tools/effect_scripts.py build bank.json rebuilt.bin
cmp bank.bin rebuilt.bin
```

Run `uv run configure.py` with the supported ROM to regenerate all nine sources.
This overwrites authored JSON; save edits elsewhere before re-extraction.
Configuration rescans ROM segments to regenerate complete undefined linker
symbols; cached scans can omit symbols needed when edited data triggers a relink.
