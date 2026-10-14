/* ROM 2E31C0, VRAM 801730F0: complete native animation command stream. */
struct river_29A1A0_Animation801730F0 D_801730F0_2E31C0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 12, { -0.2617993950843811f, -0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 18, { 0.0f, 0.018055129796266556f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 18, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 11, { -0.2617993950843811f, 0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 19, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801730F0_2E31C0 },
};
