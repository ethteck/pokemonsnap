/* ROM 2F93BC, VRAM 801892EC: complete native animation command stream. */
struct river_29A1A0_Animation801892EC D_801892EC_2F93BC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 1.0471975803375244f, 0.1745329201221466f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801892EC_2F93BC },
};
