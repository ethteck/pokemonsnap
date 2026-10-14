/* ROM 211788, VRAM 801459D8: complete native animation command stream. */
struct Cave_Animation801459D8 D_801459D8_211788 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 1, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 62, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 4, { 3.1415927410125732f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 33, { 3.1415927410125732f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801459D8_211788 },
};
