/* ROM 278F30, VRAM 801AD180: complete native animation command stream. */
struct Cave_Animation801AD180 D_801AD180_278F30 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -2.9802322387695312e-06f, 7.152557373046875e-05f, -2.384185791015625e-05f, 0.9999998807907104f, 1.0f, 0.9999998807907104f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 65 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
