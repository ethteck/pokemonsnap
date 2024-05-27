#include "common.h"
#include "app_level.h"

extern s32 D_80393BD4_533FE4;
extern s32 D_80393BD8_533FE8;

f32 func_803660E0_5064F0(GObj* obj, u8 arg1) {
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 tmp;

    if (D_80393BD4_533FE4 == 0 || D_80393BD8_533FE8 == 0) {
        return 0.0f;
    }
    if (pokemon == NULL) {
        return 0.0f;
    }
    tmp = pokemon->playerDist / 100.0f;
    return arg1 / (arg1 + tmp);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366160_506570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_8036621C_50662C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366328_506738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366470_506880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_8036650C_50691C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366520_506930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_803667C0_506BD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366864_506C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_803668DC_506CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366918_506D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366970_506D80.s")
