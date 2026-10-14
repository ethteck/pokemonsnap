/* ROM 3078C0, VRAM 801977F0: complete native animation command stream. */
struct river_29A1A0_Animation801977F0 D_801977F0_3078C0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.026179980486631393f, 0.0f, 0.0f, 35.0001106262207f, -249.9999237060547f, 99.9999771118164f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801977F0_3078C0 },
};
