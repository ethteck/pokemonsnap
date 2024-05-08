#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7BB8.s")

void func_beach_802C7C7C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, randFloat(), 0, 0.1f, 0.0f, 2);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C7CF0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~0x20;
    func_8035ED90_4FF1A0(obj, func_beach_802C7DA0);
    setPokemonAnimation(obj, &D_beach_802CCD4C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 8);
    func_8035ED90_4FF1A0(obj, func_beach_802C7DEC);
    setPokemonAnimation(obj, &D_beach_802CCD24);
    pokemon->transitionGraph = &D_beach_802CCD60;
    runInteractionsAndWaitForFlags(obj, 8);
    updatePokemonState(obj, func_beach_802C7BB8);
}

void func_beach_802C7DA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->jumpVel = 300.0f;
    func_80360300_500710(obj, 400, 0, 0, 0);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C7DEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->jumpVel = 90.0f;
    func_80360590_5009A0(obj, 400, 0, 0, 0);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C7E38(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CCDA4);
}

// TODO: potential file split

void func_beach_802C7E70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 2 | 1;
    if (pokemon->behavior == 2) {
        pokemon = pokemon;
        updatePokemonState(obj, func_beach_802C816C);
    }
    if (pokemon->behavior == 4) {
        pokemon = pokemon;
        updatePokemonState(obj, func_beach_802C81C4);
    }
    if (pokemon->behavior == 5) {
        updatePokemonState(obj, func_beach_802C821C);
    }
    updatePokemonState(obj, func_beach_802C7F1C);
}

void func_beach_802C7F1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035ED90_4FF1A0(obj, func_beach_802C7F74);
    pokemon->transitionGraph = &D_beach_802CCE1C;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C7F74(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 2 | 1;
    forcePokemonAnimation(obj, &D_beach_802CCE08);

    // clang-format off
    pokemon->counter = randRange(600) + 1; pokemon->processFlags &= ~4;
    // clang-format on

    func_8035FC54_500064(obj, 4);
    pokemon->tangible = 1;
    obj->flags = 0;
    forcePokemonAnimation(obj, &D_beach_802CCDE8);
    func_8035FC54_500064(obj, 1);
    func_8035ED90_4FF1A0(obj, func_beach_802C7F74);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8028(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 0) {
        pokemon = pokemon;
        updatePokemonState(obj, func_beach_802C80BC);
    }
    if (pokemon->behavior == 1) {
        pokemon = pokemon;
        updatePokemonState(obj, func_beach_802C80F0);
    }
    if (pokemon->behavior == 2) {
        updatePokemonState(obj, func_beach_802C8124);
    }
    updatePokemonState(obj, NULL);
}

void func_beach_802C80BC(GObj* obj) {
    D_beach_802CCDFC++;
    updatePokemonState(obj, NULL);
}

void func_beach_802C80F0(GObj* obj) {
    D_beach_802CCE00++;
    updatePokemonState(obj, NULL);
}

void func_beach_802C8124(GObj* obj) {
    D_beach_802CCE00++;
    D_beach_802CCE04++;
    updatePokemonState(obj, NULL);
}

void func_beach_802C816C(GObj* obj) {
    while (TRUE) {
        if (D_beach_802CCDFC > 0) {
            break;
        }

        ohWait(1);
    }

    updatePokemonState(obj, func_beach_802C7F1C);
}

void func_beach_802C81C4(GObj* obj) {
    while (TRUE) {
        if (D_beach_802CCE00 > 0) {
            break;
        }

        ohWait(1);
    }

    updatePokemonState(obj, func_beach_802C7F1C);
}

void func_beach_802C821C(GObj* obj) {
    while (TRUE) {
        if (D_beach_802CCE04 > 0) {
            break;
        }

        ohWait(1);
    }

    updatePokemonState(obj, func_beach_802C7F1C);
}

void func_beach_802C8274(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CCE50);
}
