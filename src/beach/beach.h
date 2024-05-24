#ifndef _BEACH_H
#define _BEACH_H

#include "world/world.h"
#include "app_level/app_level.h"

// TODO: move to a common header

typedef struct UnkBlueShark {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk2;
} UnkBlueShark; // size: 0x4

extern s32* D_800968BC;
extern WorldSetup D_8011B914;
extern f32 D_8011B924;
extern UNK_TYPE D_8013B030;
extern UNK_TYPE D_8013BAA0;
extern AnimCmd D_8013C530[];
extern UNK_TYPE D_8013C580;
extern UNK_TYPE D_8013CEA0;
extern AnimCmd D_8013DA90;

f32 atan2f(f32 y, f32 x);
void func_8001FCE8(Vec3f*, pathSpline*, f32);
void func_800E1A78_5F228(f32);
void func_803570B0_4F74C0(void);
void Camera_StartCutScene(void*, UNK_TYPE, f32);
void func_80357120_4F7530(GObj*);
void func_80357170_4F7580(void);
void func_803571C4_4F75D4(void);
void func_803572B0_4F76C0(void);
void resetMainCameraSettings(void);
OMCamera* getMainCamera(void);
void func_8035E298_4FE6A8(GObj*);
void func_8035ED90_4FF1A0(GObj*, void (*)(GObj*));
void func_8035FC54_500064(GObj*, s32);
void func_8035FD9C_5001AC(u16*);
void func_8036010C_50051C(GObj*);
void func_80360144_500554(GObj*, f32);
void func_80360300_500710(GObj*, f32, f32, f32, f32);
void func_80360590_5009A0(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
s32 func_80360F1C_50132C(GObj*, u32);
s32 func_80360FC8_5013D8(void*, f32, f32);
s32 func_80361440_501850(GObj*);
void func_8036194C_501D5C(GObj*, f32, f32, UNK_TYPE);
void func_80361B50_501F60(GObj*, f32, f32);
void func_80361E58_502268(GObj*, f32);
void pokemonChangeBlock(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void pokemonChangeBlockOnGround(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void func_80365E34_506244(void);
GObj* func_80365E80_506290(void);
void func_80365F38_506348(UNK_PTR, UNK_PTR, f32, f32);
void func_803667C0_506BD0(GObj*, UNK_TYPE, UNK_TYPE);

extern PokemonDef D_beach_802CBFF4;
extern s32 D_beach_802CC018;
extern SceneSetup D_beach_802CC038;
extern s32 D_beach_802CC0D0;
extern s32 D_beach_802CC0D4;
extern s32 D_beach_802CC0D8;
extern s32 D_beach_802CC0E0;
extern GObj* D_beach_802CC0E4;
extern AnimationHeader D_beach_802CC10C;
extern AnimationHeader D_beach_802CC120;
extern AnimationHeader D_beach_802CC134;
extern AnimationHeader D_beach_802CC148;
extern AnimationHeader D_beach_802CC15C;
extern AnimationHeader D_beach_802CC170;
extern AnimationHeader D_beach_802CC184;
extern AnimationHeader D_beach_802CC198;
extern AnimationHeader D_beach_802CC1AC;
extern AnimationHeader D_beach_802CC1C0;
extern idFuncStruct D_beach_802CC1D4;
extern idFuncStruct D_beach_802CC234;
extern idFuncStruct D_beach_802CC264;
extern idFuncStruct D_beach_802CC294;
extern randomTransition D_beach_802CC2C4;
extern PokemonInitData D_beach_802CC2F0;
extern AnimationHeader D_beach_802CC344;
extern AnimationHeader D_beach_802CC358;
extern AnimationHeader D_beach_802CC36C;
extern AnimationHeader D_beach_802CC380;
extern AnimationHeader D_beach_802CC394;
extern AnimationHeader D_beach_802CC3A8;
extern AnimationHeader D_beach_802CC3BC;
extern AnimationHeader D_beach_802CC3D0;
extern AnimationHeader D_beach_802CC3E4;
extern AnimationHeader D_beach_802CC3F8;
extern idFuncStruct D_beach_802CC40C;
extern randomTransition D_beach_802CC4AC;
extern idFuncStruct D_beach_802CC4C4;
extern idFuncStruct D_beach_802CC4F4;
extern idFuncStruct D_beach_802CC524;
extern idFuncStruct D_beach_802CC564;
extern idFuncStruct D_beach_802CC594;
extern idFuncStruct D_beach_802CC5C4;
extern idFuncStruct D_beach_802CC644;
extern idFuncStruct D_beach_802CC6B4;
extern idFuncStruct D_beach_802CC714;
extern idFuncStruct D_beach_802CC784;
extern idFuncStruct D_beach_802CC7B4;
extern idFuncStruct D_beach_802CC7E4;
extern idFuncStruct D_beach_802CC804;
extern idFuncStruct D_beach_802CC824;
extern idFuncStruct D_beach_802CC854;
extern idFuncStruct D_beach_802CC874;
extern idFuncStruct D_beach_802CC8A4;
extern idFuncStruct D_beach_802CC8D4;
extern idFuncStruct D_beach_802CC904;
extern idFuncStruct D_beach_802CC934;
extern PokemonInitData D_beach_802CC968;
extern AnimationHeader D_beach_802CC9AC;
extern AnimationHeader D_beach_802CC9C0;
extern AnimationHeader D_beach_802CC9D4;
extern AnimationHeader D_beach_802CC9E8;
extern AnimationHeader D_beach_802CC9FC;
extern idFuncStruct D_beach_802CCB28;
extern idFuncStruct D_beach_802CCBA8;
extern idFuncStruct D_beach_802CCBF8;
extern idFuncStruct D_beach_802CCA10;
extern randomTransition D_beach_802CCAA0;
extern idFuncStruct D_beach_802CCAB8;
extern idFuncStruct D_beach_802CCAE8;
extern idFuncStruct D_beach_802CCC28;
extern idFuncStruct D_beach_802CCC68;
extern idFuncStruct D_beach_802CCCA8;
extern PokemonInitData D_beach_802CCCEC;
extern AnimationHeader D_beach_802CCD24;
extern AnimationHeader D_beach_802CCD4C;
extern idFuncStruct D_beach_802CCD60;
extern PokemonInitData D_beach_802CCDA4;
extern AnimationHeader D_beach_802CCDE8;
extern s32 D_beach_802CCDFC;
extern s32 D_beach_802CCE00;
extern s32 D_beach_802CCE04;
extern AnimationHeader D_beach_802CCE08;
extern idFuncStruct D_beach_802CCE1C;
extern PokemonInitData D_beach_802CCE50;
extern AnimationHeader D_beach_802CCEB0;
extern AnimationHeader D_beach_802CCEC4;
extern AnimationHeader D_beach_802CCED8;
extern AnimationHeader D_beach_802CCEEC;
extern AnimationHeader D_beach_802CCF00;
extern idFuncStruct D_beach_802CCF14;
extern idFuncStruct D_beach_802CCF44;
extern PokemonInitData D_beach_802CCF78;
extern AnimationHeader D_beach_802CCFC0;
extern AnimationHeader D_beach_802CCFD4;
extern AnimationHeader D_beach_802CCFE8;
extern AnimationHeader D_beach_802CCFFC;
extern idFuncStruct D_beach_802CD010;
extern s32 D_beach_802CD060;
extern idFuncStruct D_beach_802CD0B4;
extern idFuncStruct D_beach_802CD0E4;
extern PokemonInitData D_beach_802CD118;
extern AnimationHeader D_beach_802CD168;
extern AnimationHeader D_beach_802CD17C;
extern AnimationHeader D_beach_802CD190;
extern AnimationHeader D_beach_802CD1A4;
extern idFuncStruct D_beach_802CD214;
extern PokemonInitData D_beach_802CD258;
extern AnimationHeader D_beach_802CD2A8;
extern AnimationHeader D_beach_802CD2BC;
extern AnimationHeader D_beach_802CD2F8;
extern AnimationHeader D_beach_802CD2E4;
extern AnimationHeader D_beach_802CD30C;
extern AnimationHeader D_beach_802CD320;
extern AnimationHeader D_beach_802CD334;
extern idFuncStruct D_beach_802CD35C;
extern randomTransition D_beach_802CD3DC;
extern pathSpline* D_beach_802CD3F4;
extern idFuncStruct D_beach_802CD3F8;
extern idFuncStruct D_beach_802CD438[4];
extern idFuncStruct D_beach_802CD478;
extern idFuncStruct D_beach_802CD4A8;
extern idFuncStruct D_beach_802CD4E8;
extern idFuncStruct D_beach_802CD518;
extern PokemonInitData D_beach_802CD55C;
extern AnimationHeader D_beach_802CD5A8;
extern AnimationHeader D_beach_802CD5BC;
extern AnimationHeader D_beach_802CD5D0;
extern AnimationHeader D_beach_802CD5E4;
extern AnimationHeader D_beach_802CD5F8;
extern AnimationHeader D_beach_802CD60C;
extern AnimationHeader D_beach_802CD620;
extern idFuncStruct D_beach_802CD634;
extern idFuncStruct D_beach_802CD694;
extern idFuncStruct D_beach_802CD6C4;
extern idFuncStruct D_beach_802CD6F4;
extern randomTransition D_beach_802CD764;
extern randomTransition D_beach_802CD774;
extern PokemonInitData D_beach_802CD7A8;
extern PokemonDef D_beach_802CD838;
extern PokemonDef D_beach_802CD848;
extern idFuncStruct D_beach_802CD858;
extern randomTransition D_beach_802CD8B8;
extern PokemonInitData D_beach_802CD8E4;
extern PokemonInitData D_beach_802CD948;
extern AnimationHeader D_beach_802CD980;
extern AnimationHeader D_beach_802CD994;
extern AnimationHeader D_beach_802CD9A8;
extern AnimationHeader D_beach_802CD9BC;
extern s32 D_beach_802CD9D0;
extern s32 D_beach_802CD9D4;
extern idFuncStruct D_beach_802CD9D8;
extern UnkBlueShark D_beach_802CD9F8;
extern PokemonInitData D_beach_802CDA10;
extern PokemonInitData D_beach_802CDAEC;
extern AnimationHeader D_beach_802CDB5C;
extern AnimationHeader D_beach_802CDB70;
extern AnimationHeader D_beach_802CDB84;
extern AnimationHeader D_beach_802CDBAC;
extern AnimationHeader D_beach_802CDBC0;
extern AnimationHeader D_beach_802CDBD4;
extern AnimationHeader D_beach_802CDBFC;
extern idFuncStruct D_beach_802CDC60;
extern idFuncStruct D_beach_802CDC80;
extern idFuncStruct D_beach_802CDCA0;
extern idFuncStruct D_beach_802CDCD0;
extern idFuncStruct D_beach_802CDD40;
extern idFuncStruct D_beach_802CDD80;
extern randomTransition D_beach_802CDE30;
extern idFuncStruct D_beach_802CDE48;
extern idFuncStruct D_beach_802CDE78;
extern idFuncStruct D_beach_802CDFD8;
extern PokemonInitData D_beach_802CE038;
extern AnimationHeader D_beach_802CE070;
extern PokemonInitData D_beach_802CE0A8;
extern PokemonDef D_beach_802CE0DC;
extern HeightMap D_beach_80318F00;
extern u8 D_beach_80347578;
extern u8 D_beach_80347579;
extern u8 D_beach_8034757A;
extern u8 D_beach_8034757B;
extern u16 D_beach_8034757C;
extern u8 D_beach_80347588;
extern void* D_beach_80347658;

extern PokemonDef beachPokemonData[17];

void func_beach_802C52EC(GObj*);
void func_beach_802C5620(GObj*);
void func_beach_802C5700(GObj*);
void func_beach_802C5768(GObj*);
void func_beach_802C5828(GObj*);
void func_beach_802C594C(GObj*);
void func_beach_802C5A20(GObj*);
void func_beach_802C5AF4(GObj*);
void func_beach_802C5B68(GObj*);
void func_beach_802C5BD4(GObj*);
void func_beach_802C5C60(GObj*);
void func_beach_802C5E88(GObj*);
void func_beach_802C5F9C(GObj*);
void func_beach_802C619C(GObj*);
void func_beach_802C6288(GObj*);
void func_beach_802C62E4(GObj*);
void func_beach_802C63F4(GObj*);
void func_beach_802C6514(GObj*);
void func_beach_802C6580(GObj*);
void func_beach_802C660C(GObj*);
void func_beach_802C6658(GObj*);
void func_beach_802C667C(GObj*);
void func_beach_802C68D8(GObj*);
void func_beach_802C69D4(GObj*);
void func_beach_802C6AA0(GObj*);
void func_beach_802C6C10(GObj*);
void func_beach_802C6D20(GObj*);
void func_beach_802C6D44(GObj*);
void func_beach_802C6DD4(GObj*);
void func_beach_802C6E40(GObj*);
void func_beach_802C6FD4(GObj*);
void func_beach_802C6FF8(GObj*);
void func_beach_802C737C(GObj*);
void func_beach_802C7490(GObj*);
void func_beach_802C75D0(GObj*);
void func_beach_802C762C(GObj*);
void func_beach_802C76C4(GObj*);
void func_beach_802C7748(GObj*);
void func_beach_802C7864(GObj*);
void func_beach_802C78B0(GObj*);
void func_beach_802C78E8(GObj*);
void func_beach_802C796C(GObj*);
void func_beach_802C7BB8(GObj*);
void func_beach_802C7DA0(GObj*);
void func_beach_802C7DEC(GObj*);
void func_beach_802C7F1C(GObj*);
void func_beach_802C7F74(GObj*);
void func_beach_802C80BC(GObj*);
void func_beach_802C80F0(GObj*);
void func_beach_802C8124(GObj*);
void func_beach_802C816C(GObj*);
void func_beach_802C81C4(GObj*);
void func_beach_802C821C(GObj*);
void func_beach_802C83D0(GObj*);
void func_beach_802C8438(GObj*);
void func_beach_802C85E0(GObj*);
void func_beach_802C86A8(GObj*);
void func_beach_802C8828(GObj*);
void func_beach_802C8894(GObj*);
void func_beach_802C8980(GObj*);
void func_beach_802C89A4(GObj*);
void func_beach_802C8B60(GObj*);
void func_beach_802C8DE8(GObj*);
void func_beach_802C8E20(GObj*);
void func_beach_802C8E90(GObj*);
void func_beach_802C907C(GObj*);
void func_beach_802C90E0(GObj*);
void func_beach_802C9274(GObj*);
void func_beach_802C92BC(GObj*);
void func_beach_802C9348(GObj*);
void func_beach_802C9580(GObj*);
void func_beach_802C9694(GObj*);
void func_beach_802C97D4(GObj*);
void func_beach_802C9830(GObj*);
void func_beach_802C98F4(GObj*);
void func_beach_802C9A10(GObj*);
void func_beach_802C9AE4(GObj*);
void func_beach_802C9C88(GObj*);
void func_beach_802C9CF8(GObj*);
void func_beach_802C9E70(GObj*);
void func_beach_802C9F30(GObj*);
void func_beach_802C9F9C(GObj*);
void func_beach_802CA010(GObj*);
void func_beach_802CA474(GObj*);
void func_beach_802CA5DC(GObj*);
void func_beach_802CA950(GObj*);
void func_beach_802CAC80(GObj*);
void func_beach_802CAD58(GObj*);
void func_beach_802CAD7C(GObj*);
void func_beach_802CAE14(GObj*);
void func_beach_802CAEB0(GObj*);
void func_beach_802CAF90(GObj*);
void func_beach_802CB08C(GObj*);
void func_beach_802CB128(GObj*);
s32 func_beach_802CB194(GObj*);
void func_beach_802CB2D8(GObj*);
void func_beach_802CB594(GObj*);
void func_beach_802CB6B4(GObj*);
void func_beach_802CB814(GObj*);
void func_beach_802CB874(GObj*);
void func_beach_802CBB90(GObj*);
void func_beach_802CBD04(GObj*);
void func_beach_802CBDD8(GObj*);

#endif
