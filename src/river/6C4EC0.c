#include "common.h"
#include "world/world.h"

void func_802DD6F0_6C54D0(GObj*);
void func_802DDCB8_6C5A98(GObj*);
void func_802DE100_6C5EE0(GObj*);

extern AnimationHeader D_802E383C_6CB61C;
extern AnimationHeader D_802E38C8_6CB6A8;
extern AnimationHeader D_802E3968_6CB748;
extern idFuncStruct D_802E39E8_6CB7C8;
extern idFuncStruct D_802E3B28_6CB908;
extern idFuncStruct D_802E3B78_6CB958;
extern PokemonInitData D_802E3CBC_6CBA9C;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD0E0_6C4EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD1D4_6C4FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD2BC_6C509C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD398_6C5178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD4AC_6C528C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD53C_6C531C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD6F0_6C54D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD74C_6C552C.s")

void func_802DD7CC_6C55AC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 50.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD828_6C5608.s")

void func_802DD8A8_6C5688(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 100.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD904_6C56E4.s")

void func_802DD96C_6C574C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E383C_6CB61C);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E39E8_6CB7C8;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DD6F0_6C54D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DD9DC_6C57BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDAA0_6C5880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDAEC_6C58CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDB70_6C5950.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDC28_6C5A08.s")

void func_802DDC94_6C5A74(GObj* arg0) {
    updatePokemonState(arg0, func_802DDCB8_6C5A98);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDCB8_6C5A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDD38_6C5B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDDB8_6C5B98.s")

void func_802DDE20_6C5C00(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E3968_6CB748);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E3B28_6CB908;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DDC94_6C5A74);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDE90_6C5C70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDF54_6C5D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DDFA0_6C5D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE024_6C5E04.s")

void func_802DE0DC_6C5EBC(GObj* arg0) {
    updatePokemonState(arg0, func_802DE100_6C5EE0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE100_6C5EE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE180_6C5F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE200_6C5FE0.s")

void func_802DE268_6C6048(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E38C8_6CB6A8);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E3B78_6CB958;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DE0DC_6C5EBC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE2D8_6C60B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE39C_6C617C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE3E8_6C61C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE46C_6C624C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE524_6C6304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4EC0/func_802DE870_6C6650.s")

GObj* func_802DE8BC_6C669C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802E3CBC_6CBA9C);
}
