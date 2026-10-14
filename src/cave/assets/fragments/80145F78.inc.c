/* ROM 211D28, VRAM 80145F78: complete native animation command stream. */
struct Cave_Animation80145F78 D_80145F78_211D28 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTZ) << 15) | 0, { 0.0872664600610733f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.003776614321395755f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTZ) << 15) | 56, { -0.0872664600610733f, -0.00029088821611367166f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTZ) << 15) | 94, { 0.04363323003053665f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
