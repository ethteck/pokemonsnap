/* ROM 30870C, VRAM 8019863C: complete native animation command stream. */
struct river_29A1A0_Animation8019863C D_8019863C_30870C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.17453300952911377f, 0.0f, 0.0f, -400.0f, -100.0f, 100.0f, 1.0f, 0.9999998807907104f, 0.9999998807907104f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
