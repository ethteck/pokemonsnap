/* ROM 4C7564, VRAM 80115194: complete native animation command stream. */
struct bank_4A8170_Animation80115194 D_80115194_4C7564 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80115194_4C7564 },
};
