/* ROM 4170D0, VRAM 80120C90: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80120C90 D_80120C90_4170D0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.483529806137085f, 0.0f, -2.2351741790771484e-08f, 0.5379557609558105f, -31.201982498168945f, -0.00019073486328125f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
