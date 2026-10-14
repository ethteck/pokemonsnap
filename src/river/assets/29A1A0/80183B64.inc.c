/* ROM 2F3C34, VRAM 80183B64: complete native animation command stream. */
struct river_29A1A0_Animation80183B64 D_80183B64_2F3C34 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.9999982118606567f, 0.9999969005584717f, 0.9999961853027344f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80183B64_2F3C34 },
};
