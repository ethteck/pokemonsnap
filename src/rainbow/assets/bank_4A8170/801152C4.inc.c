/* ROM 4C7694, VRAM 801152C4: complete native animation command stream. */
struct bank_4A8170_Animation801152C4 D_801152C4_4C7694 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 50, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801152C4_4C7694 },
};
