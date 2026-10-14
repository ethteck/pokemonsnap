/* ROM 120E80, VRAM 801949F0: complete native animation command stream. */
struct native_116A30_meowth_Animation801949F0 D_801949F0_120E80 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 50 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801949F0_120E80 },
};
