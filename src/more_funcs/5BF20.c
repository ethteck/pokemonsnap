#include "common.h"
#include "more_funcs.h"

typedef struct Unk800E1510 {
    PhotoData* unk_0;
    u32 unk_04_23 : 1;
    u32 unk_04_22 : 1;
    u32 unk_04_21 : 1;
    u32 unk_04_31 : 8;
    u32 unk_04_20 : 21;
} Unk800E1510;

extern char D_800C20E0_5EF80[16]; // HAL_SNAP_V1.0-1 in EUC-JP encoding
extern s32 D_800C20F0_5EF90;      // s32 D_800C20F0_5EF90 = 0;
extern u32 D_800C20F4_5EF94;
extern UnkBigBoy* D_800C21B0_5F050;
extern UnkBigBoy* D_800C21B8_5F058[]; // Likely wrong type, but so far it's only being used in one place and it works for now.
extern u8 D_800E14FC_7E39C[4];
extern s32 D_800E1500_7E3A0;
extern s32 D_800E1504_7E3A4;
extern s32 D_800E1508_7E3A8;
extern Unk800E1510 D_800E1510_7E3B0[];

UnkBigBoy* func_800BF080_5BF20(void) {
    return D_800C21B0_5F050;
}

s32 func_800BF08C_5BF2C(void) {
    UnkBigBoy* temp_v0 = func_800C16EC_5E58C(&D_800C21B0_5F050->data, sizeof(D_800C21B0_5F050->data));

    if (temp_v0->unk_0 != D_800C21B0_5F050->unk_0 || temp_v0->unk_4 != D_800C21B0_5F050->unk_4 ||
        temp_v0->unk_8 != D_800C21B0_5F050->unk_8 || temp_v0->unk_C != D_800C21B0_5F050->unk_C) {
        return 1;
    } else {
        return 0;
    }
}

void func_800BF10C_5BFAC(void) {
    UnkBigBoy* temp_v0 = func_800C16EC_5E58C(&D_800C21B0_5F050->data, sizeof(D_800C21B0_5F050->data));

    D_800C21B0_5F050->unk_0 = temp_v0->unk_0;
    D_800C21B0_5F050->unk_4 = temp_v0->unk_4;
    D_800C21B0_5F050->unk_8 = temp_v0->unk_8;
    D_800C21B0_5F050->unk_C = temp_v0->unk_C;
}

s32 func_800BF178_5C018(void) {
    s32 i;
    u8* versionStringBytes;
    u8* comparisonStringBytes;

    versionStringBytes = D_800C20E0_5EF80;
    comparisonStringBytes = D_800C21B0_5F050->data.unk_10;
    i = 0;
    while (true) {
        if (*versionStringBytes != *comparisonStringBytes) {
            return true;
        }
        versionStringBytes++;
        comparisonStringBytes++;
        i++;
        if (i == sizeof(D_800C20E0_5EF80)) {
            if (func_800BF08C_5BF2C() != 0) {
                return true;
            }
            return false;
        }
    }
}

void func_800BF1F0_5C090(void) {
    s32 i;
    u8* versionStringBytes;
    u8* copyToBytes;

    versionStringBytes = D_800C20E0_5EF80;
    copyToBytes = D_800C21B0_5F050->data.unk_10;
    for (i = 0; i < sizeof(D_800C20E0_5EF80); i++) {
        *copyToBytes = *versionStringBytes;
        versionStringBytes++;
        copyToBytes++;
    }
}

s32 func_800BF244_5C0E4(void) {
    UnkBigBoy* sp24;

    if (contIsPrinterAvailable()) {
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
        contPrinterSendCommand(0xCC);
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
    }
    sp24 = D_800C21B0_5F050;
    D_800C21B0_5F050->data.unk_30 = osGetTime();
    func_800BF10C_5BFAC();
    if (func_800C09C0_5D860(sp24, 0x1F2A4) != 0) {
        return 1;
    }
    if (contIsPrinterAvailable()) {
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
        contPrinterSendCommand(0x33);
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
    }
    return 0;
}

void func_800BF37C_5C21C(void) {
    UnkBigBoy* arg0 = D_800C21B0_5F050;
    func_800C06A8_5D548(arg0, sizeof(UnkBigBoy));
}

void func_800BF3A8_5C248(void) {
    UnkBigBoy* arg0 = D_800C21B0_5F050;
    func_800C0AB4_5D954(arg0, sizeof(UnkBigBoy));
}

