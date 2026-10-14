/* ROM 2EA220, VRAM 8017A150: complete native animation command stream. */
struct river_29A1A0_Animation8017A150 D_8017A150_2EA220 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A150_2EA220 },
};
