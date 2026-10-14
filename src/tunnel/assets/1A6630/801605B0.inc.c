/* ROM 1A6710, VRAM 801605B0: complete native animation command stream. */
struct tunnel_1A6630_Animation801605B0 D_801605B0_1A6710 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0xFFFFFFFF } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 142, { 0xFFFFFFFF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801605B0_1A6710 },
};
