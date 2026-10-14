/* ROM 2EB104, VRAM 8017B034: complete native animation command stream. */
struct river_29A1A0_Animation8017B034 D_8017B034_2EB104 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B034_2EB104 },
};
