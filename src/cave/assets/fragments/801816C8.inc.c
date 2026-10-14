/* ROM 24D478, VRAM 801816C8: complete native animation command stream. */
struct Cave_Animation801816C8 D_801816C8_24D478 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 164.67515563964844f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 6 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 44 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
