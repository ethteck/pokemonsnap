/* ROM 309FE0, VRAM 80199F10: complete native animation command stream. */
struct river_29A1A0_Animation80199F10 D_80199F10_309FE0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.7853981852531433f, -0.6108652353286743f, -0.47996553778648376f, 200.0f, -49.99990463256836f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 35 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
