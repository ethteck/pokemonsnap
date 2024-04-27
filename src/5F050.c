#include "common.h"
#include "level_low.h"

void func_800E354C_60CFC(s32, s32);
void func_800E3464_60C14(UnkBordeauxWolf*);

typedef struct UnkAquamarineCoyote {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
} UnkAquamarineCoyote; // size=0x0C

// data
extern UnkBordeauxWolf* D_800E6AD0_64280;
extern u32 D_800E6AD4_64284;
extern s32 D_800E6AD8_64288;
extern u32 D_800E6ADC_6428C;
extern u32 D_800E6AE0_64290;
extern u32 D_800E6AE4_64294;
extern GObj* D_800E6AE8_64298;
extern f32 D_800E6AEC_6429C;
extern f32 D_800E6AF0_642A0;
extern s32 D_800E6AF4_642A4;
extern union AnimCmd*** D_800E6AF8_642A8;
extern void (*D_800E6AFC_642AC)(UnkBordeauxWolf*, UnkBordeauxWolf*);
extern void (*D_800E6B00_642B0)(UnkBordeauxWolf*);
extern void (*D_800E6B04_642B4)(UnkBordeauxWolf*, UnkBordeauxWolf*);
extern s32 D_800E6B10_642C0;
extern s32 D_800E6B14_642C4;

// bss
extern UnkBordeauxWolf* D_800F5A08_731B8[13];
extern UnkBordeauxWolf D_800F5A40_731F0[13];
extern UnkIvoryMamba D_800F5BB0_73360[13];
static UnkAquamarineCoyote D_800F5C50_73400[14];

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E18A0_5F050.s")
void func_800E18A0_5F050(u32);

#ifdef NON_MATCHING
// requires static 
void func_800E1924_5F0D4(void) {
    s32 i;

    for (i = 0; i < 14; i++) {
        D_800F5C50_73400[i].unk_00 = -1.0f;
        D_800F5C50_73400[i].unk_04 = 0.0f;
        D_800F5C50_73400[i].unk_08 = 0.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E1924_5F0D4.s")
void func_800E1924_5F0D4(void);
#endif

void func_800E19A4_5F154(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 >= 0 && arg1 < 14) {
        f32 animationTime = arg0->obj->animationTime;
        D_800F5C50_73400[arg1].unk_00 = animationTime;
        D_800F5C50_73400[arg1].unk_04 = arg2;
        func_800E18A0_5F050(arg2);
    }   
}

void func_800E1A78_5F228(f32 arg0) {
    D_800E6AF0_642A0 = arg0;
    if (D_800E6AF8_642A8 != NULL) {
        animSetTextureAnimationSpeed(D_800E6AE8_64298, arg0);
    }
}

f32 func_800E1AB4_5F264(f32 arg0, s32 arg1) {
    while (arg0 < 0.0f) {
        arg0 += arg1;
    }
    
    arg0 *= 10000.0;
    arg0 = ((s32)arg0 + 5) / 10;
    arg0 /= 1000.0;

    while (arg0 >= arg1) {
        arg0 -= arg1;
    }

    return arg0;
}

void func_800E1B68_5F318(GObj* arg0) {
    D_800E6AEC_6429C += D_800E6AF0_642A0;
    D_800E6AEC_6429C = func_800E1AB4_5F264(D_800E6AEC_6429C, D_800E6AF4_642A4);
}

void func_800E1BB8_5F368(GObj* obj) {
    void (*userData)(GObj*) = obj->userData;
    if (userData != &renRenderModelTypeA) {
        return;
    }

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2)
    gSPClearGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
    renRenderModelTypeA(obj);
    gDPPipeSync(gMainGfxPos[0]++);
    gSPSetGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
}

void func_800E1CA4_5F454(GObj* obj) {
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2)
    gSPClearGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
    renRenderModelTypeA(obj);
    gDPPipeSync(gMainGfxPos[0]++);
    gSPSetGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
}

void func_800E1D80_5F530(GObj* obj) {
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_2CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_PASS, G_RM_AA_OPA_SURF2);
    gSPClearGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
    renRenderModelTypeA(obj);
    gDPPipeSync(gMainGfxPos[0]++);
    gSPSetGeometryMode(gMainGfxPos[0]++, G_ZBUFFER | G_FOG);
}

