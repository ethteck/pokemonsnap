/* ROM 4CA2F8, VRAM 80117F28: complete native animation command stream. */
struct bank_4A8170_Animation80117F28 D_80117F28_4CA2F8 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 140 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
