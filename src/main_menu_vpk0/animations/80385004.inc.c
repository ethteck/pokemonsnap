/* 0x80385004: native struct MainMenuAnimation80385004. */
struct MainMenuAnimation80385004 {
    AnimLine0 command_80385004;
    AnimLine6 command_80385008;
    AnimLine6 command_80385024;
    AnimLine1 command_80385040;
    AnimLine3 command_80385048;
    AnimLine0 command_80385058;
    AnimLine1 command_8038505C;
    AnimLine2 command_80385064;
    AnimLine1 command_80385070;
    AnimLine1 command_80385078;
    AnimLine0 command_80385080;
    AnimLine0 command_80385084;
    AnimLine5 command_80385088;
    AnimLine0 command_803850A0;
};

struct MainMenuAnimation80385004 D_80385004_main_menu_vpk0 = {
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 0, { -584.3999633789062f, -166.0f, -707.0000610351562f, 1.600000023841858f, 3.4000000953674316f, 1.0f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 891, { -584.3999633789062f, -166.0f, -707.0000610351562f, 1.600000023841858f, 3.4000000953674316f, 1.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((POSX) << 15) | 7, { -584.3999633789062f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((SCALEX | SCALEY | SCALEZ) << 15) | 23, { 1.600000023841858f, 3.4000000953674316f, 1.0f } },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x0) << 15) | 0 },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSY) << 15) | 969, { -166.0f } },
    { (ANIM_CMD_SET_VALUE_WITH_RATE_LAST << 25) | ((POSZ) << 15) | 7, { -707.0000610351562f, 2.0732056782435393e-06f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSZ) << 15) | 16, { -707.0f } },
    { (ANIM_CMD_SET_VALUE << 25) | ((POSX) << 15) | 16, { -8.999966621398926f } },
    { (ANIM_CMD_WAIT << 25) | ((0x0) << 15) | 14 },
    { (ANIM_CMD_SET_FLAGS << 25) | ((0x1) << 15) | 2 },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSZ | SCALEX | SCALEY | SCALEZ) << 15) | 946, { -8.999966621398926f, -707.0f, 1.600000023841858f, 3.4000000953674316f, 1.0f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
