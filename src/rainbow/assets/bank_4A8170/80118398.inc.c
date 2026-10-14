/* ROM 4CA768, VRAM 80118398: complete native animation command stream. */
struct bank_4A8170_Animation80118398 D_80118398_4CA768 = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFFFFFF4C } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 50, { 4.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0xFFFFFF80 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 30, { 0xFFFFFF19 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0xFFFFFF4C } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80118398_4CA768 },
};
