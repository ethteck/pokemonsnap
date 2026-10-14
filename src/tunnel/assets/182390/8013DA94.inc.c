/* ROM 183BF4, VRAM 8013DA94: complete native animation command stream. */
struct tunnel_182390_Animation8013DA94 D_8013DA94_183BF4 = {
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | POSY) << 15) | 0, { 0.0f, 72.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((POSY) << 15) | 90, { 72.00006103515625f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 60, { 0.0f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((ROTX) << 15) | 0, { 0.0019610440358519554f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 29, { 0.1745329201221466f, 3.9770791772753e-05f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 61, { 0.0f, -0.00021994348207954317f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((POSY) << 15) | 0, { -0.5292811989784241f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 30, { 62.696983337402344f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 30, { 72.00006103515625f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
