/* ROM F14D8, VRAM 80165048: complete native animation command stream. */
struct native_EDF80_eevee_Animation80165048 D_80165048_F14D8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80165048_F14D8 },
};
