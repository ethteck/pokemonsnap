/* ROM 2F3BD8, VRAM 80183B08: complete native animation command stream. */
struct river_29A1A0_Animation80183B08 D_80183B08_2F3BD8 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.9999995231628418f, 1.0000017881393433f, 1.000001311302185f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80183B08_2F3BD8 },
};
