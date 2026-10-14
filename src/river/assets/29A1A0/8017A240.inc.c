/* ROM 2EA310, VRAM 8017A240: complete native animation command stream. */
struct river_29A1A0_Animation8017A240 D_8017A240_2EA310 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A240_2EA310 },
};
