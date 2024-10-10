#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

void func_802DBD04_6C3AE4(GObj*);

extern AnimationHeader D_802E339C_6CB17C;
extern AnimationHeader D_802E33B0_6CB190;
extern AnimationHeader D_802E33C4_6CB1A4;
extern AnimationHeader D_802E33D8_6CB1B8;
extern AnimationHeader D_802E33EC_6CB1CC;
extern InteractionHandler D_802E3494_6CB274[];
extern RandomState D_802E3504_6CB2E4[];
extern InteractionHandler D_802E351C_6CB2FC[];
extern RandomState D_802E356C_6CB34C[];
extern InteractionHandler D_802E3584_6CB364[];
extern RandomState D_802E35D4_6CB3B4[];
extern PokemonInitData D_802E3684_6CB464;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DBBA0_6C3980.s")

void func_802DBC5C_6C3A3C(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E339C_6CB17C);
    Pokemon_SetState(obj, func_802DBD04_6C3AE4);
}

void func_802DBC94_6C3A74(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E33B0_6CB190);
    Pokemon_SetState(obj, func_802DBD04_6C3AE4);
}

void func_802DBCCC_6C3AAC(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E33C4_6CB1A4);
    Pokemon_SetState(obj, func_802DBD04_6C3AE4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DBD04_6C3AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DBDB0_6C3B90.s")

void func_802DBECC_6C3CAC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33D8_6CB1B8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3494_6CB274;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E3504_6CB2E4);
}

void func_802DBF3C_6C3D1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33EC_6CB1CC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3494_6CB274;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E3504_6CB2E4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DBFAC_6C3D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC05C_6C3E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC0A4_6C3E84.s")

void func_802DC150_6C3F30(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33D8_6CB1B8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E351C_6CB2FC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E356C_6CB34C);
}

void func_802DC1C0_6C3FA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33EC_6CB1CC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E351C_6CB2FC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E356C_6CB34C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC230_6C4010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC2F4_6C40D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC358_6C4138.s")

void func_802DC404_6C41E4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33D8_6CB1B8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3584_6CB364;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E35D4_6CB3B4);
}

void func_802DC474_6C4254(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E33EC_6CB1CC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3584_6CB364;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E35D4_6CB3B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC4E4_6C42C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC5A8_6C4388.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC60C_6C43EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC6BC_6C449C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC7AC_6C458C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DC820_6C4600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DCA7C_6C485C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DCB0C_6C48EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DCBB8_6C4998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C3980/func_802DCC6C_6C4A4C.s")

GObj* func_802DCEB0_6C4C90(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E3684_6CB464);
}
