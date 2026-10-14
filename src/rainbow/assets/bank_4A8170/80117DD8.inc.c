/* ROM 4CA1A8, VRAM 80117DD8: complete native animation command stream. */
struct bank_4A8170_Animation80117DD8 D_80117DD8_4CA1A8 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 140 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
