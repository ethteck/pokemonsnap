#include "common.h"
#include "world/world.h"

#define GET_ITEM(x) ((UnkPesterBall2*)((x)->userData))

typedef struct UnkPesterBall2 {
    /* 0x00 */ u8 itemID;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f velocity;
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ Vec3f unk_20;
} UnkPesterBall2;

typedef struct UnkTangyViper {
    /* 0x00 */ struct UnkTangyViper* unk_00;
    /* 0x04 */ struct UnkTangyViper* unk_04;
    /* 0x08 */ GObj* unk_08;
    /* 0x0C */ s32 unk_0C;
} UnkTangyViper; // size = 0x10

extern Texture** D_800E8EB8[];
extern UnkEC64Arg3 D_800E9138[];
extern AnimCmd** D_800E91C0[];

extern Texture** D_800EAC58[];
extern UnkEC64Arg3 D_800EAED0[];
extern AnimCmd** D_800EAF60[];

extern AnimCmd* D_800EAFB0[];
extern AnimCmd** D_800EB0C0[];
extern Texture** D_800EB510[];

extern AnimCmd* D_800ED5B0[];
extern AnimCmd** D_800ED6B0[];
extern UnkEC64Arg3 D_800EDAB0[];
extern Texture** D_800EDB90[];

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
extern Vec3f D_8038A398_52A7A8;
extern u8 D_803AF0C8_54F4D8;
extern GObjFunc D_80382EB4_5232C4;
extern s32 D_803AF0B4_54F4C4;
extern s32 D_803AF0B8_54F4C8;
extern s32 D_80382EB0_5232C0;
extern UnkEC64Arg3 D_800EB430_8B0C50[];
extern DObj* D_80382C04_523014;
extern s32 D_80382ED8_5232E8;
extern s32 D_80382EDC_5232EC;
extern s32 D_80382EC0_5232D0[];
extern OSTime D_80382EE0_5232F0;
extern s32 D_80382ECC_5232DC[];
extern void (*D_80382EB8_5232C8)(GObj*, GroundResult*);
extern s32 (*D_80382EBC_5232CC)(Vec3f*, Vec3f*, Vec3f*, Vec3f*);

void func_8035C8F4_4FCD04(GObj*);
void func_8035FCA0_5000B0(void);
void func_8035EC1C_4FF02C(void*);
void func_8035C2D4_4FC6E4(GObj*);
UnkPesterBall2* func_8035EBBC_4FEFCC(void);
f32 func_80363848_503C58(GObj* arg0, Vec3f* arg1);
void func_8035C35C_4FC76C(GObj* arg0);

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

