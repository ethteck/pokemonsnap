#include "common.h"

extern animalDef D_802C6FC4_649474;

void evolveIntoMuk(GObj* obj) {
    GObj* muk;
    animalDef def = D_802C6FC4_649474;

    muk = addAnimalAtGeo(obj, AnimalID_MUK, &def);
    muk->rootNode->xform->euler.y = obj->rootNode->xform->euler.y;
    endGObjProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0888_642D38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0960_642E10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C09C4_642E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0A28_642ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0A8C_642F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0AF0_642FA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0BB0_643060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0CD8_643188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0D34_6431E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0E28_6432D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0E80_643330.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C0F30_6433E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C1018_6434C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C10C8_643578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C1100_6435B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C1124_6435D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C1178_643628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C11E8_643698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C1288_643738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C12E4_643794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C134C_6437FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C13B4_643864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/642CC0/func_802C13EC_64389C.s")
