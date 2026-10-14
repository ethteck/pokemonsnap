/* 0x80382500: native struct MainMenuAnimation80382500. */
struct MainMenuAnimation80382500 {
    AnimLine1 command_80382500;
    AnimLine2 command_80382508;
    AnimLine3 command_80382514;
    AnimLine2 command_80382524;
    AnimLine1 command_80382530;
    AnimLine3 command_80382538;
    AnimLine0 command_80382548;
};

struct MainMenuAnimation80382500 D_80382500_main_menu_vpk0 = {
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSZ) << 15) | 0, { 1151.143798828125f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE_LAST << 25) | ((POSX | POSY) << 15) | 0, { 1314.1170654296875f, -1172.24609375f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((ROTX | ROTY | ROTZ) << 15) | 0, { 0.19238348305225372f, -3.0535666942596436f, -0.5375836491584778f } },
    { (ANIM_CMD_SET_VALUE_ZERO_RATE << 25) | ((POSX | POSY) << 15) | 345, { 1336.304443359375f, -1170.48828125f } },
    { (ANIM_CMD_SET_VALUE_LAST << 25) | ((POSZ) << 15) | 345, { 511.185302734375f } },
    { (ANIM_CMD_SET_VALUE_AFTER_LAST << 25) | ((POSX | POSY | POSZ) << 15) | 1515, { 1336.304443359375f, -1170.48828125f, 511.185302734375f } },
    { (ANIM_CMD_END << 25) | ((0x0) << 15) | 0 },
};
