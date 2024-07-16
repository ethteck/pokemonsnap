#include "common.h"

#include "unk_end_level_5.h"

extern s32 D_80208B90_9D2DE0;
extern UNK_TYPE D_80208B98_9D2DE8;
extern s32 D_80208B94_9D2DE4;
extern s32 D_80208C18_9D2E68;
extern s32 D_80208C1C_9D2E6C;
extern s32 D_80208C20_9D2E70;
extern s32 D_80208C24_9D2E74;
extern s32 D_80208C28_9D2E78;
extern s32 D_80208C2C_9D2E7C;
extern s32 D_80208C30_9D2E80;

extern UNK_TYPE* D_80250120_A1A370;
extern UnkCanaryScallop* D_80250124_A1A374;

const char D_80208F50_9D31A0[] = "ひらく";
const char D_80208F58_menustr[] = "けんきゅうじょへ";
const char D_80208F6C_menustr[] = "みる";
const char D_80208F74_menustr[] = "いれかえ";
const char D_80208F80_menustr[] = "けす";
const char D_80208F88_menustr[] = "ひょうしへ";
const char D_80208F94_menustr[] = "くわしく";
const char D_80208FA0_menustr[] = "コメント";
const char D_80208FAC_menustr[] = "けす";
const char D_80208FB4_menustr[] = "もどる";

UNK_TYPE* func_801E1900_9ABB50(void) {
    return &D_80208B98_9D2DE8;
}

s32 func_801E191C_9ABB6C(void) {
    return D_80208B94_9D2DE4;
}

s32 func_801E1938_9ABB88(s32 arg0) {
    s32 i = arg0;

    for (i++; i <= func_801E3A80_9ADCD0(); i++) {
        if (func_801E38E0_9ADB30(i) != NULL) {
            return i;
        }
    }

    return arg0;
}

s32 func_801E19C4_9ABC14(s32 arg0) {
    s32 i = arg0;

    for (i--; i >= func_801E3A9C_9ADCEC(); i--) {
        if (func_801E38E0_9ADB30(i) != NULL) {
            return i;
        }
    }

    return arg0;
}

