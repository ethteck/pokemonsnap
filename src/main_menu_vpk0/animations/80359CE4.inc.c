/* 0x80359CE4: native struct MainMenuAnimation80359CE4. */
struct MainMenuAnimation80359CE4 {
    AnimLineI1 command_80359CE4;
    AnimLineI1 command_80359CEC;
    AnimLineI1 command_80359CF4;
    AnimLine1 command_80359CFC;
    AnimLine1 command_80359D04;
    AnimLineI1 command_80359D0C;
    AnimLineI1 command_80359D14;
    AnimLineI1 command_80359D1C;
    AnimLineI1 command_80359D24;
    AnimLine2 command_80359D2C;
    AnimLine1 command_80359D38;
    AnimLine1 command_80359D40;
    AnimLine0 command_80359D48;
    AnimLineI1 command_80359D4C;
    AnimLineI1 command_80359D54;
    AnimLineI1 command_80359D5C;
    AnimLineI1 command_80359D64;
    AnimLineI1 command_80359D6C;
    AnimLineI1 command_80359D74;
    AnimLine0 command_80359D7C;
};

struct MainMenuAnimation80359CE4 D_80359CE4_main_menu_vpk0 = {
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((LIGHT_COLOR_2) << 15) | 0, { 0x30303000 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((LIGHT_COLOR_1) << 15) | 0, { 0xB3B3B300 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 0, { 0x0066FFFF } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((MAT_PARAM_8) << 15) | 0, { 0.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((MAT_PARAM_8) << 15) | 1155, { 0.0f } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((LIGHT_COLOR_2) << 15) | 1236, { 0x30303000 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER << 25) | ((LIGHT_COLOR_1) << 15) | 1236, { 0xB3B3B300 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 1155, { 0x0066FFFF } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((PRIM_COLOR) << 15) | 81, { 0xF7E208FF } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 10, { 3.0f, 0.05999995395541191f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((MAT_PARAM_8) << 15) | 40, { 3.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER << 25) | ((MAT_PARAM_8) << 15) | 655, { 3.0f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 31 },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((LIGHT_COLOR_2) << 15) | 624, { 0x30303000 } },
    { (ANIM_CMD_SET_EXTRA_VALUE << 25) | ((LIGHT_COLOR_1) << 15) | 624, { 0xB3B3B300 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 24, { 0xFBF07CFF } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 27, { 0xFFFFFF19 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_LAST << 25) | ((PRIM_COLOR) << 15) | 3, { 0xFFFFFF00 } },
    { (ANIM_CMD_SET_EXTRA_VALUE_AFTER_LAST << 25) | ((PRIM_COLOR) << 15) | 570, { 0xFFFFFF00 } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
