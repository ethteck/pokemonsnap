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

typedef struct DObjUnk50_3 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Gfx* unk_04;
} DObjUnk50_3; // size = 0x08

typedef struct DObjUnk50_5 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ DObjUnk50_3* unk_04;
} DObjUnk50_5; // size = 0x08

typedef struct DObjUnk50_4 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ Gfx* unk_04;
} DObjUnk50_4; // size = 0x08

typedef struct DObjUnk50_1 {
    /* 0x00 */ Gfx* unk_00;
    /* 0x04 */ Gfx* unk_04;
} DObjUnk50_1; // size = 0x08

typedef struct DObjUnk50_2 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Gfx* unk_04;
    /* 0x08 */ Gfx* unk_08;
} DObjUnk50_2; // size = 0x0C

// data
s32 D_80040F30 = 0;
s32 D_80040F34 = 0;
s32 D_80040F38 = 0;
s32 D_80040F3C = 0;

// bss
Mtx* sProjectionMatrix;
f32 sScaleX;
Mtx4f sPerspectiveMatrixF;
Mtx4f sMvpMatrixF;
Mtx4f _D_8004AFA8;
Mtx4f _D_8004AFE8;
s32 _D_8004B028;
f32 sScaleY;
f32 sScaleZ;
s32 sIsScaleMtxPushed;
Struct_8004B038* sCustomMatrixHandler;
Gfx* _D_8004B03C;
Gfx* _D_8004B040[4];
Gfx _D_8004B050[60];
s32 sLevelOfDetail;
Gfx* _D_8004B238[4];
Gfx* _D_8004B248;

void func_80011230(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_80040F30 = arg0;
    D_80040F34 = arg1;
    D_80040F38 = arg2;
    D_80040F3C = arg3;
}

void func_80011254(Struct_8004B038* arg0) {
    sCustomMatrixHandler = arg0;
}

void func_80011260(void) {
}

