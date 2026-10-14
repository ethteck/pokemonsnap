/* ROM 40F1EC, VRAM 80118DAC: complete native animation command stream. */
struct ValleyWorld3F63E0_Animation80118DAC D_80118DAC_40F1EC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80118DAC_40F1EC },
};
