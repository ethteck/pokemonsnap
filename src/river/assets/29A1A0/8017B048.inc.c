/* ROM 2EB118, VRAM 8017B048: complete native animation command stream. */
struct river_29A1A0_Animation8017B048 D_8017B048_2EB118 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B048_2EB118 },
};
