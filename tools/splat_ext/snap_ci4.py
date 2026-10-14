import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))

from snap_image_common import SnapIndexedImage
import n64img.image


class N64SegSnap_ci4(SnapIndexedImage):
    image_type = "ci4"
    bytes_per_pixel = 0.5

    def __init__(self, *args, **kwargs):
        kwargs["img_cls"] = n64img.image.CI4
        super().__init__(*args, **kwargs)
