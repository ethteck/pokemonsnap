/* ROM 4147F0, VRAM 8011E3B0: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011E3B0 D_8011E3B0_4147F0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.483529806137085f, 0.0f, -2.2351741790771484e-08f, 0.5379654169082642f, -31.202007293701172f, 5.9604644775390625e-06f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 450 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
