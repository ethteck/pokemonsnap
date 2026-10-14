#include "common.h"
#include "window.h"

/* Physical ROM order, compiled into one ordinary IDO .data section. */
extern u8 D_8037F170_852920[8];
extern u8 D_8037F178_852928[288];
extern Bitmap D_8037F298_852A48[1];
extern Sprite D_8037F2A8_852A58;
extern u8 D_8037F2EC_852A9C[12];
extern u8 D_8037F2F8_852AA8[288];
extern u8 D_8037F418_852BC8[8];
extern u8 D_8037F420_852BD0[288];
extern u8 D_8037F540_852CF0[8];
extern u8 D_8037F548_852CF8[288];
extern u8 D_8037F668_852E18[8];
extern u8 D_8037F670_852E20[288];
extern u8 D_8037F790_852F40[8];
extern u8 D_8037F798_852F48[288];
extern u8 D_8037F8B8_853068[8];
extern u8 D_8037F8C0_853070[288];
extern u8 D_8037F9E0_853190[8];
extern u8 D_8037F9E8_853198[288];
extern u8 D_8037FB08_8532B8[8];
extern u8 D_8037FB10_8532C0[288];
extern u8 D_8037FC30_8533E0[8];
extern u8 D_8037FC38_8533E8[288];
extern u8 D_8037FD58_853508[8];
extern u8 D_8037FD60_853510[288];
extern u8 D_8037FE80_853630[8];
extern u8 D_8037FE88_853638[288];
extern u8 D_8037FFA8_853758[8];
extern u8 D_8037FFB0_853760[288];
extern u8 D_803800D0_853880[8];
extern u8 D_803800D8_853888[288];
extern u8 D_803801F8_8539A8[8];
extern u8 D_80380200_8539B0[288];
extern u8 D_80380320_853AD0[8];
extern u8 D_80380328_853AD8[288];
extern u8 D_80380448_853BF8[8];
extern u8 D_80380450_853C00[288];
extern u8 D_80380570_853D20[8];
extern u8 D_80380578_853D28[288];
extern u8 D_80380698_853E48[8];
extern u8 D_803806A0_853E50[288];
extern u8 D_803807C0_853F70[8];
extern u8 D_803807C8_853F78[288];
extern u8 D_803808E8_854098[8];
extern u8 D_803808F0_8540A0[288];
extern Bitmap D_80380A10_8541C0[1];
extern Bitmap D_80380A20_8541D0[1];
extern Bitmap D_80380A30_8541E0[1];
extern Bitmap D_80380A40_8541F0[1];
extern Bitmap D_80380A50_854200[1];
extern Bitmap D_80380A60_854210[1];
extern Bitmap D_80380A70_854220[1];
extern Bitmap D_80380A80_854230[1];
extern Bitmap D_80380A90_854240[1];
extern Bitmap D_80380AA0_854250[1];
extern Bitmap D_80380AB0_854260[1];
extern Bitmap D_80380AC0_854270[1];
extern Bitmap D_80380AD0_854280[1];
extern Bitmap D_80380AE0_854290[1];
extern Bitmap D_80380AF0_8542A0[2];
extern Bitmap D_80380B10_8542C0[1];
extern Bitmap D_80380B20_8542D0[1];
extern Bitmap D_80380B30_8542E0[1];
extern Bitmap D_80380B40_8542F0[1];
extern Bitmap* D_80380B50_854300[22];
extern s32 D_80380BA8_854358[11];
extern char D_80380BD4_854384[12];
extern UIButtonImageListEntry D_80380BE0_854390;
extern UIButtonImageListEntry* D_80380BEC_85439C;
extern u8 D_80380BF0_8543A0[8];
extern u8 D_80380BF8_8543A8[128];
extern Bitmap D_80380C78_854428[1];
extern Sprite D_80380C88_854438;
extern u8 D_80380CCC_85447C[12];
extern u8 D_80380CD8_854488[128];
extern u8 D_80380D58_854508[8];
extern u8 D_80380D60_854510[128];
extern u8 D_80380DE0_854590[8];
extern u8 D_80380DE8_854598[128];
extern u8 D_80380E68_854618[8];
extern u8 D_80380E70_854620[128];
extern u8 D_80380EF0_8546A0[8];
extern u8 D_80380EF8_8546A8[128];
extern u8 D_80380F78_854728[8];
extern u8 D_80380F80_854730[128];
extern u8 D_80381000_8547B0[8];
extern u8 D_80381008_8547B8[128];
extern u8 D_80381088_854838[8];
extern u8 D_80381090_854840[128];
extern u8 D_80381110_8548C0[8];
extern u8 D_80381118_8548C8[128];
extern u8 D_80381198_854948[8];
extern u8 D_803811A0_854950[128];
extern u8 D_80381220_8549D0[8];
extern u8 D_80381228_8549D8[128];
extern u8 D_803812A8_854A58[8];
extern u8 D_803812B0_854A60[128];
extern u8 D_80381330_854AE0[8];
extern u8 D_80381338_854AE8[128];
extern u8 D_803813B8_854B68[8];
extern u8 D_803813C0_854B70[128];
extern u8 D_80381440_854BF0[8];
extern u8 D_80381448_854BF8[128];
extern u8 D_803814C8_854C78[8];
extern u8 D_803814D0_854C80[128];
extern u8 D_80381550_854D00[8];
extern u8 D_80381558_854D08[128];
extern u8 D_803815D8_854D88[8];
extern u8 D_803815E0_854D90[128];
extern u8 D_80381660_854E10[8];
extern u8 D_80381668_854E18[128];
extern u8 D_803816E8_854E98[8];
extern u8 D_803816F0_854EA0[128];
extern Bitmap D_80381770_854F20[1];
extern Bitmap D_80381780_854F30[1];
extern Bitmap D_80381790_854F40[1];
extern Bitmap D_803817A0_854F50[1];
extern Bitmap D_803817B0_854F60[1];
extern Bitmap D_803817C0_854F70[1];
extern Bitmap D_803817D0_854F80[1];
extern Bitmap D_803817E0_854F90[1];
extern Bitmap D_803817F0_854FA0[1];
extern Bitmap D_80381800_854FB0[1];
extern Bitmap D_80381810_854FC0[1];
extern Bitmap D_80381820_854FD0[1];
extern Bitmap D_80381830_854FE0[1];
extern Bitmap D_80381840_854FF0[1];
extern Bitmap D_80381850_855000[1];
extern Bitmap D_80381860_855010[1];
extern Bitmap D_80381870_855020[1];
extern Bitmap D_80381880_855030[1];
extern Bitmap D_80381890_855040[1];
extern Bitmap D_803818A0_855050[1];
extern Bitmap* D_803818B0_855060[3][9];
extern u8 D_8038191C_8550CC[4];
extern s32 D_80381920_8550D0;
extern u8 D_80381924_8550D4[20];
extern u8 D_80381938_8550E8[240];
extern Bitmap D_80381A28_8551D8[1];
extern Sprite D_80381A38_8551E8;
extern u8 D_80381A7C_85522C[12];
extern u8 D_80381A88_855238[240];
extern u8 D_80381B78_855328[8];
extern u8 D_80381B80_855330[240];
extern u8 D_80381C70_855420[8];
extern u8 D_80381C78_855428[240];
extern Bitmap D_80381D68_855518[1];
extern Bitmap D_80381D78_855528[1];
extern Bitmap D_80381D88_855538[1];
extern Bitmap* D_80381D98_855548[4];
extern u8 D_80381DA8_855558[16];
extern u8 D_80381DB8_855568[3864];
extern Bitmap D_80382CD0_856480[1];
extern Sprite D_80382CE0_856490;
extern u8 D_80382D24_8564D4[12];
extern u8 D_80382D30_8564E0[3864];
extern u8 D_80383C48_8573F8[8];
extern u8 D_80383C50_857400[3864];
extern u8 D_80384B68_858318[8];
extern u8 D_80384B70_858320[3864];
extern u8 D_80385A88_859238[8];
extern u8 D_80385A90_859240[3864];
extern u8 D_803869A8_85A158[8];
extern u8 D_803869B0_85A160[3864];
extern u8 D_803878C8_85B078[8];
extern u8 D_803878D0_85B080[3864];
extern u8 D_803887E8_85BF98[8];
extern u8 D_803887F0_85BFA0[3864];
extern u8 D_80389708_85CEB8[8];
extern u8 D_80389710_85CEC0[3864];
extern u8 D_8038A628_85DDD8[8];
extern u8 D_8038A630_85DDE0[3864];
extern u8 D_8038B548_85ECF8[8];
extern u8 D_8038B550_85ED00[3864];
extern u8 D_8038C468_85FC18[8];
extern u8 D_8038C470_85FC20[3864];
extern u8 D_8038D388_860B38[8];
extern u8 D_8038D390_860B40[3864];
extern u8 D_8038E2A8_861A58[8];
extern u8 D_8038E2B0_861A60[3864];
extern u8 D_8038F1C8_862978[8];
extern u8 D_8038F1D0_862980[3864];
extern u8 D_803900E8_863898[8];
extern u8 D_803900F0_8638A0[3864];
extern u8 D_80391008_8647B8[8];
extern u8 D_80391010_8647C0[3864];
extern u8 D_80391F28_8656D8[8];
extern u8 D_80391F30_8656E0[3864];
extern u8 D_80392E48_8665F8[8];
extern u8 D_80392E50_866600[3864];
extern u8 D_80393D68_867518[8];
extern u8 D_80393D70_867520[3864];
extern u8 D_80394C88_868438[8];
extern u8 D_80394C90_868440[3864];
extern u8 D_80395BA8_869358[8];
extern u8 D_80395BB0_869360[3864];
extern u8 D_80396AC8_86A278[8];
extern u8 D_80396AD0_86A280[3864];
extern u8 D_803979E8_86B198[8];
extern u8 D_803979F0_86B1A0[3864];
extern u8 D_80398908_86C0B8[8];
extern u8 D_80398910_86C0C0[3864];
extern u8 D_80399828_86CFD8[8];
extern u8 D_80399830_86CFE0[3864];
extern u8 D_8039A748_86DEF8[8];
extern u8 D_8039A750_86DF00[3864];
extern u8 D_8039B668_86EE18[8];
extern u8 D_8039B670_86EE20[3864];
extern u8 D_8039C588_86FD38[8];
extern u8 D_8039C590_86FD40[3864];
extern u8 D_8039D4A8_870C58[8];
extern u8 D_8039D4B0_870C60[3864];
extern u8 D_8039E3C8_871B78[8];
extern u8 D_8039E3D0_871B80[3864];
extern u8 D_8039F2E8_872A98[8];
extern u8 D_8039F2F0_872AA0[3864];
extern u8 D_803A0208_8739B8[8];
extern u8 D_803A0210_8739C0[3864];
extern Bitmap D_803A1128_8748D8[1];
extern Bitmap D_803A1138_8748E8[1];
extern Bitmap D_803A1148_8748F8[1];
extern Bitmap D_803A1158_874908[1];
extern Bitmap D_803A1168_874918[1];
extern Bitmap D_803A1178_874928[1];
extern Bitmap D_803A1188_874938[1];
extern Bitmap D_803A1198_874948[1];
extern Bitmap D_803A11A8_874958[1];
extern Bitmap D_803A11B8_874968[1];
extern Bitmap D_803A11C8_874978[1];
extern Bitmap D_803A11D8_874988[1];
extern Bitmap D_803A11E8_874998[1];
extern Bitmap D_803A11F8_8749A8[1];
extern Bitmap D_803A1208_8749B8[1];
extern Bitmap D_803A1218_8749C8[1];
extern Bitmap D_803A1228_8749D8[1];
extern Bitmap D_803A1238_8749E8[1];
extern Bitmap D_803A1248_8749F8[1];
extern Bitmap D_803A1258_874A08[1];
extern Bitmap D_803A1268_874A18[1];
extern Bitmap D_803A1278_874A28[1];
extern Bitmap D_803A1288_874A38[1];
extern Bitmap D_803A1298_874A48[1];
extern Bitmap D_803A12A8_874A58[1];
extern Bitmap D_803A12B8_874A68[1];
extern Bitmap D_803A12C8_874A78[1];
extern Bitmap D_803A12D8_874A88[1];
extern Bitmap D_803A12E8_874A98[1];
extern Bitmap D_803A12F8_874AA8[1];
extern Bitmap D_803A1308_874AB8[1];
extern Bitmap D_803A1318_874AC8[1];
extern u8 D_803A1328_874AD8[8];
extern u8 D_803A1330_874AE0[32];
extern Bitmap D_803A1350_874B00[1];
extern Sprite D_803A1360_874B10;
extern u8 D_803A13A4_874B54[12];
extern u8 D_803A13B0_874B60[1872];
extern Bitmap D_803A1B00_8752B0[1];
extern Sprite D_803A1B10_8752C0;
extern u8 D_803A1B54_875304[12];
extern u8 D_803A1B60_875310[1872];
extern Bitmap D_803A22B0_875A60[1];
extern Sprite D_803A22C0_875A70;
extern u8 D_803A2304_875AB4[12];
extern u8 D_803A2310_875AC0[3952];
extern u8 D_803A3280_876A30[8];
extern u8 D_803A3288_876A38[3952];
extern u8 D_803A41F8_8779A8[8];
extern u8 D_803A4200_8779B0[3952];
extern Bitmap D_803A5170_878920[3];
extern Sprite D_803A51A0_878950;
extern u8 D_803A51E4_878994[12];
extern u8 D_803A51F0_8789A0[288];
extern Bitmap D_803A5310_878AC0[1];
extern Sprite D_803A5320_878AD0;
extern u8 D_803A5364_878B14[12];
extern u8 D_803A5370_878B20[288];
extern Bitmap D_803A5490_878C40[1];
extern Sprite D_803A54A0_878C50;
extern u8 D_803A54E4_878C94[12];
extern u8 D_803A54F0_878CA0[288];
extern Bitmap D_803A5610_878DC0[1];
extern Sprite D_803A5620_878DD0;
extern u8 D_803A5664_878E14[12];
extern u8 D_803A5670_878E20[288];
extern Bitmap D_803A5790_878F40[1];
extern Sprite D_803A57A0_878F50;
extern u8 D_803A57E4_878F94[12];
extern u8 D_803A57F0_878FA0[288];
extern Bitmap D_803A5910_8790C0[1];
extern Sprite D_803A5920_8790D0;
extern u8 D_803A5964_879114[12];
extern u8 D_803A5970_879120[288];
extern Bitmap D_803A5A90_879240[1];
extern Sprite D_803A5AA0_879250;
extern u8 D_803A5AE4_879294[12];
extern u8 D_803A5AF0_8792A0[288];
extern Bitmap D_803A5C10_8793C0[1];
extern Sprite D_803A5C20_8793D0;
extern u8 D_803A5C64_879414[12];
extern u8 D_803A5C70_879420[288];
extern Bitmap D_803A5D90_879540[1];
extern Sprite D_803A5DA0_879550;
extern u8 D_803A5DE4_879594[12];
extern u8 D_803A5DF0_8795A0[288];
extern Bitmap D_803A5F10_8796C0[1];
extern Sprite D_803A5F20_8796D0;
extern u8 D_803A5F64_879714[12];
extern u8 D_803A5F70_879720[288];
extern Bitmap D_803A6090_879840[1];
extern Sprite D_803A60A0_879850;
extern u8 D_803A60E4_879894[12];
extern u8 D_803A60F0_8798A0[288];
extern Bitmap D_803A6210_8799C0;
extern Sprite D_803A6220_8799D0;
extern u8 D_803A6264_879A14[12];
extern u8 D_803A6270_879A20[288];
extern Bitmap D_803A6390_879B40;
extern Sprite D_803A63A0_879B50;
extern u8 D_803A63E4_879B94[12];
extern u8 D_803A63F0_879BA0[288];
extern Bitmap D_803A6510_879CC0;
extern Sprite D_803A6520_879CD0;
extern Bitmap* D_803A6564_879D14[33];
extern Sprite* D_803A65E8_879D98[7];
extern s32 UILayout_PanelState;
extern s32 UILayout_IsAnimationHorizontal;
extern s32 UILayout_IsInstantTransition;
extern UIButton* UILayout_Buttons;
extern s32 UILayout_AnimationFrames;
extern s32 UILayout_HeaderFlags;
extern f32 UILayout_TitlePosY;
extern f32 UILayout_PrevPageIndicatorPosY;
extern s32 UILayout_PrevPageIndicatorCounter;
extern f32 UILayout_NextPageIndicatorPosY;
extern s32 UILayout_NextPageIndicatorCounter;
extern s32 UILayout_PanelVisibility;
extern f32 UILayout_PanelPosX;
extern u8 D_803A6638_879DE8[8];

