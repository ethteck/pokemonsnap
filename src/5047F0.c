#include "common.h"

extern f32 D_80393AC0_533ED0;
extern f32 D_80393AC4_533ED4;
extern Mtx4f D_803B14D8_5518E8;
extern Mtx4f D_803B1518_551928;
void func_803643E0_5047F0(OMCamera* cam);
s32 func_80364618_504A28(GObj* obj, f32 x, f32 y, f32 z);
s32 func_80364494_5048A4(OMCamera* cam, f32* arg1, f32* arg2, f32* arg3, f32* arg4);
extern f32 D_80393AC8_533ED8;

void func_803643E0_5047F0(OMCamera* cam) {
    hal_perspective_fast_f(D_803B1518_551928, NULL, cam->perspMtx.persp.fovy, cam->perspMtx.persp.aspect,
                           cam->perspMtx.persp.near, cam->perspMtx.persp.far, cam->perspMtx.persp.scale);
    hal_look_at_f(D_803B14D8_5518E8, cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y, cam->viewMtx.lookAt.eye.z,
                  cam->viewMtx.lookAt.at.x, cam->viewMtx.lookAt.at.y, cam->viewMtx.lookAt.at.z,
                  cam->viewMtx.lookAt.up.x, cam->viewMtx.lookAt.up.y, cam->viewMtx.lookAt.up.z);
    guMtxCatF(D_803B14D8_5518E8, D_803B1518_551928, D_803B1518_551928);
}

#pragma GLOBAL_ASM("asm/nonmatchings/5047F0/func_80364494_5048A4.s")

s32 func_80364618_504A28(GObj* obj, f32 x, f32 y, f32 z) {
    f32 outX;
    f32 outY;
    f32 outZ;
    s32 temp;
    s32 var_v0;

    guMtxXFMF(D_803B14D8_5518E8, x, y, z, &outX, &outY, &outZ);
    if (outZ > -1.0f) {
        return 1;
    }
    if (outZ < D_80393AC0_533ED0) {
        return 1;
    }
    temp = (outX * D_80393AC4_533ED4) / outZ;
    if (temp < -240 || temp > 240) {
        return 1;
    }
    temp = (outY * D_80393AC4_533ED4) / outZ;
    if (temp < -180 || temp > 180) {
        return 1;
    }
    return 0;
}

s32 func_80364718_504B28(GObj* obj) {
    Animal* animal = GET_ANIMAL(obj);
    if (GET_ANIMAL(obj)->flags & 0x40) {
        func_8035FEEC_5002FC(obj, 0);
        return 0;
    }
    if (D_80393AC8_533ED8 < GET_ANIMAL(obj)->playerDist) {
        func_8035FEEC_5002FC(obj, 1);
        return 1;
    }
    if (func_80364618_504A28(obj, animal->collPosition.x, animal->collPosition.y, animal->collPosition.z) != 0) {
        func_8035FEEC_5002FC(obj, 1);
        return 1;
    }
    func_8035FEEC_5002FC(obj, 0);
    return 0;
}

void func_803647BC_504BCC(GObj* obj) {
    DObj* dobj;

    dobj = obj->data.dobj;
    func_80364618_504A28(obj, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z);
}
