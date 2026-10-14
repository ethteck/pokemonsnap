/* ROM 40B704, VRAM 801152C4: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation801152C4 D_801152C4_40B704 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T | MAT_PARAM_6) << 15) | 0, { 0.0f, -0.03449999913573265f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_7 | MAT_PARAM_8 | MAT_PARAM_9) << 15) | 0, { 0.0f, 0.0f, 1.034500002861023f, 1.034500002861023f, 1.0f, 0.0f, 0.5f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T | MAT_PARAM_6) << 15) | 100, { -0.03449999913573265f, 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
