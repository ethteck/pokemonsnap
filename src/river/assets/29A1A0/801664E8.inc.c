/* ROM 2D65B8, VRAM 801664E8: complete native animation command stream. */
struct river_29A1A0_Animation801664E8 D_801664E8_2D65B8 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 0, { -312.468994140625f, -15.807863235473633f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 3, { -344.77520751953125f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 12, { 604.3311767578125f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 2 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 2 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 8 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 15, { -699.2689819335938f, -118.17084503173828f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 6 },
    { (ANIM_CMD_16 << 25) | ((0x203) << 15) | 9 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
