/* ROM 0x9F320; native animation_stream. */
struct PokemonCommonAnimationBulbasaur80121F00 D_80121F00_9F320 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -105.76404571533203f, 13.533317565917969f, 148.10096740722656f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80121F00_9F320 },
};
