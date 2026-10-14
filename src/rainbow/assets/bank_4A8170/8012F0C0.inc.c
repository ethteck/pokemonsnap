/* ROM 4E1490, VRAM 8012F0C0: complete native animation command stream. */
struct bank_4A8170_Animation8012F0C0 D_8012F0C0_4E1490 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.09999999403953552f, 0.0f, 0.0f, 0.0f, 225.8209686279297f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 70 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012F0C0_4E1490 },
};
