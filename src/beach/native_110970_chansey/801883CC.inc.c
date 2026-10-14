/* ROM 11485C, VRAM 801883CC: complete native animation command stream. */
struct native_110970_chansey_Animation801883CC D_801883CC_11485C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSZ) << 15) | 0, { 0.0f, 0.0f, 35.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 0, { 0.0872664600610733f, 0.005454154219478369f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 8, { 0.0872664600610733f, -0.014544411562383175f } },
    { (ANIM_CMD_12 << 25) | ((ROTX) << 15) | 4 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 4, { -0.0872664600610733f, -0.014544409699738026f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 8, { -0.0872664600610733f, 0.007272204849869013f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 4, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 8, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
