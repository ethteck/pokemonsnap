/* ROM 22600C, VRAM 8015A25C: complete native animation command stream. */
struct Cave_Animation8015A25C D_8015A25C_22600C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 50.858497619628906f, -148.366455078125f, 154.11793518066406f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 36 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
