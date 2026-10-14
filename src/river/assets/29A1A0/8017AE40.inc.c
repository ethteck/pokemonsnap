/* ROM 2EAF10, VRAM 8017AE40: complete native animation command stream. */
struct river_29A1A0_Animation8017AE40 D_8017AE40_2EAF10 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017AE40_2EAF10 },
};
