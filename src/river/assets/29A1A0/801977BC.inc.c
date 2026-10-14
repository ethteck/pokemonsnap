/* ROM 30788C, VRAM 801977BC: complete native animation command stream. */
struct river_29A1A0_Animation801977BC D_801977BC_30788C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.17453300952911377f, 0.0f, 0.0f, -400.0f, -100.0f, 100.0f, 1.0f, 0.9999998807907104f, 0.9999998807907104f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801977BC_30788C },
};
