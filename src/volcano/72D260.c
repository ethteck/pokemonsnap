#include "common.h"
#include "world/world.h"

extern AnimationHeader D_802E2AEC_733CEC;
extern AnimationHeader D_802E2B00_733D00;
extern AnimationHeader D_802E2B14_733D14;
extern idFuncStruct D_802E2C00_733E00;
extern randomTransition D_802E2C70_733E70;
extern idFuncStruct D_802E2CA4_733EA4;
extern randomTransition D_802E2D04_733F04;
extern PokemonInitData D_802E2E08_734008;

void func_802DC060_72D260(GObj* arg0) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (TRUE) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 4 || (sp34 == 4 && sp30 >= 0.35)) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(arg0);
    Pokemon_StopAuxProc(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC108_72D308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC170_72D370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC1F8_72D3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC280_72D480.s")

void func_802DC3A0_72D5A0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E2B14_733D14);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2C00_733E00;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2C70_733E70);
}

void func_802DC410_72D610(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E2B00_733D00);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2C00_733E00;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2C70_733E70);
}

void func_802DC480_72D680(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E2AEC_733CEC);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2C00_733E00;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2C70_733E70);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC4F0_72D6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC590_72D790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC6B4_72D8B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC758_72D958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC7A8_72D9A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC7F8_72D9F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC850_72DA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC924_72DB24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DC99C_72DB9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DCA28_72DC28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DCB44_72DD44.s")

void func_802DCBD0_72DDD0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E2AEC_733CEC);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2CA4_733EA4;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2D04_733F04);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DCC40_72DE40.s")

void func_802DCCE4_72DEE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DCD40_72DF40.s")

void func_802DCDE4_72DFE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DCE40_72E040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DCF44_72E144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DCFAC_72E1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DD034_72E234.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DD0E8_72E2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DD1C0_72E3C0.s")

GObj* func_802DD214_72E414(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2E08_734008);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72D260/func_802DD24C_72E44C.s")
