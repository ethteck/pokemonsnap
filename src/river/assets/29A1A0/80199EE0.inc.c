/* ROM 309FB0, VRAM 80199EE0: complete native animation command stream. */
struct river_29A1A0_Animation80199EE0 D_80199EE0_309FB0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.2046445608139038f, -1.1725949048995972f, -1.0466316938400269f, 300.0f, 299.99993896484375f, 150.00003051757812f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 35 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
