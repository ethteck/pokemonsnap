/* ROM 211904, VRAM 80145B54: complete native animation command stream. */
struct Cave_Animation80145B54 D_80145B54_211904 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | SCALEY) << 15) | 0, { 0.0f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 100, { 12.566370964050293f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEY) << 15) | 10, { 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEY) << 15) | 10, { 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEY) << 15) | 23, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEY) << 15) | 10, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEY) << 15) | 20, { 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEY) << 15) | 10, { 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEY) << 15) | 17, { 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80145B54_211904 },
};
