/* ROM 213774, VRAM 801479C4: complete native animation command stream. */
struct Cave_Animation801479C4 D_801479C4_213774 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -35.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 80, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 5, { 2.0f, 2.0f, 2.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 10, { 2.0f, 2.0f, 2.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 25, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 30, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
