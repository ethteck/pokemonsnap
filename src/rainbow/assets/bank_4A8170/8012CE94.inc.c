/* ROM 4DF264, VRAM 8012CE94: complete native animation command stream. */
struct bank_4A8170_Animation8012CE94 D_8012CE94_4DF264 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -20.440000534057617f, -7.220000267028809f, 14.370000839233398f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012CE94_4DF264 },
};
