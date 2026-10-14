/* ROM 412CEC, VRAM 8011C8AC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011C8AC D_8011C8AC_412CEC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 1.5099580252808664e-07f, 0.0f, 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
