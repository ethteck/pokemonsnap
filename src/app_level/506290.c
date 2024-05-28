#include "common.h"

extern GObj* D_803937F0_533C00;

extern UnkEC64Arg3 D_803AAA30_54AE40[];
extern Texture** D_8039D938_53DD48[];

GObj* func_80365E80_506290(void) {
    GObj* temp_v0;

    temp_v0 = omAddGObj(0x23, ohUpdateDefault, 9, 0x80000000);
    if (temp_v0 == 0) {
        return 0;
    }
    omLinkGObjDL(temp_v0, renderModelTypeJFogged, 3, 0x80000000, -1);
    anim_func_80010230(temp_v0, D_803AAA30_54AE40, D_8039D938_53DD48, 0, 0x1C, 0, 0);
    omCreateProcess(temp_v0, animUpdateModelTreeAnimation, 1, 1);
    D_803937F0_533C00 = temp_v0;
    return temp_v0;
}

void func_80365F38_506348(AnimCmd** arg0, AnimCmd*** arg1, f32 arg2, f32 arg3) {
    if (D_803937F0_533C00 == NULL || arg2 < 0.0f || arg3 < 0.0f) {
        return;
    }

    if (arg0 != NULL) {
        animSetModelTreeAnimation(D_803937F0_533C00, arg0, arg2);
        animSetModelAnimationSpeed(D_803937F0_533C00, arg3);
    }
    if (arg1 != NULL) {
        animSetModelTreeTextureAnimation(D_803937F0_533C00, arg1, arg2);
        animSetTextureAnimationSpeed(D_803937F0_533C00, arg3);
    }
}

void func_80365FEC_5063FC(AnimCmd** arg0, AnimCmd*** arg1, f32 arg2) {
    if (D_803937F0_533C00 == NULL || arg2 < 0.0f) {
        return;
    }

    if (arg0 != NULL) {
        animSetModelTreeAnimation(D_803937F0_533C00, arg0, arg2);
    }
    if (arg1 != NULL) {
        animSetModelTreeTextureAnimation(D_803937F0_533C00, arg1, arg2);
    }
}

void func_80366070_506480(f32 arg3) {
    if (D_803937F0_533C00 == NULL || arg3 < 0.0f) {
        return;
    }

    animSetModelAnimationSpeed(D_803937F0_533C00, arg3);
    animSetTextureAnimationSpeed(D_803937F0_533C00, arg3);
}
