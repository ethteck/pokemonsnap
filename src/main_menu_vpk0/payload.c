#include "common.h"
#include "sys/anim.h"
#include "main_menu_vpk0/animations.h"

/* Forward declarations preserve all original graph identities. */
extern Gfx D_802B5000_main_menu_vpk0[1];
extern u8 D_802B5008_main_menu_vpk0[4096];
extern Gfx D_802B6008_main_menu_vpk0[1];
extern u8 D_802B6010_main_menu_vpk0[4096];
extern Gfx D_802B7010_main_menu_vpk0[1];
extern u8 D_802B7018_main_menu_vpk0[4096];
extern Gfx D_802B8018_main_menu_vpk0[1];
extern u8 D_802B8020_main_menu_vpk0[4096];
extern Gfx D_802B9020_main_menu_vpk0[1];
extern u8 D_802B9028_main_menu_vpk0[4096];
extern Gfx D_802BA028_main_menu_vpk0[1];
extern u8 D_802BA030_main_menu_vpk0[4096];
extern Gfx D_802BB030_main_menu_vpk0[1];
extern u8 D_802BB038_main_menu_vpk0[4096];
extern Gfx D_802BC038_main_menu_vpk0[1];
extern u8 D_802BC040_main_menu_vpk0[4096];
extern Gfx D_802BD040_main_menu_vpk0[1];
extern u8 D_802BD048_main_menu_vpk0[4096];
extern Gfx D_802BE048_main_menu_vpk0[1];
extern u8 D_802BE050_main_menu_vpk0[4096];
extern Gfx D_802BF050_main_menu_vpk0[1];
extern u8 D_802BF058_main_menu_vpk0[4096];
extern Gfx D_802C0058_main_menu_vpk0[1];
extern u8 D_802C0060_main_menu_vpk0[4096];
extern Gfx D_802C1060_main_menu_vpk0[1];
extern u8 D_802C1068_main_menu_vpk0[4096];
extern Gfx D_802C2068_main_menu_vpk0[1];
extern u8 D_802C2070_main_menu_vpk0[4096];
extern Gfx D_802C3070_main_menu_vpk0[1];
extern u8 D_802C3078_main_menu_vpk0[4096];
extern Gfx D_802C4078_main_menu_vpk0[1];
extern u8 D_802C4080_main_menu_vpk0[4096];
extern Gfx D_802C5080_main_menu_vpk0[1];
extern u8 D_802C5088_main_menu_vpk0[4096];
extern Gfx D_802C6088_main_menu_vpk0[1];
extern u8 D_802C6090_main_menu_vpk0[4096];
extern Gfx D_802C7090_main_menu_vpk0[1];
extern u8 D_802C7098_main_menu_vpk0[4096];
extern Gfx D_802C8098_main_menu_vpk0[1];
extern u8 D_802C80A0_main_menu_vpk0[4096];
extern Gfx D_802C90A0_main_menu_vpk0[1];
extern u8 D_802C90A8_main_menu_vpk0[4096];
extern Gfx D_802CA0A8_main_menu_vpk0[1];
extern u8 D_802CA0B0_main_menu_vpk0[4096];
extern Gfx D_802CB0B0_main_menu_vpk0[1];
extern u8 D_802CB0B8_main_menu_vpk0[4096];
extern Gfx D_802CC0B8_main_menu_vpk0[1];
extern u8 D_802CC0C0_main_menu_vpk0[4096];
extern Gfx D_802CD0C0_main_menu_vpk0[1];
extern u8 D_802CD0C8_main_menu_vpk0[4096];
extern Gfx D_802CE0C8_main_menu_vpk0[1];
extern u8 D_802CE0D0_main_menu_vpk0[4096];
extern Gfx D_802CF0D0_main_menu_vpk0[1];
extern u8 D_802CF0D8_main_menu_vpk0[4096];
extern Gfx D_802D00D8_main_menu_vpk0[1];
extern u8 D_802D00E0_main_menu_vpk0[4096];
extern Gfx D_802D10E0_main_menu_vpk0[1];
extern u8 D_802D10E8_main_menu_vpk0[4096];
extern Gfx D_802D20E8_main_menu_vpk0[1];
extern u8 D_802D20F0_main_menu_vpk0[4096];
extern Gfx D_802D30F0_main_menu_vpk0[1];
extern u8 D_802D30F8_main_menu_vpk0[3072];
extern Gfx D_802D3CF8_main_menu_vpk0[1];
extern u8 D_802D3D00_main_menu_vpk0[3072];
extern Gfx D_802D4900_main_menu_vpk0[1];
extern u8 D_802D4908_main_menu_vpk0[3072];
extern Gfx D_802D5508_main_menu_vpk0[1];
extern u8 D_802D5510_main_menu_vpk0[3072];
extern Gfx D_802D6110_main_menu_vpk0[1];
extern u8 D_802D6118_main_menu_vpk0[3072];
extern Gfx D_802D6D18_main_menu_vpk0[1];
extern u8 D_802D6D20_main_menu_vpk0[3072];
extern Gfx D_802D7920_main_menu_vpk0[1];
extern u8 D_802D7928_main_menu_vpk0[3072];
extern Gfx D_802D8528_main_menu_vpk0[1];
extern u8 D_802D8530_main_menu_vpk0[3072];
extern Gfx D_802D9130_main_menu_vpk0[1];
extern u8 D_802D9138_main_menu_vpk0[3072];
extern Gfx D_802D9D38_main_menu_vpk0[1];
extern u8 D_802D9D40_main_menu_vpk0[3072];
extern Bitmap D_802DA940_main_menu_vpk0[40];
extern Sprite D_802DABC0_main_menu_vpk0;
extern u8 D_802DAC04_main_menu_vpk0[12];
extern Gfx D_802DAC10_main_menu_vpk0[1];
extern u8 D_802DAC18_main_menu_vpk0[1792];
extern Bitmap D_802DB318_main_menu_vpk0[1];
extern Sprite D_802DB328_main_menu_vpk0;
extern u8 D_802DB36C_main_menu_vpk0[4];
extern Gfx D_802DB370_main_menu_vpk0[1];
extern u8 D_802DB378_main_menu_vpk0[512];
extern Bitmap D_802DB578_main_menu_vpk0[1];
extern Sprite D_802DB588_main_menu_vpk0;
extern u8 D_802DB5CC_main_menu_vpk0[4];
extern Gfx D_802DB5D0_main_menu_vpk0[1];
extern u8 D_802DB5D8_main_menu_vpk0[1792];
extern Bitmap D_802DBCD8_main_menu_vpk0[1];
extern Sprite D_802DBCE8_main_menu_vpk0;
extern u8 D_802DBD2C_main_menu_vpk0[4];
extern Gfx D_802DBD30_main_menu_vpk0[1];
extern u8 D_802DBD38_main_menu_vpk0[1120];
extern Bitmap D_802DC198_main_menu_vpk0[1];
extern Sprite D_802DC1A8_main_menu_vpk0;
extern u8 D_802DC1EC_main_menu_vpk0[4];
extern Gfx D_802DC1F0_main_menu_vpk0[1];
extern u8 D_802DC1F8_main_menu_vpk0[1296];
extern Bitmap D_802DC708_main_menu_vpk0[1];
extern Sprite D_802DC718_main_menu_vpk0;
extern u8 D_802DC75C_main_menu_vpk0[4];
extern Gfx D_802DC760_main_menu_vpk0[1];
extern u8 D_802DC768_main_menu_vpk0[512];
extern Bitmap D_802DC968_main_menu_vpk0[1];
extern Sprite D_802DC978_main_menu_vpk0;
extern u8 D_802DC9BC_main_menu_vpk0[4];
extern Gfx D_802DC9C0_main_menu_vpk0[1];
extern u8 D_802DC9C8_main_menu_vpk0[1200];
extern Bitmap D_802DCE78_main_menu_vpk0[1];
extern Sprite D_802DCE88_main_menu_vpk0;
extern u8 D_802DCECC_main_menu_vpk0[4];
extern Gfx D_802DCED0_main_menu_vpk0[1];
extern u8 D_802DCED8_main_menu_vpk0[4096];
extern Gfx D_802DDED8_main_menu_vpk0[1];
extern u8 D_802DDEE0_main_menu_vpk0[3328];
extern Gfx D_802DEBE0_main_menu_vpk0[1];
extern u8 D_802DEBE8_main_menu_vpk0[2048];
extern Gfx D_802DF3E8_main_menu_vpk0[1];
extern u8 D_802DF3F0_main_menu_vpk0[1664];
extern Bitmap D_802DFA70_main_menu_vpk0[4];
extern Sprite D_802DFAB0_main_menu_vpk0;
extern u8 D_802DFAF4_main_menu_vpk0[12];
extern Gfx D_802DFB00_main_menu_vpk0[1];
extern u8 D_802DFB08_main_menu_vpk0[4096];
extern Gfx D_802E0B08_main_menu_vpk0[1];
extern u8 D_802E0B10_main_menu_vpk0[4096];
extern Gfx D_802E1B10_main_menu_vpk0[1];
extern u8 D_802E1B18_main_menu_vpk0[4096];
extern Gfx D_802E2B18_main_menu_vpk0[1];
extern u8 D_802E2B20_main_menu_vpk0[3840];
extern Gfx D_802E3A20_main_menu_vpk0[1];
extern u8 D_802E3A28_main_menu_vpk0[4096];
extern Gfx D_802E4A28_main_menu_vpk0[1];
extern u8 D_802E4A30_main_menu_vpk0[4096];
extern Gfx D_802E5A30_main_menu_vpk0[1];
extern u8 D_802E5A38_main_menu_vpk0[4096];
extern Gfx D_802E6A38_main_menu_vpk0[1];
extern u8 D_802E6A40_main_menu_vpk0[3840];
extern Gfx D_802E7940_main_menu_vpk0[1];
extern u8 D_802E7948_main_menu_vpk0[1280];
extern Gfx D_802E7E48_main_menu_vpk0[1];
extern u8 D_802E7E50_main_menu_vpk0[1280];
extern Gfx D_802E8350_main_menu_vpk0[1];
extern u8 D_802E8358_main_menu_vpk0[1280];
extern Gfx D_802E8858_main_menu_vpk0[1];
extern u8 D_802E8860_main_menu_vpk0[1200];
extern Bitmap D_802E8D10_main_menu_vpk0[12];
extern Sprite D_802E8DD0_main_menu_vpk0;
extern u8 D_802E8E14_main_menu_vpk0[12];
extern Gfx D_802E8E20_main_menu_vpk0[1];
extern u8 D_802E8E28_main_menu_vpk0[4096];
extern Gfx D_802E9E28_main_menu_vpk0[1];
extern u8 D_802E9E30_main_menu_vpk0[4096];
extern Gfx D_802EAE30_main_menu_vpk0[1];
extern u8 D_802EAE38_main_menu_vpk0[4096];
extern Gfx D_802EBE38_main_menu_vpk0[1];
extern u8 D_802EBE40_main_menu_vpk0[3840];
extern Gfx D_802ECD40_main_menu_vpk0[1];
extern u8 D_802ECD48_main_menu_vpk0[4096];
extern Gfx D_802EDD48_main_menu_vpk0[1];
extern u8 D_802EDD50_main_menu_vpk0[4096];
extern Gfx D_802EED50_main_menu_vpk0[1];
extern u8 D_802EED58_main_menu_vpk0[4096];
extern Gfx D_802EFD58_main_menu_vpk0[1];
extern u8 D_802EFD60_main_menu_vpk0[3840];
extern Gfx D_802F0C60_main_menu_vpk0[1];
extern u8 D_802F0C68_main_menu_vpk0[1280];
extern Gfx D_802F1168_main_menu_vpk0[1];
extern u8 D_802F1170_main_menu_vpk0[1280];
extern Gfx D_802F1670_main_menu_vpk0[1];
extern u8 D_802F1678_main_menu_vpk0[1280];
extern Gfx D_802F1B78_main_menu_vpk0[1];
extern u8 D_802F1B80_main_menu_vpk0[1200];
extern Bitmap D_802F2030_main_menu_vpk0[12];
extern Sprite D_802F20F0_main_menu_vpk0;
extern u8 D_802F2134_main_menu_vpk0[20];
extern u8 D_802F2148_main_menu_vpk0[1536];
extern u8 D_802F2748_main_menu_vpk0[8];
extern u8 D_802F2750_main_menu_vpk0[1536];
extern u8 D_802F2D50_main_menu_vpk0[8];
extern u8 D_802F2D58_main_menu_vpk0[1536];
extern u8 D_802F3358_main_menu_vpk0[8];
extern u8 D_802F3360_main_menu_vpk0[1536];
extern u8 D_802F3960_main_menu_vpk0[8];
extern u8 D_802F3968_main_menu_vpk0[1536];
extern u8 D_802F3F68_main_menu_vpk0[8];
extern u8 D_802F3F70_main_menu_vpk0[1536];
extern u8 D_802F4570_main_menu_vpk0[8];
extern u8 D_802F4578_main_menu_vpk0[576];
extern Bitmap D_802F47B8_main_menu_vpk0[7];
extern Sprite D_802F4828_main_menu_vpk0;
extern u8 D_802F486C_main_menu_vpk0[12];
extern u8 D_802F4878_main_menu_vpk0[1280];
extern u8 D_802F4D78_main_menu_vpk0[8];
extern u8 D_802F4D80_main_menu_vpk0[1280];
extern u8 D_802F5280_main_menu_vpk0[8];
extern u8 D_802F5288_main_menu_vpk0[1280];
extern u8 D_802F5788_main_menu_vpk0[8];
extern u8 D_802F5790_main_menu_vpk0[960];
extern Bitmap D_802F5B50_main_menu_vpk0[4];
extern Sprite D_802F5B90_main_menu_vpk0;
extern u8 D_802F5BD4_main_menu_vpk0[20];
extern u8 D_802F5BE8_main_menu_vpk0[1088];
extern u8 D_802F6028_main_menu_vpk0[8];
extern u8 D_802F6030_main_menu_vpk0[1088];
extern Bitmap D_802F6470_main_menu_vpk0[2];
extern Sprite D_802F6490_main_menu_vpk0;
extern u8 D_802F64D4_main_menu_vpk0[12];
extern Gfx D_802F64E0_main_menu_vpk0[1];
extern u8 D_802F64E8_main_menu_vpk0[640];
extern Gfx D_802F6768_main_menu_vpk0[1];
extern u8 D_802F6770_main_menu_vpk0[640];
extern Gfx D_802F69F0_main_menu_vpk0[1];
extern u8 D_802F69F8_main_menu_vpk0[640];
extern Gfx D_802F6C78_main_menu_vpk0[1];
extern u8 D_802F6C80_main_menu_vpk0[640];
extern Gfx D_802F6F00_main_menu_vpk0[1];
extern u8 D_802F6F08_main_menu_vpk0[640];
extern Gfx D_802F7188_main_menu_vpk0[1];
extern u8 D_802F7190_main_menu_vpk0[240];
extern Gfx D_802F7280_main_menu_vpk0[1];
extern u8 D_802F7288_main_menu_vpk0[640];
extern Gfx D_802F7508_main_menu_vpk0[1];
extern u8 D_802F7510_main_menu_vpk0[640];
extern Gfx D_802F7790_main_menu_vpk0[1];
extern u8 D_802F7798_main_menu_vpk0[640];
extern Gfx D_802F7A18_main_menu_vpk0[1];
extern u8 D_802F7A20_main_menu_vpk0[640];
extern Gfx D_802F7CA0_main_menu_vpk0[1];
extern u8 D_802F7CA8_main_menu_vpk0[640];
extern Gfx D_802F7F28_main_menu_vpk0[1];
extern u8 D_802F7F30_main_menu_vpk0[240];
extern Gfx D_802F8020_main_menu_vpk0[1];
extern u8 D_802F8028_main_menu_vpk0[64];
extern Gfx D_802F8068_main_menu_vpk0[1];
extern u8 D_802F8070_main_menu_vpk0[64];
extern Gfx D_802F80B0_main_menu_vpk0[1];
extern u8 D_802F80B8_main_menu_vpk0[64];
extern Gfx D_802F80F8_main_menu_vpk0[1];
extern u8 D_802F8100_main_menu_vpk0[64];
extern Gfx D_802F8140_main_menu_vpk0[1];
extern u8 D_802F8148_main_menu_vpk0[64];
extern Gfx D_802F8188_main_menu_vpk0[1];
extern u8 D_802F8190_main_menu_vpk0[24];
extern Bitmap D_802F81A8_main_menu_vpk0[18];
extern Sprite D_802F82C8_main_menu_vpk0;
extern u8 D_802F830C_main_menu_vpk0[4];
extern Gfx D_802F8310_main_menu_vpk0[1];
extern u8 D_802F8318_main_menu_vpk0[4096];
extern Gfx D_802F9318_main_menu_vpk0[1];
extern u8 D_802F9320_main_menu_vpk0[4096];
extern Gfx D_802FA320_main_menu_vpk0[1];
extern u8 D_802FA328_main_menu_vpk0[4096];
extern Gfx D_802FB328_main_menu_vpk0[1];
extern u8 D_802FB330_main_menu_vpk0[3584];
extern Gfx D_802FC130_main_menu_vpk0[1];
extern u8 D_802FC138_main_menu_vpk0[4096];
extern Gfx D_802FD138_main_menu_vpk0[1];
extern u8 D_802FD140_main_menu_vpk0[4096];
extern Gfx D_802FE140_main_menu_vpk0[1];
extern u8 D_802FE148_main_menu_vpk0[4096];
extern Gfx D_802FF148_main_menu_vpk0[1];
extern u8 D_802FF150_main_menu_vpk0[3584];
extern Gfx D_802FFF50_main_menu_vpk0[1];
extern u8 D_802FFF58_main_menu_vpk0[4096];
extern Gfx D_80300F58_main_menu_vpk0[1];
extern u8 D_80300F60_main_menu_vpk0[4096];
extern Gfx D_80301F60_main_menu_vpk0[1];
extern u8 D_80301F68_main_menu_vpk0[4096];
extern Gfx D_80302F68_main_menu_vpk0[1];
extern u8 D_80302F70_main_menu_vpk0[3584];
extern Gfx D_80303D70_main_menu_vpk0[1];
extern u8 D_80303D78_main_menu_vpk0[1280];
extern Gfx D_80304278_main_menu_vpk0[1];
extern u8 D_80304280_main_menu_vpk0[1280];
extern Gfx D_80304780_main_menu_vpk0[1];
extern u8 D_80304788_main_menu_vpk0[1280];
extern Gfx D_80304C88_main_menu_vpk0[1];
extern u8 D_80304C90_main_menu_vpk0[1120];
extern Bitmap D_803050F0_main_menu_vpk0[16];
extern Sprite D_803051F0_main_menu_vpk0;
extern u8 D_80305234_main_menu_vpk0[20];
extern u8 D_80305248_main_menu_vpk0[2048];
extern u8 D_80305A48_main_menu_vpk0[8];
extern u8 D_80305A50_main_menu_vpk0[2048];
extern u8 D_80306250_main_menu_vpk0[8];
extern u8 D_80306258_main_menu_vpk0[2048];
extern u8 D_80306A58_main_menu_vpk0[8];
extern u8 D_80306A60_main_menu_vpk0[2048];
extern Bitmap D_80307260_main_menu_vpk0[4];
extern Sprite D_803072A0_main_menu_vpk0;
extern u8 D_803072E4_main_menu_vpk0[20];
extern u8 D_803072F8_main_menu_vpk0[1024];
extern u8 D_803076F8_main_menu_vpk0[8];
extern u8 D_80307700_main_menu_vpk0[1024];
extern u8 D_80307B00_main_menu_vpk0[8];
extern u8 D_80307B08_main_menu_vpk0[1024];
extern u8 D_80307F08_main_menu_vpk0[8];
extern u8 D_80307F10_main_menu_vpk0[1024];
extern u8 D_80308310_main_menu_vpk0[8];
extern u8 D_80308318_main_menu_vpk0[1024];
extern u8 D_80308718_main_menu_vpk0[8];
extern u8 D_80308720_main_menu_vpk0[640];
extern Bitmap D_803089A0_main_menu_vpk0[6];
extern Sprite D_80308A00_main_menu_vpk0;
extern u8 D_80308A44_main_menu_vpk0[12];
extern Gfx D_80308A50_main_menu_vpk0[1];
extern u8 D_80308A58_main_menu_vpk0[2048];
extern Gfx D_80309258_main_menu_vpk0[1];
extern u8 D_80309260_main_menu_vpk0[1024];
extern Gfx D_80309660_main_menu_vpk0[1];
extern u8 D_80309668_main_menu_vpk0[128];
extern Gfx D_803096E8_main_menu_vpk0[1];
extern u8 D_803096F0_main_menu_vpk0[64];
extern Bitmap D_80309730_main_menu_vpk0[4];
extern Sprite D_80309770_main_menu_vpk0;
extern u8 D_803097B4_main_menu_vpk0[12];
extern Gfx D_803097C0_main_menu_vpk0[1];
extern u8 D_803097C8_main_menu_vpk0[2048];
extern Gfx D_80309FC8_main_menu_vpk0[1];
extern u8 D_80309FD0_main_menu_vpk0[1024];
extern Gfx D_8030A3D0_main_menu_vpk0[1];
extern u8 D_8030A3D8_main_menu_vpk0[128];
extern Gfx D_8030A458_main_menu_vpk0[1];
extern u8 D_8030A460_main_menu_vpk0[64];
extern Bitmap D_8030A4A0_main_menu_vpk0[4];
extern Sprite D_8030A4E0_main_menu_vpk0;
extern u8 D_8030A524_main_menu_vpk0[12];
extern Gfx D_8030A530_main_menu_vpk0[1];
extern u8 D_8030A538_main_menu_vpk0[2048];
extern Gfx D_8030AD38_main_menu_vpk0[1];
extern u8 D_8030AD40_main_menu_vpk0[1024];
extern Gfx D_8030B140_main_menu_vpk0[1];
extern u8 D_8030B148_main_menu_vpk0[128];
extern Gfx D_8030B1C8_main_menu_vpk0[1];
extern u8 D_8030B1D0_main_menu_vpk0[64];
extern Bitmap D_8030B210_main_menu_vpk0[4];
extern Sprite D_8030B250_main_menu_vpk0;
extern u8 D_8030B294_main_menu_vpk0[12];
extern Gfx D_8030B2A0_main_menu_vpk0[1];
extern u8 D_8030B2A8_main_menu_vpk0[2048];
extern Gfx D_8030BAA8_main_menu_vpk0[1];
extern u8 D_8030BAB0_main_menu_vpk0[1024];
extern Gfx D_8030BEB0_main_menu_vpk0[1];
extern u8 D_8030BEB8_main_menu_vpk0[128];
extern Gfx D_8030BF38_main_menu_vpk0[1];
extern u8 D_8030BF40_main_menu_vpk0[64];
extern Bitmap D_8030BF80_main_menu_vpk0[4];
extern Sprite D_8030BFC0_main_menu_vpk0;
extern u8 D_8030C004_main_menu_vpk0[12];
extern Gfx D_8030C010_main_menu_vpk0[1];
extern u8 D_8030C018_main_menu_vpk0[4352];
extern Gfx D_8030D118_main_menu_vpk0[1];
extern u8 D_8030D120_main_menu_vpk0[3808];
extern Bitmap D_8030E000_main_menu_vpk0[2];
extern Sprite D_8030E020_main_menu_vpk0;
extern u8 D_8030E064_main_menu_vpk0[12];
extern Gfx D_8030E070_main_menu_vpk0[1];
extern u8 D_8030E078_main_menu_vpk0[4352];
extern Gfx D_8030F178_main_menu_vpk0[1];
extern u8 D_8030F180_main_menu_vpk0[3808];
extern Bitmap D_80310060_main_menu_vpk0[2];
extern Sprite D_80310080_main_menu_vpk0;
extern u8 D_803100C4_main_menu_vpk0[12];
extern Gfx D_803100D0_main_menu_vpk0[1];
extern u8 D_803100D8_main_menu_vpk0[4352];
extern Gfx D_803111D8_main_menu_vpk0[1];
extern u8 D_803111E0_main_menu_vpk0[3808];
extern Bitmap D_803120C0_main_menu_vpk0[2];
extern Sprite D_803120E0_main_menu_vpk0;
extern u8 D_80312124_main_menu_vpk0[20];
extern u8 D_80312138_main_menu_vpk0[240];
extern Bitmap D_80312228_main_menu_vpk0[1];
extern Sprite D_80312238_main_menu_vpk0;
extern u8 D_8031227C_main_menu_vpk0[12];
extern u8 D_80312288_main_menu_vpk0[192];
extern u8 D_80312348_main_menu_vpk0[8];
extern u8 D_80312350_main_menu_vpk0[192];
extern u8 D_80312410_main_menu_vpk0[8];
extern u8 D_80312418_main_menu_vpk0[192];
extern u8 D_803124D8_main_menu_vpk0[8];
extern u8 D_803124E0_main_menu_vpk0[192];
extern u8 D_803125A0_main_menu_vpk0[8];
extern u8 D_803125A8_main_menu_vpk0[192];
extern u8 D_80312668_main_menu_vpk0[8];
extern u8 D_80312670_main_menu_vpk0[192];
extern u8 D_80312730_main_menu_vpk0[8];
extern u8 D_80312738_main_menu_vpk0[192];
extern u8 D_803127F8_main_menu_vpk0[8];
extern u8 D_80312800_main_menu_vpk0[96];
extern Bitmap D_80312860_main_menu_vpk0[8];
extern Sprite D_803128E0_main_menu_vpk0;
extern u8 D_80312924_main_menu_vpk0[20];
extern u8 D_80312938_main_menu_vpk0[1920];
extern u8 D_803130B8_main_menu_vpk0[8];
extern u8 D_803130C0_main_menu_vpk0[1920];
extern u8 D_80313840_main_menu_vpk0[8];
extern u8 D_80313848_main_menu_vpk0[1920];
extern u8 D_80313FC8_main_menu_vpk0[8];
extern u8 D_80313FD0_main_menu_vpk0[1920];
extern u8 D_80314750_main_menu_vpk0[8];
extern u8 D_80314758_main_menu_vpk0[1920];
extern u8 D_80314ED8_main_menu_vpk0[8];
extern u8 D_80314EE0_main_menu_vpk0[1920];
extern u8 D_80315660_main_menu_vpk0[8];
extern u8 D_80315668_main_menu_vpk0[1920];
extern u8 D_80315DE8_main_menu_vpk0[8];
extern u8 D_80315DF0_main_menu_vpk0[960];
extern Bitmap D_803161B0_main_menu_vpk0[8];
extern Sprite D_80316230_main_menu_vpk0;
extern u8 D_80316274_main_menu_vpk0[20];
extern u8 D_80316288_main_menu_vpk0[1920];
extern u8 D_80316A08_main_menu_vpk0[8];
extern u8 D_80316A10_main_menu_vpk0[1920];
extern u8 D_80317190_main_menu_vpk0[8];
extern u8 D_80317198_main_menu_vpk0[1920];
extern u8 D_80317918_main_menu_vpk0[8];
extern u8 D_80317920_main_menu_vpk0[1920];
extern u8 D_803180A0_main_menu_vpk0[8];
extern u8 D_803180A8_main_menu_vpk0[1920];
extern u8 D_80318828_main_menu_vpk0[8];
extern u8 D_80318830_main_menu_vpk0[1920];
extern u8 D_80318FB0_main_menu_vpk0[8];
extern u8 D_80318FB8_main_menu_vpk0[1920];
extern u8 D_80319738_main_menu_vpk0[8];
extern u8 D_80319740_main_menu_vpk0[960];
extern Bitmap D_80319B00_main_menu_vpk0[8];
extern Sprite D_80319B80_main_menu_vpk0;
extern u8 D_80319BC4_main_menu_vpk0[20];
extern u8 D_80319BD8_main_menu_vpk0[1920];
extern u8 D_8031A358_main_menu_vpk0[8];
extern u8 D_8031A360_main_menu_vpk0[1920];
extern u8 D_8031AAE0_main_menu_vpk0[8];
extern u8 D_8031AAE8_main_menu_vpk0[1920];
extern u8 D_8031B268_main_menu_vpk0[8];
extern u8 D_8031B270_main_menu_vpk0[1920];
extern u8 D_8031B9F0_main_menu_vpk0[8];
extern u8 D_8031B9F8_main_menu_vpk0[1920];
extern u8 D_8031C178_main_menu_vpk0[8];
extern u8 D_8031C180_main_menu_vpk0[1920];
extern u8 D_8031C900_main_menu_vpk0[8];
extern u8 D_8031C908_main_menu_vpk0[1920];
extern u8 D_8031D088_main_menu_vpk0[8];
extern u8 D_8031D090_main_menu_vpk0[960];
extern Bitmap D_8031D450_main_menu_vpk0[8];
extern Sprite D_8031D4D0_main_menu_vpk0;
extern u8 D_8031D514_main_menu_vpk0[20];
extern u8 D_8031D528_main_menu_vpk0[1920];
extern u8 D_8031DCA8_main_menu_vpk0[8];
extern u8 D_8031DCB0_main_menu_vpk0[1920];
extern u8 D_8031E430_main_menu_vpk0[8];
extern u8 D_8031E438_main_menu_vpk0[1920];
extern u8 D_8031EBB8_main_menu_vpk0[8];
extern u8 D_8031EBC0_main_menu_vpk0[1920];
extern u8 D_8031F340_main_menu_vpk0[8];
extern u8 D_8031F348_main_menu_vpk0[1920];
extern u8 D_8031FAC8_main_menu_vpk0[8];
extern u8 D_8031FAD0_main_menu_vpk0[1920];
extern u8 D_80320250_main_menu_vpk0[8];
extern u8 D_80320258_main_menu_vpk0[1920];
extern u8 D_803209D8_main_menu_vpk0[8];
extern u8 D_803209E0_main_menu_vpk0[960];
extern Bitmap D_80320DA0_main_menu_vpk0[8];
extern Sprite D_80320E20_main_menu_vpk0;
extern u8 D_80320E64_main_menu_vpk0[20];
extern u8 D_80320E78_main_menu_vpk0[1920];
extern u8 D_803215F8_main_menu_vpk0[8];
extern u8 D_80321600_main_menu_vpk0[1920];
extern u8 D_80321D80_main_menu_vpk0[8];
extern u8 D_80321D88_main_menu_vpk0[1920];
extern u8 D_80322508_main_menu_vpk0[8];
extern u8 D_80322510_main_menu_vpk0[1920];
extern u8 D_80322C90_main_menu_vpk0[8];
extern u8 D_80322C98_main_menu_vpk0[1920];
extern u8 D_80323418_main_menu_vpk0[8];
extern u8 D_80323420_main_menu_vpk0[1920];
extern u8 D_80323BA0_main_menu_vpk0[8];
extern u8 D_80323BA8_main_menu_vpk0[1920];
extern u8 D_80324328_main_menu_vpk0[8];
extern u8 D_80324330_main_menu_vpk0[960];
extern Bitmap D_803246F0_main_menu_vpk0[8];
extern Sprite D_80324770_main_menu_vpk0;
extern u8 D_803247B4_main_menu_vpk0[20];
extern u8 D_803247C8_main_menu_vpk0[1920];
extern u8 D_80324F48_main_menu_vpk0[8];
extern u8 D_80324F50_main_menu_vpk0[1920];
extern u8 D_803256D0_main_menu_vpk0[8];
extern u8 D_803256D8_main_menu_vpk0[1920];
extern u8 D_80325E58_main_menu_vpk0[8];
extern u8 D_80325E60_main_menu_vpk0[1920];
extern u8 D_803265E0_main_menu_vpk0[8];
extern u8 D_803265E8_main_menu_vpk0[1920];
extern u8 D_80326D68_main_menu_vpk0[8];
extern u8 D_80326D70_main_menu_vpk0[1920];
extern u8 D_803274F0_main_menu_vpk0[8];
extern u8 D_803274F8_main_menu_vpk0[1920];
extern u8 D_80327C78_main_menu_vpk0[8];
extern u8 D_80327C80_main_menu_vpk0[960];
extern Bitmap D_80328040_main_menu_vpk0[8];
extern Sprite D_803280C0_main_menu_vpk0;
extern u8 D_80328104_main_menu_vpk0[20];
extern u8 D_80328118_main_menu_vpk0[1920];
extern u8 D_80328898_main_menu_vpk0[8];
extern u8 D_803288A0_main_menu_vpk0[1920];
extern u8 D_80329020_main_menu_vpk0[8];
extern u8 D_80329028_main_menu_vpk0[1920];
extern u8 D_803297A8_main_menu_vpk0[8];
extern u8 D_803297B0_main_menu_vpk0[1920];
extern u8 D_80329F30_main_menu_vpk0[8];
extern u8 D_80329F38_main_menu_vpk0[1920];
extern u8 D_8032A6B8_main_menu_vpk0[8];
extern u8 D_8032A6C0_main_menu_vpk0[1920];
extern u8 D_8032AE40_main_menu_vpk0[8];
extern u8 D_8032AE48_main_menu_vpk0[1920];
extern u8 D_8032B5C8_main_menu_vpk0[8];
extern u8 D_8032B5D0_main_menu_vpk0[960];
extern Bitmap D_8032B990_main_menu_vpk0[8];
extern Sprite D_8032BA10_main_menu_vpk0;
extern u8 D_8032BA54_main_menu_vpk0[20];
extern u8 D_8032BA68_main_menu_vpk0[1920];
extern u8 D_8032C1E8_main_menu_vpk0[8];
extern u8 D_8032C1F0_main_menu_vpk0[1920];
extern u8 D_8032C970_main_menu_vpk0[8];
extern u8 D_8032C978_main_menu_vpk0[1920];
extern u8 D_8032D0F8_main_menu_vpk0[8];
extern u8 D_8032D100_main_menu_vpk0[1920];
extern u8 D_8032D880_main_menu_vpk0[8];
extern u8 D_8032D888_main_menu_vpk0[1920];
extern u8 D_8032E008_main_menu_vpk0[8];
extern u8 D_8032E010_main_menu_vpk0[1920];
extern u8 D_8032E790_main_menu_vpk0[8];
extern u8 D_8032E798_main_menu_vpk0[1920];
extern u8 D_8032EF18_main_menu_vpk0[8];
extern u8 D_8032EF20_main_menu_vpk0[960];
extern Bitmap D_8032F2E0_main_menu_vpk0[8];
extern Sprite D_8032F360_main_menu_vpk0;
extern u8 D_8032F3A4_main_menu_vpk0[20];
extern u8 D_8032F3B8_main_menu_vpk0[1920];
extern u8 D_8032FB38_main_menu_vpk0[8];
extern u8 D_8032FB40_main_menu_vpk0[1920];
extern u8 D_803302C0_main_menu_vpk0[8];
extern u8 D_803302C8_main_menu_vpk0[1920];
extern u8 D_80330A48_main_menu_vpk0[8];
extern u8 D_80330A50_main_menu_vpk0[1920];
extern u8 D_803311D0_main_menu_vpk0[8];
extern u8 D_803311D8_main_menu_vpk0[1920];
extern u8 D_80331958_main_menu_vpk0[8];
extern u8 D_80331960_main_menu_vpk0[1920];
extern u8 D_803320E0_main_menu_vpk0[8];
extern u8 D_803320E8_main_menu_vpk0[1920];
extern u8 D_80332868_main_menu_vpk0[8];
extern u8 D_80332870_main_menu_vpk0[960];
extern Bitmap D_80332C30_main_menu_vpk0[8];
extern Sprite D_80332CB0_main_menu_vpk0;
extern u8 D_80332CF4_main_menu_vpk0[20];
extern u8 D_80332D08_main_menu_vpk0[1920];
extern u8 D_80333488_main_menu_vpk0[8];
extern u8 D_80333490_main_menu_vpk0[1920];
extern u8 D_80333C10_main_menu_vpk0[8];
extern u8 D_80333C18_main_menu_vpk0[1920];
extern u8 D_80334398_main_menu_vpk0[8];
extern u8 D_803343A0_main_menu_vpk0[1920];
extern u8 D_80334B20_main_menu_vpk0[8];
extern u8 D_80334B28_main_menu_vpk0[1920];
extern u8 D_803352A8_main_menu_vpk0[8];
extern u8 D_803352B0_main_menu_vpk0[1920];
extern u8 D_80335A30_main_menu_vpk0[8];
extern u8 D_80335A38_main_menu_vpk0[1920];
extern u8 D_803361B8_main_menu_vpk0[8];
extern u8 D_803361C0_main_menu_vpk0[960];
extern Bitmap D_80336580_main_menu_vpk0[8];
extern Sprite D_80336600_main_menu_vpk0;
extern u8 D_80336644_main_menu_vpk0[20];
extern u8 D_80336658_main_menu_vpk0[1920];
extern u8 D_80336DD8_main_menu_vpk0[8];
extern u8 D_80336DE0_main_menu_vpk0[1920];
extern u8 D_80337560_main_menu_vpk0[8];
extern u8 D_80337568_main_menu_vpk0[1920];
extern u8 D_80337CE8_main_menu_vpk0[8];
extern u8 D_80337CF0_main_menu_vpk0[1920];
extern u8 D_80338470_main_menu_vpk0[8];
extern u8 D_80338478_main_menu_vpk0[1920];
extern u8 D_80338BF8_main_menu_vpk0[8];
extern u8 D_80338C00_main_menu_vpk0[1920];
extern u8 D_80339380_main_menu_vpk0[8];
extern u8 D_80339388_main_menu_vpk0[1920];
extern u8 D_80339B08_main_menu_vpk0[8];
extern u8 D_80339B10_main_menu_vpk0[960];
extern Bitmap D_80339ED0_main_menu_vpk0[8];
extern Sprite D_80339F50_main_menu_vpk0;
extern u8 D_80339F94_main_menu_vpk0[20];
extern u8 D_80339FA8_main_menu_vpk0[1920];
extern u8 D_8033A728_main_menu_vpk0[8];
extern u8 D_8033A730_main_menu_vpk0[1920];
extern u8 D_8033AEB0_main_menu_vpk0[8];
extern u8 D_8033AEB8_main_menu_vpk0[1920];
extern u8 D_8033B638_main_menu_vpk0[8];
extern u8 D_8033B640_main_menu_vpk0[1920];
extern u8 D_8033BDC0_main_menu_vpk0[8];
extern u8 D_8033BDC8_main_menu_vpk0[1920];
extern u8 D_8033C548_main_menu_vpk0[8];
extern u8 D_8033C550_main_menu_vpk0[1920];
extern u8 D_8033CCD0_main_menu_vpk0[8];
extern u8 D_8033CCD8_main_menu_vpk0[1920];
extern u8 D_8033D458_main_menu_vpk0[8];
extern u8 D_8033D460_main_menu_vpk0[960];
extern Bitmap D_8033D820_main_menu_vpk0[8];
extern Sprite D_8033D8A0_main_menu_vpk0;
extern u8 D_8033D8E4_main_menu_vpk0[20];
extern u8 D_8033D8F8_main_menu_vpk0[640];
extern u8 D_8033DB78_main_menu_vpk0[8];
extern u8 D_8033DB80_main_menu_vpk0[640];
extern u8 D_8033DE00_main_menu_vpk0[8];
extern u8 D_8033DE08_main_menu_vpk0[640];
extern u8 D_8033E088_main_menu_vpk0[8];
extern u8 D_8033E090_main_menu_vpk0[320];
extern Bitmap D_8033E1D0_main_menu_vpk0[4];
extern Sprite D_8033E210_main_menu_vpk0;
extern u8 D_8033E254_main_menu_vpk0[20];
extern u8 D_8033E268_main_menu_vpk0[640];
extern u8 D_8033E4E8_main_menu_vpk0[8];
extern u8 D_8033E4F0_main_menu_vpk0[640];
extern u8 D_8033E770_main_menu_vpk0[8];
extern u8 D_8033E778_main_menu_vpk0[400];
extern Bitmap D_8033E908_main_menu_vpk0[3];
extern Sprite D_8033E938_main_menu_vpk0;
extern u8 D_8033E97C_main_menu_vpk0[12];
extern u8 D_8033E988_main_menu_vpk0[640];
extern u8 D_8033EC08_main_menu_vpk0[8];
extern u8 D_8033EC10_main_menu_vpk0[160];
extern Bitmap D_8033ECB0_main_menu_vpk0[2];
extern Sprite D_8033ECD0_main_menu_vpk0;
extern u8 D_8033ED14_main_menu_vpk0[20];
extern u8 D_8033ED28_main_menu_vpk0[56];
extern Bitmap D_8033ED60_main_menu_vpk0[1];
extern Sprite D_8033ED70_main_menu_vpk0;
extern u8 D_8033EDB4_main_menu_vpk0[20];
extern u8 D_8033EDC8_main_menu_vpk0[640];
extern u8 D_8033F048_main_menu_vpk0[8];
extern u8 D_8033F050_main_menu_vpk0[640];
extern u8 D_8033F2D0_main_menu_vpk0[8];
extern u8 D_8033F2D8_main_menu_vpk0[400];
extern Bitmap D_8033F468_main_menu_vpk0[3];
extern Sprite D_8033F498_main_menu_vpk0;
extern u8 D_8033F4DC_main_menu_vpk0[12];
extern u8 D_8033F4E8_main_menu_vpk0[640];
extern u8 D_8033F768_main_menu_vpk0[8];
extern u8 D_8033F770_main_menu_vpk0[640];
extern u8 D_8033F9F0_main_menu_vpk0[8];
extern u8 D_8033F9F8_main_menu_vpk0[400];
extern Bitmap D_8033FB88_main_menu_vpk0[3];
extern Sprite D_8033FBB8_main_menu_vpk0;
extern u8 D_8033FBFC_main_menu_vpk0[4];
extern Gfx D_8033FC00_main_menu_vpk0[1];
extern u8 D_8033FC08_main_menu_vpk0[1280];
extern Gfx D_80340108_main_menu_vpk0[1];
extern u8 D_80340110_main_menu_vpk0[1280];
extern Gfx D_80340610_main_menu_vpk0[1];
extern u8 D_80340618_main_menu_vpk0[1280];
extern Gfx D_80340B18_main_menu_vpk0[1];
extern u8 D_80340B20_main_menu_vpk0[960];
extern Gfx D_80340EE0_main_menu_vpk0[1];
extern u8 D_80340EE8_main_menu_vpk0[128];
extern Gfx D_80340F68_main_menu_vpk0[1];
extern u8 D_80340F70_main_menu_vpk0[128];
extern Gfx D_80340FF0_main_menu_vpk0[1];
extern u8 D_80340FF8_main_menu_vpk0[128];
extern Gfx D_80341078_main_menu_vpk0[1];
extern u8 D_80341080_main_menu_vpk0[96];
extern Bitmap D_803410E0_main_menu_vpk0[8];
extern Sprite D_80341160_main_menu_vpk0;
extern u8 D_803411A4_main_menu_vpk0[20];
extern u8 D_803411B8_main_menu_vpk0[832];
extern u8 D_803414F8_main_menu_vpk0[8];
extern u8 D_80341500_main_menu_vpk0[624];
extern Bitmap D_80341770_main_menu_vpk0[2];
extern Sprite D_80341790_main_menu_vpk0;
extern u8 D_803417D4_main_menu_vpk0[20];
extern u8 D_803417E8_main_menu_vpk0[640];
extern u8 D_80341A68_main_menu_vpk0[8];
extern u8 D_80341A70_main_menu_vpk0[480];
extern Bitmap D_80341C50_main_menu_vpk0[2];
extern Sprite D_80341C70_main_menu_vpk0;
extern u8 D_80341CB4_main_menu_vpk0[20];
extern u8 D_80341CC8_main_menu_vpk0[640];
extern u8 D_80341F48_main_menu_vpk0[8];
extern u8 D_80341F50_main_menu_vpk0[480];
extern Bitmap D_80342130_main_menu_vpk0[2];
extern Sprite D_80342150_main_menu_vpk0;
extern u8 D_80342194_main_menu_vpk0[20];
extern u8 D_803421A8_main_menu_vpk0[640];
extern u8 D_80342428_main_menu_vpk0[8];
extern u8 D_80342430_main_menu_vpk0[480];
extern Bitmap D_80342610_main_menu_vpk0[2];
extern Sprite D_80342630_main_menu_vpk0;
extern u8 D_80342674_main_menu_vpk0[20];
extern u8 D_80342688_main_menu_vpk0[640];
extern u8 D_80342908_main_menu_vpk0[8];
extern u8 D_80342910_main_menu_vpk0[480];
extern Bitmap D_80342AF0_main_menu_vpk0[2];
extern Sprite D_80342B10_main_menu_vpk0;
extern u8 D_80342B54_main_menu_vpk0[20];
extern u8 D_80342B68_main_menu_vpk0[640];
extern u8 D_80342DE8_main_menu_vpk0[8];
extern u8 D_80342DF0_main_menu_vpk0[480];
extern Bitmap D_80342FD0_main_menu_vpk0[2];
extern Sprite D_80342FF0_main_menu_vpk0;
extern u8 D_80343034_main_menu_vpk0[20];
extern u8 D_80343048_main_menu_vpk0[640];
extern u8 D_803432C8_main_menu_vpk0[8];
extern u8 D_803432D0_main_menu_vpk0[480];
extern Bitmap D_803434B0_main_menu_vpk0[2];
extern Sprite D_803434D0_main_menu_vpk0;
extern u8 D_80343514_main_menu_vpk0[12];
extern Gfx D_80343520_main_menu_vpk0[1];
extern u8 D_80343528_main_menu_vpk0[1520];
extern Bitmap D_80343B18_main_menu_vpk0[1];
extern Sprite D_80343B28_main_menu_vpk0;
extern u8 D_80343B6C_main_menu_vpk0[4];
extern Gfx D_80343B70_main_menu_vpk0[1];
extern u8 D_80343B78_main_menu_vpk0[128];
extern Bitmap D_80343BF8_main_menu_vpk0[1];
extern Sprite D_80343C08_main_menu_vpk0;
extern u8 D_80343C4C_main_menu_vpk0[4];
extern Gfx D_80343C50_main_menu_vpk0[1];
extern u8 D_80343C58_main_menu_vpk0[192];
extern Gfx D_80343D18_main_menu_vpk0[1];
extern u8 D_80343D20_main_menu_vpk0[192];
extern Gfx D_80343DE0_main_menu_vpk0[1];
extern u8 D_80343DE8_main_menu_vpk0[192];
extern Gfx D_80343EA8_main_menu_vpk0[1];
extern u8 D_80343EB0_main_menu_vpk0[192];
extern Gfx D_80343F70_main_menu_vpk0[1];
extern u8 D_80343F78_main_menu_vpk0[192];
extern Gfx D_80344038_main_menu_vpk0[1];
extern u8 D_80344040_main_menu_vpk0[192];
extern Gfx D_80344100_main_menu_vpk0[1];
extern u8 D_80344108_main_menu_vpk0[192];
extern Gfx D_803441C8_main_menu_vpk0[1];
extern u8 D_803441D0_main_menu_vpk0[192];
extern Gfx D_80344290_main_menu_vpk0[1];
extern u8 D_80344298_main_menu_vpk0[96];
extern Bitmap D_803442F8_main_menu_vpk0[9];
extern Sprite D_80344388_main_menu_vpk0;
extern u8 D_803443CC_main_menu_vpk0[4];
extern Gfx D_803443D0_main_menu_vpk0[1];
extern u8 D_803443D8_main_menu_vpk0[240];
extern Bitmap D_803444C8_main_menu_vpk0[1];
extern Sprite D_803444D8_main_menu_vpk0;
extern u8 D_8034451C_main_menu_vpk0[4];
extern Gfx D_80344520_main_menu_vpk0[1];
extern u8 D_80344528_main_menu_vpk0[224];
extern Bitmap D_80344608_main_menu_vpk0[1];
extern Sprite D_80344618_main_menu_vpk0;
extern u8 D_8034465C_main_menu_vpk0[4];
extern Gfx D_80344660_main_menu_vpk0[1];
extern u8 D_80344668_main_menu_vpk0[3584];
extern Gfx D_80345468_main_menu_vpk0[1];
extern u8 D_80345470_main_menu_vpk0[3584];
extern Gfx D_80346270_main_menu_vpk0[1];
extern u8 D_80346278_main_menu_vpk0[3584];
extern Gfx D_80347078_main_menu_vpk0[1];
extern u8 D_80347080_main_menu_vpk0[3584];
extern Gfx D_80347E80_main_menu_vpk0[1];
extern u8 D_80347E88_main_menu_vpk0[3584];
extern Gfx D_80348C88_main_menu_vpk0[1];
extern u8 D_80348C90_main_menu_vpk0[3584];
extern Gfx D_80349A90_main_menu_vpk0[1];
extern u8 D_80349A98_main_menu_vpk0[3584];
extern Gfx D_8034A898_main_menu_vpk0[1];
extern u8 D_8034A8A0_main_menu_vpk0[1792];
extern Bitmap D_8034AFA0_main_menu_vpk0[8];
extern Sprite D_8034B020_main_menu_vpk0;
extern u8 D_8034B064_main_menu_vpk0[20];
extern u8 D_8034B078_main_menu_vpk0[1088];
extern u8 D_8034B4B8_main_menu_vpk0[8];
extern u8 D_8034B4C0_main_menu_vpk0[1088];
extern Bitmap D_8034B900_main_menu_vpk0[2];
extern Sprite D_8034B920_main_menu_vpk0;
extern u8 D_8034B964_main_menu_vpk0[20];
extern u8 D_8034B978_main_menu_vpk0[560];
extern Bitmap D_8034BBA8_main_menu_vpk0[1];
extern Sprite D_8034BBB8_main_menu_vpk0;
extern u8 D_8034BBFC_main_menu_vpk0[12];
extern u8 D_8034BC08_main_menu_vpk0[1088];
extern u8 D_8034C048_main_menu_vpk0[8];
extern u8 D_8034C050_main_menu_vpk0[1088];
extern Bitmap D_8034C490_main_menu_vpk0[2];
extern Sprite D_8034C4B0_main_menu_vpk0;
extern u8 D_8034C4F4_main_menu_vpk0[20];
extern u8 D_8034C508_main_menu_vpk0[504];
extern Bitmap D_8034C700_main_menu_vpk0[1];
extern Sprite D_8034C710_main_menu_vpk0;
extern u8 D_8034C754_main_menu_vpk0[20];
extern u8 D_8034C768_main_menu_vpk0[576];
extern u8 D_8034C9A8_main_menu_vpk0[8];
extern u8 D_8034C9B0_main_menu_vpk0[576];
extern u8 D_8034CBF0_main_menu_vpk0[8];
extern u8 D_8034CBF8_main_menu_vpk0[432];
extern u8 D_8034CDA8_main_menu_vpk0[8];
extern u8 D_8034CDB0_main_menu_vpk0[512];
extern u8 D_8034CFB0_main_menu_vpk0[8];
extern u8 D_8034CFB8_main_menu_vpk0[512];
extern u8 D_8034D1B8_main_menu_vpk0[8];
extern u8 D_8034D1C0_main_menu_vpk0[384];
extern Bitmap D_8034D340_main_menu_vpk0[6];
extern Sprite D_8034D3A0_main_menu_vpk0;
extern u8 D_8034D3E4_main_menu_vpk0[20];
extern u8 D_8034D3F8_main_menu_vpk0[1536];
extern u8 D_8034D9F8_main_menu_vpk0[8];
extern u8 D_8034DA00_main_menu_vpk0[1536];
extern u8 D_8034E000_main_menu_vpk0[8];
extern u8 D_8034E008_main_menu_vpk0[1536];
extern u8 D_8034E608_main_menu_vpk0[8];
extern u8 D_8034E610_main_menu_vpk0[1536];
extern u8 D_8034EC10_main_menu_vpk0[8];
extern u8 D_8034EC18_main_menu_vpk0[1536];
extern u8 D_8034F218_main_menu_vpk0[8];
extern u8 D_8034F220_main_menu_vpk0[1536];
extern u8 D_8034F820_main_menu_vpk0[8];
extern u8 D_8034F828_main_menu_vpk0[576];
extern Bitmap D_8034FA68_main_menu_vpk0[7];
extern Sprite D_8034FAD8_main_menu_vpk0;
extern u8 D_8034FB1C_main_menu_vpk0[4];
extern u8 D_8034FB20_main_menu_vpk0[8];
extern u8 D_8034FB28_main_menu_vpk0[2048];
extern u8 D_80350328_main_menu_vpk0[8];
extern u8 D_80350330_main_menu_vpk0[2048];
extern u8 D_80350B30_main_menu_vpk0[8];
extern u8 D_80350B38_main_menu_vpk0[2048];
extern u8 D_80351338_main_menu_vpk0[8];
extern u8 D_80351340_main_menu_vpk0[4096];
extern u8 D_80352340_main_menu_vpk0[8];
extern u8 D_80352348_main_menu_vpk0[4096];
extern u8 D_80353348_main_menu_vpk0[8];
extern u8 D_80353350_main_menu_vpk0[4096];
extern u8 D_80354350_main_menu_vpk0[8];
extern u8 D_80354358_main_menu_vpk0[4096];
extern u8 D_80355358_main_menu_vpk0[8];
extern u8 D_80355360_main_menu_vpk0[4096];
extern u8 D_80356360_main_menu_vpk0[8];
extern u8 D_80356368_main_menu_vpk0[4096];
extern u8 D_80357368_main_menu_vpk0[8];
extern u8 D_80357370_main_menu_vpk0[4096];
extern u8 D_80358370_main_menu_vpk0[8];
extern u8 D_80358378_main_menu_vpk0[4096];
extern Texture** D_80359378_main_menu_vpk0[5];
extern u8* D_8035938C_main_menu_vpk0[5];
extern Texture D_803593A0_main_menu_vpk0;
extern u8* D_80359418_main_menu_vpk0[6];
extern Texture D_80359430_main_menu_vpk0;
extern u8* D_803594A8_main_menu_vpk0[2];
extern Texture D_803594B0_main_menu_vpk0;
extern Texture* D_80359528_main_menu_vpk0[2];
extern Texture* D_80359530_main_menu_vpk0[2];
extern Texture* D_80359538_main_menu_vpk0[2];
extern Vtx D_80359540_main_menu_vpk0[36];
extern Gfx D_80359780_main_menu_vpk0[28];
extern Gfx D_80359860_main_menu_vpk0[25];
extern Gfx D_80359928_main_menu_vpk0[25];
extern DObjPayloadTypeC D_803599F0_main_menu_vpk0[2];
extern DObjPayloadTypeC D_80359A00_main_menu_vpk0[2];
extern DObjPayloadTypeC D_80359A10_main_menu_vpk0[2];
extern UnkEC64Arg3 D_80359A20_main_menu_vpk0[6];
extern u8 D_80359B28_main_menu_vpk0[8];
extern AnimCmd* D_80359B30_main_menu_vpk0[5];
extern struct MainMenuAnimation80359B44 D_80359B44_main_menu_vpk0;
extern struct MainMenuAnimation80359C60 D_80359C60_main_menu_vpk0;
extern struct MainMenuAnimation80359C70 D_80359C70_main_menu_vpk0;
extern struct MainMenuAnimation80359C80 D_80359C80_main_menu_vpk0;
extern struct MainMenuAnimation80359C90 D_80359C90_main_menu_vpk0;
extern u8 D_80359CC8_main_menu_vpk0[8];
extern AnimCmd** D_80359CD0_main_menu_vpk0[5];
extern struct MainMenuAnimation80359CE4 D_80359CE4_main_menu_vpk0;
extern struct MainMenuAnimation80359D80 D_80359D80_main_menu_vpk0;
extern struct MainMenuAnimation8035A128 D_8035A128_main_menu_vpk0;
extern AnimCmd* D_8035A290_main_menu_vpk0[1];
extern AnimCmd* D_8035A294_main_menu_vpk0[1];
extern AnimCmd* D_8035A298_main_menu_vpk0[1];
extern u8 D_8035A29C_main_menu_vpk0[12];
extern u8 D_8035A2A8_main_menu_vpk0[12288];
extern u8 D_8035D2A8_main_menu_vpk0[8];
extern u8 D_8035D2B0_main_menu_vpk0[62];
extern u8 D_8035D2F0_main_menu_vpk0[8];
extern u8 D_8035D2F8_main_menu_vpk0[4096];
extern u8 D_8035E2F8_main_menu_vpk0[8];
extern u8 D_8035E300_main_menu_vpk0[1024];
extern u8 D_8035E700_main_menu_vpk0[8];
extern u8 D_8035E708_main_menu_vpk0[30];
extern u8 D_8035E728_main_menu_vpk0[8];
extern u8 D_8035E730_main_menu_vpk0[4096];
extern u8 D_8035F730_main_menu_vpk0[8];
extern u8 D_8035F738_main_menu_vpk0[512];
extern u8 D_8035F938_main_menu_vpk0[8];
extern u8 D_8035F940_main_menu_vpk0[32];
extern u8 D_8035F960_main_menu_vpk0[8];
extern u8 D_8035F968_main_menu_vpk0[2048];
extern u8 D_80360168_main_menu_vpk0[8];
extern u8 D_80360170_main_menu_vpk0[30];
extern u8 D_80360190_main_menu_vpk0[8];
extern u8 D_80360198_main_menu_vpk0[2048];
extern u8 D_80360998_main_menu_vpk0[8];
extern u8 D_803609A0_main_menu_vpk0[1024];
extern u8 D_80360DA0_main_menu_vpk0[8];
extern u8 D_80360DA8_main_menu_vpk0[8192];
extern u8 D_80362DA8_main_menu_vpk0[8];
extern u8 D_80362DB0_main_menu_vpk0[2048];
extern u8 D_803635B0_main_menu_vpk0[8];
extern u8 D_803635B8_main_menu_vpk0[30];
extern u8 D_803635D8_main_menu_vpk0[8];
extern u8 D_803635E0_main_menu_vpk0[2048];
extern u8 D_80363DE0_main_menu_vpk0[8];
extern u8 D_80363DE8_main_menu_vpk0[30];
extern u8 D_80363E08_main_menu_vpk0[8];
extern u8 D_80363E10_main_menu_vpk0[2048];
extern u8 D_80364610_main_menu_vpk0[8];
extern u8 D_80364618_main_menu_vpk0[32];
extern u8 D_80364638_main_menu_vpk0[8];
extern u8 D_80364640_main_menu_vpk0[2048];
extern u8 D_80364E40_main_menu_vpk0[8];
extern u8 D_80364E48_main_menu_vpk0[32];
extern u8 D_80364E68_main_menu_vpk0[8];
extern u8 D_80364E70_main_menu_vpk0[2048];
extern u8 D_80365670_main_menu_vpk0[8];
extern u8 D_80365678_main_menu_vpk0[30];
extern u8 D_80365698_main_menu_vpk0[8];
extern u8 D_803656A0_main_menu_vpk0[2048];
extern u8 D_80365EA0_main_menu_vpk0[8];
extern u8 D_80365EA8_main_menu_vpk0[32];
extern u8 D_80365EC8_main_menu_vpk0[8];
extern u8 D_80365ED0_main_menu_vpk0[1024];
extern u8 D_803662D0_main_menu_vpk0[8];
extern u8 D_803662D8_main_menu_vpk0[30];
extern u8 D_803662F8_main_menu_vpk0[8];
extern u8 D_80366300_main_menu_vpk0[1024];
extern u8 D_80366700_main_menu_vpk0[8];
extern u8 D_80366708_main_menu_vpk0[30];
extern u8 D_80366728_main_menu_vpk0[8];
extern u8 D_80366730_main_menu_vpk0[2048];
extern u8 D_80366F30_main_menu_vpk0[8];
extern u8 D_80366F38_main_menu_vpk0[32];
extern u8 D_80366F58_main_menu_vpk0[8];
extern u8 D_80366F60_main_menu_vpk0[2048];
extern u8 D_80367760_main_menu_vpk0[8];
extern u8 D_80367768_main_menu_vpk0[2048];
extern u8 D_80367F68_main_menu_vpk0[8];
extern u8 D_80367F70_main_menu_vpk0[32];
extern u8 D_80367F90_main_menu_vpk0[8];
extern u8 D_80367F98_main_menu_vpk0[2048];
extern u8 D_80368798_main_menu_vpk0[8];
extern u8 D_803687A0_main_menu_vpk0[32];
extern u8 D_803687C0_main_menu_vpk0[8];
extern u8 D_803687C8_main_menu_vpk0[1024];
extern u8 D_80368BC8_main_menu_vpk0[8];
extern u8 D_80368BD0_main_menu_vpk0[32];
extern u8 D_80368BF0_main_menu_vpk0[8];
extern u8 D_80368BF8_main_menu_vpk0[2048];
extern u8 D_803693F8_main_menu_vpk0[8];
extern u8 D_80369400_main_menu_vpk0[32];
extern u8 D_80369420_main_menu_vpk0[8];
extern u8 D_80369428_main_menu_vpk0[2048];
extern u8 D_80369C28_main_menu_vpk0[8];
extern u8 D_80369C30_main_menu_vpk0[32];
extern u8 D_80369C50_main_menu_vpk0[8];
extern u8 D_80369C58_main_menu_vpk0[2048];
extern Texture** D_8036A458_main_menu_vpk0[226];
extern Texture D_8036A7E0_main_menu_vpk0;
extern u8* D_8036A858_main_menu_vpk0[2];
extern Texture D_8036A860_main_menu_vpk0;
extern u8* D_8036A8D8_main_menu_vpk0[2];
extern Texture D_8036A8E0_main_menu_vpk0;
extern u8* D_8036A958_main_menu_vpk0[2];
extern Texture D_8036A960_main_menu_vpk0;
extern u8* D_8036A9D8_main_menu_vpk0[2];
extern Texture D_8036A9E0_main_menu_vpk0;
extern Texture* D_8036AA58_main_menu_vpk0[2];
extern Texture* D_8036AA60_main_menu_vpk0[5];
extern u8 D_8036AA74_main_menu_vpk0[4];
extern Vtx D_8036AA78_main_menu_vpk0[2019];
extern Gfx D_803728A8_main_menu_vpk0[81];
extern Gfx D_80372B30_main_menu_vpk0[66];
extern Gfx D_80372D40_main_menu_vpk0[64];
extern Gfx D_80372F40_main_menu_vpk0[35];
extern Gfx D_80373058_main_menu_vpk0[36];
extern Gfx D_80373178_main_menu_vpk0[36];
extern Gfx D_80373298_main_menu_vpk0[36];
extern Gfx D_803733B8_main_menu_vpk0[36];
extern Gfx D_803734D8_main_menu_vpk0[36];
extern Gfx D_803735F8_main_menu_vpk0[36];
extern Gfx D_80373718_main_menu_vpk0[36];
extern Gfx D_80373838_main_menu_vpk0[36];
extern Gfx D_80373958_main_menu_vpk0[36];
extern Gfx D_80373A78_main_menu_vpk0[41];
extern Gfx D_80373BC0_main_menu_vpk0[35];
extern Gfx D_80373CD8_main_menu_vpk0[36];
extern Gfx D_80373DF8_main_menu_vpk0[36];
extern Gfx D_80373F18_main_menu_vpk0[36];
extern Gfx D_80374038_main_menu_vpk0[36];
extern Gfx D_80374158_main_menu_vpk0[36];
extern Gfx D_80374278_main_menu_vpk0[38];
extern Gfx D_803743A8_main_menu_vpk0[36];
extern Gfx D_803744C8_main_menu_vpk0[36];
extern Gfx D_803745E8_main_menu_vpk0[36];
extern Gfx D_80374708_main_menu_vpk0[41];
extern Gfx D_80374850_main_menu_vpk0[35];
extern Gfx D_80374968_main_menu_vpk0[36];
extern Gfx D_80374A88_main_menu_vpk0[36];
extern Gfx D_80374BA8_main_menu_vpk0[36];
extern Gfx D_80374CC8_main_menu_vpk0[36];
extern Gfx D_80374DE8_main_menu_vpk0[36];
extern Gfx D_80374F08_main_menu_vpk0[38];
extern Gfx D_80375038_main_menu_vpk0[36];
extern Gfx D_80375158_main_menu_vpk0[36];
extern Gfx D_80375278_main_menu_vpk0[36];
extern Gfx D_80375398_main_menu_vpk0[41];
extern Gfx D_803754E0_main_menu_vpk0[35];
extern Gfx D_803755F8_main_menu_vpk0[36];
extern Gfx D_80375718_main_menu_vpk0[36];
extern Gfx D_80375838_main_menu_vpk0[39];
extern Gfx D_80375970_main_menu_vpk0[36];
extern Gfx D_80375A90_main_menu_vpk0[36];
extern Gfx D_80375BB0_main_menu_vpk0[36];
extern Gfx D_80375CD0_main_menu_vpk0[36];
extern Gfx D_80375DF0_main_menu_vpk0[36];
extern Gfx D_80375F10_main_menu_vpk0[36];
extern Gfx D_80376030_main_menu_vpk0[41];
extern Gfx D_80376178_main_menu_vpk0[35];
extern Gfx D_80376290_main_menu_vpk0[36];
extern Gfx D_803763B0_main_menu_vpk0[36];
extern Gfx D_803764D0_main_menu_vpk0[39];
extern Gfx D_80376608_main_menu_vpk0[36];
extern Gfx D_80376728_main_menu_vpk0[36];
extern Gfx D_80376848_main_menu_vpk0[36];
extern Gfx D_80376968_main_menu_vpk0[36];
extern Gfx D_80376A88_main_menu_vpk0[36];
extern Gfx D_80376BA8_main_menu_vpk0[36];
extern Gfx D_80376CC8_main_menu_vpk0[41];
extern Gfx D_80376E10_main_menu_vpk0[35];
extern Gfx D_80376F28_main_menu_vpk0[36];
extern Gfx D_80377048_main_menu_vpk0[36];
extern Gfx D_80377168_main_menu_vpk0[36];
extern Gfx D_80377288_main_menu_vpk0[36];
extern Gfx D_803773A8_main_menu_vpk0[36];
extern Gfx D_803774C8_main_menu_vpk0[36];
extern Gfx D_803775E8_main_menu_vpk0[36];
extern Gfx D_80377708_main_menu_vpk0[36];
extern Gfx D_80377828_main_menu_vpk0[36];
extern Gfx D_80377948_main_menu_vpk0[36];
extern Gfx D_80377A68_main_menu_vpk0[41];
extern Gfx D_80377BB0_main_menu_vpk0[35];
extern Gfx D_80377CC8_main_menu_vpk0[36];
extern Gfx D_80377DE8_main_menu_vpk0[36];
extern Gfx D_80377F08_main_menu_vpk0[36];
extern Gfx D_80378028_main_menu_vpk0[36];
extern Gfx D_80378148_main_menu_vpk0[36];
extern Gfx D_80378268_main_menu_vpk0[38];
extern Gfx D_80378398_main_menu_vpk0[36];
extern Gfx D_803784B8_main_menu_vpk0[36];
extern Gfx D_803785D8_main_menu_vpk0[36];
extern Gfx D_803786F8_main_menu_vpk0[41];
extern Gfx D_80378840_main_menu_vpk0[35];
extern Gfx D_80378958_main_menu_vpk0[36];
extern Gfx D_80378A78_main_menu_vpk0[36];
extern Gfx D_80378B98_main_menu_vpk0[36];
extern Gfx D_80378CB8_main_menu_vpk0[36];
extern Gfx D_80378DD8_main_menu_vpk0[36];
extern Gfx D_80378EF8_main_menu_vpk0[38];
extern Gfx D_80379028_main_menu_vpk0[36];
extern Gfx D_80379148_main_menu_vpk0[36];
extern Gfx D_80379268_main_menu_vpk0[36];
extern Gfx D_80379388_main_menu_vpk0[41];
extern Gfx D_803794D0_main_menu_vpk0[35];
extern Gfx D_803795E8_main_menu_vpk0[37];
extern Gfx D_80379710_main_menu_vpk0[36];
extern Gfx D_80379830_main_menu_vpk0[36];
extern Gfx D_80379950_main_menu_vpk0[36];
extern Gfx D_80379A70_main_menu_vpk0[36];
extern Gfx D_80379B90_main_menu_vpk0[39];
extern Gfx D_80379CC8_main_menu_vpk0[36];
extern Gfx D_80379DE8_main_menu_vpk0[36];
extern Gfx D_80379F08_main_menu_vpk0[36];
extern Gfx D_8037A028_main_menu_vpk0[41];
extern Gfx D_8037A170_main_menu_vpk0[35];
extern Gfx D_8037A288_main_menu_vpk0[36];
extern Gfx D_8037A3A8_main_menu_vpk0[36];
extern Gfx D_8037A4C8_main_menu_vpk0[36];
extern Gfx D_8037A5E8_main_menu_vpk0[36];
extern Gfx D_8037A708_main_menu_vpk0[36];
extern Gfx D_8037A828_main_menu_vpk0[38];
extern Gfx D_8037A958_main_menu_vpk0[36];
extern Gfx D_8037AA78_main_menu_vpk0[36];
extern Gfx D_8037AB98_main_menu_vpk0[36];
extern Gfx D_8037ACB8_main_menu_vpk0[41];
extern Gfx D_8037AE00_main_menu_vpk0[35];
extern Gfx D_8037AF18_main_menu_vpk0[36];
extern Gfx D_8037B038_main_menu_vpk0[36];
extern Gfx D_8037B158_main_menu_vpk0[36];
extern Gfx D_8037B278_main_menu_vpk0[36];
extern Gfx D_8037B398_main_menu_vpk0[36];
extern Gfx D_8037B4B8_main_menu_vpk0[36];
extern Gfx D_8037B5D8_main_menu_vpk0[36];
extern Gfx D_8037B6F8_main_menu_vpk0[36];
extern Gfx D_8037B818_main_menu_vpk0[36];
extern Gfx D_8037B938_main_menu_vpk0[41];
extern Gfx D_8037BA80_main_menu_vpk0[796];
extern Gfx D_8037D360_main_menu_vpk0[123];
extern Gfx D_8037D738_main_menu_vpk0[38];
extern Gfx D_8037D868_main_menu_vpk0[32];
extern Gfx D_8037D968_main_menu_vpk0[5];
extern Gfx D_8037D990_main_menu_vpk0[43];
extern Gfx D_8037DAE8_main_menu_vpk0[50];
extern Gfx D_8037DC78_main_menu_vpk0[50];
extern Gfx D_8037DE08_main_menu_vpk0[23];
extern Gfx D_8037DEC0_main_menu_vpk0[23];
extern Gfx D_8037DF78_main_menu_vpk0[24];
extern Gfx D_8037E038_main_menu_vpk0[24];
extern Gfx D_8037E0F8_main_menu_vpk0[23];
extern Gfx D_8037E1B0_main_menu_vpk0[24];
extern Gfx D_8037E270_main_menu_vpk0[23];
extern Gfx D_8037E328_main_menu_vpk0[23];
extern Gfx D_8037E3E0_main_menu_vpk0[24];
extern Gfx D_8037E4A0_main_menu_vpk0[24];
extern Gfx D_8037E560_main_menu_vpk0[25];
extern Gfx D_8037E628_main_menu_vpk0[23];
extern Gfx D_8037E6E0_main_menu_vpk0[26];
extern Gfx D_8037E7B0_main_menu_vpk0[39];
extern Gfx D_8037E8E8_main_menu_vpk0[39];
extern Gfx D_8037EA20_main_menu_vpk0[5];
extern Gfx D_8037EA48_main_menu_vpk0[44];
extern Gfx D_8037EBA8_main_menu_vpk0[44];
extern DObjPayloadTypeC D_8037ED08_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED18_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED28_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED38_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED48_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED58_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED68_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED78_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED88_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037ED98_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EDA8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EDB8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EDC8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EDD8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EDE8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EDF8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE08_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE18_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE28_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE38_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE48_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE58_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE68_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE78_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE88_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EE98_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EEA8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EEB8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EEC8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EED8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EEE8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EEF8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF08_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF18_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF28_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF38_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF48_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF58_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF68_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF78_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF88_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EF98_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EFA8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EFB8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EFC8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EFD8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EFE8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037EFF8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F008_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F018_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F028_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F038_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F048_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F058_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F068_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F078_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F088_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F098_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F0A8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F0B8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F0C8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F0D8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F0E8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F0F8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F108_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F118_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F128_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F138_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F148_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F158_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F168_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F178_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F188_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F198_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F1A8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F1B8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F1C8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F1D8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F1E8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F1F8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F208_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F218_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F228_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F238_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F248_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F258_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F268_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F278_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F288_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F298_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F2A8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F2B8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F2C8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F2D8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F2E8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F2F8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F308_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F318_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F328_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F338_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F348_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F358_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F368_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F378_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F388_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F398_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F3A8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F3B8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F3C8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F3D8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F3E8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F3F8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F408_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F418_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F428_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F438_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F448_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F458_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F468_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F478_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F488_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F498_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F4A8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F4B8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F4C8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F4D8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F4E8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F4F8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F508_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F518_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F528_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F538_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F548_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F558_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F568_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F578_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F588_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F598_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F5A8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F5B8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F5C8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F5D8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F5E8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F5F8_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F608_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F618_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F628_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F638_main_menu_vpk0[2];
extern DObjPayloadTypeC D_8037F648_main_menu_vpk0[2];
extern UnkEC64Arg3 D_8037F658_main_menu_vpk0[227];
extern u8 D_80381D5C_main_menu_vpk0[4];
extern AnimCmd* D_80381D60_main_menu_vpk0[226];
extern struct MainMenuAnimation803820E8 D_803820E8_main_menu_vpk0;
extern struct MainMenuAnimation8038217C D_8038217C_main_menu_vpk0;
extern struct MainMenuAnimation80382478 D_80382478_main_menu_vpk0;
extern struct MainMenuAnimation803824B4 D_803824B4_main_menu_vpk0;
extern struct MainMenuAnimation80382500 D_80382500_main_menu_vpk0;
extern struct MainMenuAnimation8038254C D_8038254C_main_menu_vpk0;
extern struct MainMenuAnimation803826E4 D_803826E4_main_menu_vpk0;
extern struct MainMenuAnimation803828B4 D_803828B4_main_menu_vpk0;
extern struct MainMenuAnimation80382A84 D_80382A84_main_menu_vpk0;
extern struct MainMenuAnimation80382C40 D_80382C40_main_menu_vpk0;
extern struct MainMenuAnimation80382DAC D_80382DAC_main_menu_vpk0;
extern struct MainMenuAnimation80382EF4 D_80382EF4_main_menu_vpk0;
extern struct MainMenuAnimation8038303C D_8038303C_main_menu_vpk0;
extern struct MainMenuAnimation803831FC D_803831FC_main_menu_vpk0;
extern struct MainMenuAnimation803833BC D_803833BC_main_menu_vpk0;
extern struct MainMenuAnimation80383504 D_80383504_main_menu_vpk0;
extern struct MainMenuAnimation803836EC D_803836EC_main_menu_vpk0;
extern struct MainMenuAnimation80383834 D_80383834_main_menu_vpk0;
extern struct MainMenuAnimation8038397C D_8038397C_main_menu_vpk0;
extern struct MainMenuAnimation80383B20 D_80383B20_main_menu_vpk0;
extern struct MainMenuAnimation80383D08 D_80383D08_main_menu_vpk0;
extern struct MainMenuAnimation80383E78 D_80383E78_main_menu_vpk0;
extern struct MainMenuAnimation80384018 D_80384018_main_menu_vpk0;
extern struct MainMenuAnimation80384160 D_80384160_main_menu_vpk0;
extern struct MainMenuAnimation803842A8 D_803842A8_main_menu_vpk0;
extern struct MainMenuAnimation803843F0 D_803843F0_main_menu_vpk0;
extern struct MainMenuAnimation8038450C D_8038450C_main_menu_vpk0;
extern struct MainMenuAnimation80384654 D_80384654_main_menu_vpk0;
extern struct MainMenuAnimation803847BC D_803847BC_main_menu_vpk0;
extern struct MainMenuAnimation80384904 D_80384904_main_menu_vpk0;
extern struct MainMenuAnimation80384A6C D_80384A6C_main_menu_vpk0;
extern struct MainMenuAnimation80384BDC D_80384BDC_main_menu_vpk0;
extern struct MainMenuAnimation80384D4C D_80384D4C_main_menu_vpk0;
extern struct MainMenuAnimation80384EBC D_80384EBC_main_menu_vpk0;
extern struct MainMenuAnimation80385004 D_80385004_main_menu_vpk0;
extern struct MainMenuAnimation803850A4 D_803850A4_main_menu_vpk0;
extern struct MainMenuAnimation80385120 D_80385120_main_menu_vpk0;
extern struct MainMenuAnimation8038519C D_8038519C_main_menu_vpk0;
extern struct MainMenuAnimation803851AC D_803851AC_main_menu_vpk0;
extern struct MainMenuAnimation803852A0 D_803852A0_main_menu_vpk0;
extern struct MainMenuAnimation80385320 D_80385320_main_menu_vpk0;
extern struct MainMenuAnimation8038550C D_8038550C_main_menu_vpk0;
extern u8 D_803856FC_main_menu_vpk0[4];
extern AnimCmd** D_80385700_main_menu_vpk0[226];
extern struct MainMenuAnimation80385A88 D_80385A88_main_menu_vpk0;
extern struct MainMenuAnimation80385AF4 D_80385AF4_main_menu_vpk0;
extern struct MainMenuAnimation80385BB8 D_80385BB8_main_menu_vpk0;
extern struct MainMenuAnimation80385C7C D_80385C7C_main_menu_vpk0;
extern struct MainMenuAnimation80385D40 D_80385D40_main_menu_vpk0;
extern AnimCmd* D_80385E04_main_menu_vpk0[1];
extern AnimCmd* D_80385E08_main_menu_vpk0[4];
extern u8 D_80385E18_main_menu_vpk0[16];
extern u8 D_80385E28_main_menu_vpk0[4096];
extern u8 D_80386E28_main_menu_vpk0[8];
extern u8 D_80386E30_main_menu_vpk0[512];
extern u8 D_80387030_main_menu_vpk0[8];
extern u8 D_80387038_main_menu_vpk0[30];
extern u8 D_80387058_main_menu_vpk0[8];
extern u8 D_80387060_main_menu_vpk0[512];
extern u8 D_80387260_main_menu_vpk0[8];
extern u8 D_80387268_main_menu_vpk0[12];
extern u8 D_80387274_main_menu_vpk0[12];
extern u8 D_80387280_main_menu_vpk0[512];
extern u8 D_80387480_main_menu_vpk0[8];
extern u8 D_80387488_main_menu_vpk0[18];
extern u8 D_8038749C_main_menu_vpk0[12];
extern u8 D_803874A8_main_menu_vpk0[1920];
extern u8 D_80387C28_main_menu_vpk0[8];
extern u8 D_80387C30_main_menu_vpk0[510];
extern u8 D_80387E30_main_menu_vpk0[8];
extern u8 D_80387E38_main_menu_vpk0[1920];
extern u8 D_803885B8_main_menu_vpk0[8];
extern u8 D_803885C0_main_menu_vpk0[1920];
extern u8 D_80388D40_main_menu_vpk0[8];
extern u8 D_80388D48_main_menu_vpk0[1920];
extern u8 D_803894C8_main_menu_vpk0[8];
extern u8 D_803894D0_main_menu_vpk0[1920];
extern u8 D_80389C50_main_menu_vpk0[8];
extern u8 D_80389C58_main_menu_vpk0[512];
extern u8 D_80389E58_main_menu_vpk0[8];
extern u8 D_80389E60_main_menu_vpk0[30];
extern u8 D_80389E80_main_menu_vpk0[8];
extern u8 D_80389E88_main_menu_vpk0[1024];
extern u8 D_8038A288_main_menu_vpk0[8];
extern u8 D_8038A290_main_menu_vpk0[30];
extern u8 D_8038A2B0_main_menu_vpk0[8];
extern u8 D_8038A2B8_main_menu_vpk0[512];
extern u8 D_8038A4B8_main_menu_vpk0[8];
extern u8 D_8038A4C0_main_menu_vpk0[32];
extern u8 D_8038A4E0_main_menu_vpk0[8];
extern u8 D_8038A4E8_main_menu_vpk0[1024];
extern u8 D_8038A8E8_main_menu_vpk0[8];
extern u8 D_8038A8F0_main_menu_vpk0[30];
extern u8 D_8038A910_main_menu_vpk0[8];
extern u8 D_8038A918_main_menu_vpk0[1024];
extern u8 D_8038AD18_main_menu_vpk0[8];
extern u8 D_8038AD20_main_menu_vpk0[30];
extern Texture** D_8038AD40_main_menu_vpk0[33];
extern u8* D_8038ADC4_main_menu_vpk0[7];
extern Texture D_8038ADE0_main_menu_vpk0;
extern Texture* D_8038AE58_main_menu_vpk0[2];
extern Vtx D_8038AE60_main_menu_vpk0[432];
extern Gfx D_8038C960_main_menu_vpk0[99];
extern Gfx D_8038CC78_main_menu_vpk0[29];
extern Gfx D_8038CD60_main_menu_vpk0[69];
extern Gfx D_8038CF88_main_menu_vpk0[12];
extern Gfx D_8038CFE8_main_menu_vpk0[45];
extern Gfx D_8038D150_main_menu_vpk0[135];
extern Gfx D_8038D588_main_menu_vpk0[6];
extern Gfx D_8038D5B8_main_menu_vpk0[16];
extern Gfx D_8038D638_main_menu_vpk0[6];
extern Gfx D_8038D668_main_menu_vpk0[16];
extern Gfx D_8038D6E8_main_menu_vpk0[14];
extern Gfx D_8038D758_main_menu_vpk0[16];
extern Gfx D_8038D7D8_main_menu_vpk0[14];
extern Gfx D_8038D848_main_menu_vpk0[40];
extern Gfx D_8038D988_main_menu_vpk0[16];
extern Gfx D_8038DA08_main_menu_vpk0[16];
extern Gfx D_8038DA88_main_menu_vpk0[14];
extern Gfx D_8038DAF8_main_menu_vpk0[40];
extern Gfx D_8038DC38_main_menu_vpk0[23];
extern Gfx D_8038DCF0_main_menu_vpk0[57];
extern Gfx D_8038DEB8_main_menu_vpk0[19];
extern Gfx D_8038DF50_main_menu_vpk0[21];
extern Gfx D_8038DFF8_main_menu_vpk0[53];
extern Gfx D_8038E1A0_main_menu_vpk0[53];
extern Gfx D_8038E348_main_menu_vpk0[16];
extern Gfx D_8038E3C8_main_menu_vpk0[56];
extern Gfx D_8038E588_main_menu_vpk0[24];
extern Gfx D_8038E648_main_menu_vpk0[25];
extern Gfx D_8038E710_main_menu_vpk0[58];
extern Gfx D_8038E8E0_main_menu_vpk0[55];
extern Gfx D_8038EA98_main_menu_vpk0[9];
extern Gfx D_8038EAE0_main_menu_vpk0[34];
extern Gfx D_8038EBF0_main_menu_vpk0[32];
extern Gfx D_8038ECF0_main_menu_vpk0[16];
extern Gfx D_8038ED70_main_menu_vpk0[16];
extern Gfx D_8038EDF0_main_menu_vpk0[14];
extern Gfx D_8038EE60_main_menu_vpk0[30];
extern Gfx D_8038EF50_main_menu_vpk0[30];
extern Gfx D_8038F040_main_menu_vpk0[31];
extern Gfx D_8038F138_main_menu_vpk0[34];
extern Gfx D_8038F248_main_menu_vpk0[19];
extern DObjPayloadTypeI D_8038F2E0_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F2E8_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F2F0_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F2F8_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F300_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F308_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F310_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F318_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F320_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F328_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F330_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F338_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F340_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F348_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F350_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F358_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F360_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F368_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F370_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F378_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F380_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F388_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F390_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F398_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3A0_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3A8_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3B0_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3B8_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3C0_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3C8_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3D0_main_menu_vpk0;
extern DObjPayloadTypeI D_8038F3D8_main_menu_vpk0;
extern UnkEC64Arg3 D_8038F3E0_main_menu_vpk0[34];
extern u8 D_8038F9B8_main_menu_vpk0[8];
extern AnimCmd* D_8038F9C0_main_menu_vpk0[33];
extern struct MainMenuAnimation8038FA44 D_8038FA44_main_menu_vpk0;
extern struct MainMenuAnimation8038FE0C D_8038FE0C_main_menu_vpk0;
extern struct MainMenuAnimation803900D4 D_803900D4_main_menu_vpk0;
extern struct MainMenuAnimation80390CCC D_80390CCC_main_menu_vpk0;
extern struct MainMenuAnimation80390E94 D_80390E94_main_menu_vpk0;
extern struct MainMenuAnimation80390F58 D_80390F58_main_menu_vpk0;
extern struct MainMenuAnimation80391018 D_80391018_main_menu_vpk0;
extern struct MainMenuAnimation803910DC D_803910DC_main_menu_vpk0;
extern struct MainMenuAnimation803912A8 D_803912A8_main_menu_vpk0;
extern struct MainMenuAnimation80391418 D_80391418_main_menu_vpk0;
extern struct MainMenuAnimation8039154C D_8039154C_main_menu_vpk0;
extern struct MainMenuAnimation803916AC D_803916AC_main_menu_vpk0;
extern struct MainMenuAnimation8039183C D_8039183C_main_menu_vpk0;
extern struct MainMenuAnimation80391910 D_80391910_main_menu_vpk0;
extern struct MainMenuAnimation80391AD4 D_80391AD4_main_menu_vpk0;
extern struct MainMenuAnimation80391D08 D_80391D08_main_menu_vpk0;
extern struct MainMenuAnimation80391E10 D_80391E10_main_menu_vpk0;
extern struct MainMenuAnimation80391E8C D_80391E8C_main_menu_vpk0;
extern struct MainMenuAnimation80391F38 D_80391F38_main_menu_vpk0;
extern struct MainMenuAnimation803920B0 D_803920B0_main_menu_vpk0;
extern struct MainMenuAnimation80392294 D_80392294_main_menu_vpk0;
extern struct MainMenuAnimation8039239C D_8039239C_main_menu_vpk0;
extern struct MainMenuAnimation80392418 D_80392418_main_menu_vpk0;
extern struct MainMenuAnimation80392508 D_80392508_main_menu_vpk0;
extern struct MainMenuAnimation8039276C D_8039276C_main_menu_vpk0;
extern struct MainMenuAnimation803929C0 D_803929C0_main_menu_vpk0;
extern struct MainMenuAnimation80392BFC D_80392BFC_main_menu_vpk0;
extern struct MainMenuAnimation80392E2C D_80392E2C_main_menu_vpk0;
extern struct MainMenuAnimation80393064 D_80393064_main_menu_vpk0;
extern struct MainMenuAnimation803932B8 D_803932B8_main_menu_vpk0;
extern struct MainMenuAnimation80393528 D_80393528_main_menu_vpk0;
extern struct MainMenuAnimation8039379C D_8039379C_main_menu_vpk0;
extern struct MainMenuAnimation80393938 D_80393938_main_menu_vpk0;
extern u8 D_80393ADC_main_menu_vpk0[4];
extern AnimCmd** D_80393AE0_main_menu_vpk0[33];
extern struct MainMenuAnimation80393B64 D_80393B64_main_menu_vpk0;
extern AnimCmd* D_80393BEC_main_menu_vpk0[1];
extern Vtx D_80393BF0_main_menu_vpk0[12];
extern Gfx D_80393CB0_main_menu_vpk0[16];
extern UnkEC64Arg3 D_80393D30_main_menu_vpk0[3];
extern u8 D_80393DB4_main_menu_vpk0[12];
extern AnimCmd* D_80393DC0_main_menu_vpk0[2];
extern struct MainMenuAnimation80393DC8 D_80393DC8_main_menu_vpk0;
extern u8 D_803943B0_main_menu_vpk0[8];
extern u8 D_803943B8_main_menu_vpk0[1024];
extern u8 D_803947B8_main_menu_vpk0[8];
extern u8 D_803947C0_main_menu_vpk0[512];
extern u8 D_803949C0_main_menu_vpk0[8];
extern u8 D_803949C8_main_menu_vpk0[4];
extern u8 D_803949CC_main_menu_vpk0[12];
extern u8 D_803949D8_main_menu_vpk0[512];
extern u8 D_80394BD8_main_menu_vpk0[8];
extern u8 D_80394BE0_main_menu_vpk0[16];
extern u8 D_80394BF0_main_menu_vpk0[8];
extern u8 D_80394BF8_main_menu_vpk0[1024];
extern u8 D_80394FF8_main_menu_vpk0[8];
extern u8 D_80395000_main_menu_vpk0[156];
extern u8 D_8039509C_main_menu_vpk0[12];
extern u8 D_803950A8_main_menu_vpk0[2048];
extern u8 D_803958A8_main_menu_vpk0[8];
extern u8 D_803958B0_main_menu_vpk0[2048];
extern u8 D_803960B0_main_menu_vpk0[8];
extern u8 D_803960B8_main_menu_vpk0[2048];
extern u8 D_803968B8_main_menu_vpk0[8];
extern u8 D_803968C0_main_menu_vpk0[2048];
extern u8 D_803970C0_main_menu_vpk0[8];
extern u8 D_803970C8_main_menu_vpk0[512];
extern u8 D_803972C8_main_menu_vpk0[8];
extern u8 D_803972D0_main_menu_vpk0[32];
extern u8 D_803972F0_main_menu_vpk0[8];
extern u8 D_803972F8_main_menu_vpk0[512];
extern u8 D_803974F8_main_menu_vpk0[8];
extern u8 D_80397500_main_menu_vpk0[32];
extern u8 D_80397520_main_menu_vpk0[8];
extern u8 D_80397528_main_menu_vpk0[1024];
extern u8 D_80397928_main_menu_vpk0[8];
extern u8 D_80397930_main_menu_vpk0[512];
extern u8 D_80397B30_main_menu_vpk0[8];
extern u8 D_80397B38_main_menu_vpk0[1024];
extern u8 D_80397F38_main_menu_vpk0[8];
extern u8 D_80397F40_main_menu_vpk0[512];
extern u8 D_80398140_main_menu_vpk0[8];
extern u8 D_80398148_main_menu_vpk0[1024];
extern u8 D_80398548_main_menu_vpk0[8];
extern u8 D_80398550_main_menu_vpk0[512];
extern u8 D_80398750_main_menu_vpk0[8];
extern u8 D_80398758_main_menu_vpk0[512];
extern u8 D_80398958_main_menu_vpk0[8];
extern u8 D_80398960_main_menu_vpk0[32];
extern u8 D_80398980_main_menu_vpk0[8];
extern u8 D_80398988_main_menu_vpk0[2048];
extern u8 D_80399188_main_menu_vpk0[8];
extern u8 D_80399190_main_menu_vpk0[2048];
extern u8 D_80399990_main_menu_vpk0[8];
extern u8 D_80399998_main_menu_vpk0[512];
extern u8 D_80399B98_main_menu_vpk0[8];
extern u8 D_80399BA0_main_menu_vpk0[2048];
extern u8 D_8039A3A0_main_menu_vpk0[8];
extern u8 D_8039A3A8_main_menu_vpk0[2048];
extern u8 D_8039ABA8_main_menu_vpk0[8];
extern u8 D_8039ABB0_main_menu_vpk0[512];
extern u8 D_8039ADB0_main_menu_vpk0[8];
extern u8 D_8039ADB8_main_menu_vpk0[32];
extern u8 D_8039ADD8_main_menu_vpk0[8];
extern u8 D_8039ADE0_main_menu_vpk0[512];
extern u8 D_8039AFE0_main_menu_vpk0[8];
extern u8 D_8039AFE8_main_menu_vpk0[32];
extern u8 D_8039B008_main_menu_vpk0[8];
extern u8 D_8039B010_main_menu_vpk0[512];
extern u8 D_8039B210_main_menu_vpk0[8];
extern u8 D_8039B218_main_menu_vpk0[8];
extern u8 D_8039B220_main_menu_vpk0[8];
extern u8 D_8039B228_main_menu_vpk0[512];
extern u8 D_8039B428_main_menu_vpk0[8];
extern u8 D_8039B430_main_menu_vpk0[14];
extern u8 D_8039B440_main_menu_vpk0[8];
extern u8 D_8039B448_main_menu_vpk0[2048];
extern Texture** D_8039BC48_main_menu_vpk0[26];
extern u8* D_8039BCB0_main_menu_vpk0[4];
extern Texture D_8039BCC0_main_menu_vpk0;
extern Texture* D_8039BD38_main_menu_vpk0[2];
extern Vtx D_8039BD40_main_menu_vpk0[727];
extern Gfx D_8039EAB0_main_menu_vpk0[35];
extern Gfx D_8039EBC8_main_menu_vpk0[9];
extern Gfx D_8039EC10_main_menu_vpk0[52];
extern Gfx D_8039EDB0_main_menu_vpk0[55];
extern Gfx D_8039EF68_main_menu_vpk0[66];
extern Gfx D_8039F178_main_menu_vpk0[68];
extern Gfx D_8039F398_main_menu_vpk0[9];
extern Gfx D_8039F3E0_main_menu_vpk0[52];
extern Gfx D_8039F580_main_menu_vpk0[54];
extern Gfx D_8039F730_main_menu_vpk0[71];
extern Gfx D_8039F968_main_menu_vpk0[70];
extern Gfx D_8039FB98_main_menu_vpk0[34];
extern Gfx D_8039FCA8_main_menu_vpk0[66];
extern Gfx D_8039FEB8_main_menu_vpk0[35];
extern Gfx D_8039FFD0_main_menu_vpk0[70];
extern Gfx D_803A0200_main_menu_vpk0[9];
extern Gfx D_803A0248_main_menu_vpk0[32];
extern Gfx D_803A0348_main_menu_vpk0[97];
extern Gfx D_803A0650_main_menu_vpk0[29];
extern Gfx D_803A0738_main_menu_vpk0[81];
extern Gfx D_803A09C0_main_menu_vpk0[9];
extern Gfx D_803A0A08_main_menu_vpk0[57];
extern Gfx D_803A0BD0_main_menu_vpk0[32];
extern Gfx D_803A0CD0_main_menu_vpk0[47];
extern Gfx D_803A0E48_main_menu_vpk0[9];
extern Gfx D_803A0E90_main_menu_vpk0[59];
extern Gfx D_803A1068_main_menu_vpk0[32];
extern Gfx D_803A1168_main_menu_vpk0[47];
extern Gfx D_803A12E0_main_menu_vpk0[44];
extern Gfx D_803A1440_main_menu_vpk0[19];
extern DObjPayloadTypeJ D_803A14D8_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A14F0_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1508_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1520_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1538_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1550_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1568_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1580_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1598_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A15B0_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A15C8_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A15E0_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A15F8_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1610_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1628_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1640_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1658_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1670_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1688_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A16A0_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A16B8_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A16D0_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A16E8_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1700_main_menu_vpk0[2];
extern DObjPayloadTypeJ D_803A1718_main_menu_vpk0[2];
extern UnkEC64Arg3 D_803A1730_main_menu_vpk0[27];
extern u8 D_803A1BD4_main_menu_vpk0[12];
extern AnimCmd* D_803A1BE0_main_menu_vpk0[26];
extern struct MainMenuAnimation803A1C48 D_803A1C48_main_menu_vpk0;
extern struct MainMenuAnimation803A1E94 D_803A1E94_main_menu_vpk0;
extern struct MainMenuAnimation803A224C D_803A224C_main_menu_vpk0;
extern struct MainMenuAnimation803A26A0 D_803A26A0_main_menu_vpk0;
extern struct MainMenuAnimation803A2A28 D_803A2A28_main_menu_vpk0;
extern struct MainMenuAnimation803A2D18 D_803A2D18_main_menu_vpk0;
extern struct MainMenuAnimation803A31AC D_803A31AC_main_menu_vpk0;
extern struct MainMenuAnimation803A36B4 D_803A36B4_main_menu_vpk0;
extern struct MainMenuAnimation803A3B20 D_803A3B20_main_menu_vpk0;
extern struct MainMenuAnimation803A3ED8 D_803A3ED8_main_menu_vpk0;
extern struct MainMenuAnimation803A4534 D_803A4534_main_menu_vpk0;
extern struct MainMenuAnimation803A480C D_803A480C_main_menu_vpk0;
extern struct MainMenuAnimation803A4DE4 D_803A4DE4_main_menu_vpk0;
extern struct MainMenuAnimation803A528C D_803A528C_main_menu_vpk0;
extern struct MainMenuAnimation803A53B8 D_803A53B8_main_menu_vpk0;
extern struct MainMenuAnimation803A54E4 D_803A54E4_main_menu_vpk0;
extern struct MainMenuAnimation803A5820 D_803A5820_main_menu_vpk0;
extern struct MainMenuAnimation803A5C90 D_803A5C90_main_menu_vpk0;
extern struct MainMenuAnimation803A61A4 D_803A61A4_main_menu_vpk0;
extern struct MainMenuAnimation803A66BC D_803A66BC_main_menu_vpk0;
extern struct MainMenuAnimation803A6B94 D_803A6B94_main_menu_vpk0;
extern struct MainMenuAnimation803A70F8 D_803A70F8_main_menu_vpk0;
extern struct MainMenuAnimation803A78A4 D_803A78A4_main_menu_vpk0;
extern struct MainMenuAnimation803A7D34 D_803A7D34_main_menu_vpk0;
extern u8 D_803A7F8C_main_menu_vpk0[4];
extern AnimCmd** D_803A7F90_main_menu_vpk0[26];
extern struct MainMenuAnimation803A7FF8 D_803A7FF8_main_menu_vpk0;
extern AnimCmd* D_803A80C0_main_menu_vpk0[1];
extern u8 D_803A80C4_main_menu_vpk0[12];
extern struct MainMenuAnimation803A80D0 D_803A80D0_main_menu_vpk0;
extern u8 D_803A8764_main_menu_vpk0[12];
extern Gfx D_803A8770_main_menu_vpk0[504];
extern Gfx D_803A9730_main_menu_vpk0[36];
extern Gfx D_803A9850_main_menu_vpk0[36];
extern Gfx D_803A9970_main_menu_vpk0[36];
extern Gfx D_803A9A90_main_menu_vpk0[36];
extern Gfx D_803A9BB0_main_menu_vpk0[36];
extern Gfx D_803A9CD0_main_menu_vpk0[36];
extern Gfx D_803A9DF0_main_menu_vpk0[36];
extern Gfx D_803A9F10_main_menu_vpk0[72];
extern Gfx D_803AA150_main_menu_vpk0[168];
extern Gfx D_803AA690_main_menu_vpk0[168];
extern Gfx D_803AABD0_main_menu_vpk0[240];
extern Gfx D_803AB350_main_menu_vpk0[216];
extern Gfx D_803ABA10_main_menu_vpk0[72];
extern Gfx D_803ABC50_main_menu_vpk0[72];
extern Gfx D_803ABE90_main_menu_vpk0[72];
extern Gfx D_803AC0D0_main_menu_vpk0[72];
extern Gfx D_803AC310_main_menu_vpk0[48];
extern Gfx D_803AC490_main_menu_vpk0[48];
extern Gfx D_803AC610_main_menu_vpk0[48];
extern Gfx D_803AC790_main_menu_vpk0[120];
extern Gfx D_803ACB50_main_menu_vpk0[36];
extern Gfx D_803ACC70_main_menu_vpk0[36];
extern Gfx D_803ACD90_main_menu_vpk0[132];
extern Gfx D_803AD1B0_main_menu_vpk0[36];
extern Gfx D_803AD2D0_main_menu_vpk0[36];
extern Gfx D_803AD3F0_main_menu_vpk0[120];