u8 D_8037F170_852920[8] = { 0 };

u8 D_8037F178_852928[288] = {
#include "build/assets/window/sprites/852928.png.bin.c"
};

Bitmap D_8037F298_852A48[1] = {
    { 12, 12, 0, 0, D_8037F178_852928, 12, 0 }
};

Sprite D_8037F2A8_852A58 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_8037F298_852A48, NULL, NULL, 0, 0
};

u8 D_8037F2EC_852A9C[12] = { 0 };

u8 D_8037F2F8_852AA8[288] = {
#include "build/assets/window/sprites/852AA8.png.bin.c"
};

u8 D_8037F418_852BC8[8] = { 0 };

u8 D_8037F420_852BD0[288] = {
#include "build/assets/window/sprites/852BD0.png.bin.c"
};

u8 D_8037F540_852CF0[8] = { 0 };

u8 D_8037F548_852CF8[288] = {
#include "build/assets/window/sprites/852CF8.png.bin.c"
};

u8 D_8037F668_852E18[8] = { 0 };

u8 D_8037F670_852E20[288] = {
#include "build/assets/window/sprites/852E20.png.bin.c"
};

u8 D_8037F790_852F40[8] = { 0 };

u8 D_8037F798_852F48[288] = {
#include "build/assets/window/sprites/852F48.png.bin.c"
};

