/* ROM 23A1CC, VRAM 8016E41C: complete native animation command stream. */
struct Cave_Animation8016E41C D_8016E41C_23A1CC = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0x999A54E6 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.2448980063199997f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 45, { 0x999A5400 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 45, { 3.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 1, { 0x999A54FF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 1, { 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 4, { 0x999A54E6 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 4, { 0.2448980063199997f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016E41C_23A1CC },
};
