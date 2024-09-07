#include <sp.h>
#include "common.h"
#include "sys/om.h"
#include "sys/gtl.h"
#include "sys/vi.h"
#include "sys/mtx.h"

#define gSPMvpRecalc(pkt) gImmp21((pkt), G_SPECIAL_1, 0, 1, 0)
#define gsSPMvpRecalc() gsImmp21(G_SPECIAL_1, 0, 1, 0)
#define G_TX_TILE_5 (5)
#define G_TX_TILE_BLOCK (6)

// data
s32 renCameraScisTop = 0;
s32 renCameraScisBottom = 0;
s32 renCameraScisLeft = 0;
s32 renCameraScisRight = 0;

// bss
Mtx* renProjectionMatrix;
f32 renScaleX;
Mtx4f renPerspectiveMatrixF;
Mtx4f renMvpMatrixF;
Mtx4f ren_D_8004AFA8;
Mtx4f ren_D_8004AFE8;
s32 ren_D_8004B028;
f32 renScaleY;
f32 renScaleZ;
s32 renIsScaleMtxPushed;
Struct_8004B038* renCustomMatrixHandler;
Gfx* ren_D_8004B03C;
Gfx* ren_D_8004B040[4];
Gfx ren_D_8004B050[60];
s32 renLevelOfDetail;
Gfx* ren_D_8004B238[4];
Gfx* ren_D_8004B248;

void renSetCameraScissors(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    renCameraScisTop = arg0;
    renCameraScisBottom = arg1;
    renCameraScisLeft = arg2;
    renCameraScisRight = arg3;
}

void renSetCustomMatrixHandler(Struct_8004B038* arg0) {
    renCustomMatrixHandler = arg0;
}

void renNullsub(void) {
}

void ren_func_80011268(Mtx* arg0, DObj* arg1, s32 arg2) {
    Mtx4f sp48;
    f32 x, y, z;

    OMCamera* cam;
    f32 res;

    cam = omCurrentCamera->data.cam;
    x = arg1->position.v.x - cam->viewMtx.lookAt.eye.x;
    y = arg1->position.v.y - cam->viewMtx.lookAt.eye.y;
    z = arg1->position.v.z - cam->viewMtx.lookAt.eye.z;
    res = 1.0f / sqrtf(SQ(x) + SQ(y) + SQ(z));
    x *= res;
    y *= res;
    z *= res;

    res = sqrtf(SQ(x) + SQ(y));

    sp48[0][3] = sp48[1][3] = sp48[2][3] = sp48[1][2] = 0.0f;
    sp48[3][3] = 1.0f;

    if (res != 0.0f) {
        f32 invrt = (1.0f / res);

        sp48[0][0] = -x;
        sp48[1][0] = y * invrt;
        sp48[2][0] = -x * z * invrt;

        sp48[0][1] = -y;
        sp48[1][1] = -x * invrt;
        sp48[2][1] = -y * z * invrt;

        sp48[0][2] = -z;
        sp48[2][2] = res;
    } else {
        sp48[1][0] = sp48[2][0] = sp48[0][1] = sp48[2][1] = sp48[0][2] = 0.0f;
        sp48[0][0] = sp48[1][1] = sp48[2][2] = 1.0f;
    }

    if (arg2) {
        sp48[3][0] = arg1->position.v.x;
        sp48[3][1] = arg1->position.v.y;
        sp48[3][2] = arg1->position.v.z;
    } else {
        sp48[3][0] = sp48[3][1] = sp48[3][2] = 0.0f;
    }

    hal_mtx_f2l_fixed_w(sp48, arg0);
}

void ren_func_80011438(Mtx* arg0, DObj* arg1, s32 arg2) {
    Mtx4f sp48;
    f32 x, y, z;

    OMCamera* cam;
    f32 res;

    cam = omCurrentCamera->data.cam;
    x = arg1->position.v.x - cam->viewMtx.lookAt.eye.x;
    y = arg1->position.v.y - cam->viewMtx.lookAt.eye.y;
    z = arg1->position.v.z - cam->viewMtx.lookAt.eye.z;
    res = 1.0f / sqrtf(SQ(x) + SQ(y) + SQ(z));
    x *= res;
    y *= res;
    z *= res;

    res = sqrtf(SQ(x) + SQ(z));

    sp48[0][3] = sp48[1][3] = sp48[2][3] = sp48[0][1] = 0.0f;
    sp48[3][3] = 1.0f;

    if (res != 0.0f) {
        f32 invrt = (1.0f / res);

        sp48[0][0] = -z * invrt;
        sp48[1][0] = -y * x * invrt;
        sp48[2][0] = -x;

        sp48[1][1] = res;
        sp48[2][1] = -y;

        sp48[0][2] = x * invrt;
        sp48[1][2] = -y * z * invrt;
        sp48[2][2] = -z;
    } else {
        sp48[1][0] = sp48[2][0] = sp48[2][1] = sp48[0][2] = sp48[1][2] = 0.0f;
        sp48[0][0] = sp48[1][1] = sp48[2][2] = 1.0f;
    }

    if (arg2) {
        sp48[3][0] = arg1->position.v.x;
        sp48[3][1] = arg1->position.v.y;
        sp48[3][2] = arg1->position.v.z;
    } else {
        sp48[3][0] = sp48[3][1] = sp48[3][2] = 0.0f;
    }

    hal_mtx_f2l_fixed_w(sp48, arg0);
}

void ren_func_80011608(Mtx* arg0, DObj* arg1, s32 arg2) {
    Mtx4f sp48;
    f32 x;
    f32 y;

    OMCamera* cam;
    f32 res;

    cam = omCurrentCamera->data.cam;
    x = arg1->position.v.x - cam->viewMtx.lookAt.eye.x;
    y = arg1->position.v.y - cam->viewMtx.lookAt.eye.y;
    res = sqrtf(SQ(x) + SQ(y));

    sp48[0][3] = sp48[1][3] = sp48[2][3] = sp48[2][0] = sp48[2][1] = sp48[0][2] = sp48[1][2] = 0.0f;
    sp48[2][2] = sp48[3][3] = 1.0f;

    if (res != 0.0f) {
        f32 invrt = (1.0f / res);

        x *= invrt;
        y *= invrt;

        sp48[0][0] = -x;
        sp48[0][1] = -y;
        sp48[1][0] = y;
        sp48[1][1] = -x;
    } else {
        sp48[1][0] = sp48[0][1] = 0.0f;
        sp48[0][0] = sp48[1][1] = 1.0f;
    }

    if (arg2) {
        sp48[3][0] = arg1->position.v.x;
        sp48[3][1] = arg1->position.v.y;
        sp48[3][2] = arg1->position.v.z;
    } else {
        sp48[3][0] = sp48[3][1] = sp48[3][2] = 0;
    }

    hal_mtx_f2l_fixed_w(sp48, arg0);
}

void func_8001174C(Mtx* arg0, DObj* arg1, s32 arg2) {
    Mtx4f sp48;
    f32 x;
    f32 z;

    OMCamera* cam;
    f32 res;

    cam = omCurrentCamera->data.cam;
    x = arg1->position.v.x - cam->viewMtx.lookAt.eye.x;
    z = arg1->position.v.z - cam->viewMtx.lookAt.eye.z;
    res = sqrtf(SQ(x) + SQ(z));

    sp48[0][3] = sp48[1][3] = sp48[2][3] = sp48[1][0] = sp48[0][1] = sp48[1][2] = sp48[2][1] = 0.0f;
    sp48[1][1] = sp48[3][3] = 1.0f;

    if (res != 0.0f) {
        f32 invrt = (1.0f / res);

        x *= invrt;
        z *= invrt;

        sp48[0][2] = x;
        sp48[2][0] = -x;
        sp48[0][0] = -z;
        sp48[2][2] = -z;
    } else {
        sp48[2][0] = sp48[0][2] = 0.0f;
        sp48[0][0] = sp48[2][2] = 1.0f;
    }

    if (arg2) {
        sp48[3][0] = arg1->position.v.x;
        sp48[3][1] = arg1->position.v.y;
        sp48[3][2] = arg1->position.v.z;
    } else {
        sp48[3][0] = sp48[3][1] = sp48[3][2] = 0;
    }

    hal_mtx_f2l_fixed_w(sp48, arg0);
}

