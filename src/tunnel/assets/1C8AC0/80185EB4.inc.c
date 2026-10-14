/* ROM 1CC014, VRAM 80185EB4: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80185EB4 D_80185EB4_1CC014 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 15, { 0.6981316804885864f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 4 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 11 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 15, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80185EB4_1CC014 },
};
