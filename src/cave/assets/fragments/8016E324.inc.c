/* ROM 23A0D4, VRAM 8016E324: complete native animation command stream. */
struct Cave_Animation8016E324 D_8016E324_23A0D4 = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0x999A5460 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 1.440000057220459f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 27, { 0x999A5400 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 26, { 3.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 1, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 23, { 1.440000057220459f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 1, { 0x999A54FF } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 22, { 0x999A5460 } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016E324_23A0D4 },
};
