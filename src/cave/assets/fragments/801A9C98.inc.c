/* ROM 275A48, VRAM 801A9C98: complete native animation command stream. */
struct Cave_Animation801A9C98 D_801A9C98_275A48 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -7.105427357601002e-13f, 2.384185791015625e-05f, 0.0f, 1.0000001192092896f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 32 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801A9C98_275A48 },
};
