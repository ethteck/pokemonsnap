/* ROM 2FB7C0, VRAM 8018B6F0: complete native animation command stream. */
struct river_29A1A0_Animation8018B6F0 D_8018B6F0_2FB7C0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 42 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
