#include "common.h"

typedef struct UnkPesterBall {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ GObj* unk_08;
} UnkPesterBall;

typedef struct UnkPesterBall2 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f unk_08;
} UnkPesterBall2;

typedef struct UnkTangyViper {
    /* 0x00 */ struct UnkTangyViper* unk_00;
    /* 0x04 */ struct UnkTangyViper* unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} UnkTangyViper; // size = 0x10

extern UnkTangyViper D_803AEF68_54F378[20];
extern s32 D_803AF0AC_54F4BC;
extern UnkTangyViper* D_803AF0B0_54F4C0;
extern f32 D_80382C1C_52302C;
extern f32 D_80382C20_523030;
extern f32 D_80382C24_523034;
extern s32 D_803AF0BC_54F4CC;
extern s32 D_803AF0C0_54F4D0;
extern s32 D_803AF0C4_54F4D4;
extern UnkPesterBall* D_803AF0A8_54F4B8;
extern UnkEC64Arg3 D_800E9138[];
extern UnkEC64Arg3 D_800EAED0[];
extern Texture** D_800E8EB8[];
extern Texture** D_800EAC58[];
extern AnimCmd** D_800E91C0[];
extern AnimCmd** D_800EAF60[];
extern Vec3f D_8038A398_52A7A8;
extern u8 D_803AF0C8_54F4D8;
extern GObjFunc D_80382EB4_5232C4;

void func_8035C8F4_4FCD04(GObj*);
UnkPesterBall2* func_8035EBBC_4FEFCC(void);

