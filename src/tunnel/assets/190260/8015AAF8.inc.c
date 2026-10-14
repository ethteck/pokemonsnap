/* ROM 1A0C58, VRAM 8015AAF8: complete native animation command stream. */
struct tunnel_190260_Animation8015AAF8 D_8015AAF8_1A0C58 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 486.79998779296875f, -235.1999969482422f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8015AAF8_1A0C58 },
};
