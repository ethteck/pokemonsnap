/* ROM 1135A0, VRAM 80187110: complete native animation command stream. */
struct native_110970_chansey_Animation80187110 D_80187110_1135A0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.6108652353286743f, 0.0f, -50.0f, 150.0f, 50.0f, 0.9999999403953552f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187110_1135A0 },
};
