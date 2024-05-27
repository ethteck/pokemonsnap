#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E4378_6CC158;
extern AnimationHeader D_802E4140_6CBF20;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DF670_6C7450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DF6BC_6C749C.s")

void func_802DF7D8_6C75B8(GObj* );
void func_802DF758_6C7538(GObj *);

void func_802DF710_6C74F0(GObj *obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 1;
    obj->flags = 0;
    runPathProcess(obj, func_802DF7D8_6C75B8);
    updatePokemonState(obj, func_802DF758_6C7538);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DF758_6C7538.s")

void func_802DF7D8_6C75B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.2f, 0.0f, 2U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DF844_6C7624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DF8C4_6C76A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DF91C_6C76FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DF9CC_6C77AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DFA30_6C7810.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DFA5C_6C783C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DFB74_6C7954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DFC38_6C7A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DFCD0_6C7AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DFD78_6C7B58.s")

void func_802DFDF8_6C7BD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E4140_6CBF20);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DFDF8_6C7BD8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7450/func_802DFE4C_6C7C2C.s")

GObj* func_802DFEB0_6C7C90(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemon(objID, id, block, blockB, spawn, &D_802E4378_6CC158);
}
