#include "common.h"

#include "sys/oh.h"

#define FORCE_S32(thing) (void*) (*(s32*)(&thing)) // TODO cursed
#define FORCE_F32(thing) (*(f32*)(&thing)) // TODO cursed

extern Gfx D_800AECB0[];
extern Gfx D_800AEEE0[];
extern Gfx D_800AF020[];
extern s32 D_800AF050;
extern s32 D_800AF054; // r
extern s32 D_800AF058; // g
extern s32 D_800AF05C; // b
extern s32 D_800AF060; // a
extern s32 D_800BE2C0;
extern OMCamera* D_800BE2C8;
extern s32 D_800BE2CC; // bool
extern GObj* D_800BE2D0;

f32 func_800A7430(f32 arg0) {
    return ABS(arg0);
}

s32 func_800A7460(void) {
    return D_800AF050 != FALSE;
}

void func_800A7470(s32 arg0, s32 arg1, s32 arg2) {
    D_800AF054 = arg0;
    D_800AF058 = arg1;
    D_800AF05C = arg2;
}

GObj* func_800A748C(void (*procFunc)(GObj*), Gfx* dobjBP) {
    return ohCreateModel(2, NULL, 1, 1, renRenderModelTypeA, D_800BE2C0, 1, 1 << D_800BE2C0, dobjBP, 1, 0, procFunc, 0);
}

void func_800A750C(GObj* gobj) {
    Gfx* gfx;
    s32 sp30;

    gfx = gMainGfxPos[1];
    gDPPipeSync(gfx++);
    sp30 = renPrepareModelMatrix(&gfx, gobj->data.dobj);
    renLoadTextures(gobj->data.dobj, &gfx);

    gDPSetPrimColor(gfx++, 0, 0, D_800AF054, D_800AF058, D_800AF05C, D_800AF060);
    gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gSPDisplayList(gfx++, D_800AECB0);

    if (sp30 != 0 && (gobj->data.dobj->parent == (void*) 1 || gobj->data.dobj->next != NULL)) {
        gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    }
    gMainGfxPos[1] = gfx;
}

void func_800A7660(GObj* arg0) {
    f32 temp_f24;
    f32 var_f20;
    f32 tmp;

    D_800AF050 = TRUE;
    tmp = FORCE_F32(arg0->userData);
    temp_f24 = 255.0f / (tmp * 60.0);
    var_f20 = 0.0f;

    while (TRUE) {
        var_f20 += temp_f24;
        if (var_f20 > 255.0) {
            break;
        }
        D_800AF060 = var_f20;
        ohWait(1);
    }

    D_800AF060 = 0xFF;
    D_800AF050 = FALSE;
    if (D_800BE2CC) {
        ohWait(3);
    }
    omDeleteGObj(NULL);
    ohWait(99);
}

void func_800A7760(GObj* arg0) {
    f32 temp_f24;
    f32 var_f20;
    f32 tmp;

    D_800AF050 = TRUE;
    tmp = FORCE_F32(arg0->userData);
    temp_f24 = 255.0f / (tmp * 60.0);
    var_f20 = 255.0f;

    while (TRUE) {
        var_f20 -= temp_f24;
        if (var_f20 < 0.0) {
            break;
        }
        D_800AF060 = var_f20;
        ohWait(1);
    }
    D_800AF060 = 0;
    D_800AF050 = FALSE;
    if (D_800BE2CC) {
        ohWait(3);
    }
    omDeleteGObj(NULL);
    ohWait(99);
}

void func_800A7860(s32 arg0, f32 arg1) {
    GObj* gobj;

    D_800AF050 = TRUE;
    if (arg0 != 0) {
        gobj = func_800A748C(func_800A7760, D_800AECB0);
        D_800AF060 = 0xFF;
    } else {
        gobj = func_800A748C(func_800A7660, D_800AECB0);
        D_800AF060 = 0;
    }
    gobj->fnRender = func_800A750C;
    gobj->data.dobj->scale.v.x = 1.0f;
    gobj->data.dobj->scale.v.y = 3.2f;
    gobj->data.dobj->scale.v.z = 2.4f;
    gobj->userData = FORCE_S32(arg1);
    D_800BE2CC = FALSE;
}

void func_800A7918(s32 arg0, f32 arg1) {
    func_800A7860(arg0, arg1);
    D_800BE2CC = TRUE;
}

void func_800A7948(GObj* gobj) {
    Gfx* gfx;
    s32 sp30;

    gfx = gMainGfxPos[1];
    gDPPipeSync(gfx++);
    sp30 = renPrepareModelMatrix(&gfx, gobj->data.dobj);
    renLoadTextures(gobj->data.dobj, &gfx);

    gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 0);
    gDPSetRenderMode(gfx++,
        AA_EN | Z_UPD | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_OPA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA),
        AA_EN | Z_UPD | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)
    );
    gSPDisplayList(gfx++, gobj->data.dobj->payload.dlist);

    if (sp30 != 0 && (gobj->data.dobj->parent == (void*) 1 || gobj->data.dobj->next != NULL)) {
        gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    }
    gMainGfxPos[1] = gfx;
}

