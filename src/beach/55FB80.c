#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7B10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7C7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7CF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7DEC.s")

void func_beach_802C7E38(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CCDA4);
}

// TODO: potential file split

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7E70.s")

void func_beach_802C7F1C(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal = obj->userData;
    func_8035ED90_4FF1A0(obj, func_beach_802C7F74);
    animal->transitionGraph = &D_beach_802CCE1C;
    runInteractionsAndWaitForFlags(obj, 0U);
    updateAnimalState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C8028.s")

void func_beach_802C80BC(GObj* obj) {
    D_beach_802CCDFC += 1;
    updateAnimalState(obj, NULL);
}

void func_beach_802C80F0(GObj* obj) {
    D_beach_802CCE00++;
    updateAnimalState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C8124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C816C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C81C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C821C.s")

void func_beach_802C8274(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    spawnAnimalUsingDeltaHeight(gObjID, id, roomA, roomB, spawn, &D_beach_802CCE50);
}
