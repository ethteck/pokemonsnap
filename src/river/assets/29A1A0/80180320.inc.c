/* ROM 2F03F0, VRAM 80180320: complete native animation command stream. */
struct river_29A1A0_Animation80180320 D_80180320_2F03F0 = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 9 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 30 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 21 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80180320_2F03F0 },
};