s32 renPrepareModelMatrix(Gfx** gfxPtr, DObj* dobj) {
    Gfx* sp2DC;
    uintptr_t csr;
    s32 sp2D4;
    s32 i;
    f32 f12;
    union Mtx3fi* sp2C8;
    struct Mtx4Float* sp2C4;
    struct Mtx3Float* sp2C0;
    f32 f0;
    s32 sp2B8;
    s32 (*func)(Mtx*, void*, Gfx**);

    sp2DC = *gfxPtr;
    sp2D4 = 0;

    if (dobj->unk_4C != NULL) {
        csr = (uintptr_t) dobj->unk_4C->data;
        for (i = 0; i < 3; i++) {
            switch (dobj->unk_4C->kinds[i]) {
                case 0:
                    break;
                case 1:
                    sp2C8 = (void*) csr;
                    csr += sizeof(union Mtx3fi);
                    break;
                case 2:
                    sp2C4 = (void*) csr;
                    csr += sizeof(struct Mtx4Float);
                    break;
                case 3:
                    sp2C0 = (void*) csr;
                    csr += sizeof(struct Mtx3Float);
                    break;
            }
        }
    }

    for (i = 0; i < dobj->numMatrices; i++) {
        OMMtx* ommtx = dobj->matrices[i];
        if (ommtx != NULL) {
            Mtx** unk;
            Mtx* mtx;

            unk = (Mtx**) &ommtx->unk08;
            mtx = &ommtx->unk08;

            if (ommtx->unk05 != 2) {
                if (ommtx->unk05 == 4) {
                    if (dobj->obj->lastDrawFrame != (u8) gtlDrawnFrameCounter) {
                        *unk = gtlCurrentGfxHeap.ptr;
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    } else {
                        switch (ommtx->kind) {
                            case MTX_TYPE_33:
                            case MTX_TYPE_34:
                            case MTX_TYPE_35:
                            case MTX_TYPE_36:
                            case MTX_TYPE_37:
                            case MTX_TYPE_38:
                            case MTX_TYPE_39:
                            case MTX_TYPE_40:
                            case MTX_TYPE_41:
                            case MTX_TYPE_42:
                            case MTX_TYPE_43:
                            case MTX_TYPE_44:
                            case MTX_TYPE_45:
                            case MTX_TYPE_46:
                            case MTX_TYPE_47:
                            case MTX_TYPE_48:
                            case MTX_TYPE_49:
                            case MTX_TYPE_50:
                                mtx = gtlCurrentGfxHeap.ptr;
                                gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                break;
                            default:
                                if (ommtx->kind >= MTX_TYPE_66) {
                                    mtx = gtlCurrentGfxHeap.ptr;
                                    gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                } else {
                                    mtx = *unk;
                                    goto END2;
                                }
                                break;
                        }
                    }
                } else {
                    if (gtlContextId > 0) {
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    } else if (dobj->obj->lastDrawFrame == (u8) gtlDrawnFrameCounter) {
                        switch (ommtx->kind) {
                            case MTX_TYPE_33:
                            case MTX_TYPE_34:
                            case MTX_TYPE_35:
                            case MTX_TYPE_36:
                            case MTX_TYPE_37:
                            case MTX_TYPE_38:
                            case MTX_TYPE_39:
                            case MTX_TYPE_40:
                            case MTX_TYPE_41:
                            case MTX_TYPE_42:
                            case MTX_TYPE_43:
                            case MTX_TYPE_44:
                            case MTX_TYPE_45:
                            case MTX_TYPE_46:
                            case MTX_TYPE_47:
                            case MTX_TYPE_48:
                            case MTX_TYPE_49:
                            case MTX_TYPE_50:
                                mtx = gtlCurrentGfxHeap.ptr;
                                gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                break;
                            default:
                                if (ommtx->kind >= MTX_TYPE_66) {
                                    mtx = gtlCurrentGfxHeap.ptr;
                                    gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                } else {
                                    if (ommtx->unk05 != 3) {
                                        goto END2;
                                    }
                                    mtx = gtlCurrentGfxHeap.ptr;
                                    gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                }
                                break;
                        }
                    }
                }

                sp2B8 = 0;
                switch (ommtx->kind) {
                    case MTX_TYPE_1:
                        break;
                    case MTX_TYPE_2:
                        break;
                    case MTX_TYPE_TRANSLATE:
                        hal_translate(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z);
                        break;
                    case MTX_TYPE_ROTATE_DEG:
                        hal_rotate_deg(mtx, dobj->rotation.f[0], dobj->rotation.f[1], dobj->rotation.f[2],
                                       dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_DEG_TRANSLATE:
                        hal_rotate_translate_deg(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                                 dobj->rotation.f[0], dobj->rotation.f[1], dobj->rotation.f[2],
                                                 dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_RPY_DEG:
                        hal_rotate_rpy_deg(mtx, dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_RPY_TRANSLATE_DEG:
                        hal_rotate_rpy_translate_deg(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                                     dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE:
                        hal_rotate(mtx, dobj->rotation.f[0], dobj->rotation.f[1], dobj->rotation.f[2],
                                   dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_TRANSLATE:
                        hal_rotate_translate(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                             dobj->rotation.f[0], dobj->rotation.f[1], dobj->rotation.f[2],
                                             dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_TRANSLATE_SCALE:
                        hal_rotate_translate_scale(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                                   dobj->rotation.f[0], dobj->rotation.f[1], dobj->rotation.f[2],
                                                   dobj->rotation.f[3], dobj->scale.v.x, dobj->scale.v.y,
                                                   dobj->scale.v.z);
                        renScaleX *= dobj->scale.v.x;
                        break;
                    case MTX_TYPE_ROTATE_RPY:
                        hal_rotate_rpy(mtx, dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_RPY_TRANSLATE:
                        hal_rotate_rpy_translate(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                                 dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE:
                        hal_rotate_rpy_translate_scale(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                                       dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3],
                                                       dobj->scale.v.x, dobj->scale.v.y, dobj->scale.v.z);
                        renScaleX *= dobj->scale.v.x;
                        break;
                    case MTX_TYPE_ROTATE_PYR:
                        hal_rotate_pyr(mtx, dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_PYR_TRANSLATE:
                        hal_rotate_pyr_translate(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                                 dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_ROTATE_PYR_TRANSLATE_SCALE:
                        hal_rotate_pyr_translate_scale(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                                       dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3],
                                                       dobj->scale.v.x, dobj->scale.v.y, dobj->scale.v.z);
                        renScaleX *= dobj->scale.v.x;
                        break;
                    case MTX_TYPE_SCALE:
                        hal_scale(mtx, dobj->scale.v.x, dobj->scale.v.y, dobj->scale.v.z);
                        renScaleX *= dobj->scale.v.x;
                        break;
                    case MTX_TYPE_33:
                        ren_func_80011608(mtx, dobj, false);
                        break;
                    case MTX_TYPE_34:
                        ren_func_80011608(mtx, dobj, true);
                        break;
                    case MTX_TYPE_35:
                        ren_func_80011268(mtx, dobj, false);
                        break;
                    case MTX_TYPE_36:
                        ren_func_80011268(mtx, dobj, true);
                        break;
                    case MTX_TYPE_37:
                        func_8001174C(mtx, dobj, false);
                        break;
                    case MTX_TYPE_38:
                        func_8001174C(mtx, dobj, true);
                        break;
                    case MTX_TYPE_39:
                        ren_func_80011438(mtx, dobj, false);
                        break;
                    case MTX_TYPE_40:
                        ren_func_80011438(mtx, dobj, true);
                        break;
                    case MTX_TYPE_56:
                        hal_translate(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z);
                        break;
                    case MTX_TYPE_57:
                        hal_rotate(mtx, sp2C4->f[0], sp2C4->f[1], sp2C4->f[2], sp2C4->f[3]);
                        break;
                    case MTX_TYPE_58:
                        hal_rotate_rpy(mtx, sp2C4->f[1], sp2C4->f[2], sp2C4->f[3]);
                        break;
                    case MTX_TYPE_59:
                        hal_scale(mtx, sp2C0->v.x, sp2C0->v.y, sp2C0->v.z);
                        renScaleX *= sp2C0->v.x;
                        renScaleY *= sp2C0->v.y;
                        renScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_60:
                        hal_rotate_translate(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[0], sp2C4->f[1],
                                             sp2C4->f[2], sp2C4->f[3]);
                        break;
                    case MTX_TYPE_61:
                        hal_rotate_translate_scale(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[0],
                                                   sp2C4->f[1], sp2C4->f[2], sp2C4->f[3], sp2C0->v.x, sp2C0->v.y,
                                                   sp2C0->v.z);
                        renScaleX *= sp2C0->v.x;
                        renScaleY *= sp2C0->v.y;
                        renScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_62:
                        hal_rotate_rpy_translate(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[1],
                                                 sp2C4->f[2], sp2C4->f[3]);
                        break;
                    case MTX_TYPE_63:
                        hal_rotate_rpy_translate_scale(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[1],
                                                       sp2C4->f[2], sp2C4->f[3], sp2C0->v.x, sp2C0->v.y, sp2C0->v.z);
                        renScaleX *= sp2C0->v.x;
                        renScaleY *= sp2C0->v.y;
                        renScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_41:
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, renProjectionMatrix->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, renProjectionMatrix->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, renProjectionMatrix->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, renProjectionMatrix->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, renProjectionMatrix->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, renProjectionMatrix->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, renProjectionMatrix->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, renProjectionMatrix->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, renProjectionMatrix->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, renProjectionMatrix->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, renProjectionMatrix->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, renProjectionMatrix->m[3][1]);
                        continue;
                    case MTX_TYPE_42:
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, renProjectionMatrix->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, renProjectionMatrix->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, renProjectionMatrix->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, renProjectionMatrix->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, renProjectionMatrix->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, renProjectionMatrix->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, renProjectionMatrix->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, renProjectionMatrix->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, renProjectionMatrix->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, renProjectionMatrix->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, renProjectionMatrix->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, renProjectionMatrix->m[3][1]);
                        continue;
                    case MTX_TYPE_43:
                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;
                        renMvpMatrixF[0][0] = renPerspectiveMatrixF[0][0] * renScaleX;
                        renMvpMatrixF[0][1] = 0.0f;
                        renMvpMatrixF[0][2] = 0.0f;
                        renMvpMatrixF[0][3] = 0.0f;
                        renMvpMatrixF[1][0] = 0.0f;
                        renMvpMatrixF[1][1] = renPerspectiveMatrixF[1][1] * f12;
                        renMvpMatrixF[1][2] = 0.0f;
                        renMvpMatrixF[1][3] = 0.0f;
                        renMvpMatrixF[2][0] = 0.0f;
                        renMvpMatrixF[2][1] = 0.0f;
                        renMvpMatrixF[2][2] = renPerspectiveMatrixF[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = renPerspectiveMatrixF[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[3][1]);
                        continue;
                    case MTX_TYPE_44: {
                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;
                        renMvpMatrixF[0][0] = renPerspectiveMatrixF[0][0] * renScaleX;
                        renMvpMatrixF[0][1] = 0.0f;
                        renMvpMatrixF[0][2] = 0.0f;
                        renMvpMatrixF[0][3] = 0.0f;
                        renMvpMatrixF[1][0] = 0.0f;
                        renMvpMatrixF[1][1] = renPerspectiveMatrixF[1][1] * f12;
                        renMvpMatrixF[1][2] = 0.0f;
                        renMvpMatrixF[1][3] = 0.0f;
                        renMvpMatrixF[2][0] = 0.0f;
                        renMvpMatrixF[2][1] = 0.0f;
                        renMvpMatrixF[2][2] = renPerspectiveMatrixF[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = renPerspectiveMatrixF[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[3][1]);
                        continue;
                    }
                    case MTX_TYPE_45: {
                        f32 sp1D4 = sinf(dobj->rotation.f[1]);
                        f32 f0 = cosf(dobj->rotation.f[1]);

                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;
                        renMvpMatrixF[0][0] = renPerspectiveMatrixF[0][0] * renScaleX * f0;
                        renMvpMatrixF[1][0] = renPerspectiveMatrixF[0][0] * renScaleX * -sp1D4;
                        renMvpMatrixF[0][1] = renPerspectiveMatrixF[1][1] * f12 * sp1D4;
                        renMvpMatrixF[1][1] = renPerspectiveMatrixF[1][1] * f12 * f0;
                        renMvpMatrixF[0][2] = 0.0f;
                        renMvpMatrixF[1][2] = 0.0f;
                        renMvpMatrixF[0][3] = 0.0f;
                        renMvpMatrixF[1][3] = 0.0f;
                        renMvpMatrixF[2][0] = 0.0f;
                        renMvpMatrixF[2][1] = 0.0f;
                        renMvpMatrixF[2][2] = renPerspectiveMatrixF[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = renPerspectiveMatrixF[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[3][1]);
                        continue;
                    }
                    case MTX_TYPE_46: {
                        f32 sp1D4 = sinf(dobj->rotation.f[3]);
                        f32 f0 = cosf(dobj->rotation.f[3]);

                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;

                        renMvpMatrixF[0][0] = renPerspectiveMatrixF[0][0] * renScaleX * f0;
                        renMvpMatrixF[1][0] = renPerspectiveMatrixF[0][0] * renScaleX * -sp1D4;
                        renMvpMatrixF[0][1] = renPerspectiveMatrixF[1][1] * f12 * sp1D4;
                        renMvpMatrixF[1][1] = renPerspectiveMatrixF[1][1] * f12 * f0;
                        renMvpMatrixF[0][2] = 0.0f;
                        renMvpMatrixF[1][2] = 0.0f;
                        renMvpMatrixF[0][3] = 0.0f;
                        renMvpMatrixF[1][3] = 0.0f;
                        renMvpMatrixF[2][0] = 0.0f;
                        renMvpMatrixF[2][1] = 0.0f;
                        renMvpMatrixF[2][2] = renPerspectiveMatrixF[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = renPerspectiveMatrixF[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[3][1]);
                        continue;
                    }
                    case MTX_TYPE_47: {
                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;
                        renMvpMatrixF[0][0] = ren_D_8004AFA8[0][0] * renScaleX;
                        renMvpMatrixF[0][1] = ren_D_8004AFA8[0][1] * renScaleX;
                        renMvpMatrixF[0][2] = ren_D_8004AFA8[0][2] * renScaleX;
                        renMvpMatrixF[0][3] = ren_D_8004AFA8[0][3] * renScaleX;
                        renMvpMatrixF[1][0] = ren_D_8004AFA8[1][0] * f12;
                        renMvpMatrixF[1][1] = ren_D_8004AFA8[1][1] * f12;
                        renMvpMatrixF[1][2] = ren_D_8004AFA8[1][2] * f12;
                        renMvpMatrixF[1][3] = ren_D_8004AFA8[1][3] * f12;
                        renMvpMatrixF[2][0] = ren_D_8004AFA8[2][0] * renScaleX;
                        renMvpMatrixF[2][1] = ren_D_8004AFA8[2][1] * renScaleX;
                        renMvpMatrixF[2][2] = ren_D_8004AFA8[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = ren_D_8004AFA8[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[3][1]);
                        continue;
                    }
                    case MTX_TYPE_48: {
                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;
                        renMvpMatrixF[0][0] = ren_D_8004AFA8[0][0] * renScaleX;
                        renMvpMatrixF[0][1] = ren_D_8004AFA8[0][1] * renScaleX;
                        renMvpMatrixF[0][2] = ren_D_8004AFA8[0][2] * renScaleX;
                        renMvpMatrixF[0][3] = ren_D_8004AFA8[0][3] * renScaleX;
                        renMvpMatrixF[1][0] = ren_D_8004AFA8[1][0] * f12;
                        renMvpMatrixF[1][1] = ren_D_8004AFA8[1][1] * f12;
                        renMvpMatrixF[1][2] = ren_D_8004AFA8[1][2] * f12;
                        renMvpMatrixF[1][3] = ren_D_8004AFA8[1][3] * f12;
                        renMvpMatrixF[2][0] = ren_D_8004AFA8[2][0] * renScaleX;
                        renMvpMatrixF[2][1] = ren_D_8004AFA8[2][1] * renScaleX;
                        renMvpMatrixF[2][2] = ren_D_8004AFA8[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = ren_D_8004AFA8[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[3][1]);
                        continue;
                    }
                    case MTX_TYPE_49: {
                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;
                        renMvpMatrixF[0][0] = ren_D_8004AFE8[0][0] * renScaleX;
                        renMvpMatrixF[0][1] = ren_D_8004AFE8[0][1] * renScaleX;
                        renMvpMatrixF[0][2] = ren_D_8004AFE8[0][2] * renScaleX;
                        renMvpMatrixF[0][3] = ren_D_8004AFE8[0][3] * renScaleX;
                        renMvpMatrixF[1][0] = ren_D_8004AFE8[1][0] * f12;
                        renMvpMatrixF[1][1] = ren_D_8004AFE8[1][1] * f12;
                        renMvpMatrixF[1][2] = ren_D_8004AFE8[1][2] * f12;
                        renMvpMatrixF[1][3] = ren_D_8004AFE8[1][3] * f12;
                        renMvpMatrixF[2][0] = ren_D_8004AFE8[2][0] * renScaleX;
                        renMvpMatrixF[2][1] = ren_D_8004AFE8[2][1] * renScaleX;
                        renMvpMatrixF[2][2] = ren_D_8004AFE8[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = ren_D_8004AFE8[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[3][1]);
                        continue;
                    }
                    case MTX_TYPE_50:
                        f12 = dobj->scale.v.y * renScaleX;
                        renScaleX *= dobj->scale.v.x;
                        renMvpMatrixF[0][0] = ren_D_8004AFE8[0][0] * renScaleX;
                        renMvpMatrixF[0][1] = ren_D_8004AFE8[0][1] * renScaleX;
                        renMvpMatrixF[0][2] = ren_D_8004AFE8[0][2] * renScaleX;
                        renMvpMatrixF[0][3] = ren_D_8004AFE8[0][3] * renScaleX;
                        renMvpMatrixF[1][0] = ren_D_8004AFE8[1][0] * f12;
                        renMvpMatrixF[1][1] = ren_D_8004AFE8[1][1] * f12;
                        renMvpMatrixF[1][2] = ren_D_8004AFE8[1][2] * f12;
                        renMvpMatrixF[1][3] = ren_D_8004AFE8[1][3] * f12;
                        renMvpMatrixF[2][0] = ren_D_8004AFE8[2][0] * renScaleX;
                        renMvpMatrixF[2][1] = ren_D_8004AFE8[2][1] * renScaleX;
                        renMvpMatrixF[2][2] = ren_D_8004AFE8[2][2] * renScaleX;
                        renMvpMatrixF[2][3] = ren_D_8004AFE8[2][3] * renScaleX;
                        hal_mtx_f2l(renMvpMatrixF, mtx);
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, mtx->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, mtx->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, mtx->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, mtx->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, mtx->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, mtx->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, mtx->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, mtx->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, mtx->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, mtx->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, mtx->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, mtx->m[3][1]);
                        continue;
                    case MTX_TYPE_51:
                        hal_rotate_rpy_translate(mtx, dobj->position.v.x * renScaleX, dobj->position.v.y * renScaleY,
                                                 dobj->position.v.z * renScaleZ, dobj->rotation.f[1], dobj->rotation.f[2],
                                                 dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_52:
                        hal_rotate_pyr_translate(mtx, dobj->position.v.x * renScaleX, dobj->position.v.y * renScaleY,
                                                 dobj->position.v.z * renScaleZ, dobj->rotation.f[1], dobj->rotation.f[2],
                                                 dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_53:
                        renScaleX *= dobj->scale.v.x;
                        renScaleY *= dobj->scale.v.y;
                        renScaleZ *= dobj->scale.v.z;
                        hal_scale(mtx, renScaleX, renScaleY, renScaleZ);
                        renIsScaleMtxPushed = true;
                        sp2B8 = 2;
                        break;
                    case MTX_TYPE_55:
                        hal_translate(mtx, dobj->position.v.x * renScaleX, dobj->position.v.y * renScaleY,
                                      dobj->position.v.z * renScaleZ);
                        break;
                    case MTX_TYPE_64:
                        renScaleX *= sp2C0->v.x;
                        renScaleY *= sp2C0->v.y;
                        renScaleZ *= sp2C0->v.z;
                        continue;
                    case MTX_TYPE_65:
                        hal_rotate_translate(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[0], sp2C4->f[1],
                                             sp2C4->f[2], sp2C4->f[3]);
                        renScaleX *= sp2C0->v.x;
                        renScaleY *= sp2C0->v.y;
                        renScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_54:
                        func_8001ECD0(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                      dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3], renScaleX, renScaleY,
                                      renScaleZ, dobj->scale.v.x, dobj->scale.v.y, dobj->scale.v.z);
                        renScaleX *= dobj->scale.v.x;
                        renScaleY *= dobj->scale.v.y;
                        renScaleZ *= dobj->scale.v.z;
                        break;
                    default:
                        if (ommtx->kind >= MTX_TYPE_66 && renCustomMatrixHandler != NULL) {
                            func = dobj->obj->lastDrawFrame != (u8) gtlDrawnFrameCounter
                                       ? renCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_00
                                       : renCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_04;
                            sp2B8 = func(mtx, dobj, &sp2DC);
                        }
                        if (sp2B8 == 1) {
                            continue;
                        }
                        break;
                }
            END2:
                if (ommtx->unk05 == 1 && &ommtx->unk08 == mtx) {
                    ommtx->unk05 = 2;
                }
            }
            if (ommtx->kind != MTX_TYPE_2) {
                if (sp2B8 == 2 || sp2D4 == 0 && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                    gSPMatrix(sp2DC++, mtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                } else {
                    gSPMatrix(sp2DC++, mtx, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
                }
                sp2D4++;
            }
        }
    }

    *gfxPtr = sp2DC;
    return sp2D4;
}

s32 ren_func_80013C5C(Gfx** gfxPtr, DObj* dobj) {
    Gfx* gfxPos = *gfxPtr;
    s32 i;
    s32 mtxCount = 0;

    for (i = 0; i < dobj->numMatrices; i++) {
        OMMtx* ommtx = dobj->matrices[i];
        if (ommtx != NULL) {
            Mtx** unk;
            Mtx* mtx;

            if (ommtx->kind != MTX_TYPE_53) {
                continue;
            }

            unk = (Mtx**) &ommtx->unk08;
            mtx = &ommtx->unk08;

            if (ommtx->unk05 != 2) {
                if (ommtx->unk05 == 4) {
                    if (dobj->obj->lastDrawFrame != (u8) gtlDrawnFrameCounter) {
                        *unk = gtlCurrentGfxHeap.ptr;
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    } else {
                        mtx = *unk;
                        goto END;
                    }
                } else {
                    if (gtlContextId > 0) {
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    } else if (dobj->obj->lastDrawFrame == (u8) gtlDrawnFrameCounter) {
                        if (ommtx->unk05 != 3) {
                            goto END;
                        }
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    }
                }
                hal_scale(mtx, renScaleX, renScaleY, renScaleZ);
                renIsScaleMtxPushed = true;
            END:
                if (ommtx->unk05 == 1 && &ommtx->unk08 == mtx) {
                    ommtx->unk05 = 2;
                }
            }

            gSPMatrix(gfxPos++, mtx, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            mtxCount++;
        }
    }

    *gfxPtr = gfxPos;
    return mtxCount;
}

#ifdef NON_MATCHING
void renLoadTextures(DObj* dobj, Gfx** gfxPtr) {
    s32 count;
    s32 i;
    MObj* mobj;
    Gfx* gfxPos;
    Gfx* baseDl;
    u32 flags;
    f32 scaleS;
    f32 scaleT;
    f32 spD4;
    f32 spD0;
    f32 spCC;
    f32 spC8;
    f32 zero = 0.0f;

    if (dobj->mobjList == NULL) {
        return;
    }

    gSPSegment((*gfxPtr)++, 0x0E, gtlCurrentGfxHeap.ptr);

    count = 0;
    mobj = dobj->mobjList;
    while (mobj != NULL) {
        mobj = mobj->next;
        count++;
    }
    mobj = dobj->mobjList;

    gfxPos = &((Gfx*) gtlCurrentGfxHeap.ptr)[count];
    baseDl = gtlCurrentGfxHeap.ptr;

    for (i = 0; i < count; i++) {
        flags = mobj->texture.flags;
        if (flags == 0) {
            flags = 0x80 | 0x20 | 0x01;
        }

        if (flags & (0x80 | 0x40 | 0x20)) {
            scaleS = mobj->texture.scaleS;
            scaleT = mobj->texture.scaleT;
            spD4 = mobj->texture.unk_14;
            spD0 = mobj->texture.unk_18;
            spCC = mobj->texture.unk_3C;
            spC8 = mobj->texture.unk_40;
            if (mobj->texture.unk_10) {
                scaleS *= 0.5f;
                spD4 = (spD4 - mobj->texture.unk_24 + 1.0f - mobj->texture.unk_28 * 0.5f) * 0.5f;
                spCC = (spCC - mobj->texture.unk_44 + 1.0f - mobj->texture.unk_28 * 0.5f) * 0.5f;
            }
        }

        gSPBranchList(baseDl, gfxPos);

        if (flags & 0x04) {
            // load palette
            gDPSetTextureImage(gfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                               mobj->texture.palettes[(s32) mobj->paletteIndex]);
            if (flags & (0x02 | 0x01)) {
                gDPTileSync(gfxPos++);
                gDPSetTile(gfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_TILE_5, 0, 0, 0, 0, 0, 0, 0);
                gDPLoadSync(gfxPos++);
                gDPLoadTLUTCmd(gfxPos++, G_TX_TILE_5, mobj->texture.paletteBitDepth == G_IM_SIZ_8b ? 255 : 15);
                gDPPipeSync(gfxPos++);
            }
        }

        baseDl++;

        if (flags & 0x1000) {
            gSPLightColor(gfxPos++, LIGHT_1, mobj->texture.lightColor1);
        }
        if (flags & 0x2000) {
            gSPLightColor(gfxPos++, LIGHT_2, mobj->texture.lightColor2);
        }

        if (flags & (0x200 | 0x10 | 0x08)) {
            if (flags & 0x10) {
                s32 lodLevelInt = (s32) mobj->lodLevel;
                gDPSetPrimColor(gfxPos++, mobj->texture.minLodValue, (mobj->lodLevel - lodLevelInt) * 256.0f,
                                mobj->texture.primR, mobj->texture.primG, mobj->texture.primB, mobj->texture.primA);
                mobj->imageIndex = lodLevelInt;
                mobj->nextImageIndex = lodLevelInt + 1;
            } else {
                gDPSetPrimColor(gfxPos++, mobj->texture.minLodValue, mobj->lodLevel * 255.0f, mobj->texture.primR,
                                mobj->texture.primG, mobj->texture.primB, mobj->texture.primA);
            }
        }

        if (flags & 0x400) {
            gDPSetEnvColor(gfxPos++, mobj->texture.envR, mobj->texture.envG, mobj->texture.envB, mobj->texture.envA);
        }

        if (flags & 0x800) {
            gDPSetBlendColor(gfxPos++, mobj->texture.blendR, mobj->texture.blendG, mobj->texture.blendB,
                             mobj->texture.blendA);
        }

        if (flags & (0x10 | 0x2)) {
            s32 loadBlockSiz = mobj->texture.unk_33 == G_IM_SIZ_32b ? G_IM_SIZ_32b : G_IM_SIZ_16b;
            gDPSetTextureImage(gfxPos++, mobj->texture.unk_32, loadBlockSiz, 1,
                               mobj->texture.images[mobj->nextImageIndex]);
            if (flags & (0x10 | 0x1)) {
                gDPLoadSync(gfxPos++);
                switch (mobj->texture.unk_33) {
                    case G_IM_SIZ_4b:
                        gDPLoadBlock(gfxPos++, G_TX_TILE_BLOCK, 0, 0,
                                     ((mobj->texture.blockWidth * mobj->texture.blockHeight + G_IM_SIZ_4b_INCR) >>
                                      G_IM_SIZ_4b_SHIFT) -
                                         1,
                                     CALC_DXT_4b(mobj->texture.blockWidth));
                        break;
                    case G_IM_SIZ_8b:
                        gDPLoadBlock(gfxPos++, G_TX_TILE_BLOCK, 0, 0,
                                     ((mobj->texture.blockWidth * mobj->texture.blockHeight + G_IM_SIZ_8b_INCR) >>
                                      G_IM_SIZ_8b_SHIFT) -
                                         1,
                                     CALC_DXT(mobj->texture.blockWidth, G_IM_SIZ_8b_BYTES));
                        break;
                    case G_IM_SIZ_16b:
                        gDPLoadBlock(gfxPos++, G_TX_TILE_BLOCK, 0, 0,
                                     ((mobj->texture.blockWidth * mobj->texture.blockHeight + G_IM_SIZ_16b_INCR) >>
                                      G_IM_SIZ_16b_SHIFT) -
                                         1,
                                     CALC_DXT(mobj->texture.blockWidth, G_IM_SIZ_16b_BYTES));
                        break;
                    case G_IM_SIZ_32b:
                        gDPLoadBlock(gfxPos++, G_TX_TILE_BLOCK, 0, 0,
                                     ((mobj->texture.blockWidth * mobj->texture.blockHeight + G_IM_SIZ_32b_INCR) >>
                                      G_IM_SIZ_32b_SHIFT) -
                                         1,
                                     CALC_DXT(mobj->texture.blockWidth, G_IM_SIZ_32b_BYTES));
                        break;
                }
                gDPLoadSync(gfxPos++);
            }
        }

        if (flags & (0x10 | 0x1)) {
            gDPSetTextureImage(gfxPos++, mobj->texture.fmt, mobj->texture.paletteBitDepth, 1,
                               mobj->texture.images[mobj->imageIndex]);
        }

        if (flags & 0x20) {
            s32 uls, ult;
            if (ABS(scaleS) > 1.0f / 65535) {
                uls = ((spD4 * mobj->texture.widthMain + mobj->texture.unk0A) / scaleS) * 4.0f;
            } else {
                uls = zero;
            }
            if (ABS(scaleT) > 1.0f / 65535) {
                ult = (((1.0f - scaleT - spD0) * mobj->texture.heightMain + mobj->texture.unk0A) / scaleT) * 4.0f;
            } else {
                ult = zero;
            }
            gDPSetTileSize(gfxPos++, G_TX_RENDERTILE, uls, ult, ((mobj->texture.widthMain - 1) << 2) + uls,
                           ((mobj->texture.heightMain - 1) << 2) + ult);
        }

        if (flags & 0x40) {
            s32 uls, ult;
            if (ABS(scaleS) > 1.0f / 65535) {
                uls = ((spCC * mobj->texture.widthAux + mobj->texture.unk0A) / scaleS) * 4.0f;
            } else {
                uls = zero;
            }
            if (ABS(scaleT) > 1.0f / 65535) {
                ult = (((1.0f - scaleT - spC8) * mobj->texture.heightAux + mobj->texture.unk0A) / scaleT) * 4.0f;
            } else {
                ult = zero;
            }
            gDPSetTileSize(gfxPos++, G_TX_RENDERTILE + 1, uls, ult, ((mobj->texture.widthAux - 1) << 2) + uls,
                           ((mobj->texture.heightAux - 1) << 2) + ult);
        }

        if (flags & 0x80) {
            s32 s, t;
            if (ABS(scaleS) > 1.0f / 65535) {
                s = 2097152.0f / mobj->texture.scale / scaleS;
            } else {
                s = zero;
            }
            if (ABS(scaleT) > 1.0f / 65535) {
                t = 2097152.0f / mobj->texture.scale / scaleT;
            } else {
                t = zero;
            }
            if (s > 0xFFFF) {
                s = 0xFFFF;
            }
            if (t > 0xFFFF) {
                t = 0xFFFF;
            }
            gSPTexture(gfxPos++, s, t, 0, 0, G_ON);
        }

        gSPEndDisplayList(gfxPos++);
    }

    gtlCurrentGfxHeap.ptr = gfxPos;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/render/renLoadTextures.s")
void renLoadTextures(DObj* dobj, Gfx** gfxPtr);
#endif

void renRenderModelTypeACommon(GObj* gobj, Gfx** gfxPtr) {
    s32 ret;
    DObj* dobj;

    dobj = gobj->data.dobj;

    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;

    if (dobj->payload.dlist != NULL) {
        if (dobj->flags == 0) {
            ret = renPrepareModelMatrix(gfxPtr, dobj);
            renLoadTextures(dobj, gfxPtr);
            gSPDisplayList((*gfxPtr)++, dobj->payload.dlist);

            if (renIsScaleMtxPushed) {
                gSPPopMatrix((*gfxPtr)++, G_MTX_MODELVIEW);
            }
            renIsScaleMtxPushed = false;

            if (ret != 0 && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix((*gfxPtr)++, G_MTX_MODELVIEW);
            }
        }
    }
}

void renRenderModelTypeA(GObj* gobj) {
    renRenderModelTypeACommon(gobj, &gMainGfxPos[0]);
}

void renRenderModelTypeA2(GObj* gobj) {
    renRenderModelTypeACommon(gobj, &gMainGfxPos[1]);
}

void renRenderModelTypeA3(GObj* gobj) {
    renRenderModelTypeACommon(gobj, &gMainGfxPos[2]);
}

void renRenderModelTypeA4(GObj* gobj) {
    renRenderModelTypeACommon(gobj, &gMainGfxPos[3]);
}

void renRenderModelNodeTypeB(DObj* dobj) {
    s32 ret;
    DObj* curr;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    if (!(dobj->flags & 2)) {
        sp2C = renScaleX;
        sp28 = renScaleY;
        sp24 = renScaleZ;
        ret = renPrepareModelMatrix(&gMainGfxPos[0], dobj);

        if (dobj->payload.dlist != NULL && !(dobj->flags & 1)) {
            renLoadTextures(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, dobj->payload.dlist);
        }

        if (renIsScaleMtxPushed) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }
        renIsScaleMtxPushed = false;

        if (dobj->firstChild != NULL) {
            renRenderModelNodeTypeB(dobj->firstChild);
        }

        if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }
        renScaleX = sp2C;
        renScaleY = sp28;
        renScaleZ = sp24;
    }

    if (dobj->prev == NULL) {
        curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeB(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeB(GObj* arg0) {
    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;
    renRenderModelNodeTypeB(arg0->data.dobj);
}

void renRenderModelNodeTypeC(DObj* dobj, DObjPayloadTypeC* payload) {
    Gfx* temp;
    s32 sp30 = -1;
    Gfx* t1;
    Gfx* t0;
    s32 ret;
    void* segaddr;

    if (payload == NULL || dobj->flags) {
        return;
    }

    t1 = gMainGfxPos[payload->dlistID];
    ret = renPrepareModelMatrix(&gMainGfxPos[payload->dlistID], dobj);
    t0 = gMainGfxPos[payload->dlistID];

    if (payload->dlist != NULL) {
        segaddr = gtlCurrentGfxHeap.ptr;
        renLoadTextures(dobj, &gMainGfxPos[payload->dlistID]);
        gSPDisplayList(gMainGfxPos[payload->dlistID]++, payload->dlist);

        if (renIsScaleMtxPushed) {
            gSPPopMatrix(gMainGfxPos[payload->dlistID]++, G_MTX_MODELVIEW);
        }

        if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[payload->dlistID]++, G_MTX_MODELVIEW);
        }
    } else {
        sp30 = payload->dlistID;
    }

    payload++;

    while (payload->dlistID != 4) {
        if (payload->dlist != NULL) {
            temp = t1;
            while (temp != t0) {
                *gMainGfxPos[payload->dlistID]++ = *temp++;
            }

            if (dobj->mobjList != NULL) {
                goto DUMMY_LABEL;
            DUMMY_LABEL:; // TODO find better match
                gSPSegment(gMainGfxPos[payload->dlistID]++, 0x0E, segaddr);
            }
            gSPDisplayList(gMainGfxPos[payload->dlistID]++, payload->dlist);

            if (renIsScaleMtxPushed) {
                gSPPopMatrix(gMainGfxPos[payload->dlistID]++, G_MTX_MODELVIEW);
            }
            renIsScaleMtxPushed = false;

            if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[payload->dlistID]++, G_MTX_MODELVIEW);
            }
        }
        payload++;
    }

    if (sp30 != -1) {
        gMainGfxPos[sp30] = t1;
    }
}

void renRenderModelTypeC(GObj* obj) {
    DObj* dobj;

    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;
    dobj = obj->data.dobj;
    renRenderModelNodeTypeC(dobj, dobj->payload.typeC);
}

#ifdef NON_MATCHING
void ren_func_80015448(void) {
    s32 i;

    ren_D_8004B03C = ren_D_8004B050;

    for (i = 0; i < 4; i++) {
        ren_D_8004B040[i] = ren_D_8004B050;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/render/ren_func_80015448.s")
void ren_func_80015448(void);
#endif

void renRenderModelNodeTypeD(DObj* dobj) {
    void* segaddr = NULL;
    s32 sp50;
    DObjPayloadTypeC* payload;
    Gfx* sp48;
    s32 i;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp3C = renScaleX;
        f32 sp38 = renScaleY;
        f32 sp34 = renScaleZ;

        payload = dobj->payload.typeC;
        sp48 = ren_D_8004B03C;
        sp50 = renPrepareModelMatrix(&ren_D_8004B03C, dobj);

        if (payload != NULL && !(dobj->flags & 1)) {
            while (payload->dlistID != 4) {
                if (payload->dlist != 0) {
                    while (ren_D_8004B040[payload->dlistID] != ren_D_8004B03C) {
                        *gMainGfxPos[payload->dlistID]++ = *ren_D_8004B040[payload->dlistID]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            renLoadTextures(dobj, &gMainGfxPos[payload->dlistID]);
                        } else {
                            gSPSegment(gMainGfxPos[payload->dlistID]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[payload->dlistID]++, payload->dlist);
                }

                if (renIsScaleMtxPushed) {
                    gSPPopMatrix(gMainGfxPos[payload->dlistID]++, G_MTX_MODELVIEW);
                }
                payload++;
            }
        }

        if (dobj->firstChild != NULL) {
            if (renIsScaleMtxPushed) {
                for (i = 0; i < 4; i++) {
                    if (ren_D_8004B040[i] == ren_D_8004B03C) {
                        ren_D_8004B040[i]--;
                    }
                }
                ren_D_8004B03C--;
            }
            renIsScaleMtxPushed = false;
            renRenderModelNodeTypeD(dobj->firstChild);
        }

        renIsScaleMtxPushed = false;
        ren_D_8004B03C = sp48;

        for (i = 0; i < 4; i++) {
            if (ren_D_8004B040[i] > ren_D_8004B03C) {
                ren_D_8004B040[i] = ren_D_8004B03C;
                if (sp50 && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
            do {
            } while (0);
        }

        renScaleX = sp3C;
        renScaleY = sp38;
        renScaleZ = sp34;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeD(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeD(GObj* arg0) {
    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;
    renRenderModelNodeTypeD(arg0->data.dobj);
}

f32 renSquaredDistanceToCamera(DObj* arg) {
    f32 x, y, z;
    OMCamera* cam = omCurrentCamera->data.cam;

    x = arg->position.v.x - cam->viewMtx.lookAt.eye.x;
    y = arg->position.v.y - cam->viewMtx.lookAt.eye.y;
    z = arg->position.v.z - cam->viewMtx.lookAt.eye.z;

    return SQ(x) + SQ(y) + SQ(z);
}

void renRenderModelTypeE(GObj* obj) {
    DObjPayloadTypeE* payload;
    s32 ret;
    DObj* dobj;

    dobj = obj->data.dobj;
    payload = dobj->payload.typeE;

    if (payload != NULL && !(dobj->flags)) {
        f32 dist = renSquaredDistanceToCamera(dobj);

        while (payload->maxSqDist > dist) {
            payload++;
        }

        renScaleX = renScaleY = renScaleZ = 1.0f;
        renIsScaleMtxPushed = false;

        if (payload->dlist != NULL) {
            ret = renPrepareModelMatrix(&gMainGfxPos[0], dobj);
            renLoadTextures(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, payload->dlist);
            if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }
        }
    }
}

void renRenderModelNodeTypeF(DObj* dobj) {
    s32 ret;
    Gfx** payload = dobj->payload.typeF;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp20 = renScaleX;

        ret = renPrepareModelMatrix(&gMainGfxPos[0], dobj);
        if (payload != NULL && payload[renLevelOfDetail] != NULL && !(dobj->flags & 1)) {
            renLoadTextures(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, payload[renLevelOfDetail]);
        }

        if (dobj->firstChild != NULL) {
            renRenderModelNodeTypeF(dobj->firstChild);
        }

        if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }

        renScaleX = sp20;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeF(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeF(GObj* obj) {
    DObjPayloadTypeE* payload;
    s32 ret;
    UNUSED s32 temp;
    DObj* dobj = obj->data.dobj;

    if (1) {
    } // required to match
    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;

    if (!(dobj->flags & 2)) {
        payload = dobj->payload.typeE;
        if (payload != NULL) {
            f32 dist2;

            renLevelOfDetail = 0;
            dist2 = renSquaredDistanceToCamera(dobj);
            while (payload->maxSqDist > dist2) {
                payload++;
                renLevelOfDetail++;
            }

            ret = renPrepareModelMatrix(&gMainGfxPos[0], dobj);
            if (payload->dlist != NULL && !(dobj->flags & 1)) {
                renLoadTextures(dobj, &gMainGfxPos[0]);
                gSPDisplayList(gMainGfxPos[0]++, payload->dlist);
            }

            if (dobj->firstChild != NULL) {
                renRenderModelNodeTypeF(dobj->firstChild);
            }

            if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    renRenderModelNodeTypeF(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void renRenderModelTypeG(GObj* obj) {
    DObjPayloadTypeG* payload;
    UNUSED s32 temp;
    DObj* dobj = obj->data.dobj;

    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;

    if (!(dobj->flags)) {
        payload = dobj->payload.any;
        if (payload != NULL) {
            f32 dist;

            dist = renSquaredDistanceToCamera(dobj);
            while (payload->maxSqDist > dist) {
                payload++;
            }

            renRenderModelNodeTypeC(dobj, payload->payloadTypeC);
        }
    }
}

void renRenderModelNodeTypeH(DObj* dobj) {
    void* segaddr = NULL;
    s32 ret;
    DObjPayloadTypeC** payload;
    DObjPayloadTypeC* curPayload;
    Gfx* sp3C;
    s32 i;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp30 = renScaleX;
        payload = dobj->payload.typeH;
        if (payload != NULL) {
            curPayload = payload[renLevelOfDetail];
        }

        sp3C = ren_D_8004B03C;
        ret = renPrepareModelMatrix(&ren_D_8004B03C, dobj);

        if (payload != NULL && curPayload != NULL && !(dobj->flags & 1)) {
            while (curPayload->dlistID != 4) {
                if (curPayload->dlist != NULL) {
                    while (ren_D_8004B040[curPayload->dlistID] != ren_D_8004B03C) {
                        *gMainGfxPos[curPayload->dlistID]++ = *ren_D_8004B040[curPayload->dlistID]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            renLoadTextures(dobj, &gMainGfxPos[curPayload->dlistID]);
                        } else {
                            gSPSegment(gMainGfxPos[curPayload->dlistID]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[curPayload->dlistID]++, curPayload->dlist);
                }

                curPayload++;
            }
        }

        if (dobj->firstChild != NULL) {
            renRenderModelNodeTypeH(dobj->firstChild);
        }

        ren_D_8004B03C = sp3C;
        for (i = 0; i < 4; i++) {
            if (ren_D_8004B040[i] > ren_D_8004B03C) {
                ren_D_8004B040[i] = ren_D_8004B03C;
                if (dobj) {
                }
                if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
        }

        renScaleX = sp30;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeH(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeH(GObj* obj) {
    UNUSED s32 temp[2];
    s32 ret;
    DObjPayloadTypeG* payload;
    DObj* dobj = obj->data.dobj;
    void* segaddr = NULL;
    DObjPayloadTypeC* sp34;
    Gfx* sp30;
    s32 i;

    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;

    if (!(dobj->flags & 2)) {
        payload = dobj->payload.typeG;
        if (payload != NULL) {
            f32 dist;

            renLevelOfDetail = 0;
            dist = renSquaredDistanceToCamera(dobj);
            while (payload->maxSqDist > dist) {
                payload++;
                renLevelOfDetail++;
            }

            sp34 = payload->payloadTypeC;
            sp30 = ren_D_8004B03C;
            ret = renPrepareModelMatrix(&ren_D_8004B03C, dobj);

            if (sp34 != NULL && !(dobj->flags & 1)) {
                while (sp34->dlistID != 4) {
                    if (sp34->dlist != NULL) {
                        while (ren_D_8004B040[sp34->dlistID] != ren_D_8004B03C) {
                            *gMainGfxPos[sp34->dlistID]++ = *ren_D_8004B040[sp34->dlistID]++;
                        }

                        if (dobj->mobjList != NULL) {
                            if (segaddr == NULL) {
                                segaddr = gtlCurrentGfxHeap.ptr;
                                renLoadTextures(dobj, &gMainGfxPos[sp34->dlistID]);
                            } else {
                                gSPSegment(gMainGfxPos[sp34->dlistID]++, 0x0E, segaddr);
                            }
                        }

                        gSPDisplayList(gMainGfxPos[sp34->dlistID]++, sp34->dlist);
                    }

                    sp34++;
                }
            }

            if (dobj->firstChild != NULL) {
                renRenderModelNodeTypeH(dobj->firstChild);
            }

            ren_D_8004B03C = sp30;
            for (i = 0; i < 4; i++) {
                if (ren_D_8004B040[i] > ren_D_8004B03C) {
                    ren_D_8004B040[i] = ren_D_8004B03C;
                    if (dobj) {
                    }
                    if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                        gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                    }
                }
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    renRenderModelNodeTypeH(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void renRenderModelNodeTypeI(DObj* dobj) {
    s32 ret;
    UNUSED s32 temp;
    f32 sp2C, sp28, sp24;
    DObjPayloadTypeI* payload;

    payload = dobj->payload.typeI;

    if (!(dobj->flags & 2)) {
        sp2C = renScaleX;
        sp28 = renScaleY;
        sp24 = renScaleZ;

        if (payload != NULL && payload->unk_00 != NULL && !(dobj->flags & 1)) {
            ren_func_80013C5C(&gMainGfxPos[0], dobj->parent);
            gSPDisplayList(gMainGfxPos[0]++, payload->unk_00);
            if (renIsScaleMtxPushed) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }
            renIsScaleMtxPushed = false;
        }

        ret = renPrepareModelMatrix(&gMainGfxPos[0], dobj);

        if (payload != NULL && payload->unk_04 != NULL && !(dobj->flags & 1)) {
            renLoadTextures(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, payload->unk_04);
        }
        if (renIsScaleMtxPushed) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }
        renIsScaleMtxPushed = false;

        if (dobj->firstChild != NULL) {
            renRenderModelNodeTypeI(dobj->firstChild);
        }

        if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }

        renScaleX = sp2C;
        renScaleY = sp28;
        renScaleZ = sp24;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeI(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeI(GObj* arg0) {
    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;
    renRenderModelNodeTypeI(arg0->data.dobj);
}

void renRenderModelNodeTypeJ(DObj* dobj) {
    void* segaddr = NULL;
    s32 sp60;
    s32 i;
    Gfx* sp58;
    DObjPayloadTypeJ* payload;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp4C = renScaleX;
        f32 sp48 = renScaleY;
        f32 sp44 = renScaleZ;
        s32 sp40;

        payload = dobj->payload.typeJ;
        sp58 = ren_D_8004B03C;
        sp60 = renPrepareModelMatrix(&ren_D_8004B03C, dobj);
        sp40 = renIsScaleMtxPushed;
        renIsScaleMtxPushed = false;

        if (payload != NULL && !(dobj->flags & 1)) {
            while (payload->dlistID != 4) {
                if (payload->unk_08 != 0) {
                    if (payload->unk_04 != 0) {
                        ren_func_80013C5C(&gMainGfxPos[payload->dlistID], dobj->parent);
                        gSPDisplayList(gMainGfxPos[payload->dlistID]++, payload->unk_04);
                        if (renIsScaleMtxPushed) {
                            gSPPopMatrix(gMainGfxPos[payload->dlistID]++, G_MTX_MODELVIEW);
                        }
                        renIsScaleMtxPushed = false;
                    }

                    while (ren_D_8004B040[payload->dlistID] != ren_D_8004B03C) {
                        *gMainGfxPos[payload->dlistID]++ = *ren_D_8004B040[payload->dlistID]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            renLoadTextures(dobj, &gMainGfxPos[payload->dlistID]);
                        } else {
                            gSPSegment(gMainGfxPos[payload->dlistID]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[payload->dlistID]++, payload->unk_08);

                    if (sp40) {
                        gSPPopMatrix(gMainGfxPos[payload->dlistID]++, G_MTX_MODELVIEW);
                    }
                }
                payload++;
            }
        }

        if (dobj->firstChild != NULL) {
            if (sp40) {
                for (i = 0; i < 4; i++) {
                    if (ren_D_8004B040[i] == ren_D_8004B03C) {
                        ren_D_8004B040[i]--;
                    }
                }
                ren_D_8004B03C--;
            }
            renRenderModelNodeTypeJ(dobj->firstChild);
        }

        ren_D_8004B03C = sp58;

        for (i = 0; i < 4; i++) {
            if (ren_D_8004B040[i] > ren_D_8004B03C) {
                ren_D_8004B040[i] = ren_D_8004B03C;
                if (sp60 && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
        }

        renScaleX = sp4C;
        renScaleY = sp48;
        renScaleZ = sp44;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeJ(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeJ(GObj* arg0) {
    renScaleX = renScaleY = renScaleZ = 1.0f;
    renIsScaleMtxPushed = false;
    renRenderModelNodeTypeJ(arg0->data.dobj);
}

void renRenderModelNodeTypeK(DObj* dobj) {
    s32 ret;
    DObjPayloadTypeI** payload = dobj->payload.typeK;

    if (!(dobj->flags & 2)) {
        f32 sp24 = renScaleX;
        DObjPayloadTypeI* curPayload;

        if (payload != NULL) {
            curPayload = payload[renLevelOfDetail];
        }

        if (payload != NULL && curPayload->unk_00 != NULL && !(dobj->flags & 1)) {
            gSPDisplayList(gMainGfxPos[0]++, curPayload->unk_00);
        }

        ret = renPrepareModelMatrix(&gMainGfxPos[0], dobj);

        if (payload != NULL && curPayload->unk_04 != NULL && !(dobj->flags & 1)) {
            renLoadTextures(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, curPayload->unk_04);
        }

        if (dobj->firstChild != NULL) {
            renRenderModelNodeTypeK(dobj->firstChild);
        }

        if (ret != 0 && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }

        renScaleX = sp24;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeK(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeK(GObj* obj) {
    DObjPayloadTypeE* payload;
    s32 ret;
    f32 dist;
    DObj* dobj = obj->data.dobj;

    if (!(dobj->flags & 2)) {
        payload = dobj->payload.typeE;
        if (payload != NULL) {
            renScaleX = renScaleY = renScaleZ = 1.0f;
            renIsScaleMtxPushed = false;
            renLevelOfDetail = 0;

            dist = renSquaredDistanceToCamera(dobj);
            while (payload->maxSqDist > dist) {
                payload++;
                renLevelOfDetail++;
            }

            ret = renPrepareModelMatrix(&gMainGfxPos[0], dobj);

            if (payload->dlist != NULL && !(dobj->flags & 1)) {
                renLoadTextures(dobj, &gMainGfxPos[0]);
                if (true) { // required to match
                    gSPDisplayList(gMainGfxPos[0]++, payload->dlist);
                }
            }

            if (dobj->firstChild != NULL) {
                renRenderModelNodeTypeK(dobj->firstChild);
            }

            if (ret != 0 && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    renRenderModelNodeTypeK(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void renRenderModelNodeTypeL(DObj* dobj) {
    s32 i;
    s32 ret;
    u8* segaddr;
    DObjPayloadTypeJ* curPayload;
    Gfx* sp3C;
    DObjPayloadTypeJ** payload;
    UNUSED s32 temp;
    f32 sp30;

    segaddr = NULL;

    if (!(dobj->flags & 2)) {
        sp30 = renScaleX;

        payload = dobj->payload.typeL;
        if (payload != NULL) {
            curPayload = payload[renLevelOfDetail];
        }

        sp3C = ren_D_8004B03C;
        ret = renPrepareModelMatrix(&ren_D_8004B03C, dobj);

        if (payload != NULL && curPayload != NULL && !(dobj->flags & 1)) {
            while (curPayload->dlistID != 4) {
                if (curPayload->unk_08 != NULL) {
                    if (curPayload->unk_04 != NULL) {
                        gSPDisplayList(gMainGfxPos[curPayload->dlistID]++, curPayload->unk_04);
                    }

                    while (ren_D_8004B040[curPayload->dlistID] != ren_D_8004B03C) {
                        *gMainGfxPos[curPayload->dlistID]++ = *ren_D_8004B040[curPayload->dlistID]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            renLoadTextures(dobj, &gMainGfxPos[curPayload->dlistID]);
                        } else {
                            gSPSegment(gMainGfxPos[curPayload->dlistID]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[curPayload->dlistID]++, curPayload->unk_08);
                }
                curPayload++;
            }
        }

        if (dobj->firstChild != NULL) {
            renRenderModelNodeTypeL(dobj->firstChild);
        }

        ren_D_8004B03C = sp3C;
        for (i = 0; i < 4; i++) {
            if (ren_D_8004B040[i] > ren_D_8004B03C) {
                ren_D_8004B040[i] = ren_D_8004B03C;
                if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
        }

        renScaleX = sp30;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            renRenderModelNodeTypeL(curr);
            curr = curr->next;
        }
    }
}

void renRenderModelTypeL(GObj* obj) {
    DObj* dobj;
    u8* segaddr;
    s32 ret;
    DObjPayloadTypeG* payload;
    f32 dist;
    s32 i;
    DObjPayloadTypeC* subPayload;
    Gfx* sp30;

    dobj = obj->data.dobj;
    segaddr = 0;

    if (!(dobj->flags & 2)) {
        payload = dobj->payload.typeG;
        if (payload != NULL) {
            renScaleX = renScaleY = renScaleZ = 1.0f;
            renIsScaleMtxPushed = false;
            renLevelOfDetail = 0;

            dist = renSquaredDistanceToCamera(dobj);
            while (payload->maxSqDist > dist) {
                payload++;
                renLevelOfDetail++;
            }

            subPayload = payload->payloadTypeC;
            sp30 = ren_D_8004B03C;
            ret = renPrepareModelMatrix(&ren_D_8004B03C, dobj);

            if (subPayload != NULL && !(dobj->flags & 1)) {
                while (subPayload->dlistID != 4) {
                    if (subPayload->dlist != NULL) {
                        while (ren_D_8004B040[subPayload->dlistID] != ren_D_8004B03C) {
                            *gMainGfxPos[subPayload->dlistID]++ = *ren_D_8004B040[subPayload->dlistID]++;
                        }

                        if (dobj->mobjList != NULL) {
                            if (segaddr == NULL) {
                                segaddr = gtlCurrentGfxHeap.ptr;
                                renLoadTextures(dobj, &gMainGfxPos[subPayload->dlistID]);
                            } else {
                                gSPSegment(gMainGfxPos[subPayload->dlistID]++, 0x0E, segaddr);
                            }
                        }

                        gSPDisplayList(gMainGfxPos[subPayload->dlistID]++, subPayload->dlist);
                    }
                    subPayload++;
                }
            }

            if (dobj->firstChild != NULL) {
                renRenderModelNodeTypeL(dobj->firstChild);
            }

            ren_D_8004B03C = sp30;
            for (i = 0; i < 4; i++) {
                if (ren_D_8004B040[i] > ren_D_8004B03C) {
                    ren_D_8004B040[i] = ren_D_8004B03C;
                    if (ret && ((uintptr_t) dobj->parent == 1 || dobj->next != NULL)) {
                        gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                    }
                }
                if (!NULL) {
                } // required to match
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    renRenderModelNodeTypeL(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void renDrawSprite(GObj* arg0) {
    SObj* sobj = arg0->data.sobj;
    while (sobj != NULL) {
        if (!(sobj->sprite.attr & SP_HIDDEN)) {
            sobj->sprite.rsp_dl_next = gMainGfxPos[0];
            spDraw(&sobj->sprite);
            gMainGfxPos[0] = sobj->sprite.rsp_dl_next - 1;
        }
        sobj = sobj->next;
    }
}

#ifdef NON_MATCHING
void ren_func_800177D8(Gfx** gfxPtr, OMCamera* cam, s32 mode) {
    s32 xmin, ymin, xmax, ymax;
    Gfx* gfxPos;

    if ((mode == 0 || mode == 1) && (cam->flags & CAMERA_FLAG_20)) {
        gtl_load_ucode(gfxPtr, gtlD_8004A906);
        gtlD_8004A908 = true;
    }
    gfxPos = *gfxPtr;

    gSPViewport(gfxPos++, &cam->vp);
    xmin = cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4;
    ymin = cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4;
    xmax = cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4;
    ymax = cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4;

    if (xmin < viScreenWidth / SCREEN_WIDTH * renCameraScisLeft) {
        xmin = viScreenWidth / SCREEN_WIDTH * renCameraScisLeft;
    }
    if (ymin < viScreenHeight / SCREEN_HEIGHT * renCameraScisTop) {
        ymin = viScreenHeight / SCREEN_HEIGHT * renCameraScisTop;
    }
    if (xmax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * renCameraScisRight) {
        xmax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * renCameraScisRight;
    }
    if (ymax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * renCameraScisBottom) {
        ymax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * renCameraScisBottom;
    }

    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE, xmin, ymin, xmax, ymax);
    gDPPipeSync(gfxPos++);
    gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, viBitDepth, viScreenWidth, 0x0F000000);
    gDPSetCycleType(gfxPos++, G_CYC_1CYCLE);

    if (mode == 0 || mode == 2) {
        gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    } else {
        gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    }

    *gfxPtr = gfxPos;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/render/ren_func_800177D8.s")
void ren_func_800177D8(Gfx** gfxPtr, OMCamera* cam, s32 mode);
#endif

#ifdef NON_MATCHING
void renInitCamera(Gfx** gfxPtr, OMCamera* cam, s32 mode) {
    s32 xmin, ymin, xmax, ymax;
    Gfx* gfxPos;

    if ((mode == 0 || mode == 1) && (cam->flags & CAMERA_FLAG_20)) {
        gtl_load_ucode(gfxPtr, gtlD_8004A906);
        gtlD_8004A908 = true;
    }
    gfxPos = *gfxPtr;

    gSPViewport(gfxPos++, &cam->vp);
    xmin = cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4;
    ymin = cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4;
    xmax = cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4;
    ymax = cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4;

    if (xmin < viScreenWidth / SCREEN_WIDTH * renCameraScisLeft) {
        xmin = viScreenWidth / SCREEN_WIDTH * renCameraScisLeft;
    }
    if (ymin < viScreenHeight / SCREEN_HEIGHT * renCameraScisTop) {
        ymin = viScreenHeight / SCREEN_HEIGHT * renCameraScisTop;
    }
    if (xmax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * renCameraScisRight) {
        xmax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * renCameraScisRight;
    }
    if (ymax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * renCameraScisBottom) {
        ymax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * renCameraScisBottom;
    }

    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE, xmin, ymin, xmax, ymax);

    xmax--;
    ymax--;

    if (cam->flags & CAMERA_FLAG_1) {
        gDPPipeSync(gfxPos++);
        gDPSetCycleType(gfxPos++, G_CYC_FILL);
        gDPSetRenderMode(gfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viScreenWidth, viZBuffer);
        gDPSetFillColor(gfxPos++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
        gDPFillRectangle(gfxPos++, xmin, ymin, xmax, ymax);
    }

    gDPPipeSync(gfxPos++);
    gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, viBitDepth, viScreenWidth, 0x0F000000);

    if (cam->flags & CAMERA_FLAG_2) {
        gDPSetCycleType(gfxPos++, G_CYC_FILL);
        gDPSetRenderMode(gfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfxPos++, viPackRGBA(cam->bgColor));
        gDPFillRectangle(gfxPos++, xmin, ymin, xmax, ymax);
    }

    gDPPipeSync(gfxPos++);
    gDPSetCycleType(gfxPos++, G_CYC_1CYCLE);
    if (mode == 0 || mode == 2) {
        gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    } else {
        gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    }

    *gfxPtr = gfxPos;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/render/renInitCamera.s")
void renInitCamera(Gfx** gfxPtr, OMCamera* cam, s32 mode);
#endif

void renInitCameraEx(Gfx** gfxPtr, OMCamera* cam, s32 mode, u16* buffer, s32 width, s32 height, u16* zbuffer) {
    Gfx* gfxPos;
    s32 xmin, ymin, xmax, ymax;
    UNUSED s32 pad;

    gfxPos = *gfxPtr;
    gSPViewport(gfxPos++, &cam->vp);
    xmin = cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4;
    ymin = cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4;
    xmax = cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4;
    ymax = cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4;

    if (xmin < 0) {
        xmin = 0;
    }
    if (ymin < 0) {
        ymin = 0;
    }
    if (xmax > width) {
        xmax = width;
    }
    if (ymax > height) {
        ymax = height;
    }

    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE, xmin, ymin, xmax, ymax);

    xmax--;
    ymax--;

    if (cam->flags & CAMERA_FLAG_1) {
        gDPPipeSync(gfxPos++);
        gDPSetCycleType(gfxPos++, G_CYC_FILL);
        gDPSetRenderMode(gfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, zbuffer);
        gDPSetFillColor(gfxPos++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
        gDPFillRectangle(gfxPos++, xmin, ymin, xmax, ymax);
    }

    gDPPipeSync(gfxPos++);
    gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, viBitDepth, width, buffer);
    gDPSetDepthImage(gfxPos++, zbuffer);

    if (cam->flags & CAMERA_FLAG_2) {
        gDPSetCycleType(gfxPos++, G_CYC_FILL);
        gDPSetRenderMode(gfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfxPos++, viPackRGBA(cam->bgColor));
        gDPFillRectangle(gfxPos++, xmin, ymin, xmax, ymax);
    }

    gDPPipeSync(gfxPos++);
    gDPSetCycleType(gfxPos++, G_CYC_1CYCLE);
    if (mode == 0 || mode == 2) {
        gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    } else {
        gDPSetRenderMode(gfxPos++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    }

    *gfxPtr = gfxPos;
}

#ifdef NON_MATCHING
void renPrepareCameraMatrix(Gfx** gfxPtr, OMCamera* cam) {
    Gfx* spDC;
    s32 i;
    s32 s3;
    LookAt* lookat;
    f32 f2;
    s32 spC8;
    f32 sp9C;
    f32 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;

    spDC = *gfxPtr;
    spC8 = 0;
    s3 = 0;

    if (cam->numMatrices == 0) {
        return;
    }

    for (i = 0; i < cam->numMatrices; i++) {
        OMMtx* ommtx = cam->matrices[i];
        if (ommtx != NULL) {
            Mtx* mtx = &ommtx->unk08;

            if (ommtx->unk05 != 2) {
                if (gtlContextId > 0) {
                    mtx = gtlCurrentGfxHeap.ptr;
                    gtlCurrentGfxHeap.ptr = (char*) gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                }

                switch (ommtx->kind) {
                    case MTX_TYPE_1:
                        break;
                    case MTX_TYPE_2:
                        break;
                    case MTX_TYPE_PERSP_FAST:
                        hal_perspective_fast_f(&renPerspectiveMatrixF, &cam->perspMtx.persp.perspNorm,
                                               cam->perspMtx.persp.fovy, cam->perspMtx.persp.aspect,
                                               cam->perspMtx.persp.near, cam->perspMtx.persp.far,
                                               cam->perspMtx.persp.scale);
                        hal_mtx_f2l(renPerspectiveMatrixF, mtx);
                        renProjectionMatrix = mtx;
                        break;
                    case MTX_TYPE_PERSP:
                        hal_perspective_f(&renPerspectiveMatrixF, &cam->perspMtx.persp.perspNorm,
                                          cam->perspMtx.persp.fovy, cam->perspMtx.persp.aspect,
                                          cam->perspMtx.persp.near, cam->perspMtx.persp.far, cam->perspMtx.persp.scale);
                        hal_mtx_f2l(renPerspectiveMatrixF, mtx);
                        renProjectionMatrix = mtx;
                        break;
                    case MTX_TYPE_ORTHO:
                        hal_ortho(mtx, cam->perspMtx.ortho.l, cam->perspMtx.ortho.r, cam->perspMtx.ortho.b,
                                  cam->perspMtx.ortho.t, cam->perspMtx.ortho.n, cam->perspMtx.ortho.f,
                                  cam->perspMtx.ortho.scale);
                        renProjectionMatrix = mtx;
                        break;
                    case MTX_TYPE_LOOKAT:
                    case MTX_TYPE_LOOKAT_MVIEW:
                        hal_look_at(mtx, cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y, cam->viewMtx.lookAt.eye.z,
                                    cam->viewMtx.lookAt.at.x, cam->viewMtx.lookAt.at.y, cam->viewMtx.lookAt.at.z,
                                    cam->viewMtx.lookAt.xUp, cam->viewMtx.lookAt.yUp, cam->viewMtx.lookAt.zUp);
                        if (cam->viewMtx.lookAt.zUp < cam->viewMtx.lookAt.yUp) {
                            s3 = 1;
                        } else {
                            s3 = 2;
                        }
                        break;
                    case MTX_TYPE_LOOKAT_ROLL:
                    case MTX_TYPE_LOOKAT_ROLL_MVIEW:
                        hal_look_at_roll(mtx, cam->viewMtx.lookAtRoll.eye.x, cam->viewMtx.lookAtRoll.eye.y,
                                         cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.at.x,
                                         cam->viewMtx.lookAtRoll.at.y, cam->viewMtx.lookAtRoll.at.z,
                                         cam->viewMtx.lookAtRoll.roll, 0.0f, 1.0f, 0.0f);
                        s3 = 1;
                        break;
                    case MTX_TYPE_LOOKAT_ROLL_Z:
                    case MTX_TYPE_LOOKAT_ROLL_Z_MVIEW:
                        hal_look_at_roll(mtx, cam->viewMtx.lookAtRoll.eye.x, cam->viewMtx.lookAtRoll.eye.y,
                                         cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.at.x,
                                         cam->viewMtx.lookAtRoll.at.y, cam->viewMtx.lookAtRoll.at.z,
                                         cam->viewMtx.lookAtRoll.roll, 0.0f, 0.0f, 1.0f);
                        s3 = 2;
                        break;
                    case MTX_TYPE_LOOKAT_REFLECT:
                    case MTX_TYPE_LOOKAT_REFLECT_MVIEW:
                        lookat = bump_alloc(&gtlCurrentGfxHeap, sizeof(LookAt), 8);
                        hal_look_at_reflect(mtx, lookat, cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y,
                                            cam->viewMtx.lookAt.eye.z, cam->viewMtx.lookAt.at.x, cam->viewMtx.lookAt.at.y,
                                            cam->viewMtx.lookAt.at.z, cam->viewMtx.lookAt.xUp, cam->viewMtx.lookAt.yUp,
                                            cam->viewMtx.lookAt.zUp);
                        if (cam->viewMtx.lookAt.zUp < cam->viewMtx.lookAt.yUp) {
                            s3 = 1;
                        } else {
                            s3 = 2;
                        }
                        break;
                    case MTX_TYPE_LOOKAT_REFLECT_ROLL:
                    case MTX_TYPE_LOOKAT_REFLECT_ROLL_MVIEW:
                        lookat = bump_alloc(&gtlCurrentGfxHeap, sizeof(LookAt), 8);
                        hal_look_at_reflect_roll(
                            mtx, lookat, cam->viewMtx.lookAtRoll.eye.x, cam->viewMtx.lookAtRoll.eye.y,
                            cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.at.x, cam->viewMtx.lookAtRoll.at.y,
                            cam->viewMtx.lookAtRoll.at.z, cam->viewMtx.lookAtRoll.roll, 0.0f, 1.0f, 0.0f);
                        s3 = 1;
                        break;
                    case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z:
                    case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z_MVIEW:
                        lookat = bump_alloc(&gtlCurrentGfxHeap, sizeof(LookAt), 8);
                        hal_look_at_reflect_roll(
                            mtx, lookat, cam->viewMtx.lookAtRoll.eye.x, cam->viewMtx.lookAtRoll.eye.y,
                            cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.at.x, cam->viewMtx.lookAtRoll.at.y,
                            cam->viewMtx.lookAtRoll.at.z, cam->viewMtx.lookAtRoll.roll, 0.0f, 0.0f, 1.0f);
                        s3 = 2;
                        break;
                    default:
                        if (ommtx->kind >= MTX_TYPE_66 && renCustomMatrixHandler != NULL) {
                            if (renCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_00 != NULL) {
                                renCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_00(mtx, cam, &spDC);
                            }
                        }
                        break;
                }

                if (ommtx->unk05 == 1 && &ommtx->unk08 == mtx) {
                    ommtx->unk05 = 2;
                }
            }

            switch (ommtx->kind) {
                case MTX_TYPE_1:
                    break;
                case MTX_TYPE_2:
                    break;
                case MTX_TYPE_PERSP_FAST:
                case MTX_TYPE_PERSP:
                    gSPMatrix(spDC++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                    gSPPerspNormalize(spDC++, cam->perspMtx.persp.perspNorm);
                    break;
                case MTX_TYPE_ORTHO:
                    gSPMatrix(spDC++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
                    break;
                case MTX_TYPE_LOOKAT_REFLECT:
                case MTX_TYPE_LOOKAT_REFLECT_ROLL:
                case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z:
                    gSPLookAt(spDC++, lookat);
                    /*  fallthrough */
                case MTX_TYPE_LOOKAT:
                case MTX_TYPE_LOOKAT_ROLL:
                case MTX_TYPE_LOOKAT_ROLL_Z:
                    gSPMatrix(spDC++, mtx, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
                    break;
                case MTX_TYPE_LOOKAT_REFLECT_MVIEW:
                case MTX_TYPE_LOOKAT_REFLECT_ROLL_MVIEW:
                case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z_MVIEW:
                    gSPLookAt(spDC++, lookat);
                    /*  fallthrough */
                case MTX_TYPE_LOOKAT_MVIEW:
                case MTX_TYPE_LOOKAT_ROLL_MVIEW:
                case MTX_TYPE_LOOKAT_ROLL_Z_MVIEW:
                    gSPMatrix(spDC++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    break;
                default:
                    if (ommtx->kind >= MTX_TYPE_66 && renCustomMatrixHandler != NULL) {
                        if (renCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_04 != NULL) {
                            renCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_04(mtx, cam, &spDC);
                        }
                    }
                    break;
            }
        }
    }

    switch (ren_D_8004B028) {
        case 0:
            spC8 = s3;
            break;
        case 1:
            s3 = 0;
            break;
        case 2:
            spC8 = 1;
            s3 = 1;
            break;
        case 3:
            s3 = 1;
            break;
        case 4:
            spC8 = 1;
            s3 = 0;
            break;
        case 5:
            spC8 = 2;
            s3 = 2;
            break;
        case 6:
            s3 = 2;
            break;
        case 7:
            spC8 = 2;
            s3 = 0;
            break;
    }

    if (s3 != 0) {
        switch (s3) {
            case 1:
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.at.z - cam->viewMtx.lookAt.eye.z) +
                           SQ(cam->viewMtx.lookAt.at.x - cam->viewMtx.lookAt.eye.x));
                sp98 = cam->viewMtx.lookAt.eye.y;
                sp94 = cam->viewMtx.lookAt.at.y;
                break;
            case 2:
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.at.y - cam->viewMtx.lookAt.eye.y) +
                           SQ(cam->viewMtx.lookAt.at.x - cam->viewMtx.lookAt.eye.x));
                sp98 = cam->viewMtx.lookAt.eye.z;
                sp94 = cam->viewMtx.lookAt.at.z;
                break;
            default:
                f2 = sp9C;
                break;
        }
        if (f2 < 0.0001f) {
            hal_scale_f(&ren_D_8004AFA8, 0.0f, 0.0f, 0.0f);
        } else {
            hal_look_at_f(&ren_D_8004AFA8, 0.0f, sp98, f2, 0.0f, sp94, 0.0f, 0.0f, 1.0f, 0.0f);
            guMtxCatF(ren_D_8004AFA8, renPerspectiveMatrixF, ren_D_8004AFA8);
        }
    }

    if (spC8 != 0) {
        switch (spC8) {
            case 1:
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.at.y - cam->viewMtx.lookAt.eye.y) +
                           SQ(cam->viewMtx.lookAt.at.z - cam->viewMtx.lookAt.eye.z));
                sp8C = cam->viewMtx.lookAt.eye.x;
                sp88 = cam->viewMtx.lookAt.at.x;
                break;
            case 2:
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.at.z - cam->viewMtx.lookAt.eye.z) +
                           SQ(cam->viewMtx.lookAt.at.x - cam->viewMtx.lookAt.eye.x));
                sp8C = cam->viewMtx.lookAt.eye.y;
                sp88 = cam->viewMtx.lookAt.at.y;
                break;
            default:
                f2 = sp90;
                break;
        }
        if (f2 < 0.0001f) {
            hal_scale_f(&ren_D_8004AFE8, 0.0f, 0.0f, 0.0f);
        } else {
            hal_look_at_f(&ren_D_8004AFE8, sp8C, 0.0f, f2, sp88, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            guMtxCatF(ren_D_8004AFE8, renPerspectiveMatrixF, ren_D_8004AFE8);
        }
    }

    *gfxPtr = spDC;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/render/renPrepareCameraMatrix.s")
void renPrepareCameraMatrix(Gfx** gfxPtr, OMCamera* cam);
#endif

void ren_func_80018CD0(s32 val) {
    ren_D_8004B028 = val;
}

void renCameraPreRender(OMCamera* cam, s32 arg1) {
    if (cam->fnPreRender != NULL) {
        cam->fnPreRender(cam, arg1);
    }
}

void renCameraRenderByLink(GObj* camObj, s32 dlLink, s32 mode) {
    GObj* curr = omGObjListDlHead[dlLink];

    while (curr != NULL) {
        if (!(curr->flags & GOBJ_FLAG_HIDDEN)) {
            if (mode == 0 && (camObj->cameraTag & curr->cameraTag) ||
                mode == 1 && camObj->cameraTag == curr->cameraTag) {
                omRenderedObject = curr;
                curr->fnRender(curr);
                curr->lastDrawFrame = gtlDrawnFrameCounter;
            }
        }

        curr = curr->nextDl;
    }
}

void ren_func_80018DE8(GObj* obj, s32 dlLink, s32 mode) {
    Gfx* savedGfxPos[4];
    s32 i;

    for (i = 0; i < 4; i++) {
        savedGfxPos[i] = gMainGfxPos[i];
        // reserve space for 2 commands: gSPDisplayList and gSPBranchList
        gMainGfxPos[i] += 2;
    }

    renCameraRenderByLink(obj, dlLink, mode);

    for (i = 0; i < 4; i++) {
        if (gMainGfxPos[i] == savedGfxPos[i] + 2) {
            // nothing added to this dlist
            gMainGfxPos[i] -= 2;
            omD_8004AC78[dlLink].unk04[i] = NULL;
        } else {
            gSPEndDisplayList(gMainGfxPos[i]++);
            gSPDisplayList(savedGfxPos[i], savedGfxPos[i] + 2);
            savedGfxPos[i]++;
            gSPBranchList(savedGfxPos[i]++, gMainGfxPos[i]);
            omD_8004AC78[dlLink].unk04[i] = savedGfxPos[i];
        }
    }

    omD_8004AC78[dlLink].unk00 = gtlDrawnFrameCounter;
}

void ren_func_80018F1C(s32 dlLink) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (omD_8004AC78[dlLink].unk04[i] != NULL) {
            gSPDisplayList(gMainGfxPos[i]++, omD_8004AC78[dlLink].unk04[i]);
        }
    }
}

void renCameraRenderObjects(GObj* camObj, s32 mode) {
    s32 dlLink = 0;
    u32 dlLinkBitMask = camObj->dlLinkBitMask;
    u32 unk_38 = camObj->unk_38;

    while (dlLinkBitMask != 0) {
        if (dlLinkBitMask & 1) {
            if (unk_38 & 1) {
                if ((u8) gtlDrawnFrameCounter == omD_8004AC78[dlLink].unk00) {
                    ren_func_80018F1C(dlLink);
                } else {
                    ren_func_80018DE8(camObj, dlLink, mode);
                }
            } else {
                renCameraRenderByLink(camObj, dlLink, mode);
            }
        }

        dlLinkBitMask >>= 1;
        unk_38 >>= 1;
        dlLink++;
    }
}

void renCameraPostRender(OMCamera* cam) {
    if (cam->flags & CAMERA_FLAG_4) {
        gtlCombineAllDLists();
    }

    if (cam->flags & CAMERA_FLAG_10) {
        gtlProcessAllDLists();
        gtlReset();
    }

    if (cam->flags & CAMERA_FLAG_40) {
        gtlProcessAllDLists();
    }
}

void ren_func_80019158(GObj* obj, Gfx** gfx, s32 arg2) {
    OMCamera* cam = obj->data.cam;

    renInitCamera(gfx, cam, arg2);
    renPrepareCameraMatrix(gfx, cam);
    renCameraPreRender(cam, arg2);
    renCameraRenderObjects(obj, (cam->flags & CAMERA_FLAG_8) ? 1 : 0);
    renCameraPostRender(cam);
}

void ren_func_800191D8(GObj* obj) {
    ren_func_80019158(obj, &gMainGfxPos[0], 0);
}

void ren_func_80019200(GObj* obj) {
    ren_func_80019158(obj, &gMainGfxPos[1], 1);
}

void ren_func_80019228(GObj* obj) {
    ren_func_80019158(obj, &gMainGfxPos[2], 2);
}

void ren_func_80019250(GObj* obj) {
    ren_func_80019158(obj, &gMainGfxPos[3], 3);
}

void ren_func_80019278(void) {
    OMCamera* cam = omCurrentCamera->data.cam;

    gtlProcessAllDLists();
    gtlReset();
    renInitCamera(&gMainGfxPos[0], cam, 0);
    renPrepareCameraMatrix(&gMainGfxPos[0], cam);
    renCameraPreRender(cam, 0);
}

void ren_func_800192DC(GObj* obj) {
    s32 i;
    OMCamera* cam = obj->data.cam;

    renInitCamera(&gMainGfxPos[0], cam, 0);
    ren_D_8004B248 = gMainGfxPos[0] + 1;
    gSPDisplayList(gMainGfxPos[0], gMainGfxPos[0] + 2);
    gMainGfxPos[0] += 2;
    renPrepareCameraMatrix(&gMainGfxPos[0], cam);
    gSPEndDisplayList(gMainGfxPos[0]++);
    gSPBranchList(ren_D_8004B248, gMainGfxPos[0]);
    renCameraPreRender(cam, 0);

    if (cam->flags & CAMERA_FLAG_20) {
        ren_func_800177D8(&gMainGfxPos[1], cam, 1);
    }

    for (i = 1; i < 4; i++) {
        if (gtlDLBuffers[gtlContextId][i].length != 0) {
            gMainGfxPos[i]++;
        }
        ren_D_8004B238[i] = gMainGfxPos[i];
    }

    renCameraRenderObjects(obj, (cam->flags & CAMERA_FLAG_8) ? true : false);

    for (i = 1; i < 4; i++) {
        Gfx* start = gMainGfxPos[i];

        if (ren_D_8004B238[i] == gMainGfxPos[i]) {
            if (gtlDLBuffers[gtlContextId][i].length != 0) {
                gMainGfxPos[i]--;
            }
        } else {
            gMainGfxPos[i]++;
            gSPDisplayList(&ren_D_8004B238[i][-1], gMainGfxPos[i]);
            if (i != 1 || !(cam->flags & CAMERA_FLAG_20)) {
                ren_func_800177D8(&gMainGfxPos[i], cam, i);
            }
            gSPDisplayList(gMainGfxPos[i]++, ren_D_8004B248 + 1);
            renCameraPreRender(cam, i);
            gSPEndDisplayList(gMainGfxPos[i]++);
            gSPBranchList(start, gMainGfxPos[i]);
        }
    }

    renCameraPostRender(cam);
}

void ren_func_80019588(void) {
    s32 i;
    OMCamera* cam = omCurrentCamera->data.cam;
    Gfx* start;
    Gfx** new_var = gMainGfxPos;

    for (i = 1; i < 4; i++) {
        start = new_var[i];

        if (ren_D_8004B238[i] == gMainGfxPos[i]) {
            gMainGfxPos[i]--;
        } else {
            gMainGfxPos[i]++;
            gSPDisplayList(&ren_D_8004B238[i][-1], gMainGfxPos[i]);
            ren_func_800177D8(&gMainGfxPos[i], cam, i);
            gSPDisplayList(gMainGfxPos[i]++, ren_D_8004B248 + 1);
            renCameraPreRender(cam, i);
            gSPEndDisplayList(gMainGfxPos[i]++);
            gSPBranchList(start, gMainGfxPos[i]);
        }
    }

    gtlProcessAllDLists();
    gtlReset();
    renInitCamera(&gMainGfxPos[0], cam, 0);
    ren_D_8004B248 = gMainGfxPos[0] + 1;
    gSPDisplayList(gMainGfxPos[0], gMainGfxPos[0] + 2);
    gMainGfxPos[0] += 2;
    renPrepareCameraMatrix(&gMainGfxPos[0], cam);
    gSPEndDisplayList(gMainGfxPos[0]++);
    gSPBranchList(ren_D_8004B248, gMainGfxPos[0]);
    renCameraPreRender(cam, 0);

    for (i = 1; i < 4; i++) {
        ren_D_8004B238[i] = ++gMainGfxPos[i];
    }
}

void renSpriteCameraRender(GObj* obj) {
    OMCamera* cam;
    UNUSED u32 pad;
    s32 xmin, ymin, xmax, ymax;

    cam = obj->data.cam;

    xmin = cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4;
    ymin = cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4;
    xmax = cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4;
    ymax = cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4;

    if (xmin < viScreenWidth / SCREEN_WIDTH * renCameraScisLeft) {
        xmin = viScreenWidth / SCREEN_WIDTH * renCameraScisLeft;
    }
    if (ymin < viScreenHeight / SCREEN_HEIGHT * renCameraScisTop) {
        ymin = viScreenHeight / SCREEN_HEIGHT * renCameraScisTop;
    }
    if (xmax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * renCameraScisRight) {
        xmax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * renCameraScisRight;
    }
    if (ymax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * renCameraScisBottom) {
        ymax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * renCameraScisBottom;
    }

    renInitCamera(&gMainGfxPos[0], cam, 0);
    spInit(&gMainGfxPos[0]);
    spScissor(xmin, xmax, ymin, ymax);
    renCameraRenderObjects(obj, (cam->flags & CAMERA_FLAG_8) ? true : false);
    spFinish(&gMainGfxPos[0]);
    gMainGfxPos[0]--;
    gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_PERSP);
}
