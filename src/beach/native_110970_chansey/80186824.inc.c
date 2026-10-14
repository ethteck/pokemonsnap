/* ROM 112CB4, VRAM 80186824: complete native animation command stream. */
struct native_110970_chansey_Animation80186824 D_80186824_112CB4 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.39269909262657166f, -0.2617993950843811f, 270.00006103515625f, 125.0f, -55.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 40 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80186824_112CB4 },
};
