/* ROM 1F9F40, VRAM 8012E190: complete native animation command stream. */
struct Cave_Animation8012E190 D_8012E190_1F9F40 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8012E178_1F9F28 },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTY) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | SCALEX) << 15) | 0, { 0.2591058015823364f, 0.675000011920929f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((SCALEX) << 15) | 55, { 2.0f, 0.0022499999031424522f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 16, { 0.2617993950843811f, 0.0007923329249024391f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX) << 15) | 54, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 39 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((SCALEX) << 15) | 5, { 0.8100000023841858f, -0.0264444462954998f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX) << 15) | 40, { 0.8100000023841858f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 10 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 30, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
