/* ROM 115C6C, VRAM 801897DC: complete native animation command stream. */
struct native_110970_chansey_Animation801897DC D_801897DC_115C6C = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTZ | POSY) << 15) | 0, { 0.0f, 0.0f, 295.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | POSX | POSZ) << 15) | 0, { 0.0f, 0.0f, 35.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 22, { 295.0f, -0.7692309021949768f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 15, { -0.0872664600610733f, 0.0872664600610733f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 15, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 15, { 0.0f, -0.005817763973027468f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 4, { 275.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 4, { 295.0f, 0.7692309021949768f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 22, { 295.0f, -0.7692309021949768f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 15, { -0.0872664600610733f, -0.0872664600610733f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTZ) << 15) | 15, { 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 4, { 275.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 4, { 295.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801897DC_115C6C },
};
