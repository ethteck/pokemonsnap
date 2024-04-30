#include "common.h"
#include "beach.h"

void func_beach_802C9AC0(GObj* obj) {
    updateAnimalState(obj, func_beach_802C9AE4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9AE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9BF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9CF8.s")

void func_beach_802C9D70(GObj* obj) {
    UNUSED s32 pad[3];
    Animal* animal = GET_ANIMAL(obj);

    animal->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    animal->pathProcess = NULL;
    animal->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9E70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802C9F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/561B30/func_beach_802CA010.s")

void func_beach_802CA05C(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CD7A8);
}
