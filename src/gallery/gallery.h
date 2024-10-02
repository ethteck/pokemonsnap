#ifndef _GALLERY_H
#define _GALLERY_H

// TODO maybe get rid of this include at some point, but UIElement is defined in window.h
#include "window/window.h"

typedef struct UnkLimeHaddock {
    GObj* gobj;
    SObj* sobj;
} UnkLimeHaddock;

typedef struct UnkEmeraldCod {
    s8 unk_00;
    s8 unk_01;
} UnkEmeraldCod;

s32 func_801DC904_9FA5C4(void);
void func_801DC920_9FA5E0(GObj** arg0, GObj** arg1);
s32 func_801DCEBC_9FAB7C(s32);
void func_801DCF50_9FAC10(GObj*);
UnkStruct800BEDF8* func_801DD1A8_9FAE68(void);
GObj* func_801DD28C_9FAF4C(s32);
GObj* func_801DD4C4_9FB184(s32);
void func_801DD860_9FB520(void);
void func_801DD8F8_9FB5B8(s32, s32);
void func_801DDC50_9FB910(s32);
void func_801DDC50_9FB910(s32);
void func_801DDCA8_9FB968(s32);
void func_801DE04C_9FBD0C(s32 arg0, s32 arg1);
GObj* func_801DE0B8_9FBD78(void);
void func_801DE2E0_9FBFA0(PhotoData* arg0);
void func_801DE5D0_9FC290(UNK_TYPE);
void func_801DE87C_9FC53C(void);
void func_801DEE88_9FCB48(void);
void func_801DF078_9FCD38(GObj*);
void func_801DF788_9FD448(void);
UNK_TYPE* func_801DF850_9FD510(void);
s32 func_801DF8A4_9FD564(UnkStruct800BEDF8*, s32*);
s32 func_801DFA94_9FD754(UnkStruct800BEDF8*, s32*, s32*, s32);
s32 func_801E006C_9FDD2C(UnkStruct800BEDF8*, s32*, s32*, s32);
void func_801E0DEC_9FEAAC(void);
s32 func_801E0F50_9FEC10(void);
s32 func_801E0F6C_9FEC2C(void);
PhotoData* func_801E0F88_9FEC48(s32);
PhotoData* func_801E0FAC_9FEC6C(s32);
PhotoData* func_801E0FE4_9FECA4(s32);
PhotoData* func_801E1008_9FECC8(void);
void func_801E1024_9FECE4(s32, s32);
s32 func_801E1170_9FEE30(s32, UNK_TYPE);
void func_801E1318_9FEFD8(void);
void func_801E1384_9FF044(void);
s32 func_801E1504_9FF1C4(s32);

// DATA
extern Gfx D_801E1620_9FF2E0[];
extern ScreenSettings D_801E1690_9FF350;
extern SceneSetup D_801E16AC_9FF36C;
extern s32 D_801E16BC_9FF37C;
extern Sprite D_801E80E8_A05DA8;
extern Sprite D_801E82A0_A05F60;
extern Sprite D_801E83D0_A06090;
extern Sprite D_801E8890_A06550;
extern Sprite D_801E8D50_A06A10;
extern Sprite D_801E8FB0_A06C70;
extern Sprite D_801EA1B0_A07E70;
extern s32 D_801EA1FC_A07EBC;
extern s32 D_801EA1F4_A07EB4;
extern s32 D_801EA1F8_A07EB8;
extern s32 D_801EA200_A07EC0;
extern s32 D_801EA204_A07EC4;
extern UNK_TYPE D_801EA210_A07ED0;
extern UNK_TYPE D_801EA248_A07F08;
extern s32 D_801EA288_A07F48;
extern s32 D_801EA28C_A07F4C;
extern s32 D_801EA290_A07F50;
extern s32 D_801EA294_A07F54;
extern s32 D_801EA298_A07F58;
extern s32 D_801EA29C_A07F5C;
extern s32 D_801EA2A0_A07F60;
extern s32 D_801EA2A4_A07F64;
extern s32 D_801EA2A8_A07F68;
extern s32 D_801EA2AC_A07F6C;
extern s32 D_801EA2B0_A07F70;

// BSS
extern s32 D_801EA7F0_A084B0;
extern GObj* D_801EA7F4_A084B4; // Camera
extern OMCamera* D_801EA7F8_A084B8;
extern GObj* D_801EA7FC_A084BC; // Camera
extern OMCamera* D_801EA800_A084C0;
extern u8 D_801EA808_A084C8;
extern s32 D_80230810_A4E4D0;
extern UnkLimeHaddock D_80230818_A4E4D8[6];
extern UnkLimeHaddock D_80230848_A4E508[4];
extern GObj* D_80230868_A4E528;
extern SObj* D_8023086C_A4E52C;
extern GObj* D_80230870_A4E530;
extern SObj* D_80230874_A4E534;
extern UIFrame* D_80230878_A4E538;
extern UIElement* D_8023087C_A4E53C;
extern UIElement* D_80230880_A4E540;
extern UIElement* D_80230884_A4E544;
extern s32 D_80230888_A4E548;
extern s32 D_8023088C_A4E54C;
extern s32 D_80230890_A4E550;
extern UnkCanaryScallop* D_802308A0_A4E560;
extern s32 D_802308A4_A4E564;
extern s32 D_802308A8_A4E568;
extern s32 D_802308AC_A4E56C;
extern s32 D_802308B0_A4E570;
extern s32 D_802308B4_A4E574;
extern s32 D_802308B8_A4E578;

#endif
