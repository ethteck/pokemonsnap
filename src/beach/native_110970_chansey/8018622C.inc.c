/* ROM 1126BC, VRAM 8018622C: complete native animation command stream. */
struct native_110970_chansey_Animation8018622C D_8018622C_1126BC = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 0, { 0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.2617993950843811f, 0.0f, 0.0f, -175.0f, -325.0f, 0.9999999403953552f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 8, { -0.1745329201221466f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 8, { 0.1745329201221466f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018622C_1126BC },
};
