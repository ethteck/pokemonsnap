#include "common.h"

#include "sys/interpolation.h"

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001ED60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001EEA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F030.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F3D8.s")

void func_8001F4E4(Vec3f*, InterpData*, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F4E4.s")

void func_8001F770(Vec3f*, InterpData*, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F8F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F990.s")

f32 func_8001FA94(InterpData*, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001FA94.s")

void func_8001FCA4(Vec3f* arg0, InterpData* arg1, f32 arg2) {
    f32 thing = func_8001FA94(arg1, arg2);

    func_8001F4E4(arg0, arg1, thing);
}

void func_8001FCE8(Vec3f* arg0, InterpData* arg1, f32 arg2) {
    func_8001F770(arg0, arg1, func_8001FA94(arg1, arg2));
}
