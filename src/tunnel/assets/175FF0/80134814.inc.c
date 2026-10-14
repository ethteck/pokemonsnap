/* ROM 17A974, VRAM 80134814: complete native animation command stream. */
struct tunnel_175FF0_Animation80134814 D_80134814_17A974 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((PRIM_COLOR) << 15) | 0, { 0x660066FF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80134814_17A974 },
};
