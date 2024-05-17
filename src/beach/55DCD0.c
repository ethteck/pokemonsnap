#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C5C60.s")

void func_beach_802C5DAC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field0 = pokemon->collisionOffset.x;
    pokemon->miscVars[1].field0 = pokemon->collisionOffset.y;
    pokemon->miscVars[2].field0 = pokemon->collisionOffset.z;
    pokemon->miscVars[3].field0 = pokemon->collisionRadius;

    if (pokemon->behavior == 1) {
        pokemon = pokemon;
        updatePokemonState(obj, func_beach_802C6658);
    }

    if (pokemon->behavior == 2) {
        pokemon = pokemon;
        updatePokemonState(obj, func_beach_802C6C10);
    }

    if (pokemon->behavior == 3) {
        pokemon = pokemon;
        updatePokemonState(obj, func_beach_802C6D20);
    }

    if (pokemon->behavior == 4) {
        updatePokemonState(obj, func_beach_802C6FD4);
    }

    updatePokemonState(obj, func_beach_802C5E88);
}

void func_beach_802C5E88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CC344);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CC40C;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C5EF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CC358);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_beach_802C5F9C);
    pokemon->transitionGraph = &D_beach_802CC40C;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_beach_802C5E88);
    }
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C5F9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C5FF8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    runPathProcess(obj, NULL);
    setPokemonAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = &D_beach_802CC4C4;
    runInteractionsAndWaitForFlags(obj, 1);
    runPathProcess(obj, func_beach_802C619C);
    setPokemonAnimation(obj, &D_beach_802CC36C);
    pokemon->pokemonLoopTarget = 2;
    pokemon->transitionGraph = &D_beach_802CC4C4;
    runInteractionsAndWaitForFlags(obj, 3);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C60E8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    runPathProcess(obj, NULL);
    forcePokemonAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = &D_beach_802CC4F4;
    runInteractionsAndWaitForFlags(obj, 1U);
    runPathProcess(obj, func_beach_802C619C);
    setPokemonAnimation(obj, &D_beach_802CC36C);
    pokemon->pokemonLoopTarget = 2;
    pokemon->transitionGraph = &D_beach_802CC4F4;
    runInteractionsAndWaitForFlags(obj, 3U);
    pokemon->apple = NULL;
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C619C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;

    while (TRUE) {
        if (func_80360F1C_50132C(obj, 1)) {
            break;
        }

        ohWait(1);
    }

    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C6210(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    pokemon = pokemon;
    setPokemonAnimation(obj, &D_beach_802CC36C);
    runPathProcess(obj, func_beach_802C6288);
    pokemon->transitionGraph = &D_beach_802CC524;
    runInteractionsAndWaitForFlags(obj, 2);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C6288(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C62E4(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    setPokemonAnimation(obj, &D_beach_802CC358);
    runPathProcess(obj, func_beach_802C63F4);
    pokemon->transitionGraph = &D_beach_802CC564;
    runInteractionsAndWaitForFlags(obj, 2U);
    if (!(pokemon->processFlags & 0x10)) {
        updatePokemonState(obj, func_beach_802C5E88);
    }
    setPokemonAnimation(obj, &D_beach_802CC3E4);

    // clang-format off
    pokemon->counter = 33; pokemon->processFlags &= ~4;
    // clang-format on

    pokemon->transitionGraph = &D_beach_802CC564;
    runInteractionsAndWaitForFlags(obj, 4U);
    if (pokemon->interactionTarget == NULL) {
        updatePokemonState(obj, func_beach_802C5E88);
    }
    func_8036010C_50051C(obj);
    pokemon->transitionGraph = &D_beach_802CC564;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C63F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0);
    setPokemonAnimation(obj, &D_beach_802CC36C);
    pokemon->hSpeed = 80.0f;
    func_80361748_501B58(obj, 50.0f, 0.1f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C6478(GObj* obj) {
    updatePokemonState(obj, func_beach_802C62E4);
}

void func_beach_802C649C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    setPokemonAnimation(obj, &D_beach_802CC3F8);
    runPathProcess(obj, func_beach_802C6514);
    pokemon->transitionGraph = &D_beach_802CC594;
    runInteractionsAndWaitForFlags(obj, 2);
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C6514(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (1) {
        if (!func_80361440_501850(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= 2;
    pokemon->pathProcess = NULL;
    omEndProcess(NULL);
}

void func_beach_802C6580(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, func_beach_802C660C);
    func_8035ED90_4FF1A0(obj, func_beach_802C5C60);
    setPokemonAnimation(obj, &D_beach_802CC380);
    pokemon->transitionGraph = &D_beach_802CC5C4;
    runInteractionsAndWaitForFlags(obj, 1);
    pokemon->miscVars[4].field1 = 0;
    weightedRandomStaightTransition(obj, &D_beach_802CC4AC);
}

void func_beach_802C660C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C6658(GObj* obj) {
    updatePokemonState(obj, func_beach_802C667C);
}

void func_beach_802C667C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~0x20;
    runPathProcess(obj, NULL);
    setPokemonAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = &D_beach_802CC644;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C67F8() {
}

void func_beach_802C6700(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 sp24;
    f32 sp20;

    pokemon->processFlags |= 0x20;
    runPathProcess(obj, NULL);
    forcePokemonAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    getLevelProgress(&sp24, &sp20);
    sp20 += sp24;
    if (sp20 > 3.0f) {
        runPathProcess(obj, func_beach_802C660C);
        updatePokemonState(obj, func_beach_802C6AA0);
    }
    cmdSendCommandToLink(3, 0x1C, obj);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_beach_802C67E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= 0x20;
    runPathProcess(obj, NULL);
    forcePokemonAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C667C);
}

void func_beach_802C6854(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, func_beach_802C68D8);
    pokemon->processFlags |= 0x20;
    setPokemonAnimation(obj, &D_beach_802CC3F8);
    pokemon->transitionGraph = &D_beach_802CC6B4;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_beach_802C667C);
}

void func_beach_802C68D8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (1) {
        if (!func_80361440_501850(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= 2;
    pokemon->pathProcess = NULL;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55DCD0/func_beach_802C6944.s")

void func_beach_802C69D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~0x20;
    setPokemonAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = &D_beach_802CC714;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C6A3C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    pokemon->processFlags |= 0x20;
    forcePokemonAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C6AA0);
}

void func_beach_802C6AA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    forcePokemonAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = &D_beach_802CC784;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C69D4);
}

void func_beach_802C6B28(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    pokemon->processFlags |= 0x20;
    forcePokemonAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C69D4);
}

