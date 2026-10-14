/* ROM FBA88, VRAM 8016F5F8: complete native animation command stream. */
struct native_F7AD0_kangaskhan_Animation8016F5F8 D_8016F5F8_FBA88 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 22 },
    { (ANIM_CMD_16 << 25) | ((0x100) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 17 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016F5F8_FBA88 },
};
