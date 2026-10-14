/* ROM 2EAD1C, VRAM 8017AC4C: complete native animation command stream. */
struct river_29A1A0_Animation8017AC4C D_8017AC4C_2EAD1C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017AC4C_2EAD1C },
};
