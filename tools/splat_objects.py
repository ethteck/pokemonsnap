#!/usr/bin/env python3
# Script to get a list of object files that will be in the linker script for a given splat file
import argparse
import sys
sys.path.append("./tools/splat")

from split import *

def main(config_path):
    # Load config
    with open(config_path) as f:
        config = yaml.load(f.read(), Loader=yaml.SafeLoader)

    options.initialize(config, config_path, None, None)
    options.set("modes", [])
    options.set("verbose", False)

    all_segments = initialize_segments(config["segments"])

    objs = ""

    for segment in all_segments:
        linker_entries = segment.get_linker_entries()
        for entry in linker_entries:
            objs += str(entry.object_path) + " "
    
    return objs


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Get objects for splat file',
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('yamls', nargs='+', help="Splat files")
    args = parser.parse_args()

    obj_lists = map(main, args.yamls)
    map(print, obj_lists)
    for obj_list in obj_lists:
        print(obj_list)
