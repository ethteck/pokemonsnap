# Assets

## MIDI sequence authoring

Extraction writes an ignored `assets/audio/sbk.yaml` manifest covering the
complete `0xAEFC10`–`0xAFEEE0` sequence region. Its 37 indexed slots retain
stock compressed tracks, physical fragment padding and logical table lengths.
With no overrides the generated `audio/sbk.bin.o` preserves the complete stock
region. The sequence table ROM label remains the native `ALSeqFile` identity.
The manifest and standalone extracted sequence sources are human-editable YAML.
Ninja takes its manifest dependency from Splat's YAML output path.

Configuration rescans segments rather than reusing Splat's segment cache, so
generated undefined linker symbols remain complete on repeated runs. Authored
overrides are outside the extraction outputs and are retained.

Use a standard synchronous Type 0 or Type 1 MIDI file with PPQN timing:

```sh
mkdir -p src/audio/midis
cp /path/to/authored.mid src/audio/midis/0.mid
ninja audio-mod
# Remove the override to restore the stock build, without cleaning:
rm src/audio/midis/0.mid
ninja build/pokemonsnap.ok
```

Override filenames are existing numeric song IDs `0` through `36`, with `.mid`
or `.midi` extensions; duplicate IDs and unknown filenames are errors. Plain
Ninja discovers additions, edits and removals automatically. Variable-size songs
repack the table and move later banks through their linked ROM labels. `audio-mod`
produces `build/pokemonsnap.mod.z64` with authentic CIC6103 header checksums;
the normal matching checksum gate is deliberately unchanged. ROM output is
16 MiB, with dynamic FF tail padding; overflow is rejected.

```sh
uv run tools/audio_sequence_bank.py export assets/audio/sbk.yaml /path/to/song.mid --slot 0
uv run tools/audio_midi.py export /path/to/compact.bin /path/to/song.mid
uv run tools/audio_midi.py import /path/to/song.mid /path/to/compact.bin
uv run tools/audio_seq.py extract /path/to/compact.bin /path/to/sequence.yaml
uv run tools/audio_seq.py build /path/to/sequence.yaml /path/to/rebuilt.bin
```

Export creates a standard Type 1 MIDI preview with native timing hints. Protected
`snap_native_v1_cseq_track_NN` names preserve compact track slots; versioned
sequencer-specific metadata binds native note durations, generated preview
releases and native EOT timing. Keep this metadata when reimporting an export:
native duration timers survive loop jumps and are not ordinary MIDI note-offs.
The importer removes only bound preview releases and preserves real explicit
releases. Partial, stale or conflicting hints fail rather than silently changing
playback. Visible channel messages, velocities and tempos remain the musical
source of truth; hints do not contain an original-song byte snapshot.
The first track, `snap_native_v1_preview_releases`, carries generated releases
before equal-tick events on other tracks. It is preview-only and consumes no
compact slot; keep it first so standard MIDI merging preserves release/pedal
ordering. Its bindings are validated against the editable musical tracks.
The versioned `SNAP_NATIVE` hint records embedded in MIDI retain their machine
JSON encoding; the generated override inventory cache also remains machine JSON.
Neither is a hand-edited YAML source.

Generic MIDI players preview the visible events, not SDK loop execution. Export
normalizes the actual first pass, repeated body and finite-loop tail from the
physical jump target, including compressed repeat-entry state. Unreachable bytes
after an infinite loop remain in the lossless YAML but are not preview music.

Ordinary authored Type 0/1 MIDI does not need native hints. Names `cseq_track_NN`
select compact slots; other tracks are packed into at most 16 playable slots.
Slot names that reverse source-order simultaneous events on a shared channel
are rejected rather than silently changing playback.
Notes pair FIFO per channel and key across synchronous tracks; unpaired notes
are errors. Explicit MIDI releases remain explicit native releases, so
zero-length notes and same-tick sustain ordering are retained. A conductor is
merged into a non-looping slot, or tick-zero tempo is placed before a musical
loop; later conductor changes require a non-looping slot. Channel messages,
tempo and trailing EOT silence are retained. Informational text/time/key-signature
metadata is omitted. Unsupported system events, asynchronous Type 2, SMPTE timing
and unknown markers are rejected.

Markers `loop_start` and `loop_end:N[:C]` specify SDK loop control. N is the reset
count, C is the initial current count (default N), each 0–255; current 255 loops
forever, current 0 falls through. Bare `loop_end` means forever. Loops must be
paired and non-nested per track, and infinite loops must advance time. Physical
back-offsets are recomputed after FE escaping, not copied from an exported song.
With ordinary loop markers, explicit releases must balance their NoteOns in
the same active loop body. Cross-boundary or unreachable releases require
native duration hints; otherwise looping would leak voices or repeat a
one-shot release. Normalized export supports flat stable repeat paths; nested
control flow and observable shared mutable-counter dependencies are rejected.

To use an exported song as ordinary authored MIDI instead, remove all native
sequencer-specific hints and protected track-name prefixes deliberately; its
visible preview releases then become explicit releases, not native timers.
Remove loop markers or balance releases within the authored loop. DAWs that
discard hints cannot preserve native loop/release semantics.

This is native Pokémon Snap `ALCSeq` playback, not a new runtime or new song IDs.
The loader derives playback buffer sizes from table lengths, but the total audio
heap remains fixed at `0x4B000`; large authored songs require capacity review.
No original per-slot size cap is imposed and no unbounded runtime capacity is
promised. Audio banks and wave tables remain stock assets in this branch.
