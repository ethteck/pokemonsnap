/* ROM 2464F8, VRAM 8017A748: complete native animation command stream. */
struct Cave_Animation8017A748 D_8017A748_2464F8 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { 1200.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 60, { 600.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
