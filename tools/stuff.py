import glob
from pathlib import Path


with open("stuff.txt") as f:
    lines = f.readlines()

for line in lines:
    line = line.rstrip()

    if "somewhere" not in line:
        print(line)
        continue

    file = line.split("/")[-1][:-1]

    loc = glob.glob(f"**/{file}.*", recursive=True)
    if not loc:
        print(line)
        continue

    dir = Path(loc[0]).relative_to("ultralib/src").parent

    line = line.replace("somewhere", str(dir))
    print(line)
