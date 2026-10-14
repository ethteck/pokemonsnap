/* ROM 11304C, VRAM 80186BBC: complete native animation command stream. */
struct native_110970_chansey_Animation80186BBC D_80186BBC_11304C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 0, { 0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 10, { 0.0f, -0.01745329238474369f } },
    { (ANIM_CMD_12 << 25) | ((ROTY) << 15) | 8 },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, -150.0f, 349.9999694824219f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 2 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 10, { -0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTY) << 15) | 10, { 0.0f, 0.01745329238474369f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 10, { 0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 10, { 0.0f, -0.01745329052209854f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 8 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186BBC_11304C },
};
