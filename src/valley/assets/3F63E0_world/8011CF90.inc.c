/* ROM 4133D0, VRAM 8011CF90: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011CF90 D_8011CF90_4133D0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
