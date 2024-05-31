#include "common.h"
#include "app_level.h"

typedef struct UnkBeigeBoa {
    /* 0x00 */ struct UnkBeigeBoa* next;
    /* 0x04 */ GObj* source;
    /* 0x08 */ s32 soundHandle;
    /* 0x0C */ u16 soundId;
    /* 0x0E */ u8 hearingRange;
    /* 0x0F */ u32 group : 2;
    /* 0x0F */ u32 finished : 1;
} UnkBeigeBoa; // size 0x10

typedef struct UnkVioletPython {
    /* 0x00 */ u16 soundID;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 hearingRange;
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

f32 EnvSound_GetDecay(GObj* obj, u8 hearingRange) {
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 tmp;

    if (D_80393BD4_533FE4 == NULL || D_80393BD8_533FE8 == NULL) {
        return 0.0f;
    }
    if (pokemon == NULL) {
        return 0.0f;
    }
    tmp = pokemon->playerDist / 100.0f;
    return hearingRange / (hearingRange + tmp);
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

void EnvSound_GetVolumePan(GObj* obj, u8 hearingRange, s32* volume, s32* pan) {
    f32 f0;
    s32 v1;
    f32 sp24;
    s32 temp_v0;
    s32 unused;

    sp24 = EnvSound_GetDecay(obj, hearingRange & 0x7F);

    if (hearingRange & 0x80) {
        f0 = 1.0f;
        v1 = 0x40;
    } else {
        temp_v0 = func_80366160_506570(obj);
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

    *volume = sp24 * f0 * 0x7FFF;
    *pan = v1;
}

void func_80366328_506738(GObj* obj) {
    UnkBeigeBoa* ptr;
    s32 volume, pan;
    s32 unused[2];

    if (D_80393BD4_533FE4 == NULL || D_80393BD8_533FE8 == NULL) {
        return;
    }

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->next) {
        if (ptr->source != NULL) {
            OSIntMask mask = osSetIntMask(OS_IM_NONE);
            s32 soundId = D_800968BC[ptr->soundHandle];

            if (soundId == -1 || soundId != ptr->soundId) {
                ptr->source = NULL;
                ptr->finished = TRUE;
            } else if (ptr->finished != TRUE) {
                EnvSound_GetVolumePan(ptr->source, ptr->hearingRange, &volume, &pan);
                auSetSoundVolume(ptr->soundHandle, volume);
                if (!(ptr->hearingRange & 0x80)) {
                    auSetSoundPan(ptr->soundHandle, pan);
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
        D_80393BD0_533FE0->next = NULL;
        D_80393BD0_533FE0->source = NULL;
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

void func_80366520_506930(GObj* obj, u8 group, s32 soundID, u8 pitch, u8 hearingRange) {
    Pokemon* pokemon = GET_POKEMON(obj);
    UnkBeigeBoa* last;
    u32 volume, pan;
    UnkBeigeBoa* ptr;


    if (2 * hearingRange < pokemon->playerDist / 100.0f || D_80393BD4_533FE4 == NULL || D_80393BD8_533FE8 == NULL) {
        return;
    }

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj && ptr->group == group) {
            auStopSound(ptr->soundHandle);
            ptr->source = NULL;
        }
    }

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->next) {
        if (ptr->source != NULL) {
            last = ptr;
        } else {
            break;
        }
    }

    if (ptr == NULL) {
        ptr = gtlMalloc(sizeof(UnkBeigeBoa), 4);
        ptr->next = NULL;
        ptr->source = NULL;
        last->next = ptr;
    }

    EnvSound_GetVolumePan(obj, hearingRange, &volume, &pan);
    if (volume > 0x7FFF) {
        volume = 0x7FFF;
    }
    if (pan > 0x7F) {
        pan = 0x7F;
    }

    pitch = pitch > 0x7F ? 0x7F : pitch;

    switch (pitch) {
        case 0:
            ptr->soundHandle = auPlaySoundWithParams(soundID, volume, pan, 1.0f, 0);
            break;
        case 1:
            ptr->soundHandle = auPlaySoundWithParams(soundID, volume, pan, 0.8f, 0);
            break;
        case 2:
            ptr->soundHandle = auPlaySoundWithParams(soundID, volume, pan, 0.7f, 0);
            break;
        case 3:
            ptr->soundHandle = auPlaySoundWithParams(soundID, volume, pan, 0.75f, 0);
            break;
        case 4:
            ptr->soundHandle = auPlaySoundWithParams(soundID, volume, pan, 0.5f, 0);
            break;
        default:
            ptr->soundHandle = auPlaySoundWithParams(soundID, volume, pan, 1.0f, 0);
            break;
    }

    if (ptr->soundHandle != -1) {
        ptr->source = obj;
        ptr->group = group;
        ptr->hearingRange = hearingRange;
        ptr->soundId = soundID;
        ptr->finished = FALSE;
    }
}

void func_803667C0_506BD0(GObj* obj, u8 arg1, s32 soundID) {
    s32 i;

    if (D_80393BD4_533FE4 == NULL || D_80393BD8_533FE8 == NULL || D_80393BD0_533FE0 == NULL) {
        return;
    }

    for (i = 0; i < D_80393BE0_533FF0; i++) {
        if (D_80393BDC_533FEC[i].soundID == soundID) {
            func_80366520_506930(obj, arg1, soundID, D_80393BDC_533FEC[i].unk_02, D_80393BDC_533FEC[i].hearingRange);
            break;
        }
    }
}

void func_80366864_506C74(GObj* obj, u8 group) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj && ptr->group == group) {
            auStopSound(ptr->soundHandle);
            ptr->source = NULL;
        }
    }
}

void func_803668DC_506CEC(GObj* obj) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj) {
            ptr->finished = TRUE;
        }
    }
}

void func_80366918_506D28(GObj* obj) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj) {
            auStopSound(ptr->soundHandle);
            ptr->source = NULL;
        }
    }
}

s32 EnvSound_GetSoundHandle(s32 soundId) {
    UnkBeigeBoa* ptr;

    for (ptr = D_80393BD0_533FE0; ptr != NULL; ptr = ptr->next) {
        if (ptr->source != NULL && ptr->soundId == soundId) {
            return ptr->soundHandle;
        }
    }
    return -1;
}
