/* ROM 2EA840, VRAM 8017A770: complete native animation command stream. */
struct river_29A1A0_Animation8017A770 D_8017A770_2EA840 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A770_2EA840 },
};
