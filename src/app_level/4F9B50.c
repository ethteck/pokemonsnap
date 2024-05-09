#include "common.h"
#include "world/world.h"

#define GET_ITEM(x) ((UnkPesterBall2*)((x)->userData))

typedef struct UnkPesterBall2 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f unk_08;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ Vec3f unk_20;
} UnkPesterBall2;

typedef struct UnkTangyViper {
    /* 0x00 */ struct UnkTangyViper* unk_00;
    /* 0x04 */ struct UnkTangyViper* unk_04;
    /* 0x08 */ GObj* unk_08;
    /* 0x0C */ s32 unk_0C;
} UnkTangyViper; // size = 0x10

extern UnkTangyViper D_803AEF68_54F378[20];
extern UnkTangyViper* D_803AF0AC_54F4BC;
extern UnkTangyViper* D_803AF0B0_54F4C0;
extern f32 D_80382C1C_52302C;
extern f32 D_80382C20_523030;
extern f32 D_80382C24_523034;
extern s32 D_803AF0BC_54F4CC;
extern s32 D_803AF0C0_54F4D0;
extern s32 D_803AF0C4_54F4D4;
extern UnkTangyViper* D_803AF0A8_54F4B8;
extern UnkEC64Arg3 D_800E9138[];
extern UnkEC64Arg3 D_800EAED0[];
extern Texture** D_800E8EB8[];
extern Texture** D_800EAC58[];
extern AnimCmd** D_800E91C0[];
extern AnimCmd** D_800EAF60[];
extern Vec3f D_8038A398_52A7A8;
extern u8 D_803AF0C8_54F4D8;
extern GObjFunc D_80382EB4_5232C4;
extern s32 D_803AF0B4_54F4C4;
extern s32 D_803AF0B8_54F4C8;
extern s32 D_80382EB0_5232C0;
extern UnkEC64Arg3 D_800EB430_8B0C50[];
extern Texture** D_800EB510[];
extern AnimCmd* D_800EAFB0[];
extern AnimCmd** D_800EB0C0[];
extern UnkEC64Arg3 D_800EDAB0[];
extern Texture** D_800EDB90[];
extern AnimCmd* D_800ED5B0[];
extern AnimCmd** D_800ED6B0[];
extern DObj* D_80382C04_523014;
extern s32 D_80382ED8_5232E8;
extern s32 D_80382EDC_5232EC;
extern s32 D_80382EC0_5232D0[];
extern OSTime D_80382EE0_5232F0;
extern s32 D_80382ECC_5232DC[];
extern s32 D_80382EB8_5232C8;
extern s32 D_80382EBC_5232CC;

void func_8035C8F4_4FCD04(GObj*);
void func_8035FCA0_5000B0(void);
void func_8035EC1C_4FF02C(void*);
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

void func_80359880_4F9C90(void) {
    D_803AF0B8_54F4C8 = 0;
    D_803AF0B4_54F4C4 = 0;
}

GObj* func_80359894_4F9CA4(void) {
    while (D_803AF0B4_54F4C4 < 20) {
        GObj* obj = D_803AEF68_54F378[D_803AF0B4_54F4C4++].unk_08;
        if (obj != NULL && GET_ITEM(obj)->unk_01 > 0) {
            return obj;
        }
    }
    return NULL;
}

GObj* func_80359900_4F9D10(void) {
    while (D_803AF0B4_54F4C4 < 20) {
        GObj* obj = D_803AEF68_54F378[D_803AF0B4_54F4C4++].unk_08;
        if (obj != NULL && GET_ITEM(obj)->unk_01 == 2) {
            return obj;
        }
    }
    return NULL;
}

GObj* func_80359970_4F9D80(GObj* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803AEF68_54F378); i++) {
        if (D_803AEF68_54F378[i].unk_08 == arg0) {
            return arg0;
        }
    }
    return NULL;
}

