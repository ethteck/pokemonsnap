/* ROM 2EB12C, VRAM 8017B05C: complete native animation command stream. */
struct river_29A1A0_Animation8017B05C D_8017B05C_2EB12C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B05C_2EB12C },
};
