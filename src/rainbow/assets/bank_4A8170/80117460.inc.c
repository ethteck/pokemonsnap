/* ROM 4C9830, VRAM 80117460: complete native animation command stream. */
struct bank_4A8170_Animation80117460 D_80117460_4C9830 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_12 << 25) | ((0) << 15) | 85 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 25 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
