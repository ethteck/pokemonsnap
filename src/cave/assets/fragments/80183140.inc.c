/* ROM 24EEF0, VRAM 80183140: complete native animation command stream. */
struct Cave_Animation80183140 D_80183140_24EEF0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEZ) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY) << 15) | 0, { 0.0f, 2.9240009784698486f, 0.0f, 74.8671875f, -108.41973114013672f, -130.89389038085938f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEZ) << 15) | 30, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEZ) << 15) | 16, { 1.6867090463638306f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEZ) << 15) | 14, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