void func_80359A50_4F9E60(GObj* arg0) {
    UnkTangyViper* v0;

    if (GET_ITEM(arg0)->itemID == 163) {
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
    ball->velocity.x = velocity.x;
    ball->velocity.y = velocity.y;
    ball->velocity.z = velocity.z;
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

void func_8035A26C_4FA67C(GObj* arg0, GroundResult* arg1) {
    DObj* model = arg0->data.dobj;
    UnkPesterBall2* item = GET_ITEM(arg0);
    Vec3f sp34;
    Vec3f sp28;
    f32 newvar = 0.5f;
    f32 sp20;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f)
    {
        item->unk_01 = 2;
        arg0->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(arg0, func_8035A190_4FA5A0, 1, 7);
        omEndProcess(NULL);
        return;
    }

    model->position.v.y = arg1->height + 12.0f;
    sp28.x = arg1->normal.x;
    sp28.y = arg1->normal.y;
    sp28.z = arg1->normal.z;
    sp34.x = item->velocity.x;
    sp34.y = item->velocity.y;
    sp34.z = item->velocity.z;
    sp20 = Vec3fNormalize(&sp34);
    Vec3f_func_8001AC98(&sp34, &sp28);

    if (item->itemID == 162) {
        func_8035A1B8_4FA5C8(model, 10);
        if (arg1->type == 0x4C1900 ||
            arg1->type == 0x4C4C33 ||
            arg1->type == 0x7F4C00 ||
            arg1->type == 0x7F7F7F ||
            arg1->type == 0xB2997F)
        {
            if (item->itemID == 162) {
                item->unk_01 = 2;
            }
        }
        arg0->flags |= GOBJ_FLAG_HIDDEN;        
        func_80359770_4F9B80(arg0, func_80359CD4_4FA0E4);
        omCreateProcess(arg0, func_8035C2D4_4FC6E4, 1, 7);
        animSetTextureAnimationSpeed(arg0, 0.0f);
        omEndProcess(NULL);
        return;
    }
    switch (arg1->type) {
        case 0x4C7F00U:
        case 0x996666U:
        case 0xFF9919U:
            if (sp20 > 13.0f) {
                func_8035A1B8_4FA5C8(model, 24);
            }
            sp20 *= 0.2f;
            break;
        case 0x331919:
            if (sp20 > 13.0f) {
                func_8035A1B8_4FA5C8(model, 25);
            }
            sp20 *= 0.3f;
            break;
        case 0x193333U:
        case 0x4C1900U:
        case 0x4C4C33U:
        case 0x7F4C00U:
        case 0x7F667FU:
        case 0x7F7F7FU:
        case 0xFF7FB2U:
            if (sp20 > 13.0f) {
                func_8035A1B8_4FA5C8(model, 25);
            }
            sp20 *= 0.3f;
            break;
        case 0x7F6633U:
            if (sp20 > 13.0f) {
                func_8035A1B8_4FA5C8(model, 25);
            }
            sp20 *= 0.3f;
            break;
        case 0xB2997FU:
            if (sp20 > 13.0f) {
                func_8035A1B8_4FA5C8(model, 27);
            }
            sp20 *= 0.2f;
            break;
        case 0x00FF00U:
        case 0xFF4C19U:
            if (sp20 > 13.0f) {
                func_8035A1B8_4FA5C8(model, 29);
            }
            item->unk_01 = 2;
            omCreateProcess(arg0, func_8035A150_4FA560, 0, 7);
            animSetTextureAnimationSpeed(arg0, 0.0f);
            omEndProcess(NULL);
            return;
        case 0x0019FFU:
        case 0x007F66U:
        case 0x337FB2U:
        case 0x4CCCCCU:
            if (sp20 > 13.0f) {
                func_8035A1B8_4FA5C8(model, 26);
            }
            item->unk_01 = 2;
            omCreateProcess(arg0, func_8035A110_4FA520, 0, 7);
            animSetTextureAnimationSpeed(arg0, 0.0f);
            omEndProcess(NULL);
            return;
        case 0xFF0000U:
            item->unk_01 = 2;
            sp20 = 0.0f;
            omCreateProcess(arg0, func_8035A190_4FA5A0, 1, 7);
            omEndProcess(NULL);
            break;
        default:
            sp20 = 0.0f;
            break;
    }

    if (sp20 < 13.0f && arg1->normal.y < 0.866) { // slope angle > 30 degrees
        if (SQ(arg1->normal.x) + SQ(arg1->normal.z) < SQ(6.5f)) {
            sp20 = 13.0f;
        }
    }

    if (sp20 < 13.0f) {
        item->unk_01 = 2;
        omCreateProcess(arg0, func_8035C35C_4FC76C, 1, 7);
        animSetTextureAnimationSpeed(arg0, 0.0f);
        omEndProcess(NULL);
        return;
    }

    item->velocity.x = sp34.x * sp20;
    item->velocity.y = sp34.y * sp20;
    item->velocity.z = sp34.z * sp20;
    model->position.v.x += item->velocity.x * newvar;
    model->position.v.y += item->velocity.y * newvar;
    model->position.v.z += item->velocity.z * newvar;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f)
    {
        item->unk_01 = 2;
        arg0->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(arg0, func_8035A190_4FA5A0, 1, 7);
        omEndProcess(NULL);
    }
}

