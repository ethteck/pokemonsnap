/* ROM 4CA930, VRAM 80118560: complete native animation command stream. */
struct bank_4A8170_Animation80118560 D_80118560_4CA930 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -4.656612873077393e-10f, 0.0f, 0.0f, -12.000012397766113f, 70.1534652709961f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 150 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
