/* ROM 4DF454, VRAM 8012D084: complete native animation command stream. */
struct bank_4A8170_Animation8012D084 D_8012D084_4DF454 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY | ROTZ) << 15) | 0, { 0.0f, 0.011332002468407154f, 0.0f, -0.0007484642555937171f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 5.778175354003906f, -76.84915924072266f, 62.97479248046875f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY | ROTZ) << 15) | 40, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 20, { -0.6981316804885864f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 20, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012D084_4DF454 },
};