void func_800E1E60_5F610(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    dobj->rotation.f[2] = 6.283185482f * D_800E6AEC_6429C /  D_800E6AF4_642A4;
}

void func_800E1E94_5F644(UnkEbonyBarracuda* arg0) {
    GObj* obj;
    DObj* dobj;

    obj = omAddGObj(D_800E6AD4_64284, &ohUpdateDefault, D_800E6AE0_64290, 0x80000000);
    D_800E6AE8_64298  = obj;
    omCreateProcess(obj, &func_800E1B68_5F318, 1, 2);

    if (arg0 == NULL || arg0->unk_00 == NULL) {
        return;
    }

    if (arg0->unk_04 == NULL || arg0->unk_04 != &func_800E1CA4_5F454 && arg0->unk_04 != &func_800E1D80_5F530) {
        return;
    }

    omLinkGObjDL(obj, arg0->unk_04, D_800E6AE4_64294, 0x80000001, -1);
    omGObjAddDObj(obj, arg0->unk_00);
    if (arg0->unk_04 == &func_800E1D80_5F530) {
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_ROTATE_RPY_TRANSLATE, 0);
    } else {
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_TRANSLATE, 0);
    }

    if (arg0->unk_08 != NULL) {
        Texture** ptr = *arg0->unk_08;
        Texture* curr = *ptr;
        while (curr != NULL) {
            omDObjAddMObj(obj->data.dobj, curr);
            ptr++;
            curr = *ptr; 
        }
    }

    if (arg0->unk_0C != NULL) {
        D_800E6AF8_642A8 = arg0->unk_0C;
        omCreateProcess(obj, &animUpdateModelTreeAnimation, 1, 1);
        animSetModelTreeTextureAnimation(obj, arg0->unk_0C, 0);
        animSetTextureAnimationSpeed(obj, arg0->unk_10);
    }

    if (arg0->unk_04 == &func_800E1D80_5F530) {
        omCreateProcess(obj, &func_800E1E60_5F610, 1, 1);
    }

    dobj = obj->data.dobj;
    dobj->position.v.z = 0.0f;
    dobj->position.v.y = 0.0f;
    dobj->position.v.x = 0.0f;
}

void func_800E206C_5F81C(GObj* obj) {
    Unk803586F8* v0 = func_803586F8_4F8B08();

    obj->data.dobj->position.v.x = v0->unk_3C.x;
    obj->data.dobj->position.v.y = v0->unk_3C.y;
    obj->data.dobj->position.v.z = v0->unk_3C.z;
}

void func_800E20B4_5F864(void) {
    if (D_800E6AE8_64298 != NULL && D_800E6AE8_64298->data.dobj != NULL) {
        omCreateProcess(D_800E6AE8_64298, &func_800E206C_5F81C, 1, 0);
    }
}

void func_800E20F8_5F8A8(f32 posX, f32 posY, f32 posZ, f32 arg3, f32 arg4) {

    if (D_800E6AE8_64298 != NULL && D_800E6AE8_64298->data.dobj != NULL) {
        D_800E6AE8_64298->data.dobj->position.v.x = posX;
        D_800E6AE8_64298->data.dobj->position.v.y = posY;
        D_800E6AE8_64298->data.dobj->position.v.z = posZ;
    }

    D_800E6AE8_64298->data.dobj->rotation.f[2] = arg3;

    if (D_800E6AF8_642A8 != NULL) {
        animSetModelTreeTextureAnimation(D_800E6AE8_64298, D_800E6AF8_642A8, arg4);
    }
}

UnkBordeauxWolf* func_800E2184_5F934(void) {
    return D_800E6AD0_64280;
}

UnkBordeauxWolf** func_800E2190_5F940(void) {
    return D_800F5A08_731B8;
}

f32 func_800E219C_5F94C(void) {
    return D_800E6AEC_6429C;
}

f32 func_800E21A8_5F958(f32 arg0) {
    while (TRUE) {
        if (arg0 < 100.0f) {
            return arg0;
        }
        arg0 -= 100.0f;
    }
    return arg0;
}

