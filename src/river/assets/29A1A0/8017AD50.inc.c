/* ROM 2EAE20, VRAM 8017AD50: complete native animation command stream. */
struct river_29A1A0_Animation8017AD50 D_8017AD50_2EAE20 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017AD50_2EAE20 },
};
