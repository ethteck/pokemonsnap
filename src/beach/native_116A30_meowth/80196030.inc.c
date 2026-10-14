/* ROM 1224C0, VRAM 80196030: complete native animation command stream. */
struct native_116A30_meowth_Animation80196030 D_80196030_1224C0 = {
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -2.2490819873155488e-08f, -0.01307619083672762f, 0.0f, -63.901771545410156f, 4.260993003845215f, 1.0627672672271729f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 30 },
    { (ANIM_CMD_SET_ANIMATION << 25) | ((0x0) << 15) | 0, (AnimCmd*) &D_80196030_1224C0 },
};
