/* ROM 26F86C, VRAM 801A3ABC: complete native animation command stream. */
struct Cave_Animation801A3ABC D_801A3ABC_26F86C = {
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A3ABC_26F86C },
};
