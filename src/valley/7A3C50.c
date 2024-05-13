#include "common.h"

extern AnimationHeader D_802D31AC_7AC73C;
extern AnimationHeader D_802D31C0_7AC750;
extern AnimationHeader D_802D31D4_7AC764;
extern idFuncStruct D_802D32D4_7AC864;

void func_802CA6C0_7A3C50(GObj* arg0) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (TRUE) {
        func_80357384_4F7794(&sp34, &sp30);
        if (sp34 > 2 || (sp34 == 2 && sp30 >= 0.1)) {
            break;
        }
        ohWait(1);
    }
    runPokemonCleanup(arg0);
    func_8035EDC8_4FF1D8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA768_7A3CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA7A0_7A3D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA858_7A3DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA8A4_7A3E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA8F8_7A3E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA948_7A3ED8.s")

void func_802CA9BC_7A3F4C(GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CA9BC_7A3F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAA2C_7A3FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAAD0_7A4060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAB2C_7A40BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CABD0_7A4160.s")

void func_802CAC2C_7A41BC(GObj* arg0) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    runPathProcess(arg0, NULL);
    setPokemonAnimation(arg0, &D_802D31AC_7AC73C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(arg0, 1);
    setPokemonAnimation(arg0, &D_802D31C0_7AC750);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(arg0, 1);
    setPokemonAnimation(arg0, &D_802D31D4_7AC764);
    pokemon->transitionGraph = &D_802D32D4_7AC864;
    runInteractionsAndWaitForFlags(arg0, 1);
    updatePokemonState(arg0, func_802CA9BC_7A3F4C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CACE4_7A4274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAD54_7A42E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CADEC_7A437C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAE70_7A4400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAF04_7A4494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CAF54_7A44E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CB008_7A4598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3C50/func_802CB02C_7A45BC.s")
