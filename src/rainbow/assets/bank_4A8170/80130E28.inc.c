/* ROM 4E31F8, VRAM 80130E28: complete native animation command stream. */
struct bank_4A8170_Animation80130E28 D_80130E28_4E31F8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -27.307117462158203f, 70.44439697265625f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 200 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
