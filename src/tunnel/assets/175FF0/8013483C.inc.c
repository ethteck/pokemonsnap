/* ROM 17A99C, VRAM 8013483C: complete native animation command stream. */
struct tunnel_175FF0_Animation8013483C D_8013483C_17A99C = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((PRIM_COLOR) << 15) | 0, { 0x660066FF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8013483C_17A99C },
};
