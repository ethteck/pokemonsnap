/* ROM 2EAD30, VRAM 8017AC60: complete native animation command stream. */
struct river_29A1A0_Animation8017AC60 D_8017AC60_2EAD30 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017AC60_2EAD30 },
};
