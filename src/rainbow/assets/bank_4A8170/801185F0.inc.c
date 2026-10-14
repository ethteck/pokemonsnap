/* ROM 4CA9C0, VRAM 801185F0: complete native animation command stream. */
struct bank_4A8170_Animation801185F0 D_801185F0_4CA9C0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -4.656612873077393e-10f, 0.0f, 30.000028610229492f, -25.19999122619629f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
