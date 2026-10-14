/* ROM 2B44D0, VRAM 80144400: complete native animation command stream. */
struct river_29A1A0_Animation80144400 D_80144400_2B44D0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 18, { 0.0f, 0.03235012665390968f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 1, { -47.89198303222656f, 0.0023797720205038786f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 49, { -47.89198303222656f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
