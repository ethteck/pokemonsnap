/* ROM 2EB21C, VRAM 8017B14C: complete native animation command stream. */
struct river_29A1A0_Animation8017B14C D_8017B14C_2EB21C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 2.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B14C_2EB21C },
};
