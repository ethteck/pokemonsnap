/* ROM 4CA068, VRAM 80117C98: complete native animation command stream. */
struct bank_4A8170_Animation80117C98 D_80117C98_4CA068 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 110 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
