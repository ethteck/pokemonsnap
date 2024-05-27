#include "common.h"
#include "../world/world.h"

extern PokemonInitData D_8034B638_82ADA8;

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A190_829900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A27C_8299EC.s")

void func_8034A27C_8299EC(GObj*);
void func_8034A3A0_829B10(GObj*);
extern AnimationHeader D_8034B600_82AD70;

void func_8034A334_829AA4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034B600_82AD70);
    runPathProcess(obj, func_8034A3A0_829B10);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_8034A27C_8299EC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A3A0_829B10.s")

GObj* func_8034A4E8_829C58(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_8034B638_82ADA8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A520_829C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A550_829CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A578_829CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A5EC_829D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A6B4_829E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A748_829EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829900/func_8034A7C4_829F34.s")

void func_8034A520_829C90(GObj*);
void func_8034A7C4_829F34(GObj*);
extern GObj* D_8034B674_82ADE4;

void func_8034AABC_82A22C(void) {
    GObj* obj;

    obj = func_80365E80_506290();
    D_8034B674_82ADE4 = obj;
    if (obj != NULL) {
        omCreateProcess(obj, func_8034A7C4_829F34, 0, 1);
        func_8034A520_829C90(obj);
    }
}
