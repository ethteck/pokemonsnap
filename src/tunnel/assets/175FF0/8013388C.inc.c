/* ROM 1799EC, VRAM 8013388C: complete native animation command stream. */
struct tunnel_175FF0_Animation8013388C D_8013388C_1799EC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 100 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8013388C_1799EC },
};
