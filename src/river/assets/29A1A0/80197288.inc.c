/* ROM 307358, VRAM 80197288: complete native animation command stream. */
struct river_29A1A0_Animation80197288 D_80197288_307358 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.7853981852531433f, -0.6108652353286743f, -0.47996553778648376f, 200.0f, -49.99990463256836f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80197288_307358 },
};
