/* ROM C8B44, VRAM 8013C6B4: complete native animation command stream. */
struct native_a74f0_Animation8013C6B4 D_8013C6B4_C8B44 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8013C69C_C8B2C },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 60, { 0.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((PATH_PARAM) << 15) | 0, { 0.01650043949484825f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((PATH_PARAM) << 15) | 90, { 1.0f, 0.003740500658750534f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 0 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
