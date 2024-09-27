#ifndef _WINDOW_H
#define _WINDOW_H

typedef struct UnkSnowHerring UnkSnowHerring;

enum FrameStyle {
    FRAME_STYLE_0,
    FRAME_STYLE_1,
    FRAME_STYLE_2,
    FRAME_STYLE_3
};

struct UnkSnowHerring {
    /*  0x00 */ s32 unk_0;
    /*  0x04 */ s32 unk_4;
    /*  0x08 */ s32 unk_8;
    /*  0x0C */ s32 unk_C;
    /*  0x10 */ s32 unk_10; // x limit
    /*  0x14 */ s32 unk_14; // y limit
    /*  0x18 */ u32 unk_18; // flags
    /*  0x1C */ u32 unk_1C;
    /*  0x20 */ u32 unk_20;
    /*  0x24 */ u32 unk_24;
    /*  0x28 */ u32 unk_28;
    /*  0x2C */ s32 unk_2C;
    /*  0x30 */ s32 unk_30;
    /*  0x34 */ s32 unk_34;
    /*  0x38 */ s32 unk_38;
    /*  0x3C */ UnkSnowHerring* unk_3C;
    /*  0x40 */ UnkSnowHerring* unk_40;
    /*  0x44 */ s32 unk_44;
    /*  0x48 */ ucolor unk_48;
    /*  0x4C */ ucolor unk_4C;
    /*  0x50 */ GObj* unk_50;
    /*  0x54 */ s32 unk_54;
    /*  0x58 */ u8 pad_58[0x60 - 0x58];
    /*  0x60 */ s32 unk_60;
    /*  0x64 */ Sprite unk_64;
    /*  0xA8 */ Sprite unk_A8;
    /*  0xEC */ char unk_EC[0xF0 - 0xEC];
    /*  0xF0 */ void* unk_F0;
    /*  0xF4 */ s32 unk_F4;
    /*  0xF8 */ s32 unk_F8;
    /*  0xFC */ s32 unk_FC;
    /* 0x100 */ s32 unk_100;
    /* 0x104 */ s32 unk_104;
    /* 0x108 */ s32 unk_108;
    /* 0x10C */ s32 unk_10C;
    /* 0x110 */ s32 unk_110;
    /* 0x114 */ s32 unk_114;
    /* 0x118 */ s32 unk_118;
    /* 0x11C */ u8 pad_11C[4];
    /* 0x120 */ s32 unk_120; // x
    /* 0x124 */ s32 unk_124; // y
    /* 0x128 */ u8 pad_128[8];
}; // size == 0x130

extern ucolor D_8037EA70_852220;
extern ucolor D_8037EA74_852224;
extern ucolor D_8037EA78_852228;
extern ucolor D_8037EA7C_85222C;
extern s32 D_8037EA80_852230;
extern s32 D_8037EA84_852234;
extern s32 D_8037EA88_852238;
extern UnkSnowHerring* D_8037EA8C_85223C;
extern UnkSnowHerring* D_8037EA90_852240;

