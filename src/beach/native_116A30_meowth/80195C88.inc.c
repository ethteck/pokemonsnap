/* ROM 122118, VRAM 80195C88: complete native animation command stream. */
struct native_116A30_meowth_Animation80195C88 D_80195C88_122118 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.3599998950958252f, 6.4604570582105225e-09f, 0.0f, -1.1864542961120605f, -78.61557006835938f, 2.1437020301818848f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80195C88_122118 },
};
