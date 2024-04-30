#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5620.s")

void func_beach_802C56C8(GObj* obj) {
    func_8035ED90_4FF1A0(obj, func_beach_802C5620);
    updateAnimalState(obj, func_beach_802C5700);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5768.s")

void func_beach_802C5828(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    forceAnimalAnimation(obj, &D_beach_802CC134);
    animal->transitionGraph = &D_beach_802CC1D4;
    runInteractionsAndWaitForFlags(obj, 1U);
    updateAnimalState(obj, func_beach_802C5700);
}

void func_beach_802C5884(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 8;
    updateAnimalState(obj, func_beach_802C5768);
}

void func_beach_802C58B8(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    animal->flags |= 8;
    updateAnimalState(obj, func_beach_802C5828);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C58EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C594C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C59C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5A20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5B68.s")

void func_beach_802C5BD4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    setAnimalAnimation(obj, &D_beach_802CC15C);
    animal->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updateAnimalState(obj, func_beach_802C5700);
}

void func_beach_802C5C28(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CC2F0);
}
