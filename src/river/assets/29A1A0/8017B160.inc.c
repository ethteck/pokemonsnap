/* ROM 2EB230, VRAM 8017B160: complete native animation command stream. */
struct river_29A1A0_Animation8017B160 D_8017B160_2EB230 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B160_2EB230 },
};
