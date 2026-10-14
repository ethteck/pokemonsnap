/* ROM 4DF4B0, VRAM 8012D0E0: complete native animation command stream. */
struct bank_4A8170_Animation8012D0E0 D_8012D0E0_4DF4B0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -0.0899999737739563f, 0.0f, 0.0f, 0.0f, -9.5f, 11.869999885559082f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012D0E0_4DF4B0 },
};
