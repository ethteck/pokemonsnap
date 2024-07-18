#include "common.h"

typedef struct Unk_800A8F0C {
    /* 0x00 */ char unk_00[0x3C];
    /* 0x3C */ Vec3f unk_3C;
    /* 0x48 */ Vec3f unk_48;
} Unk_800A8F0C; // size >= 0x54

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
extern UnkStruct800BEDF8 D_800BEDF8[4];
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
    gobj = ohCreateModel(1 << link, NULL, link, link, renRenderModelTypeA, dllink, link, cameraTag, dlist, TRUE, 0, procFunc, 0);
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
    gobj = ohCreateModel(1 << link, NULL, link, link, renRenderModelTypeA, dllink, link, cameraTag, dlist, TRUE, 1, procFunc, 0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A87B0.s")
void func_800A87B0(GObj* obj, s32 arg3, s32 arg4);

GObj* func_800A88E4(void (*procFunc)(GObj*), s32 link, s32 dllink, s32 arg3, s32 arg4) {
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
    func_800A87B0(gobj, arg3, arg4);
    omCreateProcess(gobj, procFunc, 0, 0);
    model = gobj->data.dobj;
    model->rotation.mtx->kind = MTX_TYPE_ROTATE_RPY;
    return gobj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A89B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8A84.s")
GObj* func_800A8A84(void (*procFunc)(GObj*), s32 arg1, s32 arg2);

GObj* func_800A8B2C(void (*procFunc)(GObj*), s32 arg1) {
    if (procFunc == NULL) {
        D_800AF0D4 = 0;
        return NULL;
    } else {
        return func_800A8A84(procFunc, arg1, 5);
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8D60.s")
void func_800A8D60(Vec3f* arg0, Mtx3f arg1, f32 arg2, f32 arg3, f32 arg4);

void func_800A8E00(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2) {
    func_800A8D60(arg0, arg1, arg2->x, arg2->y, arg2->z);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8E34.s")
void func_800A8E34(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2, f32 arg3, f32 arg4, f32 arg5);

void func_800A8ED4(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2, Vec3f* arg3) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8F5C.s")

Vec3f* func_800A904C(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2, f32 arg3) {
    arg0->x += (arg1[0][0] * arg2->x + arg1[1][0] * arg2->y + arg1[2][0] * arg2->z) * arg3;
    arg0->y += (arg1[0][1] * arg2->x + arg1[1][1] * arg2->y + arg1[2][1] * arg2->z) * arg3;
    arg0->z += (arg1[0][2] * arg2->x + arg1[1][2] * arg2->y + arg1[2][2] * arg2->z) * arg3;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A910C.s")

s32 func_800A9254(GObj* obj, GObjFunc func) {
    GObjProcess* proc;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    for (proc = obj->processListHead; proc != NULL; proc = proc->next) {
        if (proc->function == func) {
            return TRUE;
        }
    }
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A929C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A98B0.s")
void func_800A98B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_800A9A54(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_800A98B0(arg0, arg1, arg2, arg3, 0, arg4);
}

void func_800A9A7C(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_800A98B0(arg0, arg1, D_800AF378[arg4] * arg2, arg3, arg4, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9ACC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9C04.s")

f32 func_800A9CA0(Vec3f* arg0) {
    Vec3f sp1C = *arg0;
    if (Vec3fNormalize(&sp1C) == 0.0) {
        return 0.0f;
    } else {
        return -asinf(sp1C.z);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9D10.s")

f32 func_800A9DAC(Vec3f* arg0) {
    Vec3f sp1C = *arg0;
    if (Vec3fNormalize(&sp1C) == 0.0) {
        return 0.0f;
    } else {
        return -asinf(sp1C.z);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9E1C.s")

GObj* func_800A9F10(void (*procFunc)(GObj*), s32 link, Sprite* sprite) {
    return ohCreateSprite(1 << link, NULL, link, link, renDrawSprite, DL_LINK_2, link, CAM_MASK_DL_LINK_2, sprite, 0, procFunc, 0);
}

GObj* func_800A9F84(void (*procFunc)(GObj*), s32 link, Sprite* sprite) {
    return ohCreateSprite(1 << link, NULL, link, link, renDrawSprite, DL_LINK_30, link, CAM_MASK_DL_LINK_30, sprite, 0, procFunc, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9FF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA1DC.s")
void func_800AA1DC(void);

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA38C.s")

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
        ptr->unk_08 = 0.0f;
        ptr->unk_0C = 0.0f;
        ptr->unk_10 = 0.0f;
        ptr->unk_14 = 0;
        ptr->unk_18 = 0;
        ptr->unk_1C = 0;
        ptr->unk_20 = -1;
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA994.s")

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

    // D_800AF3B0.unk_00 = D_800AF3B0.unk_04 = 0;
    func_800A85E8(func_800AAB5C, LINK_PLAYER, DL_LINK_0, NULL);
    func_800A8B2C(NULL, 0);
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