#ifdef NON_MATCHING
void func_803599E8_4F9DF8(GObj* obj) {
    UnkTangyViper* v1;
    UnkTangyViper* v0;

    v0 = D_803AF0B0_54F4C0;
    v1 = D_803AF0B0_54F4C0;    
    if (D_803AF0B0_54F4C0 == NULL) {
        return;
    }
    D_803AF0B0_54F4C0 = D_803AF0B0_54F4C0->unk_04;
    
    v1->unk_00 = D_803AF0AC_54F4BC;
    v1->unk_04 = NULL;    
    
    if (v1->unk_00 != NULL) {
        D_803AF0AC_54F4BC = v1;
        v1->unk_00->unk_04 = v1;
    } else {
        D_803AF0AC_54F4BC = v0;
        D_803AF0A8_54F4B8 = v0;
    }

    v0->unk_08 = obj;
    GET_ITEM(obj)->unk_02 = v0->unk_0C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_803599E8_4F9DF8.s")
void func_803599E8_4F9DF8(GObj* obj);
#endif

//#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359A50_4F9E60.s")
void func_80359A50_4F9E60(GObj* arg0) {
    UnkTangyViper* v0;

    if (GET_ITEM(arg0)->unk_00 == 163) {
        cmdSendCommandToLink(3, 21, arg0);
    }

    v0 = &D_803AEF68_54F378[GET_ITEM(arg0)->unk_02];
    if (v0->unk_00 != NULL) {
        v0->unk_00->unk_04 = v0->unk_04;
    } else {
        D_803AF0A8_54F4B8 = v0->unk_04;
    }
    if (v0->unk_04 != NULL) {
        v0->unk_04->unk_00 = v0->unk_00;
    } else {
        D_803AF0AC_54F4BC = v0->unk_00;
    }

    v0->unk_04 = D_803AF0B0_54F4C0;
    v0->unk_08 = NULL;
    D_803AF0B0_54F4C0 = v0;
}

#ifdef NON_MATCHING
// loop not unrolled
s32 func_80359B0C_4F9F1C(void) {
    s32 i;
    
    D_80382EB0_5232C0++;
    if (D_80382EB0_5232C0 >= 20) {
        D_80382EB0_5232C0 = 0;
    }
    
    for (i = D_80382EB0_5232C0; i < 20; i++) {
        if (D_803AEF68_54F378[i].unk_08 == NULL) {
            return 300 + i;
        }
    }
    for (i = 0; i < D_80382EB0_5232C0; i++) {
        if (D_803AEF68_54F378[i].unk_08 == NULL) {
            return 300 + i;
        }
    }
    return 300;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_80359B0C_4F9F1C.s")
s32 func_80359B0C_4F9F1C(void);
#endif


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

void func_80359E94_4FA2A4(GObj* arg0) {
    omDeleteGObj(arg0);
}

void func_80359EB4_4FA2C4(GObj* arg0) {
    f32 animTime = 0.0f;

    while (TRUE) {
        if (60.0f - arg0->animationTime < 0.9f) {
            break;
        }
        if (animTime < 0.0f) {
            break;
        }
        animTime = arg0->animationTime;
        ohWait(1);
    }
    omCreateProcess(arg0, func_80359E94_4FA2A4, 1, 7);
    omEndProcess(NULL);
}

void func_80359F68_4FA378(GObj* arg0, UnkEC64Arg3* arg1, Texture*** arg2, AnimCmd** arg3, AnimCmd*** arg4) {
    DObj* model = arg0->data.dobj;
    GObj* newObj;
    GroundResult sp44;
    s32 i;

    animSetTextureAnimationSpeed(arg0, 0.0f);
    newObj = omAddGObj(func_80359B0C_4F9F1C(), ohUpdateDefault, 4, 0x80000000);
    omLinkGObjDL(newObj, renderModelTypeDFogged, 3, 0x80000000, -1);
    anim_func_80010230(newObj, arg1, arg2, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
    omCreateProcess(newObj, animUpdateModelTreeAnimation, 1, 3);
    animSetModelTreeAnimation(newObj, arg3, 0.0f);
    animSetModelTreeTextureAnimation(newObj, arg4, 0.0f);
    animSetModelAndTextureAnimationSpeed(newObj, 0.9f);
    getGroundAt(model->position.v.x, model->position.v.z, &sp44);
    newObj->data.dobj->position.v.x = model->position.v.x;
    newObj->data.dobj->position.v.y = sp44.height;
    newObj->data.dobj->position.v.z = model->position.v.z;
    newObj->data.dobj->scale.v.x = 0.1f;
    newObj->data.dobj->scale.v.y = 0.1f;
    newObj->data.dobj->scale.v.z = 0.1f;
    newObj->userData = NULL;
    omCreateProcess(newObj, func_80359EB4_4FA2C4, 0, 7);
    for (i = 59; i > 0; i--) {
        model->position.v.y -= 2.0f;
        ohWait(1);
    }
    func_8035C8F4_4FCD04(arg0);
    omEndProcess(NULL);
}

void func_8035A110_4FA520(GObj* obj) {
    func_80359F68_4FA378(obj, D_800EB430_8B0C50, D_800EB510, D_800EAFB0, D_800EB0C0);
}

void func_8035A150_4FA560(GObj* obj) {
    func_80359F68_4FA378(obj, D_800EDAB0, D_800EDB90, D_800ED5B0, D_800ED6B0);
}

void func_8035A190_4FA5A0(GObj* arg0) {
    func_8035C8F4_4FCD04(arg0);
    omEndProcess(NULL);
}

void func_8035A1B8_4FA5C8(DObj* arg0, s32 arg1) {
    f32 dist;
    Vec3f sp38;
    Vec3f sp2C;
    Vec3f sp20;    

    sp2C.x = arg0->position.v.x;
    sp2C.y = arg0->position.v.y;
    sp2C.z = arg0->position.v.z;
    sp38.x = GET_TRANSFORM(D_80382C04_523014)->pos.v.x;
    sp38.y = GET_TRANSFORM(D_80382C04_523014)->pos.v.y;
    sp38.z = GET_TRANSFORM(D_80382C04_523014)->pos.v.z;
    dist = Vec3fDirection(&sp20, &sp38, &sp2C);
    if (dist < 3000.0f) {
        auPlaySoundWithVolume(arg1, 30720.0f - (dist / 3000.0f) * 30720.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035A26C_4FA67C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035AA14_4FAE24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B088_4FB498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B128_4FB538.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B340_4FB750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B528_4FB938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B938_4FBD48.s")
void func_8035B938_4FBD48(GObj*);

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

// requires bss
#ifdef NON_MATCHING
void func_8035C74C_4FCB5C(void) {
    s32 temp_t8;

    if (D_80382EDC_5232EC) {
        D_80382ED8_5232E8++;
        if (D_80382ED8_5232E8 >= 3) {
            D_80382ED8_5232E8 -= 3;
        }
    }
    auStopSong(0);
    auPlaySong(0, D_80382EC0_5232D0[D_80382ED8_5232E8]);
    D_80382EDC_5232EC = TRUE;
    D_80382EE0_5232F0 = D_80096968;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C74C_4FCB5C.s")
void func_8035C74C_4FCB5C(void);
#endif

// requires bss
#ifdef NON_MATCHING
void func_8035C7E4_4FCBF4(void) {
    s32 temp_t8;

    if (D_80382EDC_5232EC) {
        auStopSong(0);
    }
    auStopSong(0);
    D_80382EDC_5232EC = FALSE;
    D_80382EE0_5232F0 = D_80096968;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035C7E4_4FCBF4.s")
void func_8035C7E4_4FCBF4(void);
#endif


s32 func_8035C834_4FCC44(void) {
    if (D_80382EDC_5232EC) {
        return D_80382ECC_5232DC[D_80382ED8_5232E8];
    } else {
        return 0;
    }
}

s32 func_8035C86C_4FCC7C(void) {
    if (D_80382EE0_5232F0 != D_80096968) {
        return auIsBGMPlaying(0);
    } else {
        return -1;
    }
}

void func_8035C8C0_4FCCD0(GObj* arg0) {
    func_8035FCA0_5000B0();
    func_8035EC1C_4FF02C(arg0->userData);
    omDeleteGObj(arg0);
}

void func_8035C8F4_4FCD04(GObj* arg0) {
    UnkPesterBall2* item;

    if (arg0 == NULL) {
        return;
    }
    item = GET_ITEM(arg0);
    if (item->unk_01 == 0 || (item->unk_03 & 4)) {
        return;
    }

    item->unk_03 |= 4;
    func_80359A50_4F9E60(arg0);
    arg0->flags |= GOBJ_FLAG_HIDDEN;
    func_80359770_4F9B80(arg0, func_80359CD4_4FA0E4);
    omCreateProcess(arg0, func_8035C8C0_4FCCD0, 1, 4);
    D_803AF0BC_54F4CC--;
    if (item->unk_00 == 162) {
        D_803AF0C0_54F4D0--;
    } else {
        D_803AF0C4_54F4D4--;
    }
    item->unk_01 = 0;
}

void func_8035C9CC_4FCDDC(GObjFunc arg0, u8 arg1, s32 arg2) {
    if (arg0 != NULL) {
        D_80382EB4_5232C4 = arg0;
        D_803AF0C8_54F4D8 = arg1;
        return;
    }
    D_80382EB4_5232C4 = func_8035B938_4FBD48;
    D_803AF0C8_54F4D8 = 1;
    if (arg2 != 0) {
        D_80382EB8_5232C8 = arg2;
    }
}

void func_8035CA1C_4FCE2C(s32 arg0) {
    D_80382EBC_5232CC = arg0;
}

void func_8035CA28_4FCE38(void) {
    GObj* ptr;

    ptr = omGObjListHead[4];
    while (ptr != NULL) {
        ohPauseObjectProcesses(ptr);
        ptr = ptr->next;
    }
}

void func_8035CA6C_4FCE7C(void) {
    GObj* ptr;

    ptr = omGObjListHead[4];
    while (ptr != NULL) {
        ohResumeObjectProcesses(ptr);
        ptr = ptr->next;
    }
}

void func_8035CAB0_4FCEC0(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (D_803AEF68_54F378[i].unk_08 != NULL && !(GET_ITEM(D_803AEF68_54F378[i].unk_08)->unk_03 & 2)) {
            func_8035C8F4_4FCD04(D_803AEF68_54F378[i].unk_08);
        }
    }
}

void func_8035CB18_4FCF28(f32 deltaX, f32 deltaY, f32 deltaZ) {
    GObj* ptr;
    UnkPesterBall2* item;

    ptr = omGObjListHead[4];
    while (ptr != NULL) {
        DObj* model = ptr->data.dobj;

        model->position.v.x += deltaX;
        model->position.v.y += deltaY;
        model->position.v.z += deltaZ;
        item = GET_ITEM(ptr);
        if (item != NULL) {
            item->unk_20.x += deltaX;
            item->unk_20.y += deltaY;
            item->unk_20.z += deltaZ;
        }
        ptr = ptr->next;
    }
}