u8 D_8037F8B8_853068[8] = { 0 };

u8 D_8037F8C0_853070[288] = {
#include "build/assets/window/sprites/853070.png.bin.c"
};

u8 D_8037F9E0_853190[8] = { 0 };

u8 D_8037F9E8_853198[288] = {
#include "build/assets/window/sprites/853198.png.bin.c"
};

u8 D_8037FB08_8532B8[8] = { 0 };

u8 D_8037FB10_8532C0[288] = {
#include "build/assets/window/sprites/8532C0.png.bin.c"
};

u8 D_8037FC30_8533E0[8] = { 0 };

u8 D_8037FC38_8533E8[288] = {
#include "build/assets/window/sprites/8533E8.png.bin.c"
};

u8 D_8037FD58_853508[8] = { 0 };

u8 D_8037FD60_853510[288] = {
#include "build/assets/window/sprites/853510.png.bin.c"
};

u8 D_8037FE80_853630[8] = { 0 };

u8 D_8037FE88_853638[288] = {
#include "build/assets/window/sprites/853638.png.bin.c"
};

u8 D_8037FFA8_853758[8] = { 0 };

u8 D_8037FFB0_853760[288] = {
#include "build/assets/window/sprites/853760.png.bin.c"
};

u8 D_803800D0_853880[8] = { 0 };

u8 D_803800D8_853888[288] = {
#include "build/assets/window/sprites/853888.png.bin.c"
};

u8 D_803801F8_8539A8[8] = { 0 };

u8 D_80380200_8539B0[288] = {
#include "build/assets/window/sprites/8539B0.png.bin.c"
};

u8 D_80380320_853AD0[8] = { 0 };

u8 D_80380328_853AD8[288] = {
#include "build/assets/window/sprites/853AD8.png.bin.c"
};

u8 D_80380448_853BF8[8] = { 0 };

u8 D_80380450_853C00[288] = {
#include "build/assets/window/sprites/853C00.png.bin.c"
};

u8 D_80380570_853D20[8] = { 0 };

u8 D_80380578_853D28[288] = {
#include "build/assets/window/sprites/853D28.png.bin.c"
};

u8 D_80380698_853E48[8] = { 0 };

u8 D_803806A0_853E50[288] = {
#include "build/assets/window/sprites/853E50.png.bin.c"
};

u8 D_803807C0_853F70[8] = { 0 };

u8 D_803807C8_853F78[288] = {
#include "build/assets/window/sprites/853F78.png.bin.c"
};

