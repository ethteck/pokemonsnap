#include "common.h"
#include "app_level.h"

typedef struct UnkBeigeBoa {
    /* 0x00 */ struct UnkBeigeBoa* unk_00;
    /* 0x04 */ GObj* unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u32 unk_0F_0 : 2;
    /* 0x0F */ u32 unk_0F_2 : 1;
} UnkBeigeBoa; // size 0x10

typedef struct UnkVioletPython {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
} UnkVioletPython; // size 0x4

extern UnkBeigeBoa* D_80393BD0_533FE0;
extern UnkVioletPython* D_80393BDC_533FEC;
extern s32 D_80393BE0_533FF0;
extern DObj* D_80393BD4_533FE4;
extern OMCamera* D_80393BD8_533FE8;
extern s32* D_800968BC;

DObj* func_803573B0_4F77C0(void);
OMCamera* getMainCamera(void);
s32 func_803669C0_506DD0(f32, f32);

f32 func_803660E0_5064F0(GObj* obj, u8 arg1) {
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 tmp;

    if (D_80393BD4_533FE4 == NULL || D_80393BD8_533FE8 == NULL) {
        return 0.0f;
    }
    if (pokemon == NULL) {
        return 0.0f;
    }
    tmp = pokemon->playerDist / 100.0f;
    return arg1 / (arg1 + tmp);
}

s32 func_80366160_506570(GObj* obj) {
    DObj* model = obj->data.dobj;
    f32 dx, dz;
    s32 unused[3];
    s32 val1;
    

    if (D_80393BD4_533FE4 == NULL) {
        return 0;
    }

    dx = GET_TRANSFORM(model)->pos.v.x - GET_TRANSFORM(D_80393BD4_533FE4)->pos.v.x;
    dz = GET_TRANSFORM(model)->pos.v.z - GET_TRANSFORM(D_80393BD4_533FE4)->pos.v.z;
    if ((s32)dx == 0 && (s32)dz == 0) {
        return 0;
    }
    val1 = func_803669C0_506DD0(dz, dx);
    dx = D_80393BD8_533FE8->viewMtx.lookAt.at.x - D_80393BD8_533FE8->viewMtx.lookAt.eye.x;
    dz = D_80393BD8_533FE8->viewMtx.lookAt.at.z - D_80393BD8_533FE8->viewMtx.lookAt.eye.z;
    val1 -= func_803669C0_506DD0(dz, dx);

    return val1 & 0x7FFF;
}

void func_8036621C_50662C(GObj* arg0, u8 arg1, s32* arg2, s32* arg3) {
    f32 f0;
    s32 v1;
    f32 sp24;
    s32 temp_v0;
    s32 unused;

    sp24 = func_803660E0_5064F0(arg0, arg1 & 0x7F);

    if (arg1 & 0x80) {
        f0 = 1.0f;
        v1 = 0x40;
    } else {
        temp_v0 = func_80366160_506570(arg0);
        v1 = (temp_v0 + 0x2000) & 0x7FFF;

        if (v1 > 0x4000) {
            v1 = -v1 & 0x7FFF;
        }

        v1 = v1 / 128;
        if (v1 > 127) {
            v1 = 127;
        }

        if (temp_v0 > 0x4000) {
            temp_v0 = -temp_v0 & 0x7FFF;
        }
        f0 = -0.000030517578f * temp_v0 + 1.0f;
    }

    *arg2 = sp24 * f0 * 0x7FFF;
    *arg3 = v1;
}

void func_80366328_506738(GObj* obj) {
    UnkBeigeBoa* ptr;
    s32 sp50, sp4C;
    s32 unused[2];

    if (D_80393BD4_533FE4 == NULL || D_80393BD8_533FE8 == NULL) {
        return;
    }

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->unk_00) {
        if (ptr->unk_04 != NULL) {
            OSIntMask mask = osSetIntMask(OS_IM_NONE);
            s32 v1 = D_800968BC[ptr->unk_08];

            if (v1 == -1 || v1 != ptr->unk_0C) {
                ptr->unk_04 = NULL;
                ptr->unk_0F_2 = TRUE;
            } else if (ptr->unk_0F_2 != TRUE) {
                func_8036621C_50662C(ptr->unk_04, ptr->unk_0E, &sp50, &sp4C);
                auSetSoundVolume(ptr->unk_08, sp50);
                if (!(ptr->unk_0E & 0x80)) {
                    auSetSoundPan(ptr->unk_08, sp4C);
                }
            }

            osSetIntMask(mask);
        }
    }
}

#ifdef NON_MATCHING
void func_80366470_506880(UnkVioletPython* arg0, s32 arg1) {
    if (arg0 != 0 && arg1 > 0) {
        D_80393BDC_533FEC = arg0;
        D_80393BE0_533FF0 = arg1;
        D_80393BD4_533FE4 = func_803573B0_4F77C0();
        D_80393BD8_533FE8 = getMainCamera();
        D_80393BD0_533FE0 = gtlMalloc(sizeof(UnkBeigeBoa), 4);
        D_80393BD0_533FE0->unk_00 = NULL;
        D_80393BD0_533FE0->unk_04 = NULL;
        omCreateProcess(omAddGObj(400, ohUpdateDefault, 9, 1), func_80366328_506738, 1, 1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366470_506880.s")
void func_80366470_506880(UnkVioletPython* arg0, s32 arg1);
#endif

void func_8036650C_50691C(void) {
    D_80393BD4_533FE4 = NULL;
    D_80393BD8_533FE8 = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/5064F0/func_80366520_506930.s")
void func_80366520_506930(void* arg0, u8 arg1, s32 arg2, u8 arg3, u8 arg4);

void func_803667C0_506BD0(s32 arg0, u8 arg1, s32 arg2) {
    s32 i;

    if (D_80393BD4_533FE4 == NULL || D_80393BD8_533FE8 == NULL || D_80393BD0_533FE0 == NULL) {
        return;
    }

    for (i = 0; i < D_80393BE0_533FF0; i++) {
        if (D_80393BDC_533FEC[i].unk_00 == arg2) {
            func_80366520_506930(arg0, arg1, arg2, D_80393BDC_533FEC[i].unk_02, D_80393BDC_533FEC[i].unk_03);
            break;
        }
    }
}

void func_80366864_506C74(GObj* arg0, u8 arg1) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->unk_00) {
        if (ptr->unk_04 == arg0 && ptr->unk_0F_0 == arg1) {
            auStopSound(ptr->unk_08);
            ptr->unk_04 = NULL;
        }
    }
}

void func_803668DC_506CEC(GObj* arg0) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->unk_00) {
        if (ptr->unk_04 == arg0) {
            ptr->unk_0F_2 = TRUE;
        }
    }
}

void func_80366918_506D28(GObj* arg0) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->unk_00) {
        if (ptr->unk_04 == arg0) {
            auStopSound(ptr->unk_08);
            ptr->unk_04 = NULL;
        }
    }
}

s32 func_80366970_506D80(s32 arg0) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->unk_00) {
        if (ptr->unk_04 != NULL && ptr->unk_0C == arg0) {
            return ptr->unk_08;
        }
    }
    return -1;
}
