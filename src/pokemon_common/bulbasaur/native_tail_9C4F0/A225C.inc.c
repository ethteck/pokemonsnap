/* ROM 0xA225C; native animation_stream. */
struct PokemonCommonAnimationBulbasaur80124E3C D_80124E3C_A225C = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 1.30385160446167e-07f, 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 0, { -196.7126922607422f, 12.61802864074707f, 249.01695251464844f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 24, { -0.07118339836597443f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 32, { 0.3150537610054016f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 23, { -0.3679330050945282f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTZ) << 15) | 27, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 26, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 8 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 18, { 1.30385160446167e-07f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80124E3C_A225C },
};
