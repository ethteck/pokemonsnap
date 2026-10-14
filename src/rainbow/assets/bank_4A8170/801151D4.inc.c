/* ROM 4C75A4, VRAM 801151D4: complete native animation command stream. */
struct bank_4A8170_Animation801151D4 D_801151D4_4C75A4 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.5f, 0.0f, 0.5f, 0.5f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801151D4_4C75A4 },
};
