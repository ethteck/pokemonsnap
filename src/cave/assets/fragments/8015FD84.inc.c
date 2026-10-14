/* ROM 22BB34, VRAM 8015FD84: complete native animation command stream. */
struct Cave_Animation8015FD84 D_8015FD84_22BB34 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
