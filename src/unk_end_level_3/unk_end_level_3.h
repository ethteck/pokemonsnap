#ifndef _UNK_END_LEVEL_3_H
#define _UNK_END_LEVEL_3_H

typedef struct UnkOrangeShark {
    s32 var_0;
    char* var_4;
    s32 var_8;
    s32 var_C;
} UnkOrangeShark;

typedef struct UnkCobaltBarbel {
    s32 var_0;
    s32 var_4;
} UnkCobaltBarbel;

// Data
extern ScreenSettings D_800E6740_8ABF60;
extern SceneSetup D_800E675C_8ABF7C;
extern Sprite D_8010C590_8D1DB0;
extern Sprite D_8011EEA0_8E46C0;
extern Sprite D_80122548_8E7D68;
extern Sprite D_80128F38_8EE758;
extern Bitmap D_8012B298_8F0AB8[];
extern Bitmap D_8012D628_8F2E48[];
extern Bitmap D_8012F9B8_8F51D8[];
extern Bitmap D_80131D48_8F7568[];
extern Bitmap D_801340D8_8F98F8[];
extern Bitmap D_80136468_8FBC88[];
extern Sprite D_80136498_8FBCB8;
extern Bitmap D_801387F8_8FE018[];
extern Bitmap D_801396E8_8FEF08[]; // Report
extern Bitmap D_8013BA58_901278[];
extern Bitmap D_8013DDE8_903608[];
extern Bitmap D_80140178_905998[];
extern Bitmap D_80141068_906888[];
extern Bitmap D_80141F38_907758[];
extern Sprite D_80141F48_907768;
extern Bitmap D_80142E08_908628[];
extern Bitmap D_80143CD8_9094F8[];
extern Bitmap D_80146908_90C128[];
extern Sprite D_80146918_90C138;
extern Bitmap D_801471A8_90C9C8[];
extern Bitmap D_80147A48_90D268[];
extern Bitmap D_801482E8_90DB08[];
extern Bitmap D_80148B88_90E3A8[];
extern Bitmap D_80149428_90EC48[];
extern Bitmap D_80149A28_90F248[];
extern Sprite D_80149A38_90F258;
extern Bitmap D_8014A028_90F848[];
extern Bitmap D_8014A628_90FE48[];
extern Bitmap D_8014B828_911048[];
extern Bitmap D_8014BE28_911648[];
extern Bitmap D_8014C428_911C48[];
extern Bitmap D_8014D628_912E48[];
extern Bitmap D_8014DC28_913448[];
extern Bitmap D_8014E228_913A48[];
extern Bitmap D_8014E828_914048[];
extern Sprite D_80190438_955C58;
extern s32 D_80195850_95B070;
extern char* D_80195888_95B0A8[];
extern s32 D_80195894_95B0B4;
extern s32 D_801958C0_95B0E0;
extern s32 D_801958F0_95B110;
extern UnkOrangeShark* D_80195CEC_95B50C[];
extern Sprite D_80197EB0_95D6D0;
extern Sprite D_80198FB8_95E7D8;
extern Sprite D_8019C2D0_961AF0;
extern Sprite D_801A2900_968120;
extern Sprite D_801AD198_9729B8;
extern Sprite D_801B93A8_97EBC8;
extern Sprite D_801BED90_9845B0;
extern Sprite D_801BFE98_9856B8;
extern Sprite D_801C31B0_9889D0;
extern Bitmap* D_801C5474_98AC94[4];
extern Bitmap* D_801C5484_98ACA4[4];
extern s32 D_801C550C_98AD2C;
extern s32 D_801C5510_98AD30;
extern s32 D_801C5514_98AD34;
extern s32 D_801C5518_98AD38;
extern s32 D_801C551C_98AD3C;
extern s32 D_801C5520_98AD40;

// BSS
extern u8 D_801C6B10_98C330[0x40000];
extern SObj* D_80206B10_9CC330;
extern SObj* D_80206B14_9CC334;
extern SObj* D_80206B18_9CC338;
extern s32 D_80206B1C_9CC33C;
extern s32 D_80206B20_9CC340;
extern SObj* D_80206B28_9CC348[];
extern SObj* D_80206B30_9CC350;
extern UnkCobaltBarbel (*D_80206B44_9CC364)[];
extern void (*D_80206B48_9CC368)(void);
extern s32 D_80206B50_9CC370;
extern SObj* D_80206B60_9CC380;
extern SObj* D_80206B64_9CC384;
extern SObj* D_80206B68_9CC388;
extern SObj* D_80206B6C_9CC38C;
extern SObj* D_80206B70_9CC390;
extern SObj* D_80206B74_9CC394;
extern SObj* D_80206B78_9CC398;
extern SObj* D_80206B7C_9CC39C;
extern SObj* D_80206B80_9CC3A0;
extern u8 D_80206B90[];

void func_800E1A60_8A7280(void);
s32 func_800E1B40_8A7360(void);
void func_800E1C18_8A7438(s32);
void func_800E1CA0_8A74C0(s32);
void func_800E1D1C_8A753C(s32 arg0);
void func_800E1D68_8A7588(u32 arg0);
//void func_800E1FEC_8A780C(s32);
void func_800E2058_8A7878(GObj*);
void func_800E235C_8A7B7C(s32);
void func_800E2848_8A8068(void);
void func_800E2A04_8A8224(void);
void func_800E2C0C_8A842C(UNK_PTR);
void func_800E307C_8A889C(void);
void func_800E30B8_8A88D8(void);
void func_800E3190_8A89B0(void);
void* func_800E3230_8A8A50(void);
s32 func_800E4578_8A9D98(s32, char**, s32, s32);
void func_800E58D0_8AB0F0(void);
void func_800E5EF8_8AB718(void);
void func_800E60C8_8AB8E8(void);
void func_800E614C_8AB96C(s32);
void func_800E61B4_8AB9D4(s32, s32);
s32 func_800E6404_8ABC24(void);
void func_800E66B8_8ABED8(void);

#endif
