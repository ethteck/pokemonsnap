/* ROM 1CA084, VRAM 80183F24: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80183F24 D_80183F24_1CA084 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { -124.03125762939453f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | POSX | POSZ) << 15) | 0, { 0.9499996900558472f, 0.0f, -574.5076904296875f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 41, { 600.0f, 15.22463321685791f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 16 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 25 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 12, { 550.0f, -19.478750228881836f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 2 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 10 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 12, { 132.50999450683594f, -30.63778305053711f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 10, { -124.03125762939453f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 9 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80183F24_1CA084 },
};
