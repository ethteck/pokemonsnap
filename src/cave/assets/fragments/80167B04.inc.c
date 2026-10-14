/* ROM 2338B4, VRAM 80167B04: complete native animation command stream. */
struct Cave_Animation80167B04 D_80167B04_2338B4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 41 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
