#include "common.h"

#include "pokemon_album.h"

s32 D_80208B90_9D2DE0 = 0;
s32 D_80208B94_9D2DE4 = 0;

UnkCanaryScallop D_80208B98_9D2DE8[] = {
    { 30, "ひらく" },
    { 34, NULL },
    { 17, "けんきゅうじょへ" },
    { 35, NULL },
};
UnkCanaryScallop D_80208B98_9D2DE8_4[] = {
    { 20, "みる" },
    { 26, "いれかえ" },
    { 19, "けす" },
    { 34, NULL },
    { 31, "ひょうしへ" },
    { 35, NULL },
};
UnkCanaryScallop D_80208B98_9D2DE8_10[] = {
    { 28, "くわしく" },
    { 27, "コメント" },
    { 19, "けす" },
    { 34, NULL },
    { 5, "もどる" },
    { 35, NULL },
};

s32 D_80208C18_9D2E68 = -1;
s32 D_80208C1C_9D2E6C = -1;
s32 D_80208C20_9D2E70 = -1;
s32 D_80208C24_9D2E74 = -1;
s32 D_80208C28_9D2E78 = -1;
s32 D_80208C2C_9D2E7C = -1;
s32 D_80208C30_9D2E80 = -1;

UNK_TYPE* D_80250120_A1A370;
UnkCanaryScallop* D_80250124_A1A374;

UnkCanaryScallop* func_801E1900_9ABB50(void) {
    return D_80208B98_9D2DE8;
}

s32 func_801E191C_9ABB6C(void) {
    return D_80208B94_9D2DE4;
}

s32 func_801E1938_9ABB88(s32 arg0) {
    s32 i = arg0;

    for (i++; i <= func_801E3A80_9ADCD0(); i++) {
        if (album_GetAlbumPhoto(i) != NULL) {
            return i;
        }
    }

    return arg0;
}

