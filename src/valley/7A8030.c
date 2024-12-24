#include "valley.h"

void func_802CF524_7A8AB4(GObj*);
void func_802CF65C_7A8BEC(GObj*);

extern AnimationHeader D_802D3F8C_7AD51C;
extern InteractionHandler D_802D4070_7AD600[];
extern RandomState D_802D40A0_7AD630[];
extern InteractionHandler D_802D40B0_7AD640[];
extern InteractionHandler D_802D40D0_7AD660[];
extern PokemonInitData D_802D4124_7AD6B4;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CEAA0_7A8030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CEB4C_7A80DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CEB9C_7A812C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CEC18_7A81A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CED44_7A82D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CEFB8_7A8548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF07C_7A860C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF114_7A86A4.s")

void func_802CF388_7A8918(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802D3F8C_7AD51C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D4070_7AD600;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802D40A0_7AD630);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF3F8_7A8988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF48C_7A8A1C.s")

void func_802CF500_7A8A90(GObj* arg0) {
    Pokemon_SetState(arg0, func_802CF524_7A8AB4);
}

void func_802CF524_7A8AB4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802D3F8C_7AD51C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D40B0_7AD640;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CF524_7A8AB4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF594_7A8B24.s")

void func_802CF638_7A8BC8(GObj* arg0) {
    Pokemon_SetState(arg0, func_802CF65C_7A8BEC);
}

void func_802CF65C_7A8BEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802D3F8C_7AD51C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D40D0_7AD660;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CF65C_7A8BEC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF6CC_7A8C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF720_7A8CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8030/func_802CF794_7A8D24.s")

GObj* func_802CF808_7A8D98(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D4124_7AD6B4);
}
