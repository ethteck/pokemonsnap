/* ROM 2EF4BC, VRAM 8017F3EC: complete native animation command stream. */
struct river_29A1A0_Animation8017F3EC D_8017F3EC_2EF4BC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSZ | SCALEX | SCALEZ) << 15) | 0, { -0.03399990499019623f, 0.0f, 0.0f, 0.0f, -9.253483772277832f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY | SCALEY) << 15) | 0, { 383.560791015625f, 3.850914478302002f } },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY | SCALEY) << 15) | 50, { 604.9869995117188f, 5.300166130065918f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 20 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 10 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY | SCALEY) << 15) | 50, { 383.560791015625f, 3.850914478302002f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 20 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017F3EC_2EF4BC },
};