s32 func_801E19C4_9ABC14(s32 arg0) {
    s32 i = arg0;

    for (i--; i >= func_801E3A9C_9ADCEC(); i--) {
        if (album_GetAlbumPhoto(i) != NULL) {
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
        } while (D_80250124_A1A374[*arg1].unk_00 == 35);
        auPlaySound(0x41);
    }
    if ((arg0->unk_18 & 0x20000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while (D_80250124_A1A374[*arg1].unk_00 == 35);
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
    D_80208B90_9D2DE0 = true;
    sp28 = 0;
    func_80370C34_8443E4(D_80208B98_9D2DE8);
    func_80370038_8437E8(0x3E, 0xC);
    func_803700A4_843854(1);

    while (true) {
        sp2C = func_800AA38C(0);
        if (func_801E1A50_9ABCA0(sp2C, &sp28) != 0) {
            auPlaySound(0x43);
            func_801E09A0_9AABF0(0x3C);
            return 6;
        }
        if (sp2C->unk_18 & 0x8000) {
            auPlaySound(0x42);
            switch (D_80250124_A1A374[sp28].unk_00) {
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

s32 func_801E29A8_9ACBF8(void) {
    UnkStruct800BEDF8* sp4C;
    s32 sp48;
    s32 pad;
    u32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp40 = 0;
    sp3C = 0;
    sp30 = D_80208B94_9D2DE4 % 6;
    sp38 = sp30 % 3;
    sp34 = sp30 / 3;
    func_801E0AF0_9AAD40();
    func_80370038_8437E8(0x3E, 0xC);
    sp48 = 0;
    func_80370C34_8443E4(D_80208B98_9D2DE8_4);
    func_803705A4_843D54();
    func_803700A4_843854(1);
loop_1:
    sp4C = func_800AA38C(0);
    switch (sp40) {
        case 0:
            if (func_801E1A50_9ABCA0(sp4C, &sp48) != 0) {
                sp48 = 0;
                auPlaySound(0x43);
                func_801E0E58_9AB0A8();
                func_801E1A50_9ABCA0(NULL, &sp48);
                return 1;
            }
            if (sp4C->unk_18 & 0x8000) {
                auPlaySound(0x42);
                switch (D_80250124_A1A374[sp48].unk_00) {
                    case 20:
                        func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                        func_80370038_8437E8(0x32, 0x25);
                        sp40 = 1;
                        break;
                    case 26:
                        func_80370038_8437E8(0x32, 0x25);
                        sp40 = 3;
                        sp3C = 0;
                        func_801E1FE4_9AC234(NULL, &sp38, &sp34, sp3C);
                        break;
                    case 19:
                        func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                        func_80370038_8437E8(0x32, 0x25);
                        sp40 = 7;
                        break;
                    case 31:
                        sp48 = 0;
                        func_801E1A50_9ABCA0(NULL, &sp48);
                        func_801E0E58_9AB0A8();
                        return 1;
                }
            }
            break;
        case 1:
            func_801E1C30_9ABE80(sp4C, &sp38, &sp34);
            if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) < func_800BF9EC_5C88C() - 6) {
                func_803713D4_844B84(2);
            } else {
                func_803713EC_844B9C(2);
            }

            if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) > 0) {
                func_803713D4_844B84(1);
            } else {
                func_803713EC_844B9C(1);
            }

            if (sp4C->unk_18 & 0x4000) {
                auPlaySound(0x41);
                D_80208B94_9D2DE4 -= D_80208B94_9D2DE4 % 6;
                func_803713EC_844B9C(3);
                sp48 = 0;
                func_801E1A50_9ABCA0(NULL, NULL);
                sp40 = 0;
            } else if (sp4C->unk_18 & 0x8000) {
                if (album_GetAlbumPhoto(D_80208B94_9D2DE4) == NULL) {
                    break;
                }

                auPlaySound(0x42);
                sp48 = 0;
                func_80370C34_8443E4(D_80208B98_9D2DE8_10);
                func_801E0FFC_9AB24C(2);
                func_801E1A50_9ABCA0(NULL, NULL);
                sp40 = 2;
            }
            break;
        case 2:
            func_801E1A50_9ABCA0(sp4C, &sp48);
            if (D_80208B94_9D2DE4 < func_801E3A80_9ADCD0()) {
                func_803713D4_844B84(2);
            } else {
                func_803713EC_844B9C(2);
            }
            if (func_801E3A9C_9ADCEC() < D_80208B94_9D2DE4) {
                func_803713D4_844B84(1);
            } else {
                func_803713EC_844B9C(1);
            }
            if (sp4C->unk_18 & 0x4000) {
                auPlaySound(0x43);
                func_801E0FFC_9AB24C(1);
                func_80370038_8437E8(0x32, 0x25);
                func_8036FFE0_843790((sp38 * 66) + 107, (sp34 * 55) + 56);
                func_803713EC_844B9C(3);
                func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                sp48 = 0;
                func_80370C34_8443E4(D_80208B98_9D2DE8_4);
                sp40 = 1;
            } else if (sp4C->unk_18 & 0x8000) {
                switch (D_80250124_A1A374[sp48].unk_00) {
                    case 28:
                        auPlaySound(0x42);
                        func_801DF744_9A9994(0, D_80208B94_9D2DE4);
                        sp24 = 0;
                        sp40 = 4;
                        break;
                    case 27:
                        auPlaySound(0x42);
                        func_803700A4_843854(0);
                        func_803713EC_844B9C(3);
                        func_80370A48_8441F8();
                        ohWait(30);
                        album_SwitchCharacterGridPage(0);
                        sp28 = 0;
                        sp2C = 0;
                        func_80370038_8437E8(4, 5);
                        func_8036FFE0_843790(0x19, 0x16);
                        func_801E2438_9AC688(NULL, &sp2C, &sp28);
                        func_801DE998_9A8BE8(1);
                        func_803700A4_843854(1);
                        sp40 = 5;
                        func_800AA85C(0x18, 6);
                        break;
                    case 19:
                        auPlaySound(0x42);
                        func_803700A4_843854(0);
                        func_803713EC_844B9C(3);
                        func_801E1168_9AB3B8(1);
                        sp40 = 6;
                        break;
                    case 5:
                        auPlaySound(0x43);
                        func_801E0FFC_9AB24C(1);
                        func_80370038_8437E8(0x32, 0x25);
                        func_8036FFE0_843790((sp38 * 66) + 107, (sp34 * 55) + 56);
                        func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                        sp48 = 0;
                        func_80370C34_8443E4(D_80208B98_9D2DE8_4);
                        sp40 = 1;
                        break;
                }
            } else if ((sp4C->unk_18 & 0x40000) && (D_80208B94_9D2DE4 < func_801E3A80_9ADCD0())) {
                auPlaySound(0x45);
                D_80208B94_9D2DE4 = func_801E1938_9ABB88(D_80208B94_9D2DE4);
                func_801DE2BC_9A850C(D_80208B94_9D2DE4);
            } else if ((sp4C->unk_18 & 0x80000) && (func_801E3A9C_9ADCEC() < D_80208B94_9D2DE4)) {
                auPlaySound(0x45);
                D_80208B94_9D2DE4 = func_801E19C4_9ABC14(D_80208B94_9D2DE4);
                func_801DE2BC_9A850C(D_80208B94_9D2DE4);
            }
            break;
        case 3:
            func_801E1FE4_9AC234(sp4C, &sp38, &sp34, sp3C);
            if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) < (func_800BF9EC_5C88C() - 6)) {
                func_803713D4_844B84(2);
            } else {
                func_803713EC_844B9C(2);
            }
            if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) > 0) {
                func_803713D4_844B84(1);
            } else {
                func_803713EC_844B9C(1);
            }
            if (sp4C->unk_18 & 0x4000) {
                D_80208B94_9D2DE4 -= D_80208B94_9D2DE4 % 6;
                sp48 = 1;
                func_80370090_843840(true);
                func_803713EC_844B9C(3);
                func_801E1A50_9ABCA0(NULL, NULL);
                func_801DDDF8_9A8048(-1, -1);
                func_801E3F00_9AE150();
                sp40 = 0;
            } else if (sp4C->unk_18 & 0x8000) {
                func_801E1FE4_9AC234(NULL, &sp38, &sp34, sp3C);
                sp3C = func_801E3B34_9ADD84(D_80208B94_9D2DE4);
                if (sp3C != 0) {
                    func_80370090_843840(false);
                } else {
                    func_80370090_843840(true);
                }
            }
            break;
        case 4:
            if (sp4C->unk_18 & 0xC000) {
                auPlaySound(0x43);
                func_801DF744_9A9994(2, D_80208B94_9D2DE4);
                sp48 = 0;
                func_80370C34_8443E4(D_80208B98_9D2DE8_10);
                ohWait(21);
                func_801E1A50_9ABCA0(NULL, &sp48);
                func_803700A4_843854(1);
                sp40 = 2;
                break;
            }
            break;
        case 5:
            func_801E2438_9AC688(sp4C, &sp2C, &sp28);
            if (sp4C->unk_18 & 0x4000) {
                if (func_801DD0CC_9A731C() != 0) {
                    auPlaySound(0x4A);
                    func_801E0300_9AA550();
                } else {
                    sp2C = 3;
                    sp28 = 0x13;
                }
                break;
            }

            if (sp4C->unk_18 & 0x1000) {
                sp2C = 3;
                sp28 = 0x13;
                break;
            }

            if (sp4C->unk_18 & 0x8000) {
                if ((sp2C >= 2) && (sp28 == 0x13)) {
                    auPlaySound(0x42);
                    func_803700A4_843854(0);
                    album_SwitchCharacterGridPage(6);
                    func_80370C34_8443E4(D_80208B98_9D2DE8_10);
                    ohWait(21);
                    sp48 = 1;
                    func_801E1A50_9ABCA0(NULL, &sp48);
                    func_803700A4_843854(1);
                    sp40 = 2;
                    func_800AA85C(0x18, 0xC);
                } else {
                    album_PressedCharacterInGrid(sp2C, sp28);
                    func_801DEA4C_9A8C9C(0, sp2C, sp28);
                }
                if (func_801DD0CC_9A731C() >= 0x1F) {
                    sp2C = 2;
                    sp28 = 0x13;
                }
                break;
            }
            break;
        case 6:
            if (sp4C->unk_18 & 0x4000) {
                auPlaySound(0x43);
                func_801E1168_9AB3B8(0);
                func_801E1A50_9ABCA0(NULL, &sp48);
                func_803700A4_843854(1);
                sp40 = 2;
                break;
            }

            if (sp4C->unk_18 & 0x8000) {
                auPlaySound(0x42);
                func_801E3880_9ADAD0();
                func_801E1168_9AB3B8(0);
                func_801E1320_9AB570(D_80208B94_9D2DE4);
                func_801E0FFC_9AB24C(1);
                func_80370038_8437E8(0x32, 0x25);
                func_8036FFE0_843790((sp38 * 66) + 107, (sp34 * 55) + 56);
                func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                sp48 = 0;
                func_80370C34_8443E4(D_80208B98_9D2DE8_4);
                func_803700A4_843854(1);
                sp40 = 1;
                break;
            }
            break;
        case 7:
            func_801E1C30_9ABE80(sp4C, &sp38, &sp34);
            if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) < (func_800BF9EC_5C88C() - 6)) {
                func_803713D4_844B84(2);
            } else {
                func_803713EC_844B9C(2);
            }
            if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) > 0) {
                func_803713D4_844B84(1);
            } else {
                func_803713EC_844B9C(1);
            }
            if (sp4C->unk_18 & 0x4000) {
                auPlaySound(0x41);
                D_80208B94_9D2DE4 -= D_80208B94_9D2DE4 % 6;
                func_803713EC_844B9C(3);
                sp48 = 2;
                func_801E1A50_9ABCA0(NULL, NULL);
                sp40 = 0;
            } else if (sp4C->unk_18 & 0x8000) {
                if (album_GetAlbumPhoto(D_80208B94_9D2DE4) == NULL) {
                    break;
                }

                auPlaySound(0x42);
                func_803713EC_844B9C(3);
                func_801E0FFC_9AB24C(2);
                func_803700A4_843854(0);
                ohWait(30);
                func_801E1168_9AB3B8(1);
                sp40 = 8;
            }
            break;
        case 8:
            if (sp4C->unk_18 & 0xC000) {
                if (sp4C->unk_18 & 0x8000) {
                    auPlaySound(0x42);
                    func_801E3880_9ADAD0();
                    func_801E1168_9AB3B8(0);
                    func_801E1320_9AB570(D_80208B94_9D2DE4);
                } else {
                    auPlaySound(0x43);
                    func_801E1168_9AB3B8(0);
                    func_801E0FFC_9AB24C(1);
                }
                func_80370038_8437E8(0x32, 0x25);
                func_8036FFE0_843790((sp38 * 66) + 107, (sp34 * 55) + 56);
                func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                func_803700A4_843854(1);
                sp40 = 7;
                break;
            }
            break;
    }
    ohWait(1);
    goto loop_1;
}

void func_801E37A0_9AD9F0(void) {
    UNUSED s32 pad;
    s32 sp28;

    sp28 = 1;
    D_80250120_A1A370 = D_80208B98_9D2DE8;
    D_80250124_A1A374 = func_80370600_843DB0();
    D_80208B94_9D2DE4 = 0;
    func_80370134_8438E4();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);

    while (true) {
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
