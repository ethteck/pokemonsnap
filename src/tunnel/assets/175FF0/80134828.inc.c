/* ROM 17A988, VRAM 80134828: complete native animation command stream. */
struct tunnel_175FF0_Animation80134828 D_80134828_17A988 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((PRIM_COLOR) << 15) | 0, { 0x660066FF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80134828_17A988 },
};
