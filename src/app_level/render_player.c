#include "common.h"

extern UnkEC64Arg3 D_803AAA30_54AE40[];
extern Texture** D_8039D938_53DD48[];

GObj* PlayerModel_Init(void) {
    GObj* obj;

    obj = omAddGObj(OBJID_35, ohUpdateDefault, LINK_PLAYER, 0x80000000);
    if (obj == NULL) {
        return NULL;
    }
    omLinkGObjDL(obj, renderModelTypeJFogged, DL_LINK_3, 0x80000000, -1);
    anim_func_80010230(obj, D_803AAA30_54AE40, D_8039D938_53DD48, 0, 28, 0, 0);
    omCreateProcess(obj, animUpdateModelTreeAnimation, 1, 1);
    cartGObj = obj;
    return obj;
}

void PlayerModel_SetAnimation(AnimCmd** modelAnim, AnimCmd*** matAnim, f32 startTime, f32 speed) {
    if (cartGObj == NULL || startTime < 0.0f || speed < 0.0f) {
        return;
    }

    if (modelAnim != NULL) {
        animSetModelTreeAnimation(cartGObj, modelAnim, startTime);
        animSetModelAnimationSpeed(cartGObj, speed);
    }
    if (matAnim != NULL) {
        animSetModelTreeTextureAnimation(cartGObj, matAnim, startTime);
        animSetTextureAnimationSpeed(cartGObj, speed);
    }
}

void PlayerModel_ChangeAnimation(AnimCmd** modelAnim, AnimCmd*** matAnim, f32 startTime) {
    if (cartGObj == NULL || startTime < 0.0f) {
        return;
    }

    if (modelAnim != NULL) {
        animSetModelTreeAnimation(cartGObj, modelAnim, startTime);
    }
    if (matAnim != NULL) {
        animSetModelTreeTextureAnimation(cartGObj, matAnim, startTime);
    }
}

void PlayerModel_SetAnimationSpeed(f32 speed) {
    if (cartGObj == NULL || speed < 0.0f) {
        return;
    }

    animSetModelAnimationSpeed(cartGObj, speed);
    animSetTextureAnimationSpeed(cartGObj, speed);
}
