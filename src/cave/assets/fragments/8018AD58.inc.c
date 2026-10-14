/* ROM 256B08, VRAM 8018AD58: complete native animation command stream. */
struct Cave_Animation8018AD58 D_8018AD58_256B08 = {
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x2) << 15) | 120 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8018AD58_256B08 },
};
