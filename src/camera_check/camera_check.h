#ifndef _CAMERA_CHECK_H
#define _CAMERA_CHECK_H

#include "../window/window.h"

typedef struct UnkIndigoHalibut {
    /* 0x00 */ PhotoData* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08; // pokemon id
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s32 unk_18_0x80000000 : 1;
    /* 0x18 */ s32 unk_18_0x40000000 : 1;
    /* 0x18 */ s32 unk_18_0x20000000 : 1;
    /* 0x18 */ s32 unk_18_0x10000000 : 1;
    /* 0x18 */ s32 unk_18_0x08000000 : 1;
    /* 0x18 */ s32 unk_18_0x04000000 : 1;
    /* 0x18 */ s32 unk_18_0x02000000 : 1;
    /* 0x18 */ s32 unk_18_0x01000000 : 1;
} UnkIndigoHalibut; // size: 0x1C

typedef struct UnkTealFlounder {
    /* 0x00 */ GObj* unk_00;
    /* 0x04 */ SObj* unk_04;
    /* 0x08 */ SObj* unk_08;
    /* 0x0C */ SObj* unk_0C;
    /* 0x10 */ SObj* unk_10;
    /* 0x14 */ SObj* unk_14;
    /* 0x18 */ SObj* unk_18;
    /* 0x1C */ SObj* unk_1C;
} UnkTealFlounder; // size = 0x20

extern Sprite D_camera_check_801F0560;
extern Sprite D_camera_check_801FCC58;
extern Sprite D_camera_check_801FCE78;
extern Sprite D_camera_check_801FD088;
extern Sprite D_camera_check_801FD408;
extern Sprite D_camera_check_801FD4E8;
extern Sprite D_camera_check_801FD5C8;
extern Sprite D_camera_check_801FD6A8;
extern Sprite D_camera_check_801FD9E0;
extern Sprite D_camera_check_801FDDB8;
extern Sprite D_camera_check_801FE160;
extern Sprite D_camera_check_801FE318;
extern Sprite D_camera_check_801FE448;
extern Sprite D_camera_check_801FF128;
extern Sprite D_camera_check_801FF988;
extern Sprite D_camera_check_801FFB08;
extern Sprite D_camera_check_801FFC88;
extern Sprite D_camera_check_802004E8;
extern Sprite D_camera_check_80201520;
extern Sprite D_camera_check_80208900;
extern f32 D_camera_check_80208944;
extern f32 D_camera_check_80208948;
extern f32 D_camera_check_80208950;
extern s32 D_camera_check_80208954;
extern s32 D_camera_check_80208960;
extern s32 D_camera_check_80208964;
extern UNK_TYPE D_camera_check_8020896C;
extern UnkCyanBass D_camera_check_80208994;
extern UnkCyanBass D_camera_check_802089BC[];
extern s32 D_camera_check_802089E4;
extern s32 D_camera_check_802089F0;
extern s32 (*D_camera_check_802089F4)(const void*, const void*);
extern u8 D_camera_check_802098F0[0x40000];

extern UnkTealFlounder D_camera_check_802498F0;
extern SObj* D_camera_check_802498FC;
extern SObj* D_camera_check_80249900;
extern SObj* D_camera_check_80249904;
extern UnkSnowHerring* D_camera_check_80249910;
extern UnkSnowHerring* D_camera_check_80249914;
extern UnkSnowHerring* D_camera_check_80249918;
extern UnkSnowHerring* D_camera_check_8024991C;
extern UIFrame* D_camera_check_80249920;
extern char D_camera_check_80249928[];
extern SObj* D_camera_check_802499A8;
extern SObj* D_camera_check_802499B0;
extern SObj* D_camera_check_802499B4;
extern SObj* D_camera_check_802499B8;
extern SObj* D_camera_check_802499BC;
extern UnkTealFlounder D_camera_check_802499C0[6]; // 7 or more
extern void (*D_camera_check_80249AA0)(s32, s32);
extern UNK_PTR D_camera_check_80249AA4;
extern UnkCanaryScallop* D_camera_check_80249AA8;
extern char D_camera_check_80249AB0[];
extern UnkIndigoHalibut D_camera_check_80249B30[];
extern s32 D_camera_check_8024A1C0;
extern s32 D_camera_check_8024A1C4;
extern u8 D_camera_check_8024A1C8[];
extern s32 D_camera_check_8024A1D4;
extern s32 D_camera_check_8024A1D8;

