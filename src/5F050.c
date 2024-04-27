#include "common.h"
#include "level_low.h"

typedef struct UnkEbonyBarracuda {
    /* 0x00 */ Gfx* unk_00;
    /* 0x04 */ void* unk_04;
    /* 0x08 */ Texture*** unk_08;
    /* 0x0C */ union AnimCmd*** unk_0C;
    /* 0x10 */ f32 unk_10;
} UnkEbonyBarracuda;

extern UnkCeruleanComodo* D_800E6AD0_64280;
extern u32 D_800E6AD4_64284;
extern s8 D_800E6AE3_64293;
extern u8 D_800E6AE7_64297;
extern GObj* D_800E6AE8_64298;
extern f32 D_800E6AEC_6429C;
extern s32 D_800E6AF4_642A4;
extern union AnimCmd*** D_800E6AF8_642A8;
extern f32 D_800E6BC8_64378;

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E18A0_5F050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E1924_5F0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E19A4_5F154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E1A78_5F228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E1AB4_5F264.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E1B68_5F318.s")
void func_800E1B68_5F318(GObj*);

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
    dobj->rotation.f[2] = D_800E6BC8_64378 * D_800E6AEC_6429C /  D_800E6AF4_642A4;
}

void func_800E1E94_5F644(UnkEbonyBarracuda* arg0) {
    GObj* obj;
    DObj* dobj;

    obj = omAddGObj(D_800E6AD4_64284, &ohUpdateDefault, D_800E6AE3_64293, 0x80000000);
    D_800E6AE8_64298  = obj;
    omCreateProcess(obj, &func_800E1B68_5F318, 1, 2);

    if (arg0 == NULL || arg0->unk_00 == NULL) {
        return;
    }

    if (arg0->unk_04 == NULL || arg0->unk_04 != &func_800E1CA4_5F454 && arg0->unk_04 != &func_800E1D80_5F530) {
        return;
    }

    omLinkGObjDL(obj, arg0->unk_04, D_800E6AE7_64297, 0x80000001, -1);
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

UnkCeruleanComodo* func_800E2184_5F934(void) {
    return D_800E6AD0_64280;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2190_5F940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E219C_5F94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E21A8_5F958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E21E4_5F994.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2280_5FA30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E22E0_5FA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2354_5FB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E23A8_5FB58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2400_5FBB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E25E4_5FD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E26CC_5FE7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E270C_5FEBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E27C4_5FF74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2ACC_6027C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2C24_603D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E2F38_606E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3010_607C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3064_60814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E30B0_60860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3258_60A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3464_60C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E354C_60CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3560_60D10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3590_60D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3968_61118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3B0C_612BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3D04_614B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5F050/func_800E3EE8_61698.s")
