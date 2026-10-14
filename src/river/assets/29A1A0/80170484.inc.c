/* ROM 2E0554, VRAM 80170484: complete native animation command stream. */
struct river_29A1A0_Animation80170484 D_80170484_2E0554 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX | OFFSET_S | OFFSET_T | SCALE_S | SCALE_T) << 15) | 0, { 1.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 51, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80170484_2E0554 },
};