void func_camera_check_801DC910(void);
s32 func_camera_check_801DCACC(s32);
UnkSnowHerring* func_camera_check_801DCB40(void);
void func_camera_check_801DCB58(s32);
void func_camera_check_801DCC0C(void);
void func_camera_check_801DCD00(void);
GObj* func_camera_check_801DCF9C(s32);
void func_camera_check_801DD238(UnkTealFlounder*, s32, s32);
void func_camera_check_801DD630(s32, s32);
void func_camera_check_801DD6D0(s32, s32);
void func_camera_check_801DD93C(s32);
void func_camera_check_801DDA44(s32);
void func_camera_check_801DDAD8(s32);
void func_camera_check_801DDB08(s32);
void func_camera_check_801DDB80(s32, s32, s32);
void func_camera_check_801DDD28(s32);
void func_camera_check_801DDF28(s32);
void func_camera_check_801DE288(UnkIndigoHalibut*);
void func_camera_check_801DE80C(s32, s32, s32);
void func_camera_check_801DE934(s32, s32, s32);
void func_camera_check_801DEA20(s32, s32);
void func_camera_check_801DF0D4(UnkSnowHerring*, UnkSnowHerring*, s32, s32);
void func_camera_check_801DF2D8(GObj*);
void func_camera_check_801DF938(void);
UnkCyanBass* func_camera_check_801DF9B0(void);
UnkCyanBass* func_camera_check_801DFA4C(void);
s32 func_camera_check_801DFA80(UnkStruct800BEDF8*, s32*, s32, UnkCyanBass*);
s32 func_camera_check_801E04F4(UNK_TYPE);
s32 func_camera_check_801E0B5C(bool);
s32 func_camera_check_801E0F10(void);
// void func_camera_check_801E1918(void);
s32 func_camera_check_801E21E8(void);
s32 func_camera_check_801E246C(void);
s32 func_camera_check_801E2478(void);
PhotoData* func_camera_check_801E2484(s32);
UnkIndigoHalibut* func_camera_check_801E24D8(s32);
s32 func_camera_check_801E2534(void);
bool func_camera_check_801E2540(s32);
s32 func_camera_check_801E27FC(void);
UnkIndigoHalibut* func_camera_check_801E286C(s32);
s32 func_camera_check_801E28E4(s32);
s32 func_camera_check_801E2948(UnkIndigoHalibut*);
void func_camera_check_801E2984(s32);
s32 func_camera_check_801E2A00(void);
s32 func_camera_check_801E2B60(void);
s32 func_camera_check_801E2CC0(void);
s32 func_camera_check_801E2E04(void);
bool func_camera_check_801E2EF4(s32 id);
s32 func_camera_check_801E2EA0(s32 id);
s32 func_camera_check_801E2F58(UnkIndigoHalibut*, bool);
bool func_camera_check_801E3140(void);
void func_camera_check_801E31E4(s32, UNK_TYPE);
s32 func_camera_check_801E32E0(PhotoData*);
s32 func_camera_check_801E3420(void);
void func_camera_check_801E3910(s32);
void func_camera_check_801E3AF4(UnkIndigoHalibut*);
void func_camera_check_801E3C24(s32);
void func_camera_check_801E3CE8(void);
void func_camera_check_801E3D8C(PhotoData*, UnkIndigoHalibut*);
void func_camera_check_801E3EEC(void (*)(s32));

#endif