/* Original physical order; one ordinary IDO .data section. */
#include "main_menu_vpk0/sprites/802B5000.inc.c"
#include "main_menu_vpk0/sprites/802B5008.inc.c"
#include "main_menu_vpk0/sprites/802B6008.inc.c"
#include "main_menu_vpk0/sprites/802B6010.inc.c"
#include "main_menu_vpk0/sprites/802B7010.inc.c"
#include "main_menu_vpk0/sprites/802B7018.inc.c"
#include "main_menu_vpk0/sprites/802B8018.inc.c"
#include "main_menu_vpk0/sprites/802B8020.inc.c"
#include "main_menu_vpk0/sprites/802B9020.inc.c"
#include "main_menu_vpk0/sprites/802B9028.inc.c"
#include "main_menu_vpk0/sprites/802BA028.inc.c"
#include "main_menu_vpk0/sprites/802BA030.inc.c"
#include "main_menu_vpk0/sprites/802BB030.inc.c"
#include "main_menu_vpk0/sprites/802BB038.inc.c"
#include "main_menu_vpk0/sprites/802BC038.inc.c"
#include "main_menu_vpk0/sprites/802BC040.inc.c"
#include "main_menu_vpk0/sprites/802BD040.inc.c"
#include "main_menu_vpk0/sprites/802BD048.inc.c"
#include "main_menu_vpk0/sprites/802BE048.inc.c"
#include "main_menu_vpk0/sprites/802BE050.inc.c"
#include "main_menu_vpk0/sprites/802BF050.inc.c"
#include "main_menu_vpk0/sprites/802BF058.inc.c"
#include "main_menu_vpk0/sprites/802C0058.inc.c"
#include "main_menu_vpk0/sprites/802C0060.inc.c"
#include "main_menu_vpk0/sprites/802C1060.inc.c"
#include "main_menu_vpk0/sprites/802C1068.inc.c"
#include "main_menu_vpk0/sprites/802C2068.inc.c"
#include "main_menu_vpk0/sprites/802C2070.inc.c"
#include "main_menu_vpk0/sprites/802C3070.inc.c"
#include "main_menu_vpk0/sprites/802C3078.inc.c"
#include "main_menu_vpk0/sprites/802C4078.inc.c"
#include "main_menu_vpk0/sprites/802C4080.inc.c"
#include "main_menu_vpk0/sprites/802C5080.inc.c"
#include "main_menu_vpk0/sprites/802C5088.inc.c"
#include "main_menu_vpk0/sprites/802C6088.inc.c"
#include "main_menu_vpk0/sprites/802C6090.inc.c"
#include "main_menu_vpk0/sprites/802C7090.inc.c"
#include "main_menu_vpk0/sprites/802C7098.inc.c"
#include "main_menu_vpk0/sprites/802C8098.inc.c"
#include "main_menu_vpk0/sprites/802C80A0.inc.c"
#include "main_menu_vpk0/sprites/802C90A0.inc.c"
#include "main_menu_vpk0/sprites/802C90A8.inc.c"
#include "main_menu_vpk0/sprites/802CA0A8.inc.c"
#include "main_menu_vpk0/sprites/802CA0B0.inc.c"
#include "main_menu_vpk0/sprites/802CB0B0.inc.c"
#include "main_menu_vpk0/sprites/802CB0B8.inc.c"
#include "main_menu_vpk0/sprites/802CC0B8.inc.c"
#include "main_menu_vpk0/sprites/802CC0C0.inc.c"
#include "main_menu_vpk0/sprites/802CD0C0.inc.c"
#include "main_menu_vpk0/sprites/802CD0C8.inc.c"
#include "main_menu_vpk0/sprites/802CE0C8.inc.c"
#include "main_menu_vpk0/sprites/802CE0D0.inc.c"
#include "main_menu_vpk0/sprites/802CF0D0.inc.c"
#include "main_menu_vpk0/sprites/802CF0D8.inc.c"
#include "main_menu_vpk0/sprites/802D00D8.inc.c"
#include "main_menu_vpk0/sprites/802D00E0.inc.c"
#include "main_menu_vpk0/sprites/802D10E0.inc.c"
#include "main_menu_vpk0/sprites/802D10E8.inc.c"
#include "main_menu_vpk0/sprites/802D20E8.inc.c"
#include "main_menu_vpk0/sprites/802D20F0.inc.c"
#include "main_menu_vpk0/sprites/802D30F0.inc.c"
#include "main_menu_vpk0/sprites/802D30F8.inc.c"
#include "main_menu_vpk0/sprites/802D3CF8.inc.c"
#include "main_menu_vpk0/sprites/802D3D00.inc.c"
#include "main_menu_vpk0/sprites/802D4900.inc.c"
#include "main_menu_vpk0/sprites/802D4908.inc.c"
#include "main_menu_vpk0/sprites/802D5508.inc.c"
#include "main_menu_vpk0/sprites/802D5510.inc.c"
#include "main_menu_vpk0/sprites/802D6110.inc.c"
#include "main_menu_vpk0/sprites/802D6118.inc.c"
#include "main_menu_vpk0/sprites/802D6D18.inc.c"
#include "main_menu_vpk0/sprites/802D6D20.inc.c"
#include "main_menu_vpk0/sprites/802D7920.inc.c"
#include "main_menu_vpk0/sprites/802D7928.inc.c"
#include "main_menu_vpk0/sprites/802D8528.inc.c"
#include "main_menu_vpk0/sprites/802D8530.inc.c"
#include "main_menu_vpk0/sprites/802D9130.inc.c"
#include "main_menu_vpk0/sprites/802D9138.inc.c"
#include "main_menu_vpk0/sprites/802D9D38.inc.c"
#include "main_menu_vpk0/sprites/802D9D40.inc.c"
#include "main_menu_vpk0/sprites/802DA940.inc.c"
#include "main_menu_vpk0/sprites/802DABC0.inc.c"
#include "main_menu_vpk0/sprites/802DAC04.inc.c"
#include "main_menu_vpk0/sprites/802DAC10.inc.c"
#include "main_menu_vpk0/sprites/802DAC18.inc.c"
#include "main_menu_vpk0/sprites/802DB318.inc.c"
#include "main_menu_vpk0/sprites/802DB328.inc.c"
#include "main_menu_vpk0/sprites/802DB36C.inc.c"
#include "main_menu_vpk0/sprites/802DB370.inc.c"
#include "main_menu_vpk0/sprites/802DB378.inc.c"
#include "main_menu_vpk0/sprites/802DB578.inc.c"
#include "main_menu_vpk0/sprites/802DB588.inc.c"
#include "main_menu_vpk0/sprites/802DB5CC.inc.c"
#include "main_menu_vpk0/sprites/802DB5D0.inc.c"
#include "main_menu_vpk0/sprites/802DB5D8.inc.c"
#include "main_menu_vpk0/sprites/802DBCD8.inc.c"
#include "main_menu_vpk0/sprites/802DBCE8.inc.c"
#include "main_menu_vpk0/sprites/802DBD2C.inc.c"
#include "main_menu_vpk0/sprites/802DBD30.inc.c"
#include "main_menu_vpk0/sprites/802DBD38.inc.c"
#include "main_menu_vpk0/sprites/802DC198.inc.c"
#include "main_menu_vpk0/sprites/802DC1A8.inc.c"
#include "main_menu_vpk0/sprites/802DC1EC.inc.c"
#include "main_menu_vpk0/sprites/802DC1F0.inc.c"
#include "main_menu_vpk0/sprites/802DC1F8.inc.c"
#include "main_menu_vpk0/sprites/802DC708.inc.c"
#include "main_menu_vpk0/sprites/802DC718.inc.c"
#include "main_menu_vpk0/sprites/802DC75C.inc.c"
#include "main_menu_vpk0/sprites/802DC760.inc.c"
#include "main_menu_vpk0/sprites/802DC768.inc.c"
#include "main_menu_vpk0/sprites/802DC968.inc.c"
#include "main_menu_vpk0/sprites/802DC978.inc.c"
#include "main_menu_vpk0/sprites/802DC9BC.inc.c"
#include "main_menu_vpk0/sprites/802DC9C0.inc.c"
#include "main_menu_vpk0/sprites/802DC9C8.inc.c"
#include "main_menu_vpk0/sprites/802DCE78.inc.c"
#include "main_menu_vpk0/sprites/802DCE88.inc.c"
#include "main_menu_vpk0/sprites/802DCECC.inc.c"
#include "main_menu_vpk0/sprites/802DCED0.inc.c"
#include "main_menu_vpk0/sprites/802DCED8.inc.c"
#include "main_menu_vpk0/sprites/802DDED8.inc.c"
#include "main_menu_vpk0/sprites/802DDEE0.inc.c"
#include "main_menu_vpk0/sprites/802DEBE0.inc.c"
#include "main_menu_vpk0/sprites/802DEBE8.inc.c"
#include "main_menu_vpk0/sprites/802DF3E8.inc.c"
#include "main_menu_vpk0/sprites/802DF3F0.inc.c"
#include "main_menu_vpk0/sprites/802DFA70.inc.c"
#include "main_menu_vpk0/sprites/802DFAB0.inc.c"
#include "main_menu_vpk0/sprites/802DFAF4.inc.c"
#include "main_menu_vpk0/sprites/802DFB00.inc.c"
#include "main_menu_vpk0/sprites/802DFB08.inc.c"
#include "main_menu_vpk0/sprites/802E0B08.inc.c"
#include "main_menu_vpk0/sprites/802E0B10.inc.c"
#include "main_menu_vpk0/sprites/802E1B10.inc.c"
#include "main_menu_vpk0/sprites/802E1B18.inc.c"
#include "main_menu_vpk0/sprites/802E2B18.inc.c"
#include "main_menu_vpk0/sprites/802E2B20.inc.c"
#include "main_menu_vpk0/sprites/802E3A20.inc.c"
#include "main_menu_vpk0/sprites/802E3A28.inc.c"
#include "main_menu_vpk0/sprites/802E4A28.inc.c"
#include "main_menu_vpk0/sprites/802E4A30.inc.c"
#include "main_menu_vpk0/sprites/802E5A30.inc.c"
#include "main_menu_vpk0/sprites/802E5A38.inc.c"
#include "main_menu_vpk0/sprites/802E6A38.inc.c"
#include "main_menu_vpk0/sprites/802E6A40.inc.c"
#include "main_menu_vpk0/sprites/802E7940.inc.c"
#include "main_menu_vpk0/sprites/802E7948.inc.c"
#include "main_menu_vpk0/sprites/802E7E48.inc.c"
#include "main_menu_vpk0/sprites/802E7E50.inc.c"
#include "main_menu_vpk0/sprites/802E8350.inc.c"
#include "main_menu_vpk0/sprites/802E8358.inc.c"
#include "main_menu_vpk0/sprites/802E8858.inc.c"
#include "main_menu_vpk0/sprites/802E8860.inc.c"
#include "main_menu_vpk0/sprites/802E8D10.inc.c"
#include "main_menu_vpk0/sprites/802E8DD0.inc.c"
#include "main_menu_vpk0/sprites/802E8E14.inc.c"
#include "main_menu_vpk0/sprites/802E8E20.inc.c"
#include "main_menu_vpk0/sprites/802E8E28.inc.c"
#include "main_menu_vpk0/sprites/802E9E28.inc.c"
#include "main_menu_vpk0/sprites/802E9E30.inc.c"
#include "main_menu_vpk0/sprites/802EAE30.inc.c"
#include "main_menu_vpk0/sprites/802EAE38.inc.c"
#include "main_menu_vpk0/sprites/802EBE38.inc.c"
#include "main_menu_vpk0/sprites/802EBE40.inc.c"
#include "main_menu_vpk0/sprites/802ECD40.inc.c"
#include "main_menu_vpk0/sprites/802ECD48.inc.c"
#include "main_menu_vpk0/sprites/802EDD48.inc.c"
#include "main_menu_vpk0/sprites/802EDD50.inc.c"
#include "main_menu_vpk0/sprites/802EED50.inc.c"
#include "main_menu_vpk0/sprites/802EED58.inc.c"
#include "main_menu_vpk0/sprites/802EFD58.inc.c"
#include "main_menu_vpk0/sprites/802EFD60.inc.c"
#include "main_menu_vpk0/sprites/802F0C60.inc.c"
#include "main_menu_vpk0/sprites/802F0C68.inc.c"
#include "main_menu_vpk0/sprites/802F1168.inc.c"
#include "main_menu_vpk0/sprites/802F1170.inc.c"
#include "main_menu_vpk0/sprites/802F1670.inc.c"
#include "main_menu_vpk0/sprites/802F1678.inc.c"
#include "main_menu_vpk0/sprites/802F1B78.inc.c"
#include "main_menu_vpk0/sprites/802F1B80.inc.c"
#include "main_menu_vpk0/sprites/802F2030.inc.c"
#include "main_menu_vpk0/sprites/802F20F0.inc.c"
#include "main_menu_vpk0/sprites/802F2134.inc.c"
#include "main_menu_vpk0/sprites/802F2148.inc.c"
#include "main_menu_vpk0/sprites/802F2748.inc.c"
#include "main_menu_vpk0/sprites/802F2750.inc.c"
#include "main_menu_vpk0/sprites/802F2D50.inc.c"
#include "main_menu_vpk0/sprites/802F2D58.inc.c"
#include "main_menu_vpk0/sprites/802F3358.inc.c"
#include "main_menu_vpk0/sprites/802F3360.inc.c"
#include "main_menu_vpk0/sprites/802F3960.inc.c"
#include "main_menu_vpk0/sprites/802F3968.inc.c"
#include "main_menu_vpk0/sprites/802F3F68.inc.c"
#include "main_menu_vpk0/sprites/802F3F70.inc.c"
#include "main_menu_vpk0/sprites/802F4570.inc.c"
#include "main_menu_vpk0/sprites/802F4578.inc.c"
#include "main_menu_vpk0/sprites/802F47B8.inc.c"
#include "main_menu_vpk0/sprites/802F4828.inc.c"
#include "main_menu_vpk0/sprites/802F486C.inc.c"
#include "main_menu_vpk0/sprites/802F4878.inc.c"
#include "main_menu_vpk0/sprites/802F4D78.inc.c"
#include "main_menu_vpk0/sprites/802F4D80.inc.c"
#include "main_menu_vpk0/sprites/802F5280.inc.c"
#include "main_menu_vpk0/sprites/802F5288.inc.c"
#include "main_menu_vpk0/sprites/802F5788.inc.c"
#include "main_menu_vpk0/sprites/802F5790.inc.c"
#include "main_menu_vpk0/sprites/802F5B50.inc.c"
#include "main_menu_vpk0/sprites/802F5B90.inc.c"
#include "main_menu_vpk0/sprites/802F5BD4.inc.c"
#include "main_menu_vpk0/sprites/802F5BE8.inc.c"
#include "main_menu_vpk0/sprites/802F6028.inc.c"
#include "main_menu_vpk0/sprites/802F6030.inc.c"
#include "main_menu_vpk0/sprites/802F6470.inc.c"
#include "main_menu_vpk0/sprites/802F6490.inc.c"
#include "main_menu_vpk0/sprites/802F64D4.inc.c"
#include "main_menu_vpk0/sprites/802F64E0.inc.c"
#include "main_menu_vpk0/sprites/802F64E8.inc.c"
#include "main_menu_vpk0/sprites/802F6768.inc.c"
#include "main_menu_vpk0/sprites/802F6770.inc.c"
#include "main_menu_vpk0/sprites/802F69F0.inc.c"
#include "main_menu_vpk0/sprites/802F69F8.inc.c"
#include "main_menu_vpk0/sprites/802F6C78.inc.c"
#include "main_menu_vpk0/sprites/802F6C80.inc.c"
#include "main_menu_vpk0/sprites/802F6F00.inc.c"
#include "main_menu_vpk0/sprites/802F6F08.inc.c"
#include "main_menu_vpk0/sprites/802F7188.inc.c"
#include "main_menu_vpk0/sprites/802F7190.inc.c"
#include "main_menu_vpk0/sprites/802F7280.inc.c"
#include "main_menu_vpk0/sprites/802F7288.inc.c"
#include "main_menu_vpk0/sprites/802F7508.inc.c"
#include "main_menu_vpk0/sprites/802F7510.inc.c"
#include "main_menu_vpk0/sprites/802F7790.inc.c"
#include "main_menu_vpk0/sprites/802F7798.inc.c"
#include "main_menu_vpk0/sprites/802F7A18.inc.c"
#include "main_menu_vpk0/sprites/802F7A20.inc.c"
#include "main_menu_vpk0/sprites/802F7CA0.inc.c"
#include "main_menu_vpk0/sprites/802F7CA8.inc.c"
#include "main_menu_vpk0/sprites/802F7F28.inc.c"
#include "main_menu_vpk0/sprites/802F7F30.inc.c"
#include "main_menu_vpk0/sprites/802F8020.inc.c"
#include "main_menu_vpk0/sprites/802F8028.inc.c"
#include "main_menu_vpk0/sprites/802F8068.inc.c"
#include "main_menu_vpk0/sprites/802F8070.inc.c"
#include "main_menu_vpk0/sprites/802F80B0.inc.c"
#include "main_menu_vpk0/sprites/802F80B8.inc.c"
#include "main_menu_vpk0/sprites/802F80F8.inc.c"
#include "main_menu_vpk0/sprites/802F8100.inc.c"
#include "main_menu_vpk0/sprites/802F8140.inc.c"
#include "main_menu_vpk0/sprites/802F8148.inc.c"
#include "main_menu_vpk0/sprites/802F8188.inc.c"
#include "main_menu_vpk0/sprites/802F8190.inc.c"
#include "main_menu_vpk0/sprites/802F81A8.inc.c"
#include "main_menu_vpk0/sprites/802F82C8.inc.c"
#include "main_menu_vpk0/sprites/802F830C.inc.c"
#include "main_menu_vpk0/sprites/802F8310.inc.c"
#include "main_menu_vpk0/sprites/802F8318.inc.c"
#include "main_menu_vpk0/sprites/802F9318.inc.c"
#include "main_menu_vpk0/sprites/802F9320.inc.c"
#include "main_menu_vpk0/sprites/802FA320.inc.c"
#include "main_menu_vpk0/sprites/802FA328.inc.c"
#include "main_menu_vpk0/sprites/802FB328.inc.c"
#include "main_menu_vpk0/sprites/802FB330.inc.c"
#include "main_menu_vpk0/sprites/802FC130.inc.c"
#include "main_menu_vpk0/sprites/802FC138.inc.c"
#include "main_menu_vpk0/sprites/802FD138.inc.c"
#include "main_menu_vpk0/sprites/802FD140.inc.c"
#include "main_menu_vpk0/sprites/802FE140.inc.c"
#include "main_menu_vpk0/sprites/802FE148.inc.c"
#include "main_menu_vpk0/sprites/802FF148.inc.c"
#include "main_menu_vpk0/sprites/802FF150.inc.c"
#include "main_menu_vpk0/sprites/802FFF50.inc.c"
#include "main_menu_vpk0/sprites/802FFF58.inc.c"
#include "main_menu_vpk0/sprites/80300F58.inc.c"
#include "main_menu_vpk0/sprites/80300F60.inc.c"
#include "main_menu_vpk0/sprites/80301F60.inc.c"
#include "main_menu_vpk0/sprites/80301F68.inc.c"
#include "main_menu_vpk0/sprites/80302F68.inc.c"
#include "main_menu_vpk0/sprites/80302F70.inc.c"
#include "main_menu_vpk0/sprites/80303D70.inc.c"
#include "main_menu_vpk0/sprites/80303D78.inc.c"
#include "main_menu_vpk0/sprites/80304278.inc.c"
#include "main_menu_vpk0/sprites/80304280.inc.c"
#include "main_menu_vpk0/sprites/80304780.inc.c"
#include "main_menu_vpk0/sprites/80304788.inc.c"
#include "main_menu_vpk0/sprites/80304C88.inc.c"
#include "main_menu_vpk0/sprites/80304C90.inc.c"
#include "main_menu_vpk0/sprites/803050F0.inc.c"
#include "main_menu_vpk0/sprites/803051F0.inc.c"
#include "main_menu_vpk0/sprites/80305234.inc.c"
#include "main_menu_vpk0/sprites/80305248.inc.c"
#include "main_menu_vpk0/sprites/80305A48.inc.c"
#include "main_menu_vpk0/sprites/80305A50.inc.c"
#include "main_menu_vpk0/sprites/80306250.inc.c"
#include "main_menu_vpk0/sprites/80306258.inc.c"
#include "main_menu_vpk0/sprites/80306A58.inc.c"
#include "main_menu_vpk0/sprites/80306A60.inc.c"
#include "main_menu_vpk0/sprites/80307260.inc.c"
#include "main_menu_vpk0/sprites/803072A0.inc.c"
#include "main_menu_vpk0/sprites/803072E4.inc.c"
#include "main_menu_vpk0/sprites/803072F8.inc.c"
#include "main_menu_vpk0/sprites/803076F8.inc.c"
#include "main_menu_vpk0/sprites/80307700.inc.c"
#include "main_menu_vpk0/sprites/80307B00.inc.c"
#include "main_menu_vpk0/sprites/80307B08.inc.c"
#include "main_menu_vpk0/sprites/80307F08.inc.c"
#include "main_menu_vpk0/sprites/80307F10.inc.c"
#include "main_menu_vpk0/sprites/80308310.inc.c"
#include "main_menu_vpk0/sprites/80308318.inc.c"
#include "main_menu_vpk0/sprites/80308718.inc.c"
#include "main_menu_vpk0/sprites/80308720.inc.c"
#include "main_menu_vpk0/sprites/803089A0.inc.c"
#include "main_menu_vpk0/sprites/80308A00.inc.c"
#include "main_menu_vpk0/sprites/80308A44.inc.c"
#include "main_menu_vpk0/sprites/80308A50.inc.c"
#include "main_menu_vpk0/sprites/80308A58.inc.c"
#include "main_menu_vpk0/sprites/80309258.inc.c"
#include "main_menu_vpk0/sprites/80309260.inc.c"
#include "main_menu_vpk0/sprites/80309660.inc.c"
#include "main_menu_vpk0/sprites/80309668.inc.c"
#include "main_menu_vpk0/sprites/803096E8.inc.c"
#include "main_menu_vpk0/sprites/803096F0.inc.c"
#include "main_menu_vpk0/sprites/80309730.inc.c"
#include "main_menu_vpk0/sprites/80309770.inc.c"
#include "main_menu_vpk0/sprites/803097B4.inc.c"
#include "main_menu_vpk0/sprites/803097C0.inc.c"
#include "main_menu_vpk0/sprites/803097C8.inc.c"
#include "main_menu_vpk0/sprites/80309FC8.inc.c"
#include "main_menu_vpk0/sprites/80309FD0.inc.c"
#include "main_menu_vpk0/sprites/8030A3D0.inc.c"
#include "main_menu_vpk0/sprites/8030A3D8.inc.c"
#include "main_menu_vpk0/sprites/8030A458.inc.c"
#include "main_menu_vpk0/sprites/8030A460.inc.c"
#include "main_menu_vpk0/sprites/8030A4A0.inc.c"
#include "main_menu_vpk0/sprites/8030A4E0.inc.c"
#include "main_menu_vpk0/sprites/8030A524.inc.c"
#include "main_menu_vpk0/sprites/8030A530.inc.c"
#include "main_menu_vpk0/sprites/8030A538.inc.c"
#include "main_menu_vpk0/sprites/8030AD38.inc.c"
#include "main_menu_vpk0/sprites/8030AD40.inc.c"
#include "main_menu_vpk0/sprites/8030B140.inc.c"
#include "main_menu_vpk0/sprites/8030B148.inc.c"
#include "main_menu_vpk0/sprites/8030B1C8.inc.c"
#include "main_menu_vpk0/sprites/8030B1D0.inc.c"
#include "main_menu_vpk0/sprites/8030B210.inc.c"
#include "main_menu_vpk0/sprites/8030B250.inc.c"
#include "main_menu_vpk0/sprites/8030B294.inc.c"
#include "main_menu_vpk0/sprites/8030B2A0.inc.c"
#include "main_menu_vpk0/sprites/8030B2A8.inc.c"
#include "main_menu_vpk0/sprites/8030BAA8.inc.c"
#include "main_menu_vpk0/sprites/8030BAB0.inc.c"
#include "main_menu_vpk0/sprites/8030BEB0.inc.c"
#include "main_menu_vpk0/sprites/8030BEB8.inc.c"
#include "main_menu_vpk0/sprites/8030BF38.inc.c"
#include "main_menu_vpk0/sprites/8030BF40.inc.c"
#include "main_menu_vpk0/sprites/8030BF80.inc.c"
#include "main_menu_vpk0/sprites/8030BFC0.inc.c"
#include "main_menu_vpk0/sprites/8030C004.inc.c"
#include "main_menu_vpk0/sprites/8030C010.inc.c"
#include "main_menu_vpk0/sprites/8030C018.inc.c"
#include "main_menu_vpk0/sprites/8030D118.inc.c"
#include "main_menu_vpk0/sprites/8030D120.inc.c"
#include "main_menu_vpk0/sprites/8030E000.inc.c"
#include "main_menu_vpk0/sprites/8030E020.inc.c"
#include "main_menu_vpk0/sprites/8030E064.inc.c"
#include "main_menu_vpk0/sprites/8030E070.inc.c"
#include "main_menu_vpk0/sprites/8030E078.inc.c"
#include "main_menu_vpk0/sprites/8030F178.inc.c"
#include "main_menu_vpk0/sprites/8030F180.inc.c"
#include "main_menu_vpk0/sprites/80310060.inc.c"
#include "main_menu_vpk0/sprites/80310080.inc.c"
#include "main_menu_vpk0/sprites/803100C4.inc.c"
#include "main_menu_vpk0/sprites/803100D0.inc.c"
#include "main_menu_vpk0/sprites/803100D8.inc.c"
#include "main_menu_vpk0/sprites/803111D8.inc.c"
#include "main_menu_vpk0/sprites/803111E0.inc.c"
#include "main_menu_vpk0/sprites/803120C0.inc.c"
#include "main_menu_vpk0/sprites/803120E0.inc.c"
#include "main_menu_vpk0/sprites/80312124.inc.c"
#include "main_menu_vpk0/sprites/80312138.inc.c"
#include "main_menu_vpk0/sprites/80312228.inc.c"
#include "main_menu_vpk0/sprites/80312238.inc.c"
#include "main_menu_vpk0/sprites/8031227C.inc.c"
#include "main_menu_vpk0/sprites/80312288.inc.c"
#include "main_menu_vpk0/sprites/80312348.inc.c"
#include "main_menu_vpk0/sprites/80312350.inc.c"
#include "main_menu_vpk0/sprites/80312410.inc.c"
#include "main_menu_vpk0/sprites/80312418.inc.c"
#include "main_menu_vpk0/sprites/803124D8.inc.c"
#include "main_menu_vpk0/sprites/803124E0.inc.c"
#include "main_menu_vpk0/sprites/803125A0.inc.c"
#include "main_menu_vpk0/sprites/803125A8.inc.c"
#include "main_menu_vpk0/sprites/80312668.inc.c"
#include "main_menu_vpk0/sprites/80312670.inc.c"
#include "main_menu_vpk0/sprites/80312730.inc.c"
#include "main_menu_vpk0/sprites/80312738.inc.c"
#include "main_menu_vpk0/sprites/803127F8.inc.c"
#include "main_menu_vpk0/sprites/80312800.inc.c"
#include "main_menu_vpk0/sprites/80312860.inc.c"
#include "main_menu_vpk0/sprites/803128E0.inc.c"
#include "main_menu_vpk0/sprites/80312924.inc.c"
#include "main_menu_vpk0/sprites/80312938.inc.c"
#include "main_menu_vpk0/sprites/803130B8.inc.c"
#include "main_menu_vpk0/sprites/803130C0.inc.c"
#include "main_menu_vpk0/sprites/80313840.inc.c"
#include "main_menu_vpk0/sprites/80313848.inc.c"
#include "main_menu_vpk0/sprites/80313FC8.inc.c"
#include "main_menu_vpk0/sprites/80313FD0.inc.c"
#include "main_menu_vpk0/sprites/80314750.inc.c"
#include "main_menu_vpk0/sprites/80314758.inc.c"
#include "main_menu_vpk0/sprites/80314ED8.inc.c"
#include "main_menu_vpk0/sprites/80314EE0.inc.c"
#include "main_menu_vpk0/sprites/80315660.inc.c"
#include "main_menu_vpk0/sprites/80315668.inc.c"
#include "main_menu_vpk0/sprites/80315DE8.inc.c"
#include "main_menu_vpk0/sprites/80315DF0.inc.c"
#include "main_menu_vpk0/sprites/803161B0.inc.c"
#include "main_menu_vpk0/sprites/80316230.inc.c"
#include "main_menu_vpk0/sprites/80316274.inc.c"
#include "main_menu_vpk0/sprites/80316288.inc.c"
#include "main_menu_vpk0/sprites/80316A08.inc.c"
#include "main_menu_vpk0/sprites/80316A10.inc.c"
#include "main_menu_vpk0/sprites/80317190.inc.c"
#include "main_menu_vpk0/sprites/80317198.inc.c"
#include "main_menu_vpk0/sprites/80317918.inc.c"
#include "main_menu_vpk0/sprites/80317920.inc.c"
#include "main_menu_vpk0/sprites/803180A0.inc.c"
#include "main_menu_vpk0/sprites/803180A8.inc.c"
#include "main_menu_vpk0/sprites/80318828.inc.c"
#include "main_menu_vpk0/sprites/80318830.inc.c"
#include "main_menu_vpk0/sprites/80318FB0.inc.c"
#include "main_menu_vpk0/sprites/80318FB8.inc.c"
#include "main_menu_vpk0/sprites/80319738.inc.c"
#include "main_menu_vpk0/sprites/80319740.inc.c"
#include "main_menu_vpk0/sprites/80319B00.inc.c"
#include "main_menu_vpk0/sprites/80319B80.inc.c"
#include "main_menu_vpk0/sprites/80319BC4.inc.c"
#include "main_menu_vpk0/sprites/80319BD8.inc.c"
#include "main_menu_vpk0/sprites/8031A358.inc.c"
#include "main_menu_vpk0/sprites/8031A360.inc.c"
#include "main_menu_vpk0/sprites/8031AAE0.inc.c"
#include "main_menu_vpk0/sprites/8031AAE8.inc.c"
#include "main_menu_vpk0/sprites/8031B268.inc.c"
#include "main_menu_vpk0/sprites/8031B270.inc.c"
#include "main_menu_vpk0/sprites/8031B9F0.inc.c"
#include "main_menu_vpk0/sprites/8031B9F8.inc.c"
#include "main_menu_vpk0/sprites/8031C178.inc.c"
#include "main_menu_vpk0/sprites/8031C180.inc.c"
#include "main_menu_vpk0/sprites/8031C900.inc.c"
#include "main_menu_vpk0/sprites/8031C908.inc.c"
#include "main_menu_vpk0/sprites/8031D088.inc.c"
#include "main_menu_vpk0/sprites/8031D090.inc.c"
#include "main_menu_vpk0/sprites/8031D450.inc.c"
#include "main_menu_vpk0/sprites/8031D4D0.inc.c"
#include "main_menu_vpk0/sprites/8031D514.inc.c"
#include "main_menu_vpk0/sprites/8031D528.inc.c"
#include "main_menu_vpk0/sprites/8031DCA8.inc.c"
#include "main_menu_vpk0/sprites/8031DCB0.inc.c"
#include "main_menu_vpk0/sprites/8031E430.inc.c"
#include "main_menu_vpk0/sprites/8031E438.inc.c"
#include "main_menu_vpk0/sprites/8031EBB8.inc.c"
#include "main_menu_vpk0/sprites/8031EBC0.inc.c"
#include "main_menu_vpk0/sprites/8031F340.inc.c"
#include "main_menu_vpk0/sprites/8031F348.inc.c"
#include "main_menu_vpk0/sprites/8031FAC8.inc.c"
#include "main_menu_vpk0/sprites/8031FAD0.inc.c"
#include "main_menu_vpk0/sprites/80320250.inc.c"
#include "main_menu_vpk0/sprites/80320258.inc.c"
#include "main_menu_vpk0/sprites/803209D8.inc.c"
#include "main_menu_vpk0/sprites/803209E0.inc.c"
#include "main_menu_vpk0/sprites/80320DA0.inc.c"
#include "main_menu_vpk0/sprites/80320E20.inc.c"
#include "main_menu_vpk0/sprites/80320E64.inc.c"
#include "main_menu_vpk0/sprites/80320E78.inc.c"
#include "main_menu_vpk0/sprites/803215F8.inc.c"
#include "main_menu_vpk0/sprites/80321600.inc.c"
#include "main_menu_vpk0/sprites/80321D80.inc.c"
#include "main_menu_vpk0/sprites/80321D88.inc.c"
#include "main_menu_vpk0/sprites/80322508.inc.c"
#include "main_menu_vpk0/sprites/80322510.inc.c"
#include "main_menu_vpk0/sprites/80322C90.inc.c"
#include "main_menu_vpk0/sprites/80322C98.inc.c"
#include "main_menu_vpk0/sprites/80323418.inc.c"
#include "main_menu_vpk0/sprites/80323420.inc.c"
#include "main_menu_vpk0/sprites/80323BA0.inc.c"
#include "main_menu_vpk0/sprites/80323BA8.inc.c"
#include "main_menu_vpk0/sprites/80324328.inc.c"
#include "main_menu_vpk0/sprites/80324330.inc.c"
#include "main_menu_vpk0/sprites/803246F0.inc.c"
#include "main_menu_vpk0/sprites/80324770.inc.c"
#include "main_menu_vpk0/sprites/803247B4.inc.c"
#include "main_menu_vpk0/sprites/803247C8.inc.c"
#include "main_menu_vpk0/sprites/80324F48.inc.c"
#include "main_menu_vpk0/sprites/80324F50.inc.c"
#include "main_menu_vpk0/sprites/803256D0.inc.c"
#include "main_menu_vpk0/sprites/803256D8.inc.c"
#include "main_menu_vpk0/sprites/80325E58.inc.c"
#include "main_menu_vpk0/sprites/80325E60.inc.c"
#include "main_menu_vpk0/sprites/803265E0.inc.c"
#include "main_menu_vpk0/sprites/803265E8.inc.c"
#include "main_menu_vpk0/sprites/80326D68.inc.c"
#include "main_menu_vpk0/sprites/80326D70.inc.c"
#include "main_menu_vpk0/sprites/803274F0.inc.c"
#include "main_menu_vpk0/sprites/803274F8.inc.c"
#include "main_menu_vpk0/sprites/80327C78.inc.c"
#include "main_menu_vpk0/sprites/80327C80.inc.c"
#include "main_menu_vpk0/sprites/80328040.inc.c"
#include "main_menu_vpk0/sprites/803280C0.inc.c"
#include "main_menu_vpk0/sprites/80328104.inc.c"
#include "main_menu_vpk0/sprites/80328118.inc.c"
#include "main_menu_vpk0/sprites/80328898.inc.c"
#include "main_menu_vpk0/sprites/803288A0.inc.c"
#include "main_menu_vpk0/sprites/80329020.inc.c"
#include "main_menu_vpk0/sprites/80329028.inc.c"
#include "main_menu_vpk0/sprites/803297A8.inc.c"
#include "main_menu_vpk0/sprites/803297B0.inc.c"
#include "main_menu_vpk0/sprites/80329F30.inc.c"
#include "main_menu_vpk0/sprites/80329F38.inc.c"
#include "main_menu_vpk0/sprites/8032A6B8.inc.c"
#include "main_menu_vpk0/sprites/8032A6C0.inc.c"
#include "main_menu_vpk0/sprites/8032AE40.inc.c"
#include "main_menu_vpk0/sprites/8032AE48.inc.c"
#include "main_menu_vpk0/sprites/8032B5C8.inc.c"
#include "main_menu_vpk0/sprites/8032B5D0.inc.c"
#include "main_menu_vpk0/sprites/8032B990.inc.c"
#include "main_menu_vpk0/sprites/8032BA10.inc.c"
#include "main_menu_vpk0/sprites/8032BA54.inc.c"
#include "main_menu_vpk0/sprites/8032BA68.inc.c"
#include "main_menu_vpk0/sprites/8032C1E8.inc.c"
#include "main_menu_vpk0/sprites/8032C1F0.inc.c"
#include "main_menu_vpk0/sprites/8032C970.inc.c"
#include "main_menu_vpk0/sprites/8032C978.inc.c"
#include "main_menu_vpk0/sprites/8032D0F8.inc.c"
#include "main_menu_vpk0/sprites/8032D100.inc.c"
#include "main_menu_vpk0/sprites/8032D880.inc.c"
#include "main_menu_vpk0/sprites/8032D888.inc.c"
#include "main_menu_vpk0/sprites/8032E008.inc.c"
#include "main_menu_vpk0/sprites/8032E010.inc.c"
#include "main_menu_vpk0/sprites/8032E790.inc.c"
#include "main_menu_vpk0/sprites/8032E798.inc.c"
#include "main_menu_vpk0/sprites/8032EF18.inc.c"
#include "main_menu_vpk0/sprites/8032EF20.inc.c"
#include "main_menu_vpk0/sprites/8032F2E0.inc.c"
#include "main_menu_vpk0/sprites/8032F360.inc.c"
#include "main_menu_vpk0/sprites/8032F3A4.inc.c"
#include "main_menu_vpk0/sprites/8032F3B8.inc.c"
#include "main_menu_vpk0/sprites/8032FB38.inc.c"
#include "main_menu_vpk0/sprites/8032FB40.inc.c"
#include "main_menu_vpk0/sprites/803302C0.inc.c"
#include "main_menu_vpk0/sprites/803302C8.inc.c"
#include "main_menu_vpk0/sprites/80330A48.inc.c"
#include "main_menu_vpk0/sprites/80330A50.inc.c"
#include "main_menu_vpk0/sprites/803311D0.inc.c"
#include "main_menu_vpk0/sprites/803311D8.inc.c"
#include "main_menu_vpk0/sprites/80331958.inc.c"
#include "main_menu_vpk0/sprites/80331960.inc.c"
#include "main_menu_vpk0/sprites/803320E0.inc.c"
#include "main_menu_vpk0/sprites/803320E8.inc.c"
#include "main_menu_vpk0/sprites/80332868.inc.c"
#include "main_menu_vpk0/sprites/80332870.inc.c"
#include "main_menu_vpk0/sprites/80332C30.inc.c"
#include "main_menu_vpk0/sprites/80332CB0.inc.c"
#include "main_menu_vpk0/sprites/80332CF4.inc.c"
#include "main_menu_vpk0/sprites/80332D08.inc.c"
#include "main_menu_vpk0/sprites/80333488.inc.c"
#include "main_menu_vpk0/sprites/80333490.inc.c"
#include "main_menu_vpk0/sprites/80333C10.inc.c"
#include "main_menu_vpk0/sprites/80333C18.inc.c"
#include "main_menu_vpk0/sprites/80334398.inc.c"
#include "main_menu_vpk0/sprites/803343A0.inc.c"
#include "main_menu_vpk0/sprites/80334B20.inc.c"
#include "main_menu_vpk0/sprites/80334B28.inc.c"
#include "main_menu_vpk0/sprites/803352A8.inc.c"
#include "main_menu_vpk0/sprites/803352B0.inc.c"
#include "main_menu_vpk0/sprites/80335A30.inc.c"
#include "main_menu_vpk0/sprites/80335A38.inc.c"
#include "main_menu_vpk0/sprites/803361B8.inc.c"
#include "main_menu_vpk0/sprites/803361C0.inc.c"
#include "main_menu_vpk0/sprites/80336580.inc.c"
#include "main_menu_vpk0/sprites/80336600.inc.c"
#include "main_menu_vpk0/sprites/80336644.inc.c"
#include "main_menu_vpk0/sprites/80336658.inc.c"
#include "main_menu_vpk0/sprites/80336DD8.inc.c"
#include "main_menu_vpk0/sprites/80336DE0.inc.c"
#include "main_menu_vpk0/sprites/80337560.inc.c"
#include "main_menu_vpk0/sprites/80337568.inc.c"
#include "main_menu_vpk0/sprites/80337CE8.inc.c"
#include "main_menu_vpk0/sprites/80337CF0.inc.c"
#include "main_menu_vpk0/sprites/80338470.inc.c"
#include "main_menu_vpk0/sprites/80338478.inc.c"
#include "main_menu_vpk0/sprites/80338BF8.inc.c"
#include "main_menu_vpk0/sprites/80338C00.inc.c"
#include "main_menu_vpk0/sprites/80339380.inc.c"
#include "main_menu_vpk0/sprites/80339388.inc.c"
#include "main_menu_vpk0/sprites/80339B08.inc.c"
#include "main_menu_vpk0/sprites/80339B10.inc.c"
#include "main_menu_vpk0/sprites/80339ED0.inc.c"
#include "main_menu_vpk0/sprites/80339F50.inc.c"
#include "main_menu_vpk0/sprites/80339F94.inc.c"
#include "main_menu_vpk0/sprites/80339FA8.inc.c"
#include "main_menu_vpk0/sprites/8033A728.inc.c"
#include "main_menu_vpk0/sprites/8033A730.inc.c"
#include "main_menu_vpk0/sprites/8033AEB0.inc.c"
#include "main_menu_vpk0/sprites/8033AEB8.inc.c"
#include "main_menu_vpk0/sprites/8033B638.inc.c"
#include "main_menu_vpk0/sprites/8033B640.inc.c"
#include "main_menu_vpk0/sprites/8033BDC0.inc.c"
#include "main_menu_vpk0/sprites/8033BDC8.inc.c"
#include "main_menu_vpk0/sprites/8033C548.inc.c"
#include "main_menu_vpk0/sprites/8033C550.inc.c"
#include "main_menu_vpk0/sprites/8033CCD0.inc.c"
#include "main_menu_vpk0/sprites/8033CCD8.inc.c"
#include "main_menu_vpk0/sprites/8033D458.inc.c"
#include "main_menu_vpk0/sprites/8033D460.inc.c"
#include "main_menu_vpk0/sprites/8033D820.inc.c"
#include "main_menu_vpk0/sprites/8033D8A0.inc.c"
#include "main_menu_vpk0/sprites/8033D8E4.inc.c"
#include "main_menu_vpk0/sprites/8033D8F8.inc.c"
#include "main_menu_vpk0/sprites/8033DB78.inc.c"
#include "main_menu_vpk0/sprites/8033DB80.inc.c"
#include "main_menu_vpk0/sprites/8033DE00.inc.c"
#include "main_menu_vpk0/sprites/8033DE08.inc.c"
#include "main_menu_vpk0/sprites/8033E088.inc.c"
#include "main_menu_vpk0/sprites/8033E090.inc.c"
#include "main_menu_vpk0/sprites/8033E1D0.inc.c"
#include "main_menu_vpk0/sprites/8033E210.inc.c"
#include "main_menu_vpk0/sprites/8033E254.inc.c"
#include "main_menu_vpk0/sprites/8033E268.inc.c"
#include "main_menu_vpk0/sprites/8033E4E8.inc.c"
#include "main_menu_vpk0/sprites/8033E4F0.inc.c"
#include "main_menu_vpk0/sprites/8033E770.inc.c"
#include "main_menu_vpk0/sprites/8033E778.inc.c"
#include "main_menu_vpk0/sprites/8033E908.inc.c"
#include "main_menu_vpk0/sprites/8033E938.inc.c"
#include "main_menu_vpk0/sprites/8033E97C.inc.c"
#include "main_menu_vpk0/sprites/8033E988.inc.c"
#include "main_menu_vpk0/sprites/8033EC08.inc.c"
#include "main_menu_vpk0/sprites/8033EC10.inc.c"
#include "main_menu_vpk0/sprites/8033ECB0.inc.c"
#include "main_menu_vpk0/sprites/8033ECD0.inc.c"
#include "main_menu_vpk0/sprites/8033ED14.inc.c"
#include "main_menu_vpk0/sprites/8033ED28.inc.c"
#include "main_menu_vpk0/sprites/8033ED60.inc.c"
#include "main_menu_vpk0/sprites/8033ED70.inc.c"
#include "main_menu_vpk0/sprites/8033EDB4.inc.c"
#include "main_menu_vpk0/sprites/8033EDC8.inc.c"
#include "main_menu_vpk0/sprites/8033F048.inc.c"
#include "main_menu_vpk0/sprites/8033F050.inc.c"
#include "main_menu_vpk0/sprites/8033F2D0.inc.c"
#include "main_menu_vpk0/sprites/8033F2D8.inc.c"
#include "main_menu_vpk0/sprites/8033F468.inc.c"
#include "main_menu_vpk0/sprites/8033F498.inc.c"
#include "main_menu_vpk0/sprites/8033F4DC.inc.c"
#include "main_menu_vpk0/sprites/8033F4E8.inc.c"
#include "main_menu_vpk0/sprites/8033F768.inc.c"
#include "main_menu_vpk0/sprites/8033F770.inc.c"
#include "main_menu_vpk0/sprites/8033F9F0.inc.c"
#include "main_menu_vpk0/sprites/8033F9F8.inc.c"
#include "main_menu_vpk0/sprites/8033FB88.inc.c"
#include "main_menu_vpk0/sprites/8033FBB8.inc.c"
#include "main_menu_vpk0/sprites/8033FBFC.inc.c"
#include "main_menu_vpk0/sprites/8033FC00.inc.c"
#include "main_menu_vpk0/sprites/8033FC08.inc.c"
#include "main_menu_vpk0/sprites/80340108.inc.c"
#include "main_menu_vpk0/sprites/80340110.inc.c"
#include "main_menu_vpk0/sprites/80340610.inc.c"
#include "main_menu_vpk0/sprites/80340618.inc.c"
#include "main_menu_vpk0/sprites/80340B18.inc.c"
#include "main_menu_vpk0/sprites/80340B20.inc.c"
#include "main_menu_vpk0/sprites/80340EE0.inc.c"
#include "main_menu_vpk0/sprites/80340EE8.inc.c"
#include "main_menu_vpk0/sprites/80340F68.inc.c"
#include "main_menu_vpk0/sprites/80340F70.inc.c"
#include "main_menu_vpk0/sprites/80340FF0.inc.c"
#include "main_menu_vpk0/sprites/80340FF8.inc.c"
#include "main_menu_vpk0/sprites/80341078.inc.c"
#include "main_menu_vpk0/sprites/80341080.inc.c"
#include "main_menu_vpk0/sprites/803410E0.inc.c"
#include "main_menu_vpk0/sprites/80341160.inc.c"
#include "main_menu_vpk0/sprites/803411A4.inc.c"
#include "main_menu_vpk0/sprites/803411B8.inc.c"
#include "main_menu_vpk0/sprites/803414F8.inc.c"
#include "main_menu_vpk0/sprites/80341500.inc.c"
#include "main_menu_vpk0/sprites/80341770.inc.c"
#include "main_menu_vpk0/sprites/80341790.inc.c"
#include "main_menu_vpk0/sprites/803417D4.inc.c"
#include "main_menu_vpk0/sprites/803417E8.inc.c"
#include "main_menu_vpk0/sprites/80341A68.inc.c"
#include "main_menu_vpk0/sprites/80341A70.inc.c"
#include "main_menu_vpk0/sprites/80341C50.inc.c"
#include "main_menu_vpk0/sprites/80341C70.inc.c"
#include "main_menu_vpk0/sprites/80341CB4.inc.c"
#include "main_menu_vpk0/sprites/80341CC8.inc.c"
#include "main_menu_vpk0/sprites/80341F48.inc.c"
#include "main_menu_vpk0/sprites/80341F50.inc.c"
#include "main_menu_vpk0/sprites/80342130.inc.c"
#include "main_menu_vpk0/sprites/80342150.inc.c"
#include "main_menu_vpk0/sprites/80342194.inc.c"
#include "main_menu_vpk0/sprites/803421A8.inc.c"
#include "main_menu_vpk0/sprites/80342428.inc.c"
#include "main_menu_vpk0/sprites/80342430.inc.c"
#include "main_menu_vpk0/sprites/80342610.inc.c"
#include "main_menu_vpk0/sprites/80342630.inc.c"
#include "main_menu_vpk0/sprites/80342674.inc.c"
#include "main_menu_vpk0/sprites/80342688.inc.c"
#include "main_menu_vpk0/sprites/80342908.inc.c"
#include "main_menu_vpk0/sprites/80342910.inc.c"
#include "main_menu_vpk0/sprites/80342AF0.inc.c"
#include "main_menu_vpk0/sprites/80342B10.inc.c"
#include "main_menu_vpk0/sprites/80342B54.inc.c"
#include "main_menu_vpk0/sprites/80342B68.inc.c"
#include "main_menu_vpk0/sprites/80342DE8.inc.c"
#include "main_menu_vpk0/sprites/80342DF0.inc.c"
#include "main_menu_vpk0/sprites/80342FD0.inc.c"
#include "main_menu_vpk0/sprites/80342FF0.inc.c"
#include "main_menu_vpk0/sprites/80343034.inc.c"
#include "main_menu_vpk0/sprites/80343048.inc.c"
#include "main_menu_vpk0/sprites/803432C8.inc.c"
#include "main_menu_vpk0/sprites/803432D0.inc.c"
#include "main_menu_vpk0/sprites/803434B0.inc.c"
#include "main_menu_vpk0/sprites/803434D0.inc.c"
#include "main_menu_vpk0/sprites/80343514.inc.c"
#include "main_menu_vpk0/sprites/80343520.inc.c"
#include "main_menu_vpk0/sprites/80343528.inc.c"
#include "main_menu_vpk0/sprites/80343B18.inc.c"
#include "main_menu_vpk0/sprites/80343B28.inc.c"
#include "main_menu_vpk0/sprites/80343B6C.inc.c"
#include "main_menu_vpk0/sprites/80343B70.inc.c"
#include "main_menu_vpk0/sprites/80343B78.inc.c"
#include "main_menu_vpk0/sprites/80343BF8.inc.c"
#include "main_menu_vpk0/sprites/80343C08.inc.c"
#include "main_menu_vpk0/sprites/80343C4C.inc.c"
#include "main_menu_vpk0/sprites/80343C50.inc.c"
#include "main_menu_vpk0/sprites/80343C58.inc.c"
#include "main_menu_vpk0/sprites/80343D18.inc.c"
#include "main_menu_vpk0/sprites/80343D20.inc.c"
#include "main_menu_vpk0/sprites/80343DE0.inc.c"
#include "main_menu_vpk0/sprites/80343DE8.inc.c"
#include "main_menu_vpk0/sprites/80343EA8.inc.c"
#include "main_menu_vpk0/sprites/80343EB0.inc.c"
#include "main_menu_vpk0/sprites/80343F70.inc.c"
#include "main_menu_vpk0/sprites/80343F78.inc.c"
#include "main_menu_vpk0/sprites/80344038.inc.c"
#include "main_menu_vpk0/sprites/80344040.inc.c"
#include "main_menu_vpk0/sprites/80344100.inc.c"
#include "main_menu_vpk0/sprites/80344108.inc.c"
#include "main_menu_vpk0/sprites/803441C8.inc.c"
#include "main_menu_vpk0/sprites/803441D0.inc.c"
#include "main_menu_vpk0/sprites/80344290.inc.c"
#include "main_menu_vpk0/sprites/80344298.inc.c"
#include "main_menu_vpk0/sprites/803442F8.inc.c"
#include "main_menu_vpk0/sprites/80344388.inc.c"
#include "main_menu_vpk0/sprites/803443CC.inc.c"
#include "main_menu_vpk0/sprites/803443D0.inc.c"
#include "main_menu_vpk0/sprites/803443D8.inc.c"
#include "main_menu_vpk0/sprites/803444C8.inc.c"
#include "main_menu_vpk0/sprites/803444D8.inc.c"
#include "main_menu_vpk0/sprites/8034451C.inc.c"
#include "main_menu_vpk0/sprites/80344520.inc.c"
#include "main_menu_vpk0/sprites/80344528.inc.c"
#include "main_menu_vpk0/sprites/80344608.inc.c"
#include "main_menu_vpk0/sprites/80344618.inc.c"
#include "main_menu_vpk0/sprites/8034465C.inc.c"
#include "main_menu_vpk0/sprites/80344660.inc.c"
#include "main_menu_vpk0/sprites/80344668.inc.c"
#include "main_menu_vpk0/sprites/80345468.inc.c"
#include "main_menu_vpk0/sprites/80345470.inc.c"
#include "main_menu_vpk0/sprites/80346270.inc.c"
#include "main_menu_vpk0/sprites/80346278.inc.c"
#include "main_menu_vpk0/sprites/80347078.inc.c"
#include "main_menu_vpk0/sprites/80347080.inc.c"
#include "main_menu_vpk0/sprites/80347E80.inc.c"
#include "main_menu_vpk0/sprites/80347E88.inc.c"
#include "main_menu_vpk0/sprites/80348C88.inc.c"
#include "main_menu_vpk0/sprites/80348C90.inc.c"
#include "main_menu_vpk0/sprites/80349A90.inc.c"
#include "main_menu_vpk0/sprites/80349A98.inc.c"
#include "main_menu_vpk0/sprites/8034A898.inc.c"
#include "main_menu_vpk0/sprites/8034A8A0.inc.c"
#include "main_menu_vpk0/sprites/8034AFA0.inc.c"
#include "main_menu_vpk0/sprites/8034B020.inc.c"
#include "main_menu_vpk0/sprites/8034B064.inc.c"
#include "main_menu_vpk0/sprites/8034B078.inc.c"
#include "main_menu_vpk0/sprites/8034B4B8.inc.c"
#include "main_menu_vpk0/sprites/8034B4C0.inc.c"
#include "main_menu_vpk0/sprites/8034B900.inc.c"
#include "main_menu_vpk0/sprites/8034B920.inc.c"
#include "main_menu_vpk0/sprites/8034B964.inc.c"
#include "main_menu_vpk0/sprites/8034B978.inc.c"
#include "main_menu_vpk0/sprites/8034BBA8.inc.c"
#include "main_menu_vpk0/sprites/8034BBB8.inc.c"
#include "main_menu_vpk0/sprites/8034BBFC.inc.c"
#include "main_menu_vpk0/sprites/8034BC08.inc.c"
#include "main_menu_vpk0/sprites/8034C048.inc.c"
#include "main_menu_vpk0/sprites/8034C050.inc.c"
#include "main_menu_vpk0/sprites/8034C490.inc.c"
#include "main_menu_vpk0/sprites/8034C4B0.inc.c"
#include "main_menu_vpk0/sprites/8034C4F4.inc.c"
#include "main_menu_vpk0/sprites/8034C508.inc.c"
#include "main_menu_vpk0/sprites/8034C700.inc.c"
#include "main_menu_vpk0/sprites/8034C710.inc.c"
#include "main_menu_vpk0/sprites/8034C754.inc.c"
#include "main_menu_vpk0/sprites/8034C768.inc.c"
#include "main_menu_vpk0/sprites/8034C9A8.inc.c"
#include "main_menu_vpk0/sprites/8034C9B0.inc.c"
#include "main_menu_vpk0/sprites/8034CBF0.inc.c"
#include "main_menu_vpk0/sprites/8034CBF8.inc.c"
#include "main_menu_vpk0/sprites/8034CDA8.inc.c"
#include "main_menu_vpk0/sprites/8034CDB0.inc.c"
#include "main_menu_vpk0/sprites/8034CFB0.inc.c"
#include "main_menu_vpk0/sprites/8034CFB8.inc.c"
#include "main_menu_vpk0/sprites/8034D1B8.inc.c"
#include "main_menu_vpk0/sprites/8034D1C0.inc.c"
#include "main_menu_vpk0/sprites/8034D340.inc.c"
#include "main_menu_vpk0/sprites/8034D3A0.inc.c"
#include "main_menu_vpk0/sprites/8034D3E4.inc.c"
#include "main_menu_vpk0/sprites/8034D3F8.inc.c"
#include "main_menu_vpk0/sprites/8034D9F8.inc.c"
#include "main_menu_vpk0/sprites/8034DA00.inc.c"
#include "main_menu_vpk0/sprites/8034E000.inc.c"
#include "main_menu_vpk0/sprites/8034E008.inc.c"
#include "main_menu_vpk0/sprites/8034E608.inc.c"
#include "main_menu_vpk0/sprites/8034E610.inc.c"
#include "main_menu_vpk0/sprites/8034EC10.inc.c"
#include "main_menu_vpk0/sprites/8034EC18.inc.c"
#include "main_menu_vpk0/sprites/8034F218.inc.c"
#include "main_menu_vpk0/sprites/8034F220.inc.c"
#include "main_menu_vpk0/sprites/8034F820.inc.c"
#include "main_menu_vpk0/sprites/8034F828.inc.c"
#include "main_menu_vpk0/sprites/8034FA68.inc.c"
#include "main_menu_vpk0/sprites/8034FAD8.inc.c"
#include "main_menu_vpk0/sprites/8034FB1C.inc.c"
#include "main_menu_vpk0/models/8034FB20.inc.c"
#include "main_menu_vpk0/models/8034FB28.inc.c"
#include "main_menu_vpk0/models/80350328.inc.c"
#include "main_menu_vpk0/models/80350330.inc.c"
#include "main_menu_vpk0/models/80350B30.inc.c"
#include "main_menu_vpk0/models/80350B38.inc.c"
#include "main_menu_vpk0/models/80351338.inc.c"
#include "main_menu_vpk0/models/80351340.inc.c"
#include "main_menu_vpk0/models/80352340.inc.c"
#include "main_menu_vpk0/models/80352348.inc.c"
#include "main_menu_vpk0/models/80353348.inc.c"
#include "main_menu_vpk0/models/80353350.inc.c"
#include "main_menu_vpk0/models/80354350.inc.c"
#include "main_menu_vpk0/models/80354358.inc.c"
#include "main_menu_vpk0/models/80355358.inc.c"
#include "main_menu_vpk0/models/80355360.inc.c"
#include "main_menu_vpk0/models/80356360.inc.c"
#include "main_menu_vpk0/models/80356368.inc.c"
#include "main_menu_vpk0/models/80357368.inc.c"
#include "main_menu_vpk0/models/80357370.inc.c"
#include "main_menu_vpk0/models/80358370.inc.c"
#include "main_menu_vpk0/models/80358378.inc.c"
#include "main_menu_vpk0/models/80359378.inc.c"
#include "main_menu_vpk0/models/8035938C.inc.c"
#include "main_menu_vpk0/models/803593A0.inc.c"
#include "main_menu_vpk0/models/80359418.inc.c"
#include "main_menu_vpk0/models/80359430.inc.c"
#include "main_menu_vpk0/models/803594A8.inc.c"
#include "main_menu_vpk0/models/803594B0.inc.c"
#include "main_menu_vpk0/models/80359528.inc.c"
#include "main_menu_vpk0/models/80359530.inc.c"
#include "main_menu_vpk0/models/80359538.inc.c"
#include "main_menu_vpk0/models/80359540.inc.c"
#include "main_menu_vpk0/models/80359780.inc.c"
#include "main_menu_vpk0/models/80359860.inc.c"
#include "main_menu_vpk0/models/80359928.inc.c"
#include "main_menu_vpk0/models/803599F0.inc.c"
#include "main_menu_vpk0/models/80359A00.inc.c"
#include "main_menu_vpk0/models/80359A10.inc.c"
#include "main_menu_vpk0/models/80359A20.inc.c"
#include "main_menu_vpk0/models/80359B28.inc.c"
#include "main_menu_vpk0/animations/80359B30.inc.c"
#include "main_menu_vpk0/animations/80359B44.inc.c"
#include "main_menu_vpk0/animations/80359C60.inc.c"
#include "main_menu_vpk0/animations/80359C70.inc.c"
#include "main_menu_vpk0/animations/80359C80.inc.c"
#include "main_menu_vpk0/animations/80359C90.inc.c"
#include "main_menu_vpk0/animations/80359CC8.inc.c"
#include "main_menu_vpk0/animations/80359CD0.inc.c"
#include "main_menu_vpk0/animations/80359CE4.inc.c"
#include "main_menu_vpk0/animations/80359D80.inc.c"
#include "main_menu_vpk0/animations/8035A128.inc.c"
#include "main_menu_vpk0/animations/8035A290.inc.c"
#include "main_menu_vpk0/animations/8035A294.inc.c"
#include "main_menu_vpk0/animations/8035A298.inc.c"
#include "main_menu_vpk0/models/8035A29C.inc.c"
#include "main_menu_vpk0/models/8035A2A8.inc.c"
#include "main_menu_vpk0/models/8035D2A8.inc.c"
#include "main_menu_vpk0/models/8035D2B0.inc.c"
#include "main_menu_vpk0/models/8035D2F0.inc.c"
#include "main_menu_vpk0/models/8035D2F8.inc.c"
#include "main_menu_vpk0/models/8035E2F8.inc.c"
#include "main_menu_vpk0/models/8035E300.inc.c"
#include "main_menu_vpk0/models/8035E700.inc.c"
#include "main_menu_vpk0/models/8035E708.inc.c"
#include "main_menu_vpk0/models/8035E728.inc.c"
#include "main_menu_vpk0/models/8035E730.inc.c"
#include "main_menu_vpk0/models/8035F730.inc.c"
#include "main_menu_vpk0/models/8035F738.inc.c"
#include "main_menu_vpk0/models/8035F938.inc.c"
#include "main_menu_vpk0/models/8035F940.inc.c"
#include "main_menu_vpk0/models/8035F960.inc.c"
#include "main_menu_vpk0/models/8035F968.inc.c"
#include "main_menu_vpk0/models/80360168.inc.c"
#include "main_menu_vpk0/models/80360170.inc.c"
#include "main_menu_vpk0/models/80360190.inc.c"
#include "main_menu_vpk0/models/80360198.inc.c"
#include "main_menu_vpk0/models/80360998.inc.c"
#include "main_menu_vpk0/models/803609A0.inc.c"
#include "main_menu_vpk0/models/80360DA0.inc.c"
#include "main_menu_vpk0/models/80360DA8.inc.c"
#include "main_menu_vpk0/models/80362DA8.inc.c"
#include "main_menu_vpk0/models/80362DB0.inc.c"
#include "main_menu_vpk0/models/803635B0.inc.c"
#include "main_menu_vpk0/models/803635B8.inc.c"
#include "main_menu_vpk0/models/803635D8.inc.c"
#include "main_menu_vpk0/models/803635E0.inc.c"
#include "main_menu_vpk0/models/80363DE0.inc.c"
#include "main_menu_vpk0/models/80363DE8.inc.c"
#include "main_menu_vpk0/models/80363E08.inc.c"
#include "main_menu_vpk0/models/80363E10.inc.c"
#include "main_menu_vpk0/models/80364610.inc.c"
#include "main_menu_vpk0/models/80364618.inc.c"
#include "main_menu_vpk0/models/80364638.inc.c"
#include "main_menu_vpk0/models/80364640.inc.c"
#include "main_menu_vpk0/models/80364E40.inc.c"
#include "main_menu_vpk0/models/80364E48.inc.c"
#include "main_menu_vpk0/models/80364E68.inc.c"
#include "main_menu_vpk0/models/80364E70.inc.c"
#include "main_menu_vpk0/models/80365670.inc.c"
#include "main_menu_vpk0/models/80365678.inc.c"
#include "main_menu_vpk0/models/80365698.inc.c"
#include "main_menu_vpk0/models/803656A0.inc.c"
#include "main_menu_vpk0/models/80365EA0.inc.c"
#include "main_menu_vpk0/models/80365EA8.inc.c"
#include "main_menu_vpk0/models/80365EC8.inc.c"
#include "main_menu_vpk0/models/80365ED0.inc.c"
#include "main_menu_vpk0/models/803662D0.inc.c"
#include "main_menu_vpk0/models/803662D8.inc.c"
#include "main_menu_vpk0/models/803662F8.inc.c"
#include "main_menu_vpk0/models/80366300.inc.c"
#include "main_menu_vpk0/models/80366700.inc.c"
#include "main_menu_vpk0/models/80366708.inc.c"
#include "main_menu_vpk0/models/80366728.inc.c"
#include "main_menu_vpk0/models/80366730.inc.c"
#include "main_menu_vpk0/models/80366F30.inc.c"
#include "main_menu_vpk0/models/80366F38.inc.c"
#include "main_menu_vpk0/models/80366F58.inc.c"
#include "main_menu_vpk0/models/80366F60.inc.c"
#include "main_menu_vpk0/models/80367760.inc.c"
#include "main_menu_vpk0/models/80367768.inc.c"
#include "main_menu_vpk0/models/80367F68.inc.c"
#include "main_menu_vpk0/models/80367F70.inc.c"
#include "main_menu_vpk0/models/80367F90.inc.c"
#include "main_menu_vpk0/models/80367F98.inc.c"
#include "main_menu_vpk0/models/80368798.inc.c"
#include "main_menu_vpk0/models/803687A0.inc.c"
#include "main_menu_vpk0/models/803687C0.inc.c"
#include "main_menu_vpk0/models/803687C8.inc.c"
#include "main_menu_vpk0/models/80368BC8.inc.c"
#include "main_menu_vpk0/models/80368BD0.inc.c"
#include "main_menu_vpk0/models/80368BF0.inc.c"
#include "main_menu_vpk0/models/80368BF8.inc.c"
#include "main_menu_vpk0/models/803693F8.inc.c"
#include "main_menu_vpk0/models/80369400.inc.c"
#include "main_menu_vpk0/models/80369420.inc.c"
#include "main_menu_vpk0/models/80369428.inc.c"
#include "main_menu_vpk0/models/80369C28.inc.c"
#include "main_menu_vpk0/models/80369C30.inc.c"
#include "main_menu_vpk0/models/80369C50.inc.c"
#include "main_menu_vpk0/models/80369C58.inc.c"
#include "main_menu_vpk0/models/8036A458.inc.c"
#include "main_menu_vpk0/models/8036A7E0.inc.c"
#include "main_menu_vpk0/models/8036A858.inc.c"
#include "main_menu_vpk0/models/8036A860.inc.c"
#include "main_menu_vpk0/models/8036A8D8.inc.c"
#include "main_menu_vpk0/models/8036A8E0.inc.c"
#include "main_menu_vpk0/models/8036A958.inc.c"
#include "main_menu_vpk0/models/8036A960.inc.c"
#include "main_menu_vpk0/models/8036A9D8.inc.c"
#include "main_menu_vpk0/models/8036A9E0.inc.c"
#include "main_menu_vpk0/models/8036AA58.inc.c"
#include "main_menu_vpk0/models/8036AA60.inc.c"
#include "main_menu_vpk0/models/8036AA74.inc.c"
#include "main_menu_vpk0/models/8036AA78.inc.c"
#include "main_menu_vpk0/models/803728A8.inc.c"
#include "main_menu_vpk0/models/80372B30.inc.c"
#include "main_menu_vpk0/models/80372D40.inc.c"
#include "main_menu_vpk0/models/80372F40.inc.c"
#include "main_menu_vpk0/models/80373058.inc.c"
#include "main_menu_vpk0/models/80373178.inc.c"
#include "main_menu_vpk0/models/80373298.inc.c"
#include "main_menu_vpk0/models/803733B8.inc.c"
#include "main_menu_vpk0/models/803734D8.inc.c"
#include "main_menu_vpk0/models/803735F8.inc.c"
#include "main_menu_vpk0/models/80373718.inc.c"
#include "main_menu_vpk0/models/80373838.inc.c"
#include "main_menu_vpk0/models/80373958.inc.c"
#include "main_menu_vpk0/models/80373A78.inc.c"
#include "main_menu_vpk0/models/80373BC0.inc.c"
#include "main_menu_vpk0/models/80373CD8.inc.c"
#include "main_menu_vpk0/models/80373DF8.inc.c"
#include "main_menu_vpk0/models/80373F18.inc.c"
#include "main_menu_vpk0/models/80374038.inc.c"
#include "main_menu_vpk0/models/80374158.inc.c"
#include "main_menu_vpk0/models/80374278.inc.c"
#include "main_menu_vpk0/models/803743A8.inc.c"
#include "main_menu_vpk0/models/803744C8.inc.c"
#include "main_menu_vpk0/models/803745E8.inc.c"
#include "main_menu_vpk0/models/80374708.inc.c"
#include "main_menu_vpk0/models/80374850.inc.c"
#include "main_menu_vpk0/models/80374968.inc.c"
#include "main_menu_vpk0/models/80374A88.inc.c"
#include "main_menu_vpk0/models/80374BA8.inc.c"
#include "main_menu_vpk0/models/80374CC8.inc.c"
#include "main_menu_vpk0/models/80374DE8.inc.c"
#include "main_menu_vpk0/models/80374F08.inc.c"
#include "main_menu_vpk0/models/80375038.inc.c"
#include "main_menu_vpk0/models/80375158.inc.c"
#include "main_menu_vpk0/models/80375278.inc.c"
#include "main_menu_vpk0/models/80375398.inc.c"
#include "main_menu_vpk0/models/803754E0.inc.c"
#include "main_menu_vpk0/models/803755F8.inc.c"
#include "main_menu_vpk0/models/80375718.inc.c"
#include "main_menu_vpk0/models/80375838.inc.c"
#include "main_menu_vpk0/models/80375970.inc.c"
#include "main_menu_vpk0/models/80375A90.inc.c"
#include "main_menu_vpk0/models/80375BB0.inc.c"
#include "main_menu_vpk0/models/80375CD0.inc.c"
#include "main_menu_vpk0/models/80375DF0.inc.c"
#include "main_menu_vpk0/models/80375F10.inc.c"
#include "main_menu_vpk0/models/80376030.inc.c"
#include "main_menu_vpk0/models/80376178.inc.c"
#include "main_menu_vpk0/models/80376290.inc.c"
#include "main_menu_vpk0/models/803763B0.inc.c"
#include "main_menu_vpk0/models/803764D0.inc.c"
#include "main_menu_vpk0/models/80376608.inc.c"
#include "main_menu_vpk0/models/80376728.inc.c"
#include "main_menu_vpk0/models/80376848.inc.c"
#include "main_menu_vpk0/models/80376968.inc.c"
#include "main_menu_vpk0/models/80376A88.inc.c"
#include "main_menu_vpk0/models/80376BA8.inc.c"
#include "main_menu_vpk0/models/80376CC8.inc.c"
#include "main_menu_vpk0/models/80376E10.inc.c"
#include "main_menu_vpk0/models/80376F28.inc.c"
#include "main_menu_vpk0/models/80377048.inc.c"
#include "main_menu_vpk0/models/80377168.inc.c"
#include "main_menu_vpk0/models/80377288.inc.c"
#include "main_menu_vpk0/models/803773A8.inc.c"
#include "main_menu_vpk0/models/803774C8.inc.c"
#include "main_menu_vpk0/models/803775E8.inc.c"
#include "main_menu_vpk0/models/80377708.inc.c"
#include "main_menu_vpk0/models/80377828.inc.c"
#include "main_menu_vpk0/models/80377948.inc.c"
#include "main_menu_vpk0/models/80377A68.inc.c"
#include "main_menu_vpk0/models/80377BB0.inc.c"
#include "main_menu_vpk0/models/80377CC8.inc.c"
#include "main_menu_vpk0/models/80377DE8.inc.c"
#include "main_menu_vpk0/models/80377F08.inc.c"
#include "main_menu_vpk0/models/80378028.inc.c"
#include "main_menu_vpk0/models/80378148.inc.c"
#include "main_menu_vpk0/models/80378268.inc.c"
#include "main_menu_vpk0/models/80378398.inc.c"
#include "main_menu_vpk0/models/803784B8.inc.c"
#include "main_menu_vpk0/models/803785D8.inc.c"
#include "main_menu_vpk0/models/803786F8.inc.c"
#include "main_menu_vpk0/models/80378840.inc.c"
#include "main_menu_vpk0/models/80378958.inc.c"
#include "main_menu_vpk0/models/80378A78.inc.c"
#include "main_menu_vpk0/models/80378B98.inc.c"
#include "main_menu_vpk0/models/80378CB8.inc.c"
#include "main_menu_vpk0/models/80378DD8.inc.c"
#include "main_menu_vpk0/models/80378EF8.inc.c"
#include "main_menu_vpk0/models/80379028.inc.c"
#include "main_menu_vpk0/models/80379148.inc.c"
#include "main_menu_vpk0/models/80379268.inc.c"
#include "main_menu_vpk0/models/80379388.inc.c"
#include "main_menu_vpk0/models/803794D0.inc.c"
#include "main_menu_vpk0/models/803795E8.inc.c"
#include "main_menu_vpk0/models/80379710.inc.c"
#include "main_menu_vpk0/models/80379830.inc.c"
#include "main_menu_vpk0/models/80379950.inc.c"
#include "main_menu_vpk0/models/80379A70.inc.c"
#include "main_menu_vpk0/models/80379B90.inc.c"
#include "main_menu_vpk0/models/80379CC8.inc.c"
#include "main_menu_vpk0/models/80379DE8.inc.c"
#include "main_menu_vpk0/models/80379F08.inc.c"
#include "main_menu_vpk0/models/8037A028.inc.c"
#include "main_menu_vpk0/models/8037A170.inc.c"
#include "main_menu_vpk0/models/8037A288.inc.c"
#include "main_menu_vpk0/models/8037A3A8.inc.c"
#include "main_menu_vpk0/models/8037A4C8.inc.c"
#include "main_menu_vpk0/models/8037A5E8.inc.c"
#include "main_menu_vpk0/models/8037A708.inc.c"
#include "main_menu_vpk0/models/8037A828.inc.c"
#include "main_menu_vpk0/models/8037A958.inc.c"
#include "main_menu_vpk0/models/8037AA78.inc.c"
#include "main_menu_vpk0/models/8037AB98.inc.c"
#include "main_menu_vpk0/models/8037ACB8.inc.c"
#include "main_menu_vpk0/models/8037AE00.inc.c"
#include "main_menu_vpk0/models/8037AF18.inc.c"
#include "main_menu_vpk0/models/8037B038.inc.c"
#include "main_menu_vpk0/models/8037B158.inc.c"
#include "main_menu_vpk0/models/8037B278.inc.c"
#include "main_menu_vpk0/models/8037B398.inc.c"
#include "main_menu_vpk0/models/8037B4B8.inc.c"
#include "main_menu_vpk0/models/8037B5D8.inc.c"
#include "main_menu_vpk0/models/8037B6F8.inc.c"
#include "main_menu_vpk0/models/8037B818.inc.c"
#include "main_menu_vpk0/models/8037B938.inc.c"
#include "main_menu_vpk0/models/8037BA80.inc.c"
#include "main_menu_vpk0/models/8037D360.inc.c"
#include "main_menu_vpk0/models/8037D738.inc.c"
#include "main_menu_vpk0/models/8037D868.inc.c"
#include "main_menu_vpk0/models/8037D968.inc.c"
#include "main_menu_vpk0/models/8037D990.inc.c"
#include "main_menu_vpk0/models/8037DAE8.inc.c"
#include "main_menu_vpk0/models/8037DC78.inc.c"
#include "main_menu_vpk0/models/8037DE08.inc.c"
#include "main_menu_vpk0/models/8037DEC0.inc.c"
#include "main_menu_vpk0/models/8037DF78.inc.c"
#include "main_menu_vpk0/models/8037E038.inc.c"
#include "main_menu_vpk0/models/8037E0F8.inc.c"
#include "main_menu_vpk0/models/8037E1B0.inc.c"
#include "main_menu_vpk0/models/8037E270.inc.c"
#include "main_menu_vpk0/models/8037E328.inc.c"
#include "main_menu_vpk0/models/8037E3E0.inc.c"
#include "main_menu_vpk0/models/8037E4A0.inc.c"
#include "main_menu_vpk0/models/8037E560.inc.c"
#include "main_menu_vpk0/models/8037E628.inc.c"
#include "main_menu_vpk0/models/8037E6E0.inc.c"
#include "main_menu_vpk0/models/8037E7B0.inc.c"
#include "main_menu_vpk0/models/8037E8E8.inc.c"
#include "main_menu_vpk0/models/8037EA20.inc.c"
#include "main_menu_vpk0/models/8037EA48.inc.c"
#include "main_menu_vpk0/models/8037EBA8.inc.c"
#include "main_menu_vpk0/models/8037ED08.inc.c"
#include "main_menu_vpk0/models/8037ED18.inc.c"
#include "main_menu_vpk0/models/8037ED28.inc.c"
#include "main_menu_vpk0/models/8037ED38.inc.c"
#include "main_menu_vpk0/models/8037ED48.inc.c"
#include "main_menu_vpk0/models/8037ED58.inc.c"
#include "main_menu_vpk0/models/8037ED68.inc.c"
#include "main_menu_vpk0/models/8037ED78.inc.c"
#include "main_menu_vpk0/models/8037ED88.inc.c"
#include "main_menu_vpk0/models/8037ED98.inc.c"
#include "main_menu_vpk0/models/8037EDA8.inc.c"
#include "main_menu_vpk0/models/8037EDB8.inc.c"
#include "main_menu_vpk0/models/8037EDC8.inc.c"
#include "main_menu_vpk0/models/8037EDD8.inc.c"
#include "main_menu_vpk0/models/8037EDE8.inc.c"
#include "main_menu_vpk0/models/8037EDF8.inc.c"
#include "main_menu_vpk0/models/8037EE08.inc.c"
#include "main_menu_vpk0/models/8037EE18.inc.c"
#include "main_menu_vpk0/models/8037EE28.inc.c"
#include "main_menu_vpk0/models/8037EE38.inc.c"
#include "main_menu_vpk0/models/8037EE48.inc.c"
#include "main_menu_vpk0/models/8037EE58.inc.c"
#include "main_menu_vpk0/models/8037EE68.inc.c"
#include "main_menu_vpk0/models/8037EE78.inc.c"
#include "main_menu_vpk0/models/8037EE88.inc.c"
#include "main_menu_vpk0/models/8037EE98.inc.c"
#include "main_menu_vpk0/models/8037EEA8.inc.c"
#include "main_menu_vpk0/models/8037EEB8.inc.c"
#include "main_menu_vpk0/models/8037EEC8.inc.c"
#include "main_menu_vpk0/models/8037EED8.inc.c"
#include "main_menu_vpk0/models/8037EEE8.inc.c"
#include "main_menu_vpk0/models/8037EEF8.inc.c"
#include "main_menu_vpk0/models/8037EF08.inc.c"
#include "main_menu_vpk0/models/8037EF18.inc.c"
#include "main_menu_vpk0/models/8037EF28.inc.c"
#include "main_menu_vpk0/models/8037EF38.inc.c"
#include "main_menu_vpk0/models/8037EF48.inc.c"
#include "main_menu_vpk0/models/8037EF58.inc.c"
#include "main_menu_vpk0/models/8037EF68.inc.c"
#include "main_menu_vpk0/models/8037EF78.inc.c"
#include "main_menu_vpk0/models/8037EF88.inc.c"
#include "main_menu_vpk0/models/8037EF98.inc.c"
#include "main_menu_vpk0/models/8037EFA8.inc.c"
#include "main_menu_vpk0/models/8037EFB8.inc.c"
#include "main_menu_vpk0/models/8037EFC8.inc.c"
#include "main_menu_vpk0/models/8037EFD8.inc.c"
#include "main_menu_vpk0/models/8037EFE8.inc.c"
#include "main_menu_vpk0/models/8037EFF8.inc.c"
#include "main_menu_vpk0/models/8037F008.inc.c"
#include "main_menu_vpk0/models/8037F018.inc.c"
#include "main_menu_vpk0/models/8037F028.inc.c"
#include "main_menu_vpk0/models/8037F038.inc.c"
#include "main_menu_vpk0/models/8037F048.inc.c"
#include "main_menu_vpk0/models/8037F058.inc.c"
#include "main_menu_vpk0/models/8037F068.inc.c"
#include "main_menu_vpk0/models/8037F078.inc.c"
#include "main_menu_vpk0/models/8037F088.inc.c"
#include "main_menu_vpk0/models/8037F098.inc.c"
#include "main_menu_vpk0/models/8037F0A8.inc.c"
#include "main_menu_vpk0/models/8037F0B8.inc.c"
#include "main_menu_vpk0/models/8037F0C8.inc.c"
#include "main_menu_vpk0/models/8037F0D8.inc.c"
#include "main_menu_vpk0/models/8037F0E8.inc.c"
#include "main_menu_vpk0/models/8037F0F8.inc.c"
#include "main_menu_vpk0/models/8037F108.inc.c"
#include "main_menu_vpk0/models/8037F118.inc.c"
#include "main_menu_vpk0/models/8037F128.inc.c"
#include "main_menu_vpk0/models/8037F138.inc.c"
#include "main_menu_vpk0/models/8037F148.inc.c"
#include "main_menu_vpk0/models/8037F158.inc.c"
#include "main_menu_vpk0/models/8037F168.inc.c"
#include "main_menu_vpk0/models/8037F178.inc.c"
#include "main_menu_vpk0/models/8037F188.inc.c"
#include "main_menu_vpk0/models/8037F198.inc.c"
#include "main_menu_vpk0/models/8037F1A8.inc.c"
#include "main_menu_vpk0/models/8037F1B8.inc.c"
#include "main_menu_vpk0/models/8037F1C8.inc.c"
#include "main_menu_vpk0/models/8037F1D8.inc.c"
#include "main_menu_vpk0/models/8037F1E8.inc.c"
#include "main_menu_vpk0/models/8037F1F8.inc.c"
#include "main_menu_vpk0/models/8037F208.inc.c"
#include "main_menu_vpk0/models/8037F218.inc.c"
#include "main_menu_vpk0/models/8037F228.inc.c"
#include "main_menu_vpk0/models/8037F238.inc.c"
#include "main_menu_vpk0/models/8037F248.inc.c"
#include "main_menu_vpk0/models/8037F258.inc.c"
#include "main_menu_vpk0/models/8037F268.inc.c"
#include "main_menu_vpk0/models/8037F278.inc.c"
#include "main_menu_vpk0/models/8037F288.inc.c"
#include "main_menu_vpk0/models/8037F298.inc.c"
#include "main_menu_vpk0/models/8037F2A8.inc.c"
#include "main_menu_vpk0/models/8037F2B8.inc.c"
#include "main_menu_vpk0/models/8037F2C8.inc.c"
#include "main_menu_vpk0/models/8037F2D8.inc.c"
#include "main_menu_vpk0/models/8037F2E8.inc.c"
#include "main_menu_vpk0/models/8037F2F8.inc.c"
#include "main_menu_vpk0/models/8037F308.inc.c"
#include "main_menu_vpk0/models/8037F318.inc.c"
#include "main_menu_vpk0/models/8037F328.inc.c"
#include "main_menu_vpk0/models/8037F338.inc.c"
#include "main_menu_vpk0/models/8037F348.inc.c"
#include "main_menu_vpk0/models/8037F358.inc.c"
#include "main_menu_vpk0/models/8037F368.inc.c"
#include "main_menu_vpk0/models/8037F378.inc.c"
#include "main_menu_vpk0/models/8037F388.inc.c"
#include "main_menu_vpk0/models/8037F398.inc.c"
#include "main_menu_vpk0/models/8037F3A8.inc.c"
#include "main_menu_vpk0/models/8037F3B8.inc.c"
#include "main_menu_vpk0/models/8037F3C8.inc.c"
#include "main_menu_vpk0/models/8037F3D8.inc.c"
#include "main_menu_vpk0/models/8037F3E8.inc.c"
#include "main_menu_vpk0/models/8037F3F8.inc.c"
#include "main_menu_vpk0/models/8037F408.inc.c"
#include "main_menu_vpk0/models/8037F418.inc.c"
#include "main_menu_vpk0/models/8037F428.inc.c"
#include "main_menu_vpk0/models/8037F438.inc.c"
#include "main_menu_vpk0/models/8037F448.inc.c"
#include "main_menu_vpk0/models/8037F458.inc.c"
#include "main_menu_vpk0/models/8037F468.inc.c"
#include "main_menu_vpk0/models/8037F478.inc.c"
#include "main_menu_vpk0/models/8037F488.inc.c"
#include "main_menu_vpk0/models/8037F498.inc.c"
#include "main_menu_vpk0/models/8037F4A8.inc.c"
#include "main_menu_vpk0/models/8037F4B8.inc.c"
#include "main_menu_vpk0/models/8037F4C8.inc.c"
#include "main_menu_vpk0/models/8037F4D8.inc.c"
#include "main_menu_vpk0/models/8037F4E8.inc.c"
#include "main_menu_vpk0/models/8037F4F8.inc.c"
#include "main_menu_vpk0/models/8037F508.inc.c"
#include "main_menu_vpk0/models/8037F518.inc.c"
#include "main_menu_vpk0/models/8037F528.inc.c"
#include "main_menu_vpk0/models/8037F538.inc.c"
#include "main_menu_vpk0/models/8037F548.inc.c"
#include "main_menu_vpk0/models/8037F558.inc.c"
#include "main_menu_vpk0/models/8037F568.inc.c"
#include "main_menu_vpk0/models/8037F578.inc.c"
#include "main_menu_vpk0/models/8037F588.inc.c"
#include "main_menu_vpk0/models/8037F598.inc.c"
#include "main_menu_vpk0/models/8037F5A8.inc.c"
#include "main_menu_vpk0/models/8037F5B8.inc.c"
#include "main_menu_vpk0/models/8037F5C8.inc.c"
#include "main_menu_vpk0/models/8037F5D8.inc.c"
#include "main_menu_vpk0/models/8037F5E8.inc.c"
#include "main_menu_vpk0/models/8037F5F8.inc.c"
#include "main_menu_vpk0/models/8037F608.inc.c"
#include "main_menu_vpk0/models/8037F618.inc.c"
#include "main_menu_vpk0/models/8037F628.inc.c"
#include "main_menu_vpk0/models/8037F638.inc.c"
#include "main_menu_vpk0/models/8037F648.inc.c"
#include "main_menu_vpk0/models/8037F658.inc.c"
#include "main_menu_vpk0/models/80381D5C.inc.c"
#include "main_menu_vpk0/animations/80381D60.inc.c"
#include "main_menu_vpk0/animations/803820E8.inc.c"
#include "main_menu_vpk0/animations/8038217C.inc.c"
#include "main_menu_vpk0/animations/80382478.inc.c"
#include "main_menu_vpk0/animations/803824B4.inc.c"
#include "main_menu_vpk0/animations/80382500.inc.c"
#include "main_menu_vpk0/animations/8038254C.inc.c"
#include "main_menu_vpk0/animations/803826E4.inc.c"
#include "main_menu_vpk0/animations/803828B4.inc.c"
#include "main_menu_vpk0/animations/80382A84.inc.c"
#include "main_menu_vpk0/animations/80382C40.inc.c"
#include "main_menu_vpk0/animations/80382DAC.inc.c"
#include "main_menu_vpk0/animations/80382EF4.inc.c"
#include "main_menu_vpk0/animations/8038303C.inc.c"
#include "main_menu_vpk0/animations/803831FC.inc.c"
#include "main_menu_vpk0/animations/803833BC.inc.c"
#include "main_menu_vpk0/animations/80383504.inc.c"
#include "main_menu_vpk0/animations/803836EC.inc.c"
#include "main_menu_vpk0/animations/80383834.inc.c"
#include "main_menu_vpk0/animations/8038397C.inc.c"
#include "main_menu_vpk0/animations/80383B20.inc.c"
#include "main_menu_vpk0/animations/80383D08.inc.c"
#include "main_menu_vpk0/animations/80383E78.inc.c"
#include "main_menu_vpk0/animations/80384018.inc.c"
#include "main_menu_vpk0/animations/80384160.inc.c"
#include "main_menu_vpk0/animations/803842A8.inc.c"
#include "main_menu_vpk0/animations/803843F0.inc.c"
#include "main_menu_vpk0/animations/8038450C.inc.c"
#include "main_menu_vpk0/animations/80384654.inc.c"
#include "main_menu_vpk0/animations/803847BC.inc.c"
#include "main_menu_vpk0/animations/80384904.inc.c"
#include "main_menu_vpk0/animations/80384A6C.inc.c"
#include "main_menu_vpk0/animations/80384BDC.inc.c"
#include "main_menu_vpk0/animations/80384D4C.inc.c"
#include "main_menu_vpk0/animations/80384EBC.inc.c"
#include "main_menu_vpk0/animations/80385004.inc.c"
#include "main_menu_vpk0/animations/803850A4.inc.c"
#include "main_menu_vpk0/animations/80385120.inc.c"
#include "main_menu_vpk0/animations/8038519C.inc.c"
#include "main_menu_vpk0/animations/803851AC.inc.c"
#include "main_menu_vpk0/animations/803852A0.inc.c"
#include "main_menu_vpk0/animations/80385320.inc.c"
#include "main_menu_vpk0/animations/8038550C.inc.c"
#include "main_menu_vpk0/animations/803856FC.inc.c"
#include "main_menu_vpk0/animations/80385700.inc.c"
#include "main_menu_vpk0/animations/80385A88.inc.c"
#include "main_menu_vpk0/animations/80385AF4.inc.c"
#include "main_menu_vpk0/animations/80385BB8.inc.c"
#include "main_menu_vpk0/animations/80385C7C.inc.c"
#include "main_menu_vpk0/animations/80385D40.inc.c"
#include "main_menu_vpk0/animations/80385E04.inc.c"
#include "main_menu_vpk0/animations/80385E08.inc.c"
#include "main_menu_vpk0/models/80385E18.inc.c"
#include "main_menu_vpk0/models/80385E28.inc.c"
#include "main_menu_vpk0/models/80386E28.inc.c"
#include "main_menu_vpk0/models/80386E30.inc.c"
#include "main_menu_vpk0/models/80387030.inc.c"
#include "main_menu_vpk0/models/80387038.inc.c"
#include "main_menu_vpk0/models/80387058.inc.c"
#include "main_menu_vpk0/models/80387060.inc.c"
#include "main_menu_vpk0/models/80387260.inc.c"
#include "main_menu_vpk0/models/80387268.inc.c"
#include "main_menu_vpk0/models/80387274.inc.c"
#include "main_menu_vpk0/models/80387280.inc.c"
#include "main_menu_vpk0/models/80387480.inc.c"
#include "main_menu_vpk0/models/80387488.inc.c"
#include "main_menu_vpk0/models/8038749C.inc.c"
#include "main_menu_vpk0/models/803874A8.inc.c"
#include "main_menu_vpk0/models/80387C28.inc.c"
#include "main_menu_vpk0/models/80387C30.inc.c"
#include "main_menu_vpk0/models/80387E30.inc.c"
#include "main_menu_vpk0/models/80387E38.inc.c"
#include "main_menu_vpk0/models/803885B8.inc.c"
#include "main_menu_vpk0/models/803885C0.inc.c"
#include "main_menu_vpk0/models/80388D40.inc.c"
#include "main_menu_vpk0/models/80388D48.inc.c"
#include "main_menu_vpk0/models/803894C8.inc.c"
#include "main_menu_vpk0/models/803894D0.inc.c"
#include "main_menu_vpk0/models/80389C50.inc.c"
#include "main_menu_vpk0/models/80389C58.inc.c"
#include "main_menu_vpk0/models/80389E58.inc.c"
#include "main_menu_vpk0/models/80389E60.inc.c"
#include "main_menu_vpk0/models/80389E80.inc.c"
#include "main_menu_vpk0/models/80389E88.inc.c"
#include "main_menu_vpk0/models/8038A288.inc.c"
#include "main_menu_vpk0/models/8038A290.inc.c"
#include "main_menu_vpk0/models/8038A2B0.inc.c"
#include "main_menu_vpk0/models/8038A2B8.inc.c"
#include "main_menu_vpk0/models/8038A4B8.inc.c"
#include "main_menu_vpk0/models/8038A4C0.inc.c"
#include "main_menu_vpk0/models/8038A4E0.inc.c"
#include "main_menu_vpk0/models/8038A4E8.inc.c"
#include "main_menu_vpk0/models/8038A8E8.inc.c"
#include "main_menu_vpk0/models/8038A8F0.inc.c"
#include "main_menu_vpk0/models/8038A910.inc.c"
#include "main_menu_vpk0/models/8038A918.inc.c"
#include "main_menu_vpk0/models/8038AD18.inc.c"
#include "main_menu_vpk0/models/8038AD20.inc.c"
#include "main_menu_vpk0/models/8038AD40.inc.c"
#include "main_menu_vpk0/models/8038ADC4.inc.c"
#include "main_menu_vpk0/models/8038ADE0.inc.c"
#include "main_menu_vpk0/models/8038AE58.inc.c"
#include "main_menu_vpk0/models/8038AE60.inc.c"
#include "main_menu_vpk0/models/8038C960.inc.c"
#include "main_menu_vpk0/models/8038CC78.inc.c"
#include "main_menu_vpk0/models/8038CD60.inc.c"
#include "main_menu_vpk0/models/8038CF88.inc.c"
#include "main_menu_vpk0/models/8038CFE8.inc.c"
#include "main_menu_vpk0/models/8038D150.inc.c"
#include "main_menu_vpk0/models/8038D588.inc.c"
#include "main_menu_vpk0/models/8038D5B8.inc.c"
#include "main_menu_vpk0/models/8038D638.inc.c"
#include "main_menu_vpk0/models/8038D668.inc.c"
#include "main_menu_vpk0/models/8038D6E8.inc.c"
#include "main_menu_vpk0/models/8038D758.inc.c"
#include "main_menu_vpk0/models/8038D7D8.inc.c"
#include "main_menu_vpk0/models/8038D848.inc.c"
#include "main_menu_vpk0/models/8038D988.inc.c"
#include "main_menu_vpk0/models/8038DA08.inc.c"
#include "main_menu_vpk0/models/8038DA88.inc.c"
#include "main_menu_vpk0/models/8038DAF8.inc.c"
#include "main_menu_vpk0/models/8038DC38.inc.c"
#include "main_menu_vpk0/models/8038DCF0.inc.c"
#include "main_menu_vpk0/models/8038DEB8.inc.c"
#include "main_menu_vpk0/models/8038DF50.inc.c"
#include "main_menu_vpk0/models/8038DFF8.inc.c"
#include "main_menu_vpk0/models/8038E1A0.inc.c"
#include "main_menu_vpk0/models/8038E348.inc.c"
#include "main_menu_vpk0/models/8038E3C8.inc.c"
#include "main_menu_vpk0/models/8038E588.inc.c"
#include "main_menu_vpk0/models/8038E648.inc.c"
#include "main_menu_vpk0/models/8038E710.inc.c"
#include "main_menu_vpk0/models/8038E8E0.inc.c"
#include "main_menu_vpk0/models/8038EA98.inc.c"
#include "main_menu_vpk0/models/8038EAE0.inc.c"
#include "main_menu_vpk0/models/8038EBF0.inc.c"
#include "main_menu_vpk0/models/8038ECF0.inc.c"
#include "main_menu_vpk0/models/8038ED70.inc.c"
#include "main_menu_vpk0/models/8038EDF0.inc.c"
#include "main_menu_vpk0/models/8038EE60.inc.c"
#include "main_menu_vpk0/models/8038EF50.inc.c"
#include "main_menu_vpk0/models/8038F040.inc.c"
#include "main_menu_vpk0/models/8038F138.inc.c"
#include "main_menu_vpk0/models/8038F248.inc.c"
#include "main_menu_vpk0/models/8038F2E0.inc.c"
#include "main_menu_vpk0/models/8038F2E8.inc.c"
#include "main_menu_vpk0/models/8038F2F0.inc.c"
#include "main_menu_vpk0/models/8038F2F8.inc.c"
#include "main_menu_vpk0/models/8038F300.inc.c"
#include "main_menu_vpk0/models/8038F308.inc.c"
#include "main_menu_vpk0/models/8038F310.inc.c"
#include "main_menu_vpk0/models/8038F318.inc.c"
#include "main_menu_vpk0/models/8038F320.inc.c"
#include "main_menu_vpk0/models/8038F328.inc.c"
#include "main_menu_vpk0/models/8038F330.inc.c"
#include "main_menu_vpk0/models/8038F338.inc.c"
#include "main_menu_vpk0/models/8038F340.inc.c"
#include "main_menu_vpk0/models/8038F348.inc.c"
#include "main_menu_vpk0/models/8038F350.inc.c"
#include "main_menu_vpk0/models/8038F358.inc.c"
#include "main_menu_vpk0/models/8038F360.inc.c"
#include "main_menu_vpk0/models/8038F368.inc.c"
#include "main_menu_vpk0/models/8038F370.inc.c"
#include "main_menu_vpk0/models/8038F378.inc.c"
#include "main_menu_vpk0/models/8038F380.inc.c"
#include "main_menu_vpk0/models/8038F388.inc.c"
#include "main_menu_vpk0/models/8038F390.inc.c"
#include "main_menu_vpk0/models/8038F398.inc.c"
#include "main_menu_vpk0/models/8038F3A0.inc.c"
#include "main_menu_vpk0/models/8038F3A8.inc.c"
#include "main_menu_vpk0/models/8038F3B0.inc.c"
#include "main_menu_vpk0/models/8038F3B8.inc.c"
#include "main_menu_vpk0/models/8038F3C0.inc.c"
#include "main_menu_vpk0/models/8038F3C8.inc.c"
#include "main_menu_vpk0/models/8038F3D0.inc.c"
#include "main_menu_vpk0/models/8038F3D8.inc.c"
#include "main_menu_vpk0/models/8038F3E0.inc.c"
#include "main_menu_vpk0/models/8038F9B8.inc.c"
#include "main_menu_vpk0/animations/8038F9C0.inc.c"
#include "main_menu_vpk0/animations/8038FA44.inc.c"
#include "main_menu_vpk0/animations/8038FE0C.inc.c"
#include "main_menu_vpk0/animations/803900D4.inc.c"
#include "main_menu_vpk0/animations/80390CCC.inc.c"
#include "main_menu_vpk0/animations/80390E94.inc.c"
#include "main_menu_vpk0/animations/80390F58.inc.c"
#include "main_menu_vpk0/animations/80391018.inc.c"
#include "main_menu_vpk0/animations/803910DC.inc.c"
#include "main_menu_vpk0/animations/803912A8.inc.c"
#include "main_menu_vpk0/animations/80391418.inc.c"
#include "main_menu_vpk0/animations/8039154C.inc.c"
#include "main_menu_vpk0/animations/803916AC.inc.c"
#include "main_menu_vpk0/animations/8039183C.inc.c"
#include "main_menu_vpk0/animations/80391910.inc.c"
#include "main_menu_vpk0/animations/80391AD4.inc.c"
#include "main_menu_vpk0/animations/80391D08.inc.c"
#include "main_menu_vpk0/animations/80391E10.inc.c"
#include "main_menu_vpk0/animations/80391E8C.inc.c"
#include "main_menu_vpk0/animations/80391F38.inc.c"
#include "main_menu_vpk0/animations/803920B0.inc.c"
#include "main_menu_vpk0/animations/80392294.inc.c"
#include "main_menu_vpk0/animations/8039239C.inc.c"
#include "main_menu_vpk0/animations/80392418.inc.c"
#include "main_menu_vpk0/animations/80392508.inc.c"
#include "main_menu_vpk0/animations/8039276C.inc.c"
#include "main_menu_vpk0/animations/803929C0.inc.c"
#include "main_menu_vpk0/animations/80392BFC.inc.c"
#include "main_menu_vpk0/animations/80392E2C.inc.c"
#include "main_menu_vpk0/animations/80393064.inc.c"
#include "main_menu_vpk0/animations/803932B8.inc.c"
#include "main_menu_vpk0/animations/80393528.inc.c"
#include "main_menu_vpk0/animations/8039379C.inc.c"
#include "main_menu_vpk0/animations/80393938.inc.c"
#include "main_menu_vpk0/animations/80393ADC.inc.c"
#include "main_menu_vpk0/animations/80393AE0.inc.c"
#include "main_menu_vpk0/animations/80393B64.inc.c"
#include "main_menu_vpk0/animations/80393BEC.inc.c"
#include "main_menu_vpk0/models/80393BF0.inc.c"
#include "main_menu_vpk0/models/80393CB0.inc.c"
#include "main_menu_vpk0/models/80393D30.inc.c"
#include "main_menu_vpk0/models/80393DB4.inc.c"
#include "main_menu_vpk0/animations/80393DC0.inc.c"
#include "main_menu_vpk0/animations/80393DC8.inc.c"
#include "main_menu_vpk0/models/803943B0.inc.c"
#include "main_menu_vpk0/models/803943B8.inc.c"
#include "main_menu_vpk0/models/803947B8.inc.c"
#include "main_menu_vpk0/models/803947C0.inc.c"
#include "main_menu_vpk0/models/803949C0.inc.c"
#include "main_menu_vpk0/models/803949C8.inc.c"
#include "main_menu_vpk0/models/803949CC.inc.c"
#include "main_menu_vpk0/models/803949D8.inc.c"
#include "main_menu_vpk0/models/80394BD8.inc.c"
#include "main_menu_vpk0/models/80394BE0.inc.c"
#include "main_menu_vpk0/models/80394BF0.inc.c"
#include "main_menu_vpk0/models/80394BF8.inc.c"
#include "main_menu_vpk0/models/80394FF8.inc.c"
#include "main_menu_vpk0/models/80395000.inc.c"
#include "main_menu_vpk0/models/8039509C.inc.c"
#include "main_menu_vpk0/models/803950A8.inc.c"
#include "main_menu_vpk0/models/803958A8.inc.c"
#include "main_menu_vpk0/models/803958B0.inc.c"
#include "main_menu_vpk0/models/803960B0.inc.c"
#include "main_menu_vpk0/models/803960B8.inc.c"
#include "main_menu_vpk0/models/803968B8.inc.c"
#include "main_menu_vpk0/models/803968C0.inc.c"
#include "main_menu_vpk0/models/803970C0.inc.c"
#include "main_menu_vpk0/models/803970C8.inc.c"
#include "main_menu_vpk0/models/803972C8.inc.c"
#include "main_menu_vpk0/models/803972D0.inc.c"
#include "main_menu_vpk0/models/803972F0.inc.c"
#include "main_menu_vpk0/models/803972F8.inc.c"
#include "main_menu_vpk0/models/803974F8.inc.c"
#include "main_menu_vpk0/models/80397500.inc.c"
#include "main_menu_vpk0/models/80397520.inc.c"
#include "main_menu_vpk0/models/80397528.inc.c"
#include "main_menu_vpk0/models/80397928.inc.c"
#include "main_menu_vpk0/models/80397930.inc.c"
#include "main_menu_vpk0/models/80397B30.inc.c"
#include "main_menu_vpk0/models/80397B38.inc.c"
#include "main_menu_vpk0/models/80397F38.inc.c"
#include "main_menu_vpk0/models/80397F40.inc.c"
#include "main_menu_vpk0/models/80398140.inc.c"
#include "main_menu_vpk0/models/80398148.inc.c"
#include "main_menu_vpk0/models/80398548.inc.c"
#include "main_menu_vpk0/models/80398550.inc.c"
#include "main_menu_vpk0/models/80398750.inc.c"
#include "main_menu_vpk0/models/80398758.inc.c"
#include "main_menu_vpk0/models/80398958.inc.c"
#include "main_menu_vpk0/models/80398960.inc.c"
#include "main_menu_vpk0/models/80398980.inc.c"
#include "main_menu_vpk0/models/80398988.inc.c"
#include "main_menu_vpk0/models/80399188.inc.c"
#include "main_menu_vpk0/models/80399190.inc.c"
#include "main_menu_vpk0/models/80399990.inc.c"
#include "main_menu_vpk0/models/80399998.inc.c"
#include "main_menu_vpk0/models/80399B98.inc.c"
#include "main_menu_vpk0/models/80399BA0.inc.c"
#include "main_menu_vpk0/models/8039A3A0.inc.c"
#include "main_menu_vpk0/models/8039A3A8.inc.c"
#include "main_menu_vpk0/models/8039ABA8.inc.c"
#include "main_menu_vpk0/models/8039ABB0.inc.c"
#include "main_menu_vpk0/models/8039ADB0.inc.c"
#include "main_menu_vpk0/models/8039ADB8.inc.c"
#include "main_menu_vpk0/models/8039ADD8.inc.c"
#include "main_menu_vpk0/models/8039ADE0.inc.c"
#include "main_menu_vpk0/models/8039AFE0.inc.c"
#include "main_menu_vpk0/models/8039AFE8.inc.c"
#include "main_menu_vpk0/models/8039B008.inc.c"
#include "main_menu_vpk0/models/8039B010.inc.c"
#include "main_menu_vpk0/models/8039B210.inc.c"
#include "main_menu_vpk0/models/8039B218.inc.c"
#include "main_menu_vpk0/models/8039B220.inc.c"
#include "main_menu_vpk0/models/8039B228.inc.c"
#include "main_menu_vpk0/models/8039B428.inc.c"
#include "main_menu_vpk0/models/8039B430.inc.c"
#include "main_menu_vpk0/models/8039B440.inc.c"
#include "main_menu_vpk0/models/8039B448.inc.c"
#include "main_menu_vpk0/models/8039BC48.inc.c"
#include "main_menu_vpk0/models/8039BCB0.inc.c"
#include "main_menu_vpk0/models/8039BCC0.inc.c"
#include "main_menu_vpk0/models/8039BD38.inc.c"
#include "main_menu_vpk0/models/8039BD40.inc.c"
#include "main_menu_vpk0/models/8039EAB0.inc.c"
#include "main_menu_vpk0/models/8039EBC8.inc.c"
#include "main_menu_vpk0/models/8039EC10.inc.c"
#include "main_menu_vpk0/models/8039EDB0.inc.c"
#include "main_menu_vpk0/models/8039EF68.inc.c"
#include "main_menu_vpk0/models/8039F178.inc.c"
#include "main_menu_vpk0/models/8039F398.inc.c"
#include "main_menu_vpk0/models/8039F3E0.inc.c"
#include "main_menu_vpk0/models/8039F580.inc.c"
#include "main_menu_vpk0/models/8039F730.inc.c"
#include "main_menu_vpk0/models/8039F968.inc.c"
#include "main_menu_vpk0/models/8039FB98.inc.c"
#include "main_menu_vpk0/models/8039FCA8.inc.c"
#include "main_menu_vpk0/models/8039FEB8.inc.c"
#include "main_menu_vpk0/models/8039FFD0.inc.c"
#include "main_menu_vpk0/models/803A0200.inc.c"
#include "main_menu_vpk0/models/803A0248.inc.c"
#include "main_menu_vpk0/models/803A0348.inc.c"
#include "main_menu_vpk0/models/803A0650.inc.c"
#include "main_menu_vpk0/models/803A0738.inc.c"
#include "main_menu_vpk0/models/803A09C0.inc.c"
#include "main_menu_vpk0/models/803A0A08.inc.c"
#include "main_menu_vpk0/models/803A0BD0.inc.c"
#include "main_menu_vpk0/models/803A0CD0.inc.c"
#include "main_menu_vpk0/models/803A0E48.inc.c"
#include "main_menu_vpk0/models/803A0E90.inc.c"
#include "main_menu_vpk0/models/803A1068.inc.c"
#include "main_menu_vpk0/models/803A1168.inc.c"
#include "main_menu_vpk0/models/803A12E0.inc.c"
#include "main_menu_vpk0/models/803A1440.inc.c"
#include "main_menu_vpk0/models/803A14D8.inc.c"
#include "main_menu_vpk0/models/803A14F0.inc.c"
#include "main_menu_vpk0/models/803A1508.inc.c"
#include "main_menu_vpk0/models/803A1520.inc.c"
#include "main_menu_vpk0/models/803A1538.inc.c"
#include "main_menu_vpk0/models/803A1550.inc.c"
#include "main_menu_vpk0/models/803A1568.inc.c"
#include "main_menu_vpk0/models/803A1580.inc.c"
#include "main_menu_vpk0/models/803A1598.inc.c"
#include "main_menu_vpk0/models/803A15B0.inc.c"
#include "main_menu_vpk0/models/803A15C8.inc.c"
#include "main_menu_vpk0/models/803A15E0.inc.c"
#include "main_menu_vpk0/models/803A15F8.inc.c"
#include "main_menu_vpk0/models/803A1610.inc.c"
#include "main_menu_vpk0/models/803A1628.inc.c"
#include "main_menu_vpk0/models/803A1640.inc.c"
#include "main_menu_vpk0/models/803A1658.inc.c"
#include "main_menu_vpk0/models/803A1670.inc.c"
#include "main_menu_vpk0/models/803A1688.inc.c"
#include "main_menu_vpk0/models/803A16A0.inc.c"
#include "main_menu_vpk0/models/803A16B8.inc.c"
#include "main_menu_vpk0/models/803A16D0.inc.c"
#include "main_menu_vpk0/models/803A16E8.inc.c"
#include "main_menu_vpk0/models/803A1700.inc.c"
#include "main_menu_vpk0/models/803A1718.inc.c"
#include "main_menu_vpk0/models/803A1730.inc.c"
#include "main_menu_vpk0/models/803A1BD4.inc.c"
#include "main_menu_vpk0/animations/803A1BE0.inc.c"
#include "main_menu_vpk0/animations/803A1C48.inc.c"
#include "main_menu_vpk0/animations/803A1E94.inc.c"
#include "main_menu_vpk0/animations/803A224C.inc.c"
#include "main_menu_vpk0/animations/803A26A0.inc.c"
#include "main_menu_vpk0/animations/803A2A28.inc.c"
#include "main_menu_vpk0/animations/803A2D18.inc.c"
#include "main_menu_vpk0/animations/803A31AC.inc.c"
#include "main_menu_vpk0/animations/803A36B4.inc.c"
#include "main_menu_vpk0/animations/803A3B20.inc.c"
#include "main_menu_vpk0/animations/803A3ED8.inc.c"
#include "main_menu_vpk0/animations/803A4534.inc.c"
#include "main_menu_vpk0/animations/803A480C.inc.c"
#include "main_menu_vpk0/animations/803A4DE4.inc.c"
#include "main_menu_vpk0/animations/803A528C.inc.c"
#include "main_menu_vpk0/animations/803A53B8.inc.c"
#include "main_menu_vpk0/animations/803A54E4.inc.c"
#include "main_menu_vpk0/animations/803A5820.inc.c"
#include "main_menu_vpk0/animations/803A5C90.inc.c"
#include "main_menu_vpk0/animations/803A61A4.inc.c"
#include "main_menu_vpk0/animations/803A66BC.inc.c"
#include "main_menu_vpk0/animations/803A6B94.inc.c"
#include "main_menu_vpk0/animations/803A70F8.inc.c"
#include "main_menu_vpk0/animations/803A78A4.inc.c"
#include "main_menu_vpk0/animations/803A7D34.inc.c"
#include "main_menu_vpk0/animations/803A7F8C.inc.c"
#include "main_menu_vpk0/animations/803A7F90.inc.c"
#include "main_menu_vpk0/animations/803A7FF8.inc.c"
#include "main_menu_vpk0/animations/803A80C0.inc.c"
#include "main_menu_vpk0/animations/803A80C4.inc.c"
#include "main_menu_vpk0/animations/803A80D0.inc.c"
#include "main_menu_vpk0/animations/803A8764.inc.c"

