/* ROM 236104, VRAM 8016A354: complete native animation command stream. */
struct Cave_Animation8016A354 D_8016A354_236104 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -49.97526931762695f, 6.262985721150471e-07f, -178.6629180908203f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 160 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_8016A354_236104 },
};
