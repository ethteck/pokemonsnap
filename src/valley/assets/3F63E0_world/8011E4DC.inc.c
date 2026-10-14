/* ROM 41491C, VRAM 8011E4DC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation8011E4DC D_8011E4DC_41491C = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.05728084594011307f, 0.43702393770217896f, -0.1942342221736908f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.13374042510986328f, 34.20059585571289f, -1.6087144613265991f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 22, { 0.05728084594011307f, 0.43702393770217896f, -0.1942342221736908f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 135, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY | ROTZ) << 15) | 293, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 54, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 59, { -0.3296779990196228f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 180, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
