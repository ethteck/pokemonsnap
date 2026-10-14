/* ROM 113504, VRAM 80187074: complete native animation command stream. */
struct native_110970_chansey_Animation80187074 D_80187074_113504 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.3490658700466156f, 40.00003433227539f, 84.28573608398438f, 0.0f, 0.9999999403953552f, 0.9999999403953552f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187074_113504 },
};