s32 func_801E1A50_9ABCA0(UnkStruct800BEDF8* arg0, s32* arg1) {
    if (arg0 == NULL) {
        D_80208C18_9D2E68 = -1;
        if (arg1 != NULL) {
            func_80370004_8437B4(22, (*arg1 * 24) + 29);
            func_8037005C_84380C(62, 12);
        } else {
            func_80370038_8437E8(62, 12);
        }
        return 0;
    }

    func_8036FFE0_843790(22, (*arg1 * 24) + 29);

    if ((arg0->unk_18 & 0x10000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while (D_80250124_A1A374[*arg1].unk_0 == 35);
        auPlaySound(0x41);
    }
    if ((arg0->unk_18 & 0x20000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while (D_80250124_A1A374[*arg1].unk_0 == 35);
        auPlaySound(0x41);
    }
    if (arg0->unk_18 & 0x4000) {
        return -1;
    }
    return 0;
}

s32 func_801E1C30_9ABE80(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2) {
    if (arg0 == NULL) {
        D_80208C1C_9D2E6C = -1;
        D_80208C20_9D2E70 = -1;
        func_801DE1FC_9A844C(D_80208B94_9D2DE4);
        return 0;
    }
    if ((arg0->unk_18 & 0x20000) && *arg2 <= 0) {
        (*arg2)++;
    }
    if ((arg0->unk_18 & 0x10000) && *arg2 > 0) {
        (*arg2)--;
    }
    if (arg0->unk_18 & 0x40000) {
        if (*arg1 < 2) {
            (*arg1)++;
        } else if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) < func_800BF9EC_5C88C() - 6) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 += 6;
            *arg1 = 0;
            func_80370004_8437B4((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if (arg0->unk_18 & 0x80000) {
        if (*arg1 > 0) {
            (*arg1)--;
        } else if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) > 0) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 -= 6;
            *arg1 = 2;
            func_80370004_8437B4((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if ((*arg1 != D_80208C1C_9D2E6C) || (*arg2 != D_80208C20_9D2E70)) {
        // bug? using the same variable twice. silly mask needed to match
        if (!((D_80208C1C_9D2E6C < 0) & 0xFFFFFFFF) || !(D_80208C1C_9D2E6C < 0)) {
            auPlaySound(0x45);
        }
        D_80208C1C_9D2E6C = *arg1;
        D_80208C20_9D2E70 = *arg2;
        D_80208B94_9D2DE4 = ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) + (*arg2 * 3)) + *arg1;
        func_8036FFE0_843790((*arg1 * 66) + 107, (*arg2 * 55) + 56);
        func_801DE1FC_9A844C(D_80208B94_9D2DE4);
    }
    return 0;
}

s32 func_801E1FE4_9AC234(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2, s32 arg3) {
    if (arg0 == NULL) {
        D_80208C24_9D2E74 = -1;
        D_80208C28_9D2E78 = -1;
        return 0;
    }
    func_801E3880_9ADAD0();
    if ((arg0->unk_18 & 0x20000) && *arg2 <= 0) {
        (*arg2)++;
    }
    if ((arg0->unk_18 & 0x10000) && *arg2 > 0) {
        (*arg2)--;
    }
    if (arg0->unk_18 & 0x40000) {
        if (*arg1 < 2) {
            (*arg1)++;
        } else if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) < func_800BF9EC_5C88C() - 6) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 += 6;
            *arg1 = 0;
            func_80370004_8437B4((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if (arg0->unk_18 & 0x80000) {
        if (*arg1 > 0) {
            (*arg1)--;
        } else if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) > 0) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 -= 6;
            *arg1 = 2;
            func_80370004_8437B4((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if ((*arg1 != D_80208C24_9D2E74) || (*arg2 != D_80208C28_9D2E78)) {
        // bug? using the same variable twice. silly mask needed to match
        if (!((D_80208C24_9D2E74 < 0) & 0xFFFFFFFF) || !(D_80208C24_9D2E74 < 0)) {
            auPlaySound(0x45);
        }
        D_80208C24_9D2E74 = *arg1;
        D_80208C28_9D2E78 = *arg2;
        D_80208B94_9D2DE4 = ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) + (*arg2 * 3)) + *arg1;
        if (arg3 != 0) {
            func_8036FFE0_843790((*arg1 * 66) + 99, (*arg2 * 55) + 48);
            func_801DDDF8_9A8048((*arg1 * 66) + 96, (*arg2 * 55) + 45);
        } else {
            func_8036FFE0_843790((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DDDF8_9A8048(-1, -1);
        }
        func_801DE1FC_9A844C(D_80208B94_9D2DE4);
    }
    return 0;
}

s32 func_801E2438_9AC688(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2) {
    if (arg0 == NULL) {
        D_80208C2C_9D2E7C = -1;
        D_80208C30_9D2E80 = -1;
        func_801DEA4C_9A8C9C(1, 0, 0);
        return 0;
    }
    func_801E3880_9ADAD0();
    if (arg0->unk_18 & 0x20000) {
        if (*arg2 < 0x13) {
            (*arg2)++;
        } else {
            *arg2 = 0;
        }
    }
    if (arg0->unk_18 & 0x10000) {
        if (*arg2 > 0) {
            (*arg2)--;
        } else {
            *arg2 = 19;
        }
    }
    if (arg0->unk_18 & 0x40000) {
        if (*arg2 < 0x13) {
            if (*arg1 < 4) {
                (*arg1)++;
            } else {
                *arg1 = 0;
            }
        } else if (*arg1 < 2) {
            (*arg1)++;
        } else {
            *arg1 = 0;
        }
    }
    if (arg0->unk_18 & 0x80000) {
        if (*arg2 < 19) {
            if (*arg1 > 0) {
                *arg1 -= 1;
            } else {
                *arg1 = 4;
            }
        } else if (*arg1 > 0) {
            *arg1 -= 1;
        } else {
            *arg1 = 2;
        }
    }

    if (*arg2 < 19) {
        if ((*arg1 != D_80208C2C_9D2E7C) || (*arg2 != D_80208C30_9D2E80)) {
            // bug? using the same variable twice. silly mask needed to match
            if (!((D_80208C2C_9D2E7C < 0) & 0xFFFFFFFF) || !(D_80208C2C_9D2E7C < 0)) {
                auPlaySound(0x45);
            }
            D_80208C2C_9D2E7C = *arg1;
            D_80208C30_9D2E80 = *arg2;
            func_801DE998_9A8BE8(1);
            func_80370038_8437E8(4, 5);
            func_8036FFE0_843790((*arg1 * 13) + 25, (*arg2 * 10) + 22);
            func_801DEA4C_9A8C9C(0, *arg1, *arg2);
        }
    } else if (*arg1 != D_80208C2C_9D2E7C || *arg2 != D_80208C30_9D2E80) {
        D_80208C2C_9D2E7C = *arg1;
        D_80208C30_9D2E80 = *arg2;
        auPlaySound(0x41);
        func_801DE998_9A8BE8(0);
        if (*arg1 < 2) {
            func_80370038_8437E8(4, 5);
            func_8036FFE0_843790((*arg1 * 13) + 25, (*arg2 * 10) + 22);
        } else {
            func_80370038_8437E8(0xD, 5);
            func_8036FFE0_843790(68, (*arg2 * 10) + 22);
        }
        func_801DEA4C_9A8C9C(0, *arg1, *arg2);
    }
    return 0;
}

s32 func_801E2874_9ACAC4(void) {
    UnkStruct800BEDF8* sp2C;
    s32 sp28;

    if (D_80208B90_9D2DE0) {
        func_801E0774_9AA9C4();
    }
    D_80208B90_9D2DE0 = TRUE;
    sp28 = 0;
    func_80370C34_8443E4(&D_80208B98_9D2DE8);
    func_80370038_8437E8(0x3E, 0xC);
    func_803700A4_843854(1);

    while (TRUE) {
        sp2C = func_800AA38C(0);
        if (func_801E1A50_9ABCA0(sp2C, &sp28) != 0) {
            auPlaySound(0x43);
            func_801E09A0_9AABF0(0x3C);
            return 6;
        }
        if (sp2C->unk_18 & 0x8000) {
            auPlaySound(0x42);
            switch (D_80250124_A1A374[sp28].unk_0) {
                case 30:
                    func_80370A48_8441F8();
                    func_801E09A0_9AABF0(0);
                    return 0;
                case 17:
                    func_801E09A0_9AABF0(0x3C);
                    return 6;
            }
        }
        ohWait(1);
    }
}

s32 func_801E29A8_9ACBF8(void);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9ABB50/func_801E29A8_9ACBF8.s")

void func_801E37A0_9AD9F0(void) {
    UNUSED s32 pad;
    s32 sp28;

    sp28 = 1;
    D_80250120_A1A370 = &D_80208B98_9D2DE8;
    D_80250124_A1A374 = func_80370600_843DB0();
    D_80208B94_9D2DE4 = 0;
    func_80370134_8438E4();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);

    while (TRUE) {
        switch (sp28) {
            case 1:
                sp28 = func_801E2874_9ACAC4();
                break;
            case 0:
                sp28 = func_801E29A8_9ACBF8();
                break;
            case 6:
                return;
        }
    }
}
