/* ROM 2464D0, VRAM 8017A720: complete native animation command stream. */
struct Cave_Animation8017A720 D_8017A720_2464D0 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 60, { 20.0f, 20.0f, 20.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
