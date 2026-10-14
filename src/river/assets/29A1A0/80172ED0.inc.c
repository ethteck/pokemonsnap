/* ROM 2E2FA0, VRAM 80172ED0: complete native animation command stream. */
struct river_29A1A0_Animation80172ED0 D_80172ED0_2E2FA0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 12, { -0.2617993950843811f, -0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTZ) << 15) | 18, { 0.0f, 0.018055129796266556f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 18, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 11, { -0.2617993950843811f, 0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | ROTZ) << 15) | 19, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80172ED0_2E2FA0 },
};