void func_beach_802C6B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, func_beach_802C68D8);
    pokemon->processFlags |= 0x20;
    setPokemonAnimation(obj, &D_beach_802CC3F8);
    pokemon->transitionGraph = &D_beach_802CC7B4;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_beach_802C69D4);
}

void func_beach_802C6C10(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = &D_beach_802CC7E4;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C6C60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 1;
    obj->flags = 0;
    setPokemonAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = &D_beach_802CC804;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C6CC4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = &D_beach_802CC824;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C6580);
}

void func_beach_802C6D20(GObj* obj) {
    updatePokemonState(obj, func_beach_802C6D44);
}

void func_beach_802C6D44(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = &D_beach_802CC854;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C6D9C(GObj* obj) {
    runPathProcess(obj, func_beach_802C6DD4);
    updatePokemonState(obj, func_beach_802C6E40);
}

void func_beach_802C6DD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1.0f, 0.033333335f, 0.0f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(0);
}

void func_beach_802C6E40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~0x20;
    setPokemonAnimation(obj, &D_beach_802CC36C);
    pokemon->transitionGraph = &D_beach_802CC874;
    runInteractionsAndWaitForFlags(obj, 2);
    setPokemonAnimation(obj, &D_beach_802CC344);
    updatePokemonState(obj, NULL);
}

void func_beach_802C6EC0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= 0x20;
    setPokemonAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = &D_beach_802CC8A4;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C6E40);
}

void func_beach_802C6F6C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= 0x20;
    forcePokemonAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = &D_beach_802CC8D4;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C6E40);
}

void func_beach_802C6FD4(GObj* obj) {
    updatePokemonState(obj, func_beach_802C6FF8);
}

void func_beach_802C6FF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = &D_beach_802CC904;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C7050(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_beach_802CBDD8(obj);
    setPokemonAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CC3BC);
    updatePokemonState(obj, NULL);
}

void func_beach_802C70C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CC3F8);
    runPathProcess(obj, func_beach_802C660C);
    pokemon->transitionGraph = &D_beach_802CC934;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C7130(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, NULL);
    setPokemonAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = &D_beach_802CC934;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C70C0);
}

void func_beach_802C71E8(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    Pokemon* pokemon = GET_POKEMON(arg0);

    if (pokemon->behavior == 1) {
        pokemonChangeBlock(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    } else {
        pokemonChangeBlockOnGround(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    }
}

void func_beach_802C7270(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    if (spawn->behavior == 1) {
        // required to match
        if (FALSE) {
        }

        spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CC968);
    } else {
        spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CC968);
    }
}
