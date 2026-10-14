/* ROM 25A96C, VRAM 8018EBBC: complete native animation command stream. */
struct Cave_Animation8018EBBC D_8018EBBC_25A96C = {
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 120 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018EBBC_25A96C },
};
