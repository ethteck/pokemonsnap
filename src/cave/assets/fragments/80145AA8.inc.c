/* ROM 211858, VRAM 80145AA8: complete native animation command stream. */
struct Cave_Animation80145AA8 D_80145AA8_211858 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 100, { 12.566370964050293f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80145AA8_211858 },
};
