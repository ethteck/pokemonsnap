/* ROM 1F9C04, VRAM 8012DE54: complete native animation command stream. */
struct Cave_Animation8012DE54 D_8012DE54_1F9C04 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 0, { -0.20000000298023224f, -0.10000000149011612f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6 | MAT_PARAM_8) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.2000000476837158f, 1.0f, 0.0f, 0.5f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 100, { 0.0f, 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