bool func_800BF3D4_5C274(s32 pkmnID) {
    s32 photoIdx;
    PhotoData* photoData;

    photoIdx = func_8009BB4C(pkmnID);
    if (photoIdx < 0 || (photoIdx >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_180))) {
        return false;
    }
    photoData = (D_800C21B0_5F050->data.unk_180[photoIdx].unk_04.s32 == -1) ? NULL : &D_800C21B0_5F050->data.unk_180[photoIdx];
    return photoData != NULL;
}

void func_800BF444_5C2E4(s32 arg0) {
}

void func_800BF44C_5C2EC(PlayerName* arg0) {
    D_800C21B0_5F050->data.playerName = *arg0;
}

char* get_player_name(void) {
    return D_800C21B0_5F050->data.playerName.data;
}

void func_800BF4A8_5C348(UnkFuzzyCaterpillar* arg0, s32 arg1) {
    if (arg1 < 0 || arg1 >= ARRAY_COUNT(D_800C21B0_5F050->data.var_10A20)) {
        return;
    }

    D_800C21B0_5F050->data.var_10A20[arg1].unk_3A0 = *arg0;
}

UnkFuzzyCaterpillar* func_800BF534_5C3D4(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_800C21B0_5F050->data.var_10A20)) {
        return NULL;
    }

    return &D_800C21B0_5F050->data.var_10A20[arg0].unk_3A0;
}

PhotoData* func_800BF574_5C414(s32 arg0) {
    PhotoData* ret;

    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_FBA0)) {
        return NULL;
    }

    if (D_800C21B0_5F050->data.unk_FBA0[arg0].unk_04.s32 == -1) {
        ret = NULL;
    } else {
        ret = &D_800C21B0_5F050->data.unk_FBA0[arg0];
    }

    return ret;
}

void func_800BF5D8_5C478(s32 arg0, PhotoData* arg1) {
    if (arg0 < 0 || arg0 >= 4) {
        return;
    }

    if (arg1 == NULL) {
        return;
    }

    D_800C21B0_5F050->data.unk_FBA0[arg0] = *arg1;
}

void func_800BF650_5C4F0(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_FBA0)) {
        return;
    }

    D_800C21B0_5F050->data.unk_FBA0[arg0].unk_04.s32 = -1;
}

void func_800BF690_5C530(s32 arg0, PhotoData* arg1) {
    s32 temp_v0 = func_8009BB4C(arg0);
    if (temp_v0 < 0 || temp_v0 >= 0x45) {
        return;
    }

    D_800C21B0_5F050->data.unk_180[temp_v0] = *arg1;
}

PhotoData* func_800BF710_5C5B0(s32 arg0) {
    s32 index;
    PhotoData* ret;

    index = func_8009BB4C(arg0);
    if ((index < 0) || (index >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_180))) {
        return NULL;
    }

    if (D_800C21B0_5F050->data.unk_180[index].unk_04.s32 == -1) {
        ret = NULL;
    } else {
        ret = &D_800C21B0_5F050->data.unk_180[index];
    }
    return ret;
}

void func_800BF780_5C620(s32 arg0) {
    s32 temp_v0 = func_8009BB4C(arg0);

    if (temp_v0 < 0 || temp_v0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_180)) {
        return;
    }

    D_800C21B0_5F050->data.unk_180[temp_v0].unk_04.s32 = -1;
}

void func_800BF7D4_5C674(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8009BB4C(arg0);
    if (temp_v0 >= 0 && temp_v0 < ARRAY_COUNT(D_800C21B0_5F050->data.unk_6C)) {
        D_800C21B0_5F050->data.unk_6C[temp_v0] = arg1;
    }
}

s32 func_800BF818_5C6B8(s32 arg0) {
    arg0 = func_8009BB4C(arg0);

    if (arg0 < 0 || arg0 >= 69) {
        return 0;
    }

    return D_800C21B0_5F050->data.unk_6C[arg0];
}

s32 func_800BF864_5C704(void) {
    s32 i;
    s32 ret = 0;

    for (i = PokemonID_BULBASAUR; i <= POKEDEX_MAX; i++) {
        if (func_800BF3D4_5C274(i)) {
            ret++;
        }
    }

    return ret;
}

PhotoData* func_800BF8BC_5C75C(s32 arg0) {
    s32 i;
    PhotoData* sp28;

    sp28 = NULL;
    for (i = PokemonID_BULBASAUR; i <= POKEDEX_MAX; i++) {
        if (!func_800BF3D4_5C274(i))
            continue;
        if (arg0--) {
            continue;
        }

        sp28 = D_800C21B0_5F050->data.unk_180 + func_8009BB4C(i);
        break;
    }

    return sp28;
}

