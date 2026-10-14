/* ROM 23A5FC, VRAM 8016E84C: complete native animation command stream. */
struct Cave_Animation8016E84C D_8016E84C_23A5FC = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0x999A54FF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 21, { 0x999A54FF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 20, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 20, { 3.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0x999A5400 } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 29, { 0x999A54FF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 9 },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 20, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
