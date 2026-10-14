/* ROM 183D70, VRAM 8013DC10: complete native animation command stream. */
struct tunnel_182390_Animation8013DC10 D_8013DC10_183D70 = {
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 0, { -0.05960908532142639f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 15.000185012817383f, -20.649999618530273f, 29.489999771118164f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 90, { -0.05960831418633461f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 30, { 3.1415927410125732f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 3 },
    { (ANIM_CMD_16 << 25) | ((0xA) << 15) | 27 },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((ROTX) << 15) | 0, { 0.021262532100081444f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX) << 15) | 30, { 3.1415927410125732f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
