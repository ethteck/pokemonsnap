/* ROM 25DFCC, VRAM 8019221C: complete native animation command stream. */
struct Cave_Animation8019221C D_8019221C_25DFCC = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 13 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 47 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019221C_25DFCC },
};