void func_8035AA14_4FAE24(GObj* arg0, GroundResult* arg1) {
    DObj* model = arg0->data.dobj;
    UnkPesterBall2* item = GET_ITEM(arg0);
    Vec3f sp4C;
    Vec3f sp40;
    Vec3f sp34;
    f32 newvar = 0.5f;    
    f32 sp2C;
    f32 unused;
    f32 f2;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f)
    {
        item->unk_01 = 2;
        arg0->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(arg0, func_8035A190_4FA5A0, 1, 7);
        omEndProcess(NULL);
        return;
    }
    

    sp40.x = arg1->normal.x;
    sp40.y = arg1->normal.y;
    sp40.z = arg1->normal.z;
    sp34.x = 0.0f;
    sp34.y = model->position.v.y - arg1->height;
    sp34.z = 0.0f;
    sp4C.x = item->velocity.x;
    sp4C.y = item->velocity.y;
    sp4C.z = item->velocity.z;    
    
    sp2C = Vec3fNormalize(&sp4C);
    f2 = sp40.x * sp4C.x + sp40.y * sp4C.y + sp40.z * sp4C.z;
    if (ABS(f2) > 0.001f) {
        Vec3fAddScaled(&model->position.v, &sp4C, - (sp40.x * sp34.x + sp40.y * sp34.y + sp40.z * sp34.z) / f2);
    } else {

    }
    Vec3fAddScaled(&model->position.v, &sp40, 12.0f);
    Vec3f_func_8001AC98(&sp4C, &sp40);

    if (item->itemID == 162) {
        func_8035A1B8_4FA5C8(model, 10);
        if (arg1->type == 0x4C1900 ||
            arg1->type == 0x4C4C33 ||
            arg1->type == 0x7F4C00 ||
            arg1->type == 0x7F7F7F ||
            arg1->type == 0xB2997F)
        {
            if (item->itemID == 162) {
                item->unk_01 = 2;
            }
        }
        arg0->flags |= GOBJ_FLAG_HIDDEN;        
        func_80359770_4F9B80(arg0, func_80359CD4_4FA0E4);
        omCreateProcess(arg0, func_8035C2D4_4FC6E4, 1, 7);
        animSetTextureAnimationSpeed(arg0, 0.0f);
        omEndProcess(NULL);
        return;
    }
    switch (arg1->type) {
        case 0x193333U:
        case 0x4C7F00U:
        case 0x996666U:
        case 0xFF9919U:
            if (sp2C > 13.0f) {
                func_8035A1B8_4FA5C8(model, 24);
            }
            sp2C *= 0.2f;
            break;
        case 0x331919U:
            if (sp2C > 13.0f) {
                func_8035A1B8_4FA5C8(model, 25);
            }
            sp2C *= 0.2f;
            break;
        case 0x4C1900U:
        case 0x4C4C33U:
        case 0x7F4C00U:
        case 0x7F667FU:
        case 0x7F7F7FU:
        case 0xFF7FB2U:
            if (sp2C > 13.0f) {
                func_8035A1B8_4FA5C8(model, 25);
            }
            sp2C *= 0.3f;
            break;
        case 0x7F6633U:
            if (sp2C > 13.0f) {
                func_8035A1B8_4FA5C8(model, 25);
            }
            sp2C *= 0.3f;
            break;
        case 0xB2997FU:
            if (sp2C > 13.0f) {
                func_8035A1B8_4FA5C8(model, 27);
            }
            sp2C *= 0.2f;
            break;
        default:
            sp2C = 0.0f;
            break;
    }

    item->velocity.x = sp4C.x * sp2C;
    item->velocity.y = sp4C.y * sp2C;
    item->velocity.z = sp4C.z * sp2C;
    model->position.v.x += item->velocity.x * newvar;
    model->position.v.y += item->velocity.y * newvar;
    model->position.v.z += item->velocity.z * newvar;

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f)
    {
        item->unk_01 = 2;
        arg0->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(arg0, func_8035A190_4FA5A0, 1, 7);
        omEndProcess(NULL);
    }
}

