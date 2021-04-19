#include "common.h"

extern animalDef D_802CBFF4;
extern animalDef beachAnimalData[17];

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/beachSpawnMagikarpAtGObj.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C416C_55C1DC.s")

void beachAnimalAdd(roomGFX* param_1, roomGFX* param_2) {
    animalAdd(param_1, param_2, beachAnimalData);
}

void func_802C42F8_55C368(s32* param_1, objectSpawn* param_2) {
    func_8036406C(param_1, param_2, beachAnimalData);
}

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C431C_55C38C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4340_55C3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C43CC_55C43C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4430_55C4A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4438_55C4A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4440_55C4B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C44D4_55C544.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C45C0_55C630.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4738_55C7A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/55C110/func_802C4740_55C7B0.s")
