/* ROM 183FA0, VRAM 8013DE40: complete native animation command stream. */
struct tunnel_182390_Animation8013DE40 D_8013DE40_183FA0 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 0, { -0.05960908532142639f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, -30.048768997192383f, -58.51052474975586f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 120, { -0.059609100222587585f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((ROTX) << 15) | 0, { -0.0008298743050545454f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 30, { 6.2831854820251465f, 0.3711197078227997f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
