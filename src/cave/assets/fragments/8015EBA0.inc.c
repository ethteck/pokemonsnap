/* ROM 22A950, VRAM 8015EBA0: complete native animation command stream. */
struct Cave_Animation8015EBA0 D_8015EBA0_22A950 = {
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSX | POSZ) << 15) | 0, { 0.0f, 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 0, { 250.0f, -15.124566078186035f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.005585004109889269f, 0.9999992847442627f, 0.9999992847442627f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSX) << 15) | 15, { 0.2457388937473297f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSZ) << 15) | 20, { 37.94906997680664f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSY) << 15) | 10, { 225.06735229492188f, 14.058273315429688f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((POSY) << 15) | 20, { 250.0f, -14.26949691772461f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSX) << 15) | 15, { 0.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 5 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSZ) << 15) | 10, { 0.0f } },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8015EBA0_22A950 },
};