static void nullsub() {
    
}

#ifdef NON_MATCHING
void func_800E21E4_5F994(UnkBordeauxWolf* arg0, UnkBordeauxWolf* arg1) {
    f32 x1, y1, z1;

    if (arg0 == NULL ||
        arg0->unk_04 == NULL ||
        arg1 == NULL ||
        arg0->unk_10 == NULL ||
        arg0->unk_10->data.dobj == NULL)
    {
        return;
    }

    x1 = arg0->unk_04->unk_04.x;
    y1 = arg0->unk_04->unk_04.y;
    z1 = arg0->unk_04->unk_04.z;

    arg0->unk_10->data.dobj->position.v.x = (x1 - arg1->unk_04->unk_04.x) * 100.0f;
    arg0->unk_10->data.dobj->position.v.y = (y1 - arg1->unk_04->unk_04.y) * 100.0f;
    arg0->unk_10->data.dobj->position.v.z = (z1 - arg1->unk_04->unk_04.z) * 100.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E21E4_5F994.s")
void func_800E21E4_5F994(UnkBordeauxWolf* arg0, UnkBordeauxWolf* arg1);
#endif

void func_800E2280_5FA30(UnkBordeauxWolf* arg0) {
    s32 i;

    for (i = 0; i < 13; i++) {
        if (D_800F5A08_731B8[i] == NULL) {
            break;
        }
        func_800E21E4_5F994(D_800F5A08_731B8[i], arg0);
    }
}

void func_800E22E0_5FA90(UnkBordeauxWolf* arg0) {
    if (arg0 != NULL) {
        if (D_800E6B00_642B0 != NULL) {
            D_800E6B00_642B0(arg0);
        }
        if (arg0->unk_10 != NULL) {
            omDeleteGObj(arg0->unk_10);
        }
        if (arg0->unk_14 != NULL) {
            omDeleteGObj(arg0->unk_14);
        }
        arg0->unk_10 = NULL;
        arg0->unk_14 = NULL;
    }
}

void func_800E2354_5FB04(UnkBordeauxWolf* arg0) {
    s32 i;

    if (arg0 != NULL) {
        for (i = 0; i < 1; i++) {
            arg0 = arg0->unk_08;
            if (arg0 == NULL) {
                return;
            }
        }
        if (D_800E6B00_642B0 != NULL) {
            D_800E6B00_642B0(arg0);
        }
    }    
}

void func_800E23A8_5FB58(UnkBordeauxWolf* arg0) {
    s32 i;

    if (arg0 != NULL) {
        UnkBordeauxWolf* next = arg0;
        for (i = 0; i < 1; i++) {
            next = next->unk_0C;
            if (next == NULL) {
                return;
            }
        }
        if (D_800E6AFC_642AC != NULL) {
            D_800E6AFC_642AC(next, arg0);
        }
    }    
}

UnkBordeauxWolf* func_800E2400_5FBB0(void) {
    UnkBordeauxWolf* curr;
    UnkBordeauxWolf* next;
    s32 i;

    curr = D_800E6AD0_64280;
    if (curr == NULL || curr->unk_0C == NULL) {
        return NULL;
    }
    next = curr->unk_0C;
    D_800E6AD0_64280 = next;
    func_8035024C_4F065C((curr->unk_04->unk_04.x - next->unk_04->unk_04.x) * 100.0f,
                         (curr->unk_04->unk_04.y - next->unk_04->unk_04.y) * 100.0f,
                         (curr->unk_04->unk_04.z - next->unk_04->unk_04.z) * 100.0f);
    func_800A71F8((curr->unk_04->unk_04.x - next->unk_04->unk_04.x) * 100.0f,
                         (curr->unk_04->unk_04.y - next->unk_04->unk_04.y) * 100.0f,
                         (curr->unk_04->unk_04.z - next->unk_04->unk_04.z) * 100.0f);

    func_800E2280_5FA30(next);
    func_800E2354_5FB04(curr);
    func_800E23A8_5FB58(next);

    for (i = 0; i <= curr->unk_00; i++) {
        if (D_800F5A08_731B8[i] == NULL) {
            break;
        }
        if (D_800E6B04_642B4 != NULL) {
            D_800E6B04_642B4(D_800F5A08_731B8[i], next);
        }
    }

    for (i = 0; i < 1; i++) {
        if (next->unk_00 + i >= 13) {
            break;
        }
        if (D_800F5A08_731B8[next->unk_00 + i] == NULL) {
            break;
        }
        if (D_800E6B04_642B4 != NULL) {
            D_800E6B04_642B4(D_800F5A08_731B8[next->unk_00 + i], next);
        }
    }

    return D_800E6AD0_64280;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E25E4_5FD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E26CC_5FE7C.s")

#ifdef NON_MATCHING
void func_800E270C_5FEBC(GObj* obj) {
    UnkBordeauxWolf* temp_v1 = D_800F5A08_731B8[(obj->id - D_800E6AD8_64288) / 2];

    if (temp_v1 == NULL ||
        temp_v1->unk_10 == NULL ||
        temp_v1->unk_04 == NULL ||
        temp_v1->unk_04->unk_00 == NULL ||
        temp_v1->unk_04->unk_00->unk_08 == NULL)
    {
        return;
    }

    animSetModelTreeTextureAnimation(obj, temp_v1->unk_04->unk_00->unk_08, func_800E21A8_5F958(D_800E6AEC_6429C));
    animSetTextureAnimationSpeed(obj, 0.0f);
    animUpdateModelTreeAnimation(obj);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E270C_5FEBC.s")
void func_800E270C_5FEBC(GObj* obj);
#endif

GObj* func_800E27C4_5FF74(UnkBordeauxWolf* arg0) {
    s32 id;
    GObj* obj;
    DObj* dobj;
    Texture** ptr;
    Texture* curr;
    u32 priority = 0x80000000;

    if (arg0 == NULL || arg0->unk_04 == NULL || arg0->unk_04->unk_00 == NULL || arg0->unk_04->unk_00->unk_00 == NULL) {
        return NULL;
    }

    id = arg0->unk_00 * 2 + D_800E6AD8_64288;
    if (!inRange_DEBUG(id, D_800E6AD8_64288, D_800E6ADC_6428C, "blockModelCreate()")) {
        return NULL;
    }

    obj = omAddGObj(id, &ohUpdateDefault, D_800E6AE0_64290, priority);
    omLinkGObjDL(obj, arg0->unk_04->unk_00->unk_0C, D_800E6AE4_64294, priority, -1);

    if (&func_800E1D80_5F530 == arg0->unk_04->unk_00->unk_0C) {
        omGObjAddDObj(obj, arg0->unk_04->unk_00->unk_00);
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_ROTATE_RPY_TRANSLATE, 0);
        if (arg0->unk_04->unk_00->unk_04 != NULL) {
            ptr = *arg0->unk_04->unk_00->unk_04;
            curr = *ptr;
            while (curr != NULL) {
                omDObjAddMObj(obj->data.dobj, curr);
                ptr++;
                curr = *ptr; 
            }
        }
    } else if (&renRenderModelTypeA == arg0->unk_04->unk_00->unk_0C ||
               &func_800A1530 == arg0->unk_04->unk_00->unk_0C || 
               &renRenderModelTypeC == arg0->unk_04->unk_00->unk_0C || 
               &func_800A1590 == arg0->unk_04->unk_00->unk_0C)
    {
        omGObjAddDObj(obj, arg0->unk_04->unk_00->unk_00);
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_TRANSLATE, 0);
        if (arg0->unk_04->unk_00->unk_04 != NULL) {
            ptr = *arg0->unk_04->unk_00->unk_04;
            curr = *ptr;
            while (curr != NULL) {
                omDObjAddMObj(obj->data.dobj, curr);
                ptr++;
                curr = *ptr; 
            }
        }
    } else if (&renRenderModelTypeB == arg0->unk_04->unk_00->unk_0C ||
               &func_800A15D8 == arg0->unk_04->unk_00->unk_0C || 
               &renRenderModelTypeD == arg0->unk_04->unk_00->unk_0C || 
               &func_800A1608 == arg0->unk_04->unk_00->unk_0C)
    {
        anim_func_80010230(obj, arg0->unk_04->unk_00->unk_00, arg0->unk_04->unk_00->unk_04, NULL, 0, 0, 0);
        omDObjAppendMtx(obj->data.dobj, MTX_TYPE_TRANSLATE, 0);
    } else {
        omDeleteGObj(obj);
        return NULL;
    }

    if (arg0 != NULL && arg0->unk_04 != NULL && arg0->unk_04->unk_00 != NULL && arg0->unk_04->unk_00->unk_08 != NULL) {
        omCreateProcess(obj, &func_800E270C_5FEBC, 1, 1);
    }

    dobj = obj->data.dobj;
    dobj->rotation.f[2] = arg0->unk_04->unk_10;
    dobj->rotation.f[1] = dobj->rotation.f[3] = 0.0f;
    dobj->scale.v.x = dobj->scale.v.y = dobj->scale.v.z = 1.0f;
    return obj;
}

GObj* func_800E2ACC_6027C(UnkBordeauxWolf* arg0) {
    s32 id;
    GObj* obj;
    f32 skipFrames;
    
    if (arg0 == NULL || arg0->unk_04 == NULL || arg0->unk_04->unk_00 == NULL) {
        return NULL;
    }
    if (arg0->unk_04->unk_00->unk_14 < 2) {
        return NULL;
    }

    id = arg0->unk_00 * 2 + 1 + D_800E6AD8_64288;
    if (!inRange_DEBUG(id, D_800E6AD8_64288, D_800E6ADC_6428C, "blockUVCreate()")) {
        return NULL;
    }

    obj = omAddGObj(id, &ohUpdateDefault, D_800E6AE0_64290, 0x80000000);
    omLinkGObjDL(obj, renRenderModelTypeB, D_800E6AE4_64294, 0x80000000, -1);
    anim_func_8000FBC4(obj, arg0->unk_04->unk_00->unk_10, arg0->unk_18);
    animSetModelAnimationSpeed(obj, 0.0f);
    if (arg0->unk_04->unk_14 != 0) {
        skipFrames = arg0->unk_04->unk_00->unk_1C;
    } else {
        skipFrames = 0.0f;
    }
    animSetModelTreeAnimation(obj, arg0->unk_04->unk_00->unk_18, skipFrames);
    animUpdateModelTreeAnimation(obj);
    obj->fnAnimCallback = &func_800E19A4_5F154;
    return obj;
}

#ifdef NON_MATCHING
UnkBordeauxWolf** func_800E2C24_603D4(UnkBoneFox* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void (*arg6)(UnkBordeauxWolf*, UnkBordeauxWolf*), void (*arg7)(UnkBordeauxWolf*), void (*arg8)(UnkBordeauxWolf*, UnkBordeauxWolf*)) {
    s32 i;
    s32 num1;
    UnkBordeauxWolf* s0;
    UnkMintLynx** ptr;

    D_800E6AD4_64284 = arg1;
    D_800E6AD8_64288 = arg2;
    D_800E6ADC_6428C = arg3;
    D_800E6AE0_64290 = arg4;
    D_800E6AE4_64294 = arg5;
    D_800E6AFC_642AC = arg6;
    D_800E6B00_642B0 = arg7;
    D_800E6B04_642B4 = arg8;

    for (i = 0; i < 13; i++) {
        D_800F5A08_731B8[i] = 0;
    }

    if (arg0 == NULL || arg0->unk_00 == NULL) {
        return NULL;
    }
    ptr = arg0->unk_00;
    func_800E1E94_5F644(arg0->unk_08);
    
    for (i = 0; (i < 13) != 0; i++) {
        if (ptr[i] == NULL) {
            break;
        }

        if (i > 0 && ptr[i] == ptr[0]) {
            D_800F5A08_731B8[0]->unk_08 = D_800F5A08_731B8[i - 1];
            if (1) {

            }
            D_800F5A08_731B8[i - 1]->unk_0C = D_800F5A08_731B8[0];
            break;
        }

        s0 = &D_800F5A40_731F0[i];
        s0->unk_00 = i;
        s0->unk_04 = ptr[i];
        if (i > 0) {
            if (s0) { }
            s0->unk_08 = D_800F5A08_731B8[i - 1];
        } else {
            s0->unk_08 = NULL;
        }
        s0->unk_0C = NULL;
        if (s0->unk_04->unk_00->unk_14 <= 0 || s0->unk_04->unk_00->unk_14 >= 4) {
            s0->unk_18 = NULL;
        } else {
            s0->unk_18 = &D_800F5BB0_73360[i];
        }

        s0->unk_10 = func_800E27C4_5FF74(s0);
        s0->unk_14 = func_800E2ACC_6027C(s0);
        D_800F5A08_731B8[i] = s0;
        func_800E3464_60C14(s0);
        if (s0->unk_08 != NULL) {
            s0->unk_08->unk_0C = s0;
        }
    }

    num1 = i;

    if (arg0->unk_04 == NULL) {
        return D_800F5A08_731B8;
    }
    ptr = arg0->unk_04;

    for (i = num1; i < 13; i++) {
        if (ptr[i - num1] == 0) {
            break;
        }

        s0 = &D_800F5A40_731F0[i];
        s0->unk_00 = i;
        s0->unk_04 = ptr[i - num1];
        s0->unk_08 = NULL;
        s0->unk_0C = NULL;
        if (1) { } if (1) { }
        s0->unk_10 = func_800E27C4_5FF74(s0);
        s0->unk_14 = NULL;
        s0->unk_18 = NULL;
        D_800F5A08_731B8[i] = s0;
        func_800E3464_60C14(s0);
    }

    if (i >= 13) {
        return NULL;
    }

    s0 = D_800F5A08_731B8[0];
    if (s0 != NULL &&
        s0->unk_14 != NULL &&
        s0->unk_04 != NULL &&
        s0->unk_04->unk_00 != NULL &&
        s0->unk_04->unk_00->unk_18 != NULL
        )
    {
        animSetModelTreeAnimation(s0->unk_14, s0->unk_04->unk_00->unk_18, 0);
        animUpdateModelTreeAnimation(s0->unk_14);
    }

    return D_800F5A08_731B8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2C24_603D4.s")
UnkBordeauxWolf** func_800E2C24_603D4(UnkBoneFox* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
#endif

s32 func_800E2F38_606E8(UnkTomatoEagle* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    func_800E1924_5F0D4();
    if (arg0 == NULL || arg0->unk_00 == NULL) {
        return FALSE;
    }
    func_800E354C_60CFC(arg0->unk_04, arg0->unk_08);
    func_800E66BC_63E6C(arg0->unk_0C);
    func_800A18AC(arg0->unk_14, arg0->unk_16);
    func_800A181C(arg0->unk_18, arg0->unk_19, arg0->unk_1A);
    func_800A1780(arg0->unk_1B, arg0->unk_1C, arg0->unk_1D);
    func_800E2C24_603D4(arg0->unk_00, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    func_800E1A78_5F228(arg0->unk_10);
    return TRUE;
}

void func_800E3010_607C0(void) {
    s32 i;

    for (i = 0; i < 13; i++) {
        if (D_800F5A08_731B8[i] != NULL) {
            func_800E22E0_5FA90(D_800F5A08_731B8[i]);
        }
    }
}

void func_800E3064_60814(void) {
    func_800E1924_5F0D4();
    func_800E3010_607C0();
    if (D_800E6AE8_64298 != NULL) {
        omDeleteGObj(D_800E6AE8_64298);
        D_800E6AE8_64298 = NULL;
    }
    D_800E6AF8_642A8 = NULL;
}

// unrefernced
#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E30B0_60860.s")

// unrefernced
#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3258_60A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3464_60C14.s")
/*void func_800E3464_60C14(UnkBordeauxWolf* arg0) {
    if (arg0 == NULL || arg0->unk_04 == NULL || arg0->unk_04->unk_18 == NULL) {
        return;
    }

    if (arg0->unk_00 < 13) {
        s32* = arg0->unk_04->unk_18;
    }
}*/

void func_800E354C_60CFC(s32 arg0, s32 arg1) {
    D_800E6B10_642C0 = arg0;
    D_800E6B14_642C4 = arg1;
}
