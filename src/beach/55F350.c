#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C72E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C737C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C73EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C7490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C74EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C755C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C75D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C762C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C76C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C7748.s")

void func_beach_802C77CC(GObj* obj) {
    updateAnimalState(obj, func_beach_802C762C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C77F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C7864.s")

void func_beach_802C78B0(GObj* obj) {
    runPathProcess(obj, func_beach_802C796C);
    updateAnimalState(obj, func_beach_802C78E8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C78E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C796C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C79DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55F350/func_beach_802C7A60.s")

void func_beach_802C7AD0(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CCCEC);
}
