#include "common.h"

#include "sys/oh.h"

#define FORCE_S32(thing) (void*) (*(s32*) (&thing)) // TODO cursed
#define FORCE_F32(thing) (*(f32*) (&thing))         // TODO cursed


static s32 D_800BE2C0;
static s32 D_800BE2C4;
static OMCamera* D_800BE2C8;
static bool D_800BE2CC;
static GObj* D_800BE2D0;

extern u32 D_800AECE0[];
extern u32 D_800AEF80[];

// .data
Vtx D_800AEC70[] = {
    { { { 0, 50, 50 }, 0, { 0, 0 }, { 0, 0, 127, 0 } } },
    { { { 0, 50, -50 }, 0, { 0, 0 }, { 0, 0, 127, 0 } } },
    { { { 0, -50, -50 }, 0, { 0, 0 }, { 0, 0, 127, 0 } } },
    { { { 0, -50, 50 }, 0, { 0, 0 }, { 0, 0, 127, 0 } } },
};

Gfx D_800AECB0[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPVertex(D_800AEC70, 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 0, 3, 1, 0),
    gsSPEndDisplayList(),
};

u32 D_800AECE0[] = {
    0x00000014, 0xFF9E0000, 0x00000000, 0x7F000000,
    0x00000026, 0xFFA40000, 0x00000000, 0x7F000000,
    0x00000038, 0xFFAD0000, 0x00000000, 0x7F000000,
    0x00000047, 0xFFB90000, 0x00000000, 0x7F000000,
    0x00000053, 0xFFC80000, 0x00000000, 0x7F000000,
    0x0000005C, 0xFFDA0000, 0x00000000, 0x7F000000,
    0x00000062, 0xFFEC0000, 0x00000000, 0x7F000000,
    0x00000064, 0x00000000, 0x00000000, 0x7F000000,
    0x00000062, 0x00140000, 0x00000000, 0x7F000000,
    0x0000005C, 0x00260000, 0x00000000, 0x7F000000,
    0x00000053, 0x00380000, 0x00000000, 0x7F000000,
    0x00000047, 0x00470000, 0x00000000, 0x7F000000,
    0x00000038, 0x00530000, 0x00000000, 0x7F000000,
    0x00000026, 0x005C0000, 0x00000000, 0x7F000000,
    0x00000014, 0x00620000, 0x00000000, 0x7F000000,
    0x00000000, 0x00640000, 0x00000000, 0x7F000000,
    0x0000FFEC, 0x00620000, 0x00000000, 0x7F000000,
    0x0000FFDA, 0x005C0000, 0x00000000, 0x7F000000,
    0x0000FFC8, 0x00530000, 0x00000000, 0x7F000000,
    0x0000FFB9, 0x00470000, 0x00000000, 0x7F000000,
    0x0000FFAD, 0x00380000, 0x00000000, 0x7F000000,
    0x0000FFA4, 0x00260000, 0x00000000, 0x7F000000,
    0x0000FF9E, 0x00140000, 0x00000000, 0x7F000000,
    0x0000FF9C, 0x00000000, 0x00000000, 0x7F000000,
    0x0000FFEC, 0xFF9E0000, 0x00000000, 0x7F000000,
    0x0000FF9E, 0xFFEC0000, 0x00000000, 0x7F000000,
    0x0000FFA4, 0xFFDA0000, 0x00000000, 0x7F000000,
    0x0000FFDA, 0xFFA40000, 0x00000000, 0x7F000000,
    0x0000FFAD, 0xFFC80000, 0x00000000, 0x7F000000,
    0x00000000, 0xFF9C0000, 0x00000000, 0x7F000000,
    0x0000FFC8, 0xFFAD0000, 0x00000000, 0x7F000000,
    0x0000FFB9, 0xFFB90000, 0x00000000, 0x7F000000,
};

Gfx D_800AEEE0[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPVertex(D_800AECE0, 32, 0),
    gsSP2Triangles(31, 30, 29, 0, 28, 31, 29, 0),
    gsSP2Triangles(30, 27, 29, 0, 26, 28, 29, 0),
    gsSP2Triangles(25, 26, 29, 0, 27, 24, 29, 0),
    gsSP2Triangles(23, 25, 29, 0, 22, 23, 29, 0),
    gsSP2Triangles(21, 22, 29, 0, 20, 21, 29, 0),
    gsSP2Triangles(19, 20, 29, 0, 18, 19, 29, 0),
    gsSP2Triangles(17, 18, 29, 0, 16, 17, 29, 0),
    gsSP2Triangles(15, 16, 29, 0, 14, 15, 29, 0),
    gsSP2Triangles(13, 14, 29, 0, 12, 13, 29, 0),
    gsSP2Triangles(11, 12, 29, 0, 10, 11, 29, 0),
    gsSP2Triangles(9, 10, 29, 0, 8, 9, 29, 0),
    gsSP2Triangles(7, 8, 29, 0, 6, 7, 29, 0),
    gsSP2Triangles(5, 6, 29, 0, 4, 5, 29, 0),
    gsSP2Triangles(3, 4, 29, 0, 2, 3, 29, 0),
    gsSP2Triangles(1, 2, 29, 0, 0, 1, 29, 0),
    gsSPEndDisplayList(),
};

