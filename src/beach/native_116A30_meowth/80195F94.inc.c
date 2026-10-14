/* ROM 122424, VRAM 80195F94: complete native animation command stream. */
struct native_116A30_meowth_Animation80195F94 D_80195F94_122424 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -4.089094396420023e-09f, 0.04475582018494606f, 0.0f, 63.901771545410156f, 4.261016845703125f, 1.062766432762146f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80195F94_122424 },
};