void func_8035B088_4FB498(GObj* arg0) {
    UnkPesterBall2* item = GET_ITEM(arg0);

    if (item->itemID == 162) {
        UnkBrassLynx* unk = func_800A6C48(3, 0);
        if (unk != NULL) {
            unk->unk_14.x = arg0->data.dobj->position.v.x;
            unk->unk_14.y = arg0->data.dobj->position.v.y;
            unk->unk_14.z = arg0->data.dobj->position.v.z;
        }
    }

    if (item->itemID == 162) {
        cmdSendCommandToLink(3, 10, arg0);
    } else {
        cmdSendCommandToLink(3, 14, arg0);
    }
}

void func_8035B128_4FB538(GObj* arg0, GroundResult* arg1) {
    DObj* model = arg0->data.dobj;
    UnkPesterBall2* item = GET_ITEM(arg0);
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    f32 x3, y3, z3;
    f32 x4, y4, z4;
    f32 d;
    s32 i;

    x1 = item->unk_20.x;
    y1 = item->unk_20.y;
    z1 = item->unk_20.z;
    
    x2 = model->position.v.x;
    y2 = model->position.v.y;
    z2 = model->position.v.z;

    // reuiqred for matching, affects only regalloc
    x3 = 0.0f;
    z3 = 0.0f;
    
    d = sqrtf(SQ(x2 - x1) + SQ(z2 - z1));

    for (i = 0; i < 100; i++) {
        x3 = (x1 + x2) * 0.5f;
        y3 = (y1 + y2) * 0.5f;
        z3 = (z1 + z2) * 0.5f;
        d *= 0.5f;
        if (d <= 1.0f) {
            break;
        }

        func_800E435C_61B0C(x3, z3, arg1);
        if (y3 > arg1->height) {
            x2 = x3;
            y2 = y3;
            z2 = z3;
        } else {
            x1 = x3;
            y1 = y3;
            z1 = z3;
        }
    }
    
    x4 = model->position.v.x;
    y4 = model->position.v.y;
    z4 = model->position.v.z;
    model->position.v.x = x3;
    model->position.v.y = y3;
    model->position.v.z = z3;
    func_8035AA14_4FAE24(arg0, arg1);
    if (D_80382EB8_5232C8 != NULL) {
        D_80382EB8_5232C8(arg0, arg1);
    }

    model->position.v.x = item->unk_20.x + model->position.v.x - x4;
    model->position.v.y = item->unk_20.y + model->position.v.y - y4;
    model->position.v.z = item->unk_20.z + model->position.v.z - z4;
    func_8035B088_4FB498(arg0);
}

