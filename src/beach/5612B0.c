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

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C96F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C9760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C97D4.s")

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
