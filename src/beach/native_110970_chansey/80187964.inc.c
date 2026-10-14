/* ROM 113DF4, VRAM 80187964: complete native animation command stream. */
struct native_110970_chansey_Animation80187964 D_80187964_113DF4 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 0, { 0.0f, -0.027925269678235054f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 15, { -0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTZ) << 15) | 15, { 0.0f, 0.027925269678235054f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 15, { 0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTZ) << 15) | 15, { 0.0f, -0.027925269678235054f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187964_113DF4 },
};
