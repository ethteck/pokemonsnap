/* ROM 112D1C, VRAM 8018688C: complete native animation command stream. */
struct native_110970_chansey_Animation8018688C D_8018688C_112D1C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.39269909262657166f, -0.5235987901687622f, 270.00006103515625f, 110.00003814697266f, 45.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018688C_112D1C },
};
