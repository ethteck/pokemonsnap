#include "common.h"

#include "world/world.h"

extern GObj* D_802D2FF0_7AC580;
extern AnimationHeader D_802D2F8C_7AC51C;
extern AnimationHeader D_802D2FA0_7AC530;
extern AnimationHeader D_802D2FB4_7AC544;
extern AnimationHeader D_802D2FC8_7AC558;
extern AnimationHeader D_802D2FDC_7AC56C;
extern s16 D_802D2FF4_7AC584;
extern idFuncStruct D_802D2FF8_7AC588;
extern PokemonInitData D_802D302C_7AC5BC;

void func_802CA1B0_7A3740(GObj*);

void func_802C9FD0_7A3560(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    pokemon->tangible = 0;
    arg0->flags |= 0x2 | 0x1;
    pokemon->transitionGraph = &D_802D2FF8_7AC588;
    runInteractionsAndWaitForFlags(arg0, 0);
    updatePokemonState(arg0, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3560/func_802CA020_7A35B0.s")
// void func_802CA020_7A35B0(GObj* arg0) {
//     Pokemon* pokemon = GET_POKEMON(arg0);
//     void* temp_v1;
//     void* temp_v1_2;

//     D_802D2FF4_7AC584 = 1;
//     temp_v1 = func_8035E1D4_4FE5E4()->unk_48->unk_4C;
//     temp_v1->unk_2C *= 15.0f;
//     temp_v1_2 = temp_v1 + 0x28;
//     temp_v1_2->unk_8 = temp_v1->unk_30 * 15.0f;
//     temp_v1_2->unk_C = temp_v1->unk_34 * 10.0f;
//     pokemon->tangible = 1;
//     arg0->flags = 0;
//     forcePokemonAnimation(arg0, &D_802D2F8C_7AC51C);
//     pokemon->transitionGraph = NULL;
//     runInteractionsAndWaitForFlags(arg0, 1);
//     setPokemonAnimation(arg0, &D_802D2FA0_7AC530);
//     pokemon->transitionGraph = NULL;
//     runInteractionsAndWaitForFlags(arg0, 1);
//     setPokemonAnimation(arg0, &D_802D2FC8_7AC558);
//     runPathProcess(arg0, func_802CA1B0_7A3740);

//     while (!(pokemon->pathParam > 0.2)) {
//         ohWait(1);
//     }

//     pokemon->processFlags |= POKEMON_PROCESS_FLAG_20;
//     setPokemonAnimation(arg0, &D_802D2FB4_7AC544);
//     pokemon->transitionGraph = NULL;
//     runInteractionsAndWaitForFlags(arg0, 1);
//     pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_20;
//     setPokemonAnimation(arg0, &D_802D2FDC_7AC56C);
//     pokemon->transitionGraph = 0;
//     runInteractionsAndWaitForFlags(arg0, 2);
//     runPokemonCleanup(arg0);
//     updatePokemonState(arg0, NULL);
// }

void func_802CA1B0_7A3740(GObj* arg0) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    setNodePosToNegRoom(arg0);
    pokemonPathLoop(arg0, 0.0f, 1.0f, 0.1f, 0.1f, 0x80);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

static void stub(void) {
    // todo remove?
}

GObj* func_802CA224_7A37B4(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802D2FF0_7AC580 = spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_802D302C_7AC5BC);

    return D_802D2FF0_7AC580;
}
