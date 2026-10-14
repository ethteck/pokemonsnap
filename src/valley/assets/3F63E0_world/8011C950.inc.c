/* ROM 412D90, VRAM 8011C950: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011C950 D_8011C950_412D90 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.5f, 0.5f, 0.5f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
