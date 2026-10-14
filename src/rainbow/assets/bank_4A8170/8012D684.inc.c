/* ROM 4DFA54, VRAM 8012D684: complete native animation command stream. */
struct bank_4A8170_Animation8012D684 D_8012D684_4DFA54 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.822746753692627f, -34.55514907836914f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 5.960464477539063e-08f, -2.9802322387695312e-08f, 2.9802322387695312e-08f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012D684_4DFA54 },
};
