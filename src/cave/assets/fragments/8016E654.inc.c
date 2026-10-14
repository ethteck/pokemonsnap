/* ROM 23A404, VRAM 8016E654: complete native animation command stream. */
struct Cave_Animation8016E654 D_8016E654_23A404 = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0x999A54FF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 29, { 3.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 11, { 0x999A54FF } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 25, { 0x999A5400 } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 18 },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 11, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 20, { 0x999A54FF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 30, { 3.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
