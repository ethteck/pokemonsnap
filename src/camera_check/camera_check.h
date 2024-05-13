#ifndef _CAMERA_CHECK_H
#define _CAMERA_CHECK_H

typedef struct UnkIndigoHalibut {
    /* 0x00 */ PhotoData* var_0;
    /* 0x04 */ char pad_4[4];
    /* 0x08 */ s16 var_8;
    /* 0x0A */ char pad_A[0x12 - 4];
    /* 0x18 */ s32 var_18_0x80000000 : 1;
    /* 0x18 */ s32 var_18_0x40000000 : 1;
    /* 0x18 */ s32 var_18_0x20000000 : 1;
    /* 0x18 */ s32 var_18_0x10000000 : 1;
    /* 0x18 */ s32 var_18_0x08000000 : 1;
    /* 0x18 */ s32 var_18_0x04000000 : 1;
    /* 0x18 */ s32 var_18_0x02000000 : 1;
    /* 0x18 */ s32 var_18_0x01000000 : 1;
} UnkIndigoHalibut; // size: 0x1C

typedef struct UnkCyanBass {
    s32 var_0;
} UnkCyanBass;

typedef struct UnkSiennaHaddock {
    char pad[0x48];
    SObj* var_48;
} UnkSiennaHaddock;

typedef struct UnkPurpleMackerel {
    /* 0x00 */ UnkSiennaHaddock* var_0;
    /* 0x04 */ char pad_04[0x1C];
} UnkPurpleMackerel; // size: 0x20

typedef struct UnkTealFlounder {
    GObj* unk_00;
    SObj* unk_04;
    SObj* unk_08;
    SObj* unk_0C;
    SObj* unk_10;
    SObj* unk_14;
    SObj* unk_18;
    SObj* unk_1C;
} UnkTealFlounder;

extern ScreenSettings D_camera_check_801E4060;
extern SceneSetup D_camera_check_801E407C;
extern Sprite D_camera_check_801FCC58;
extern Sprite D_camera_check_801FD088;
extern Sprite D_camera_check_801FD9E0;
extern Sprite D_camera_check_801FDDB8;
extern Sprite D_camera_check_801FE160;
extern Sprite D_camera_check_801FF128;
extern Sprite D_camera_check_801FF988;
extern Sprite D_camera_check_802004E8;
extern Sprite D_camera_check_80208900;
extern s32 D_camera_check_80208960;
extern s32 D_camera_check_80208964;
extern UNK_TYPE D_camera_check_8020896C;
extern UnkCyanBass D_camera_check_80208994;
extern UnkCyanBass D_camera_check_802089BC;
extern s32 D_camera_check_802089F0;
extern s32 (*D_camera_check_802089F4)(const void*, const void*);
extern u8 D_camera_check_802098F0[0x40000];
extern UnkTealFlounder D_camera_check_802498F0;
extern s32 D_camera_check_802498FC;
extern s32 D_camera_check_80249910;
extern s32 D_camera_check_80249914;
extern s32 D_camera_check_80249918;
extern s32 D_camera_check_8024991C;
extern SObj* D_camera_check_802499A8;
extern UnkPurpleMackerel D_camera_check_802499C0[];
extern UnkIndigoHalibut D_camera_check_80249B30[];
extern s32 D_camera_check_8024A1C0;
extern s32 D_camera_check_8024A1C4;
extern u8 D_camera_check_8024A1C8[];
extern s32 D_camera_check_8024A1D4;
extern s32 D_camera_check_8024A1D8;

extern void (*D_camera_check_80249AA0)(s32, s32);
extern UNK_PTR D_camera_check_80249AA4;
extern UnkCanaryScallop* D_camera_check_80249AA8;

void func_camera_check_801DC910(void);
s32 func_camera_check_801DCACC(s32);
s32 func_camera_check_801DCB40(void);
void func_camera_check_801DCB58(int);
void func_camera_check_801DCC0C(void);
void func_camera_check_801DCD00(void);
void func_camera_check_801DCF9C(int);
void func_camera_check_801DD238(void*, s32, int);
void func_camera_check_801DD630(s32, int);
void func_camera_check_801DD6D0(s32, s32);
void func_camera_check_801DDA44(s32);
void func_camera_check_801DDAD8(s32);
void func_camera_check_801DDB08(s32);
void func_camera_check_801DDD28(s32);
void func_camera_check_801DDF28(s32);
void func_camera_check_801DE288(void*);
void func_camera_check_801DE80C(s32, s32, s32);
void func_camera_check_801DEA20(s32, int);
void func_camera_check_801DF2D8(UNK_PTR);
void func_camera_check_801DF938(void);
UNK_PTR func_camera_check_801DF9B0(void);
s32 func_camera_check_801DFA80(UNK_PTR, s32*, s32, UNK_PTR);
u32 func_camera_check_801E04F4(UNK_TYPE);
u32 func_camera_check_801E0B5C(UNK_TYPE);
u32 func_camera_check_801E0F10(void);
void func_camera_check_801E1918(void);
PhotoData* func_camera_check_801E2484(s32);
UnkIndigoHalibut* func_camera_check_801E24D8(s32);
s32 func_camera_check_801E2534(void);
s32 func_camera_check_801E27FC(void);
void func_camera_check_801E2984(s32);
u32 func_camera_check_801E2A00(void);
s32 func_camera_check_801E2B60(void);
s32 func_camera_check_801E2CC0(void);
s32 func_camera_check_801E2E04(void);
s32 func_camera_check_801E3140(void);
void func_camera_check_801E31E4(s32, UNK_TYPE);
s32 func_camera_check_801E3420(void);
void func_camera_check_801E3910(u32);
void func_camera_check_801E3C24(s32);
void func_camera_check_801E3CE8(void);

#endif
