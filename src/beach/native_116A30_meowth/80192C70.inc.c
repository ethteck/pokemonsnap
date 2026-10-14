/* ROM 11F100, VRAM 80192C70: complete native animation command stream. */
struct native_116A30_meowth_Animation80192C70 D_80192C70_11F100 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 13 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 55 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80192C70_11F100 },
};
