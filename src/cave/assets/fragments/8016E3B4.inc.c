/* ROM 23A164, VRAM 8016E3B4: complete native animation command stream. */
struct Cave_Animation8016E3B4 D_8016E3B4_23A164 = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0x999A54FF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 50, { 0x999A5400 } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016E3B4_23A164 },
};
