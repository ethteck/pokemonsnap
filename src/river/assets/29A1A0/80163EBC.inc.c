/* ROM 2D3F8C, VRAM 80163EBC: complete native animation command stream. */
struct river_29A1A0_Animation80163EBC D_80163EBC_2D3F8C = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTZ) << 15) | 0, { 0.0f, 0.15999998152256012f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 119.13066101074219f, 9.214317321777344f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 25, { 0.0f, -0.009299998171627522f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 20, { -0.23184365034103394f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTZ) << 15) | 20, { 0.15999998152256012f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 15, { -0.37199991941452026f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
