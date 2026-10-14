/* ROM 2EB0DC, VRAM 8017B00C: complete native animation command stream. */
struct river_29A1A0_Animation8017B00C D_8017B00C_2EB0DC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 75 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017B00C_2EB0DC },
};