void func_800BF954_5C7F4(s32 arg0, PhotoData* photoData, UnkFuzzyCaterpillar* arg2) {
    if (arg0 < 0 || arg0 >= 60) {
        return;
    }

    if (photoData != NULL) {
        D_800C21B0_5F050->data.var_10A20[arg0].photoData = *photoData;
    }
    if (arg2 != 0) {
        func_800BF4A8_5C348(arg2, arg0);
    }
}

s32 func_800BF9EC_5C88C(void) {
    return 60;
}

void func_800BF9F4_5C894(s32 arg0) {

    if (arg0 < 0 || arg0 >= 60) {
        return;
    }

    D_800C21B0_5F050->data.var_10A20[arg0].photoData.unk_04.s32 = -1;
    D_800C21B0_5F050->data.var_10A20[arg0].unk_3A0.data.s[0] = 0;
}

PhotoData* func_800BFA44_5C8E4(s32 arg0) {
    PhotoData* ret;
    if (arg0 < 0 || arg0 >= 60) {
        return NULL;
    }

    if (D_800C21B0_5F050->data.var_10A20[arg0].photoData.unk_04.s32 == -1) {
        ret = NULL;
    } else {
        ret = &D_800C21B0_5F050->data.var_10A20[arg0].photoData;
    }

    if (ret) {
        return &D_800C21B0_5F050->data.var_10A20[arg0].photoData;
    }

    return NULL;
}

void func_800BFABC_5C95C(PhotoData* arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk800E1510* temp_v1;

    if (arg0 == NULL) {
        D_800C20F0_5EF90 = 0;
        return;
    }
    if (D_800C20F0_5EF90 >= 0x3C) {
        return;
    }

    D_800E1510_7E3B0[D_800C20F0_5EF90].unk_0 = arg0;
    D_800E1510_7E3B0[D_800C20F0_5EF90].unk_04_23 = (arg1 != 0);
    D_800E1510_7E3B0[D_800C20F0_5EF90].unk_04_22 = (arg2 != 0);
    D_800E1510_7E3B0[D_800C20F0_5EF90].unk_04_21 = (arg3 != 0);

    D_800C20F0_5EF90++;
}

void* func_800BFB50_5C9F0(s32 arg0) {
    if (arg0 < 0 || arg0 >= D_800C20F0_5EF90) {
        return NULL;
    }
    return &D_800E1510_7E3B0[arg0];
}

s32 func_800BFB84_5CA24(void) {
    return D_800C20F0_5EF90;
}

void func_800BFB90_5CA30(s32 arg0, s32 arg1) {
    if (arg0 < -76) {
        arg0 = -76;
    } else if (arg0 > 24) {
        arg0 = 24;
    }
    if (arg1 < -36) {
        arg1 = -36;
    } else if (arg1 > 14) {
        arg1 = 14;
    }

    D_800C21B0_5F050->data.unk_64_22 = arg0 + 76;
    D_800C21B0_5F050->data.unk_64_16 = arg1 + 36;
}

void func_800BFC18_5CAB8(s32* arg0, s32* arg1) {
    if (arg0 != NULL) {
        *arg0 = D_800C21B0_5F050->data.unk_64_22 - 76;
    }
    if (arg1 != NULL) {
        *arg1 = D_800C21B0_5F050->data.unk_64_16 - 36;
    }
}

s32 func_800BFC5C_5CAFC(void) {
    return D_800C21B0_5F050->data.unk_64_29;
}

void func_800BFC70_5CB10(s32 arg0) {
    if (arg0 >= 0 && arg0 < 7) {
        D_800C21B0_5F050->data.unk_64_29 = arg0;
    }
}

