/* ROM 4E0578, VRAM 8012E1A8: complete native animation command stream. */
struct bank_4A8170_Animation8012E1A8 D_8012E1A8_4E0578 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 85.8696517944336f, 84.79067993164062f, -3.7495415210723877f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012E1A8_4E0578 },
};
