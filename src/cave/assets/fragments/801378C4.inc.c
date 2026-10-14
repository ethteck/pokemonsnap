/* ROM 203674, VRAM 801378C4: complete native animation command stream. */
struct Cave_Animation801378C4 D_801378C4_203674 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((MAT_PARAM_8) << 15) | 100, { 3.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
