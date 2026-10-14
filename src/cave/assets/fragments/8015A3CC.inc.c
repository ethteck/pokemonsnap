/* ROM 22617C, VRAM 8015A3CC: complete native animation command stream. */
struct Cave_Animation8015A3CC D_8015A3CC_22617C = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 3 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 33 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8015A3CC_22617C },
};
