/* ROM 4E2B60, VRAM 80130790: complete native animation command stream. */
struct bank_4A8170_Animation80130790 D_80130790_4E2B60 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 85.8696517944336f, 84.79067993164062f, -3.7495415210723877f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 200 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
