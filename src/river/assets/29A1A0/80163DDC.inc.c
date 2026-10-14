/* ROM 2D3EAC, VRAM 80163DDC: complete native animation command stream. */
struct river_29A1A0_Animation80163DDC D_80163DDC_2D3EAC = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY | POSZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY | POSZ) << 15) | 32, { 241.9907989501953f, 6.049769878387451f, -258.4367370605469f, -6.46091890335083f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY | POSZ) << 15) | 8, { 241.9907989501953f, -258.4367370605469f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
