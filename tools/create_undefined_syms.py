#! /usr/bin/python3

import glob

def find_func(string):
    for fl in glob.glob('asm/*.s'):
        with open(fl) as f:
            contents = f.read()
        if string in contents:
            return True
    return False

import re

syms = set()

with open("errors.txt") as f:
    for line in f.readlines():
        if "undefined reference to" in line:
            pattern = r"[D|func]_[0-9A-F]{8}"
            res = re.findall(pattern, line)
            if len(res) > 0:
                syms.add(res[0])

with open("undefined_syms.txt", "w", newline="\n") as undefined_f:
    with open("globals.inc", "w", newline="\n") as globals_f:
        for item in sorted(syms):
            if item.startswith("c_"):
                func = "fun" + item
                if find_func(func + ":"):
                    globals_f.write(".global " + func + "\n")
                else:
                    undefined_f.write(func + " = 0x" + item.split("_")[1] + ";\n")
            else:
                undefined_f.write(item + " = 0x" + item.split("_")[1] + ";\n")
