/* ROM 1824A0, VRAM 8013C340: complete native animation command stream. */
struct tunnel_182390_Animation8013C340 D_8013C340_1824A0 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8013C328_182488 },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 1.570796012878418f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 150, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
