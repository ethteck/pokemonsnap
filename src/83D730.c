#include "common.h"

typedef struct UnkClaretTilapia UnkClaretTilapia;
struct UnkClaretTilapia {
    UnkClaretTilapia* unk0;
    s32 unk4;
    s32 unk8;
    s32 pad;
    // Followed by data[]
};

typedef struct UnkCreamGrouper UnkCreamGrouper;
struct UnkCreamGrouper {
    u8 pad_00[4];
    s32 unk4;
    s32 unk8;
    u8 pad_0C[4];
    UnkCreamGrouper* unk10;
    UnkCreamGrouper* unk14;
};

extern UnkClaretTilapia* D_803A6900_87A0B0;
extern s32 D_803A6904_87A0B4;
extern UnkClaretTilapia* D_803A6908_87A0B8;

extern UnkCreamGrouper D_803A6910_87A0C0;

void func_8036A0BC_83D86C(UnkClaretTilapia*);
void func_80369FD4_83D784(void*, s32);
UnkCreamGrouper* func_8036A07C_83D82C(void*, u32);

void func_80369F80_83D730(UnkCreamGrouper* arg0, UnkCreamGrouper* arg1, UnkCreamGrouper* arg2) {
    arg0->unk10 = arg1;
    arg1->unk10 = arg2;
    arg2->unk14 = arg1;
    arg1->unk14 = arg0;
}

void func_80369F94_83D744(UnkCreamGrouper* arg0) {
    func_80369F80_83D730(D_803A6910_87A0C0.unk14, arg0, &D_803A6910_87A0C0);
}

void func_80369FC0_83D770(UnkCreamGrouper* arg0) {
    UnkCreamGrouper* temp_v0;
    UnkCreamGrouper* temp_v1;

    temp_v0 = arg0->unk14;
    temp_v1 = arg0->unk10;
    temp_v0->unk10 = temp_v1;
    temp_v1->unk14 = temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/83D730/func_80369FD4_83D784.s")

UnkCreamGrouper* func_8036A038_83D7E8(s32 arg0) {
    UnkCreamGrouper* var_v1;

    for (var_v1 = D_803A6910_87A0C0.unk10; var_v1 != &D_803A6910_87A0C0; var_v1 = var_v1->unk10) {
        if (var_v1->unk4 >= arg0) {
            return var_v1;
        }
    }

    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/83D730/func_8036A07C_83D82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/83D730/func_8036A0BC_83D86C.s")

void* func_8036A194_83D944(u32 arg0) {
    u32 temp_a1;
    UnkCreamGrouper* temp_v0;

    if (arg0 < 8) {
        arg0 = 8;
    }
    temp_a1 = (arg0 + 0x17) & ~7;
    temp_v0 = func_8036A038_83D7E8(temp_a1);
    if (temp_v0 == NULL) {
        return NULL;
    }
    if ((temp_v0->unk4 - temp_a1) > 0x18) {
        func_80369F94_83D744(func_8036A07C_83D82C(temp_v0, temp_a1));
    }
    func_80369FC0_83D770(temp_v0);
    temp_v0->unk8 = 1;

    return &temp_v0->unk10;
}

// Probably dealloc
void func_8036A228_83D9D8(void* arg0) {
    func_8036A0BC_83D86C((UnkClaretTilapia*) (((uintptr_t) arg0) - sizeof(UnkClaretTilapia)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/83D730/func_8036A248_83D9F8.s")

void func_8036A3F8_83DBA8(void* arg0, s32 arg1) {
    func_80369FD4_83D784(arg0, arg1);
}

s32 func_8036A418_83DBC8(void) {
    s32 end;
    UnkClaretTilapia* cur;

    end = 0;
    for (cur = D_803A6900_87A0B0; cur < D_803A6908_87A0B8; cur = (UnkClaretTilapia*) ((uintptr_t) cur + cur->unk4)) {
        if (cur->unk8 != 0) {
            end += cur->unk4;
        }
    }

    return end;
}
