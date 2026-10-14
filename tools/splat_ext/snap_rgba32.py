import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from snap_image_common import SnapShuffledImage
from splat.segtypes.n64.rgba32 import N64SegRgba32


class N64SegSnap_rgba32(SnapShuffledImage, N64SegRgba32):
    image_type = "rgba32"
    bytes_per_pixel = 4
