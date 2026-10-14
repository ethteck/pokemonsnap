/* ROM 0x86EE4; native animation_stream. */
struct PokemonCommonAnimationPikachu80109AC4 D_80109AC4_86EE4 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ) << 15) | 0, { -4.3475141525268555f, 2.172128438949585f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 0, { 1.5661460161209106f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 6, { 1.1354185342788696f } },
    { (ANIM_CMD_12 << 25) | ((ROTX) << 15) | 5 },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 6, { 1.5661460161209106f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 6, { 1.1354185342788696f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80109AC4_86EE4 },
};
