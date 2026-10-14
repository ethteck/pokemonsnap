/* ROM C8724, VRAM 8013C294: complete native animation command stream. */
struct native_a74f0_Animation8013C294 D_8013C294_C8724 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6 | MAT_PARAM_8) << 15) | 0, { 0.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f, 0.5f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T) << 15) | 150, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 50, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 50, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 50, { -1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
