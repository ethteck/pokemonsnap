/* ROM 40FDD8, VRAM 80119998: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80119998 D_80119998_40FDD8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | SCALE_S | SCALE_T | MAT_PARAM_5 | MAT_PARAM_6 | MAT_PARAM_8) << 15) | 0, { 0.0f, 0.0f, 1.0f, 2.0f, 1.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((MAT_PARAM_7) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((OFFSET_T) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((OFFSET_T) << 15) | 100, { -1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((MAT_PARAM_7) << 15) | 100, { -1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80119998_40FDD8 },
};
