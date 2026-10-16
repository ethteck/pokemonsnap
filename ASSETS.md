# Assets

## Demo scripts

Extraction writes the beach and tunnel demo recordings to
`assets/demo_script_beach.yaml` and `assets/demo_script_tunnel.yaml`. Edit the
header and controller `inputs` in these ignored files, then run `ninja` to
regenerate the native recordings and rebuild the ROM. Running extraction again
overwrites these edits, so save any recordings you want to keep elsewhere.
Configuration rescans ROM segments to regenerate complete undefined linker
symbols; cached scans can omit symbols needed when edited data triggers a relink.

The YAML preserves the header's `dataSize` independently of the physical input
count, the reserved header word, and the tunnel recording's incomplete final
input (`partialInput`). Do not complete that prefix or add padding when
rebuilding an unchanged recording. Field names follow the native `IdleScript`
header and `ControllerInput` records; `header.reserved` preserves `unk_04`.

For standalone conversion:

```sh
uv run python tools/demo_script.py extract input.bin output.yaml
uv run python tools/demo_script.py build input.yaml output.bin
```
