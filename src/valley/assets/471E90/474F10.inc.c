/* ROM 474F10, VRAM 8017EAD0: struct ValleyAnimation8017EAD0. */
struct ValleyAnimation8017EAD0 D_8017EAD0_474F10 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 0, { -0.2617993950843811f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 15, { 0.2617993950843811f } },
    { (ANIM_CMD_12 << 25) | ((ROTY) << 15) | 10 },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -165.0f, 40.0f, 0.9999998807907104f, 0.9999997019767761f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 0, { -0.4363323152065277f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 8, { -0.2617993950843811f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 15, { -0.2617993950843811f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 3 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 7, { -0.4363323152065277f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 8, { -0.2617993950843811f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 15, { 0.2617993950843811f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 3 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 7, { -0.4363323152065277f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017EAD0_474F10 },
};