u8 D_803808E8_854098[8] = { 0 };

u8 D_803808F0_8540A0[288] = {
#include "build/assets/window/sprites/8540A0.png.bin.c"
};

Bitmap D_80380A10_8541C0[1] = {
    { 12, 12, 0, 0, D_8037F2F8_852AA8, 12, 0 }
};

Bitmap D_80380A20_8541D0[1] = {
    { 12, 12, 0, 0, D_8037F420_852BD0, 12, 0 }
};

Bitmap D_80380A30_8541E0[1] = {
    { 12, 12, 0, 0, D_8037F548_852CF8, 12, 0 }
};

Bitmap D_80380A40_8541F0[1] = {
    { 12, 12, 0, 0, D_8037F670_852E20, 12, 0 }
};

Bitmap D_80380A50_854200[1] = {
    { 12, 12, 0, 0, D_8037F798_852F48, 12, 0 }
};

Bitmap D_80380A60_854210[1] = {
    { 12, 12, 0, 0, D_8037F8C0_853070, 12, 0 }
};

Bitmap D_80380A70_854220[1] = {
    { 12, 12, 0, 0, D_8037F9E8_853198, 12, 0 }
};

Bitmap D_80380A80_854230[1] = {
    { 12, 12, 0, 0, D_8037FB10_8532C0, 12, 0 }
};

Bitmap D_80380A90_854240[1] = {
    { 12, 12, 0, 0, D_8037FC38_8533E8, 12, 0 }
};

Bitmap D_80380AA0_854250[1] = {
    { 12, 12, 0, 0, D_8037FD60_853510, 12, 0 }
};

Bitmap D_80380AB0_854260[1] = {
    { 12, 12, 0, 0, D_8037FE88_853638, 12, 0 }
};

Bitmap D_80380AC0_854270[1] = {
    { 12, 12, 0, 0, D_8037FFB0_853760, 12, 0 }
};

Bitmap D_80380AD0_854280[1] = {
    { 12, 12, 0, 0, D_803800D8_853888, 12, 0 }
};

Bitmap D_80380AE0_854290[1] = {
    { 12, 12, 0, 0, D_80380200_8539B0, 12, 0 }
};

Bitmap D_80380AF0_8542A0[2] = {
    { 12, 12, 0, 0, D_80380328_853AD8, 12, 0 },
    { 12, 12, 0, 0, D_80380450_853C00, 12, 0 }
};

Bitmap D_80380B10_8542C0[1] = {
    { 12, 12, 0, 0, D_80380578_853D28, 12, 0 }
};

Bitmap D_80380B20_8542D0[1] = {
    { 12, 12, 0, 0, D_803806A0_853E50, 12, 0 }
};

Bitmap D_80380B30_8542E0[1] = {
    { 12, 12, 0, 0, D_803807C8_853F78, 12, 0 }
};

Bitmap D_80380B40_8542F0[1] = {
    { 12, 12, 0, 0, D_803808F0_8540A0, 12, 0 }
};

Bitmap* D_80380B50_854300[22] = {
    D_8037F298_852A48,
    D_80380A10_8541C0,
    D_80380A20_8541D0,
    D_80380A30_8541E0,
    D_80380A60_854210,
    D_80380A70_854220,
    D_80380A40_8541F0,
    D_80380A50_854200,
    D_80380A80_854230,
    D_80380A90_854240,
    D_80380AA0_854250,
    D_80380AB0_854260,
    D_80380AC0_854270,
    D_80380AD0_854280,
    D_80380AE0_854290,
    D_80380AF0_8542A0,
    D_80380B10_8542C0,
    D_80380B20_8542D0,
    D_80380B30_8542E0,
    D_80380B30_8542E0,
    D_80380B40_8542F0,
    D_80380B40_8542F0
};

s32 D_80380BA8_854358[11] = { 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24 };

char D_80380BD4_854384[12] = "abcdfrzlsmu";

UIButtonImageListEntry D_80380BE0_854390 = { &D_80380BE0_854390, &D_80380BE0_854390, NULL };

UIButtonImageListEntry* D_80380BEC_85439C = &D_80380BE0_854390;

u8 D_80380BF0_8543A0[8] = { 0 };

u8 D_80380BF8_8543A8[128] = {
#include "build/assets/window/sprites/8543A8.png.bin.c"
};

Bitmap D_80380C78_854428[1] = {
    { 8, 8, 0, 0, D_80380BF8_8543A8, 8, 0 }
};

Sprite D_80380C88_854438 = {
    0, 0, 8, 8, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 8, 8, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80380C78_854428, NULL, NULL, 0, 0
};

u8 D_80380CCC_85447C[12] = { 0 };

u8 D_80380CD8_854488[128] = {
#include "build/assets/window/sprites/854488.png.bin.c"
};

u8 D_80380D58_854508[8] = { 0 };

u8 D_80380D60_854510[128] = {
#include "build/assets/window/sprites/854510.png.bin.c"
};

u8 D_80380DE0_854590[8] = { 0 };

u8 D_80380DE8_854598[128] = {
#include "build/assets/window/sprites/854598.png.bin.c"
};

u8 D_80380E68_854618[8] = { 0 };

u8 D_80380E70_854620[128] = {
#include "build/assets/window/sprites/854620.png.bin.c"
};

u8 D_80380EF0_8546A0[8] = { 0 };

u8 D_80380EF8_8546A8[128] = {
#include "build/assets/window/sprites/8546A8.png.bin.c"
};

u8 D_80380F78_854728[8] = { 0 };

u8 D_80380F80_854730[128] = {
#include "build/assets/window/sprites/854730.png.bin.c"
};

u8 D_80381000_8547B0[8] = { 0 };

u8 D_80381008_8547B8[128] = {
#include "build/assets/window/sprites/8547B8.png.bin.c"
};

u8 D_80381088_854838[8] = { 0 };

u8 D_80381090_854840[128] = {
#include "build/assets/window/sprites/854840.png.bin.c"
};

u8 D_80381110_8548C0[8] = { 0 };

u8 D_80381118_8548C8[128] = {
#include "build/assets/window/sprites/8548C8.png.bin.c"
};

u8 D_80381198_854948[8] = { 0 };

u8 D_803811A0_854950[128] = {
#include "build/assets/window/sprites/854950.png.bin.c"
};

u8 D_80381220_8549D0[8] = { 0 };

u8 D_80381228_8549D8[128] = {
#include "build/assets/window/sprites/8549D8.png.bin.c"
};

u8 D_803812A8_854A58[8] = { 0 };

u8 D_803812B0_854A60[128] = {
#include "build/assets/window/sprites/854A60.png.bin.c"
};

u8 D_80381330_854AE0[8] = { 0 };

u8 D_80381338_854AE8[128] = {
#include "build/assets/window/sprites/854AE8.png.bin.c"
};

u8 D_803813B8_854B68[8] = { 0 };

