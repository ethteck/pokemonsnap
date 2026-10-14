/* ROM 40FC7C, VRAM 8011983C: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011983C D_8011983C_40FC7C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6) << 15) | 0, { 0.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((MAT_PARAM_7) << 15) | 0, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T | MAT_PARAM_8) << 15) | 0, { -1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T) << 15) | 10, { -0.8999999761581421f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((MAT_PARAM_7) << 15) | 10, { -0.972000002861023f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 3, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 7, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
