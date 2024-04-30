#include "common.h"

extern animalInitData D_beach_802CE038;
extern AnimalDef D_beach_802CE0DC;
extern animalInitData D_beach_802CE0A8;

void func_beach_802CB08C(GObj*);
void func_beach_802CB128(GObj*);
void func_beach_802CBD04(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CAF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CAFEC.s")

void func_beach_802CB054(GObj* arg0) {
    runPathProcess(arg0, func_beach_802CB128);
    updateAnimalState(arg0, func_beach_802CB08C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB2D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB36C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB3DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB44C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB594.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB6B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CBA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CBB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CBB90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CBC4C.s")

void func_beach_802CBCA8(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362EE0_5032F0(gObjID, id, roomA, roomB, spawn, &D_beach_802CE038);
}

void func_beach_802CBCE0(GObj* obj) {
    updateAnimalState(obj, func_beach_802CBD04);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CBD04.s")

void func_beach_802CBDA0(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn) {
    func_80362DC4_5031D4(gObjID, id, roomA, roomB, spawn, &D_beach_802CE0A8);
}

void func_beach_802CBDD8(GObj* arg0) {
    GObj* var;

    var = addAnimalAtGeo(arg0, 0x3EEU, &D_beach_802CE0DC);
    GET_ANIMAL(var)->behavior = 0;
}
