/* ROM 0x9E22C; native animation_stream. */
struct PokemonCommonAnimationBulbasaur80120E0C D_80120E0C_9E22C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -2.384185791015625e-05f, 0.0f, 0.0002816319465637207f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 120 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80120E0C_9E22C },
};
