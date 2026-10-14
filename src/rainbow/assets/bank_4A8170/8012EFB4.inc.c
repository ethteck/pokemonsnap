/* ROM 4E1384, VRAM 8012EFB4: complete native animation command stream. */
struct bank_4A8170_Animation8012EFB4 D_8012EFB4_4E1384 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.822746753692627f, -78.9834976196289f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { -1.4901161193847656e-08f, 0.0f, -1.4901161193847656e-08f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 80 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8012EFB4_4E1384 },
};