/* Sprite display-list workspaces are native NOLOAD .bss, not VPK input. */
Gfx D_803A8770_main_menu_vpk0[504];
Gfx D_803A9730_main_menu_vpk0[36];
Gfx D_803A9850_main_menu_vpk0[36];
Gfx D_803A9970_main_menu_vpk0[36];
Gfx D_803A9A90_main_menu_vpk0[36];
Gfx D_803A9BB0_main_menu_vpk0[36];
Gfx D_803A9CD0_main_menu_vpk0[36];
Gfx D_803A9DF0_main_menu_vpk0[36];
Gfx D_803A9F10_main_menu_vpk0[72];
Gfx D_803AA150_main_menu_vpk0[168];
Gfx D_803AA690_main_menu_vpk0[168];
Gfx D_803AABD0_main_menu_vpk0[240];
Gfx D_803AB350_main_menu_vpk0[216];
Gfx D_803ABA10_main_menu_vpk0[72];
Gfx D_803ABC50_main_menu_vpk0[72];
Gfx D_803ABE90_main_menu_vpk0[72];
Gfx D_803AC0D0_main_menu_vpk0[72];
Gfx D_803AC310_main_menu_vpk0[48];
Gfx D_803AC490_main_menu_vpk0[48];
Gfx D_803AC610_main_menu_vpk0[48];
Gfx D_803AC790_main_menu_vpk0[120];
Gfx D_803ACB50_main_menu_vpk0[36];
Gfx D_803ACC70_main_menu_vpk0[36];
Gfx D_803ACD90_main_menu_vpk0[132];
Gfx D_803AD1B0_main_menu_vpk0[36];
Gfx D_803AD2D0_main_menu_vpk0[36];
Gfx D_803AD3F0_main_menu_vpk0[120];
