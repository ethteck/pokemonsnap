/* ROM F5218, VRAM 80168D88: complete native animation command stream. */
struct native_EDF80_eevee_Animation80168D88 D_80168D88_F5218 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 25 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 9 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 14 },
    { (ANIM_CMD_16 << 25) | ((0x100) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 17 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80168D88_F5218 },
};
