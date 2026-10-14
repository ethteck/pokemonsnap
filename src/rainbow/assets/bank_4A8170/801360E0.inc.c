/* ROM 4E84B0, VRAM 801360E0: complete native animation command stream. */
struct bank_4A8170_Animation801360E0 D_801360E0_4E84B0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -27.307117462158203f, 70.44439697265625f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 140 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
