/* ROM 2EAE0C, VRAM 8017AD3C: complete native animation command stream. */
struct river_29A1A0_Animation8017AD3C D_8017AD3C_2EAE0C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017AD3C_2EAE0C },
};
