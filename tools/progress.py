#!/usr/bin/env python3

import argparse
import git
import os
import subprocess
import sys

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.join(script_dir, "..")
asm_dir = os.path.join(root_dir, "asm", "nonmatchings")
build_dir = os.path.join(root_dir, "build")
elf_path = os.path.join(build_dir, "pokemonsnap.elf")


def get_func_sizes():
    try:
        result = subprocess.run(["objdump", "-x", elf_path], stdout=subprocess.PIPE)
        nm_lines = result.stdout.decode().split("\n")
    except:
        print(
            f"Error: Could not run objdump on {elf_path} - make sure that the project is built"
        )
        sys.exit(1)

    sizes = {}
    total = 0

    for line in nm_lines:
        if " F " in line:
            components = line.split()
            size = int(components[4], 16)
            name = components[5]
            if not name.startswith(".L") or not name.startswith("D_"):
                total += size
                sizes[name] = size

    return sizes, total


def get_nonmatching_funcs():
    funcs = set()

    for root, dirs, files in os.walk(asm_dir):
        for f in files:
            if f.endswith(".s") and not f.startswith(".L"):
                funcs.add(f[:-2])

    return funcs


def get_funcs_sizes(sizes, matchings, nonmatchings):
    msize = 0
    nmsize = 0

    for func in matchings:
        msize += sizes[func]

    for func in nonmatchings:
        if func not in sizes:
            pass
            # print(func)
        else:
            nmsize += sizes[func]

    return msize, nmsize


def lerp(a, b, alpha):
    return a + (b - a) * alpha


def getProgressData() -> list:
    func_sizes, total_size = get_func_sizes()
    all_funcs = set(func_sizes.keys())

    nonmatching_funcs = get_nonmatching_funcs()
    matching_funcs = all_funcs - nonmatching_funcs

    matching_size, nonmatching_size = get_funcs_sizes(
        func_sizes, matching_funcs, nonmatching_funcs
    )

    if len(all_funcs) == 0:
        funcs_matching_ratio = 0.0
        matching_ratio = 0.0
    else:
        funcs_matching_ratio = (len(matching_funcs) / len(all_funcs)) * 100
        matching_ratio = (matching_size / total_size) * 100

    if matching_size + nonmatching_size != total_size:
        print("Warning: category/total size mismatch!\n")

    return (
        len(matching_funcs),
        len(all_funcs),
        funcs_matching_ratio,
        matching_size,
        total_size,
        matching_ratio,
    )


def main(frogress_key=None):
    func_sizes, total_size = get_func_sizes()
    all_funcs = set(func_sizes.keys())

    nonmatching_funcs = get_nonmatching_funcs()
    matching_funcs = all_funcs - nonmatching_funcs

    matching_size, nonmatching_size = get_funcs_sizes(
        func_sizes, matching_funcs, nonmatching_funcs
    )

    if len(all_funcs) == 0:
        funcs_matching_ratio = 0.0
        matching_ratio = 0.0
    else:
        funcs_matching_ratio = (len(matching_funcs) / len(all_funcs)) * 100
        matching_ratio = (matching_size / total_size) * 100

    if matching_size + nonmatching_size != total_size:
        print("Warning: category/total size mismatch!\n")
    print(
        f"{len(matching_funcs)} matched functions / {len(all_funcs)} total ({funcs_matching_ratio:.2f}%)"
    )
    print(
        f"{matching_size} matching bytes / {total_size} total ({matching_ratio:.2f}%)"
    )

    if frogress_key is not None:
        import requests

        frogress_url = "https://progress.deco.mp/data/pokemonsnap/us/"

        repo = git.Repo(root_dir)

        frogress_data = {
            "api_key": frogress_key,
            "entries": [
                {
                    "timestamp": repo.head.commit.committed_date,
                    "git_hash": repo.head.commit.hexsha,
                    "categories": {
                        "all": {
                            "bytes": matching_size,
                            "bytes/total": total_size,
                            "funcs": len(matching_funcs),
                            "funcs/total": len(all_funcs),
                        }
                    },
                }
            ],
        }
        response = requests.post(frogress_url, json=frogress_data)
        if response.status_code != 201:
            print("Error: Could not push progress data to frogress:" + response.text)
            sys.exit(1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Calculate the progress of the project"
    )
    parser.add_argument(
        "--frogress",
        help="Push progress data to progress.deco.mp with the provided key",
    )
    args = parser.parse_args()
    main(args.frogress)
