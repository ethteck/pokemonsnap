/* ROM 211750, VRAM 801459A0: complete native animation command stream. */
struct Cave_Animation801459A0 D_801459A0_211750 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 46, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 15, { 1.5707963705062866f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 39, { 1.5707963705062866f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801459A0_211750 },
};
