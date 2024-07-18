#include "common.h"

extern s32 D_800AF3A0;
extern u64 D_800AF3B0;
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8B2C.s")
void func_800A8B2C(s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8C5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8E34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8ED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A8F5C.s")

Vec3f* func_800A904C(Vec3f* arg0, Mtx3f arg1, Vec3f* arg2, f32 arg3) {
    arg0->x += (arg1[0][0] * arg2->x + arg1[1][0] * arg2->y + arg1[2][0] * arg2->z) * arg3;
    arg0->y += (arg1[0][1] * arg2->x + arg1[1][1] * arg2->y + arg1[2][1] * arg2->z) * arg3;
    arg0->z += (arg1[0][2] * arg2->x + arg1[1][2] * arg2->y + arg1[2][2] * arg2->z) * arg3;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A910C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A929C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A98B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9A7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9C04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9CA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800A9DAC.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA828.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA85C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA87C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AA994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AAAA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AAB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/53AD0/func_800AAB30.s")

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

    //D_800AF3B0.unk_00 = D_800AF3B0.unk_04 = 0;
    func_800A85E8(func_800AAB5C, LINK_PLAYER, DL_LINK_0, NULL);
    func_800A8B2C(0, 0);
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
