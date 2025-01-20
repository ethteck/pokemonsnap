#include "volcano/volcano.h"

extern AnimCmd volcano_camera_anim_intro[];
extern AnimCmd* volcano_player_modelanim_intro[];
extern AnimCmd** volcano_player_matanim_intro[];

__ALIGNER2

s32 volcano_IntroEnded = false;
GObj* volcano_PlayerObj = NULL;

u8 volcano_intro_SoundHandle1;
u8 volcano_intro_SoundHandle2;
u8 volcano_intro_SoundHandle3;
u8 volcano_intro_SoundHandle4;

void volcano_IntroStartCutscene(GObj* obj) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(obj);
    func_803570B0_4F74C0();
}

void volcano_IntroStopCutscene(void) {
    func_803572B0_4F76C0();
}

void volcano_IntroAnimationCallback(struct DObj* dobj, s32 param, f32 value) {
    if (param == -2 || param == -1) {
        volcano_IntroEnded = true;
    } else if ((s32) value - 1 >= 0) {
        ParticleGenerator* gen = particle_makeGenerator(param, (s32) value - 1);
        if (gen != NULL) {
            gen->dobj = dobj;
        }
    }
}

void volcano_StopIntro(void) {
    if (auPlayingSound[volcano_intro_SoundHandle1] == SOUND_ID_21) {
        auStopSound(volcano_intro_SoundHandle1);
    }
    if (auPlayingSound[volcano_intro_SoundHandle2] == SOUND_ID_101) {
        auStopSound(volcano_intro_SoundHandle2);
    }
    if (auPlayingSound[volcano_intro_SoundHandle3] == SOUND_ID_30) {
        auStopSound(volcano_intro_SoundHandle3);
    }
    if (auPlayingSound[volcano_intro_SoundHandle4] == SOUND_ID_50) {
        auStopSound(volcano_intro_SoundHandle4);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    volcano_IntroStopCutscene();
    omDeleteGObj(NULL);
}

void volcano_PlayIntroSounds(GObj* obj) {
    s32 i;

    for (i = 0; i < 60; i++) {
        ohWait(1);
    }
    volcano_intro_SoundHandle1 = auPlaySoundWithParams(SOUND_ID_21, 32256, 64, 1.0f, 30);
    for (; i < 178; i++) {
        ohWait(1);
    }
    volcano_intro_SoundHandle2 = auPlaySoundWithParams(SOUND_ID_101, 12288, 64, 1.5f, 30);
    volcano_intro_SoundHandle3 = auPlaySoundWithParams(SOUND_ID_30, 8192, 64, 0.6f, 30);
    for (; i < 196; i++) {
        ohWait(1);
    }
    volcano_intro_SoundHandle4 = auPlaySoundWithParams(SOUND_ID_50, 12288, 64, 0.74f, 30);
    omEndProcess(NULL);
}

void volcano_UpdateIntro(GObj* obj) {
    s32 unused[4];
    s32 i;
    OMCamera* camera = getMainCamera();
    GObj* camObj = getMainCamera()->obj;
    f32 origXEye, origYEye, origZEye;
    f32 origXAt, origYAt, origZAt;
    f32 xEye, yEye, zEye;
    f32 xAt, yAt, zAt;
    GObjProcess* animProc;

    origXEye = camera->viewMtx.lookAt.eye.x;
    origYEye = camera->viewMtx.lookAt.eye.y;
    origZEye = camera->viewMtx.lookAt.eye.z;
    origXAt = camera->viewMtx.lookAt.at.x;
    origYAt = camera->viewMtx.lookAt.at.y;
    origZAt = camera->viewMtx.lookAt.at.z;
    camera->animSpeed = 0.5f;
    animSetCameraAnimation(camera, volcano_camera_anim_intro, 0);
    animProc = omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(volcano_player_modelanim_intro, volcano_player_matanim_intro, 0, 0.5f);
    volcano_IntroEnded = false;
    obj->fnAnimCallback = volcano_IntroAnimationCallback;
    omCreateProcess(obj, volcano_PlayIntroSounds, 0, 1);

    for (i = 0; !volcano_IntroEnded && i < 290; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            omEndProcess(animProc);
            volcano_StopIntro();
        }
        ohWait(1);
    }

    omEndProcess(animProc);

    xEye = camera->viewMtx.lookAt.eye.x;
    yEye = camera->viewMtx.lookAt.eye.y;
    zEye = camera->viewMtx.lookAt.eye.z;
    xAt = camera->viewMtx.lookAt.at.x;
    yAt = camera->viewMtx.lookAt.at.y;
    zAt = camera->viewMtx.lookAt.at.z;

    for (i = 0; i < 11; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            volcano_StopIntro();
        }
        camera->viewMtx.lookAt.eye.x = i * (origXEye - xEye) / 10.0f + xEye;
        camera->viewMtx.lookAt.eye.y = i * (origYEye - yEye) / 10.0f + yEye;
        camera->viewMtx.lookAt.eye.z = i * (origZEye - zEye) / 10.0f + zEye;
        camera->viewMtx.lookAt.at.x = i * (origXAt - xAt) / 10.0f + xAt;
        camera->viewMtx.lookAt.at.y = i * (origYAt - yAt) / 10.0f + yAt;
        camera->viewMtx.lookAt.at.z = i * (origZAt - zAt) / 10.0f + zAt;
        ohWait(1);
    };

    volcano_StopIntro();
    ohWait(1);
}

void volcano_StartIntro(void) {
    GObj* obj;

    obj = PlayerModel_Init();
    volcano_PlayerObj = obj;
    if (obj != NULL) {
        omCreateProcess(obj, volcano_UpdateIntro, 0, 1);
        volcano_IntroStartCutscene(obj);
    }
}
