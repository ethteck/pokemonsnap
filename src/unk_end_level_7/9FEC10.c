#include "common.h"
#include "photo_check/photo_check.h"

// TODO: combine with UnkPinkBarracuda and PhotoData
typedef struct PhotoData {
    s32 unk_000[0x3A0 / 4];
} PhotoData; // Size: 0x3A0

void func_801DDC50_9FB910(s32);
void func_801E1170_9FEE30(s8, int);

void func_800BF5D8_5C478(s32, UnkPinkBarracuda*);

void func_801DE2E0_9FBFA0(s32 arg0);

extern s32 D_80230ADC_A4E79C;
extern s32 D_80230AE0_A4E7A0;
extern PhotoData* D_802309B0_A4E670[];
extern UNK_PTR D_802309C0_A4E680[0x45];
extern UNK_PTR D_802308C0_A4E580[];
extern UNK_PTR D_80230AD4_A4E794;

extern s8 D_80230AD8_A4E798;

extern s8 D_80230AD9_A4E799;

s32 func_801E0F50_9FEC10(void) {
    return D_80230ADC_A4E79C;
}

s32 func_801E0F6C_9FEC2C(void) {
    return D_80230AE0_A4E7A0;
}

PhotoData* func_801E0F88_9FEC48(s32 arg0) {
    return D_802309B0_A4E670[arg0];
}

s32 func_801E0FAC_9FEC6C(s32 arg0) {
    if (arg0 >= 0x45) {
        return NULL;
    }
    return D_802309C0_A4E680[arg0];
}

s32 func_801E0FE4_9FECA4(s32 arg0) {
    return D_802308C0_A4E580[arg0];
}

s32 func_801E1008_9FECC8(void) {
    return D_80230AD4_A4E794;
}

void func_801E1024_9FECE4(s32 arg0, s32 arg1) {
    if (arg0 < 0) {
        return;
    }
    if (arg1 < 0) {
        D_80230AD8_A4E798 = -1;
        D_80230AD9_A4E799 = -1;
        D_80230AD4_A4E794 = 0;
        return;
    }
    D_80230AD8_A4E798 = (s8) arg0;
    D_80230AD9_A4E799 = (s8) arg1;
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
    if (D_80230AD4_A4E794 != 0) {
        func_801DE2E0_9FBFA0(D_80230AD4_A4E794);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FEC10/func_801E1170_9FEE30.s")

void func_801E1318_9FEFD8(void) {
    s32 sp1C = D_80230AD9_A4E799;

    if (!D_80230AD4_A4E794) {
        auPlaySound(0x43U);
        return;
    }

    auPlaySound(0x4AU);

    func_801E1170_9FEE30(D_80230AD9_A4E799, 0);
    func_801DDC50_9FB910(sp1C);
}

#if defined(NONMATCHING)
void func_801E1384_9FF044(void) {
    s32 sp2C;
    s32 sp28;

    for (sp2C = 0; sp2C < 4; sp2C++) {
        D_802309B0_A4E670[sp2C] = (PhotoData*) func_800BF574_5C414(sp2C);
    }

    for (sp28 = 0, sp2C = 1; sp2C < 152; sp2C++) {
        if ((D_802309C0_A4E680[sp28] = func_800BF710_5C5B0(sp2C))) {
            sp28 += 1;
        }
    }

    for (sp2C = 1004; sp2C < 1036; sp2C++) {
        if ((D_802309C0_A4E680[sp28] = func_800BF710_5C5B0(sp2C))) {
            sp28 += 1;
        }
    }

    D_80230AE0_A4E7A0 = sp28;

    for (sp2C = 0, sp28 = 0; sp2C < 60; sp2C++) {
        if ((D_802308C0_A4E580[sp28] = func_800BFA44_5C8E4(sp2C))) {
            sp28 += 1;
        }
    }
    D_80230ADC_A4E79C = sp28;

    D_80230AD4_A4E794 = 0;
    D_80230AD8_A4E798 = -1;
    D_80230AD9_A4E799 = -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FEC10/func_801E1384_9FF044.s")
#endif

s32 func_801E1504_9FF1C4(s32 arg0) {
    s32 spE9C;
    s32 spE98;
    PhotoData sp18[4];

    spE98 = 0;

    for (spE9C = 0; spE9C < 4; spE9C++) {
        sp18[spE9C] = *D_802309B0_A4E670[spE9C];
    }
    for (spE9C = 0; spE9C < 4; spE9C++) {
        func_800BF5D8_5C478(spE9C, (UnkPinkBarracuda*) &sp18[spE9C]);
    }

    if (arg0) {
        auSetBGMVolumeSmooth(0, 0U, 0x1EU);
        ohWait(0x1E);
        spE98 = func_800BF244_5C0E4();
    }

    return spE98;
}
