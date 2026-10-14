/* ROM 413BE4, VRAM 8011D7A4: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011D7A4 D_8011D7A4_413BE4 = {
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
