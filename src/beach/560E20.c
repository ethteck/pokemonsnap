#include "common.h"
#include "beach.h"

void func_beach_802C8DB0(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->miscVars[0].field0 = animal->collisionRadius;
    animal->collisionRadius = 0;
    updateAnimalState(obj, func_beach_802C8DE8);
}

void func_beach_802C8DE8(GObj* obj) {
    runPathProcess(obj, func_beach_802C8E20);
    updateAnimalState(obj, func_beach_802C8E90);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C8E20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C8E90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C8F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C907C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C90E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C914C.s")

void func_beach_802C91CC(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}

void func_beach_802C9204(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}
