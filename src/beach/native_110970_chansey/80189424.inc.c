/* ROM 1158B4, VRAM 80189424: complete native animation command stream. */
struct native_110970_chansey_Animation80189424 D_80189424_1158B4 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | POSY | POSZ) << 15) | 0, { 0.0f, -175.0f, 89.99996185302734f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 18, { -175.0f, 1.2500001192092896f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX | POSZ) << 15) | 18, { 0.0f, 89.99996185302734f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY | POSZ) << 15) | 2, { -150.0f, 2.0833334922790527f, 400.0f, 25.833337783813477f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 1, { -0.3490658402442932f, -0.05817766487598419f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 5, { -0.3490658402442932f, 0.07933314889669418f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
