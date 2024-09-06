#include "common.h"
#include "unk_end_level.h"

extern s32 D_80381920_8550D0;

void func_8036F8A0_843050(UnkFireHerring* arg0, s32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843050/func_8036F8A0_843050.s")

void func_8036FABC_84326C(UnkFireHerring* arg0, s32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843050/func_8036FABC_84326C.s")

void func_8036FCA4_843454(UnkFireHerring* arg0, s32 arg1, s32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843050/func_8036FCA4_843454.s")

void func_8036FE54_843604(UnkFireHerring* arg0, s32 arg1) {
    func_8036F0DC_84288C(arg0, 1);

    switch (arg1) {
        case 0:
            func_8036F8A0_843050(arg0, arg1, 1);
            break;
        case 1:
            func_8036F8A0_843050(arg0, arg1, 1);
            break;
        case 2:
            func_8036FABC_84326C(arg0, arg1, 1);
            break;
        case 3:
            func_8036FCA4_843454(arg0, arg1, 1);
            break;
    }

    func_8036F198_842948(arg0, 0xFF);
    func_8036F0A0_842850(arg0, false);
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843050/func_8036FF20_8436D0.s")
