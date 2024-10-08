#include "common.h"

typedef struct Unk_800A8F0C {
    /* 0x00 */ char unk_00[0x3C];
    /* 0x3C */ Vec3f unk_3C;
    /* 0x48 */ Vec3f unk_48;
    /* 0x54 */ Vec3f unk_54;
} Unk_800A8F0C; // size >= 0x60

typedef struct Unk800BEDF0 {
    /* 0x0 */ u8 stickX;
    /* 0x1 */ u8 stickY;
    /* 0x2 */ u16 buttons;
} Unk800BEDF0; // size = 0x4

extern UNK_TYPE D_800AF0D4;
extern f32 D_800AF378[];
extern s32 D_800AF3A0;
extern s32 D_800AF3A4;
extern s32 D_800AF3A8;
extern s32 D_800AF3AC;
extern u64 D_800AF3B0;
extern s32 D_800AF3B8;
extern s32 D_800AF3BC;

extern s32 D_800BE2F0[4][24];
extern s32 D_800BE470[4][24];
extern Unk800BEDF0 D_800BEDF0;
extern UnkStruct800BEDF8 D_800BEDF8[4];
extern UnkStruct800BEDF8* D_800BEE98;
extern UnkStruct800BEDF8 D_800BEEA0[4];
extern s32 D_800BEF48;

