/* ROM 4C9C20, VRAM 80117850: complete native animation command stream. */
struct bank_4A8170_Animation80117850 D_80117850_4C9C20 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEZ) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY) << 15) | 0, { 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY) << 15) | 25, { 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY) << 15) | 15, { 8.0f, 8.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
