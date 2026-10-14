/* ROM 10B438, VRAM 8017EFA8: complete native animation command stream. */
struct native_105E80_snorlax_Animation8017EFA8 D_8017EFA8_10B438 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { -2.9802322387695312e-08f, 1.4901161193847656e-08f, 8.940696716308594e-08f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 25 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8017EFA8_10B438 },
};
