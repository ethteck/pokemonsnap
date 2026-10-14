/* ROM 1101DC, VRAM 80183D4C: complete native animation command stream. */
struct native_10E9A0_lapras_Animation80183D4C D_80183D4C_1101DC = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | POSY) << 15) | 0, { 0.0f, -1350.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 100, { 150.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 100, { -0.07599999010562897f, 0.0004801232716999948f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 80 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX | POSY) << 15) | 30, { 0.06241602823138237f, 0.002511791419237852f, 0.0f, -0.7692307233810425f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 35, { 0.0872664600610733f, 0.0014996788231655955f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 35, { 100.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 100, { -1350.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 30, { 0.1598951369524002f, -0.0008726644446142018f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 70, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
