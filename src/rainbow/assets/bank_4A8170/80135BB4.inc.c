/* ROM 4E7F84, VRAM 80135BB4: complete native animation command stream. */
struct bank_4A8170_Animation80135BB4 D_80135BB4_4E7F84 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 10.014891624450684f, 17.526023864746094f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 40, { -0.7330383062362671f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 20, { 0.0f, 0.007330382242798805f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 80, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
