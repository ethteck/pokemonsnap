/* ROM 4C8DA4, VRAM 801169D4: complete native animation command stream. */
struct bank_4A8170_Animation801169D4 D_801169D4_4C8DA4 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 0, { -0.05000000074505806f, -0.10000000149011612f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6) << 15) | 0, { 0.0f, 0.0f, 1.0f, 1.100000023841858f, 1.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T | MAT_PARAM_7) << 15) | 100, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801169D4_4C8DA4 },
};