u8 D_803813C0_854B70[128] = {
#include "build/assets/window/sprites/854B70.png.bin.c"
};

u8 D_80381440_854BF0[8] = { 0 };

u8 D_80381448_854BF8[128] = {
#include "build/assets/window/sprites/854BF8.png.bin.c"
};

u8 D_803814C8_854C78[8] = { 0 };

u8 D_803814D0_854C80[128] = {
#include "build/assets/window/sprites/854C80.png.bin.c"
};

u8 D_80381550_854D00[8] = { 0 };

u8 D_80381558_854D08[128] = {
#include "build/assets/window/sprites/854D08.png.bin.c"
};

u8 D_803815D8_854D88[8] = { 0 };

u8 D_803815E0_854D90[128] = {
#include "build/assets/window/sprites/854D90.png.bin.c"
};

u8 D_80381660_854E10[8] = { 0 };

u8 D_80381668_854E18[128] = {
#include "build/assets/window/sprites/854E18.png.bin.c"
};

u8 D_803816E8_854E98[8] = { 0 };

u8 D_803816F0_854EA0[128] = {
#include "build/assets/window/sprites/854EA0.png.bin.c"
};

Bitmap D_80381770_854F20[1] = {
    { 8, 8, 0, 0, D_80380CD8_854488, 8, 0 }
};

Bitmap D_80381780_854F30[1] = {
    { 8, 8, 0, 0, D_80380D60_854510, 8, 0 }
};

Bitmap D_80381790_854F40[1] = {
    { 8, 8, 0, 0, D_80380DE8_854598, 8, 0 }
};

Bitmap D_803817A0_854F50[1] = {
    { 8, 8, 0, 0, D_80380E70_854620, 8, 0 }
};

Bitmap D_803817B0_854F60[1] = {
    { 8, 8, 0, 0, D_80380EF8_8546A8, 8, 0 }
};

Bitmap D_803817C0_854F70[1] = {
    { 8, 8, 0, 0, D_80380F80_854730, 8, 0 }
};

Bitmap D_803817D0_854F80[1] = {
    { 8, 8, 0, 0, D_80381008_8547B8, 8, 0 }
};

Bitmap D_803817E0_854F90[1] = {
    { 8, 8, 0, 0, D_80381090_854840, 8, 0 }
};

Bitmap D_803817F0_854FA0[1] = {
    { 8, 8, 0, 0, D_80381118_8548C8, 8, 0 }
};

Bitmap D_80381800_854FB0[1] = {
    { 8, 8, 0, 0, D_803811A0_854950, 8, 0 }
};

Bitmap D_80381810_854FC0[1] = {
    { 8, 8, 0, 0, D_80381228_8549D8, 8, 0 }
};

Bitmap D_80381820_854FD0[1] = {
    { 8, 8, 0, 0, D_803812B0_854A60, 8, 0 }
};

Bitmap D_80381830_854FE0[1] = {
    { 8, 8, 0, 0, D_80381338_854AE8, 8, 0 }
};

Bitmap D_80381840_854FF0[1] = {
    { 8, 8, 0, 0, D_803813C0_854B70, 8, 0 }
};

Bitmap D_80381850_855000[1] = {
    { 8, 8, 0, 0, D_80381448_854BF8, 8, 0 }
};

Bitmap D_80381860_855010[1] = {
    { 8, 8, 0, 0, D_803814D0_854C80, 8, 0 }
};

Bitmap D_80381870_855020[1] = {
    { 8, 8, 0, 0, D_80381558_854D08, 8, 0 }
};

Bitmap D_80381880_855030[1] = {
    { 8, 8, 0, 0, D_803815E0_854D90, 8, 0 }
};

Bitmap D_80381890_855040[1] = {
    { 8, 8, 0, 0, D_80381668_854E18, 8, 0 }
};

Bitmap D_803818A0_855050[1] = {
    { 8, 8, 0, 0, D_803816F0_854EA0, 8, 0 }
};

Bitmap* D_803818B0_855060[3][9] = {
    { D_80381770_854F20, D_80381780_854F30, D_80381790_854F40, D_803817A0_854F50, D_803817B0_854F60, D_803817C0_854F70, D_80380C78_854428, D_80381770_854F20, D_803817C0_854F70 },
    { D_80381840_854FF0, D_80381850_855000, D_80381860_855010, D_80381870_855020, D_80381880_855030, D_80381890_855040, D_803818A0_855050, D_80381840_854FF0, D_80381890_855040 },
    { D_803817D0_854F80, D_803817E0_854F90, D_803817F0_854FA0, D_80381800_854FB0, D_80381810_854FC0, D_80381820_854FD0, D_80381830_854FE0, D_803817D0_854F80, D_80381820_854FD0 }
};

u8 D_8038191C_8550CC[4] = { 0 };

s32 D_80381920_8550D0 = 15;

u8 D_80381924_8550D4[20] = { 0 };

u8 D_80381938_8550E8[240] = {
#include "build/assets/window/sprites/8550E8.png.bin.c"
};

Bitmap D_80381A28_8551D8[1] = {
    { 10, 12, 0, 0, D_80381938_8550E8, 10, 0 }
};

Sprite D_80381A38_8551E8 = {
    0, 0, 10, 10, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 10, 10, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80381A28_8551D8, NULL, NULL, 0, 0
};

u8 D_80381A7C_85522C[12] = { 0 };

u8 D_80381A88_855238[240] = {
#include "build/assets/window/sprites/855238.png.bin.c"
};

u8 D_80381B78_855328[8] = { 0 };

u8 D_80381B80_855330[240] = {
#include "build/assets/window/sprites/855330.png.bin.c"
};

u8 D_80381C70_855420[8] = { 0 };

u8 D_80381C78_855428[240] = {
#include "build/assets/window/sprites/855428.png.bin.c"
};

Bitmap D_80381D68_855518[1] = {
    { 10, 12, 0, 0, D_80381A88_855238, 10, 0 }
};

Bitmap D_80381D78_855528[1] = {
    { 10, 12, 0, 0, D_80381B80_855330, 10, 0 }
};

Bitmap D_80381D88_855538[1] = {
    { 10, 12, 0, 0, D_80381C78_855428, 10, 0 }
};

Bitmap* D_80381D98_855548[4] = {
    D_80381D68_855518,
    D_80381D88_855538,
    D_80381A28_8551D8,
    D_80381D78_855528
};

u8 D_80381DA8_855558[16] = { 0 };

u8 D_80381DB8_855568[3864] = {
#include "build/assets/window/sprites/855568.png.bin.c"
};

Bitmap D_80382CD0_856480[1] = {
    { 89, 92, 0, 0, D_80381DB8_855568, 21, 0 }
};

Sprite D_80382CE0_856490 = {
    0, 0, 89, 21, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 21, 21, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_80382CD0_856480, NULL, NULL, 0, 0
};

u8 D_80382D24_8564D4[12] = { 0 };

u8 D_80382D30_8564E0[3864] = {
#include "build/assets/window/sprites/8564E0.png.bin.c"
};

