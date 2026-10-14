/* ROM 40F400, VRAM 80118FC0: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80118FC0 D_80118FC0_40F400 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 18, { 0.0f, 0.03235012665390968f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 1, { -47.89198303222656f, 0.0023797720205038786f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 49, { -47.89198303222656f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
