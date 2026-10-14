/* ROM 412C54, VRAM 8011C814: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011C814 D_8011C814_412C54 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 9.999999747378752e-06f, 9.999999747378752e-06f, 9.999999747378752e-06f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 150, { 17.802358627319336f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
