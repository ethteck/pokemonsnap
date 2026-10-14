/* ROM 113538, VRAM 801870A8: complete native animation command stream. */
struct native_110970_chansey_Animation801870A8 D_801870A8_113538 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.39269909262657166f, 0.5235987901687622f, 55.00004196166992f, 74.28579711914062f, 45.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801870A8_113538 },
};
