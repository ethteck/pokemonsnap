/* ROM 17A250, VRAM 801340F0: complete native animation command stream. */
struct tunnel_175FF0_Animation801340F0 D_801340F0_17A250 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801340F0_17A250 },
};
