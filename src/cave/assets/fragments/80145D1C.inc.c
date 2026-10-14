/* ROM 211ACC, VRAM 80145D1C: complete native animation command stream. */
struct Cave_Animation80145D1C D_80145D1C_211ACC = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 74, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 15, { 1.5707963705062866f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 11, { 1.5707963705062866f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80145D1C_211ACC },
};