#ifdef NON_EQUIVALENT
void func_8035B340_4FB750(GObj* arg0, GroundResult* arg1) {
    DObj* model = arg0->data.dobj;
    UnkPesterBall2* item = GET_ITEM(arg0);
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    s32 i;
    f32 f0;

    x1 = item->unk_20.x;
    y1 = item->unk_20.y;
    z1 = item->unk_20.z;

    x2 = model->position.v.x;
    y2 = model->position.v.y;
    z2 = model->position.v.z;

    item->unk_20.x = model->position.v.x;
    item->unk_20.y = model->position.v.y;
    item->unk_20.z = model->position.v.z;

    for (i = 15; i >= 0; i--) {
        model->position.v.x = (x1 + model->position.v.x) * 0.5;
        model->position.v.y = (y1 + model->position.v.y) * 0.5;
        model->position.v.z = (z1 + model->position.v.z) * 0.5;
        getGroundAt(model->position.v.x, model->position.v.z, arg1);
        f0 = ABS(model->position.v.y - arg1->height);
        if (ABS(f0) <= 0.375f) {
            model->position.v.y = arg1->height;
            break;
        }

        if (model->position.v.y < arg1->height) {
            x2 = model->position.v.x;
            y2 = model->position.v.y;
            z2 = model->position.v.z;
        } else {
            x1 = model->position.v.x;
            y1 = model->position.v.y;
            z1 = model->position.v.z;
        }
    }

    if (i < 0) {
        model->position.v.y = arg1->height;
    }
    item->unk_03 |= 3;
    func_8035A26C_4FA67C(arg0, arg1);
    if (D_80382EB8_5232C8 != NULL) {
        D_80382EB8_5232C8(arg0, arg1);
    }
    func_8035B088_4FB498(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F9B50/func_8035B340_4FB750.s")
void func_8035B340_4FB750(GObj* arg0, GroundResult* arg1);
#endif

void func_8035B528_4FB938(GObj* arg0, GroundResult* arg1) {
    DObj* model = arg0->data.dobj;
    UnkPesterBall2* item = GET_ITEM(arg0);
    Vec3f sp24;
    f32 sp20;

    sp24.x = item->velocity.x;
    sp24.y = item->velocity.y;
    sp24.z = item->velocity.z;
    sp20 = Vec3fNormalize(&sp24);
    func_800E435C_61B0C(item->unk_20.x, item->unk_20.z, arg1);
    if (item->itemID == 162) {
        func_8035A1B8_4FA5C8(model, 10);
        sp20 = 0.0f;
        if (arg1->type == 0x4C1900U ||
            arg1->type == 0x4C4C33 ||
            arg1->type == 0x7F4C00 ||
            arg1->type == 0x7F7F7F ||
            arg1->type == 0xB2997F)
        {
            if (item->itemID == 162) {
                item->unk_01 = 2;
            }
        }
        arg0->flags |= GOBJ_FLAG_HIDDEN;        
        func_80359770_4F9B80(arg0, func_80359CD4_4FA0E4);
        omCreateProcess(arg0, func_8035C2D4_4FC6E4, 1, 7);
        animSetTextureAnimationSpeed(arg0, 0.0f);
        omEndProcess(NULL);
    } else {
        switch (arg1->type) {
            case 0x193333U:
            case 0x4C7F00U:
            case 0x996666U:
            case 0xFF9919U:
                if (sp20 > 13.0f) {
                    func_8035A1B8_4FA5C8(model, 24);
                }
                sp20 *= 0.2f;
                break;
            case 0x331919:
                if (sp20 > 13.0f) {
                    func_8035A1B8_4FA5C8(model, 25);
                }
                sp20 *= 0.2f;
                break;
            case 0x4C1900U:
            case 0x4C4C33U:
            case 0x7F4C00U:
            case 0x7F667FU:
            case 0x7F7F7FU:
            case 0xFF7FB2U:
                if (sp20 > 13.0f) {
                    func_8035A1B8_4FA5C8(model, 25);
                }
                sp20 *= 0.3f;
                break;
            case 0x7F6633U:
                if (sp20 > 13.0f) {
                    func_8035A1B8_4FA5C8(model, 25);
                }
                sp20 *= 0.3f;
                break;
            case 0xB2997FU:
                if (sp20 > 13.0f) {
                    func_8035A1B8_4FA5C8(model, 27);
                }
                sp20 *= 0.2f;
                break;
            default:
                sp20 = 0.0f;
                break;
        }
    }

    Vec3f_func_8001AC98(&sp24, &arg1->normal);
    item->velocity.x = sp24.x * sp20;
    item->velocity.y = sp24.y * sp20;
    item->velocity.z = sp24.z * sp20;
    model->position.v.x = item->unk_20.x + item->velocity.x;
    model->position.v.y = item->unk_20.y + item->velocity.y;
    model->position.v.z = item->unk_20.z + item->velocity.z;
    func_8035B088_4FB498(arg0);
}

void func_8035B938_4FBD48(GObj* arg0) {
    DObj* model = arg0->data.dobj;
    UnkPesterBall2* item = GET_ITEM(arg0);
    Vec3f sp124;
    UnkBrassLynx* v03;
    f32 sp11C;
    GObj* sp118;    
    Pokemon* pokemon;
    Vec3f sp108;
    GroundResult spF4;
    GObj* ptr;
    f32 f2;
    Vec3f spE0;
    Vec3f spD4;
    f32 g = 1.2f;
    f32 absVal;
    GroundResult spB8;
    s32 v02;
    Vec3f spA8;
    Vec3f sp9C;
    Vec3f sp90;
    Vec3f sp84;
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;
    s32 v0;
    f32 f22;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 unused1[3];

    if (model->position.v.x <= -10000.0f ||
        model->position.v.x >= 10000.0f ||
        model->position.v.y <= -10000.0f ||
        model->position.v.y >= 10000.0f ||
        model->position.v.z <= -10000.0f ||
        model->position.v.z >= 10000.0f)
    {
        item->unk_01 = 2;
        arg0->flags |= GOBJ_FLAG_HIDDEN;
        omCreateProcess(arg0, func_8035A190_4FA5A0, 1, 7);
        omEndProcess(NULL);
        return;
    }

    getGroundAt(model->position.v.x, model->position.v.z, &spF4);
    v0 = func_800E435C_61B0C(model->position.v.x, model->position.v.z, &spB8);
    if (v0 && model->position.v.y <= spF4.height && model->position.v.y > spB8.height) {
        func_8035B528_4FB938(arg0, &spB8);
        return;
    }
    if (v0 && model->position.v.y > spB8.height) {
        func_8035B128_4FB538(arg0, &spB8);
        return;
    }
    absVal = ABS(model->position.v.y - spF4.height);
    if (absVal > 0.375f && model->position.v.y < spF4.height) {
        func_8035B340_4FB750(arg0, &spF4);
        return;
    }    
    if (absVal <= 0.375f) {
        item->unk_20.x = model->position.v.x;
        item->unk_20.y = model->position.v.y;
        item->unk_20.z = model->position.v.z;
        item->unk_03 |= 3;
        func_8035A26C_4FA67C(arg0, &spF4);
        if (D_80382EB8_5232C8 != NULL) {
            D_80382EB8_5232C8(arg0, &spF4);
        }
        func_8035B088_4FB498(arg0);
        return;
    }

    item->unk_20.x = model->position.v.x;
    item->unk_20.y = model->position.v.y;
    item->unk_20.z = model->position.v.z;
    sp124.x = item->velocity.x * 0.5f;
    sp124.y = item->velocity.y * 0.5f;
    sp124.z = item->velocity.z * 0.5f;

    v02 = func_800E6238_639E8(&model->position.v, &sp124, &spE0, &spD4);
    if (v02 >= 0) {
        item->unk_03 |= 1;
        if (item->itemID == 162) {
            func_8035A1B8_4FA5C8(model, 10);
            v03 = func_800A6C48(3, 0);
            if (v03 != NULL) {
                v03->unk_14.x = arg0->data.dobj->position.v.x;
                v03->unk_14.y = arg0->data.dobj->position.v.y;
                v03->unk_14.z = arg0->data.dobj->position.v.z;
            }
            arg0->flags |= GOBJ_FLAG_HIDDEN;
            func_80359770_4F9B80(arg0, func_80359CD4_4FA0E4);
            omCreateProcess(arg0, func_8035C2D4_4FC6E4, 1, 7);
            animSetTextureAnimationSpeed(arg0, 0.0f);
            cmdSendCommandToLink(3, 10, arg0);
            omEndProcess(NULL);
        } else if (v02 == 0x3EC || v02 == 0x3EF || v02 == 0x3F2 || v02 == 0x3FE) {
            func_8035A1B8_4FA5C8(model, 25);
        } else {
            func_8035A1B8_4FA5C8(model, 31);
        }
        item->unk_14.x = item->velocity.x;
        item->unk_14.y = item->velocity.y;
        item->unk_14.z = item->velocity.z;
        item->velocity.x = spD4.x;
        item->velocity.y = spD4.y;
        item->velocity.z = spD4.z;
        model->position.v.x = spE0.x;
        model->position.v.y = spE0.y;
        model->position.v.z = spE0.z;
        return;
    }

    if (D_80382EBC_5232CC != NULL && D_80382EBC_5232CC(&model->position.v, &sp124, &spE0, &spD4) >= 0) {
        item->unk_03 |= 1;
        if (item->itemID == 162) {
            func_8035A1B8_4FA5C8(model, 10);
            v03 = func_800A6C48(3, 0);
            if (v03 != NULL) {
                v03->unk_14.x = arg0->data.dobj->position.v.x;
                v03->unk_14.y = arg0->data.dobj->position.v.y;
                v03->unk_14.z = arg0->data.dobj->position.v.z;
            }
            arg0->flags |= GOBJ_FLAG_HIDDEN;
            func_80359770_4F9B80(arg0, func_80359CD4_4FA0E4);
            omCreateProcess(arg0, func_8035C2D4_4FC6E4, 1, 7);
            animSetTextureAnimationSpeed(arg0, 0.0f);
            cmdSendCommandToLink(3, 10, arg0);
            omEndProcess(NULL);
        } else {
            func_8035A1B8_4FA5C8(model, 31);
        }
        item->unk_14.x = item->velocity.x;
        item->unk_14.y = item->velocity.y;
        item->unk_14.z = item->velocity.z;
        item->velocity.x = spD4.x;
        item->velocity.y = spD4.y;
        item->velocity.z = spD4.z;
        model->position.v.x = spE0.x;
        model->position.v.y = spE0.y;
        model->position.v.z = spE0.z;
        return;
    }

    spA8.x = model->position.v.x;
    spA8.y = model->position.v.y;
    spA8.z = model->position.v.z;

    sp78.x = item->velocity.x * 0.5f;
    sp78.y = item->velocity.y * 0.5f;
    sp78.z = item->velocity.z * 0.5f;
    sp4C = Vec3fNormalize(&sp78);

    sp11C = sp4C;
    sp118 = NULL;

    for (ptr = omGObjListHead[3]; ptr != NULL; ptr = ptr->next) {
        pokemon = GET_POKEMON(ptr);
        if (pokemon->tangible && pokemon->collisionRadius > 0.0f) {
            sp54 = func_80363848_503C58(ptr, &sp9C);
            sp50 = Vec3fDirection(&sp84, &sp9C, &spA8);
            f2 = func_80359740_4F9B50(&sp84, &sp78) * sp50;
            if (f2 > 0.0f) {
                if (SQ(sp54) < SQ(sp50) - SQ(f2)) {
                    continue;
                }
                if (pokemon->flags & 2) {
                    if (item->itemID == 162) {
                        cmdSendCommand(ptr, 8, NULL);
                    } else {
                        cmdSendCommand(ptr, 12, NULL);
                    }
                }

                f22 = f2 - sqrtf(SQ(sp54) - (SQ(sp50) - SQ(f2)));
                if (f22 < sp11C) {
                    sp11C = f22;
                    sp118 = ptr;
                    sp108.x = sp9C.x;
                    sp108.y = sp9C.y;
                    sp108.z = sp9C.z;
                }
            }
        }
    }

    if (sp118 != NULL) {
        sp90.x = spA8.x + sp11C * sp78.x;
        sp90.y = spA8.y + sp11C * sp78.y;
        sp90.z = spA8.z + sp11C * sp78.z;
        Vec3fDirection(&sp6C, &sp90, &sp108);
        Vec3f_func_8001AC98(&sp78, &sp6C);
        sp60.x = sp78.x = sp78.x * sp4C * 0.5f;
        sp60.y = sp78.y = sp78.y * sp4C * 0.5f - g * 0.5f;
        sp60.z = sp78.z = sp78.z * sp4C * 0.5f;
        if (Vec3fNormalize(&sp60) < 10.0f) {
            sp78.x = sp6C.x * 10.0f;
            sp78.y = sp6C.y * 10.0f;
            sp78.z = sp6C.z * 10.0f;
        }
        if (item->itemID == 162) {
            v03 = func_800A6C48(3, 0);
            if (v03 != NULL) {
                v03->unk_14.x = arg0->data.dobj->position.v.x;
                v03->unk_14.y = arg0->data.dobj->position.v.y;
                v03->unk_14.z = arg0->data.dobj->position.v.z;
            }
            func_8035A1B8_4FA5C8(model, 10);
            cmdSendCommand(sp118, 9, NULL);
            arg0->flags |= GOBJ_FLAG_HIDDEN;
            func_80359770_4F9B80(arg0, func_80359CD4_4FA0E4);
            omCreateProcess(arg0, func_8035C2D4_4FC6E4, 1, 7);
            animSetTextureAnimationSpeed(arg0, 0.0f);
            omEndProcess(NULL);
        } else {
            func_8035A1B8_4FA5C8(model, 12);
            cmdSendCommand(sp118, 13, NULL);
        }
        item->unk_14.x = item->velocity.x;
        item->unk_14.y = item->velocity.y;
        item->unk_14.z = item->velocity.z;
        item->velocity.x = sp78.x;
        item->velocity.y = sp78.y;
        item->velocity.z = sp78.z;
        model->position.v.x = sp90.x + item->velocity.x * 0.5f;
        model->position.v.y = sp90.y + item->velocity.y * 0.5f;
        model->position.v.z = sp90.z + item->velocity.z * 0.5f;
        return;
    } else {
        item->velocity.y -= g * 0.5f;
        model->position.v.x += item->velocity.x * 0.5f;
        model->position.v.y += item->velocity.y * 0.5f;
        model->position.v.z += item->velocity.z * 0.5f;
    }
}

void func_8035C2D4_4FC6E4(GObj* arg0) {
    UnkPesterBall2* item = GET_ITEM(arg0);

    if (item->unk_04 > 60.0f) {
        func_8035C8F4_4FCD04(arg0);
        omEndProcess(NULL);
        return;
    }
    if (item->unk_01 == 0) {
        omEndProcess(NULL);
        return;
    }
    item->unk_04 += 0.5;
}

void func_8035C35C_4FC76C(GObj* arg0) {
    UnkPesterBall2* item = GET_ITEM(arg0);
    DObj* model = arg0->data.dobj;

    if (item->unk_04 > 170.0f) {
        func_8035C8F4_4FCD04(arg0);
        omEndProcess(0);
        return;
    }
    if (item->unk_01 == 0) {
        omEndProcess(NULL);
        return;
    }
    if (item->unk_04 > 140.0f) {
        model->scale.v.x *= 0.9f;
        model->scale.v.y *= 0.9f;
        model->scale.v.z *= 0.9f;
        model->position.v.y -= model->scale.v.y * 12.0f;
    }
    item->unk_04 += 0.5;
}

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
    ball->itemID = 162;
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
    ball->itemID = 163;
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
    if (item->itemID == 162) {
        D_803AF0C0_54F4D0--;
    } else {
        D_803AF0C4_54F4D4--;
    }
    item->unk_01 = 0;
}

void func_8035C9CC_4FCDDC(GObjFunc arg0, u8 arg1, void (*arg2)(GObj*, GroundResult*)) {
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

void func_8035CA1C_4FCE2C(s32 (*arg0)(Vec3f*, Vec3f*, Vec3f*, Vec3f*)) {
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
