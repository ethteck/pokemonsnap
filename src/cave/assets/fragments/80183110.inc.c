/* ROM 24EEC0, VRAM 80183110: complete native animation command stream. */
struct Cave_Animation80183110 D_80183110_24EEC0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.36000001430511475f, 0.0f, -49.5860595703125f, -102.4197006225586f, 92.55963897705078f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
