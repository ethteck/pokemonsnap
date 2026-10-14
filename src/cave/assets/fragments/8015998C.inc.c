/* ROM 22573C, VRAM 8015998C: complete native animation command stream. */
struct Cave_Animation8015998C D_8015998C_22573C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 15 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 21 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
