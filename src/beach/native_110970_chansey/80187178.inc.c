/* ROM 113608, VRAM 80187178: complete native animation command stream. */
struct native_110970_chansey_Animation80187178 D_80187178_113608 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -1.2217304706573486f, 0.6981316804885864f, -0.5235987901687622f, 125.0f, -175.0f, 100.0f, 0.9999999403953552f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187178_113608 },
};
