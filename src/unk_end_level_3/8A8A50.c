#include "common.h"

typedef struct UnkOrangeShark {
    s32 var_0;
    char* var_4;
    s32 var_8;
    s32 var_C;
} UnkOrangeShark;

typedef struct UnkCobaltBarbel {
    s32 var_0;
    s32 var_4;
} UnkCobaltBarbel;

extern s32 D_801958C0_95B0E0;
extern s32 D_801958F0_95B110;

UnkStruct800BEDF8* func_800AA740(int);      /* extern */
s32 func_800E1B40_8A7360(void);             /* extern */
void func_800E1C18_8A7438(int);             /* extern */
void func_800E1D1C_8A753C(int);             /* extern */
void func_800E1FEC_8A780C(s32);             /* extern */
void func_800E2A04_8A8224(void);            /* extern */
void func_800E61B4_8AB9D4(int, int);        /* extern */
s32 func_800E6404_8ABC24(void);             /* extern */
void func_8037060C_843DBC(int, s32);        /* extern */
void func_80370900_8440B0(int, s32);        /* extern */
void func_80370C34_8443E4(UnkOrangeShark*); /* extern */
char* func_803717A8_844F58(void*, s32);     /* extern */
extern s32 D_80195894_95B0B4;

extern UnkOrangeShark* D_80195CEC_95B50C[];
extern void* D_80206B48_9CC368;
void func_800E307C_8A889C(void);

extern UnkCobaltBarbel (*D_80206B44_9CC364)[];
void func_80370004_8437B4(s32, s32);

UNK_PTR func_800E3230_8A8A50(void) {
    if (func_800BFCA0_5CB40(7) == 0) {
        return &D_801958F0_95B110;
    }
    return &D_801958C0_95B0E0;
}

s32 func_800E3264_8A8A84(UnkStruct800BEDF8* arg0, s32* arg1) {
    int temp;
    if (arg0 == NULL) {
        if (arg1 != NULL) {
            func_80370004_8437B4(0x16, (*arg1 * 0x18) + 0x1D);
            func_8037005C_84380C(0x3E, 0xD);
        }
        return 0;
    }

    func_8036FFE0_843790(0x16, (*arg1 * 0x18) + 0x1D);

    if ((arg0->unk_18 & 0x10000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while ((*D_80206B44_9CC364)[*arg1].var_0 == 0x23);

        auPlaySound(0x41U);
    }

    if ((arg0->unk_18 & 0x20000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while ((*D_80206B44_9CC364)[*arg1].var_0 == 0x23);

        auPlaySound(0x41U);
    }

    if (arg0->unk_18 & 0x4000) {
        return -1;
    }

    return 0;
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/func_800E3404_8A8C24.s")
#else
s32 func_800E3404_8A8C24(void) {
    UnkStruct800BEDF8* var_v0;
    s32 sp40;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 var_s2;
    UnkOrangeShark* shark;

    var_s2 = -1;
    sp40 = 0;
    if ((getLevelId() >= 0) && (getLevelId() < 7)) {
        sp40 = getLevelId();
    }
    func_80370038_8437E8(0x3E, 0xD);
    func_800E1D1C_8A753C(1);
    func_800E1C18_8A7438(1);
    func_800E61B4_8AB9D4(1, 0);
    temp_s0 = func_800C0290_5D130();
    if (func_800BFC5C_5CAFC() < temp_s0) {
        func_803700A4_843854(0);
        func_80370900_8440B0(0, func_800C0290_5D130() + 6);
        shark = D_80195CEC_95B50C[func_800C0290_5D130()];
        func_80370C34_8443E4(shark);
        func_803705A4_843D54();
        func_800E2A04_8A8224();
        sp40 = func_800BFC5C_5CAFC();
        func_803700A4_843854(1);
    } else {
        sp40 = D_80195894_95B0B4;
        shark = D_80195CEC_95B50C[func_800BFC5C_5CAFC()];
        func_80370C34_8443E4(shark);
    }
    func_800E3264_8A8A84(NULL, &sp40);
    func_803700A4_843854(1);

    while (1) {
        if (func_800E6404_8ABC24() != 0) {
            var_v0 = func_800AA740(0);
        } else {
            var_v0 = func_800AA38C(0);
        }
        if (func_800E3264_8A8A84(var_v0, &sp40) != 0) {
            auPlaySound(0x43U);
            func_800E1D1C_8A753C(0);
            return 0;
        }
        func_800E1FEC_8A780C(sp40);
        if (var_v0->unk_18 & 0x8000) {
            auPlaySound(0x42U);
            func_8037060C_843DBC(1, (*D_80206B44_9CC364)[sp40].var_0);
            switch ((*D_80206B44_9CC364)[sp40].var_0) {
                case 6:
                    D_80195894_95B0B4 = 0;
                    return 4;
                case 7:
                    D_80195894_95B0B4 = 1;
                    return 4;
                case 10:
                    D_80195894_95B0B4 = 4;
                    return 4;
                case 9:
                    D_80195894_95B0B4 = 3;
                    return 4;
                case 8:
                    D_80195894_95B0B4 = 2;
                    return 4;
                case 11:
                    D_80195894_95B0B4 = 5;
                    return 4;
                case 12:
                    D_80195894_95B0B4 = 6;
                    return 4;
                case 5:
                    D_80206B48_9CC368 = &func_800E307C_8A889C;
                    func_800E1D1C_8A753C(0);
                    func_8037060C_843DBC(0, (*D_80206B44_9CC364)[sp40].var_0);
                    return 0;
            }
        } else {
            if (var_s2 != sp40) {
                var_s2 = sp40;
                func_8036A8E4_83E094(func_800E1B40_8A7360());
                func_8036B9EC_83F19C(func_800E1B40_8A7360(), 0, 0);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                temp_s0_2 = func_800E1B40_8A7360();
                shark = D_80195CEC_95B50C[func_800BFC5C_5CAFC()];
                func_8036C898_840048(temp_s0_2, func_803717A8_844F58(shark, (*D_80206B44_9CC364)[sp40].var_0));
            }
            ohWait(1);
        }
    }
}
#endif

s32 func_800E3774_8A8F94(void) {
    s32 i;
    s32 var_s1;

    var_s1 = 0;
    for (i = 0; i < 0x3C; i++) {
        if (func_800BFA44_5C8E4(i) != 0) {
            var_s1 += 1;
        }
    }

    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/D_801C5650_98AE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/D_801C5664_98AE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/D_801C5688_98AEA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/D_801C569C_98AEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/D_801C56C0_98AEE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/D_801C56D4_98AEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/func_800E37CC_8A8FEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/func_800E3CE8_8A9508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/func_800E3ED4_8A96F4.s")
