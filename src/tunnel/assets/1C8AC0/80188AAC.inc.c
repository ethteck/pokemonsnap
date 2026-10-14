/* ROM 1CEC0C, VRAM 80188AAC: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80188AAC D_80188AAC_1CEC0C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_16 << 25) | ((0x2) << 15) | 0 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 7 },
    { (ANIM_CMD_16 << 25) | ((0x2) << 15) | 9 },
    { (ANIM_CMD_16 << 25) | ((0x2) << 15) | 9 },
    { (ANIM_CMD_16 << 25) | ((0x2) << 15) | 12 },
    { (ANIM_CMD_16 << 25) | ((0x2) << 15) | 8 },
    { (ANIM_CMD_16 << 25) | ((0x2) << 15) | 10 },
    { (ANIM_CMD_16 << 25) | ((0x2) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80188AAC_1CEC0C },
};
