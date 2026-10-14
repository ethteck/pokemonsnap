/* ROM 10B1F4, VRAM 8017ED64: complete native animation command stream. */
struct native_105E80_snorlax_Animation8017ED64 D_8017ED64_10B1F4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 50.0f, 200.0f, 300.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 25 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017ED64_10B1F4 },
};
