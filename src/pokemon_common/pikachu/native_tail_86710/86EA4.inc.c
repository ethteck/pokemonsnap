/* ROM 0x86EA4; native animation_stream. */
struct PokemonCommonAnimationPikachu80109A84 D_80109A84_86EA4 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ) << 15) | 0, { -1.9170866012573242f, -2.150857448577881f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 0, { 1.1502501964569092f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 6, { 1.4655086994171143f } },
    { (ANIM_CMD_12 << 25) | ((ROTX) << 15) | 5 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 6, { 1.1502501964569092f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 6, { 1.4655086994171143f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80109A84_86EA4 },
};
