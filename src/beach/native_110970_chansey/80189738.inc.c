/* ROM 115BC8, VRAM 80189738: complete native animation command stream. */
struct native_110970_chansey_Animation80189738 D_80189738_115BC8 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTZ | POSY) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | POSX | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 22, { 0.0f, -2.884615421295166f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 15, { -0.0872664600610733f, 0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 15, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 15, { 0.0f, -0.011635527946054935f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 4, { -75.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 4, { 0.0f, 2.884615421295166f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 22, { 0.0f, -2.884615421295166f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 15, { -0.0872664600610733f, -0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTZ) << 15) | 15, { 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 4, { -75.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 4, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80189738_115BC8 },
};
