/* ROM 1223F0, VRAM 80195F60: complete native animation command stream. */
struct native_116A30_meowth_Animation80195F60 D_80195F60_1223F0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -1.4560264105512033e-09f, 0.024492206051945686f, 0.0f, 84.05374145507812f, 4.084193706512451f, 5.53736686706543f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80195F60_1223F0 },
};
