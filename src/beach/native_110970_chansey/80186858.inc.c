/* ROM 112CE8, VRAM 80186858: complete native animation command stream. */
struct native_110970_chansey_Animation80186858 D_80186858_112CE8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -0.3490658402442932f, 285.0001220703125f, 119.99998474121094f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186858_112CE8 },
};
