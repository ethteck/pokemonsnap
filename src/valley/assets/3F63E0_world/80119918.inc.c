/* ROM 40FD58, VRAM 80119918: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80119918 D_80119918_40FD58 = {
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTY) << 15) | 0, { 12.566370964050293f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTY) << 15) | 100, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80119918_40FD58 },
};
