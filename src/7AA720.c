#include "common.h"
#include "world/world.h"

void func_802D1190(GObj* animal) {
    updateAnimalState(animal, NULL);
}

void func_802D11B0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_802EC7B8_7C5D48);
}
