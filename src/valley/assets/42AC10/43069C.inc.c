/* ROM 43069C, VRAM 8013A25C: struct ValleyAnimation8013A25C. */
struct ValleyAnimation8013A25C D_8013A25C_43069C = {
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 0, { -39.053916931152344f, -1020.013427734375f, -1023.6876220703125f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 7 },
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 7 },
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 10 },
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 5 },
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 10 },
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 9 },
    { (ANIM_CMD_16 << 25) | ((0x5) << 15) | 8 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8013A25C_43069C },
};
