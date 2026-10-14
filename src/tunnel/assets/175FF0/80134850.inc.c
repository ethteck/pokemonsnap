/* ROM 17A9B0, VRAM 80134850: complete native animation command stream. */
struct tunnel_175FF0_Animation80134850 D_80134850_17A9B0 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((PRIM_COLOR) << 15) | 0, { 0x660066FF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80134850_17A9B0 },
};
