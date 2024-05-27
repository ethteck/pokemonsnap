#include "common.h"
#include "world/world.h"

extern AnimationHeader D_802E29FC_6CA7DC;
extern idFuncStruct D_802E2AC4_6CA8A4;
extern randomTransition D_802E2B24_6CA904;
extern PokemonInitData D_802E2BDC_6CA9BC;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9520_6C1300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9664_6C1444.s")

void func_802D96FC_6C14DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E29FC_6CA7DC);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2AC4_6CA8A4;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2B24_6CA904);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D976C_6C154C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9808_6C15E8.s")

extern AnimationHeader D_802E2A38_6CA818;

void func_802D990C_6C16EC(GObj * obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0);
    setPokemonAnimation(obj, &D_802E2A38_6CA818);
    pokemon->hSpeed = 100.0f;
    func_80361748_501B58(obj, 90.0f, 0.1f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}


#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9990_6C1770.s")

void func_802D9A0C_6C17EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2E);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9A58_6C1838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9AC4_6C18A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9C8C_6C1A6C.s")

void func_802D9D7C_6C1B5C(GObj *obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_80361B50_501F60(obj, pokemon->pos1.x, pokemon->pos1.z);
    func_80361E58_502268(obj, 0.1f);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1300/func_802D9DD8_6C1BB8.s")

GObj* func_802D9F44_6C1D24(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2BDC_6CA9BC);
}
