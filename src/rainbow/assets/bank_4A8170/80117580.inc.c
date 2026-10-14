/* ROM 4C9950, VRAM 80117580: complete native animation command stream. */
struct bank_4A8170_Animation80117580 D_80117580_4C9950 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEZ) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((SCALEX | SCALEY) << 15) | 0, { 1.0f, 0.060746967792510986f, 1.0f, 0.06087242066860199f } },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX | SCALEY) << 15) | 25, { 8.0f, 0.6464712023735046f, 8.0f, 0.6392553448677063f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