#ifdef NON_MATCHING
void func_800A8120(Mtx arg0, Mtx arg1, Mtx arg2) {
    Mtx temp;
    f32 value;
    s32 i, j, k;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            value = 0.0f;
            for (k = 0; k < 4; k++) {
                value += (arg1.m[i][k] / 65536.0f) * (arg2.m[k][j] / 65536.0f);
            }
            temp.m[i][j] = value * 65536.0f;
        }
    }
    arg0 = temp;
}
#else
void func_800A8120(Mtx arg0, Mtx arg1, Mtx arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8120.s")
#endif

void func_800A8344(Mtx arg0, Vec3f* arg1, f32 arg2) {
    Mtx spC8;

    hal_rotate_deg(&spC8, arg2, arg1->x, arg1->y, arg1->z);
    func_800A8120(arg0, arg0, spC8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A844C.s")

GObj* func_800A85E8(void (*procFunc)(GObj*), s32 link, s32 dllink, Gfx* dlist) {
    GObj* gobj;
    s32 cameraTag;
    DObj* model;

    if (dllink < 0) {
        dllink = 0;
        cameraTag = 0;
    } else {
        cameraTag = 1 << dllink;
    }
    gobj = ohCreateModel(1 << link, NULL, link, link, renRenderModelTypeA, dllink, link, cameraTag, dlist, true, 0, procFunc, 0);
    if (gobj == NULL) {
        return NULL;
    }
    model = gobj->data.dobj;
    model->rotation.mtx->kind = MTX_TYPE_ROTATE_RPY;
    return gobj;
}

GObj* func_800A86A4(void (*procFunc)(GObj*), s32 link, s32 dllink, Gfx* dlist) {
    GObj* gobj;
    s32 cameraTag;
    DObj* model;

    if (dllink < 0) {
        dllink = 0;
        cameraTag = 0;
    } else {
        cameraTag = 1 << dllink;
    }
    gobj = ohCreateModel(1 << link, NULL, link, link, renRenderModelTypeA, dllink, link, cameraTag, dlist, true, 1, procFunc, 0);
    if (gobj == NULL) {
        return NULL;
    }
    model = gobj->data.dobj;
    model->rotation.mtx->kind = MTX_TYPE_ROTATE_RPY;
    return gobj;
}

DObj* func_800A8764(DObj* dobj) {
    omDObjAppendMtx(dobj, MTX_TYPE_TRANSLATE, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_ROTATE_RPY, 0);
    omDObjAppendMtx(dobj, MTX_TYPE_SCALE, 0);
    return dobj;
}

void func_800A87B0(GObj* obj, UnkEC64Arg3* treeDef, DObj** nodeList) {
    int i;
    DObj* dobj;
    DObj* sp44[18];

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(sp44); i++) { sp44[i] = NULL; }
    // clang-format on

    while (treeDef->unk_00 != 18) {
        if (treeDef->unk_00 != 0) {
            dobj = sp44[treeDef->unk_00] = func_800A8764(omDObjAddChild(sp44[treeDef->unk_00 - 1], treeDef->unk04));
        } else {
            dobj = sp44[0] = func_800A8764(omGObjAddDObj(obj, treeDef->unk04));
        }

        dobj->position.v = treeDef->position;
        *((Vec3f*) &dobj->rotation.f[1]) = treeDef->rotation;
        dobj->scale.v = treeDef->scale;

        if (nodeList != NULL) {
            *nodeList++ = dobj;
        }

        treeDef++;
    }
}

GObj* func_800A88E4(void (*procFunc)(GObj*), s32 link, s32 dllink, UnkEC64Arg3* treeDef, DObj** nodeList) {
    s32 unused;
    GObj* gobj;
    s32 cameraTag;
    DObj* model;

    if (dllink < 0) {
        dllink = 0;
        cameraTag = 0;
    } else {
        cameraTag = 1 << dllink;
    }
    gobj = omAddGObj(1 << link, NULL, link, link);
    if (gobj == NULL) {
        return NULL;
    }

    omLinkGObjDL(gobj, renRenderModelTypeB, dllink, link, cameraTag);
    func_800A87B0(gobj, treeDef, nodeList);
    omCreateProcess(gobj, procFunc, 0, 0);
    model = gobj->data.dobj;
    model->rotation.mtx->kind = MTX_TYPE_ROTATE_RPY;
    return gobj;
}

GObj* func_800A89B4(void (*procFunc)(GObj*), s32 link, s32 dllink, UnkEC64Arg3* treeDef, DObj** nodeList) {
    s32 unused;
    GObj* gobj;
    s32 cameraTag;
    DObj* model;

    if (dllink < 0) {
        dllink = 0;
        cameraTag = 0;
    } else {
        cameraTag = 1 << dllink;
    }
    gobj = omAddGObj(1 << link, NULL, link, link);
    if (gobj == NULL) {
        return NULL;
    }

    omLinkGObjDL(gobj, renRenderModelTypeB, dllink, link, cameraTag);
    func_800A87B0(gobj, treeDef, nodeList);
    omCreateProcess(gobj, procFunc, 1, 0);
    model = gobj->data.dobj;
    model->rotation.mtx->kind = MTX_TYPE_ROTATE_RPY;
    return gobj;
}

GObj* func_800A8A84(void (*procFunc)(GObj*), s32 dllink, s32 link) {
    GObj* gobj;
    OMCamera* cam;

    gobj = ohCreateCamera(0x200, NULL, link, link, ren_func_800191D8, dllink, 1 << dllink, 1 << dllink, true, 0, procFunc, 0, true);
    if (gobj == NULL) {
        return NULL;
    }
    cam = gobj->data.cam;
    cam->flags = CAMERA_FLAG_4;
    D_800AF0D4++;
    return gobj;
}

GObj* func_800A8B2C(void (*procFunc)(GObj*), s32 dllink) {
    if (procFunc == NULL) {
        D_800AF0D4 = 0;
        return NULL;
    } else {
        return func_800A8A84(procFunc, dllink, LINK_5);
    }
}

UNK_PTR func_800A8B60(void) {
    return &D_800AF0D4;
}

void func_800A8B6C(DObj* arg0, void* arg1) {
    DObj* child;

    child = omDObjAddChild(arg0, arg1);
    child->rotation.f[1] = 0.0f;
    child->rotation.f[2] = 0.0f;
    child->rotation.f[3] = 0.0f;
    child->position.v.x = 0.0f;
    child->position.v.y = 0.0f;
    child->position.v.z = 0.0f;
    child->scale.v.x = 1.0f;
    child->scale.v.y = 1.0f;
    child->scale.v.z = 1.0f;
}

Vec3f* func_800A8BBC(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    Vec3f_func_8001A8B8(&arg0[0], arg1, arg2);
    Vec3f_func_8001A8B8(&arg0[1], arg1, arg2);
    Vec3f_func_8001A8B8(&arg0[2], arg1, arg2);
    return arg0;
}

Vec3f* func_800A8C10(Vec3f* arg0, f32 arg1) {
    Vec3fNormalize(arg0);
    Vec3f_func_8001A8B8(&arg0[1], arg0, arg1);
    Vec3f_func_8001A8B8(&arg0[2], arg0, arg1);
    return arg0;
}

Vec3f* func_800A8C5C(Vec3f* arg0, f32 arg1) {
    Vec3fNormalize(&arg0[1]);
    Vec3f_func_8001A8B8(arg0, &arg0[1], arg1);
    Vec3f_func_8001A8B8(&arg0[2], &arg0[1], arg1);
    return arg0;
}

Vec3f* func_800A8CB0(Vec3f* arg0, f32 arg1) {
    Vec3fNormalize(&arg0[2]);
    Vec3f_func_8001A8B8(arg0, &arg0[2], arg1);
    Vec3f_func_8001A8B8(&arg0[1], &arg0[2], arg1);
    return arg0;
}

Vec3f* func_800A8D04(Vec3f* arg0) {
    Vec3f unused;

    Vec3fNormalize(arg0);
    Vec3fNormalize(&arg0[2]);
    Vec3fNormalizedCross(arg0, &arg0[2], &arg0[1]);
    Vec3fNormalizedCross(&arg0[1], arg0, &arg0[2]);
    return arg0;
}

Vec3f* func_800A8D60(Vec3f* arg0, Mtx3f arg1, f32 arg2, f32 arg3, f32 arg4) {
    arg0->x += arg1[0][0] * arg2 + arg1[1][0] * arg3 + arg1[2][0] * arg4;
    arg0->y += arg1[0][1] * arg2 + arg1[1][1] * arg3 + arg1[2][1] * arg4;
    arg0->z += arg1[0][2] * arg2 + arg1[1][2] * arg3 + arg1[2][2] * arg4;
    return arg0;
}

Vec3f* func_800A8E00(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2) {
    return func_800A8D60(arg0, arg1, arg2->x, arg2->y, arg2->z);
}

// void func_800A8E34(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2, f32 arg3, f32 arg4, f32 arg5);
#ifdef NON_MATCHING
Vec3f* func_800A8E34(Vec3f* arg0, Vec3f* arg1, Mtx3f arg2, f32 arg3, f32 arg4, f32 arg5) {
    arg0->x = arg1->x + arg2[0][0] * arg3 + arg2[1][0] * arg4 + arg2[2][0] * arg5;
    arg0->y = arg1->y + arg2[0][1] * arg3 + arg2[1][1] * arg4 + arg2[2][1] * arg5;
    arg0->z = arg1->z + arg2[0][2] * arg3 + arg2[1][2] * arg4 + arg2[2][2] * arg5;
    return arg0;
}
#else
Vec3f* func_800A8E34(Vec3f* arg0, Vec3f* arg1, Mtx3f arg2, f32 arg3, f32 arg4, f32 arg5);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8E34.s")
#endif

void func_800A8ED4(Vec3f* arg0, Vec3f* arg1, Mtx3f arg2, Vec3f* arg3) {
    func_800A8E34(arg0, arg1, arg2, arg3->x, arg3->y, arg3->z);
}

Unk_800A8F0C* func_800A8F0C(Unk_800A8F0C* arg0, Vec3f* arg1, Vec3f* arg2) {
    arg0->unk_3C.x = arg1->x + arg2->x;
    arg0->unk_3C.y = arg1->y + arg2->y;
    arg0->unk_3C.z = arg1->z + arg2->z;
    arg0->unk_48.x = arg1->x;
    arg0->unk_48.y = arg1->y;
    arg0->unk_48.z = arg1->z;
    return arg0;
}

void func_800A8F5C(Unk_800A8F0C* arg0, Vec3f* arg1, f32 arg2) {
    Vec3f* s0; // BUG: s0 undefined!

    s0[0].x = arg0->unk_48.x - arg0->unk_3C.x;
    s0[0].y = arg0->unk_48.y - arg0->unk_3C.y;
    s0[0].z = arg0->unk_48.z - arg0->unk_3C.z;
    s0[2] = arg0->unk_54;

    Vec3f_func_8001A8B8(&s0[0], arg1, arg2);
    Vec3f_func_8001A8B8(&s0[2], arg1, arg2);

    arg0->unk_48.x = arg0->unk_3C.x + s0->x;
    arg0->unk_48.y = arg0->unk_3C.y + s0->y;
    arg0->unk_48.z = arg0->unk_3C.z + s0->z;
    arg0->unk_54.x = s0[2].x;
    arg0->unk_54.y = s0[2].y;
    arg0->unk_54.z = s0[2].z;
}

Vec3f* func_800A904C(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2, f32 arg3) {
    arg0->x += (arg1[0][0] * arg2->x + arg1[1][0] * arg2->y + arg1[2][0] * arg2->z) * arg3;
    arg0->y += (arg1[0][1] * arg2->x + arg1[1][1] * arg2->y + arg1[2][1] * arg2->z) * arg3;
    arg0->z += (arg1[0][2] * arg2->x + arg1[1][2] * arg2->y + arg1[2][2] * arg2->z) * arg3;
    return arg0;
}

Unk_800A8F0C* func_800A910C(Unk_800A8F0C* arg0, Vec3f* arg1, f32 arg2) {
    Vec3f* sp34; // BUG: sp34 undefined
    Vec3f sp28;

    sp34[0].x = arg0->unk_48.x - arg0->unk_3C.x;
    sp34[0].y = arg0->unk_48.y - arg0->unk_3C.y;
    sp34[0].z = arg0->unk_48.z - arg0->unk_3C.z;
    sp34[2].x = arg0->unk_54.x;
    sp34[2].y = arg0->unk_54.y;
    sp34[2].z = arg0->unk_54.z;
    sp28.x = arg0->unk_3C.x;
    sp28.y = arg0->unk_3C.y;
    sp28.z = arg0->unk_3C.z;

    Vec3fNormalize(&sp34[0]);
    Vec3fNormalize(&sp34[2]);
    Vec3fNormalizedCross(&sp34[0], &sp34[2], &sp34[1]);
    Vec3fNormalizedCross(&sp34[0], &sp34[1], &sp34[2]);
    func_800A904C(&sp28, (f32(*)[3]) sp34, arg1, arg2);

    arg0->unk_48.x = sp28.x + sp34[0].x;
    arg0->unk_48.y = sp28.y + sp34[0].y;
    arg0->unk_48.z = sp28.z + sp34[0].z;
    arg0->unk_54.x = sp34[2].x;
    arg0->unk_54.y = sp34[2].y;
    arg0->unk_54.z = sp34[2].z;
    arg0->unk_3C.x = sp28.x;
    arg0->unk_3C.y = sp28.y;
    arg0->unk_3C.z = sp28.z;
    return arg0;
}

s32 func_800A9254(GObj* obj, GObjFunc func) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    for (proc = obj->processListHead; proc != NULL; proc = proc->next) {
        if (proc->function == func) {
            return true;
        }
    }
    return false;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A929C.s")
void func_800A929C(s32, s32, s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A98B0.s")
void func_800A98B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_800A9A54(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_800A98B0(arg0, arg1, arg2, arg3, 0, arg4);
}

void func_800A9A7C(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_800A98B0(arg0, arg1, D_800AF378[arg4] * arg2, arg3, arg4, arg5);
}

void func_800A9ACC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg3 <= 0 || arg3 >= (320 - arg0) / 7) {
        return;
    }

    arg0 += (arg3 - 1) * 7;
    while (arg3 > 0) {
        func_800A929C(arg0, arg1, arg2 & 0xF, 0);
        arg2 = arg2 >> 4;
        if (arg4 && arg2 == 0) {
            break;
        }
        arg3--;
        arg0 -= 7;
    }
}

f32 func_800A9BA4(f32 arg0, f32 arg1) {
    f32 sign;
    if (arg0 < 0.0f) {
        sign = -1.0f;
        arg0 = -arg0;
    } else {
        sign = 1.0f;
    }

    arg0 -= arg1;
    if (arg0 < 0.0) {
        arg0 = 0.0f;
    }

    return arg0 * sign;
}

f32 func_800A9C04(Vec3f* arg0) {
    Vec3f sp1C = *arg0;
    sp1C.z = 0.0f;
    if (Vec3fNormalize(&sp1C) == 0.0) {
        return 0.0f;
    } else {
        f32 ret;
        if (sp1C.y < 0.0f) {
            ret = -acosf(sp1C.x);
        } else {
            ret = acosf(sp1C.x);
        }
        return ret;
    }
}

f32 func_800A9CA0(Vec3f* arg0) {
    Vec3f sp1C = *arg0;
    if (Vec3fNormalize(&sp1C) == 0.0) {
        return 0.0f;
    } else {
        return -asinf(sp1C.z);
    }
}

f32 func_800A9D10(Vec3f* arg0) {
    Vec3f sp1C = *arg0;
    sp1C.z = 0.0f;
    if (Vec3fNormalize(&sp1C) == 0.0) {
        return 0.0f;
    } else {
        f32 ret;
        if (sp1C.y < 0.0f) {
            ret = -acosf(sp1C.x);
        } else {
            ret = acosf(sp1C.x);
        }
        return ret;
    }
}

f32 func_800A9DAC(Vec3f* arg0) {
    Vec3f sp1C = *arg0;
    if (Vec3fNormalize(&sp1C) == 0.0) {
        return 0.0f;
    } else {
        return -asinf(sp1C.z);
    }
}

#ifdef NON_MATCHING
void func_800A9E1C(GObj* obj) {
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, obj->data.cam->bgColor >> 24, obj->data.cam->bgColor >> 16, obj->data.cam->bgColor >> 8, obj->data.cam->bgColor);
    gDPSetBlendColor(gMainGfxPos[0]++, 0, 0, 0, 15);
    gDPSetAlphaCompare(gMainGfxPos[0]++, G_AC_THRESHOLD);
    renRenderModelTypeA(obj);
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, 255, 255, 255, 255);
    gDPSetAlphaCompare(gMainGfxPos[0]++, G_AC_NONE);
}
#else
void func_800A9E1C(GObj* obj);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9E1C.s")
#endif

