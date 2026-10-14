/* ROM 6AE30, VRAM 800ED680: complete native animation command stream. */
struct bank_64420_Animation800ED680 D_800ED680_6AE30 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((SCALEX | SCALEZ) << 15) | 0, { 0.7000002861022949f, 0.0985141173005104f, 0.7000002861022949f, 0.09819581359624863f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEY) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX | SCALEZ) << 15) | 60, { 3.0f, 3.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
