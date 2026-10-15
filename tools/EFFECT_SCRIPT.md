# Effect script banks

Extraction also decodes the nine particle-script banks (`common`, `beach`,
`tunnel`, `cave`, `river`, `volcano`, `valley`, `rainbow`, and `intro`) into
`assets/fx/script/<bank>.yaml`. These ROM-derived sources are ignored by Git;
do not commit them. Effect sprite extraction and rebuilding are unchanged.

The YAML describes the pointer table (including aliases), named script headers,
and semantic commands. It retains record offsets, padding fill runs, floating-point
bit patterns, and compact/extended command encodings so unedited sources rebuild
the original bank bytes. Preserve offsets and total bank size when editing.

`ninja` rebuilds each YAML source into its original `.bin` and `.bin.o` linker
input. The encoder reads only YAML, without consulting the ROM or an extracted
reference binary. The codec can also be used independently:

```sh
uv run tools/effect_scripts.py extract bank.bin bank.yaml
uv run tools/effect_scripts.py build bank.yaml rebuilt.bin
cmp bank.bin rebuilt.bin
```

Run `uv run configure.py` with the supported ROM to regenerate all nine sources.
This overwrites authored YAML; save edits elsewhere before re-extraction.
Configuration rescans ROM segments to regenerate complete undefined linker
symbols; cached scans can omit symbols needed when edited data triggers a relink.
