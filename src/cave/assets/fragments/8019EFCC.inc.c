/* ROM 26AD7C, VRAM 8019EFCC: complete native animation command stream. */
struct Cave_Animation8019EFCC D_8019EFCC_26AD7C = {
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 34 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 56 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019EFCC_26AD7C },
};
