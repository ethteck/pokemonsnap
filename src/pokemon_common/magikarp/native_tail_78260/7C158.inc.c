/* ROM 0x7C158; native animation_stream. */
struct PokemonCommonAnimationMagikarp800FED38 D_800FED38_7C158 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -6.364164306660314e-08f, 8.918536309465708e-08f, -0.000286102294921875f, -0.0001430511474609375f, 1.6001462936401367f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_800FED38_7C158 },
};
