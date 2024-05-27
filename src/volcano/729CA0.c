#include "common.h"
#include "world/world.h"

void func_802D93DC_72A5DC(GObj*);

extern AnimationHeader D_802E1958_732B58;
extern AnimationHeader D_802E196C_732B6C;
extern idFuncStruct D_802E1A34_732C34;
extern idFuncStruct D_802E1DF4_732FF4;
extern randomTransition D_802E1E64_733064;
extern PokemonInitData D_802E1FB4_7331B4;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D8AA0_729CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D8BB8_729DB8.s")

void func_802D8CA4_729EA4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E1958_732B58);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E1A34_732C34;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E1E64_733064);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D8D14_729F14.s")

void func_802D8DB8_729FB8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D8E14_72A014.s")

void func_802D8EB8_72A0B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D8F14_72A114.s")

void func_802D8F94_72A194(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E196C_732B6C);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E1DF4_732FF4;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E1E64_733064);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9004_72A204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9074_72A274.s")

void func_802D9244_72A444(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D924C_72A44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D930C_72A50C.s")

void func_802D9380_72A580(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 600.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D93DC_72A5DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9464_72A664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D94E8_72A6E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D95AC_72A7AC.s")

void func_802D9614_72A814(GObj* arg0) {
    updatePokemonState(arg0, func_802D93DC_72A5DC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9638_72A838.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D96AC_72A8AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D96F8_72A8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D976C_72A96C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D97B8_72A9B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9900_72AB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9950_72AB50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D99A0_72ABA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9A80_72AC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9B44_72AD44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9B8C_72AD8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9BF4_72ADF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9C30_72AE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/729CA0/func_802D9C84_72AE84.s")

GObj* func_802D9CB8_72AEB8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E1FB4_7331B4);
}
