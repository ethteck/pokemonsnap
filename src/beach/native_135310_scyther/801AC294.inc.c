/* ROM 138724, VRAM 801AC294: complete native animation command stream. */
struct native_135310_scyther_Animation801AC294 D_801AC294_138724 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 30, { 525.9712524414062f, -1.0787293910980225f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 2 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 28 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 28, { -62.56630325317383f, -3.1710047721862793f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 29, { 345.2240905761719f, 1.251326084136963f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 8 },
    { (ANIM_CMD_16 << 25) | ((0x202) << 15) | 21 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 21, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSY) << 15) | 2, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801AC294_138724 },
};
