/* ROM 112D84, VRAM 801868F4: complete native animation command stream. */
struct native_110970_chansey_Animation801868F4 D_801868F4_112D84 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.3490658700466156f, -284.9999694824219f, 119.99998474121094f, 0.0f, 0.9999999403953552f, 0.9999999403953552f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801868F4_112D84 },
};
