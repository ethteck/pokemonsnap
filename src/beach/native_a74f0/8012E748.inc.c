/* ROM BABD8, VRAM 8012E748: complete native animation command stream. */
struct native_a74f0_Animation8012E748 D_8012E748_BABD8 = {
    { (ANIM_CMD_13 << 25) | ((PATH_PARAM) << 15) | 0, &D_8012E730_BABC0 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTY) << 15) | 0, { 0.0f, 0.6981316804885864f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((PATH_PARAM | SCALEX) << 15) | 0, { 0.0f, 1.9900000095367432f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTX) << 15) | 54, { 0.0f, -1.1495131730043795e-05f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY) << 15) | 74, { 2.044560194015503f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((PATH_PARAM) << 15) | 100, { 1.0f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((SCALEX) << 15) | 1, { 3.7200000286102295f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((SCALEX) << 15) | 99, { 3.7200000286102295f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 53 },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 20, { -0.2617993950843811f, -2.9103168344590813e-05f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE << 25) | ((ROTY) << 15) | 26, { 2.7052602767944336f, 0.04654211178421974f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 26, { -0.2617993950843811f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
