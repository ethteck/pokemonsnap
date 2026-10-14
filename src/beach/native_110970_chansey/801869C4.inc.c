/* ROM 112E54, VRAM 801869C4: complete native animation command stream. */
struct native_110970_chansey_Animation801869C4 D_801869C4_112E54 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 0, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 10, { 0.0f, -0.0581776425242424f } },
    { (ANIM_CMD_12 << 25) | ((ROTY) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.1745329201221466f, 0.0f, 0.0f, -150.0f, -325.0f, 0.9999999403953552f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 10, { -0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTY) << 15) | 10, { 0.0f, 0.0581776425242424f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 10, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 10, { 0.0f, -0.0581776425242424f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801869C4_112E54 },
};
