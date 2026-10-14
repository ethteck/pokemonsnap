import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from snap_image_common import SnapIndexedImage
import n64img.image


class N64SegSnap_ci8(SnapIndexedImage):
    image_type = "ci8"
    bytes_per_pixel = 1

    def __init__(self, *args, **kwargs):
        kwargs["img_cls"] = n64img.image.CI8
        super().__init__(*args, **kwargs)
