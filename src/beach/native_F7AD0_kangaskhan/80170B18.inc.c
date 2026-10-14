/* ROM FCFA8, VRAM 80170B18: complete native animation command stream. */
struct native_F7AD0_kangaskhan_Animation80170B18 D_80170B18_FCFA8 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSZ) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSZ) << 15) | 39, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 27 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 12 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSZ) << 15) | 13, { 0.0f, 11.66412353515625f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSZ) << 15) | 6, { 221.61834716796875f, 83.84174346923828f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 1 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSZ) << 15) | 3, { 754.5755615234375f, 14.40424919128418f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSZ) << 15) | 34, { 754.5755615234375f, -15.92302417755127f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSZ) << 15) | 6, { 117.65462493896484f, -62.881324768066406f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSZ) << 15) | 6, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80170B18_FCFA8 },
};