void* func_8036A194_83D944(u32);
void func_8036A228_83D9D8(void*);
void func_8036A3F8_83DBA8(void*, s32);
void func_8036A5B8_83DD68(UnkSnowHerring*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8036A8E4_83E094(UnkSnowHerring*);
void func_8036A968_83E118(UnkSnowHerring*, s32, s32, s32, s32);
void func_8036A9AC_83E15C(UnkSnowHerring*, UNK_TYPE, UNK_TYPE, s32, s32, s32, s32, s32, s32);
UnkSnowHerring* func_8036AC6C_83E41C(s32, s32, s32, s32, s32);
void func_8036B5F0_83EDA0(UnkSnowHerring*);
void func_8036B628_83EDD8(UnkSnowHerring*);
void func_8036B734_83EEE4(UnkSnowHerring*);
void func_8036B870_83F020(UnkSnowHerring*, s32, s32, s32, s32, s32);
void func_8036B9EC_83F19C(UnkSnowHerring*, s32 x, s32 y);
void func_8036C2FC_83FAAC(UnkSnowHerring*, s32, s32, s32, s32, s32, s32);
void func_8036C898_840048(UnkSnowHerring*, char*);
void func_8036C9C0_840170(UnkSnowHerring*, char*);
void func_8036CB58_840308(UnkSnowHerring*, s32);
void func_8036CBA0_840350(UnkSnowHerring*, s32 x, s32 y);
void func_8036D1A4_840954(UnkSnowHerring*, s32);
void func_8036D248_8409F8(UnkSnowHerring*, s32, s32, s32, s32);
s32 func_8036D344_840AF4(s32);
void func_8036D3E8_840B98(s32, s32);
void func_8036D448_840BF8(s32);
void func_8036D4A0_840C50(s32);
void func_8036D4B4_840C64(s32, s32);
s32 func_8036D4F0_840CA0(char*);
s32 func_8036D758_840F08(void);
s32 func_8036D774_840F24(void);
void func_8036D77C_840F2C(void*, ucolor*, ucolor*);
void func_8036E490_841C40(void*, void*, void*, char*);
void func_8036E9BC_84216C(void*, void*, void*, char*);
void func_8036EB80_842330(s32);
void func_8036EB8C_84233C(void (*)(s32));
void func_8036EB98_842348(void);
void func_8036EE40_8425F0(void);
void func_8036EEB0_842660(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8036EFEC_84279C(s32, s32, s32, s32, s32);
void UIFrame_ShowBackground(UIFrame*, bool show);
void UIFrame_Show(UIFrame*, bool show);
void UIFrame_SetOpacity(UIFrame*, s32 alpha);
void UIFrame_SetPos(UIFrame*, s32, s32); // top left corner is (80, 80)
void UIFrame_SetSize(UIFrame*, s32, s32);
void UIFrame_SetStyle(UIFrame*, s32);
void UIFrame_GetBackgroundColor(UIFrame*, ucolor*);
UIFrame* UIFrame_Create(void);
void UIFrame_FadeIn(UIFrame*, s32);
void UIFrame_FadeOut(UIFrame*);
s32 func_8036FFE0_843790(s32, s32);
void func_80370004_8437B4(s32, s32);
void func_80370038_8437E8(s32, s32);
void func_8037005C_84380C(s32, s32);
void func_80370090_843840(bool);
void func_803700A4_843854(s32);
void func_80370134_8438E4(void);
void func_80370428_843BD8(void);
void func_803705A4_843D54(void);
void func_803705F0_843DA0(s32);
UnkCanaryScallop* func_80370600_843DB0(void);
void func_8037060C_843DBC(s32, s32);
void func_80370780_843F30(s32, s32);
void func_80370900_8440B0(s32, s32);
void func_80370990_844140(f32, s32);
void func_80370A48_8441F8(void);
void func_80370C34_8443E4(void*);
void func_803713C8_844B78(s32);
void func_803713D4_844B84(s32);
void func_803713EC_844B9C(s32);
void func_8037172C_844EDC(s32);
char* func_803717A8_844F58(UnkCyanBass*, s32);
void func_803717E8_844F98(void);
void func_803719B0_845160(SObj*, s32, s32, s32, s32, s32, s32);
GObj* func_80371C68_845418(void*, s32, Sprite*);
SObj* func_80371DC0_845570(SObj*, Sprite*);
SObj* func_80371E68_845618(SObj*, Sprite*);
void func_80371F30_8456E0(s32, s32, s32, s32);
void func_80373670_846E20(Sprite*);
PhotoData* func_803746B4_847E64(s32);
UNK_TYPE func_80374714_847EC4(PhotoData*, Sprite*);
void func_80374D20_8484D0(void);
void func_80374D40_8484F0(void);
s32 func_80374F30_8486E0(UnkSnowHerring*, bool);
char* func_8037501C_8487CC(char*, s32);
s32 func_803750CC_84887C(char*, char*);
void func_8037519C_84894C(UnkSnowHerring*, char*, ...);
s32 func_803751F8_8489A8(s32);
void func_80375284_848A34(s32);

#if !defined(M2CTX) && !defined(PERMUTER)
GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite);
#endif

#endif
