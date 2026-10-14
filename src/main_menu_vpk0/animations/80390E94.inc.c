/* 0x80390E94: native struct MainMenuAnimation80390E94. */
struct MainMenuAnimation80390E94 {
    AnimLine9 command_80390E94;
    AnimLine9 command_80390EBC;
    AnimLine8 command_80390EE4;
    AnimLine2 command_80390F08;
    AnimLine2 command_80390F14;
    AnimLine2 command_80390F20;
    AnimLine1 command_80390F2C;
    AnimLine1 command_80390F34;
    AnimLine1 command_80390F3C;
    AnimLine1 command_80390F44;
    AnimLine1 command_80390F4C;
    AnimLine0 command_80390F54;
};

struct MainMenuAnimation80390E94 D_80390E94_main_menu_vpk0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, 5.007445812225342f, 8.763011932373047f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 861, { 0.0f, 0.0f, 0.0f, 0.0f, 5.007445812225342f, 8.763011932373047f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 999, { 0.0f, 0.0f, 0.0f, 5.007445812225342f, 8.763011932373047f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 7, { -0.011472878977656364f, -0.0014036849606782198f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 12, { -0.026670008897781372f, 0.004622290376573801f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 66, { 0.3490658402442932f, 0.003913916181772947f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX) << 15) | 30, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 120, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX) << 15) | 30, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX) << 15) | 30, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX) << 15) | 704, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
