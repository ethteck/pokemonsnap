#include "common.h"

extern char D_camera_check_802098F0[0x40000];
extern s32 D_800AF3C0;
extern ScreenSettings D_camera_check_801E4060;
extern SceneSetup D_camera_check_801E407C;
extern Addr D_8024A1E0;
extern Addr D_80369F80;

void func_camera_check_801DC910(void);
void func_80375284(int);
void func_camera_check_801DF938(void);
void func_80374D40(void);

void gtlSetIntervals(u16 updateInterval, u16 drawInterval);

extern UnkCharcoalBurbot D_800AF0C4;
extern UnkCharcoalBurbot D_800AF094;

static void nullsub() {
}

static void nullsub2() {
}

void func_camera_check_801DC8D0(s32 arg0) {
    while (1) {
        func_8000BCA8(1);
    }
}

void func_camera_check_801DC910(void) {
    UNUSED s32 temp_t3;
    UnkDesertMackerel* temp_a0;
    UnkAmberCod* temp_v0;

    temp_v0 = func_8000C3FC(0x200, func_8000BC84, 5, 5, func_800191D8, 0x14, 0x100000, 0x100000, 1, 0,
                            func_camera_check_801DC8D0, 0, 1);
    temp_a0 = temp_v0->unk_48;
    temp_v0->unk_38 = 0x100000;
    temp_a0->unk_80 |= 6;
    temp_a0->unk_80 &= ~3;
    func_800A844C(temp_a0, 0, 0, 640, 480);
    temp_a0->unk_54 = 0.0f;
    temp_a0->unk_58 = 0.0f;
    temp_a0->unk_5C = 1.0f;
    temp_a0->unk_48 = D_800AF0C4;
    temp_a0->unk_3C = D_800AF094;
    temp_a0->unk_84 = 0x7101;
    temp_a0->unk_30 = 1.0f;
    temp_a0->unk_2C = 8000.0f;
    temp_a0->unk_20 = 33.0f;
    temp_a0->unk_28 = temp_a0->unk_2C / 128.0;
}

void func_camera_check_801DCA60(void) {
    func_8036A3F8((s32*) D_camera_check_802098F0, 0x40000);
    func_800AAE28();
    func_camera_check_801DC910();
    func_80374D40();
    func_8036EB98();
    func_80375284(3);
    func_80375284(2);
    func_80022454(0, 0x7F00);
    func_camera_check_801DF938();
}

s32 func_camera_check_801DCACC(s32 arg0) {
    gtlDisableNearClipping(1);
    gtlSetIntervals(1, 2);
    viApplyScreenSettings(&D_camera_check_801E4060);
    D_camera_check_801E407C.gtlSetup.heapSize = D_80369F80 - D_8024A1E0;
    omSetupScene(&D_camera_check_801E407C);
    return D_800AF3C0;
}
