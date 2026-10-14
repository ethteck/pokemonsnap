/* ROM 112E20, VRAM 80186990: complete native animation command stream. */
struct native_110970_chansey_Animation80186990 D_80186990_112E20 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.4363322854042053f, 0.3490658104419708f, 0.0f, -225.0f, 150.0f, 275.0f, 0.9999999403953552f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186990_112E20 },
};
