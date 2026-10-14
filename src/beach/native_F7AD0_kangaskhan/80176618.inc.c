/* ROM 102AA8, VRAM 80176618: complete native animation command stream. */
struct native_F7AD0_kangaskhan_Animation80176618 D_80176618_102AA8 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 2 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 38 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80176618_102AA8 },
};
