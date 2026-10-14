/* ROM F2258, VRAM 80165DC8: complete native animation command stream. */
struct native_EDF80_eevee_Animation80165DC8 D_80165DC8_F2258 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 38 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80165DC8_F2258 },
};
