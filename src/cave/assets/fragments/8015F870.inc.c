/* ROM 22B620, VRAM 8015F870: complete native animation command stream. */
struct Cave_Animation8015F870 D_8015F870_22B620 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
