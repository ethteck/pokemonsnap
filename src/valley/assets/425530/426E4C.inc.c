/* ROM 426E4C, VRAM 80130A0C: struct ValleyAnimation80130A0C. */
struct ValleyAnimation80130A0C D_80130A0C_426E4C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ) << 15) | 0, { 0.00038050164585001767f, 130.56283569335938f, -0.00010132789611816406f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 15 },
    { (ANIM_CMD_16 << 25) | ((0xC) << 15) | 9 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80130A0C_426E4C },
};
