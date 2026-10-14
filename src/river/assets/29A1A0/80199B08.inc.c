/* ROM 309BD8, VRAM 80199B08: complete native animation command stream. */
struct river_29A1A0_Animation80199B08 D_80199B08_309BD8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 35 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
