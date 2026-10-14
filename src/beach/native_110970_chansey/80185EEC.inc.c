/* ROM 11237C, VRAM 80185EEC: complete native animation command stream. */
struct native_110970_chansey_Animation80185EEC D_80185EEC_11237C = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | POSY) << 15) | 0, { 0.0f, 295.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 35.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 4, { 320.0f, 2.0833334922790527f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 4, { 0.0872664600610733f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 8, { 320.0f, -2.0833330154418945f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 4, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 4, { 0.0872664600610733f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | POSY) << 15) | 4, { 0.0f, 295.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80185EEC_11237C },
};
