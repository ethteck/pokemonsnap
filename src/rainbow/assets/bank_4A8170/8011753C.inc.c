/* ROM 4C990C, VRAM 8011753C: complete native animation command stream. */
struct bank_4A8170_Animation8011753C D_8011753C_4C990C = {
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((IMG_INDEX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 85, { 0x0066FFFF } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 25 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
