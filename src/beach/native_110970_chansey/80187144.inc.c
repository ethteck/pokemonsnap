/* ROM 1135D4, VRAM 80187144: complete native animation command stream. */
struct native_110970_chansey_Animation80187144 D_80187144_1135D4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.30543261766433716f, 0.0f, 0.0f, 0.0f, -150.0f, -430.0000305175781f, 0.9999999403953552f, 1.0f, 0.10000000149011612f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187144_1135D4 },
};
