/* 0x80391E8C: native struct MainMenuAnimation80391E8C. */
struct MainMenuAnimation80391E8C {
    AnimLine9 command_80391E8C;
    AnimLine9 command_80391EB4;
    AnimLine8 command_80391EDC;
    AnimLine2 command_80391F00;
    AnimLine2 command_80391F0C;
    AnimLine2 command_80391F18;
    AnimLine1 command_80391F24;
    AnimLine1 command_80391F2C;
    AnimLine0 command_80391F34;
};

struct MainMenuAnimation80391E8C D_80391E8C_main_menu_vpk0 = {
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { 0.0f, 0.0f, 0.0f, 0.0f, -13.653558731079102f, 35.222198486328125f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 861, { 0.0f, 0.0f, 0.0f, 0.0f, -13.653558731079102f, 35.222198486328125f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((ROTY | ROTZ | POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 999, { 0.0f, 0.0f, 0.0f, -13.653558731079102f, 35.222198486328125f, 1.0f, 1.0f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 7, { -0.030047662556171417f, -0.0011151464423164725f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 12, { -0.02118777669966221f, 0.0003852263907901943f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((ROTX) << 15) | 66, { 0.0f, 0.00022070608974900097f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX) << 15) | 30, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((ROTX) << 15) | 884, { 0.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
