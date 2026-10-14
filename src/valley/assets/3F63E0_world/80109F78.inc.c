/* ROM 4003B8, VRAM 80109F78: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80109F78 D_80109F78_4003B8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6 | MAT_PARAM_9) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.25f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 0, { -0.08330000191926956f, -0.08330000191926956f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 100, { -0.16670000553131104f, -0.16670000553131104f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 25, { 0.5f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 25, { 0.25f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 25, { 0.5f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 25, { 0.25f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
