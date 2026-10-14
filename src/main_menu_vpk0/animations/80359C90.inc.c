/* 0x80359C90: native struct MainMenuAnimation80359C90. */
struct MainMenuAnimation80359C90 {
    AnimLine9 command_80359C90;
    AnimLine0 command_80359CB8;
    AnimLine0 command_80359CBC;
    AnimLine0 command_80359CC0;
    AnimLine0 command_80359CC4;
};

struct MainMenuAnimation80359C90 D_80359C90_main_menu_vpk0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -2.9802320611338473e-08f, -5.329071365233699e-15f, 1.5881867761018131e-22f, 0.0f, 0.0f, 20.489852905273438f, 14.285714149475098f, 14.285714149475098f, 14.285714149475098f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 1287 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 1 },
    { (ANIM_CMD_16 << 25) | ((0x1) << 15) | 572 },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
