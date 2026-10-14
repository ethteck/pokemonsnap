/* ROM 1CEE2C, VRAM 80188CCC: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80188CCC D_80188CCC_1CEE2C = {
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 60, { 20.0f, 20.0f, 20.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
