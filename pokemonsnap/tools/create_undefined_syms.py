import re

syms = set()

with open("../errors.txt") as f:
    for line in f.readlines():
        if "undefined reference to" in line:
            pattern = r"[D|func]_[0-9A-F]{8}"
            res = re.findall(pattern, line)
            syms.add(res[0])

with open("../undefined_syms_tmp.txt", "w", newline="\n") as f:
    for item in sorted(syms):
        pre = ""
        if item.startswith("c_"):
            pre = "fun"
        f.write(pre + item + " = 0x" + item.split("_")[1] + ";\n")
