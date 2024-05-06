#include "common.h"
#include "beach.h"

void func_beach_802C82B0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    obj->flags |= GOBJ_FLAG_HIDDEN;
    runPathProcess(obj, func_beach_802C8438);
    // clang-format off
    animal->counter = 1; animal->processFlags &= ~4;
    // clang-format on
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    animal->processFlags |= 0x20;
    animal->transitionGraph = &D_beach_802CCF44;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802C8354(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 0x200;
    obj->flags = 0;
    animal->processFlags &= ~0x20;
    setAnimalAnimation(obj, &D_beach_802CCF00);
    animal->transitionGraph = &D_beach_802CCF14;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C83D0);
}

void func_beach_802C83D0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CCEB0);
    animal->transitionGraph = &D_beach_802CCF14;
    runInteractionsAndWaitForFlags(obj, 2);
    runAnimalCleanup(obj);
    updateAnimalState(obj, 0);
}

void func_beach_802C8438(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setNodePosToNegRoom(obj);
    animalPathLoop(obj, 0, 1.0f, 0.1f, 0.0f, 3);
    animal->pathProcess = 0;
    animal->processFlags |= 2;
    omEndProcess(0);
}

void func_beach_802C84A4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->processFlags |= 0x20;
    setAnimalAnimation(obj, &D_beach_802CCEC4);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setAnimalAnimation(obj, &D_beach_802CCED8);
    // clang-format off
    animal->counter = 120; animal->processFlags &= ~4;
    // clang-format on
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    setAnimalAnimation(obj, &D_beach_802CCEEC);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    animal->processFlags &= ~0x20;
    updateAnimalState(obj, func_beach_802C83D0);
}

void func_beach_802C8570(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CCF78);
}
