/* ROM 24D6E0, VRAM 80181930: complete native animation command stream. */
struct Cave_Animation80181930 D_80181930_24D6E0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.36000001430511475f, 0.0f, -49.5860595703125f, -102.4197006225586f, 92.55963897705078f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
