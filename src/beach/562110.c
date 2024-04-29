#include "common.h"

extern animalInitData D_beach_802CD8E4;
extern idFuncStruct D_beach_802CD858;
extern AnimalDef D_beach_802CD848;
extern AnimalDef D_beach_802CD838;
extern randomTransition D_beach_802CD8B8;

void func_beach_802CA0A0(GObj* arg0) {
    // TODO: see if this can be inlined
    AnimalDef sp18 = D_beach_802CD838;

    addAnimalAtGeo(arg0, 0x10U, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA0F4(GObj* arg0) {
    // TODO: see if this can be inlined
    AnimalDef sp18 = D_beach_802CD848;

    addAnimalAtGeo(arg0, 0x7BU, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA148(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 0;
    obj->flags |= 3;
    animal->transitionGraph = &D_beach_802CD858;
    runInteractionsAndWaitForFlags(obj, 0U);
    updateAnimalState(obj, NULL);
}

void func_beach_802CA198(GObj* arg0) {
    weightedRandomStaightTransition(arg0, &D_beach_802CD8B8);
}

void func_beach_802CA1BC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    omCreateProcess(obj, func_beach_802CA0A0, 1U, 1U);
    // clang-format off
    animal->counter = 1; animal->processFlags &= ~4;
    // clang-format on

    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4U);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802CA23C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    omCreateProcess(obj, func_beach_802CA0F4, 1U, 1U);
    // clang-format off
    animal->counter = 1; animal->processFlags &= ~4;
    // clang-format on
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4U);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802CA2BC(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD8E4);
}