s32 checkPlayerFlag(s32 arg0) {
    switch (arg0) {
        case PFID_HAS_APPLE:
            return D_800C21B0_5F050->data.hasApple;
        case PFID_HAS_PESTER_BALL:
            return D_800C21B0_5F050->data.hasPesterBall;
        case PFID_HAS_FLUTE:
            return D_800C21B0_5F050->data.hasFlute;
        case PFID_3:
            return D_800C21B0_5F050->data.unk_64_12;
        case PFID_4:
            return D_800C21B0_5F050->data.unk_64_11;
        case PFID_HAS_DASH_ENGINE:
            return D_800C21B0_5F050->data.hasDashEngine;
        case PFID_6:
            return D_800C21B0_5F050->data.unk_64_09;
        case PFID_7:
            return D_800C21B0_5F050->data.unk_64_08;
        case PFID_HAS_FINISHED_TUTORIAL:
            return D_800C21B0_5F050->data.hasFinishedTutorial;
        case PFID_9:
            return D_800C21B0_5F050->data.unk_64_06;
        case PFID_10:
            return D_800C21B0_5F050->data.unk_64_05;
        case PFID_11:
            return D_800C21B0_5F050->data.unk_64_03;
        case PFID_ZOOM_SWITCH:
            return D_800C21B0_5F050->data.zoomSwitch;
        case PFID_INVERTED_Y:
            return D_800C21B0_5F050->data.invertedY;
        case PFID_14:
            return D_800C21B0_5F050->data.unk_64_00;
        case PFID_16:
            return D_800C21B0_5F050->data.unk_68_31;
        case PFID_17:
            return D_800C21B0_5F050->data.unk_68_30;
        case PFID_18:
            return D_800C21B0_5F050->data.unk_68_29;
        case PFID_19:
            return D_800C21B0_5F050->data.unk_68_28;
        case PFID_20:
            return D_800C21B0_5F050->data.unk_68_27;
        case PFID_21:
            return D_800C21B0_5F050->data.unk_64_04;
        case PFID_15:
            return D_800C20F4_5EF94;
    }

    return 0;
}

void setPlayerFlag(s32 arg0, s32 arg1) {
    switch (arg0) {
        case PFID_HAS_APPLE:
            D_800C21B0_5F050->data.hasApple = arg1 != 0;
            break;
        case PFID_HAS_PESTER_BALL:
            D_800C21B0_5F050->data.hasPesterBall = arg1 != 0;
            break;
        case PFID_HAS_FLUTE:
            D_800C21B0_5F050->data.hasFlute = arg1 != 0;
            break;
        case PFID_3:
            D_800C21B0_5F050->data.unk_64_12 = arg1 != 0;
            break;
        case PFID_4:
            D_800C21B0_5F050->data.unk_64_11 = arg1 != 0;
            break;
        case PFID_HAS_DASH_ENGINE:
            D_800C21B0_5F050->data.hasDashEngine = arg1 != 0;
            break;
        case PFID_6:
            D_800C21B0_5F050->data.unk_64_09 = arg1 != 0;
            break;
        case PFID_7:
            D_800C21B0_5F050->data.unk_64_08 = arg1 != 0;
            break;
        case PFID_HAS_FINISHED_TUTORIAL:
            D_800C21B0_5F050->data.hasFinishedTutorial = arg1 != 0;
            break;
        case PFID_9:
            D_800C21B0_5F050->data.unk_64_06 = arg1 != 0;
            break;
        case PFID_10:
            D_800C21B0_5F050->data.unk_64_05 = arg1 != 0;
            break;
        case PFID_11:
            D_800C21B0_5F050->data.unk_64_03 = arg1 != 0;
            break;
        case PFID_ZOOM_SWITCH:
            D_800C21B0_5F050->data.zoomSwitch = arg1 != 0;
            break;
        case PFID_INVERTED_Y:
            D_800C21B0_5F050->data.invertedY = arg1 != 0;
            break;
        case PFID_14:
            D_800C21B0_5F050->data.unk_64_00 = arg1 != 0;
            break;
        case PFID_16:
            D_800C21B0_5F050->data.unk_68_31 = arg1 != 0;
            break;
        case PFID_17:
            D_800C21B0_5F050->data.unk_68_30 = arg1 != 0;
            break;
        case PFID_18:
            D_800C21B0_5F050->data.unk_68_29 = arg1 != 0;
            break;
        case PFID_19:
            D_800C21B0_5F050->data.unk_68_28 = arg1 != 0;
            break;
        case PFID_20:
            D_800C21B0_5F050->data.unk_68_27 = arg1 != 0;
            break;
        case PFID_21:
            D_800C21B0_5F050->data.unk_64_04 = arg1 != 0;
            break;
        case PFID_15:
            D_800C20F4_5EF94 = arg1 != 0;
            break;
    }
}

s32 func_800C0224_5D0C4(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_34)) {
        return 0;
    }
    return D_800C21B0_5F050->data.unk_34[arg0];
}

void func_800C0254_5D0F4(s32 arg0, s32 arg1) {
    if (arg0 >= 0 && arg0 < ARRAY_COUNT(D_800C21B0_5F050->data.unk_34)) {
        D_800C21B0_5F050->data.unk_34[arg0] = arg1;
    }
}

s32 func_800C027C_5D11C(void) {
    s32 prev = D_800E1500_7E3A0;

    D_800E1500_7E3A0 = 0;
    return prev;
}

s32 func_800C0290_5D130(void) {
    return D_800C21B0_5F050->data.unk_50;
}

