/* ROM 2EFBC0, VRAM 8017FAF0: complete native animation command stream. */
struct river_29A1A0_Animation8017FAF0 D_8017FAF0_2EFBC0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEY) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEZ) << 15) | 0, { -0.03399990499019623f, 0.0f, 0.0f, 0.0f, 383.560791015625f, -9.253483772277832f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEY) << 15) | 40, { 3.850914478302002f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEY) << 15) | 20, { 3.850914478302002f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
