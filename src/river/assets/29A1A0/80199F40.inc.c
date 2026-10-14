/* ROM 30A010, VRAM 80199F40: complete native animation command stream. */
struct river_29A1A0_Animation80199F40 D_80199F40_30A010 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -1.826256275177002f, 4.33229923248291f, 1.5071847438812256f, -300.0f, 299.99993896484375f, 150.00003051757812f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 35 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
