#include "common.h"
#include "unk_end_level.h"

typedef struct UnkCreamGrouper UnkCreamGrouper;
struct UnkCreamGrouper {
    /* 0x00 */ UnkCreamGrouper* unk_00;
    /* 0x04 */ s32 unk_04; // size ?
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8 pad_0C[4];
    /* 0x10 */ UnkCreamGrouper* unk_10;
    /* 0x14 */ UnkCreamGrouper* unk_14;
};

typedef struct UnkCreamGrouperInner {
    /* 0x00 */ UnkCreamGrouper* unk_00;
    /* 0x04 */ s32 unk_04; // size ?
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u8 pad_0C[4];
} UnkCreamGrouperInner; // size = 0x10

extern UnkCreamGrouper* D_803A6900_87A0B0;
extern s32 D_803A6904_87A0B4;
extern UnkCreamGrouper* D_803A6908_87A0B8;
extern UnkCreamGrouper D_803A6910_87A0C0;

void func_80369F80_83D730(UnkCreamGrouper* arg0, UnkCreamGrouper* arg1, UnkCreamGrouper* arg2) {
    arg0->unk_10 = arg1;
    arg1->unk_10 = arg2;
    arg2->unk_14 = arg1;
    arg1->unk_14 = arg0;
}

void func_80369F94_83D744(UnkCreamGrouper* arg0) {
    func_80369F80_83D730(D_803A6910_87A0C0.unk_14, arg0, &D_803A6910_87A0C0);
}

void func_80369FC0_83D770(UnkCreamGrouper* arg0) {
    UnkCreamGrouper* temp_v0;
    UnkCreamGrouper* temp_v1;

    temp_v0 = arg0->unk_14;
    temp_v1 = arg0->unk_10;
    temp_v0->unk_10 = temp_v1;
    temp_v1->unk_14 = temp_v0;
}

void func_80369FD4_83D784(UnkCreamGrouper*, u32);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83D730/func_80369FD4_83D784.s")

UnkCreamGrouper* func_8036A038_83D7E8(s32 arg0) {
    UnkCreamGrouper* var_v1;

    for (var_v1 = D_803A6910_87A0C0.unk_10; var_v1 != &D_803A6910_87A0C0; var_v1 = var_v1->unk_10) {
        if (var_v1->unk_04 >= arg0) {
            return var_v1;
        }
    }

    return NULL;
}

UnkCreamGrouper* func_8036A07C_83D82C(UnkCreamGrouper*, u32);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83D730/func_8036A07C_83D82C.s")

void func_8036A0BC_83D86C(UnkCreamGrouper*);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83D730/func_8036A0BC_83D86C.s")

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
    if ((temp_v0->unk_04 - temp_a1) > 0x18) {
        func_80369F94_83D744(func_8036A07C_83D82C(temp_v0, temp_a1));
    }
    func_80369FC0_83D770(temp_v0);
    temp_v0->unk_08 = 1;

    return &temp_v0->unk_10;
}

// Probably dealloc
void func_8036A228_83D9D8(void* arg0) {
    func_8036A0BC_83D86C((UnkCreamGrouper*) (((uintptr_t) arg0) - sizeof(UnkCreamGrouperInner)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83D730/func_8036A248_83D9F8.s")

void func_8036A3F8_83DBA8(void* arg0, s32 arg1) {
    func_80369FD4_83D784(arg0, arg1);
}

s32 func_8036A418_83DBC8(void) {
    s32 end;
    UnkCreamGrouper* cur;

    end = 0;
    for (cur = D_803A6900_87A0B0; cur < D_803A6908_87A0B8; cur = (UnkCreamGrouper*) ((uintptr_t) cur + cur->unk_04)) {
        if (cur->unk_08 != 0) {
            end += cur->unk_04;
        }
    }

    return end;
}
