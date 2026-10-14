/* ROM 22A460, VRAM 8015E6B0: complete native animation command stream. */
struct Cave_Animation8015E6B0 D_8015E6B0_22A460 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -300.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSZ) << 15) | 19, { -150.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 15, { 0.8999999761581421f, 1.100000023841858f, 0.9200000166893005f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 15, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSZ) << 15) | 11, { -300.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8015E6B0_22A460 },
};
