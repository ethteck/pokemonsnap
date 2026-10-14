/* ROM 121F50, VRAM 80195AC0: complete native animation command stream. */
struct native_116A30_meowth_Animation80195AC0 D_80195AC0_121F50 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80195AC0_121F50 },
};
