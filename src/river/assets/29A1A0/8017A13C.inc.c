/* ROM 2EA20C, VRAM 8017A13C: complete native animation command stream. */
struct river_29A1A0_Animation8017A13C D_8017A13C_2EA20C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A13C_2EA20C },
};
