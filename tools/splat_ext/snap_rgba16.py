import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from snap_image_common import SnapShuffledImage
from splat.segtypes.n64.rgba16 import N64SegRgba16


class N64SegSnap_rgba16(SnapShuffledImage, N64SegRgba16):
    image_type = "rgba16"
    bytes_per_pixel = 2
