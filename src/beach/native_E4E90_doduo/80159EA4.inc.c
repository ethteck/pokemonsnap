/* ROM E6334, VRAM 80159EA4: complete native animation command stream. */
struct native_E4E90_doduo_Animation80159EA4 D_80159EA4_E6334 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 2 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 14 },
    { (ANIM_CMD_16 << 25) | ((0x302) << 15) | 4 },
    { (ANIM_CMD_16 << 25) | ((0x103) << 15) | 18 },
    { (ANIM_CMD_16 << 25) | ((0x202) << 15) | 18 },
    { (ANIM_CMD_16 << 25) | ((0x302) << 15) | 20 },
    { (ANIM_CMD_16 << 25) | ((0x202) << 15) | 4 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80159EA4_E6334 },
};
