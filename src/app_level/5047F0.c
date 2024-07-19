#include "common.h"
#include "app_level.h"

typedef struct Unk80364494 {
    /* 0x00 */ char unk_00[0x20];
    /* 0x20 */ Vec3f unk_20;
} Unk80364494; // size >= 0x2C

extern Mtx4f D_803B14D8_5518E8;
extern Mtx4f D_803B1518_551928;

void func_803643E0_5047F0(OMCamera* cam);

s32 func_80364618_504A28(GObj* obj, f32 x, f32 y, f32 z);

void func_803643E0_5047F0(OMCamera* cam) {
    hal_perspective_fast_f(D_803B1518_551928, NULL, cam->perspMtx.persp.fovy, cam->perspMtx.persp.aspect,
                           cam->perspMtx.persp.near, cam->perspMtx.persp.far, cam->perspMtx.persp.scale);
    hal_look_at_f(D_803B14D8_5518E8, cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y, cam->viewMtx.lookAt.eye.z,
                  cam->viewMtx.lookAt.at.x, cam->viewMtx.lookAt.at.y, cam->viewMtx.lookAt.at.z,
                  cam->viewMtx.lookAt.up.x, cam->viewMtx.lookAt.up.y, cam->viewMtx.lookAt.up.z);
    guMtxCatF(D_803B14D8_5518E8, D_803B1518_551928, D_803B1518_551928);
}

s32 func_80364494_5048A4(Unk80364494* arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4) {
    f32 x, y, z;
    f32 outX, outY, outZ, outS;

    x = arg0->unk_20.x;
    y = arg0->unk_20.y;
    z = arg0->unk_20.z;

    outX = D_803B1518_551928[0][0] * x + D_803B1518_551928[1][0] * y + D_803B1518_551928[2][0] * z + D_803B1518_551928[3][0];
    outY = D_803B1518_551928[0][1] * x + D_803B1518_551928[1][1] * y + D_803B1518_551928[2][1] * z + D_803B1518_551928[3][1];
    outZ = D_803B1518_551928[0][2] * x + D_803B1518_551928[1][2] * y + D_803B1518_551928[2][2] * z + D_803B1518_551928[3][2];
    outS = D_803B1518_551928[0][3] * x + D_803B1518_551928[1][3] * y + D_803B1518_551928[2][3] * z + D_803B1518_551928[3][3];
    if (outS == 0.0f) {
        return true;
    }

    outS = 1.0f / outS;
    outX *= outS;
    outY *= outS;
    outZ *= outS;

    if (outX < -1.0f || outX > 1.0f || outY < -1.0f || outY > 1.0f || outZ < -1.0f || outZ > 1.0f) {
        return true;
    }

    *arg1 = outX;
    *arg2 = outY;
    *arg3 = outZ;
    *arg4 = outS;
    return false;
}

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
    if (outZ < -10000.0f) {
        return 1;
    }
    temp = (outX * 228.506134f) / outZ;
    if (temp < -240 || temp > 240) {
        return 1;
    }
    temp = (outY * 228.506134f) / outZ;
    if (temp < -180 || temp > 180) {
        return 1;
    }
    return 0;
}

s32 func_80364718_504B28(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    if (GET_POKEMON(obj)->flags & POKEMON_FLAG_40) {
        Pokemon_SetFlag100(obj, false);
        return 0;
    }
    if (10000.0f < GET_POKEMON(obj)->playerDist) {
        Pokemon_SetFlag100(obj, true);
        return 1;
    }
    if (func_80364618_504A28(obj, pokemon->collPosition.x, pokemon->collPosition.y, pokemon->collPosition.z) != 0) {
        Pokemon_SetFlag100(obj, true);
        return 1;
    }
    Pokemon_SetFlag100(obj, false);
    return 0;
}

s32 func_803647BC_504BCC(GObj* obj) {
    DObj* dobj;

    dobj = obj->data.dobj;
    return func_80364618_504A28(obj, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z);
}
