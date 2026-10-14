/* ROM 22BF54, VRAM 801601A4: complete native animation command stream. */
struct Cave_Animation801601A4 D_801601A4_22BF54 = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 29 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801601A4_22BF54 },
};
