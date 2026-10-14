/* ROM 40FD3C, VRAM 801198FC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation801198FC D_801198FC_40FD3C = {
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 0, { 18.84955596923828f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 100, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801198FC_40FD3C },
};
