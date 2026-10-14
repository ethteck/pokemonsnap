/* ROM 4C9D6C, VRAM 8011799C: complete native animation command stream. */
struct bank_4A8170_Animation8011799C D_8011799C_4C9D6C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8011799C_4C9D6C },
};
