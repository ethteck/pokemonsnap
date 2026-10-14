/* ROM B0098, VRAM 80123C08: complete native animation command stream. */
struct native_a74f0_Animation80123C08 D_80123C08_B0098 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80123BF0_B0080 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 0, { 0.0872664600610733f, 0.008726646192371845f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 100, { 1.2217304706573486f, 0.01745329238474369f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 1, { 2.140000104904175f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX) << 15) | 99, { 2.140000104904175f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
