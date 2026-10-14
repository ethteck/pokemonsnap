/* ROM 2EB0F0, VRAM 8017B020: complete native animation command stream. */
struct river_29A1A0_Animation8017B020 D_8017B020_2EB0F0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B020_2EB0F0 },
};
