/* ROM 2EA2FC, VRAM 8017A22C: complete native animation command stream. */
struct river_29A1A0_Animation8017A22C D_8017A22C_2EA2FC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((IMG_INDEX) << 15) | 0, { 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A22C_2EA2FC },
};
