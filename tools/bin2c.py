#!/usr/bin/python3
import sys
from pathlib import Path

def main():
    srcfile, dstfile = sys.argv[1:]
    data = Path(srcfile).read_bytes()
    text = ", ".join(str(d) for d in data) + "\n"
    Path(dstfile).write_text(text)
    
if __name__ == "__main__":
    main()