u32 D_800AEF80[] = {
    0x000000BE, 0x003E0000, 0x00000000, 0x7F000000,
    0x00000000, 0x00C80000, 0x00000000, 0x7F000000,
    0x00000076, 0xFF5E0000, 0x00000000, 0x7F000000,
    0x00000049, 0xFFE80000, 0x00000000, 0x7F000000,
    0x0000002D, 0x003E0000, 0x00000000, 0x7F000000,
    0x0000FF42, 0x003E0000, 0x00000000, 0x7F000000,
    0x0000FFD3, 0x003E0000, 0x00000000, 0x7F000000,
    0x00000000, 0xFFB30000, 0x00000000, 0x7F000000,
    0x0000FF8A, 0xFF5E0000, 0x00000000, 0x7F000000,
    0x0000FFB7, 0xFFE80000, 0x00000000, 0x7F000000,
};

Gfx D_800AF020[] = {
    gsSPVertex(D_800AEF80, 10, 0),
    gsSP2Triangles(9, 8, 7, 0, 6, 9, 7, 0),
    gsSP2Triangles(9, 6, 5, 0, 4, 6, 7, 0),
    gsSP2Triangles(3, 4, 7, 0, 2, 3, 7, 0),
    gsSP2Triangles(4, 1, 6, 0, 0, 4, 3, 0),
    gsSPEndDisplayList(),
};

s32 D_800AF050 = 0;
s32 D_800AF054 = 0; // r
s32 D_800AF058 = 0; // g
s32 D_800AF05C = 0; // b
s32 D_800AF060 = 0; // a

u32 D_800AF064_5AA14[] = {
    0x00000000, 0x00000000, 0x00000000, 0x3F800000,
    0x00000000, 0x00000000, 0x00000000, 0x3F800000,
    0x00000000, 0x00000000, 0x00000000, 0x3F800000,
};

Vec3f D_800AF094 = { -1.0f, 0.0f, 0.0f };

u32 D_800AF0A0_5AA50[] = {
    0x00000000, 0xBF800000, 0x00000000, 0x00000000,
    0x00000000, 0xBF800000, 0x00000000, 0x00000000,
    0x00000000,
};

Vec3f D_800AF0C4 = { 0.0f, 0.0f, 0.0f };

f32 func_800A7430(f32 arg0) {
    return ABS(arg0);
}

s32 func_800A7460(void) {
    return D_800AF050 != false;
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

    D_800AF050 = true;
    tmp = FORCE_F32(arg0->userData);
    temp_f24 = 255.0f / (tmp * 60.0);
    var_f20 = 0.0f;

    while (true) {
        var_f20 += temp_f24;
        if (var_f20 > 255.0) {
            break;
        }
        D_800AF060 = var_f20;
        ohWait(1);
    }

    D_800AF060 = 0xFF;
    D_800AF050 = false;
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

    D_800AF050 = true;
    tmp = FORCE_F32(arg0->userData);
    temp_f24 = 255.0f / (tmp * 60.0);
    var_f20 = 255.0f;

    while (true) {
        var_f20 -= temp_f24;
        if (var_f20 < 0.0) {
            break;
        }
        D_800AF060 = var_f20;
        ohWait(1);
    }
    D_800AF060 = 0;
    D_800AF050 = false;
    if (D_800BE2CC) {
        ohWait(3);
    }
    omDeleteGObj(NULL);
    ohWait(99);
}

void func_800A7860(s32 arg0, f32 arg1) {
    GObj* gobj;

    D_800AF050 = true;
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
    D_800BE2CC = false;
}

void func_800A7918(s32 arg0, f32 arg1) {
    func_800A7860(arg0, arg1);
    D_800BE2CC = true;
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
                     AA_EN | Z_UPD | IM_RD | CLR_ON_CVG | CVG_DST_WRAP | ZMODE_OPA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
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

    D_800AF050 = true;
    tmp = FORCE_F32(gobj->userData);
    temp_f20 = gobj->data.dobj->scale.v.x;
    temp_f24 = temp_f20 / (tmp * 60.0);
    var_f20 = temp_f20;

    while (true) {
        var_f20 -= temp_f24;
        if (var_f20 <= 0.0) {
            break;
        }
        gobj->data.dobj->scale.v.x = var_f20;
        gobj->data.dobj->scale.v.y = var_f20;
        gobj->data.dobj->scale.v.z = var_f20;
        ohWait(1);
    }

    D_800AF050 = false;
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
    D_800BE2CC = false;
}

void func_800A7F40(f32 arg0, f32 arg1, s32 arg2, f32 arg3) {
    func_800A7CC4(arg0, arg1, arg2, arg3);
    D_800BE2CC = true;
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
