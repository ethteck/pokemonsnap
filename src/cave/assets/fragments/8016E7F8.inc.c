/* ROM 23A5A8, VRAM 8016E7F8: complete native animation command stream. */
struct Cave_Animation8016E7F8 D_8016E7F8_23A5A8 = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0x999A54FF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 21, { 0x999A54FF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 10, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 20, { 3.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 11 },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 10, { 0x999A5400 } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 9 },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 20, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 19, { 0x999A54FF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
