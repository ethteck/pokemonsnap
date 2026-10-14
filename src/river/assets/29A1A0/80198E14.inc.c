/* ROM 308EE4, VRAM 80198E14: complete native animation command stream. */
struct river_29A1A0_Animation80198E14 D_80198E14_308EE4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.7853981852531433f, -0.6108652353286743f, -0.47996553778648376f, 200.0f, -49.99990463256836f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 23 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80198E14_308EE4 },
};
