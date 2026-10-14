import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from snap_image_common import SnapShuffledImage
from splat.segtypes.n64.ia16 import N64SegIa16


class N64SegSnap_ia16(SnapShuffledImage, N64SegIa16):
    image_type = "ia16"
    bytes_per_pixel = 2