GObj* func_800A9F10(void (*procFunc)(GObj*), s32 link, Sprite* sprite) {
    return ohCreateSprite(1 << link, NULL, link, link, renDrawSprite, DL_LINK_2, link, CAM_MASK_DL_LINK_2, sprite, 0, procFunc, 0);
}

GObj* func_800A9F84(void (*procFunc)(GObj*), s32 link, Sprite* sprite) {
    return ohCreateSprite(1 << link, NULL, link, link, renDrawSprite, DL_LINK_30, link, CAM_MASK_DL_LINK_30, sprite, 0, procFunc, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9FF8.s")
void func_800A9FF8(GObj*);

void func_800AA1DC(void) {
    GObj* camObj;
    s32 unused[2];

    camObj = func_800A8A84(NULL, DL_LINK_2, LINK_POKEMON);
    camObj->fnRender = func_800A9FF8;
    camObj->data.cam->flags = CAMERA_FLAG_4;
    func_800A844C(camObj->data.cam, 0, 0, viScreenWidth, viScreenHeight);

    camObj = func_800A8A84(NULL, DL_LINK_30, LINK_10);
    camObj->fnRender = func_800A9FF8;
    camObj->data.cam->flags = CAMERA_FLAG_4;
    func_800A844C(camObj->data.cam, 0, 0, viScreenWidth, viScreenHeight);
}

s32 func_800AA28C(s32 buttons, s32 contId) {
    s32 i;
    s32 v1 = 0;
    s32 mask = 1;

    for (i = 0; i < 24; i++, mask *= 2) {
        if (!(D_800AF3AC & mask)) {
            v1 |= mask & buttons;
        } else if (!(mask & buttons)) {
            D_800BE2F0[contId][i] = 0;
        } else if (D_800BE2F0[contId][i] < D_800AF3A4) {
            D_800BE2F0[contId][i]++;
            D_800BE470[contId][i] = D_800AF3A8;
            v1 |= buttons & mask;
        } else if (D_800BE470[contId][i] >= D_800AF3A8) {
            D_800BE470[contId][i] = 0;
        } else {
            D_800BE470[contId][i]++;
            v1 |= mask;
        }
    }
    return v1;
}

UnkStruct800BEDF8* func_800AA38C(s32 arg0) {
    UnkStruct800BEDF8* ptr;
    ControllerInput* contInput;
    u32 buttons;
    s32 i;

    if (arg0 < 0 || arg0 > 3) {
        return &D_800BEDF8[0];
    }

    if (D_800AF3A0 != 0) {
        return &D_800BEDF8[arg0];
    }

    ptr = D_800BEDF8;
    for (i = 0; i < 4; ptr++, i++) {
        contInput = &gContInput[i];

        if (D_800AF3B8 == 1 && i == 0) {
            contInput->stickX = D_800BEDF0.stickX;
            contInput->stickY = D_800BEDF0.stickY;
            contInput->buttons = D_800BEDF0.buttons;
        }

        ptr->stickX = (f32)contInput->stickX / 80.0;
        ptr->stickY = (f32)contInput->stickY / 80.0;
        ptr->unk_10 = 0.0f;

        if (ptr->stickX > 1.0) {
            ptr->stickX = 1.0f;
        } else if (ptr->stickX < -1.0) {
            ptr->stickX = -1.0f;
        }
        if (ptr->stickY > 1.0) {
            ptr->stickY = 1.0f;
        } else if (ptr->stickY < -1.0) {
            ptr->stickY = -1.0f;
        }

        buttons = contInput->buttons;
        if (ptr->stickX > 0.3) {
            buttons |= STICK_SLOW_RIGHT;
        } else if (ptr->stickX < -0.3) {
            buttons |= STICK_SLOW_LEFT;
        }
        if (ptr->stickY > 0.3) {
            buttons |= STICK_SLOW_UP;
        } else if (ptr->stickY < -0.3) {
            buttons |= STICK_SLOW_DOWN;
        }
        if (ptr->stickX > 0.7) {
            buttons |= STICK_RIGHT;
        } else if (ptr->stickX < -0.7) {
            buttons |= STICK_LEFT;
        }
        if (ptr->stickY > 0.7) {
            buttons |= STICK_UP;
        } else if (ptr->stickY < -0.7) {
            buttons |= STICK_DOWN;
        }

        ptr->currentButtons = func_800AA28C(buttons, i);
        ptr->pressedButtons = ptr->notPressedButtons & ptr->currentButtons;
        ptr->releasedButtons = ~(ptr->notPressedButtons | ptr->currentButtons);
        ptr->notPressedButtons = ~(ptr->currentButtons);
        ptr->unk_00 = D_800AF3B0;
        D_800AF3A0 = 1;
    }

    D_800BEE98 = ptr;
    D_800AF3B0++;
    return &D_800BEDF8[arg0];
}

// TODO requires bss migration
#ifdef NON_MATCHING
UnkStruct800BEDF8* func_800AA740(s32 arg0) {
    s32 i;
    static UnkStruct800BEDF8* ptr; // D_800BEF40

    if (arg0 < 0 || arg0 > 3) {
        return &D_800BEEA0[0];
    }

    // clang-format off
    if (D_800AF3A0 != 0) { return &D_800BEEA0[arg0]; }
    // clang-format on

    ptr = D_800BEEA0;
    for (i = 0; i < gNumControllers; i++, ptr++) {
        ptr->stickX = 0.0f;
        ptr->stickY = 0.0f;
        ptr->unk_10 = 0.0f;
        ptr->currentButtons = 0;
        ptr->pressedButtons = 0;
        ptr->releasedButtons = 0;
        ptr->notPressedButtons = ~0;
        ptr->unk_00 = D_800AF3B0;
    }
    return &D_800BEEA0[arg0];
}
#else
UnkStruct800BEDF8* func_800AA740(s32 arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA740.s")
#endif

void func_800AA81C(void) {
    D_800AF3A0 = 0;
}

void func_800AA828(s32 arg0) {
    D_800AF3B8 = arg0;
}

s32 func_800AA834(void) {
    return D_800AF3BC * 8;
}

void func_800AA844(u32 arg0) {
    D_800AF3BC = arg0 / 8;
}

s32 func_800AA854(void) {
    return 0xF00000;
}

void func_800AA85C(s32 arg0, s32 arg1) {
    D_800AF3A4 = arg0;
    D_800AF3A8 = arg1;
}

void func_800AA870(s32 arg0) {
    D_800AF3AC = arg0;
}

s32 func_800AA87C(void) {
    return D_800AF3AC;
}

f32 func_800AA888(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3) {
    Vec3f sp2C = *arg2;
    Vec3f sp20;
    f32 ret;

    Vec3fSub(&sp2C, arg1);
    sp2C.z = 0.0f;
    if (Vec3fNormalize(&sp2C) == 0.0f) {
        return 0.0f;
    }

    sp20 = *arg0;
    sp20.z = 0.0f;
    if (Vec3fNormalize(&sp20) == 0.0f) {
        return 0.0f;
    }

    ret = Vec3fAngleDiff(&sp2C, &sp20);
    if (ret > arg3) {
        ret = arg3;
    }
    if (Vec3fAngleDiff(&sp2C, &arg0[1]) > PI_2) {
        ret = -ret;
    }
    return ret;
}

f32 func_800AA994(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3) {
    Vec3f sp2C = *arg1;
    Vec3f sp20;
    f32 ret;

    Vec3fSub(&sp2C, arg2);
    sp2C.z = 0.0f;
    if (Vec3fNormalize(&sp2C) == 0.0f) {
        return 0.0f;
    }

    sp20 = *arg0;
    sp20.z = 0.0f;
    if (Vec3fNormalize(&sp20) == 0.0f) {
        return 0.0f;
    }

    ret = Vec3fAngleDiff(&sp2C, &sp20);
    if (ret > arg3) {
        ret = arg3;
    }
    if (Vec3fAngleDiff(&sp2C, &arg0[1]) > PI_2) {
        ret = -ret;
    }
    return ret;
}

f32 func_800AAAA8(Vec3f* arg0, Vec3f* arg1) {
    Vec3f sp24 = *arg0;
    Vec3f sp18 = *arg1;

    sp24.z = 0.0f;
    sp18.z = 0.0f;
    return Vec3fDistance(&sp24, &sp18);
}

void func_800AAB10(void* romSrc, void* ramDst, u32 nbytes) {
    dmaReadRom(romSrc, ramDst, nbytes);
}

void func_800AAB30(u32 romDst, void* ramSrc, u32 nbytes) {
    dmaWriteRom(ramSrc, romDst, nbytes);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AAB5C.s")
void func_800AAB5C(GObj*);

void func_800AADF0(s32 arg0) {
    D_800AF3C0 = arg0;
    func_800067DC();
}

void func_800AAE14(s32 arg0) {
    D_800BEF48 = arg0;
}

void func_800AAE20(void) {
}

#ifdef NON_MATCHING
void func_800AAE28(void) {
    s32 i, j;

    D_800AF3B0 = 0;
    func_800A85E8(func_800AAB5C, LINK_PLAYER, DL_LINK_0, NULL);
    func_800A8B2C(NULL, DL_LINK_0);
    func_800AA1DC();

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 24; j++) {
            D_800BE2F0[i][j] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AAE28.s")
#endif
