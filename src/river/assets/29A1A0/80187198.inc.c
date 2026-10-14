/* ROM 2F7268, VRAM 80187198: complete native animation command stream. */
struct river_29A1A0_Animation80187198 D_80187198_2F7268 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 0, { -0.4363323152065277f, -0.1070355623960495f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 300.0f, -84.00018310546875f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 15, { -0.0872664600610733f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY | ROTZ) << 15) | 10, { 1.490116545710407e-07f, -6.519259798665189e-09f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY | ROTZ) << 15) | 10, { 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 5, { -0.4363323152065277f, -0.1070355623960495f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187198_2F7268 },
};
