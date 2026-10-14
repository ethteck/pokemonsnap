/* ROM 4C9F18, VRAM 80117B48: complete native animation command stream. */
struct bank_4A8170_Animation80117B48 D_80117B48_4C9F18 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 110 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
