/* ROM 11363C, VRAM 801871AC: complete native animation command stream. */
struct native_110970_chansey_Animation801871AC D_801871AC_11363C = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -175.0f, 89.99996185302734f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 28 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_801871AC_11363C },
};
