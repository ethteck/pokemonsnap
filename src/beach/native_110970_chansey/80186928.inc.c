/* ROM 112DB8, VRAM 80186928: complete native animation command stream. */
struct native_110970_chansey_Animation80186928 D_80186928_112DB8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.39269909262657166f, 0.5235987901687622f, -269.9999694824219f, 110.00003814697266f, 45.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186928_112DB8 },
};
