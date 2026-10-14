/* ROM 4E31C8, VRAM 80130DF8: complete native animation command stream. */
struct bank_4A8170_Animation80130DF8 D_80130DF8_4E31C8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -10.289615631103516f, 22.16225814819336f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 200 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
