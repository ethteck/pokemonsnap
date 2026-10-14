/* ROM 10A1EC, VRAM 8017DD5C: complete native animation command stream. */
struct native_105E80_snorlax_Animation8017DD5C D_8017DD5C_10A1EC = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 19 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
