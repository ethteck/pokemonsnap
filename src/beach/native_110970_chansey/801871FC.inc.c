/* ROM 11368C, VRAM 801871FC: complete native animation command stream. */
struct native_110970_chansey_Animation801871FC D_801871FC_11368C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -1.2217304706573486f, -0.6981316804885864f, 0.5235987901687622f, -125.0f, -175.0f, 100.0f, 0.9999999403953552f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801871FC_11368C },
};