f32 func_80359740_4F9B50(Vec3f* v1, Vec3f* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void func_80359770_4F9B80(GObj* obj, GObjFunc func) {
    GObjProcess* proc;
    GObjProcess* next;

    if (obj == NULL) {
        obj = omCurrentObject;
    }

    proc = obj->processListHead;
    while (proc != NULL) {
        next = proc->next;
        if (func == proc->function) {
            omEndProcess(proc);
        }
        proc = next;
    }
}

void func_803597D4_4F9BE4(void) {
    s32 i;

    D_803AF0A8_54F4B8 = NULL;
    D_803AF0AC_54F4BC = 0;
    D_803AF0B0_54F4C0 = D_803AEF68_54F378;

    for (i = 0; i < ARRAY_COUNT(D_803AEF68_54F378); i++) {
        if (i == 0) {
            D_803AEF68_54F378[i].unk_00 = NULL;
        } else {
            D_803AEF68_54F378[i].unk_00 = &D_803AEF68_54F378[i - 1];
        }
        if (i == ARRAY_COUNT(D_803AEF68_54F378) - 1) {
            D_803AEF68_54F378[i].unk_04 = NULL;
        } else {
            D_803AEF68_54F378[i].unk_04 = &D_803AEF68_54F378[i + 1];
        }
        D_803AEF68_54F378[i].unk_08 = 0;
        D_803AEF68_54F378[i].unk_0C = i;
    }
    D_803AF0BC_54F4CC = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359880_4F9C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359894_4F9CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359900_4F9D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359970_4F9D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_803599E8_4F9DF8.s")
void func_803599E8_4F9DF8(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359A50_4F9E60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359B0C_4F9F1C.s")
s32 func_80359B0C_4F9F1C(void);
/*
extern s32 D_80382EB0_5232C0;

s32 func_80359B0C_4F9F1C(void) {
    D_80382EB0_5232C0++;
    if (D_80382EB0_5232C0 >= 20) {
        D_80382EB0_5232C0 = 0;
    }

    if (D_80382EB0_5232C0 < 20) {

    }
}
*/

void func_80359CD4_4FA0E4(GObj* obj) {
    ohWait(3);
    obj->flags &= ~GOBJ_FLAG_HIDDEN;
    omEndProcess(NULL);
}

void func_80359D14_4FA124(GObj* obj, Vec3f* pos, Vec3f* arg2) {
    Vec3f velocity;
    DObj* model;
    UnkPesterBall2* ball;

    model = obj->data.dobj;

    model->position.v.x = pos->x;
    model->position.v.y = pos->y;
    model->position.v.z = pos->z;

    velocity.x = D_80382C1C_52302C - model->position.v.x;
    velocity.y = D_80382C20_523030 - model->position.v.y + 100.0f;
    velocity.z = D_80382C24_523034 - model->position.v.z;
    Vec3fNormalize(&velocity);
    Vec3fScale(&velocity, 50.0f);
    Vec3fAdd(&velocity, arg2);
    
    ball = obj->userData;
    ball->unk_01 = 1;
    ball->unk_03 = 0;
    ball->unk_04 = 0.0f;
    ball->unk_08.x = velocity.x;
    ball->unk_08.y = velocity.y;
    ball->unk_08.z = velocity.z;
    func_803599E8_4F9DF8(obj);
    obj->flags |= GOBJ_FLAG_HIDDEN;
    omCreateProcess(obj, D_80382EB4_5232C4, D_803AF0C8_54F4D8, 7);
    omCreateProcess(obj, func_80359CD4_4FA0E4, 0, 7);
}

void func_80359E38_4FA248(GObj* source, s32 cmd) {
    s32* cmdPtr = &cmd; // TODO find better match
    if (*cmdPtr == 100) {
        func_8035C8F4_4FCD04(omCurrentObject);
    }
}

void func_80359E6C_4FA27C(GObj* arg0) {
    cmdProcessCommands(func_80359E38_4FA248);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359E94_4FA2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359EB4_4FA2C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359F68_4FA378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035A110_4FA520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035A150_4FA560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035A190_4FA5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035A1B8_4FA5C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035A26C_4FA67C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035AA14_4FAE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B088_4FB498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B128_4FB538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B340_4FB750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B528_4FB938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B938_4FBD48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C2D4_4FC6E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C35C_4FC76C.s")

void spawnPesterBall(Vec3f* arg0, Vec3f* arg1) {
    GObj* ballObj;
    UnkPesterBall2* ball;

    if (D_803AF0C0_54F4D0 >= 5 && D_803AF0A8_54F4B8 != NULL) {
        func_8035C8F4_4FCD04(D_803AF0A8_54F4B8->unk_08);
    }
    D_803AF0BC_54F4CC++;
    D_803AF0C0_54F4D0++;    
    ballObj = omAddGObj(func_80359B0C_4F9F1C(), func_80359E6C_4FA27C, 4, 0x80000000);
    omLinkGObjDL(ballObj, renderModelTypeBFogged, 3, 0x80000000, -1);
    anim_func_80010230(ballObj, D_800E9138, D_800E8EB8, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
    omCreateProcess(ballObj, animUpdateModelTreeAnimation, 1, 3);
    animSetModelTreeTextureAnimation(ballObj, D_800E91C0, 0);
    animSetTextureAnimationSpeed(ballObj, 0.4f);
    ballObj->data.dobj->scale.v.x = 0.1f;
    ballObj->data.dobj->scale.v.y = 0.1f;
    ballObj->data.dobj->scale.v.z = 0.1f;
    ball = func_8035EBBC_4FEFCC();
    ballObj->userData = ball;
    ball->unk_00 = 162;
    ballObj->flags |= GOBJ_FLAG_HIDDEN;
    func_80359770_4F9B80(ballObj, func_80359CD4_4FA0E4);
    auPlaySound(8);
    func_80359D14_4FA124(ballObj, arg0, arg1);
}

void spawnApple(Vec3f* arg0, Vec3f* arg1) {
    GObj* ballObj;
    UnkPesterBall2* ball;

    if (D_803AF0C4_54F4D4 >= 5 && D_803AF0A8_54F4B8 != NULL) {
        func_8035C8F4_4FCD04(D_803AF0A8_54F4B8->unk_08);
    }
    D_803AF0BC_54F4CC++;
    D_803AF0C4_54F4D4++;    
    ballObj = omAddGObj(func_80359B0C_4F9F1C(), func_80359E6C_4FA27C, 4, 0x80000000);
    omLinkGObjDL(ballObj, renderModelTypeBFogged, 3, 0x80000000, -1);
    anim_func_80010230(ballObj, D_800EAED0, D_800EAC58, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
    omCreateProcess(ballObj, animUpdateModelTreeAnimation, 1, 3);
    animSetModelTreeTextureAnimation(ballObj, D_800EAF60, 0);
    animSetTextureAnimationSpeed(ballObj, 0.4f);
    ballObj->data.dobj->scale.v.x = 0.1f;
    ballObj->data.dobj->scale.v.y = 0.1f;
    ballObj->data.dobj->scale.v.z = 0.1f;
    ball = func_8035EBBC_4FEFCC();
    ballObj->userData = ball;
    ball->unk_00 = 163;
    ballObj->flags |= GOBJ_FLAG_HIDDEN;
    func_80359770_4F9B80(ballObj, func_80359CD4_4FA0E4);
    auPlaySound(9);
    func_80359D14_4FA124(ballObj, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C74C_4FCB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C7E4_4FCBF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C834_4FCC44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C86C_4FCC7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C8C0_4FCCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C8F4_4FCD04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C9CC_4FCDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035CA1C_4FCE2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035CA28_4FCE38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035CA6C_4FCE7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035CAB0_4FCEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035CB18_4FCF28.s")