u8 D_80383C48_8573F8[8] = { 0 };

u8 D_80383C50_857400[3864] = {
#include "build/assets/window/sprites/857400.png.bin.c"
};

u8 D_80384B68_858318[8] = { 0 };

u8 D_80384B70_858320[3864] = {
#include "build/assets/window/sprites/858320.png.bin.c"
};

u8 D_80385A88_859238[8] = { 0 };

u8 D_80385A90_859240[3864] = {
#include "build/assets/window/sprites/859240.png.bin.c"
};

u8 D_803869A8_85A158[8] = { 0 };

u8 D_803869B0_85A160[3864] = {
#include "build/assets/window/sprites/85A160.png.bin.c"
};

u8 D_803878C8_85B078[8] = { 0 };

u8 D_803878D0_85B080[3864] = {
#include "build/assets/window/sprites/85B080.png.bin.c"
};

u8 D_803887E8_85BF98[8] = { 0 };

u8 D_803887F0_85BFA0[3864] = {
#include "build/assets/window/sprites/85BFA0.png.bin.c"
};

u8 D_80389708_85CEB8[8] = { 0 };

u8 D_80389710_85CEC0[3864] = {
#include "build/assets/window/sprites/85CEC0.png.bin.c"
};

u8 D_8038A628_85DDD8[8] = { 0 };

u8 D_8038A630_85DDE0[3864] = {
#include "build/assets/window/sprites/85DDE0.png.bin.c"
};

u8 D_8038B548_85ECF8[8] = { 0 };

u8 D_8038B550_85ED00[3864] = {
#include "build/assets/window/sprites/85ED00.png.bin.c"
};

u8 D_8038C468_85FC18[8] = { 0 };

u8 D_8038C470_85FC20[3864] = {
#include "build/assets/window/sprites/85FC20.png.bin.c"
};

u8 D_8038D388_860B38[8] = { 0 };

u8 D_8038D390_860B40[3864] = {
#include "build/assets/window/sprites/860B40.png.bin.c"
};

u8 D_8038E2A8_861A58[8] = { 0 };

u8 D_8038E2B0_861A60[3864] = {
#include "build/assets/window/sprites/861A60.png.bin.c"
};

u8 D_8038F1C8_862978[8] = { 0 };

u8 D_8038F1D0_862980[3864] = {
#include "build/assets/window/sprites/862980.png.bin.c"
};

u8 D_803900E8_863898[8] = { 0 };

u8 D_803900F0_8638A0[3864] = {
#include "build/assets/window/sprites/8638A0.png.bin.c"
};

u8 D_80391008_8647B8[8] = { 0 };

u8 D_80391010_8647C0[3864] = {
#include "build/assets/window/sprites/8647C0.png.bin.c"
};

u8 D_80391F28_8656D8[8] = { 0 };

u8 D_80391F30_8656E0[3864] = {
#include "build/assets/window/sprites/8656E0.png.bin.c"
};

u8 D_80392E48_8665F8[8] = { 0 };

u8 D_80392E50_866600[3864] = {
#include "build/assets/window/sprites/866600.png.bin.c"
};

u8 D_80393D68_867518[8] = { 0 };

u8 D_80393D70_867520[3864] = {
#include "build/assets/window/sprites/867520.png.bin.c"
};

u8 D_80394C88_868438[8] = { 0 };

u8 D_80394C90_868440[3864] = {
#include "build/assets/window/sprites/868440.png.bin.c"
};

u8 D_80395BA8_869358[8] = { 0 };

u8 D_80395BB0_869360[3864] = {
#include "build/assets/window/sprites/869360.png.bin.c"
};

u8 D_80396AC8_86A278[8] = { 0 };

u8 D_80396AD0_86A280[3864] = {
#include "build/assets/window/sprites/86A280.png.bin.c"
};

u8 D_803979E8_86B198[8] = { 0 };

u8 D_803979F0_86B1A0[3864] = {
#include "build/assets/window/sprites/86B1A0.png.bin.c"
};

u8 D_80398908_86C0B8[8] = { 0 };

u8 D_80398910_86C0C0[3864] = {
#include "build/assets/window/sprites/86C0C0.png.bin.c"
};

u8 D_80399828_86CFD8[8] = { 0 };

u8 D_80399830_86CFE0[3864] = {
#include "build/assets/window/sprites/86CFE0.png.bin.c"
};

u8 D_8039A748_86DEF8[8] = { 0 };

u8 D_8039A750_86DF00[3864] = {
#include "build/assets/window/sprites/86DF00.png.bin.c"
};

u8 D_8039B668_86EE18[8] = { 0 };

u8 D_8039B670_86EE20[3864] = {
#include "build/assets/window/sprites/86EE20.png.bin.c"
};

u8 D_8039C588_86FD38[8] = { 0 };

u8 D_8039C590_86FD40[3864] = {
#include "build/assets/window/sprites/86FD40.png.bin.c"
};

u8 D_8039D4A8_870C58[8] = { 0 };

u8 D_8039D4B0_870C60[3864] = {
#include "build/assets/window/sprites/870C60.png.bin.c"
};

u8 D_8039E3C8_871B78[8] = { 0 };

u8 D_8039E3D0_871B80[3864] = {
#include "build/assets/window/sprites/871B80.png.bin.c"
};

u8 D_8039F2E8_872A98[8] = { 0 };

u8 D_8039F2F0_872AA0[3864] = {
#include "build/assets/window/sprites/872AA0.png.bin.c"
};

u8 D_803A0208_8739B8[8] = { 0 };

u8 D_803A0210_8739C0[3864] = {
#include "build/assets/window/sprites/8739C0.png.bin.c"
};

Bitmap D_803A1128_8748D8[1] = {
    { 89, 92, 0, 0, D_80382D30_8564E0, 21, 0 }
};

Bitmap D_803A1138_8748E8[1] = {
    { 89, 92, 0, 0, D_80383C50_857400, 21, 0 }
};

Bitmap D_803A1148_8748F8[1] = {
    { 89, 92, 0, 0, D_80384B70_858320, 21, 0 }
};

Bitmap D_803A1158_874908[1] = {
    { 89, 92, 0, 0, D_80385A90_859240, 21, 0 }
};

Bitmap D_803A1168_874918[1] = {
    { 89, 92, 0, 0, D_803869B0_85A160, 21, 0 }
};

Bitmap D_803A1178_874928[1] = {
    { 89, 92, 0, 0, D_803878D0_85B080, 21, 0 }
};

Bitmap D_803A1188_874938[1] = {
    { 89, 92, 0, 0, D_803887F0_85BFA0, 21, 0 }
};

Bitmap D_803A1198_874948[1] = {
    { 89, 92, 0, 0, D_8038B550_85ED00, 21, 0 }
};

Bitmap D_803A11A8_874958[1] = {
    { 89, 92, 0, 0, D_8038A630_85DDE0, 21, 0 }
};

