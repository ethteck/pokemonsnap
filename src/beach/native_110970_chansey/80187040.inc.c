/* ROM 1134D0, VRAM 80187040: complete native animation command stream. */
struct native_110970_chansey_Animation80187040 D_80187040_1134D0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, -0.39269909262657166f, 0.2617993950843811f, 55.00004196166992f, 89.28585052490234f, -55.0f, 1.0f, 0.9999999403953552f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80187040_1134D0 },
};
