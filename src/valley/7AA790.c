#include "common.h"

void func_802D1344_7AA8D4(GObj*);
void func_802D15BC_7AAB4C(GObj*);

extern AnimationHeader D_802EC82C_7C5DBC;
extern AnimationHeader D_802EC840_7C5DD0;
extern AnimationHeader D_802EC854_7C5DE4;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1200_7AA790.s")

void func_802D129C_7AA82C(GObj* arg0) {
    forcePokemonAnimation(arg0, &D_802EC82C_7C5DBC);
    updatePokemonState(arg0, func_802D1344_7AA8D4);
}

void func_802D12D4_7AA864(GObj* arg0) {
    forcePokemonAnimation(arg0, &D_802EC840_7C5DD0);
    updatePokemonState(arg0, func_802D1344_7AA8D4);
}

void func_802D130C_7AA89C(GObj* arg0) {
    forcePokemonAnimation(arg0, &D_802EC854_7C5DE4);
    updatePokemonState(arg0, func_802D1344_7AA8D4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1344_7AA8D4.s")

void func_802D1414_7AA9A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1454_7AA9E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D156C_7AAAFC.s")

void func_802D1598_7AAB28(GObj* arg0) {
    updatePokemonState(arg0, func_802D15BC_7AAB4C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D15BC_7AAB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D16CC_7AAC5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1734_7AACC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D17D8_7AAD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D18D8_7AAE68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D19DC_7AAF6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1ACC_7AB05C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1B48_7AB0D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1BC8_7AB158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1C40_7AB1D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1D4C_7AB2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1E3C_7AB3CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1EB8_7AB448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1F18_7AB4A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D1FC0_7AB550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D2128_7AB6B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA790/func_802D21C8_7AB758.s")