Bitmap D_803A11B8_874968[1] = {
    { 89, 92, 0, 0, D_80389710_85CEC0, 21, 0 }
};

Bitmap D_803A11C8_874978[1] = {
    { 89, 92, 0, 0, D_8038C470_85FC20, 21, 0 }
};

Bitmap D_803A11D8_874988[1] = {
    { 89, 92, 0, 0, D_8038D390_860B40, 21, 0 }
};

Bitmap D_803A11E8_874998[1] = {
    { 89, 92, 0, 0, D_8038E2B0_861A60, 21, 0 }
};

Bitmap D_803A11F8_8749A8[1] = {
    { 89, 92, 0, 0, D_8038F1D0_862980, 21, 0 }
};

Bitmap D_803A1208_8749B8[1] = {
    { 89, 92, 0, 0, D_803900F0_8638A0, 21, 0 }
};

Bitmap D_803A1218_8749C8[1] = {
    { 89, 92, 0, 0, D_80391010_8647C0, 21, 0 }
};

Bitmap D_803A1228_8749D8[1] = {
    { 89, 92, 0, 0, D_80391F30_8656E0, 21, 0 }
};

Bitmap D_803A1238_8749E8[1] = {
    { 89, 92, 0, 0, D_80392E50_866600, 21, 0 }
};

Bitmap D_803A1248_8749F8[1] = {
    { 89, 92, 0, 0, D_80393D70_867520, 21, 0 }
};

Bitmap D_803A1258_874A08[1] = {
    { 89, 92, 0, 0, D_80394C90_868440, 21, 0 }
};

Bitmap D_803A1268_874A18[1] = {
    { 89, 92, 0, 0, D_80395BB0_869360, 21, 0 }
};

Bitmap D_803A1278_874A28[1] = {
    { 89, 92, 0, 0, D_80396AD0_86A280, 21, 0 }
};

Bitmap D_803A1288_874A38[1] = {
    { 89, 92, 0, 0, D_803979F0_86B1A0, 21, 0 }
};

Bitmap D_803A1298_874A48[1] = {
    { 89, 92, 0, 0, D_80398910_86C0C0, 21, 0 }
};

Bitmap D_803A12A8_874A58[1] = {
    { 89, 92, 0, 0, D_80399830_86CFE0, 21, 0 }
};

Bitmap D_803A12B8_874A68[1] = {
    { 89, 92, 0, 0, D_8039A750_86DF00, 21, 0 }
};

Bitmap D_803A12C8_874A78[1] = {
    { 89, 92, 0, 0, D_8039B670_86EE20, 21, 0 }
};

Bitmap D_803A12D8_874A88[1] = {
    { 89, 92, 0, 0, D_8039C590_86FD40, 21, 0 }
};

Bitmap D_803A12E8_874A98[1] = {
    { 89, 92, 0, 0, D_8039D4B0_870C60, 21, 0 }
};

Bitmap D_803A12F8_874AA8[1] = {
    { 89, 92, 0, 0, D_8039E3D0_871B80, 21, 0 }
};

Bitmap D_803A1308_874AB8[1] = {
    { 89, 92, 0, 0, D_8039F2F0_872AA0, 21, 0 }
};

Bitmap D_803A1318_874AC8[1] = {
    { 89, 92, 0, 0, D_803A0210_8739C0, 21, 0 }
};

u8 D_803A1328_874AD8[8] = { 0 };

u8 D_803A1330_874AE0[32] = {
#include "build/assets/window/sprites/874AE0.png.bin.c"
};

Bitmap D_803A1350_874B00[1] = {
    { 4, 4, 0, 0, D_803A1330_874AE0, 4, 0 }
};

Sprite D_803A1360_874B10 = {
    0, 0, 4, 4, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 4, 4, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A1350_874B00, NULL, NULL, 0, 0
};

u8 D_803A13A4_874B54[12] = { 0 };

u8 D_803A13B0_874B60[1872] = {
#include "build/assets/window/sprites/874B60.png.bin.c"
};

Bitmap D_803A1B00_8752B0[1] = {
    { 24, 24, 0, 0, D_803A13B0_874B60, 39, 0 }
};

Sprite D_803A1B10_8752C0 = {
    0, 0, 24, 39, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 39, 39, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A1B00_8752B0, NULL, NULL, 0, 0
};

u8 D_803A1B54_875304[12] = { 0 };

u8 D_803A1B60_875310[1872] = {
#include "build/assets/window/sprites/875310.png.bin.c"
};

Bitmap D_803A22B0_875A60[1] = {
    { 24, 24, 0, 0, D_803A1B60_875310, 39, 0 }
};

Sprite D_803A22C0_875A70 = {
    0, 0, 24, 39, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 39, 39, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A22B0_875A60, NULL, NULL, 0, 0
};

u8 D_803A2304_875AB4[12] = { 0 };

u8 D_803A2310_875AC0[3952] = {
#include "build/assets/window/sprites/875AC0.png.bin.c"
};

u8 D_803A3280_876A30[8] = { 0 };

u8 D_803A3288_876A38[3952] = {
#include "build/assets/window/sprites/876A38.png.bin.c"
};

u8 D_803A41F8_8779A8[8] = { 0 };

u8 D_803A4200_8779B0[3952] = {
#include "build/assets/window/sprites/8779B0.png.bin.c"
};

Bitmap D_803A5170_878920[3] = {
    { 152, 152, 0, 0, D_803A2310_875AC0, 13, 0 },
    { 152, 152, 0, 0, D_803A3288_876A38, 13, 0 },
    { 152, 152, 0, 0, D_803A4200_8779B0, 13, 0 }
};

Sprite D_803A51A0_878950 = {
    0, 0, 152, 39, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 3, 60, 13, 13, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5170_878920, NULL, NULL, 0, 0
};

u8 D_803A51E4_878994[12] = { 0 };

u8 D_803A51F0_8789A0[288] = {
#include "build/assets/window/sprites/8789A0.png.bin.c"
};

Bitmap D_803A5310_878AC0[1] = {
    { 12, 12, 0, 0, D_803A51F0_8789A0, 12, 0 }
};

Sprite D_803A5320_878AD0 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5310_878AC0, NULL, NULL, 0, 0
};

u8 D_803A5364_878B14[12] = { 0 };

u8 D_803A5370_878B20[288] = {
#include "build/assets/window/sprites/878B20.png.bin.c"
};

Bitmap D_803A5490_878C40[1] = {
    { 12, 12, 0, 0, D_803A5370_878B20, 12, 0 }
};

Sprite D_803A54A0_878C50 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5490_878C40, NULL, NULL, 0, 0
};

u8 D_803A54E4_878C94[12] = { 0 };

u8 D_803A54F0_878CA0[288] = {
#include "build/assets/window/sprites/878CA0.png.bin.c"
};

Bitmap D_803A5610_878DC0[1] = {
    { 12, 12, 0, 0, D_803A54F0_878CA0, 12, 0 }
};

