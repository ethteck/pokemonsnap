#include "common.h"
#include "beach.h"

void func_beach_802CA0A0(GObj* obj) {
    // TODO: see if this can be inlined
    AnimalDef sp18 = D_beach_802CD838;

    addAnimalAtGeo(obj, AnimalID_PIDGEY, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA0F4(GObj* obj) {
    // TODO: see if this can be inlined
    AnimalDef sp18 = D_beach_802CD848;

    addAnimalAtGeo(obj, AnimalID_SCYTHER, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA148(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->tangible = 0;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    animal->transitionGraph = &D_beach_802CD858;
    runInteractionsAndWaitForFlags(obj, 0);
    updateAnimalState(obj, NULL);
}

void func_beach_802CA198(GObj* obj) {
    weightedRandomStaightTransition(obj, &D_beach_802CD8B8);
}

void func_beach_802CA1BC(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    omCreateProcess(obj, func_beach_802CA0A0, 1, 1);
    // clang-format off
    animal->counter = 1; animal->processFlags &= ~4;
    // clang-format on

    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802CA23C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    omCreateProcess(obj, func_beach_802CA0F4, 1, 1);
    // clang-format off
    animal->counter = 1; animal->processFlags &= ~4;
    // clang-format on
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runAnimalCleanup(obj);
    updateAnimalState(obj, NULL);
}

void func_beach_802CA2BC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD8E4);
}
