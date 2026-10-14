/* ROM 4E8458, VRAM 80136088: complete native animation command stream. */
struct bank_4A8170_Animation80136088 D_80136088_4E8458 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f, -0.00515435915440321f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -10.289615631103516f, 22.16225814819336f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 40, { 0.0f, -0.00515435915440321f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 20, { 0.0f, -0.00515435915440321f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 80, { 0.0f, -0.00515435915440321f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
