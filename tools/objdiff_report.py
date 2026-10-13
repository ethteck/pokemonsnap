#!/usr/bin/env python3
"""
Wrapper around `mapfile_parser objdiff_report` that leaves out objects which are
not decompilation targets: the entrypoint and the RSP microcode.

mapfile_parser has no option to exclude files, so the parsed mapfile is
filtered before the report is generated. All other arguments and the
decomp.yaml settings are handled by mapfile_parser as usual.

Usage: uv run tools/objdiff_report.py report.json [--version us]
"""

import sys
from pathlib import Path

from mapfile_parser import mapfile
from mapfile_parser.__main__ import mapfileParserMain
from mapfile_parser.frontends import objdiff_report

EXCLUDED_PATHS = (
    "build/asm/entry.s.o",
    "build/asm/data/rsp/",
)


def is_excluded(path: Path) -> bool:
    return str(path).startswith(EXCLUDED_PATHS)


def load_filtered_mapfile(mapPath: Path) -> mapfile.MapFile:
    mapFile = mapfile.MapFile.newFromMapFile(mapPath)
    segments = mapFile.copySegmentList()
    for segment in segments:
        segment.setFileList([f for f in segment.copyFileList() if not is_excluded(f.filepath)])
    mapFile.setSegmentList(segments)
    return mapFile


class _FilteredMapfileModule:
    """Stands in for the `mapfile` module used by the objdiff_report frontend."""

    class MapFile:
        newFromMapFile = staticmethod(load_filtered_mapfile)

    def __getattr__(self, name):
        return getattr(mapfile, name)


if __name__ == "__main__":
    objdiff_report.mapfile = _FilteredMapfileModule()
    sys.argv = [sys.argv[0], "objdiff_report", *sys.argv[1:]]
    mapfileParserMain()
