/* ROM 0xA200C; native animation_stream. */
struct PokemonCommonAnimationBulbasaur80124BEC D_80124BEC_A200C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -105.76404571533203f, 13.533317565917969f, 148.10096740722656f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80124BEC_A200C },
};
