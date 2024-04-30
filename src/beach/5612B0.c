#include "common.h"
#include "beach.h"

void func_beach_802C9240(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);

    D_beach_802CD3F4 = animal->path;
    updateAnimalState(obj, func_beach_802C9274);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C92BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C93B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C943C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C94F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C95F0.s")

void func_beach_802C9694(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 30.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C96F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9760.s")

void func_beach_802C97D4(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C98F4.s")

void func_beach_802C9978(GObj* obj) {
    updateAnimalState(obj, func_beach_802C9830);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C999C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9A10.s")

void func_beach_802C9A7C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CD55C);
}
