/* ROM 2BBD68, VRAM 8014BC98: complete native animation command stream. */
struct river_29A1A0_Animation8014BC98 D_8014BC98_2BBD68 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6 | MAT_PARAM_8) << 15) | 0, { 0.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f, 0.5f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFFFFFFFF } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_7) << 15) | 50, { -1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T) << 15) | 150, { -1.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 30, { 0xFFFFFFFF } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0xFFFFFFE6 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0xFFFFFF99 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_7) << 15) | 50, { -1.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0xFFFFFF00 } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 90, { 0xFFFFFF00 } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_7) << 15) | 50, { -1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
