/* ROM 4E2B2C, VRAM 8013075C: complete native animation command stream. */
struct bank_4A8170_Animation8013075C D_8013075C_4E2B2C = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -85.8699951171875f, 84.78999328613281f, -3.7599995136260986f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 200 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
