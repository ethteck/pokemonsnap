/* 0x80382478: native struct MainMenuAnimation80382478. */
struct MainMenuAnimation80382478 {
    AnimLine1 command_80382478;
    AnimLine2 command_80382480;
    AnimLine2 command_8038248C;
    AnimLine1 command_80382498;
    AnimLine3 command_803824A0;
    AnimLine0 command_803824B0;
};

struct MainMenuAnimation80382478 D_80382478_main_menu_vpk0 = {
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSZ) << 15) | 0, { 816.4933471679688f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSX | POSY) << 15) | 0, { 558.2435302734375f, -699.7195434570312f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSX | POSY) << 15) | 345, { 560.216552734375f, -699.7195434570312f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSZ) << 15) | 345, { 179.04534912109375f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 1515, { 560.216552734375f, -699.7195434570312f, 179.04534912109375f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
