#include "common.h"
#include "gallery.h"

PhotoData* D_802309B0_A4E670[4];
PhotoData* D_802309C0_A4E680[69];
PhotoData* D_80230AD4_A4E794;
UnkEmeraldCod D_80230AD8_A4E798;
s32 D_80230ADC_A4E79C; // num album photos
s32 D_80230AE0_A4E7A0;
PhotoData* D_802308C0_A4E580[60];

// get number of album photos
s32 func_801E0F50_9FEC10(void) {
    return D_80230ADC_A4E79C;
}

s32 func_801E0F6C_9FEC2C(void) {
    return D_80230AE0_A4E7A0;
}

PhotoData* func_801E0F88_9FEC48(s32 arg0) {
    return D_802309B0_A4E670[arg0];
}

PhotoData* func_801E0FAC_9FEC6C(s32 arg0) {
    if (arg0 >= 69) {
        return NULL;
    }
    return D_802309C0_A4E680[arg0];
}

PhotoData* func_801E0FE4_9FECA4(s32 arg0) {
    return D_802308C0_A4E580[arg0];
}

PhotoData* func_801E1008_9FECC8(void) {
    return D_80230AD4_A4E794;
}

void func_801E1024_9FECE4(s32 arg0, s32 arg1) {
    if (arg0 < 0) {
        return;
    }
    if (arg1 < 0) {
        D_80230AD8_A4E798.unk_00 = -1;
        D_80230AD8_A4E798.unk_01 = -1;
        D_80230AD4_A4E794 = NULL;
        return;
    }

    D_80230AD8_A4E798.unk_00 = (s8) arg0;
    D_80230AD8_A4E798.unk_01 = (s8) arg1;

    switch (arg0) {
        case 0:
            D_80230AD4_A4E794 = D_802309B0_A4E670[arg1];
            break;
        case 2:
            D_80230AD4_A4E794 = D_802309C0_A4E680[arg1];
            break;
        case 1:
            D_80230AD4_A4E794 = D_802308C0_A4E580[arg1];
            break;
        default:
            D_80230AD4_A4E794 = NULL;
            // fallthrough
    }

    if (D_80230AD4_A4E794 != NULL) {
        func_801DE2E0_9FBFA0(D_80230AD4_A4E794);
    }
}

s32 func_801E1170_9FEE30(s32 arg0, s32 arg1) {
    PhotoData* sp1C;

    sp1C = NULL;
    if (arg0 < 0 || arg0 >= 4) {
        return -1;
    }

    if (D_80230AD4_A4E794 != NULL) {
        if (arg1 != 0) {
            auPlaySound(0x5D);
        }
        if (D_802309B0_A4E670[arg0] != NULL) {
            sp1C = D_80230AD4_A4E794;
            D_80230AD4_A4E794 = D_802309B0_A4E670[arg0];
            D_802309B0_A4E670[arg0] = sp1C;
            return 1;
        } else {

            D_802309B0_A4E670[arg0] = D_80230AD4_A4E794;
            D_80230AD4_A4E794 = 0;
            D_80230AD8_A4E798.unk_01 = D_80230AD8_A4E798.unk_00 = -1;
            return 0;
        }
    } else if (D_802309B0_A4E670[arg0] != NULL) {
        if (arg1 != 0) {
            auPlaySound(0x5E);
        }
        D_80230AD4_A4E794 = D_802309B0_A4E670[arg0];
        D_802309B0_A4E670[arg0] = 0;
        D_80230AD8_A4E798.unk_01 = arg0;
        D_80230AD8_A4E798.unk_00 = 0;
        return 1;
    }

    return 0;
}

void func_801E1318_9FEFD8(void) {
    s32 sp1C = D_80230AD8_A4E798.unk_01;

    if (!D_80230AD4_A4E794) {
        auPlaySound(0x43);
        return;
    }

    auPlaySound(0x4A);

    func_801E1170_9FEE30(D_80230AD8_A4E798.unk_01, 0);
    func_801DDC50_9FB910(sp1C);
}

void func_801E1384_9FF044(void) {
    s32 i;
    s32 count;

    for (i = 0; i < ARRAY_COUNT(D_802309B0_A4E670); i++) {
        // TODO: figure out what is returned and remove cast
        D_802309B0_A4E670[i] = (PhotoData*) func_800BF574_5C414(i);
    }

    for (count = 0, i = PokemonID_BULBASAUR; i <= POKEDEX_MAX; i++) {
        // TODO weird for this to be an if
        if (D_802309C0_A4E680[count] = func_800BF710_5C5B0(i)) {
            count++;
        }
    }

    for (i = PokemonID_1004; i <= PokemonID_1035; i++) {
        // TODO weird for this to be an if
        if (D_802309C0_A4E680[count] = func_800BF710_5C5B0(i)) {
            count++;
        }
    }

    D_80230AE0_A4E7A0 = count;

    for (i = 0, count = 0; i < 60; i++) {
        // TODO weird for this to be an if
        if (D_802308C0_A4E580[count] = getAlbumPhoto(i)) {
            count++;
        }
    }
    D_80230ADC_A4E79C = count;

    D_80230AD4_A4E794 = 0;
    D_80230AD8_A4E798.unk_00 = D_80230AD8_A4E798.unk_01 = -1;
    return;
}

s32 func_801E1504_9FF1C4(s32 arg0) {
    s32 spE9C;
    s32 spE98;
    PhotoData sp18[ARRAY_COUNT(D_802309B0_A4E670)];

    spE98 = 0;

    for (spE9C = 0; spE9C < ARRAY_COUNT(D_802309B0_A4E670); spE9C++) {
        sp18[spE9C] = *D_802309B0_A4E670[spE9C];
    }
    for (spE9C = 0; spE9C < ARRAY_COUNT(D_802309B0_A4E670); spE9C++) {
        func_800BF5D8_5C478(spE9C, &sp18[spE9C]);
    }

    if (arg0) {
        auSetBGMVolumeSmooth(0, 0, 30);
        ohWait(30);
        spE98 = func_800BF244_5C0E4();
    }

    return spE98;
}
