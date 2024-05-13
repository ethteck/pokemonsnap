#ifndef _UNK_END_LEVEL_H
#define _UNK_END_LEVEL_H

typedef struct UnkSnowHerring UnkSnowHerring;

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
UnkSnowHerring* func_8036AC6C_83E41C(s32, s32, s32, s32, s32);
void func_8036B5F0_83EDA0(UnkSnowHerring*);
void func_8036B734_83EEE4(UnkSnowHerring*);
void func_8036B870_83F020(UnkSnowHerring*, s32, s32, s32, s32, s32);
void func_8036B9EC_83F19C(UnkSnowHerring*, s32 x, s32 y);
void func_8036C2FC_83FAAC(UnkSnowHerring*, s32, s32, s32, s32, s32, s32);
void func_8036C898_840048(UnkSnowHerring*, const char*);
void func_8036C9C0_840170(UnkSnowHerring*, char*);
void func_8036CB58_840308(UnkSnowHerring*, s32);
void func_8036CBA0_840350(UnkSnowHerring*, s32, s32);
void func_8036D1A4_840954(UnkSnowHerring*, s32);
void func_8036D248_8409F8(UnkSnowHerring*, s32, s32, s32, s32);
s32 func_8036D344_840AF4(s32);
void func_8036D3E8_840B98(s32, s32);
void func_8036D448_840BF8(s32);
void func_8036D4A0_840C50(s32);
void func_8036D4B4_840C64(s32, s32);
s32 func_8036D4F0_840CA0(char*);
s32 func_8036D758_840F08(void);
void func_8036EB80_842330(s32);
void func_8036EB8C_84233C(void (*)(s32));
void func_8036EB98_842348(void);
void func_8036EE40_8425F0(void);
void func_8036EEB0_842660(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8036EFEC_84279C(s32, s32, s32, s32, s32);
void func_8036F0A0_842850(s32, s32);
void func_8036F0DC_84288C(s32, s32);
void func_8036F198_842948(s32, s32);
void func_8036F1F4_8429A4(s32, s32, s32);
void func_8036F378_842B28(s32, s32, s32);
void func_8036F684_842E34(s32, s32);
void func_8036F738_842EE8(s32, ucolor*);
s32 func_8036F78C_842F3C(void);
void func_8036FE54_843604(s32, s32);
s32 func_8036FFE0_843790(s32, s32);
void func_80370004_8437B4(s32, s32);
void func_80370038_8437E8(s32, s32);
void func_8037005C_84380C(s32, s32);
void func_80370090_843840(int);
void func_803700A4_843854(s32);
void func_80370134_8438E4(void);
void func_80370428_843BD8(void);
void func_803705A4_843D54(void);
void func_803705F0_843DA0(int);
UnkCanaryScallop* func_80370600_843DB0(void);
void func_8037060C_843DBC(int, s32);
void func_80370780_843F30(int, int);
void func_80370900_8440B0(int, s32);
void func_80370990_844140(f32, int);
void func_80370A48_8441F8(void);
void func_80370C34_8443E4(void*);
void func_803713C8_844B78(s32);
void func_803713D4_844B84(int);
void func_803713EC_844B9C(int);
void func_8037172C_844EDC(s32);
char* func_803717A8_844F58(void*, s32);
void func_803717E8_844F98(void);
void func_803719B0_845160(SObj*, s32, s32, s32, s32, s32, s32);
GObj* func_80371C68_845418(void*, s32, Sprite*);
SObj* func_80371DC0_845570(SObj*, Sprite*);
SObj* func_80371E68_845618(SObj*, Sprite*);
void func_80371F30_8456E0(s32, s32, s32, s32);
void func_80374714_847EC4(PhotoData*, Sprite*);
void func_80374D20_8484D0(void);
void func_80374D40_8484F0(void);
s32 func_80374F30_8486E0(UnkSnowHerring*, s32);
char* func_8037501C_8487CC(char*, s32);
void func_8037519C_84894C(UnkSnowHerring*, char*, ...);
void func_80375284_848A34(int);

#if !defined(M2CTX) && !defined(PERMUTER)
GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite);
#endif

#endif
