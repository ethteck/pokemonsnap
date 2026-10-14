/* ROM F2F58, VRAM 80166AC8: complete native animation command stream. */
struct native_EDF80_eevee_Animation80166AC8 D_80166AC8_F2F58 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 70 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80166AC8_F2F58 },
};
