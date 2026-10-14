/* ROM 4E4A88, VRAM 801326B8: complete native animation command stream. */
struct bank_4A8170_Animation801326B8 D_801326B8_4E4A88 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -27.307117462158203f, 70.44439697265625f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 90 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
