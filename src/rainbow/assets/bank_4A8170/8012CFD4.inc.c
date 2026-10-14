/* ROM 4DF3A4, VRAM 8012CFD4: complete native animation command stream. */
struct bank_4A8170_Animation8012CFD4 D_8012CFD4_4DF3A4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -10.289615631103516f, 22.16225814819336f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012CFD4_4DF3A4 },
};
