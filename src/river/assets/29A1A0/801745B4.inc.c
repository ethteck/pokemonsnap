/* ROM 2E4684, VRAM 801745B4: complete native animation command stream. */
struct river_29A1A0_Animation801745B4 D_801745B4_2E4684 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | POSY) << 15) | 0, { 0.0f, 265.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 25, { 265.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 10, { 0.1745329201221466f, -0.018703166395425797f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 25, { -0.6544984579086304f, -0.0034906587097793818f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 15 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 10, { 319.41461181640625f, 0.9801228642463684f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | POSY) << 15) | 25, { 0.0f, 265.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
