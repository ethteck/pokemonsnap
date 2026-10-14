/* ROM 4E1EF8, VRAM 8012FB28: complete native animation command stream. */
struct bank_4A8170_Animation8012FB28 D_8012FB28_4E1EF8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.822746753692627f, -78.9834976196289f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 70 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012FB28_4E1EF8 },
};
