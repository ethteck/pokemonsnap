#include "common.h"
#include "world/world.h"

void func_802DA3A0_72B5A0(GObj*);

extern PokemonInitData D_802E2358_733558;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9D00_72AF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9DFC_72AFFC.s")

void func_802D9E7C_72B07C(GObj* arg0) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (TRUE) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 4 || (sp34 == 4 && sp30 >= 0.1)) {
            break;
        }
        ohWait(1);
    }
    runPokemonCleanup(arg0);
    func_8035EDC8_4FF1D8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9F24_72B124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9F90_72B190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA000_72B200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA0A4_72B2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA100_72B300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA1A4_72B3A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA200_72B400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA2C8_72B4C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA330_72B530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA3A0_72B5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA428_72B628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA4AC_72B6AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA55C_72B75C.s")

void func_802DA5B4_72B7B4(GObj* arg0) {
    updatePokemonState(arg0, func_802DA3A0_72B5A0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA5D8_72B7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA640_72B840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA68C_72B88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA748_72B948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA7A4_72B9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA848_72BA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA8A4_72BAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA930_72BB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA97C_72BB7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DAA34_72BC34.s")

GObj* func_802DAA9C_72BC9C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2358_733558);
}
