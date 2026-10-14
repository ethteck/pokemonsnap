/* ROM 1CCF44, VRAM 80186DE4: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80186DE4 D_80186DE4_1CCF44 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 0, { -0.3811776041984558f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 22, { 0.3137255012989044f } },
    { (ANIM_CMD_12 << 25) | ((ROTX) << 15) | 7 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 15 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 8, { -0.3811776041984558f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 22, { 0.3137255012989044f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
