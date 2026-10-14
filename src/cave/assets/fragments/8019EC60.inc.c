/* ROM 26AA10, VRAM 8019EC60: complete native animation command stream. */
struct Cave_Animation8019EC60 D_8019EC60_26AA10 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -1.997639742512547e-08f, 7.270813728865733e-09f, 0.0f, 450.0f, 275.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8019EC60_26AA10 },
};
