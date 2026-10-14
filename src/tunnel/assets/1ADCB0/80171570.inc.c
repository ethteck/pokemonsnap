/* ROM 1B76D0, VRAM 80171570: complete native animation command stream. */
struct tunnel_1ADCB0_Animation80171570 D_80171570_1B76D0 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 135, { 0.0f, 0.8111060261726379f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 86 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 49 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 3, { 111.93263244628906f, 14.201498031616211f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 11, { 198.82118225097656f, -4.866637706756592f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 12, { 0.0f, -9.46767807006836f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSY) << 15) | 9, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
