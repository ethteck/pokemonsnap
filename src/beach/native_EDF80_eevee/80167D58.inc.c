/* ROM F41E8, VRAM 80167D58: complete native animation command stream. */
struct native_EDF80_eevee_Animation80167D58 D_80167D58_F41E8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 8 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80167D58_F41E8 },
};
