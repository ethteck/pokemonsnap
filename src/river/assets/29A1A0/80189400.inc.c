/* ROM 2F94D0, VRAM 80189400: complete native animation command stream. */
struct river_29A1A0_Animation80189400 D_80189400_2F94D0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 3.1415927410125732f, 0.0f, 0.0f, 0.0f, 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x102) << 15) | 10 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
