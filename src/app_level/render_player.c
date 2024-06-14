#include "common.h"

extern GObj* D_803937F0_533C00;

extern UnkEC64Arg3 D_803AAA30_54AE40[];
extern Texture** D_8039D938_53DD48[];

GObj* PlayerModel_Init(void) {
    GObj* obj;

    obj = omAddGObj(0x23, ohUpdateDefault, 9, 0x80000000);
    if (obj == 0) {
        return 0;
    }
    omLinkGObjDL(obj, renderModelTypeJFogged, 3, 0x80000000, -1);
    anim_func_80010230(obj, D_803AAA30_54AE40, D_8039D938_53DD48, 0, 28, 0, 0);
    omCreateProcess(obj, animUpdateModelTreeAnimation, 1, 1);
    D_803937F0_533C00 = obj;
    return obj;
}

void PlayerModel_SetAnimation(AnimCmd** modelAnim, AnimCmd*** matAnim, f32 startTime, f32 speed) {
    if (D_803937F0_533C00 == NULL || startTime < 0.0f || speed < 0.0f) {
        return;
    }

    if (modelAnim != NULL) {
        animSetModelTreeAnimation(D_803937F0_533C00, modelAnim, startTime);
        animSetModelAnimationSpeed(D_803937F0_533C00, speed);
    }
    if (matAnim != NULL) {
        animSetModelTreeTextureAnimation(D_803937F0_533C00, matAnim, startTime);
        animSetTextureAnimationSpeed(D_803937F0_533C00, speed);
    }
}

void PlayerModel_ChangeAnimation(AnimCmd** modelAnim, AnimCmd*** matAnim, f32 startTime) {
    if (D_803937F0_533C00 == NULL || startTime < 0.0f) {
        return;
    }

    if (modelAnim != NULL) {
        animSetModelTreeAnimation(D_803937F0_533C00, modelAnim, startTime);
    }
    if (matAnim != NULL) {
        animSetModelTreeTextureAnimation(D_803937F0_533C00, matAnim, startTime);
    }
}

void PlayerModel_SetAnimationSpeed(f32 speed) {
    if (D_803937F0_533C00 == NULL || speed < 0.0f) {
        return;
    }

    animSetModelAnimationSpeed(D_803937F0_533C00, speed);
    animSetTextureAnimationSpeed(D_803937F0_533C00, speed);
}
