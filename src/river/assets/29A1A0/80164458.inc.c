/* ROM 2D4528, VRAM 80164458: complete native animation command stream. */
struct river_29A1A0_Animation80164458 D_80164458_2D4528 = {
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY | POSY) << 15) | 0, { 0.0f, 0.5526875853538513f, -1006.7589721679688f, 316.6666564941406f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTZ | POSX | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 15, { 1634.900146484375f, 40.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 40, { 25.132741928100586f, 0.5526875853538513f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 5 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 9 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 10, { 1634.900146484375f, -40.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 15, { -1006.7589721679688f, -316.6666564941406f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 12 },
    { (ANIM_CMD_16 << 25) | ((0x203) << 15) | 3 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
