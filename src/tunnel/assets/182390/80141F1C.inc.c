/* ROM 18807C, VRAM 80141F1C: complete native animation command stream. */
struct tunnel_182390_Animation80141F1C D_80141F1C_18807C = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_80141F04_188064 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | PATH_PARAM) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((ROTX | PATH_PARAM) << 15) | 30, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((ROTX) << 15) | 0, { 2.2177318896865472e-05f } },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((PATH_PARAM) << 15) | 0, { 0.00018914333486463875f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((PATH_PARAM) << 15) | 80, { 0.3199999928474426f, 0.002311036689206958f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 60, { 1.5707963705062866f, 0.00012252792657818645f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 90, { 3.1415927410125732f, -1.05999661172973e-05f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 20 },
    { (ANIM_CMD_SET_TARGET_RATE << 25) | ((PATH_PARAM) << 15) | 0, { 0.0023110334295779467f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((PATH_PARAM) << 15) | 80, { 1.0f, 0.014758240431547165f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 70 },
    { (ANIM_CMD_SET_VALUE << 25) | ((ROTX) << 15) | 270, { 3.1415927410125732f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 260, { 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
