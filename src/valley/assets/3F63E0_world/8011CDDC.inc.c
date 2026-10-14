/* ROM 41321C, VRAM 8011CDDC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011CDDC D_8011CDDC_41321C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { -0.4920000731945038f, 0.0f, 0.0f, 0.020939111709594727f, -13.91439437866211f, -0.059854984283447266f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