Sprite D_803A5620_878DD0 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5610_878DC0, NULL, NULL, 0, 0
};

u8 D_803A5664_878E14[12] = { 0 };

u8 D_803A5670_878E20[288] = {
#include "build/assets/window/sprites/878E20.png.bin.c"
};

Bitmap D_803A5790_878F40[1] = {
    { 12, 12, 0, 0, D_803A5670_878E20, 12, 0 }
};

Sprite D_803A57A0_878F50 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5790_878F40, NULL, NULL, 0, 0
};

u8 D_803A57E4_878F94[12] = { 0 };

u8 D_803A57F0_878FA0[288] = {
#include "build/assets/window/sprites/878FA0.png.bin.c"
};

Bitmap D_803A5910_8790C0[1] = {
    { 12, 12, 0, 0, D_803A57F0_878FA0, 12, 0 }
};

Sprite D_803A5920_8790D0 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5910_8790C0, NULL, NULL, 0, 0
};

u8 D_803A5964_879114[12] = { 0 };

u8 D_803A5970_879120[288] = {
#include "build/assets/window/sprites/879120.png.bin.c"
};

Bitmap D_803A5A90_879240[1] = {
    { 12, 12, 0, 0, D_803A5970_879120, 12, 0 }
};

Sprite D_803A5AA0_879250 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5A90_879240, NULL, NULL, 0, 0
};

u8 D_803A5AE4_879294[12] = { 0 };

u8 D_803A5AF0_8792A0[288] = {
#include "build/assets/window/sprites/8792A0.png.bin.c"
};

Bitmap D_803A5C10_8793C0[1] = {
    { 12, 12, 0, 0, D_803A5AF0_8792A0, 12, 0 }
};

Sprite D_803A5C20_8793D0 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5C10_8793C0, NULL, NULL, 0, 0
};

u8 D_803A5C64_879414[12] = { 0 };

u8 D_803A5C70_879420[288] = {
#include "build/assets/window/sprites/879420.png.bin.c"
};

Bitmap D_803A5D90_879540[1] = {
    { 12, 12, 0, 0, D_803A5C70_879420, 12, 0 }
};

Sprite D_803A5DA0_879550 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5D90_879540, NULL, NULL, 0, 0
};

u8 D_803A5DE4_879594[12] = { 0 };

u8 D_803A5DF0_8795A0[288] = {
#include "build/assets/window/sprites/8795A0.png.bin.c"
};

Bitmap D_803A5F10_8796C0[1] = {
    { 12, 12, 0, 0, D_803A5DF0_8795A0, 12, 0 }
};

Sprite D_803A5F20_8796D0 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A5F10_8796C0, NULL, NULL, 0, 0
};

u8 D_803A5F64_879714[12] = { 0 };

u8 D_803A5F70_879720[288] = {
#include "build/assets/window/sprites/879720.png.bin.c"
};

Bitmap D_803A6090_879840[1] = {
    { 12, 12, 0, 0, D_803A5F70_879720, 12, 0 }
};

Sprite D_803A60A0_879850 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_803A6090_879840, NULL, NULL, 0, 0
};

u8 D_803A60E4_879894[12] = { 0 };

u8 D_803A60F0_8798A0[288] = {
#include "build/assets/window/sprites/8798A0.png.bin.c"
};

Bitmap D_803A6210_8799C0 = { 12, 12, 0, 0, D_803A60F0_8798A0, 12, 0 };

Sprite D_803A6220_8799D0 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, &D_803A6210_8799C0, NULL, NULL, 0, 0
};

u8 D_803A6264_879A14[12] = { 0 };

u8 D_803A6270_879A20[288] = {
#include "build/assets/window/sprites/879A20.png.bin.c"
};

Bitmap D_803A6390_879B40 = { 12, 12, 0, 0, D_803A6270_879A20, 12, 0 };

Sprite D_803A63A0_879B50 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, &D_803A6390_879B40, NULL, NULL, 0, 0
};

u8 D_803A63E4_879B94[12] = { 0 };

u8 D_803A63F0_879BA0[288] = {
#include "build/assets/window/sprites/879BA0.png.bin.c"
};

Bitmap D_803A6510_879CC0 = { 12, 12, 0, 0, D_803A63F0_879BA0, 12, 0 };

Sprite D_803A6520_879CD0 = {
    0, 0, 12, 12, 1.0f, 1.0f, 0, 0, SP_TEXSHUF, 4660, 255, 255, 255, 255, 0, 0, NULL, 0, 1, 1, 36, 12, 12, G_IM_FMT_RGBA, G_IM_SIZ_16b, &D_803A6510_879CC0, NULL, NULL, 0, 0
};

Bitmap* D_803A6564_879D14[33] = {
    D_80382CD0_856480,
    D_803A1128_8748D8,
    D_803A1138_8748E8,
    D_803A1148_8748F8,
    D_803A1158_874908,
    D_803A1168_874918,
    D_803A1178_874928,
    D_803A1188_874938,
    D_803A1198_874948,
    D_803A11A8_874958,
    D_803A11B8_874968,
    D_803A11C8_874978,
    D_803A11D8_874988,
    D_803A11E8_874998,
    D_803A11F8_8749A8,
    D_803A1208_8749B8,
    D_803A1218_8749C8,
    D_803A1228_8749D8,
    D_803A1238_8749E8,
    D_803A1248_8749F8,
    D_803A1258_874A08,
    D_803A1268_874A18,
    D_803A1278_874A28,
    D_803A1288_874A38,
    D_803A1298_874A48,
    D_803A12A8_874A58,
    D_803A12B8_874A68,
    D_803A12C8_874A78,
    D_803A12D8_874A88,
    D_803A12E8_874A98,
    D_803A12F8_874AA8,
    D_803A1308_874AB8,
    D_803A1318_874AC8
};

Sprite* D_803A65E8_879D98[7] = {
    &D_803A1360_874B10,
    &D_803A1B10_8752C0,
    &D_803A5320_878AD0,
    &D_803A54A0_878C50,
    &D_803A22C0_875A70,
    &D_803A5620_878DD0,
    &D_803A57A0_878F50
};

s32 UILayout_PanelState = 2;

s32 UILayout_IsAnimationHorizontal = 0;

s32 UILayout_IsInstantTransition = 0;

UIButton* UILayout_Buttons = NULL;

s32 UILayout_AnimationFrames = 3;

s32 UILayout_HeaderFlags = 0;

f32 UILayout_TitlePosY = -40.0f;

f32 UILayout_PrevPageIndicatorPosY = -40.0f;

s32 UILayout_PrevPageIndicatorCounter = 0;

f32 UILayout_NextPageIndicatorPosY = -40.0f;

s32 UILayout_NextPageIndicatorCounter = 0;

s32 UILayout_PanelVisibility = 0;

f32 UILayout_PanelPosX = -180.0f;

u8 D_803A6638_879DE8[8] = { 0 };
