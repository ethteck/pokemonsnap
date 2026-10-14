/* ROM 4CCA44, VRAM 8011A674: complete native animation command stream. */
struct bank_4A8170_Animation8011A674 D_8011A674_4CCA44 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.4920000731945038f, 0.0f, 0.0f, 0.020939111709594727f, -13.91439437866211f, -0.059854984283447266f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
