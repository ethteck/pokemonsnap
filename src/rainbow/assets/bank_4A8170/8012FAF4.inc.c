/* ROM 4E1EC4, VRAM 8012FAF4: complete native animation command stream. */
struct bank_4A8170_Animation8012FAF4 D_8012FAF4_4E1EC4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -0.822746753692627f, -34.55514907836914f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 70 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012FAF4_4E1EC4 },
};