void func_800C02A0_5D140(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 6) {
        arg0 = 6;
    }
    D_800C21B0_5F050->data.unk_50 = arg0;
    if (D_800C21B0_5F050->data.unk_64_29 < arg0) {
        D_800E1500_7E3A0 = 1;
    }
}

u8 func_800C02EC_5D18C(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 2U) {
        arg0 = 2;
    }
    return D_800E14FC_7E39C[arg0];
}

void func_800C0314_5D1B4(s32 arg0, s32 arg1) {
    s32 temp_v0;

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 2U) {
        arg0 = 2;
    }

    temp_v0 = !!arg1;
    D_800E14FC_7E39C[arg0] = temp_v0;

    switch (arg0) {
        case 0:
            if (temp_v0 && !D_800C21B0_5F050->data.hasApple) {
                D_800E1500_7E3A0 = 1;
            }
            break;
        case 1:
            if (temp_v0 && !D_800C21B0_5F050->data.hasPesterBall) {
                D_800E1500_7E3A0 = 1;
            }
            break;
        case 2:
            if (temp_v0 && !D_800C21B0_5F050->data.hasFlute) {
                D_800E1500_7E3A0 = 1;
            }
            break;
    }
}

s32 func_800C03D4_5D274(void) {
    if (D_800E1504_7E3A4 == 0) {
        return 0;
    }
    D_800E1504_7E3A4 = 0;
    return 1;
}

s32 func_800C0400_5D2A0(void) {
    if (D_800E1508_7E3A8 == 0) {
        return 0;
    }
    D_800E1508_7E3A8 = 0;
    return 1;
}

s32 func_800C042C_5D2CC(void) {
    s32 var_v1;
    u8* var_v0;

    var_v0 = (u8*) D_800C21B0_5F050;
    for (var_v1 = 0; var_v1 < sizeof(UnkBigBoy); var_v1++) {
        *(var_v0++) = 0;
    }

    for (var_v1 = 0; var_v1 < 69 + 4; var_v1++) {
        D_800C21B0_5F050->data.unk_180[var_v1].unk_04.s32 = -1;
    }

    for (var_v1 = 0; var_v1 < 60; var_v1++) {
        D_800C21B0_5F050->data.var_10A20[var_v1].photoData.unk_04.s32 = -1;
    }

    func_800BF650_5C4F0(0);
    func_800BF650_5C4F0(1);
    func_800BF650_5C4F0(2);
    func_800BF650_5C4F0(3);
    D_800E14FC_7E39C[0] = 0;
    D_800E14FC_7E39C[1] = 0;
    D_800E14FC_7E39C[2] = 0;
    D_800E1500_7E3A0 = 0;
    D_800C21B0_5F050->data.unk_64_05 = 1;
    D_800C21B0_5F050->data.unk_64_22 = 0x4C;
    D_800C21B0_5F050->data.unk_64_16 = 0x24;
    D_800C20F0_5EF90 = 0;
    D_800C20F4_5EF94 = 0;
    D_800C21B0_5F050->data.unk_20 = (uintptr_t) D_800C21B0_5F050->data.unk_6C - (uintptr_t) D_800C21B0_5F050;
    D_800C21B0_5F050->data.unk_24 = (uintptr_t) D_800C21B0_5F050->data.unk_180 - (uintptr_t) D_800C21B0_5F050;
    D_800C21B0_5F050->data.unk_28 = (uintptr_t) D_800C21B0_5F050->data.unk_FBA0 - (uintptr_t) D_800C21B0_5F050;
    D_800C21B0_5F050->data.unk_2C = (uintptr_t) D_800C21B0_5F050->data.var_10A20 - (uintptr_t) D_800C21B0_5F050;
    D_800C21B0_5F050->data.unk_30 = osGetTime();
    func_800BF1F0_5C090();
    return 0;
}

s32 func_800C05D4_5D474(void) {
    s32 temp_v0;

    // Align to a multiple of 16
    D_800C21B0_5F050 = (UnkBigBoy*) ((s32) (&D_800C21B8_5F058) + 0xF & ~0xF);

    func_800C0B48_5D9E8();
    func_800BF37C_5C21C();
    temp_v0 = func_800BF178_5C018();
    if (temp_v0 != 0) {
        if (func_800C042C_5D2CC() != 0) {
            return 1;
        } else {
            D_800E1504_7E3A4 = 1;
            D_800E1508_7E3A8 = 1;
        }
        return 1;
    } else {
        D_800E1504_7E3A4 = 0;
        D_800E1508_7E3A8 = 0;
    }

//! @bug This doesn't guarantee a return. In practice, the return value isn't actually checked though.
#ifdef AVOID_UB
    return 0;
#endif
}
