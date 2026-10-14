/* ROM 1147DC, VRAM 8018834C: complete native animation command stream. */
struct native_110970_chansey_Animation8018834C D_8018834C_1147DC = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSZ | SCALEX | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX | SCALEY) << 15) | 0, { 0.2617993950843811f, 0.01636246219277382f, 1.0f, 0.01875000260770321f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEY) << 15) | 8, { 1.0f } },
    { (ANIM_CMD_12 << 25) | ((SCALEY) << 15) | 4 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 8, { 0.2617993950843811f, -0.03272492438554764f } },
    { (ANIM_CMD_12 << 25) | ((ROTX) << 15) | 4 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEY) << 15) | 24, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 4, { -0.13089969754219055f, -0.03272492066025734f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 8, { -0.13089969754219055f, 0.010908306576311588f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 4, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 8, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
