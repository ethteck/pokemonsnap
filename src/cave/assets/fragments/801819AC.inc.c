/* ROM 24D75C, VRAM 801819AC: complete native animation command stream. */
struct Cave_Animation801819AC D_801819AC_24D75C = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEZ) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY) << 15) | 0, { 0.0f, 3.492000102996826f, 0.0f, -74.60786437988281f, -101.25994873046875f, -120.41360473632812f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEZ) << 15) | 30, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((SCALEZ) << 15) | 16, { 1.6888256072998047f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEZ) << 15) | 14, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
