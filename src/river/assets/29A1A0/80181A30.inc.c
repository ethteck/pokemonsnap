/* ROM 2F1B00, VRAM 80181A30: complete native animation command stream. */
struct river_29A1A0_Animation80181A30 D_80181A30_2F1B00 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 1.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80181A30_2F1B00 },
};
