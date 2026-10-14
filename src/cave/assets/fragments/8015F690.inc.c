/* ROM 22B440, VRAM 8015F690: complete native animation command stream. */
struct Cave_Animation8015F690 D_8015F690_22B440 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
