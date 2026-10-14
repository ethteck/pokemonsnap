/* ROM 2F6A20, VRAM 80186950: complete native animation command stream. */
struct river_29A1A0_Animation80186950 D_80186950_2F6A20 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX | ROTZ) << 15) | 0, { -0.4363323152065277f, -0.07200668752193451f, 0.0f, -0.027164919301867485f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 300.0f, -84.00018310546875f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 10, { 1.490116545710407e-07f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 15, { -0.2601739168167114f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 4, { -0.08687377721071243f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 16, { 0.0f, -0.028724396601319313f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 6 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 10, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 5, { -0.4363323152065277f, -0.05186059698462486f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186950_2F6A20 },
};
