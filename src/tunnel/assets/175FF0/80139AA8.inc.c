/* ROM 17FC08, VRAM 80139AA8: complete native animation command stream. */
struct tunnel_175FF0_Animation80139AA8 D_80139AA8_17FC08 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T) << 15) | 0, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6 | MAT_PARAM_7 | MAT_PARAM_9) << 15) | 0, { 0.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T) << 15) | 100, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
