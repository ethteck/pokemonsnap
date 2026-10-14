/* ROM 4CA990, VRAM 801185C0: complete native animation command stream. */
struct bank_4A8170_Animation801185C0 D_801185C0_4CA990 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -4.656612873077393e-10f, 0.0f, 0.0f, -5.9604644775390625e-06f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
