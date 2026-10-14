/* ROM 2460AC, VRAM 8017A2FC: complete native animation command stream. */
struct Cave_Animation8017A2FC D_8017A2FC_2460AC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 0, { 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 60 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017A2FC_2460AC },
};
