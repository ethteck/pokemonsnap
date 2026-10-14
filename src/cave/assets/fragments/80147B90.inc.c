/* ROM 213940, VRAM 80147B90: complete native animation command stream. */
struct Cave_Animation80147B90 D_80147B90_213940 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 2.905726432800293e-05f, -25.0f, -0.0041961669921875f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 80, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 5, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 10, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 25, { 0.5f, 0.5f, 0.5f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 30, { 0.5f, 0.5f, 0.5f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
