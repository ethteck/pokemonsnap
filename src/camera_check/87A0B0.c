#include "common.h"
#include "camera_check.h"
#include "../sys/gtl.h"

extern Addr D_8024A1E0;
extern Addr D_80369F80;

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
    func_8036A3F8(D_camera_check_802098F0, sizeof(D_camera_check_802098F0));
    func_800AAE28();
    func_camera_check_801DC910();
    func_80374D40_8484F0();
    func_8036EB98();
    func_80375284_848A34(3);
    func_80375284_848A34(2);
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
