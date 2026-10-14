/* ROM 41440C, VRAM 8011DFCC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011DFCC D_8011DFCC_41440C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.003776614088565111f, 0.0f, 0.0f, -30.000001907348633f, 0.00019073486328125f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 450 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
