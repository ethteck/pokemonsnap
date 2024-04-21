#include "common.h"

typedef struct Fizz {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Fizz;

typedef struct Bar {
    char pad0[0x20];
    float unk20;
    char pad24[4];
    f32 unk28;
    float unk2C;

    float unk30;
    char pad34[8];
    Fizz unk3C;
    Fizz unk48;

    float unk54;
    float unk58;
    float unk5C;

    char pad60[0x20];

    s32 unk80;
    int unk84;
} Bar;

typedef struct Foo {
    char pad0[0x38];
    int unk38;
    char pad3C[0xC];
    Bar* unk48;
} Foo;

extern char D_802098F0_8A70E0[0x40000];
extern s32 D_800AF3C0;
extern ScreenSettings D_801E4060_881850;
extern SceneSetup D_801E407C_88186C;
extern Addr D_8024A1E0;
extern Addr D_80369F80;

void func_801DC910_87A100(void);
void func_80375284(int);
void func_801DF938_87D128(void);
void func_80374D40(void);

void gtlSetIntervals(u16 updateInterval, u16 drawInterval);

Foo* func_8000C3FC(int, void*, int, int, void*, int, int, int, int, int, void*, int, int);
void func_800A844C(void*, int, int, int, s32);
void func_8000BC84(void);
void func_800191D8(void);
extern Fizz D_800AF0C4;
extern Fizz D_800AF094;

static void nullsub() {
}

static void nullsub2() {
}

void func_801DC8D0_87A0C0(s32 arg0) {
    while (1) {
        func_8000BCA8(1);
    }
}

void func_801DC910_87A100(void) {
    UNUSED s32 temp_t3;
    Bar* temp_a0;
    Foo* temp_v0;

    temp_v0 = func_8000C3FC(0x200, func_8000BC84, 5, 5, func_800191D8, 0x14, 0x100000, 0x100000, 1, 0,
                            func_801DC8D0_87A0C0, 0, 1);
    temp_a0 = temp_v0->unk48;
    temp_v0->unk38 = 0x100000;
    temp_a0->unk80 |= 6;
    temp_a0->unk80 &= ~3;
    func_800A844C(temp_a0, 0, 0, 640, 480);
    temp_a0->unk54 = 0.0f;
    temp_a0->unk58 = 0.0f;
    temp_a0->unk5C = 1.0f;
    temp_a0->unk48 = D_800AF0C4;
    temp_a0->unk3C = D_800AF094;
    temp_a0->unk84 = 0x7101;
    temp_a0->unk30 = 1.0f;
    temp_a0->unk2C = 8000.0f;
    temp_a0->unk20 = 33.0f;
    temp_a0->unk28 = temp_a0->unk2C / 128.0;
}

void func_801DCA60_87A250(void) {
    func_8036A3F8((s32*) D_802098F0_8A70E0, 0x40000);
    func_800AAE28();
    func_801DC910_87A100();
    func_80374D40();
    func_8036EB98();
    func_80375284(3);
    func_80375284(2);
    func_80022454(0, 0x7F00);
    func_801DF938_87D128();
}

s32 func_801DCACC_87A2BC(s32 arg0) {
    gtlDisableNearClipping(1);
    gtlSetIntervals(1, 2);
    viApplyScreenSettings(&D_801E4060_881850);
    D_801E407C_88186C.gtlSetup.heapSize = D_80369F80 - D_8024A1E0;
    omSetupScene(&D_801E407C_88186C);
    return D_800AF3C0;
}
