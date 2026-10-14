/* ROM 30A040, VRAM 80199F70: complete native animation command stream. */
struct river_29A1A0_Animation80199F70 D_80199F70_30A040 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.26339346170425415f, 0.48803645372390747f, -0.23826107382774353f, 200.0f, -49.99990463256836f, 7.152557373046875e-05f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 35 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