void func_80011268(Mtx* arg0, DObj* arg1, s32 arg2) {
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

void func_80011438(Mtx* arg0, DObj* arg1, s32 arg2) {
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

void func_80011608(Mtx* arg0, DObj* arg1, s32 arg2) {
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

s32 func_80011890(Gfx** gfxPtr, DObj* dobj) {
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

    if (dobj->unk4C != NULL) {
        csr = (uintptr_t)dobj->unk4C->data;
        for (i = 0; i < 3; i++) {
            switch (dobj->unk4C->kinds[i]) {
                case 0:
                    break;
                case 1:
                    sp2C8 = (void*)csr;
                    csr += sizeof(union Mtx3fi);
                    break;
                case 2:
                    sp2C4 = (void*)csr;
                    csr += sizeof(struct Mtx4Float);
                    break;
                case 3:
                    sp2C0 = (void*)csr;
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

            unk = &ommtx->unk08;
            mtx = &ommtx->unk08;

            if (ommtx->unk05 != 2) {
                if (ommtx->unk05 == 4) {
                    if (dobj->obj->lastDrawFrame != (u8)gtlDrawnFrameCounter) {
                        *unk = gtlCurrentGfxHeap.ptr;
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
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
                                gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                break;
                            default:
                                if (ommtx->kind >= MTX_TYPE_66) {
                                    mtx = gtlCurrentGfxHeap.ptr;
                                    gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
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
                        gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    } else if (dobj->obj->lastDrawFrame == (u8)gtlDrawnFrameCounter) {
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
                                gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                break;
                            default:
                                if (ommtx->kind >= MTX_TYPE_66) {
                                    mtx = gtlCurrentGfxHeap.ptr;
                                    gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                                } else {
                                    if (ommtx->unk05 != 3) {
                                        goto END2;
                                    }
                                    mtx = gtlCurrentGfxHeap.ptr;
                                    gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
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
                        sScaleX *= dobj->scale.v.x;
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
                        sScaleX *= dobj->scale.v.x;
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
                        sScaleX *= dobj->scale.v.x;
                        break;
                    case MTX_TYPE_SCALE:
                        hal_scale(mtx, dobj->scale.v.x, dobj->scale.v.y, dobj->scale.v.z);
                        sScaleX *= dobj->scale.v.x;
                        break;
                    case MTX_TYPE_33:
                        func_80011608(mtx, dobj, FALSE);
                        break;
                    case MTX_TYPE_34:
                        func_80011608(mtx, dobj, TRUE);
                        break;
                    case MTX_TYPE_35:
                        func_80011268(mtx, dobj, FALSE);
                        break;
                    case MTX_TYPE_36:
                        func_80011268(mtx, dobj, TRUE);
                        break;
                    case MTX_TYPE_37:
                        func_8001174C(mtx, dobj, FALSE);
                        break;
                    case MTX_TYPE_38:
                        func_8001174C(mtx, dobj, TRUE);
                        break;
                    case MTX_TYPE_39:
                        func_80011438(mtx, dobj, FALSE);
                        break;
                    case MTX_TYPE_40:
                        func_80011438(mtx, dobj, TRUE);
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
                        sScaleX *= sp2C0->v.x;
                        sScaleY *= sp2C0->v.y;
                        sScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_60:
                        hal_rotate_translate(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[0], sp2C4->f[1],
                                             sp2C4->f[2], sp2C4->f[3]);
                        break;
                    case MTX_TYPE_61:
                        hal_rotate_translate_scale(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[0],
                                                   sp2C4->f[1], sp2C4->f[2], sp2C4->f[3], sp2C0->v.x, sp2C0->v.y,
                                                   sp2C0->v.z);
                        sScaleX *= sp2C0->v.x;
                        sScaleY *= sp2C0->v.y;
                        sScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_62:
                        hal_rotate_rpy_translate(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[1],
                                                 sp2C4->f[2], sp2C4->f[3]);
                        break;
                    case MTX_TYPE_63:
                        hal_rotate_rpy_translate_scale(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[1],
                                                       sp2C4->f[2], sp2C4->f[3], sp2C0->v.x, sp2C0->v.y, sp2C0->v.z);
                        sScaleX *= sp2C0->v.x;
                        sScaleY *= sp2C0->v.y;
                        sScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_41:
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, sProjectionMatrix->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, sProjectionMatrix->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, sProjectionMatrix->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, sProjectionMatrix->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, sProjectionMatrix->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, sProjectionMatrix->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, sProjectionMatrix->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, sProjectionMatrix->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, sProjectionMatrix->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, sProjectionMatrix->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, sProjectionMatrix->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, sProjectionMatrix->m[3][1]);
                        continue;
                    case MTX_TYPE_42:
                        gSPMvpRecalc(sp2DC++);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_I, sProjectionMatrix->m[0][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_I, sProjectionMatrix->m[0][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_I, sProjectionMatrix->m[0][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_I, sProjectionMatrix->m[0][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_I, sProjectionMatrix->m[1][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_I, sProjectionMatrix->m[1][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XX_XY_F, sProjectionMatrix->m[2][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_XZ_XW_F, sProjectionMatrix->m[2][1]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YX_YY_F, sProjectionMatrix->m[2][2]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_YZ_YW_F, sProjectionMatrix->m[2][3]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZX_ZY_F, sProjectionMatrix->m[3][0]);
                        gMoveWd(sp2DC++, G_MW_MATRIX, G_MWO_MATRIX_ZZ_ZW_F, sProjectionMatrix->m[3][1]);
                        continue;
                    case MTX_TYPE_43:
                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;
                        sMvpMatrixF[0][0] = sPerspectiveMatrixF[0][0] * sScaleX;
                        sMvpMatrixF[0][1] = 0.0f;
                        sMvpMatrixF[0][2] = 0.0f;
                        sMvpMatrixF[0][3] = 0.0f;
                        sMvpMatrixF[1][0] = 0.0f;
                        sMvpMatrixF[1][1] = sPerspectiveMatrixF[1][1] * f12;
                        sMvpMatrixF[1][2] = 0.0f;
                        sMvpMatrixF[1][3] = 0.0f;
                        sMvpMatrixF[2][0] = 0.0f;
                        sMvpMatrixF[2][1] = 0.0f;
                        sMvpMatrixF[2][2] = sPerspectiveMatrixF[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = sPerspectiveMatrixF[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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
                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;
                        sMvpMatrixF[0][0] = sPerspectiveMatrixF[0][0] * sScaleX;
                        sMvpMatrixF[0][1] = 0.0f;
                        sMvpMatrixF[0][2] = 0.0f;
                        sMvpMatrixF[0][3] = 0.0f;
                        sMvpMatrixF[1][0] = 0.0f;
                        sMvpMatrixF[1][1] = sPerspectiveMatrixF[1][1] * f12;
                        sMvpMatrixF[1][2] = 0.0f;
                        sMvpMatrixF[1][3] = 0.0f;
                        sMvpMatrixF[2][0] = 0.0f;
                        sMvpMatrixF[2][1] = 0.0f;
                        sMvpMatrixF[2][2] = sPerspectiveMatrixF[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = sPerspectiveMatrixF[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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

                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;
                        sMvpMatrixF[0][0] = sPerspectiveMatrixF[0][0] * sScaleX * f0;
                        sMvpMatrixF[1][0] = sPerspectiveMatrixF[0][0] * sScaleX * -sp1D4;
                        sMvpMatrixF[0][1] = sPerspectiveMatrixF[1][1] * f12 * sp1D4;
                        sMvpMatrixF[1][1] = sPerspectiveMatrixF[1][1] * f12 * f0;
                        sMvpMatrixF[0][2] = 0.0f;
                        sMvpMatrixF[1][2] = 0.0f;
                        sMvpMatrixF[0][3] = 0.0f;
                        sMvpMatrixF[1][3] = 0.0f;
                        sMvpMatrixF[2][0] = 0.0f;
                        sMvpMatrixF[2][1] = 0.0f;
                        sMvpMatrixF[2][2] = sPerspectiveMatrixF[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = sPerspectiveMatrixF[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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

                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;

                        sMvpMatrixF[0][0] = sPerspectiveMatrixF[0][0] * sScaleX * f0;
                        sMvpMatrixF[1][0] = sPerspectiveMatrixF[0][0] * sScaleX * -sp1D4;
                        sMvpMatrixF[0][1] = sPerspectiveMatrixF[1][1] * f12 * sp1D4;
                        sMvpMatrixF[1][1] = sPerspectiveMatrixF[1][1] * f12 * f0;
                        sMvpMatrixF[0][2] = 0.0f;
                        sMvpMatrixF[1][2] = 0.0f;
                        sMvpMatrixF[0][3] = 0.0f;
                        sMvpMatrixF[1][3] = 0.0f;
                        sMvpMatrixF[2][0] = 0.0f;
                        sMvpMatrixF[2][1] = 0.0f;
                        sMvpMatrixF[2][2] = sPerspectiveMatrixF[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = sPerspectiveMatrixF[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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
                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;
                        sMvpMatrixF[0][0] = _D_8004AFA8[0][0] * sScaleX;
                        sMvpMatrixF[0][1] = _D_8004AFA8[0][1] * sScaleX;
                        sMvpMatrixF[0][2] = _D_8004AFA8[0][2] * sScaleX;
                        sMvpMatrixF[0][3] = _D_8004AFA8[0][3] * sScaleX;
                        sMvpMatrixF[1][0] = _D_8004AFA8[1][0] * f12;
                        sMvpMatrixF[1][1] = _D_8004AFA8[1][1] * f12;
                        sMvpMatrixF[1][2] = _D_8004AFA8[1][2] * f12;
                        sMvpMatrixF[1][3] = _D_8004AFA8[1][3] * f12;
                        sMvpMatrixF[2][0] = _D_8004AFA8[2][0] * sScaleX;
                        sMvpMatrixF[2][1] = _D_8004AFA8[2][1] * sScaleX;
                        sMvpMatrixF[2][2] = _D_8004AFA8[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = _D_8004AFA8[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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
                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;
                        sMvpMatrixF[0][0] = _D_8004AFA8[0][0] * sScaleX;
                        sMvpMatrixF[0][1] = _D_8004AFA8[0][1] * sScaleX;
                        sMvpMatrixF[0][2] = _D_8004AFA8[0][2] * sScaleX;
                        sMvpMatrixF[0][3] = _D_8004AFA8[0][3] * sScaleX;
                        sMvpMatrixF[1][0] = _D_8004AFA8[1][0] * f12;
                        sMvpMatrixF[1][1] = _D_8004AFA8[1][1] * f12;
                        sMvpMatrixF[1][2] = _D_8004AFA8[1][2] * f12;
                        sMvpMatrixF[1][3] = _D_8004AFA8[1][3] * f12;
                        sMvpMatrixF[2][0] = _D_8004AFA8[2][0] * sScaleX;
                        sMvpMatrixF[2][1] = _D_8004AFA8[2][1] * sScaleX;
                        sMvpMatrixF[2][2] = _D_8004AFA8[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = _D_8004AFA8[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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
                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;
                        sMvpMatrixF[0][0] = _D_8004AFE8[0][0] * sScaleX;
                        sMvpMatrixF[0][1] = _D_8004AFE8[0][1] * sScaleX;
                        sMvpMatrixF[0][2] = _D_8004AFE8[0][2] * sScaleX;
                        sMvpMatrixF[0][3] = _D_8004AFE8[0][3] * sScaleX;
                        sMvpMatrixF[1][0] = _D_8004AFE8[1][0] * f12;
                        sMvpMatrixF[1][1] = _D_8004AFE8[1][1] * f12;
                        sMvpMatrixF[1][2] = _D_8004AFE8[1][2] * f12;
                        sMvpMatrixF[1][3] = _D_8004AFE8[1][3] * f12;
                        sMvpMatrixF[2][0] = _D_8004AFE8[2][0] * sScaleX;
                        sMvpMatrixF[2][1] = _D_8004AFE8[2][1] * sScaleX;
                        sMvpMatrixF[2][2] = _D_8004AFE8[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = _D_8004AFE8[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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
                        f12 = dobj->scale.v.y * sScaleX;
                        sScaleX *= dobj->scale.v.x;
                        sMvpMatrixF[0][0] = _D_8004AFE8[0][0] * sScaleX;
                        sMvpMatrixF[0][1] = _D_8004AFE8[0][1] * sScaleX;
                        sMvpMatrixF[0][2] = _D_8004AFE8[0][2] * sScaleX;
                        sMvpMatrixF[0][3] = _D_8004AFE8[0][3] * sScaleX;
                        sMvpMatrixF[1][0] = _D_8004AFE8[1][0] * f12;
                        sMvpMatrixF[1][1] = _D_8004AFE8[1][1] * f12;
                        sMvpMatrixF[1][2] = _D_8004AFE8[1][2] * f12;
                        sMvpMatrixF[1][3] = _D_8004AFE8[1][3] * f12;
                        sMvpMatrixF[2][0] = _D_8004AFE8[2][0] * sScaleX;
                        sMvpMatrixF[2][1] = _D_8004AFE8[2][1] * sScaleX;
                        sMvpMatrixF[2][2] = _D_8004AFE8[2][2] * sScaleX;
                        sMvpMatrixF[2][3] = _D_8004AFE8[2][3] * sScaleX;
                        hal_mtx_f2l(sMvpMatrixF, mtx);
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
                        hal_rotate_rpy_translate(mtx, dobj->position.v.x * sScaleX, dobj->position.v.y * sScaleY,
                                                 dobj->position.v.z * sScaleZ, dobj->rotation.f[1], dobj->rotation.f[2],
                                                 dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_52:
                        hal_rotate_pyr_translate(mtx, dobj->position.v.x * sScaleX, dobj->position.v.y * sScaleY,
                                                 dobj->position.v.z * sScaleZ, dobj->rotation.f[1], dobj->rotation.f[2],
                                                 dobj->rotation.f[3]);
                        break;
                    case MTX_TYPE_53:
                        sScaleX *= dobj->scale.v.x;
                        sScaleY *= dobj->scale.v.y;
                        sScaleZ *= dobj->scale.v.z;
                        hal_scale(mtx, sScaleX, sScaleY, sScaleZ);
                        sIsScaleMtxPushed = TRUE;
                        sp2B8 = 2;
                        break;
                    case MTX_TYPE_55:
                        hal_translate(mtx, dobj->position.v.x * sScaleX, dobj->position.v.y * sScaleY,
                                      dobj->position.v.z * sScaleZ);
                        break;
                    case MTX_TYPE_64:
                        sScaleX *= sp2C0->v.x;
                        sScaleY *= sp2C0->v.y;
                        sScaleZ *= sp2C0->v.z;
                        continue;
                    case MTX_TYPE_65:
                        hal_rotate_translate(mtx, sp2C8->f.v.x, sp2C8->f.v.y, sp2C8->f.v.z, sp2C4->f[0], sp2C4->f[1],
                                             sp2C4->f[2], sp2C4->f[3]);
                        sScaleX *= sp2C0->v.x;
                        sScaleY *= sp2C0->v.y;
                        sScaleZ *= sp2C0->v.z;
                        break;
                    case MTX_TYPE_54:
                        func_8001ECD0(mtx, dobj->position.v.x, dobj->position.v.y, dobj->position.v.z,
                                      dobj->rotation.f[1], dobj->rotation.f[2], dobj->rotation.f[3], sScaleX, sScaleY,
                                      sScaleZ, dobj->scale.v.x, dobj->scale.v.y, dobj->scale.v.z);
                        sScaleX *= dobj->scale.v.x;
                        sScaleY *= dobj->scale.v.y;
                        sScaleZ *= dobj->scale.v.z;
                        break;
                    default:
                        if (ommtx->kind >= MTX_TYPE_66 && sCustomMatrixHandler != NULL) {
                            func = dobj->obj->lastDrawFrame != (u8)gtlDrawnFrameCounter
                                       ? sCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_00
                                       : sCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_04;
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
                if (sp2B8 == 2 || sp2D4 == 0 && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
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

s32 func_80013C5C(Gfx** gfxPtr, DObj* dobj) {
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

            unk = &ommtx->unk08;
            mtx = &ommtx->unk08;

            if (ommtx->unk05 != 2) {
                if (ommtx->unk05 == 4) {
                    if (dobj->obj->lastDrawFrame != (u8)gtlDrawnFrameCounter) {
                        *unk = gtlCurrentGfxHeap.ptr;
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    } else {
                        mtx = *unk;
                        goto END;
                    }
                } else {
                    if (gtlContextId > 0) {
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    } else if (dobj->obj->lastDrawFrame == (u8)gtlDrawnFrameCounter) {
                        if (ommtx->unk05 != 3) {
                            goto END;
                        }
                        mtx = gtlCurrentGfxHeap.ptr;
                        gtlCurrentGfxHeap.ptr = (u8*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                    }
                }
                hal_scale(mtx, sScaleX, sScaleY, sScaleZ);
                sIsScaleMtxPushed = TRUE;
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
void func_80013E2C(DObj* dobj, Gfx** gfxPtr) {
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

    gfxPos = &((Gfx*)gtlCurrentGfxHeap.ptr)[count];
    baseDl = gtlCurrentGfxHeap.ptr;

    for (i = 0; i < count; i++) {
        flags = mobj->texture.flags;
        if (flags == 0) {
            flags = 0x80 | 0x20 | 0x01;
        }

        if (flags & (0x80 | 0x40 | 0x20)) {
            scaleS = mobj->texture.scaleS;
            scaleT = mobj->texture.scaleT;
            spD4 = mobj->texture.unk14;
            spD0 = mobj->texture.unk18;
            spCC = mobj->texture.unk3C;
            spC8 = mobj->texture.unk40;
            if (mobj->texture.unk10) {
                scaleS *= 0.5f;
                spD4 = (spD4 - mobj->texture.unk24 + 1.0f - mobj->texture.unk28 * 0.5f) * 0.5f;
                spCC = (spCC - mobj->texture.unk44 + 1.0f - mobj->texture.unk28 * 0.5f) * 0.5f;
            }
        }

        gSPBranchList(baseDl, gfxPos);

        if (flags & 0x04) {
            // load palette
            gDPSetTextureImage(gfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1,
                               mobj->texture.palettes[(s32)mobj->paletteIndex]);
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
                s32 lodLevelInt = (s32)mobj->lodLevel;
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
            s32 loadBlockSiz = mobj->texture.unk33 == G_IM_SIZ_32b ? G_IM_SIZ_32b : G_IM_SIZ_16b;
            gDPSetTextureImage(gfxPos++, mobj->texture.unk32, loadBlockSiz, 1,
                               mobj->texture.images[mobj->nextImageIndex]);
            if (flags & (0x10 | 0x1)) {
                gDPLoadSync(gfxPos++);
                switch (mobj->texture.unk33) {
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
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013E2C.s")
void func_80013E2C(DObj* dobj, Gfx** gfxPtr);
#endif

void func_80014C28(GObj* gobj, Gfx** gfxPtr) {
    s32 ret;
    DObj* dobj;

    dobj = gobj->data.dobj;

    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;

    if (dobj->unk50 != NULL) {
        if (dobj->flags == 0) {
            ret = func_80011890(gfxPtr, dobj);
            func_80013E2C(dobj, gfxPtr);
            gSPDisplayList((*gfxPtr)++, dobj->unk50);

            if (sIsScaleMtxPushed) {
                gSPPopMatrix((*gfxPtr)++, G_MTX_MODELVIEW);
            }
            sIsScaleMtxPushed = FALSE;

            if (ret != 0 && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix((*gfxPtr)++, G_MTX_MODELVIEW);
            }
        }
    }
}

void func_80014D60(GObj* gobj) {
    func_80014C28(gobj, &gMainGfxPos[0]);
}

void func_80014D84(GObj* gobj) {
    func_80014C28(gobj, &gMainGfxPos[1]);
}

void func_80014DA8(GObj* gobj) {
    func_80014C28(gobj, &gMainGfxPos[2]);
}

void func_80014DCC(GObj* gobj) {
    func_80014C28(gobj, &gMainGfxPos[3]);
}

void func_80014DF0(DObj* dobj) {
    s32 ret;
    DObj* curr;
    f32 sp2C;
    f32 sp28;
    f32 sp24;

    if (!(dobj->flags & 2)) {
        sp2C = sScaleX;
        sp28 = sScaleY;
        sp24 = sScaleZ;
        ret = func_80011890(&gMainGfxPos[0], dobj);

        if (dobj->unk50 != NULL && !(dobj->flags & 1)) {
            func_80013E2C(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, dobj->unk50);
        }

        if (sIsScaleMtxPushed) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }
        sIsScaleMtxPushed = FALSE;

        if (dobj->firstChild != NULL) {
            func_80014DF0(dobj->firstChild);
        }

        if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }
        sScaleX = sp2C;
        sScaleY = sp28;
        sScaleZ = sp24;
    }

    if (dobj->prev == NULL) {
        curr = dobj->next;
        while (curr != NULL) {
            func_80014DF0(curr);
            curr = curr->next;
        }
    }
}

void func_80014F98(GObj* arg0) {
    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;
    func_80014DF0(arg0->data.any); // TODO object type
}

void func_80014FF0(DObj* dobj, DObjUnk50_3* arg1) {
    Gfx* temp;
    s32 sp30 = -1;
    Gfx* t1;
    Gfx* t0;
    s32 ret;
    void* segaddr;

    if (arg1 == NULL || dobj->flags) {
        return;
    }

    t1 = gMainGfxPos[arg1->unk_00];
    ret = func_80011890(&gMainGfxPos[arg1->unk_00], dobj);
    t0 = gMainGfxPos[arg1->unk_00];

    if (arg1->unk_04 != NULL) {
        segaddr = gtlCurrentGfxHeap.ptr;
        func_80013E2C(dobj, &gMainGfxPos[arg1->unk_00]);
        gSPDisplayList(gMainGfxPos[arg1->unk_00]++, arg1->unk_04);

        if (sIsScaleMtxPushed) {
            gSPPopMatrix(gMainGfxPos[arg1->unk_00]++, G_MTX_MODELVIEW);
        }

        if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[arg1->unk_00]++, G_MTX_MODELVIEW);
        }
    } else {
        sp30 = arg1->unk_00;
    }

    arg1++;

    while (arg1->unk_00 != 4) {
        if (arg1->unk_04 != NULL) {
            temp = t1;
            while (temp != t0) {
                *gMainGfxPos[arg1->unk_00]++ = *temp++;
            }

            if (dobj->mobjList != NULL) {
                goto DUMMY_LABEL;
            DUMMY_LABEL:; // TODO find better match
                gSPSegment(gMainGfxPos[arg1->unk_00]++, 0x0E, segaddr);
            }
            gSPDisplayList(gMainGfxPos[arg1->unk_00]++, arg1->unk_04);

            if (sIsScaleMtxPushed) {
                gSPPopMatrix(gMainGfxPos[arg1->unk_00]++, G_MTX_MODELVIEW);
            }
            sIsScaleMtxPushed = FALSE;

            if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[arg1->unk_00]++, G_MTX_MODELVIEW);
            }
        }
        arg1++;
    }

    if (sp30 != -1) {
        gMainGfxPos[sp30] = t1;
    }
}

void func_800153EC(GObj* obj) {
    DObj* dobj;

    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;
    dobj = obj->data.dobj;
    func_80014FF0(dobj, dobj->unk50);
}

#ifdef NON_MATCHING
void func_80015448(void) {
    s32 i;

    _D_8004B03C = _D_8004B050;

    for (i = 0; i < 4; i++) {
        _D_8004B040[i] = _D_8004B050;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80015448.s")
void func_80015448(void);
#endif

void func_80015474(DObj* dobj) {
    void* segaddr = NULL;
    s32 sp50;
    DObjUnk50_3* unk_50;
    Gfx* sp48;
    s32 i;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp3C = sScaleX;
        f32 sp38 = sScaleY;
        f32 sp34 = sScaleZ;

        unk_50 = dobj->unk50;
        sp48 = _D_8004B03C;
        sp50 = func_80011890(&_D_8004B03C, dobj);

        if (unk_50 != NULL && !(dobj->flags & 1)) {
            while (unk_50->unk_00 != 4) {
                if (unk_50->unk_04 != 0) {
                    while (_D_8004B040[unk_50->unk_00] != _D_8004B03C) {
                        *gMainGfxPos[unk_50->unk_00]++ = *_D_8004B040[unk_50->unk_00]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            func_80013E2C(dobj, &gMainGfxPos[unk_50->unk_00]);
                        } else {
                            gSPSegment(gMainGfxPos[unk_50->unk_00]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[unk_50->unk_00]++, unk_50->unk_04);
                }

                if (sIsScaleMtxPushed) {
                    gSPPopMatrix(gMainGfxPos[unk_50->unk_00]++, G_MTX_MODELVIEW);
                }
                unk_50++;
            }
        }

        if (dobj->firstChild != NULL) {
            if (sIsScaleMtxPushed) {
                for (i = 0; i < 4; i++) {
                    if (_D_8004B040[i] == _D_8004B03C) {
                        _D_8004B040[i]--;
                    }
                }
                _D_8004B03C--;
            }
            sIsScaleMtxPushed = FALSE;
            func_80015474(dobj->firstChild);
        }

        sIsScaleMtxPushed = FALSE;
        _D_8004B03C = sp48;

        for (i = 0; i < 4; i++) {
            if (_D_8004B040[i] > _D_8004B03C) {
                _D_8004B040[i] = _D_8004B03C;
                if (sp50 && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
            do { } while (0); }

        sScaleX = sp3C;
        sScaleY = sp38;
        sScaleZ = sp34;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            func_80015474(curr);
            curr = curr->next;
        }
    }
}

void func_80015890(GObj* arg0) {
    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;
    func_80015474(arg0->data.any); // TODO objet type ?
}

f32 func_800158E8(DObj* arg) {
    f32 x, y, z;
    OMCamera* cam = omCurrentCamera->data.cam;

    x = arg->position.v.x - cam->viewMtx.lookAt.eye.x;
    y = arg->position.v.y - cam->viewMtx.lookAt.eye.y;
    z = arg->position.v.z - cam->viewMtx.lookAt.eye.z;

    return SQ(x) + SQ(y) + SQ(z);
}

void func_80015930(GObj* obj) {
    DObjUnk50_4* unk_50;
    s32 ret;
    DObj* dobj;

    dobj = obj->data.dobj;
    unk_50 = dobj->unk50;

    if (unk_50 != NULL && !(dobj->flags)) {
        f32 dist = func_800158E8(dobj);

        while (unk_50->unk_00 > dist) {
            unk_50++;
        }

        sScaleX = sScaleY = sScaleZ = 1.0f;
        sIsScaleMtxPushed = FALSE;

        if (unk_50->unk_04 != NULL) {
            ret = func_80011890(&gMainGfxPos[0], dobj);
            func_80013E2C(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, unk_50->unk_04);
            if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }
        }
    }
}

void func_80015A84(DObj* dobj) {
    s32 ret;
    Gfx** unk_50 = dobj->unk50;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp20 = sScaleX;

        ret = func_80011890(&gMainGfxPos[0], dobj);
        if (unk_50 != NULL && unk_50[sLevelOfDetail] != NULL && !(dobj->flags & 1)) {
            func_80013E2C(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, unk_50[sLevelOfDetail]);
        }

        if (dobj->firstChild != NULL) {
            func_80015A84(dobj->firstChild);
        }

        if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }

        sScaleX = sp20;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            func_80015A84(curr);
            curr = curr->next;
        }
    }
}

void func_80015BFC(GObj* obj) {
    DObjUnk50_4* unk_50;
    s32 ret;
    UNUSED s32 temp;
    DObj* dobj = obj->data.dobj;

    if (1) {} // required to match
    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;

    if (!(dobj->flags & 2)) {
        unk_50 = dobj->unk50;
        if (unk_50 != NULL) {
            f32 dist;

            sLevelOfDetail = 0;
            dist = func_800158E8(dobj);
            while (unk_50->unk_00 > dist) {
                unk_50++;
                sLevelOfDetail++;
            }

            ret = func_80011890(&gMainGfxPos[0], dobj);
            if (unk_50->unk_04 != NULL && !(dobj->flags & 1)) {
                func_80013E2C(dobj, &gMainGfxPos[0]);
                gSPDisplayList(gMainGfxPos[0]++, unk_50->unk_04);
            }

            if (dobj->firstChild != NULL) {
                func_80015A84(dobj->firstChild);
            }

            if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    func_80015A84(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void func_80015DD8(GObj* obj) {
    DObjUnk50_5* unk_50;
    UNUSED s32 temp;
    DObj* dobj = obj->data.dobj;

    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;

    if (!(dobj->flags)) {
        unk_50 = dobj->unk50;
        if (unk_50 != NULL) {
            f32 dist;

            dist = func_800158E8(dobj);
            while (unk_50->unk_00 > dist) {
                unk_50++;
            }

            func_80014FF0(dobj, unk_50->unk_04);
        }
    }
}

void func_80015E98(DObj* dobj) {
    void* segaddr = NULL;
    s32 ret;
    DObjUnk50_3** unk_50;
    DObjUnk50_3* sp40;
    Gfx* sp3C;
    s32 i;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp30 = sScaleX;
        unk_50 = dobj->unk50;
        if (unk_50 != NULL) {
            sp40 = unk_50[sLevelOfDetail];
        }

        sp3C = _D_8004B03C;
        ret = func_80011890(&_D_8004B03C, dobj);

        if (unk_50 != NULL && sp40 != NULL && !(dobj->flags & 1)) {
            while (sp40->unk_00 != 4) {
                if (sp40->unk_04 != NULL) {
                    while (_D_8004B040[sp40->unk_00] != _D_8004B03C) {
                        *gMainGfxPos[sp40->unk_00]++ = *_D_8004B040[sp40->unk_00]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            func_80013E2C(dobj, &gMainGfxPos[sp40->unk_00]);
                        } else {
                            gSPSegment(gMainGfxPos[sp40->unk_00]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[sp40->unk_00]++, sp40->unk_04);
                }

                sp40++;
            }
        }

        if (dobj->firstChild != NULL) {
            func_80015E98(dobj->firstChild);
        }

        _D_8004B03C = sp3C;
        for (i = 0; i < 4; i++) {
            if (_D_8004B040[i] > _D_8004B03C) {
                _D_8004B040[i] = _D_8004B03C;
                if (dobj) {}
                if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
        }

        sScaleX = sp30;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            func_80015E98(curr);
            curr = curr->next;
        }
    }
}

void func_800161C4(GObj* obj) {
    UNUSED s32 temp[2];
    s32 ret;
    DObjUnk50_5* unk_50;
    DObj* dobj = obj->data.dobj;
    void* segaddr = NULL;
    DObjUnk50_3* sp34;
    Gfx* sp30;
    s32 i;

    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;

    if (!(dobj->flags & 2)) {
        unk_50 = dobj->unk50;
        if (unk_50 != NULL) {
            f32 dist;

            sLevelOfDetail = 0;
            dist = func_800158E8(dobj);
            while (unk_50->unk_00 > dist) {
                unk_50++;
                sLevelOfDetail++;
            }

            sp34 = unk_50->unk_04;
            sp30 = _D_8004B03C;
            ret = func_80011890(&_D_8004B03C, dobj);

            if (sp34 != NULL && !(dobj->flags & 1)) {
                while (sp34->unk_00 != 4) {
                    if (sp34->unk_04 != NULL) {
                        while (_D_8004B040[sp34->unk_00] != _D_8004B03C) {
                            *gMainGfxPos[sp34->unk_00]++ = *_D_8004B040[sp34->unk_00]++;
                        }

                        if (dobj->mobjList != NULL) {
                            if (segaddr == NULL) {
                                segaddr = gtlCurrentGfxHeap.ptr;
                                func_80013E2C(dobj, &gMainGfxPos[sp34->unk_00]);
                            } else {
                                gSPSegment(gMainGfxPos[sp34->unk_00]++, 0x0E, segaddr);
                            }
                        }

                        gSPDisplayList(gMainGfxPos[sp34->unk_00]++, sp34->unk_04);
                    }

                    sp34++;
                }
            }

            if (dobj->firstChild != NULL) {
                func_80015E98(dobj->firstChild);
            }

            _D_8004B03C = sp30;
            for (i = 0; i < 4; i++) {
                if (_D_8004B040[i] > _D_8004B03C) {
                    _D_8004B040[i] = _D_8004B03C;
                    if (dobj) {}
                    if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                        gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                    }
                }
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    func_80015E98(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void func_80016548(DObj* dobj) {
    s32 ret;
    UNUSED s32 temp;
    f32 sp2C, sp28, sp24;
    DObjUnk50_1* unk_50;

    unk_50 = dobj->unk50;

    if (!(dobj->flags & 2)) {
        sp2C = sScaleX;
        sp28 = sScaleY;
        sp24 = sScaleZ;

        if (unk_50 != NULL && unk_50->unk_00 != NULL && !(dobj->flags & 1)) {
            func_80013C5C(&gMainGfxPos[0], dobj->parent);
            gSPDisplayList(gMainGfxPos[0]++, unk_50->unk_00);
            if (sIsScaleMtxPushed) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }
            sIsScaleMtxPushed = FALSE;
        }

        ret = func_80011890(&gMainGfxPos[0], dobj);

        if (unk_50 != NULL && unk_50->unk_04 != NULL && !(dobj->flags & 1)) {
            func_80013E2C(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, unk_50->unk_04);
        }
        if (sIsScaleMtxPushed) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }
        sIsScaleMtxPushed = FALSE;

        if (dobj->firstChild != NULL) {
            func_80016548(dobj->firstChild);
        }

        if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }

        sScaleX = sp2C;
        sScaleY = sp28;
        sScaleZ = sp24;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            func_80016548(curr);
            curr = curr->next;
        }
    }
}

void func_8001679C(GObj* arg0) {
    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;
    func_80016548(arg0->data.any); // TODO object type ?
}

void func_800167F4(DObj* dobj) {
    void* segaddr = NULL;
    s32 sp60;
    s32 i;
    Gfx* sp58;
    DObjUnk50_2* unk_50;
    UNUSED s32 temp;

    if (!(dobj->flags & 2)) {
        f32 sp4C = sScaleX;
        f32 sp48 = sScaleY;
        f32 sp44 = sScaleZ;
        s32 sp40;

        unk_50 = dobj->unk50;
        sp58 = _D_8004B03C;
        sp60 = func_80011890(&_D_8004B03C, dobj);
        sp40 = sIsScaleMtxPushed;
        sIsScaleMtxPushed = FALSE;

        if (unk_50 != NULL && !(dobj->flags & 1)) {
            while (unk_50->unk_00 != 4) {
                if (unk_50->unk_08 != 0) {
                    if (unk_50->unk_04 != 0) {
                        func_80013C5C(&gMainGfxPos[unk_50->unk_00], dobj->parent);
                        gSPDisplayList(gMainGfxPos[unk_50->unk_00]++, unk_50->unk_04);
                        if (sIsScaleMtxPushed) {
                            gSPPopMatrix(gMainGfxPos[unk_50->unk_00]++, G_MTX_MODELVIEW);
                        }
                        sIsScaleMtxPushed = FALSE;
                    }

                    while (_D_8004B040[unk_50->unk_00] != _D_8004B03C) {
                        *gMainGfxPos[unk_50->unk_00]++ = *_D_8004B040[unk_50->unk_00]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            func_80013E2C(dobj, &gMainGfxPos[unk_50->unk_00]);
                        } else {
                            gSPSegment(gMainGfxPos[unk_50->unk_00]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[unk_50->unk_00]++, unk_50->unk_08);

                    if (sp40) {
                        gSPPopMatrix(gMainGfxPos[unk_50->unk_00]++, G_MTX_MODELVIEW);
                    }
                }
                unk_50++;
            }
        }

        if (dobj->firstChild != NULL) {
            if (sp40) {
                for (i = 0; i < 4; i++) {
                    if (_D_8004B040[i] == _D_8004B03C) {
                        _D_8004B040[i]--;
                    }
                }
                _D_8004B03C--;
            }
            func_800167F4(dobj->firstChild);
        }

        _D_8004B03C = sp58;

        for (i = 0; i < 4; i++) {
            if (_D_8004B040[i] > _D_8004B03C) {
                _D_8004B040[i] = _D_8004B03C;
                if (sp60 && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
        }

        sScaleX = sp4C;
        sScaleY = sp48;
        sScaleZ = sp44;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            func_800167F4(curr);
            curr = curr->next;
        }
    }
}

void func_80016C88(GObj* arg0) {
    sScaleX = sScaleY = sScaleZ = 1.0f;
    sIsScaleMtxPushed = FALSE;
    func_800167F4(arg0->data.any); // TODO object type ?
}

void func_80016CE0(DObj* dobj) {
    s32 ret;
    DObjUnk50_1** unk50 = dobj->unk50;

    if (!(dobj->flags & 2)) {
        f32 sp24 = sScaleX;
        DObjUnk50_1* sp20;

        if (unk50 != NULL) {
            sp20 = unk50[sLevelOfDetail];
        }

        if (unk50 != NULL && sp20->unk_00 != NULL && !(dobj->flags & 1)) {
            gSPDisplayList(gMainGfxPos[0]++, sp20->unk_00);
        }

        ret = func_80011890(&gMainGfxPos[0], dobj);

        if (unk50 != NULL && sp20->unk_04 != NULL && !(dobj->flags & 1)) {
            func_80013E2C(dobj, &gMainGfxPos[0]);
            gSPDisplayList(gMainGfxPos[0]++, sp20->unk_04);
        }

        if (dobj->firstChild != NULL) {
            func_80016CE0(dobj->firstChild);
        }

        if (ret != 0 && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
            gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
        }

        sScaleX = sp24;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            func_80016CE0(curr);
            curr = curr->next;
        }
    }
}

void func_80016EA8(GObj* obj) {
    DObjUnk50_4* unk50;
    s32 ret;
    f32 dist;
    DObj* dobj = obj->data.dobj;

    if (!(dobj->flags & 2)) {
        unk50 = dobj->unk50;
        if (unk50 != NULL) {
            sScaleX = sScaleY = sScaleZ = 1.0f;
            sIsScaleMtxPushed = FALSE;
            sLevelOfDetail = 0;

            dist = func_800158E8(dobj);
            while (unk50->unk_00 > dist) {
                unk50++;
                sLevelOfDetail++;
            }

            ret = func_80011890(&gMainGfxPos[0], dobj);

            if (unk50->unk_04 != NULL && !(dobj->flags & 1)) {
                func_80013E2C(dobj, &gMainGfxPos[0]);
                if (TRUE) { // required to match
                    gSPDisplayList(gMainGfxPos[0]++, unk50->unk_04);
                }
            }

            if (dobj->firstChild != NULL) {
                func_80016CE0(dobj->firstChild);
            }

            if (ret != 0 && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                gSPPopMatrix(gMainGfxPos[0]++, G_MTX_MODELVIEW);
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    func_80016CE0(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void func_80017084(DObj* dobj) {
    s32 i;
    s32 ret;
    s32 segaddr;
    DObjUnk50_2* sp40;
    Gfx* sp3C;
    DObjUnk50_2** unk50;
    UNUSED s32 temp;
    f32 sp30;

    segaddr = NULL;

    if (!(dobj->flags & 2)) {
        sp30 = sScaleX;

        unk50 = dobj->unk50;
        if (unk50 != NULL) {
            sp40 = unk50[sLevelOfDetail];
        }

        sp3C = _D_8004B03C;
        ret = func_80011890(&_D_8004B03C, dobj);

        if (unk50 != NULL && sp40 != NULL && !(dobj->flags & 1)) {
            while (sp40->unk_00 != 4) {
                if (sp40->unk_08 != NULL) {
                    if (sp40->unk_04 != NULL) {
                        gSPDisplayList(gMainGfxPos[sp40->unk_00]++, sp40->unk_04);
                    }

                    while (_D_8004B040[sp40->unk_00] != _D_8004B03C) {
                        *gMainGfxPos[sp40->unk_00]++ = *_D_8004B040[sp40->unk_00]++;
                    }

                    if (dobj->mobjList != NULL) {
                        if (segaddr == NULL) {
                            segaddr = gtlCurrentGfxHeap.ptr;
                            func_80013E2C(dobj, &gMainGfxPos[sp40->unk_00]);
                        } else {
                            gSPSegment(gMainGfxPos[sp40->unk_00]++, 0x0E, segaddr);
                        }
                    }

                    gSPDisplayList(gMainGfxPos[sp40->unk_00]++, sp40->unk_08);
                }
                sp40++;
            }
        }

        if (dobj->firstChild != NULL) {
            func_80017084(dobj->firstChild);
        }

        _D_8004B03C = sp3C;
        for (i = 0; i < 4; i++) {
            if (_D_8004B040[i] > _D_8004B03C) {
                _D_8004B040[i] = _D_8004B03C;
                if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                    gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                }
            }
        }

        sScaleX = sp30;
    }

    if (dobj->prev == NULL) {
        DObj* curr = dobj->next;
        while (curr != NULL) {
            func_80017084(curr);
            curr = curr->next;
        }
    }
}

void func_800173E4(GObj* obj) {
    DObj* dobj;
    s32 segaddr;
    s32 ret;
    DObjUnk50_5* unk50;
    f32 dist;
    s32 i;
    DObjUnk50_3* sp34;
    s32 sp30;

    dobj = obj->data.dobj;
    segaddr = 0;

    if (!(dobj->flags & 2)) {
        unk50 = dobj->unk50;
        if (unk50 != NULL) {
            sScaleX = sScaleY = sScaleZ = 1.0f;
            sIsScaleMtxPushed = FALSE;
            sLevelOfDetail = 0;

            dist = func_800158E8(dobj);
            while (unk50->unk_00 > dist) {
                unk50++;
                sLevelOfDetail++;
            }

            sp34 = unk50->unk_04;
            sp30 = _D_8004B03C;
            ret = func_80011890(&_D_8004B03C, dobj);

            if (sp34 != NULL && !(dobj->flags & 1)) {
                while (sp34->unk_00 != 4) {
                    if (sp34->unk_04 != NULL) {
                        while (_D_8004B040[sp34->unk_00] != _D_8004B03C) {
                            *gMainGfxPos[sp34->unk_00]++ = *_D_8004B040[sp34->unk_00]++;
                        }

                        if (dobj->mobjList != NULL) {
                            if (segaddr == NULL) {
                                segaddr = gtlCurrentGfxHeap.ptr;
                                func_80013E2C(dobj, &gMainGfxPos[sp34->unk_00]);
                            } else {
                                gSPSegment(gMainGfxPos[sp34->unk_00]++, 0x0E, segaddr);
                            }
                        }

                        gSPDisplayList(gMainGfxPos[sp34->unk_00]++, sp34->unk_04);
                    }
                    sp34++;
                }
            }

            if (dobj->firstChild != NULL) {
                func_80017084(dobj->firstChild);
            }

            _D_8004B03C = sp30;
            for (i = 0; i < 4; i++) {
                if (_D_8004B040[i] > _D_8004B03C) {
                    _D_8004B040[i] = _D_8004B03C;
                    if (ret && ((uintptr_t)dobj->parent == 1 || dobj->next != NULL)) {
                        gSPPopMatrix(gMainGfxPos[i]++, G_MTX_MODELVIEW);
                    }
                }
                if (!NULL) {} // required to match
            }

            if (dobj->prev == NULL) {
                DObj* curr = dobj->next;
                while (curr != NULL) {
                    func_80017084(curr);
                    curr = curr->next;
                }
            }
        }
    }
}

void draw_sprite(GObj* arg0) {
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
void func_800177D8(Gfx** gfxPtr, OMCamera* cam, s32 mode) {
    s32 xmin, ymin, xmax, ymax;
    Gfx* gfxPos;

    if ((mode == 0 || mode == 1) && (cam->flags & 0x20)) {
        gtl_load_ucode(gfxPtr, gtlD_8004A906);
        gtlD_8004A908 = TRUE;
    }
    gfxPos = *gfxPtr;

    gSPViewport(gfxPos++, &cam->vp);
    xmin = cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4;
    ymin = cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4;
    xmax = cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4;
    ymax = cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4;

    if (xmin < viScreenWidth / SCREEN_WIDTH * D_80040F38) {
        xmin = viScreenWidth / SCREEN_WIDTH * D_80040F38;
    }
    if (ymin < viScreenHeight / SCREEN_HEIGHT * D_80040F30) {
        ymin = viScreenHeight / SCREEN_HEIGHT * D_80040F30;
    }
    if (xmax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80040F3C) {
        xmax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80040F3C;
    }
    if (ymax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80040F34) {
        ymax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80040F34;
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
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_800177D8.s")
void func_800177D8(Gfx** gfxPtr, OMCamera* cam, s32 mode);
#endif

#ifdef NON_MATCHING
void camera_init(Gfx** gfxPtr, OMCamera* cam, s32 mode) {
    s32 xmin, ymin, xmax, ymax;
    Gfx* gfxPos;

    if ((mode == 0 || mode == 1) && (cam->flags & 0x20)) {
        gtl_load_ucode(gfxPtr, gtlD_8004A906);
        gtlD_8004A908 = TRUE;
    }
    gfxPos = *gfxPtr;

    gSPViewport(gfxPos++, &cam->vp);
    xmin = cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4;
    ymin = cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4;
    xmax = cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4;
    ymax = cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4;

    if (xmin < viScreenWidth / SCREEN_WIDTH * D_80040F38) {
        xmin = viScreenWidth / SCREEN_WIDTH * D_80040F38;
    }
    if (ymin < viScreenHeight / SCREEN_HEIGHT * D_80040F30) {
        ymin = viScreenHeight / SCREEN_HEIGHT * D_80040F30;
    }
    if (xmax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80040F3C) {
        xmax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80040F3C;
    }
    if (ymax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80040F34) {
        ymax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80040F34;
    }

    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE, xmin, ymin, xmax, ymax);

    xmax--;
    ymax--;

    if (cam->flags & 1) {
        gDPPipeSync(gfxPos++);
        gDPSetCycleType(gfxPos++, G_CYC_FILL);
        gDPSetRenderMode(gfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viScreenWidth, viZBuffer);
        gDPSetFillColor(gfxPos++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
        gDPFillRectangle(gfxPos++, xmin, ymin, xmax, ymax);
    }

    gDPPipeSync(gfxPos++);
    gDPSetColorImage(gfxPos++, G_IM_FMT_RGBA, viBitDepth, viScreenWidth, 0x0F000000);

    if (cam->flags & 2) {
        gDPSetCycleType(gfxPos++, G_CYC_FILL);
        gDPSetRenderMode(gfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfxPos++, func_80007910(cam->unk84));
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
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/camera_init.s")
void camera_init(Gfx** gfxPtr, OMCamera* cam, s32 mode);
#endif

#ifdef NON_MATCHING
void func_80017F84(Gfx** gfxPtr, OMCamera* cam, s32 mode, u16* buffer, s32 width, s32 height, u16* zbuffer) {
    s32 xmin, ymin, xmax, ymax;
    Gfx* gfxPos;

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

    if (cam->flags & 1) {
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

    if (cam->flags & 2) {
        gDPSetCycleType(gfxPos++, G_CYC_FILL);
        gDPSetRenderMode(gfxPos++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfxPos++, func_80007910(cam->unk84));
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
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80017F84.s")
#endif

#ifdef NON_MATCHING
void camera_prepare_matrix(Gfx** gfxPtr, OMCamera* cam) {
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
                    gtlCurrentGfxHeap.ptr = (char*)gtlCurrentGfxHeap.ptr + sizeof(Mtx);
                }

                switch (ommtx->kind) {
                    case MTX_TYPE_1:
                        break;
                    case MTX_TYPE_2:
                        break;
                    case MTX_TYPE_PERSP_FAST:
                        hal_perspective_fast_f(&sPerspectiveMatrixF, &cam->perspMtx.persp.perspNorm,
                                               cam->perspMtx.persp.fovy, cam->perspMtx.persp.aspect,
                                               cam->perspMtx.persp.near, cam->perspMtx.persp.far,
                                               cam->perspMtx.persp.scale);
                        hal_mtx_f2l(sPerspectiveMatrixF, mtx);
                        sProjectionMatrix = mtx;
                        break;
                    case MTX_TYPE_PERSP:
                        hal_perspective_f(&sPerspectiveMatrixF, &cam->perspMtx.persp.perspNorm,
                                          cam->perspMtx.persp.fovy, cam->perspMtx.persp.aspect,
                                          cam->perspMtx.persp.near, cam->perspMtx.persp.far, cam->perspMtx.persp.scale);
                        hal_mtx_f2l(sPerspectiveMatrixF, mtx);
                        sProjectionMatrix = mtx;
                        break;
                    case MTX_TYPE_ORTHO:
                        hal_ortho(mtx, cam->perspMtx.ortho.l, cam->perspMtx.ortho.r, cam->perspMtx.ortho.b,
                                  cam->perspMtx.ortho.t, cam->perspMtx.ortho.n, cam->perspMtx.ortho.f,
                                  cam->perspMtx.ortho.scale);
                        sProjectionMatrix = mtx;
                        break;
                    case MTX_TYPE_LOOKAT:
                    case MTX_TYPE_LOOKAT_MVIEW:
                        hal_look_at(mtx, cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y, cam->viewMtx.lookAt.eye.z,
                                    cam->viewMtx.lookAt.xAt, cam->viewMtx.lookAt.yAt, cam->viewMtx.lookAt.zAt,
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
                                         cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.xAt,
                                         cam->viewMtx.lookAtRoll.yAt, cam->viewMtx.lookAtRoll.zAt,
                                         cam->viewMtx.lookAtRoll.roll, 0.0f, 1.0f, 0.0f);
                        s3 = 1;
                        break;
                    case MTX_TYPE_LOOKAT_ROLL_Z:
                    case MTX_TYPE_LOOKAT_ROLL_Z_MVIEW:
                        hal_look_at_roll(mtx, cam->viewMtx.lookAtRoll.eye.x, cam->viewMtx.lookAtRoll.eye.y,
                                         cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.xAt,
                                         cam->viewMtx.lookAtRoll.yAt, cam->viewMtx.lookAtRoll.zAt,
                                         cam->viewMtx.lookAtRoll.roll, 0.0f, 0.0f, 1.0f);
                        s3 = 2;
                        break;
                    case MTX_TYPE_LOOKAT_REFLECT:
                    case MTX_TYPE_LOOKAT_REFLECT_MVIEW:
                        lookat = bump_alloc(&gtlCurrentGfxHeap, sizeof(LookAt), 8);
                        hal_look_at_reflect(mtx, lookat, cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y,
                                            cam->viewMtx.lookAt.eye.z, cam->viewMtx.lookAt.xAt, cam->viewMtx.lookAt.yAt,
                                            cam->viewMtx.lookAt.zAt, cam->viewMtx.lookAt.xUp, cam->viewMtx.lookAt.yUp,
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
                            cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.xAt, cam->viewMtx.lookAtRoll.yAt,
                            cam->viewMtx.lookAtRoll.zAt, cam->viewMtx.lookAtRoll.roll, 0.0f, 1.0f, 0.0f);
                        s3 = 1;
                        break;
                    case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z:
                    case MTX_TYPE_LOOKAT_REFLECT_ROLL_Z_MVIEW:
                        lookat = bump_alloc(&gtlCurrentGfxHeap, sizeof(LookAt), 8);
                        hal_look_at_reflect_roll(
                            mtx, lookat, cam->viewMtx.lookAtRoll.eye.x, cam->viewMtx.lookAtRoll.eye.y,
                            cam->viewMtx.lookAtRoll.eye.z, cam->viewMtx.lookAtRoll.xAt, cam->viewMtx.lookAtRoll.yAt,
                            cam->viewMtx.lookAtRoll.zAt, cam->viewMtx.lookAtRoll.roll, 0.0f, 0.0f, 1.0f);
                        s3 = 2;
                        break;
                    default:
                        if (ommtx->kind >= MTX_TYPE_66 && sCustomMatrixHandler != NULL) {
                            if (sCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_00 != NULL) {
                                sCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_00(mtx, cam, &spDC);
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
                    if (ommtx->kind >= MTX_TYPE_66 && sCustomMatrixHandler != NULL) {
                        if (sCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_04 != NULL) {
                            sCustomMatrixHandler[ommtx->kind - MTX_TYPE_66].unk_04(mtx, cam, &spDC);
                        }
                    }
                    break;
            }
        }
    }

    switch (_D_8004B028) {
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
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.zAt - cam->viewMtx.lookAt.eye.z) +
                           SQ(cam->viewMtx.lookAt.xAt - cam->viewMtx.lookAt.eye.x));
                sp98 = cam->viewMtx.lookAt.eye.y;
                sp94 = cam->viewMtx.lookAt.yAt;
                break;
            case 2:
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.yAt - cam->viewMtx.lookAt.eye.y) +
                           SQ(cam->viewMtx.lookAt.xAt - cam->viewMtx.lookAt.eye.x));
                sp98 = cam->viewMtx.lookAt.eye.z;
                sp94 = cam->viewMtx.lookAt.zAt;
                break;
            default:
                f2 = sp9C;
                break;
        }
        if (f2 < 0.0001f) {
            hal_scale_f(&_D_8004AFA8, 0.0f, 0.0f, 0.0f);
        } else {
            hal_look_at_f(&_D_8004AFA8, 0.0f, sp98, f2, 0.0f, sp94, 0.0f, 0.0f, 1.0f, 0.0f);
            guMtxCatF(_D_8004AFA8, sPerspectiveMatrixF, _D_8004AFA8);
        }
    }

    if (spC8 != 0) {
        switch (spC8) {
            case 1:
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.yAt - cam->viewMtx.lookAt.eye.y) +
                           SQ(cam->viewMtx.lookAt.zAt - cam->viewMtx.lookAt.eye.z));
                sp8C = cam->viewMtx.lookAt.eye.x;
                sp88 = cam->viewMtx.lookAt.xAt;
                break;
            case 2:
                f2 = sqrtf(SQ(cam->viewMtx.lookAt.zAt - cam->viewMtx.lookAt.eye.z) +
                           SQ(cam->viewMtx.lookAt.xAt - cam->viewMtx.lookAt.eye.x));
                sp8C = cam->viewMtx.lookAt.eye.y;
                sp88 = cam->viewMtx.lookAt.yAt;
                break;
            default:
                f2 = sp90;
                break;
        }
        if (f2 < 0.0001f) {
            hal_scale_f(&_D_8004AFE8, 0.0f, 0.0f, 0.0f);
        } else {
            hal_look_at_f(&_D_8004AFE8, sp8C, 0.0f, f2, sp88, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            guMtxCatF(_D_8004AFE8, sPerspectiveMatrixF, _D_8004AFE8);
        }
    }

    *gfxPtr = spDC;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/camera_prepare_matrix.s")
void camera_prepare_matrix(Gfx** gfxPtr, OMCamera* cam);
#endif

void func_80018CD0(s32 val) {
    _D_8004B028 = val;
}

void camera_pre_render(OMCamera* cam, s32 arg1) {
    if (cam->fnPreRender != NULL) {
        cam->fnPreRender(cam, arg1);
    }
}

void camera_render_by_link(GObj* camObj, s32 dlLink, s32 mode) {
    GObj* curr = omGObjListDlHead[dlLink];

    while (curr != NULL) {
        if (!(curr->flags & GOBJ_FLAG_1)) {
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

void func_80018DE8(GObj* obj, s32 dlLink, s32 mode) {
    Gfx* savedGfxPos[4];
    s32 i;

    for (i = 0; i < 4; i++) {
        savedGfxPos[i] = gMainGfxPos[i];
        // reserve space for 2 commands: gSPDisplayList and gSPBranchList
        gMainGfxPos[i] += 2;
    }

    camera_render_by_link(obj, dlLink, mode);

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

void func_80018F1C(s32 dlLink) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (omD_8004AC78[dlLink].unk04[i] != NULL) {
            gSPDisplayList(gMainGfxPos[i]++, omD_8004AC78[dlLink].unk04[i]);
        }
    }
}

void camera_render_objects(GObj* camObj, s32 mode) {
    s32 dlLink = 0;
    u32 dlLinkBitMask = camObj->dlLinkBitMask;
    u32 unk_38 = camObj->unk38;

    while (dlLinkBitMask != 0) {
        if (dlLinkBitMask & 1) {
            if (unk_38 & 1) {
                if ((u8)gtlDrawnFrameCounter == omD_8004AC78[dlLink].unk00) {
                    func_80018F1C(dlLink);
                } else {
                    func_80018DE8(camObj, dlLink, mode);
                }
            } else {
                camera_render_by_link(camObj, dlLink, mode);
            }
        }

        dlLinkBitMask >>= 1;
        unk_38 >>= 1;
        dlLink++;
    }
}

void camera_post_render(OMCamera* cam) {
    if (cam->flags & 0x04) {
        gtlCombineAllDLists();
    }

    if (cam->flags & 0x10) {
        gtlProcessAllDLists();
        gtlReset();
    }

    if (cam->flags & 0x40) {
        gtlProcessAllDLists();
    }
}

void func_80019158(GObj* obj, Gfx** gfx, s32 arg2) {
    OMCamera* cam = obj->data.cam;

    camera_init(gfx, cam, arg2);
    camera_prepare_matrix(gfx, cam);
    camera_pre_render(cam, arg2);
    camera_render_objects(obj, (cam->flags & 8) ? 1 : 0);
    camera_post_render(cam);
}

void func_800191D8(GObj* obj) {
    func_80019158(obj, &gMainGfxPos[0], 0);
}

void func_80019200(GObj* obj) {
    func_80019158(obj, &gMainGfxPos[1], 1);
}

void func_80019228(GObj* obj) {
    func_80019158(obj, &gMainGfxPos[2], 2);
}

void func_80019250(GObj* obj) {
    func_80019158(obj, &gMainGfxPos[3], 3);
}

void func_80019278(void) {
    OMCamera* cam = omCurrentCamera->data.cam;

    gtlProcessAllDLists();
    gtlReset();
    camera_init(&gMainGfxPos[0], cam, 0);
    camera_prepare_matrix(&gMainGfxPos[0], cam);
    camera_pre_render(cam, 0);
}

void func_800192DC(GObj* obj) {
    s32 i;
    OMCamera* cam = obj->data.cam;

    camera_init(&gMainGfxPos[0], cam, 0);
    _D_8004B248 = gMainGfxPos[0] + 1;
    gSPDisplayList(gMainGfxPos[0], gMainGfxPos[0] + 2);
    gMainGfxPos[0] += 2;
    camera_prepare_matrix(&gMainGfxPos[0], cam);
    gSPEndDisplayList(gMainGfxPos[0]++);
    gSPBranchList(_D_8004B248, gMainGfxPos[0]);
    camera_pre_render(cam, 0);

    if (cam->flags & 0x20) {
        func_800177D8(&gMainGfxPos[1], cam, 1);
    }

    for (i = 1; i < 4; i++) {
        if (gtlDLBuffers[gtlContextId][i].length != 0) {
            gMainGfxPos[i]++;
        }
        _D_8004B238[i] = gMainGfxPos[i];
    }

    camera_render_objects(obj, (cam->flags & 8) ? TRUE : FALSE);

    for (i = 1; i < 4; i++) {
        Gfx* start = gMainGfxPos[i];

        if (_D_8004B238[i] == gMainGfxPos[i]) {
            if (gtlDLBuffers[gtlContextId][i].length != 0) {
                gMainGfxPos[i]--;
            }
        } else {
            gMainGfxPos[i]++;
            gSPDisplayList(&_D_8004B238[i][-1], gMainGfxPos[i]);
            if (i != 1 || !(cam->flags & 0x20)) {
                func_800177D8(&gMainGfxPos[i], cam, i);
            }
            gSPDisplayList(gMainGfxPos[i]++, _D_8004B248 + 1);
            camera_pre_render(cam, i);
            gSPEndDisplayList(gMainGfxPos[i]++);
            gSPBranchList(start, gMainGfxPos[i]);
        }
    }

    camera_post_render(cam);
}

void func_80019588(void) {
    s32 i;
    OMCamera* cam = omCurrentCamera->data.cam;
    Gfx* start;
    Gfx** new_var = gMainGfxPos;

    for (i = 1; i < 4; i++) {
        start = new_var[i];

        if (_D_8004B238[i] == gMainGfxPos[i]) {
            gMainGfxPos[i]--;
        } else {
            gMainGfxPos[i]++;
            gSPDisplayList(&_D_8004B238[i][-1], gMainGfxPos[i]);
            func_800177D8(&gMainGfxPos[i], cam, i);
            gSPDisplayList(gMainGfxPos[i]++, _D_8004B248 + 1);
            camera_pre_render(cam, i);
            gSPEndDisplayList(gMainGfxPos[i]++);
            gSPBranchList(start, gMainGfxPos[i]);
        }
    }

    gtlProcessAllDLists();
    gtlReset();
    camera_init(&gMainGfxPos[0], cam, 0);
    _D_8004B248 = gMainGfxPos[0] + 1;
    gSPDisplayList(gMainGfxPos[0], gMainGfxPos[0] + 2);
    gMainGfxPos[0] += 2;
    camera_prepare_matrix(&gMainGfxPos[0], cam);
    gSPEndDisplayList(gMainGfxPos[0]++);
    gSPBranchList(_D_8004B248, gMainGfxPos[0]);
    camera_pre_render(cam, 0);

    for (i = 1; i < 4; i++) {
        _D_8004B238[i] = ++gMainGfxPos[i];
    }
}

void sprite_camera_render(GObj* obj) {
    OMCamera* cam;
    UNUSED u32 pad;
    s32 xmin, ymin, xmax, ymax;

    cam = obj->data.cam;

    xmin = cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4;
    ymin = cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4;
    xmax = cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4;
    ymax = cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4;

    if (xmin < viScreenWidth / SCREEN_WIDTH * D_80040F38) {
        xmin = viScreenWidth / SCREEN_WIDTH * D_80040F38;
    }
    if (ymin < viScreenHeight / SCREEN_HEIGHT * D_80040F30) {
        ymin = viScreenHeight / SCREEN_HEIGHT * D_80040F30;
    }
    if (xmax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80040F3C) {
        xmax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80040F3C;
    }
    if (ymax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80040F34) {
        ymax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80040F34;
    }

    camera_init(&gMainGfxPos[0], cam, 0);
    spInit(&gMainGfxPos[0]);
    spScissor(xmin, xmax, ymin, ymax);
    camera_render_objects(obj, (cam->flags & 8) ? TRUE : FALSE);
    spFinish(&gMainGfxPos[0]);
    gMainGfxPos[0]--;
    gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_PERSP);
}
