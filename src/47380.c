#include "common.h"
#include "ld_addrs.h"

void func_8009D21C(s32 arg0, s32* arg1);

typedef struct PhotoData {
    u8 pad[0x3A0];
} PhotoData; // Size: 0x3A0

extern s32 D_800AE27C;
extern s32 D_800AE280;
extern PhotoData D_800B0598[60]; // Size: 0xD980 - All photos taken in a level
extern u8 D_800BDF1E;
extern u8 D_800BDF1C;
extern u8 D_800BDF1D;
extern s32 D_800BDF20[3];

// rodata
extern s32 D_800AC0F0;
extern char* D_800AE284; // Pokedex entries
extern s8 D_800AE4E4[];
// s8 D_800AE4E4[] = {
//     0,  -1, -1, 1,  2,  3,  4,  -1, -1, -1, 5,  6,  -1, 7,  -1, 8,  -1, -1, -1, -1, -1, -1, -1, -1, 9,  -1,
//     10, 11, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, 13, -1, 14, -1, -1, -1, 15, -1, -1, -1, -1, 16, 17, 18,
//     -1, 19, -1, 20, -1, 21, 22, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, 25, -1, -1, 26, 27, -1, -1, 28,
//     29, 30, 31, 32, -1, 33, -1, -1, -1, 34, 35, 36, 37, -1, 38, -1, -1, -1, -1, -1, -1, -1, 39, -1, -1, -1,
//     -1, -1, -1, -1, 40, -1, -1, -1, 41, -1, 42, -1, -1, 43, -1, 44, 45, -1, 46, 47, 48, 49, -1, -1, 50, 51,
//     52, 53, 54, -1, -1, -1, 55, -1, -1, -1, -1, -1, 56, 57, 58, 59, 60, -1, 61, -1, 62, 0,  0,  0,  0,  0,
// };
extern char D_800AFE80[4];  // = "？";
extern char D_800AFE84[16]; // = "Ｓｉｇｎ？";
extern char D_800AFE90[13]; // = "Ｓｉｇｎ";
extern char D_800AFE9C[4];  // = "Ｓｉｇｎ？";

#ifdef RODATA_MIGRATED
char* getPokemonName(s32 pkmnID) {
    if (pkmnID > 0 && pkmnID <= AnimalID_MAX) {
        return (&D_800AE284)[pkmnID];
    }
    if (pkmnID == 0x3EC || pkmnID == 0x3F2 || pkmnID == 0x3FA || pkmnID == 0x3FE || pkmnID == 0x404 ||
        pkmnID == 0x40B) {
        if (func_800BFCA0_5CB40(5) == 0) {
            return "？";
        }
    }
    if (pkmnID == 0x3EC || pkmnID == 0x3F2 || pkmnID == 0x3FA || pkmnID == 0x3FE || pkmnID == 0x404 ||
        pkmnID == 0x40B) {
        if (func_800BF3D4_5C274(pkmnID) == 0) {
            return "Ｓｉｇｎ？";
        }
    }
    switch (pkmnID) {
        case 0x25B:
            return (&D_800AE284)[AnimalID_SHELLDER];
        case 0x3EC:
        case 0x3F2:
        case 0x3FA:
        case 0x3FE:
        case 0x404:
        case 0x40B:
            return "Ｓｉｇｎ";
        case 0x1F4:
        case 0x258:
        case 0x259:
        case 0x25A:
            return "Ｓｉｇｎ？";
        default:
            return NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/47380/getPokemonName.s")
#endif


s32 func_8009BB4C(s32 pkmnID) {
    s32 ret;
    s32 temp = D_800AE4E4[150];

    if (pkmnID == 0x25B) {
        pkmnID = AnimalID_SHELLDER;
    }
    if (pkmnID > 0 && pkmnID <= AnimalID_MAX) {
        ret = D_800AE4E4[pkmnID - 1];
    } else {
        switch (pkmnID) {
            case 0x3EC:
                ret = temp + 1;
                break;
            case 0x3F2:
                ret = temp + 2;
                break;
            case 0x404:
                ret = temp + 3;
                break;
            case 0x3FE:
                ret = temp + 4;
                break;
            case 0x3FA:
                ret = temp + 5;
                break;
            case 0x40B:
                ret = temp + 6;
                break;
            default:
                ret = -1;
                break;
        }
    }
    return ret;
}

s32 func_8009BBF4(void) {
    return D_800AE27C;
}

s32 func_8009BC00(void) {
    return D_800AE280;
}

s32 func_8009BC0C(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800AE280 && i < ARRAY_COUNT(D_800BDF20); i++) {
        if (arg0 == D_800BDF20[i]) {
            return 0;
        }
    }
    return 1;
}

s32 func_8009BC68(void) {
    return gPhotoCount;
}

PhotoData* func_8009BC74(void) {
    return D_800B0598;
}

PhotoData* func_8009BC80(s32 photoIndex) {
    if (photoIndex < 0 || gPhotoCount < photoIndex) {
        return NULL;
    }
    return &D_800B0598[photoIndex];
}

typedef struct UnkFunc8009BCC4 {
    s32 unk_00_25 : 7;
    u8 unk_00_17 : 8;
    s32 unk_00_00 : 16;
    u8 pad[0x1C];
    s32 unk_20_19 : 13;
    s32 unk_20_00 : 19;
} UnkFunc8009BCC4;

s32 func_8009BCC4(UnkFunc8009BCC4* arg0) {
    s32 temp_v0;
    s32 ret;

    if (arg0->unk_00_25 < 0) {
        return -1;
    }
    switch (arg0->unk_00_17 & 0xE0) {
        default:
            ret = -1;
            break;
        case 0x60:
            ret = 0x3EC;
            break;
        case 0x80:
            ret = 0x3FA;
            break;
        case 0xA0:
            ret = 0x3FE;
            break;
        case 0xE0:
            ret = 0x40B;
            break;
        case 0x20:
            ret = arg0->unk_20_19;
            break;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BF48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C4F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C9E8.s")

// & 0xFFs and temp required to match
void func_8009CDC0(u8* arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 prev = *arg0;

        *arg0 = (arg1 & 1) & 0xFF | (prev & 0xFF & ~1);
    }
}

s32 func_8009CDE4(u8* arg0) {
    if (arg0 != NULL) {
        return *arg0 & 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009CE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009CEAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D184.s")

void func_8009D1E8(u32 arg0, s32 arg1, s32 arg2) {
    if (arg1 >= arg0) {
        dmaReadRom((void*) arg0, (void*) arg2, arg1 - arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D21C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D65C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D9A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009DEF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FA68.s")

void func_8009FB50(u8 arg0, u8 arg1, u8 arg2) {
    s32* temp_v0;

    D_800BDF1C = arg0;
    D_800BDF1D = arg1;
    D_800BDF1E = arg2;
    D_800AC0F0 = -1;
    temp_v0 = func_800A73C0((u32) AB5980_ROM_START, (u32) AB5980_ROM_END);
    if (temp_v0 != NULL) {
        func_8009D21C(3, temp_v0);
    }
}

void func_8009FBC4(void) {
    GObj* curObj;
    GObj* nextObj;

    func_800E3064();
    curObj = omGObjListHead[D_800BDF1E];
    while (curObj != NULL) {
        nextObj = curObj->next;
        omDeleteGObj(curObj);
        curObj = nextObj;
    }
    D_800AC0F0 = -1;
}

void func_8009FC2C(s32 arg0) {
    D_800AC0F0 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FC38.s")
