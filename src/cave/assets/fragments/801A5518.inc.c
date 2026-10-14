/* ROM 2712C8, VRAM 801A5518: complete native animation command stream. */
struct Cave_Animation801A5518 D_801A5518_2712C8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((OFFSET_T | SCALE_S | SCALE_T | MAT_PARAM_7) << 15) | 0, { 0.0f, 4.0f, 1.0f, 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFFFFFF00 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_S | MAT_PARAM_6) << 15) | 0, { 0.0f, -3.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_S | MAT_PARAM_6) << 15) | 29, { -3.0f, 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 4, { 0xFFFFFF00 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 3, { 0xFFFFFFFF } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 12, { 0xFFFFFFFF } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 10, { 0xFFFFFF00 } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 70, { 0xFFFFFF00 } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_S | MAT_PARAM_6) << 15) | 70, { -3.0f, 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
