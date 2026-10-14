/* ROM 2BC340, VRAM 8014C270: complete native animation command stream. */
struct river_29A1A0_Animation8014C270 D_8014C270_2BC340 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 9.5367431640625e-05f, -12.000006675720215f, 70.15342712402344f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 450 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
