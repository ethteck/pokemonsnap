/* ROM 0xA207C; native animation_stream. */
struct PokemonCommonAnimationBulbasaur80124C5C D_80124C5C_A207C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -2.384185791015625e-05f, 0.0f, 0.0002816319465637207f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80124C5C_A207C },
};
