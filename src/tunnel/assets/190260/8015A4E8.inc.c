/* ROM 1A0648, VRAM 8015A4E8: complete native animation command stream. */
struct tunnel_190260_Animation8015A4E8 D_8015A4E8_1A0648 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 486.79998779296875f, -235.1999969482422f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8015A4E8_1A0648 },
};
