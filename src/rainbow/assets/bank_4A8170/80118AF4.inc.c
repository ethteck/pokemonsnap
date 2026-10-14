/* ROM 4CAEC4, VRAM 80118AF4: complete native animation command stream. */
struct bank_4A8170_Animation80118AF4 D_80118AF4_4CAEC4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.483529806137085f, 0.0f, -2.2351741790771484e-08f, 0.5379654169082642f, -31.202007293701172f, 5.9604644775390625e-06f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