void func_800A7A58(GObj* gobj) {
    Gfx* gfx;
    s32 sp30;

    gfx = gMainGfxPos[1];
    gDPPipeSync(gfx++);
    sp30 = renPrepareModelMatrix(&gfx, gobj->data.dobj);
    renLoadTextures(gobj->data.dobj, &gfx);

    gDPSetPrimColor(gfx++, 0, 0, D_800AF054, D_800AF058, D_800AF05C, D_800AF060);
    gDPSetRenderMode(gfx++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gSPDisplayList(gfx++, D_800AECB0);

    if (sp30 != 0 && (gobj->data.dobj->parent == (void*) 1 || gobj->data.dobj->next != NULL)) {
        gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    }
    gMainGfxPos[1] = gfx;
}

void func_800A7BAC(GObj* gobj) {
    f32 temp_f20;
    f32 temp_f24;
    f32 var_f20;
    f32 tmp;

    D_800AF050 = TRUE;
    tmp = FORCE_F32(gobj->userData);
    temp_f20 = gobj->data.dobj->scale.v.x;
    temp_f24 = temp_f20 / (tmp * 60.0);
    var_f20 = temp_f20;

    while (TRUE) {
        var_f20 -= temp_f24;
        if (var_f20 <= 0.0) {
            break;
        }
        gobj->data.dobj->scale.v.x = var_f20;
        gobj->data.dobj->scale.v.y = var_f20;
        gobj->data.dobj->scale.v.z = var_f20;
        ohWait(1);
    }

    D_800AF050 = FALSE;
    if (D_800BE2CC) {
        ohWait(3);
    }
    if (D_800BE2D0 != NULL) {
        omDeleteGObj(D_800BE2D0);
    }
    omDeleteGObj(NULL);
    ohWait(99);
}

void func_800A7CC4(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    Gfx* var_a1;
    GObj* gobj;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;

    if (arg2 != 0) {
        var_a1 = D_800AF020;
    } else {
        var_a1 = D_800AEEE0;
    }
    gobj = func_800A748C(func_800A7BAC, var_a1);
    gobj->fnRender = func_800A7948;

    temp_f24 = func_800A7430(arg0);
    temp_f20 = func_800A7430(arg0);
    temp_f22 = func_800A7430(arg1);
    gobj->data.dobj->scale.v.x = sqrtf(((func_800A7430(arg1) + 120.0f) * (120.0f + temp_f22)) + ((160.0f + temp_f20) * (160.0f + temp_f24))) / 100.0;

    temp_f24 = func_800A7430(arg0);
    temp_f20 = func_800A7430(arg0);
    temp_f22 = func_800A7430(arg1);
    gobj->data.dobj->scale.v.y = sqrtf(((func_800A7430(arg1) + 120.0f) * (120.0f + temp_f22)) + ((160.0f + temp_f20) * (160.0f + temp_f24))) / 100.0;

    temp_f24 = func_800A7430(arg0);
    temp_f20 = func_800A7430(arg0);
    temp_f22 = func_800A7430(arg1);
    gobj->data.dobj->scale.v.z = sqrtf(((func_800A7430(arg1) + 120.0f) * (120.0f + temp_f22)) + ((160.0f + temp_f20) * (160.0f + temp_f24))) / 100.0;

    gobj->data.dobj->position.v.x = 1.0f;
    gobj->data.dobj->position.v.y = arg0;
    gobj->data.dobj->position.v.z = arg1;

    gobj->userData = FORCE_S32(arg3);

    gobj = func_800A748C(NULL, D_800AECB0);
    gobj->fnRender = func_800A7A58;
    gobj->data.dobj->scale.v.x = 1.0f;
    gobj->data.dobj->scale.v.y = 3.2f;
    gobj->data.dobj->scale.v.z = 2.4f;

    D_800BE2D0 = gobj;
    D_800BE2CC = FALSE;
}

void func_800A7F40(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    func_800A7CC4(arg0, arg1, arg2, arg3);
    D_800BE2CC = TRUE;
}

void func_800A7F68(s32 arg0, s32 arg1) {
    D_800BE2C0 = arg0;
    D_800BE2C8 = ohCreateCamera(5, NULL, 0, 0x80000000, ren_func_800191D8, 1, 1 << arg0, 1 << arg0, 1, 0, NULL, 0, 1)->data.cam;
    D_800BE2C8->flags = CAMERA_FLAG_4 | CAMERA_FLAG_1;
    if (arg1 & 0x100) {
        D_800BE2C8->flags &= ~CAMERA_FLAG_1;
    }
    D_800BE2C8->bgColor = 0x10001;
    D_800BE2C8->perspMtx.persp.fovy = 45.0f;
    D_800BE2C8->perspMtx.persp.near = 8.0f;
    D_800BE2C8->perspMtx.persp.far = 1024.0f;
    D_800BE2C8->perspMtx.persp.scale = 1.0f;
    D_800BE2C8->viewMtx.lookAt.up.x = 0.0f;
    D_800BE2C8->viewMtx.lookAt.up.y = 0.0f;
    D_800BE2C8->viewMtx.lookAt.up.z = 1.0f;
    func_800A844C(D_800BE2C8, 0, 0, (arg1 & 3) * SCREEN_WIDTH, (arg1 & 3) * SCREEN_HEIGHT);
    D_800BE2C8->viewMtx.lookAt.eye.x = 290.0f;
    D_800BE2C8->viewMtx.lookAt.eye.y = 0.0f;
    D_800BE2C8->viewMtx.lookAt.eye.z = 0.0f;
    D_800BE2C8->viewMtx.lookAt.at.x = 0.0f;
    D_800BE2C8->viewMtx.lookAt.at.y = 0.0f;
    D_800BE2C8->viewMtx.lookAt.at.z = 0.0f;
    D_800AF054 = 0;
    D_800AF058 = 0;
    D_800AF05C = 0;
    D_800AF050 = 0;
}
