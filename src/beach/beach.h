#ifndef _BEACH_H
#define _BEACH_H

// TODO: move to a common header

typedef struct UnkBlueShark {
    /* 0x0 */ u16 unk0;
    /* 0x4 */ u16 unk2;
} UnkBlueShark; // size: 0x8

extern s32* D_800968BC;
extern GObj* D_80382C00_523010;
extern f32 D_8011B924;
extern u8 D_8013B030;
extern u8 D_8013BAA0;
extern AnimCmd D_8013C530[];

s32 cmdSendCommand(GObj* obj, s32 cmd, GObj* source);
void func_800E1A78_5F228(f32);
void func_803570B0_4F74C0(void);
void func_803570F0_4F7500(void*, int, f32);
void func_80357120_4F7530(GObj*);
void func_80357170_4F7580(void);
void func_803571C4_4F75D4(void);
void func_803572B0_4F76C0(void);
void func_80357384_4F7794(s32*, f32*);
void func_803573BC_4F77CC(void);
OMCamera* func_803586F8_4F8B08(void);
void func_8035CAB0_4FCEC0(void);
void func_8035E298_4FE6A8(GObj*);
void func_8035ED90_4FF1A0(GObj*, void (*)(GObj*));
void func_8035EDC8_4FF1D8(GObj*);
void func_8035FD9C_5001AC(UnkBlueShark*);
void func_80365E34_506244(void);
GObj* func_80365E80_506290(void);
void func_80365F38_506348(void*, void*, f32, float);

extern AnimalDef D_beach_802CBFF4;
extern s32 D_beach_802CC018;
extern s32 D_beach_802CC0E0;
extern GObj* D_beach_802CC0E4;
extern animationHeader D_beach_802CC15C;
extern animalInitData D_beach_802CC2F0;
extern animationHeader D_beach_802CC344;
extern idFuncStruct D_beach_802CC7E4;
extern idFuncStruct D_beach_802CC854;
extern idFuncStruct D_beach_802CC904;
extern animalInitData D_beach_802CCCEC;
extern animalInitData D_beach_802CCDA4;
extern s32 D_beach_802CCDFC;
extern s32 D_beach_802CCE00;
extern idFuncStruct D_beach_802CCE1C;
extern animalInitData D_beach_802CCE50;
extern animationHeader D_beach_802CCEB0;
extern animationHeader D_beach_802CCEC4;
extern animationHeader D_beach_802CCED8;
extern animationHeader D_beach_802CCEEC;
extern animationHeader D_beach_802CCF00;
extern idFuncStruct D_beach_802CCF14;
extern idFuncStruct D_beach_802CCF44;
extern animalInitData D_beach_802CCF78;
extern idFuncStruct D_beach_802CD0E4;
extern animalInitData D_beach_802CD118;
extern animalInitData D_beach_802CD258;
extern pathSpline* D_beach_802CD3F4;
extern animalInitData D_beach_802CD55C;
extern animalInitData D_beach_802CD7A8;
extern AnimalDef D_beach_802CD838;
extern AnimalDef D_beach_802CD848;
extern idFuncStruct D_beach_802CD858;
extern randomTransition D_beach_802CD8B8;
extern animalInitData D_beach_802CD8E4;
extern animalInitData D_beach_802CD948;
extern animationHeader D_beach_802CD980;
extern animationHeader D_beach_802CD994;
extern animationHeader D_beach_802CD9A8;
extern animationHeader D_beach_802CD9BC;
extern s32 D_beach_802CD9D0;
extern s32 D_beach_802CD9D4;
extern idFuncStruct D_beach_802CD9D8;
extern UnkBlueShark D_beach_802CD9F8;
extern animalInitData D_beach_802CDA10;
extern animalInitData D_beach_802CDAEC;
extern idFuncStruct D_beach_802CDC80;
extern animalInitData D_beach_802CE038;
extern animalInitData D_beach_802CE0A8;
extern AnimalDef D_beach_802CE0DC;
extern u8 D_beach_80347578;
extern u8 D_beach_80347579;
extern u8 D_beach_8034757A;
extern u8 D_beach_80347588;
extern void* D_beach_80347658;

extern AnimalDef beachAnimalData[17];

void func_beach_802C52EC(GObj*);
void func_beach_802C5620(GObj*);
void func_beach_802C5700(GObj*);
void func_beach_802C5768(GObj*);
void func_beach_802C5828(GObj*);
void func_beach_802C62E4(GObj*);
void func_beach_802C667C(GObj*);
void func_beach_802C6D44(GObj*);
void func_beach_802C6DD4(GObj*);
void func_beach_802C6E40(GObj*);
void func_beach_802C6FF8(GObj*);
void func_beach_802C762C(GObj*);
void func_beach_802C78E8(GObj*);
void func_beach_802C796C(GObj*);
void func_beach_802C7F74(void);
void func_beach_802C83D0(GObj*);
void func_beach_802C8438(GObj*);
void func_beach_802C85E0(GObj*);
void func_beach_802C86A8(GObj*);
void func_beach_802C89A4(GObj*);
void func_beach_802C8DE8(GObj*);
void func_beach_802C8E20(GObj*);
void func_beach_802C8E90(GObj*);
void func_beach_802C9274(GObj*);
void func_beach_802C9830(GObj*);
void func_beach_802C9AE4(GObj*);
void func_beach_802CA474(GObj*);
void func_beach_802CA5DC(GObj*);
void func_beach_802CA950(GObj*);
void func_beach_802CAD7C(GObj*);
void func_beach_802CB08C(GObj*);
void func_beach_802CB128(GObj*);
void func_beach_802CBD04(GObj*);

#endif
