/* ROM 4C748C, VRAM 801150BC: complete native animation command stream. */
struct bank_4A8170_Animation801150BC D_801150BC_4C748C = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801150BC_4C748C },
};
