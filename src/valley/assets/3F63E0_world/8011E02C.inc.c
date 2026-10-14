/* ROM 41446C, VRAM 8011E02C: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011E02C D_8011E02C_41446C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 4.656612873077393e-10f, 0.0f, -3.187385082244873f, -20.648801803588867f, 29.48947525024414f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 450 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
