/* ROM 2F3C00, VRAM 80183B30: complete native animation command stream. */
struct river_29A1A0_Animation80183B30 D_80183B30_2F3C00 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.000000238418579f, 0.9999962449073792f, 0.9999971985816956f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80183B30_2F3C00 },
};
