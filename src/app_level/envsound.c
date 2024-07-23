#include "common.h"
#include "app_level.h"
#include "sys/om.h"

typedef struct EnvSound {
    /* 0x00 */ struct EnvSound* next;
    /* 0x04 */ GObj* source;
    /* 0x08 */ s32 soundHandle;
    /* 0x0C */ u16 soundId;
    /* 0x0E */ u8 hearingRange;
    /* 0x0F */ u32 category : 2;
    /* 0x0F */ u32 fixedParams : 1;
} EnvSound; // size 0x10

typedef struct EnvSoundData {
    /* 0x00 */ u16 soundID;
    /* 0x02 */ u8 pitchModifier;
    /* 0x03 */ u8 hearingRange;
} EnvSoundData; // size 0x4

extern EnvSound* EnvSound_Sounds;
extern EnvSoundData* EnvSound_InitData;
extern s32 EnvSound_InitDataSize;
extern DObj* EnvSound_PlayerModel;
extern OMCamera* EnvSound_MainCamera;

DObj* func_803573B0_4F77C0(void);
OMCamera* getMainCamera(void);
s32 atan2s(f32, f32);

f32 EnvSound_GetDecay(GObj* obj, u8 hearingRange) {
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 tmp;

    if (EnvSound_PlayerModel == NULL || EnvSound_MainCamera == NULL) {
        return 0.0f;
    }
    if (pokemon == NULL) {
        return 0.0f;
    }
    tmp = pokemon->playerDist / 100.0f;
    return hearingRange / (hearingRange + tmp);
}

s32 EnvSound_GetTargetAngle(GObj* obj) {
    DObj* model = obj->data.dobj;
    f32 dx, dz;
    s32 unused[3];
    s32 val1;

    if (EnvSound_PlayerModel == NULL) {
        return 0;
    }

    dx = GET_TRANSFORM(model)->pos.v.x - GET_TRANSFORM(EnvSound_PlayerModel)->pos.v.x;
    dz = GET_TRANSFORM(model)->pos.v.z - GET_TRANSFORM(EnvSound_PlayerModel)->pos.v.z;
    if ((s32) dx == 0 && (s32) dz == 0) {
        return 0;
    }
    val1 = atan2s(dz, dx);
    dx = EnvSound_MainCamera->viewMtx.lookAt.at.x - EnvSound_MainCamera->viewMtx.lookAt.eye.x;
    dz = EnvSound_MainCamera->viewMtx.lookAt.at.z - EnvSound_MainCamera->viewMtx.lookAt.eye.z;
    val1 -= atan2s(dz, dx);

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
        temp_v0 = EnvSound_GetTargetAngle(obj);
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

void EnvSound_Update(GObj* obj) {
    EnvSound* ptr;
    s32 volume, pan;
    s32 unused[2];

    if (EnvSound_PlayerModel == NULL || EnvSound_MainCamera == NULL) {
        return;
    }

    for (ptr = EnvSound_Sounds; ptr != NULL; ptr = ptr->next) {
        if (ptr->source != NULL) {
            OSIntMask mask = osSetIntMask(OS_IM_NONE);
            s32 soundId = auPlayingSound[ptr->soundHandle];

            if (soundId == -1 || soundId != ptr->soundId) {
                ptr->source = NULL;
                ptr->fixedParams = true;
            } else if (ptr->fixedParams != true) {
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

void EnvSound_Init(EnvSoundData* data, s32 numEntries) {
    EnvSound* envSound; // TODO required to match
    GObj* gobj;

    if (data != NULL && numEntries > 0) {
        EnvSound_InitData = data;
        EnvSound_InitDataSize = numEntries;
        EnvSound_PlayerModel = func_803573B0_4F77C0();
        EnvSound_MainCamera = getMainCamera();
        EnvSound_Sounds = gtlMalloc(sizeof(EnvSound), 4);
        envSound = EnvSound_Sounds;
        envSound->next = NULL;
        EnvSound_Sounds->source = NULL;
        gobj = omAddGObj(OBJID_ENV_SOUND_PLAYER, ohUpdateDefault, LINK_PLAYER, 1);
        do {
        } while (0); // TODO required to match
        omCreateProcess(gobj, EnvSound_Update, 1, 1);
    }
}

void EnvSound_Cleanup(void) {
    EnvSound_PlayerModel = NULL;
    EnvSound_MainCamera = NULL;
}

void EnvSound_PlaySoundInt(GObj* obj, u8 category, s32 soundID, u8 pitchModifier, u8 hearingRange) {
    Pokemon* pokemon = GET_POKEMON(obj);
    EnvSound* last;
    u32 volume, pan;
    EnvSound* ptr;

    if (2 * hearingRange < pokemon->playerDist / 100.0f || EnvSound_PlayerModel == NULL || EnvSound_MainCamera == NULL) {
        return;
    }

    for (ptr = EnvSound_Sounds; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj && ptr->category == category) {
            auStopSound(ptr->soundHandle);
            ptr->source = NULL;
        }
    }

    for (ptr = EnvSound_Sounds; ptr != NULL; ptr = ptr->next) {
        if (ptr->source != NULL) {
            last = ptr;
        } else {
            break;
        }
    }

    if (ptr == NULL) {
        ptr = gtlMalloc(sizeof(EnvSound), 4);
        ptr->next = NULL;
        ptr->source = NULL;
        last->next = ptr;
    }

    EnvSound_GetVolumePan(obj, hearingRange, (s32*) &volume, (s32*) &pan);
    if (volume > 0x7FFF) {
        volume = 0x7FFF;
    }
    if (pan > 0x7F) {
        pan = 0x7F;
    }

    pitchModifier = pitchModifier > 0x7F ? 0x7F : pitchModifier;

    switch (pitchModifier) {
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
        ptr->category = category;
        ptr->hearingRange = hearingRange;
        ptr->soundId = soundID;
        ptr->fixedParams = false;
    }
}

void EnvSound_PlaySound(GObj* obj, u8 category, s32 soundID) {
    s32 i;

    if (EnvSound_PlayerModel == NULL || EnvSound_MainCamera == NULL || EnvSound_Sounds == NULL) {
        return;
    }

    for (i = 0; i < EnvSound_InitDataSize; i++) {
        if (EnvSound_InitData[i].soundID == soundID) {
            EnvSound_PlaySoundInt(obj, category, soundID, EnvSound_InitData[i].pitchModifier, EnvSound_InitData[i].hearingRange);
            break;
        }
    }
}

void EnvSound_StopSoundByCategory(GObj* obj, u8 category) {
    EnvSound* ptr;

    for (ptr = EnvSound_Sounds; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj && ptr->category == category) {
            auStopSound(ptr->soundHandle);
            ptr->source = NULL;
        }
    }
}

void EnvSound_FixParams(GObj* obj) {
    EnvSound* ptr;

    for (ptr = EnvSound_Sounds; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj) {
            ptr->fixedParams = true;
        }
    }
}

void EnvSound_StopSounds(GObj* obj) {
    EnvSound* ptr;

    for (ptr = EnvSound_Sounds; ptr != NULL; ptr = ptr->next) {
        if (ptr->source == obj) {
            auStopSound(ptr->soundHandle);
            ptr->source = NULL;
        }
    }
}

s32 EnvSound_GetSoundHandle(s32 soundId) {
    EnvSound* ptr;

    for (ptr = EnvSound_Sounds; ptr != NULL; ptr = ptr->next) {
        if (ptr->source != NULL && ptr->soundId == soundId) {
            return ptr->soundHandle;
        }
    }
    return -1;
}
