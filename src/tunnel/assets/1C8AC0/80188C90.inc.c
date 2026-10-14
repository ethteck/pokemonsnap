/* ROM 1CEDF0, VRAM 80188C90: complete native animation command stream. */
struct tunnel_1C8AC0_Animation80188C90 D_80188C90_1CEDF0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80188C90_1CEDF0 },
};
