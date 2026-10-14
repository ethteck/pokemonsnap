/* ROM 2D2EA4, VRAM 80162DD4: complete native animation command stream. */
struct river_29A1A0_Animation80162DD4 D_80162DD4_2D2EA4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 5.9604641222676946e-08f, 3.160413325531408e-05f, 269.7709045410156f, -12.745001792907715f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80162DD4_2D2EA4 },
};
