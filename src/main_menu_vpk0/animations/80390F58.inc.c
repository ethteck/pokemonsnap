/* 0x80390F58: native struct MainMenuAnimation80390F58. */
struct MainMenuAnimation80390F58 {
    AnimLine9 command_80390F58;
    AnimLine9 command_80390F80;
    AnimLine8 command_80390FA8;
    AnimLine1 command_80390FCC;
    AnimLine2 command_80390FD4;
    AnimLine2 command_80390FE0;
    AnimLine1 command_80390FEC;
    AnimLine1 command_80390FF4;
    AnimLine1 command_80390FFC;
    AnimLine1 command_80391004;
    AnimLine1 command_8039100C;
    AnimLine0 command_80391014;
};

struct MainMenuAnimation80390F58 D_80390F58_main_menu_vpk0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, -42.93499755859375f, 42.394996643066406f, -1.8799997568130493f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 861, { 0.0f, 0.0f, 0.0f, -42.93499755859375f, 42.394996643066406f, -1.8799997568130493f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTX | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 999, { 0.0f, 0.0f, -42.93499755859375f, 42.394996643066406f, -1.8799997568130493f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 14, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTY) << 15) | 5, { 0.0f, 0.004916420206427574f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTY) << 15) | 66, { 0.3490658402442932f, 0.003636104054749012f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY) << 15) | 30, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTY) << 15) | 120, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY) << 15) | 30, { 0.3490658402442932f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY) << 15) | 30, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTY) << 15) | 704, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
