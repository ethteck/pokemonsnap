#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/562BC0/func_beach_802CAB50.s")

void func_beach_802CAC08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802CAC48(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CDAEC);
}

// TODO: potential file split. spawnPokemonOnGround tends to be used at the end of files

void func_beach_802CAC80(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 0x200;
    pokemon->flags |= 0x800;
    pokemon->transitionGraph = &D_beach_802CDC60;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802CACD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        updatePokemonState(obj, func_beach_802CAD58);
    }

    if (pokemon->behavior == 4) {
        updatePokemonState(obj, func_beach_802CB2D8);
    }
    updatePokemonState(obj, func_beach_802CAC80);
    updatePokemonState(obj, NULL);
}

void func_beach_802CAD58(GObj* obj) {
    updatePokemonState(obj, func_beach_802CAD7C);
}

void func_beach_802CAD7C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = &D_beach_802CDC80;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802CADCC(GObj* ob) {
    Pokemon* pokemon = GET_POKEMON(ob);

    pokemon->tangible = 1;
    ob->flags = 0;
    runPathProcess(ob, func_beach_802CAEB0);
    updatePokemonState(ob, func_beach_802CAE14);
}

void func_beach_802CAE14(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 1;
    obj->flags = 0;
    setPokemonAnimation(obj, &D_beach_802CDBAC);
    pokemon->transitionGraph = &D_beach_802CDCA0;
    runInteractionsAndWaitForFlags(obj, 2);
    pokemon->field_0x10e = 5;
    setPokemonAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = &D_beach_802CDCA0;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802CAF90);
}

void func_beach_802CAEB0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(0);
}

void func_beach_802CAF1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_20;
    setPokemonAnimation(obj, &D_beach_802CDBC0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_20;
    updatePokemonState(obj, func_beach_802CAE14);
}
