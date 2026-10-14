/* ROM 1856BC, VRAM 8013F55C: complete native animation command stream. */
struct tunnel_182390_Animation8013F55C D_8013F55C_1856BC = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, -30.000028610229492f, -25.199981689453125f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 30, { 0.0f, 3.1590458092978224e-05f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 40, { -0.10471975803375244f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 60, { 0.0f, 0.0002755782916210592f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 320, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
