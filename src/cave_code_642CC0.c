#include "common.h"

extern animalDef D_802C6FC4;

void evolveIntoMuk(GObj* obj) {
    GObj* muk;
    animalDef def = D_802C6FC4;

    muk = addAnimalAtGeo(obj, AnimalID_MUK, &def);
    muk->rootNode->xform->euler.y = obj->rootNode->xform->euler.y;
    endGObjProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C09C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0A28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0A8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0AF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0E28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0E80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C0F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C1018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C10C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C1100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C1124.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C1178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C11E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C1288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C12E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C134C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C13B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave_code_642CC0/func_802C13EC.s")
