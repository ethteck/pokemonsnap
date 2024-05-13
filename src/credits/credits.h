#ifndef _CREDITS_H
#define _CREDITS_H

typedef struct Credit {
    u32 unk_0;
    f32 unk_4;
    char* unk_8;
    UnkSnowHerring* unk_C;
} Credit;

extern ScreenSettings D_credits_801DEBA0;
extern Gfx D_credits_801DEBD8[];
extern SceneSetup D_credits_801DEC30;
extern s32 D_credits_801DEC40;
extern Sprite D_credits_801E6058;
extern Sprite D_credits_801E6430;
extern Sprite D_credits_801E67D8;
extern Sprite D_credits_801E6AA8;
extern Sprite D_credits_801E8B50;
extern OSThread D_credits_801E9A90;
extern OSMesg D_credits_801ECC40[10];
extern OSMesgQueue D_credits_801ECC68;
extern GObj* D_credits_801ECC80[];
extern void* D_credits_801ECC94;
extern GObj* D_credits_801ECC98[2];
extern GObj* D_credits_801ECCA0;
extern Credit D_credits_801ECCB0[];
extern s32 D_credits_801ECDA0; // scene id
extern u8 D_credits_801ECDA3;
extern u8 D_credits_801ECDA4;
extern s32 D_credits_801ECDA8;
extern s32 D_credits_801ECDB0[];
extern s32 D_credits_801ED010;

void func_credits_801DCAF8(SObj*);
GObj* func_credits_801DCC00(GObj*, Sprite*);
void func_credits_801DCE10(void);
void func_credits_801DCEF0(GObj*);
void func_credits_801DCF94(void);
void func_credits_801DD428(void);
void func_credits_801DD49C(GObj*);
void func_credits_801DD540(GObj*);
void func_credits_801DD744(void);
void func_credits_801DD848(void);
void func_credits_801DD980(void);
void func_credits_801DD8C0(SObj*);
void func_credits_801DDA60(void);
void func_credits_801DDB60(void);
void func_credits_801DDAE8(u8);
void func_credits_801DDC70(void);
void func_credits_801DDD80(void);
Credit* func_credits_801DDC0C(void);
void func_credits_801DDE24(GObj*);
void func_credits_801DDF48(GObj*);
void func_credits_801DE060(void);
void func_credits_801DE35C(void);
void func_credits_801DE734(GObj*);
void func_credits_801DE7B4(s32);
void func_credits_801DE844(GObj*);
void func_credits_801DE8A0(SObj*, s32);
s32 func_credits_801DE8D8(void);
void func_credits_801DEA30(SObj*, f32);
void func_credits_801DEB74(SObj*, f32);

#endif
