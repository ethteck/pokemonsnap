/* ROM 2F0E10, VRAM 80180D40: complete native animation command stream. */
struct river_29A1A0_Animation80180D40 D_80180D40_2F0E10 = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 6 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 84 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80180D40_2F0E10 },
};
