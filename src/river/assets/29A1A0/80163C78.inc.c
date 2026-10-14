/* ROM 2D3D48, VRAM 80163C78: complete native animation command stream. */
struct river_29A1A0_Animation80163C78 D_80163C78_2D3D48 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 0, { -1006.7594604492188f, 159.1677703857422f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 15, { 692.0711059570312f, 24.9877872467041f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 2 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 13 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 10, { 692.0711059570312f, -26.849149703979492f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 15, { -1006.7594604492188f, -173.87094116210938f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_16 << 25) | ((0x203) << 15) | 8 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
