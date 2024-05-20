#include "common.h"
#include "world/world.h"
#include "app_level.h"

enum CamMessageIds {
    MESSAGE_NONE                = 0,
    MESSAGE_PRESS_Z             = 1,
    MESSAGE_PRESS_A             = 2,
    MESSAGE_TAKE_PICTURES       = 3,
    MESSAGE_USE_CONTROL_STICK   = 4
};

enum PauseOptions {
    PAUSE_OPTION_CONTINUE = 0,
    PAUSE_OPTION_QUIT = 1,
    PAUSE_OPTION_RETRY = 2
};

void processTurnToDirection(GObj*);
void updateMovementState(GObj*);
void handleAnalogStick(GObj*);
void handleCButtons(GObj*);
void handleItemButtonsPress(GObj*);

// TODO make sprite assets

/*
s32 sMinTimeBetweenPhotos = 10;
MovementState gMovementState = {
    0.0f,
    0.5f,
    NULL,
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
}
*/

extern s32 sMinTimeBetweenPhotos;
extern MovementState gMovementState;
extern Sprite D_80366DF0_507200; // 506FE8 small reticle
extern Sprite D_80367580_507990; // 507248 reticle 2
extern Sprite D_80367D10_508120; // 5079D8 reticle 3
extern Sprite D_80367DC0_5081D0; // 508168 red dot
extern Sprite D_80368038_508448; // 508218 white dot
extern Sprite D_803706E0_510AF0; // 508490
extern Sprite D_80378D88_519198; // 510B38
extern Sprite D_80378ED8_5192E8; // 5191E0 white square
extern Sprite D_8037A9A0_51ADB0; // 519330 Pause
extern Sprite D_8037C468_51C878; // 51ADF8 Pause Pressed
extern Sprite D_8037D2A0_51D6B0; // 51C8C0 Quit Course
extern Sprite D_8037E0D8_51E4E8; // 51D6F8 Quit Course Pressed
extern Sprite D_8037EF10_51F320; // 51E530 Continue
extern Sprite D_8037FD48_520158; // 51F368 Continue Pressed
extern Sprite D_80380B80_520F90; // 5201A0 Retry
extern Sprite D_803819B8_521DC8; // 520FD8 Retry Pressed
extern Sprite D_80381B58_521F68; // 521E10 END

// we have to make this small array because of alignment
u32 D_80382BF0_523000[] = {
    0x803AE160,
    0x00000000,
    0x00000000
};

s32 gDirectionIndex = 2;
GObj* gObjPlayer = NULL;
DObj* gPlayerDObj = NULL;
s32 D_80382C08_523018_unused = 0;
f32 sViewPitch = 0.0f;
f32 D_80382C10_523020_unused = 0.0f;
s32 sReticleScreenX = 0;
s32 sReticleScreenY = 0;
f32 gCamTargetX = 0.0f;
f32 gCamTargetY = 0.0f;
f32 gCamTargetZ = -500.0f;
f32 sStickXAccum = 0.0f;
f32 sStickYAccum = 0.0f;
OMCamera* gMainCamera = NULL;
s32 D_80382C34_523044_unused = 0;
GObj* D_80382C38_523048 = NULL;
s32 D_80382C3C_52304C = 0;
GObj* D_80382C40_523050 = NULL;
f32 gTotalSpeedMult = 0.0005f;
f32 sCameraShakingDeltaY = 0.0f;
s32 sTargetDirectionZoomedIn = 0;
f32 sTargetDirectionYawZommedIn = 0.0f;
f32 D_80382C54_523064_unused = 0.0f;
f32 sCameraVibrationDeltaY = 0.0f;
f32 sCameraVibrationAmplitude = 20.0f;
f32 sCameraVibrationSpeed = 3.0f;
s32 D_80382C64_523074 = 0;
f32 gDashEngineSpeedMult = 1.0f;
GObj* gObjPauseMenu = NULL;
SObj* D_80382C70_523080 = NULL;
SObj* Pause_LabelPause2 = NULL;
SObj* Pause_LabelPause = NULL;
SObj* Pause_QuitCourseSelected = NULL;
SObj* Pause_QuitCourse = NULL;
SObj* Pause_ContinueSelected = NULL;
SObj* Pause_Continue = NULL;
SObj* Pause_RetrySelected = NULL;
SObj* Pause_Retry = NULL;
Vec3f gPlayerPos = { 0.0f, 0.0f, 0.0f };
Vec3f gPlayerVelocity = { 0.0f, 0.0f, 0.0f };
s32 D_80382CAC_5230BC_unused[2] = { 0, 0 };
s32 ThrowItemTimeout = 3;
s32 PressPokeFluteTimeout = 3;
s32 sDashEngineSoundTimeout = 3;
f32 sStickXValue = 0.0f;
f32 sStickYValue = 0.0f;
f32 gViewYaw = 0.0f; // relative to forward direction
f32 sTurnToDirSpeed = 0.0f;
f32 gCurrentDirectionYaw = 0.0f;
f32 D_80382CD4_5230E4 = 0.0f;
f32 sDirections[5] = {
    -3.141592741f,
    -1.570796371f,
    0.0f,
    1.570796371f,
    3.141592741f,
};
f32 sMinPitch = -0.3926990926f;
f32 sMaxPitch = 0.7853981853f;
s32 LastItemId = 0;
s32 D_80382CF8_523108 = 0;
s32 D_80382CFC_52310C = 0;
s8 D_80382D00_523110 = 2;
s8 D_80382D04_523114 = 0;
s32 D_80382D08_523118 = 0;
s32 IsInputDisabled = FALSE;
GObj* D_80382D10_523120 = NULL;
GObj* D_80382D14_523124 = NULL;
void (*EndLevelCb)(s32) = NULL;
void (*PauseCb)(s32) = NULL;
u8 gIsPaused = 0;
u8 Pause_CurrentSelection = 0;
s32 D_80382D28_523138 = 153;
u8 D_80382D2C_52313C = 0;
u8 D_80382D30_523140 = 0;
u8 D_80382D34_523144 = 0;
s32 D_80382D38_523148 = 360;
f32 D_80382D3C_52314C = 1.0f;
u8 Pause_ButtonPressTimeout = 0;
u8 D_80382D44_523154 = FALSE;
s32 sBGMSongID = -1;

extern s32 D_80382DC0_5231D0;
extern Sprite D_80388E00_529210;

// bss
extern s32 D_803AE408_54E818;
extern Vec3f gCameraEyePos;
extern Vec3f gCameraAtPos;
extern Vec3f gCameraViewVector;
extern SObj* sMainCameraReticles[4];
extern SObj* D_803AE458_54E868[6];
extern s32 D_803AE470_54E880;
extern s32 D_803AE474_54E884;
extern f32 D_803AE478_54E888;
extern f32 D_803AE47C_54E88C;
extern struct DObjDynamicStore sPlayerMatrixStore; // size 0x38
extern Vec3f D_803AE4D8_54E8E8;
extern Vec3f D_803AE4E8_54E8F8;
extern Vec3f D_803AE4F8_54E908;
extern Vec3f D_803AE508_54E918;
extern s8 sForceDashEngineDisabled;
extern s8 IsTutorialEnabled;
extern s8 D_803AE516_54E926;
extern IdleScript* gIdleScript;
extern u32 gProgressFlags;
extern s8 ZoomSwitchMode;
extern s8 IsAxisYInverted;
extern s8 IsDashEngineAvailable;
extern s32 gMainCameraViewport[4]; // Rect?
extern s32 MainCameraBorderXmin;
extern s32 MainCameraBorderYmin;
extern s32 MainCameraBorderXmax;
extern s32 MainCameraBorderYmax;
extern s32 D_803AE768_54EB78;
extern GObj* gPokemonInFocus; // TODO check if it's pokemon
extern s32 D_803AE770_54EB80;
extern u16 D_803AE774_54EB84;

extern s32 D_803AEF30_54F340;
extern u16 D_803AEF38_54F348;

void resetMainCameraSettings(void);
void handleItemButtonsPress(GObj*);
void handleAnalogStick(GObj*);
void handleCButtons(GObj*);
void updateCameraZoomedOut(GObj*);
void processZoomingIn(GObj*);
void processZoomingOut(GObj*);
void updateCameraZoomedIn(GObj*);
void updatePauseMenu(GObj*);
void func_80357120_4F7530(GObj*);
void screenCoorsToWorld(f32*, f32*, f32*);
void func_803588D4_4F8CE4(void);
void func_8035E37C_4FE78C(void);
void func_80365B24_505F34(void);
void showMessage(char*, s32, s32, u8, u8, u8, u8, s32, u8);
s32 func_80365E70_506280(void);
IdleScript* getIdleScript(void);
void func_800A7918(s32, f32);
void func_800A7F40(f32, f32, s32, f32);
void setMainCameraViewport(s32, s32, s32, s32);
void func_80365E34_506244(void);
void func_80358994_4F8DA4(s32);
void freezePokemons(GObj*);
void func_80357170_4F7580(void);
void func_80359064_4F9474(void);
void updateReticleScreenPos(GObj* arg0);
s32 func_8009BBF4(void);
void func_8035E4D0_4FE8E0(void);
void func_8035E764_4FEB74(void);
void func_8035E754_4FEB64(void);
void func_80359034_4F9444(void);
void func_800A1E6C(Vec3f* arg0);
void func_80356074_4F6484(GObj* arg0);
void processOutOfFilm(GObj*);
s32 func_8035E508_4FE918(void);
s32 makePhoto(GObj* gobj);
s32 func_8035E52C_4FE93C(void);

s32 func_80350200_4F0610(s32 pokemonID) {
    return func_800BF3D4_5C274(pokemonID) == 0;
}

void updateMovementState(GObj* obj) {
    Movement_Update(&gMovementState);
}

void bindCameraNextBlock(f32 dx, f32 dy, f32 dz) {
    gPlayerPos.x += dx;
    gPlayerPos.y += dy;
    gPlayerPos.z += dz;

    gMainCamera->viewMtx.lookAt.eye.x += dx;
    gMainCamera->viewMtx.lookAt.eye.y += dy;
    gMainCamera->viewMtx.lookAt.eye.z += dz;

    gMainCamera->viewMtx.lookAt.at.x += dx;
    gMainCamera->viewMtx.lookAt.at.y += dy;
    gMainCamera->viewMtx.lookAt.at.z += dz;

    gCameraEyePos.x += dx; gCameraEyePos.y += dy; gCameraEyePos.z += dz;
    gCameraAtPos.x += dx; gCameraAtPos.y += dy; gCameraAtPos.z += dz;
    gCamTargetX += dx; gCamTargetY += dy; gCamTargetZ += dz;
}

void stopLevelProcesses(void) {
    ohPauseProcessByFunction(gObjPlayer, processZoomingIn);
    ohPauseProcessByFunction(gObjPlayer, processZoomingOut);
    ohPauseProcessByFunction(gObjPlayer, updateCameraZoomedIn);
    ohPauseProcessByFunction(gObjPlayer, processTurnToDirection);
    ohPauseProcessByFunction(gObjPlayer, updateMovementState);
    ohPauseProcessByFunction(gObjPlayer, handleAnalogStick);
    ohPauseProcessByFunction(gObjPlayer, handleCButtons);
    ohPauseProcessByFunction(gObjPlayer, handleItemButtonsPress);
    ohPauseProcessByFunction(gObjPlayer, updateCameraZoomedOut);
    ohPauseProcessByFunction(gObjPauseMenu, updatePauseMenu);
}

void func_80350458_4F0868(s32 arg0, s32 arg1) {
    scRemovePostProcessFunc();
    func_800A7F68(arg0, arg1);
}

void updateIdle(GObj* obj) {
    f32 var_f20;
    s32 i;
    f32 duration = 120.0f;
    IdleScriptEntry* input = gIdleScript->inputs;

    for (i = gIdleScript->dataSize / sizeof(IdleScriptEntry); i > 0; i--, input++) {
        gContInputCurrentButtons = input->currentButtons;
        gContInputPressedButtons = input->pressedButtons;
        gContInputHeldButtons = input->heldButtons;
        gContInputReleasedButtons = input->releasedButtons;
        gContInputStickX = input->stickX;
        gContInputStickY = input->stickY;
        ohWait(1);
        if (D_800BF051 == 0 && (gContInputPressedButtons & (A_BUTTON | START_BUTTON))) {
            stopLevelProcesses();
            func_80350458_4F0868(10, 1);
            func_800A7470(0, 0, 0);
            func_800A7918(0, 0.5f);
            ohWait(1);
            while (func_800A7460() == 1) {
                ohWait(1);
            }
            EndLevelCb(END_LEVEL_REASON_IDLE_INTERRUPTED);
            omEndProcess(NULL);
            return;
        }
    }

    stopLevelProcesses();
    var_f20 = 1.0f;
    func_80350458_4F0868(10, 1);
    func_800A7F40(0.0f, 0.0f, 0, 2.0f);
    auSetBGMVolumeSmooth(1, 0, 120);
    ohWait(1);
    while (func_800A7460() == 1) {
        var_f20 += -(1.0f / duration);
        auSetSoundGlobalVolume(127.0f * var_f20);
        ohWait(1);
    }
    auSetSoundGlobalVolume(0);
    EndLevelCb(END_LEVEL_REASON_IDLE_FINISHED);
    omEndProcess(NULL);
}

void initIdle(GObj* obj) {
    IdleScript* unk = gIdleScript;
    setRandSeed(unk->randSeed);
    gProgressFlags = unk->playerFlags;
    omCreateProcess(obj, updateIdle, 0, 10);
}

void setBackgroundMusic(s32 songID) {
    sBGMSongID = songID;
}

void updateMusic(GObj* obj) {
    s32 timerAfterFluteStopped = 2;

    while (TRUE) {
        if (Items_GetPokeFluteState() == 0) {
            if (--timerAfterFluteStopped < 0) {
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                timerAfterFluteStopped = 2;
                auStopSong(BGM_PLAYER_MAIN);
                if (gIdleScript == NULL) {
                    auPlaySong(BGM_PLAYER_MAIN, sBGMSongID);
                }
            }
        } else {
            timerAfterFluteStopped = 2;
        }
        ohWait(1);
    }
}

void shakeCamera(GObj* obj) {
    f32 phase;
    s32 i;

    for (phase = 0.0f, i = 59; i > 0; i--) {
        sCameraShakingDeltaY = cosf(phase) * 15.0f;
        phase += 0.3f;
        if (phase > TAU) {
            phase -= TAU;
        }
        ohWait(1);
    }
    sCameraShakingDeltaY = 0.0f;
    omEndProcess(NULL);
}

void handleItemButtonsPress(GObj* obj) {
    if (!IsInputDisabled) {
        if ((gContInputPressedButtons & D_CBUTTONS) && Icons_NumItemsAvailable >= 3 && PressPokeFluteTimeout == 0) {
            LastItemId = ITEM_ID_POKEFLUTE;
            PressPokeFluteTimeout = 45;
            Icons_ProcessButtonPress(ITEM_ID_POKEFLUTE);
            Items_PlayPokeFlute();
        } else if (ThrowItemTimeout == 0) {
            if ((gContInputPressedButtons & B_BUTTON) && Icons_NumItemsAvailable >= 2) {
                LastItemId = ITEM_ID_PESTER_BALL;
                ThrowItemTimeout = 45;
                Items_SpawnPesterBall(&gMainCamera->viewMtx.lookAt.eye, &gPlayerVelocity);
                Icons_ProcessButtonPress(ITEM_ID_PESTER_BALL);
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                PressPokeFluteTimeout = 0;
            } else if ((gContInputPressedButtons & A_BUTTON) && Icons_NumItemsAvailable >= 1) {
                LastItemId = ITEM_ID_APPLE;
                ThrowItemTimeout = 45;
                Items_SpawnApple(&gMainCamera->viewMtx.lookAt.eye, &gPlayerVelocity);
                Icons_ProcessButtonPress(ITEM_ID_APPLE);
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                PressPokeFluteTimeout = 0;
            }
        }
    }
    if (ThrowItemTimeout > 0) {
        ThrowItemTimeout--;
    }
    if (PressPokeFluteTimeout > 0) {
        PressPokeFluteTimeout--;
    }
}

void handleAnalogStick(GObj* obj) {
    DObj* model = obj->data.dobj;

    if (ABS(gContInputStickX) >= 6 && !IsInputDisabled) {
        sStickXValue = (f32)gContInputStickX / 80.0;
        sStickXAccum += 0.014f * sStickXValue;
        if (sStickXAccum > 1.0f) {
            sStickXAccum = 1.0f;
        } else if (sStickXAccum < -1.0f) {
            sStickXAccum = -1.0f;
        }
    } else {
        sStickXValue = 0.0f;
        if (sStickXAccum > 0.8) {
            sStickXAccum -= 0.03;
        } else if (sStickXAccum < -0.8) {
            sStickXAccum += 0.03;
        }
    }

    if (ABS(gContInputStickY) >= 6 && !IsInputDisabled) {
        sStickYValue = (f32)gContInputStickY / 80.0;
        if (IsAxisYInverted == TRUE) {
            sStickYValue = -sStickYValue;
        }

        if (sStickYValue < 0.0f && sViewPitch <= sMaxPitch + 0.017453292f ||
            sStickYValue > 0.0f && sViewPitch >= sMinPitch - 0.017453292f)
        {
            sStickYAccum += 0.02f * sStickYValue;
        }

        if (sStickYAccum > 0.2f) {
            sStickYAccum = 0.2f;
        } else if (sStickYAccum < -0.9f) {
            sStickYAccum = -0.9f;
        }

        if (sStickYValue < 0.0f && sViewPitch <= sMaxPitch ||
            sStickYValue > 0.0f && sViewPitch > sMinPitch)
        {
            sViewPitch -= 0.015f * sStickYValue;
        }
    } else {
        if (sStickYAccum > 0.0) {
            sStickYAccum -= 0.03;
        } else if (sStickYAccum < -0.7) {
            sStickYAccum += 0.03;
        }
    }

    if (!(gDirectionIndex < 0 || (gDirectionIndex & 1))) {
    } else {
        if (ABS(D_80382CD4_5230E4) > 0.1f) {
            D_80382CD4_5230E4 -= SIGN(D_80382CD4_5230E4) * 0.1f;
        } else {
            D_80382CD4_5230E4 = 0.0f;
        }
    }

    if (!D_80382C64_523074) {
        gMovementState.cpTime += D_803AE47C_54E88C * 0.005f;
        if (gMovementState.cpTime > 1.0f) {
            gMovementState.cpTime = 1.0f;
        } else if (gMovementState.cpTime < 0.0f) {
            gMovementState.cpTime = 0.0f;
        }
        gMovementState.speedMult = gTotalSpeedMult;
    } else {
        gMovementState.speedMult = 0.0f;
    }

    GET_TRANSFORM(model)->pos.v.x = gMovementState.pos.x;
    GET_TRANSFORM(model)->pos.v.y = gMovementState.pos.y;
    GET_TRANSFORM(model)->pos.v.z = gMovementState.pos.z;
    GET_TRANSFORM(model)->rot.f[1] = gMovementState.rotation.x;
    GET_TRANSFORM(model)->rot.f[2] = gMovementState.rotation.y + D_80382CD4_5230E4;
    GET_TRANSFORM(model)->rot.f[3] = gMovementState.rotation.z;

    Vec3fDiff(&gPlayerVelocity, &GET_TRANSFORM(model)->pos.v, &gPlayerPos);

    gPlayerPos = GET_TRANSFORM(model)->pos.v;

    if (D_80382D04_523114 == 1) {
        if (ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG) && gDirectionIndex >= 0 ||
            ZoomSwitchMode == 0 && (gContInputCurrentButtons & Z_TRIG) && gDirectionIndex >= 0)
        {
            D_80382C3C_52304C = 0;
            auPlaySound(SOUND_ID_5);
            gDirectionIndex = -2;
            omCreateProcess(obj, processZoomingIn, 0, 9);
            ohPauseProcessByFunction(obj, handleCButtons);
            ohPauseProcessByFunction(obj, handleItemButtonsPress);
            ohPauseProcessByFunction(obj, updateCameraZoomedOut);
        }
    }
}

void func_80351114_4F1524(GObj* obj) {
    if (gTotalSpeedMult > 0.0f) {
        gTotalSpeedMult -= 0.0000025000002f;
    } else {
        gTotalSpeedMult = 0.0f;
    }
}

void playDashEngineSounds(s32 enabled) {
    static s32 dashEngineSoundHandle = -1;
    if (enabled == TRUE) {
        if (dashEngineSoundHandle == -1) {
            dashEngineSoundHandle = auPlaySound(SOUND_ID_14);
        }
    } else {
        if (dashEngineSoundHandle == -1) {
            return;
        }
        auStopSound(dashEngineSoundHandle);
        auPlaySound(SOUND_ID_15);
        dashEngineSoundHandle = -1;
        sDashEngineSoundTimeout = 10;
    }
}

s32 IsDashEngineOn = 0;
s32 D_80382D54_523164 = 100;

void updateDashEngine(void) {
    gDashEngineSpeedMult = 1.0f;
    if (!IsInputDisabled && IsDashEngineAvailable == 1) {
        if ((gContInputCurrentButtons & R_TRIG) && sForceDashEngineDisabled == 0) {
            gDashEngineSpeedMult *= 3.0f;
            Icons_SetDashEngineEnabled(TRUE);
            if (sDashEngineSoundTimeout == 0) {
                playDashEngineSounds(TRUE);
            }
        } else {
            playDashEngineSounds(FALSE);
            IsDashEngineOn = 0;
            Icons_SetDashEngineEnabled(FALSE);
        }
    }
    if (sDashEngineSoundTimeout > 0) {
        sDashEngineSoundTimeout--;
    }
    gTotalSpeedMult = gDashEngineSpeedMult * 0.0005f * (1.0f + D_803AE478_54E888 * 0.25f);
}

void handleCButtons(GObj* obj) {
    s32 CButtonPressed = FALSE;

    if (gDirectionIndex < 0) {
        return;
    }

    if (!IsInputDisabled) {
        if (gContInputPressedButtons & U_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            if (gDirectionIndex == 0) {
                sTurnToDirSpeed = 0.2f;
            } else if (gDirectionIndex == 1) {
                sTurnToDirSpeed = 0.1f;
            } else {
                sTurnToDirSpeed = -0.1f;
            }
            gDirectionIndex = 2;
            CButtonPressed = TRUE;
            sReticleScreenX = 0;
        } else if (gContInputPressedButtons & R_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            gDirectionIndex++;
            if (gDirectionIndex >= 4) {
                gDirectionIndex -= 4;
            }
            CButtonPressed = TRUE;
            sTurnToDirSpeed = 0.1f;
            sReticleScreenX = 0;
        } else if (gContInputPressedButtons & L_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            gDirectionIndex--;
            if (gDirectionIndex < 0) {
                gDirectionIndex += 4;
            }
            CButtonPressed = TRUE;
            sTurnToDirSpeed = -0.1f;
            sReticleScreenX = 0;
        }
    }

    updateDashEngine();
    if (CButtonPressed) {
        sStickXAccum = 0.0f;
        gViewYaw = 0.0f;
        ohResumeProcessByFunction(obj, processTurnToDirection);
        ohPauseProcessByFunction(obj, updateMovementState);
        ohPauseProcessByFunction(obj, handleAnalogStick);
        ohPauseProcessByFunction(obj, handleCButtons);
        return;
    }

    if (ABS(sReticleScreenX) > 50) {
        gViewYaw += sStickXValue * 0.03 * 0.8;
    }
}

void processTurnToDirection(GObj* obj) {
    f32 currentYaw;
    f32 targetYaw;
    s32 v0 = 0;

    if (gIsPaused) {
        return;
    }

    targetYaw = sDirections[gDirectionIndex];
    currentYaw = gCurrentDirectionYaw;

    while (targetYaw < 0.0f) {
        targetYaw += TAU;
    }
    while (targetYaw >= TAU) {
        targetYaw -= TAU;
    }

    while (currentYaw < 0.0f) {
        currentYaw += TAU;
    }
    while (currentYaw >= TAU) {
        currentYaw -= TAU;
    }

    if (ABS(targetYaw - currentYaw) > ABS(sTurnToDirSpeed)) {
        gCurrentDirectionYaw += sTurnToDirSpeed;
    } else {
        gCurrentDirectionYaw = sDirections[gDirectionIndex];
        v0++;
    }
    targetYaw = 0.04712389f; // need var reuse for matching
    if (ABS(sViewPitch) > targetYaw) {
        if (sViewPitch > 0.0f) {
            sViewPitch -= targetYaw;
        } else {
            sViewPitch += targetYaw;
        }
    } else {
        sViewPitch = 0.0f;
        v0++;
    }

    if (v0 >= 2) {
        sTurnToDirSpeed = 0.0f;
        ohResumeProcessByFunction(obj, updateMovementState);
        ohResumeProcessByFunction(obj, handleAnalogStick);
        ohResumeProcessByFunction(obj, handleCButtons);
        ohPauseProcessByFunction(obj, processTurnToDirection);
    }
}

static void nullsub(void) {

}

void updateCameraZoomedOut(GObj* obj) {
    f32 sp94;
    f32 unused1[6];
    Vec3f eyePos;
    Vec3f sp64;
    f32 unused2[11];
    f32 dx, dz;
    f32 delta1;
    f32 oneHundred = 100.0f;

    static f32 D_80382D58_523168 = 0.0f;
    static f32 D_80382D5C_52316C = 50.0f;
    static f32 D_80382D60_523170 = 0.0f;
    static f32 D_80382D64_523174 = 50.0f;

    if (gDirectionIndex == 0) {
        if (gViewYaw > 0.9424779f) {
            gDirectionIndex = 1;
            gViewYaw = -0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        } else if (gViewYaw < -0.9424779f) {
            gDirectionIndex = 3;
            gViewYaw = 0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        }
    } else if (gDirectionIndex == 1) {
        if (gViewYaw > 0.9424779f) {
            gDirectionIndex = 2;
            gViewYaw = -0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        } else if (gViewYaw < -0.9424779f) {
            gDirectionIndex = 0;
            gViewYaw = 0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        }
    } else if (gDirectionIndex == 2) {
        if (gViewYaw > 0.9424779f) {
            gDirectionIndex = 3;
            gViewYaw = -0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        } else if (gViewYaw < -0.9424779f) {
            gDirectionIndex = 1;
            gViewYaw = 0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        }
    } else if (gDirectionIndex == 3) {
        if (gViewYaw > 0.9424779f) {
            gDirectionIndex = 0;
            gViewYaw = -0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        } else if (gViewYaw < -0.9424779f) {
            gDirectionIndex = 2;
            gViewYaw = 0.62831855f;
            gCurrentDirectionYaw = sDirections[gDirectionIndex];
        }
    }

    if (gDirectionIndex == 0) {
        sStickXValue *= -1.0f;
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    } else if (gDirectionIndex == 1) {
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    } else if (gDirectionIndex == 2) {
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    } else if (gDirectionIndex == 3) {
        D_80382D60_523170 = 0.0f;
        D_80382D64_523174 = 0.0f;
    }

    sp94 = gCurrentDirectionYaw + gViewYaw;
    D_803AE478_54E888 = cosf(sp94);
    D_803AE47C_54E88C = sinf(sp94);

    if (!D_80382C64_523074) {
        gTotalSpeedMult = gDashEngineSpeedMult * 0.0005f * (1.0f + D_803AE478_54E888 * 0.25f);
    }

    if (ABS(D_80382D60_523170 - D_80382D58_523168) > 0.2f) {
        D_80382D58_523168 += SIGN(D_80382D60_523170 - D_80382D58_523168) * 0.2f;
    } else {
        D_80382D58_523168 = D_80382D60_523170;
    }

    if (ABS(D_80382D64_523174 - D_80382D5C_52316C) > 0.2f) {
        D_80382D5C_52316C += SIGN(D_80382D64_523174 - D_80382D5C_52316C) * 0.2f;
        D_80382D64_523174 = D_80382D64_523174;
    } else {
        D_80382D5C_52316C = D_80382D64_523174;
        D_80382D64_523174 = D_80382D64_523174;
    }

    sinf(gMovementState.rotation.y);
    cosf(gMovementState.rotation.y);

    eyePos.x = gCameraEyePos.x = gMovementState.pos.x;
    eyePos.y = gCameraEyePos.y = gMovementState.pos.y + oneHundred + sCameraShakingDeltaY + sCameraVibrationDeltaY;
    eyePos.z = gCameraEyePos.z = gMovementState.pos.z;

    sp64.x = -20.0f * cosf(sViewPitch) * sinf(sp94);
    sp64.y = 20.0f * sinf(sViewPitch);
    sp64.z = 20.0f * cosf(sViewPitch) * cosf(sp94);

    Vec3fGetEulerRotation(&sp64, AXIS_X, gMovementState.rotation.x);
    Vec3fGetEulerRotation(&sp64, AXIS_Y, gMovementState.rotation.y);
    Vec3fGetEulerRotation(&sp64, AXIS_Z, gMovementState.rotation.z);

    gCameraAtPos.x = sp64.x + eyePos.x;
    gCameraAtPos.y = sp64.y + eyePos.y;
    gCameraAtPos.z = sp64.z + eyePos.z;

    dx = gCameraAtPos.x - gCameraEyePos.x;
    dz = gCameraAtPos.z - gCameraEyePos.z;
    if (SQ(dx) + SQ(dz) < 0.1f) {
        gCameraAtPos.x = gCameraEyePos.x + gCameraViewVector.x;
        gCameraAtPos.z = gCameraEyePos.z + gCameraViewVector.z;
    } else {
        gCameraViewVector.x = dx;
        gCameraViewVector.z = dz;
    }

    gMainCamera->viewMtx.lookAt.eye.x = gCameraEyePos.x;
    gMainCamera->viewMtx.lookAt.eye.y = gCameraEyePos.y;
    gMainCamera->viewMtx.lookAt.eye.z = gCameraEyePos.z;
    gMainCamera->viewMtx.lookAt.at.x = gCameraAtPos.x;
    gMainCamera->viewMtx.lookAt.at.y = gCameraAtPos.y;
    gMainCamera->viewMtx.lookAt.at.z = gCameraAtPos.z;
}

char D_80382D68_523178[] = "\\#S0\\[\\]\\#S1";
s32 D_80382D78_523188 = 0;


void WorldToPlayerCoors(Vec3f* pos) {
    f32 sin;
    f32 cos;
    f32 x;
    f32 y;
    f32 z;

    x = pos->x - gMovementState.pos.x;
    y = pos->y - gMovementState.pos.y;
    z = pos->z - gMovementState.pos.z;
    sin = sinf(-gMovementState.rotation.y);
    cos = cosf(-gMovementState.rotation.y);
    pos->x = x * cos + z * sin;
    pos->y = y;
    pos->z = z * cos - x * sin;
}

void PlayerToWorldCoors(Vec3f* arg0) {
    f32 sp2C, sp28;
    f32 x, y, z;

    x = arg0->x;
    y = arg0->y;
    z = arg0->z;
    sp2C = sinf(gMovementState.rotation.y);
    sp28 = cosf(gMovementState.rotation.y);

    arg0->x = x * sp28 + z * sp2C + gMovementState.pos.x;
    arg0->y = y + gMovementState.pos.y;
    arg0->z = z * sp28 - x * sp2C + gMovementState.pos.z;
}

void processZoomingIn(GObj* obj) {
    s32 unused1;
    s32 i;
    f32 sp114;
    f32 sp110;
    s32 unused2[6];
    Vec3f spEC;
    Vec3f spE0;
    Vec3f spD4;
    f32 f28;
    s32 y1, y2;
    s32 x1, x2;
    s32 unused3;
    f32 dx, dy, dz;
    s32 y3, y4;
    s32 x3, x4;
    f32 sinAngle, cosAngle;
    s32 unused4[4];
    f32 dx2, dz2;

    i = 0;

    Icons_ProcessZoom(TRUE);

    y1 = 0;
    y2 = SCREEN_HEIGHT;
    x1 = 0;
    x2 = SCREEN_WIDTH;
    y3 = 0;
    y4 = SCREEN_HEIGHT;
    x3 = 0;
    x4 = SCREEN_WIDTH;

    D_803AE4F8_54E908.x = 0.0f;
    D_803AE4F8_54E908.y = 100.0f;
    D_803AE4F8_54E908.z = 0.0f;
    PlayerToWorldCoors(&D_803AE4F8_54E908);

    dx = gCamTargetX - D_803AE4F8_54E908.x;
    dy = gCamTargetY - D_803AE4F8_54E908.y;
    dz = gCamTargetZ - D_803AE4F8_54E908.z;
    f28 = sqrtf(SQ(dx) + SQ(dz));
    sinAngle = sinf(-gMovementState.rotation.y);
    cosAngle = cosf(-gMovementState.rotation.y);

    spD4.x = dx * cosAngle + dz * sinAngle;
    spD4.y = dy;
    spD4.z = dz * cosAngle - dx * sinAngle;

    gViewYaw = atanf(spD4.x / spD4.z);
    sViewPitch = atanf(spD4.y / f28);
    if (spD4.z > 0.0f) {
        gViewYaw = TAU - gViewYaw;
    } else {
        gViewYaw = 3.1415927f - gViewYaw;
    }
    if (gViewYaw > TAU) {
        gViewYaw -= TAU;
    } else if (gViewYaw < 0.0f) {
        gViewYaw += TAU;
    }

    D_803AE4F8_54E908.x = 0.0f;
    D_803AE4F8_54E908.y = 100.0f;
    D_803AE4F8_54E908.z = 0.0f;

    spD4.x = gCamTargetX;
    spD4.y = gCamTargetY;
    spD4.z = gCamTargetZ;
    WorldToPlayerCoors(&spD4);
    spD4.x -= D_803AE4F8_54E908.x;
    spD4.y -= D_803AE4F8_54E908.y;
    spD4.z -= D_803AE4F8_54E908.z;
    Vec3fNormalize(&spD4);

    D_803AE508_54E918.x = 20.0f * spD4.x + D_803AE4F8_54E908.x;
    D_803AE508_54E918.y = 20.0f * spD4.y + D_803AE4F8_54E908.y;
    D_803AE508_54E918.z = 20.0f * spD4.z + D_803AE4F8_54E908.z;
    D_803AE4D8_54E8E8.x = gCameraEyePos.x;
    D_803AE4D8_54E8E8.y = gCameraEyePos.y;
    D_803AE4D8_54E8E8.z = gCameraEyePos.z;
    D_803AE4E8_54E8F8.x = gCameraAtPos.x;
    D_803AE4E8_54E8F8.y = gCameraAtPos.y;
    D_803AE4E8_54E8F8.z = gCameraAtPos.z;
    WorldToPlayerCoors(&D_803AE4D8_54E8E8);
    WorldToPlayerCoors(&D_803AE4E8_54E8F8);

    spEC.x = D_803AE4F8_54E908.x - D_803AE4D8_54E8E8.x;
    spEC.y = D_803AE4F8_54E908.y - D_803AE4D8_54E8E8.y;
    spEC.z = D_803AE4F8_54E908.z - D_803AE4D8_54E8E8.z;
    sp114 = Vec3fNormalize(&spEC) / 10.0f;
    spE0.x = D_803AE508_54E918.x - D_803AE4E8_54E8F8.x;
    spE0.y = D_803AE508_54E918.y - D_803AE4E8_54E8F8.y;
    spE0.z = D_803AE508_54E918.z - D_803AE4E8_54E8F8.z;
    sp110 = Vec3fNormalize(&spE0) / 10.0f;

    while (TRUE) {
        if (ZoomSwitchMode == 0 && (gContInputReleasedButtons & Z_TRIG)) {
            break;
        }

        sinAngle = sinf(gMovementState.rotation.y);
        cosAngle = cosf(gMovementState.rotation.y);

        D_803AE4D8_54E8E8.x += sp114 * spEC.x;
        D_803AE4D8_54E8E8.y += sp114 * spEC.y;
        D_803AE4D8_54E8E8.z += sp114 * spEC.z;

        gCameraEyePos.x = gMovementState.pos.x + D_803AE4D8_54E8E8.x * cosAngle + D_803AE4D8_54E8E8.z * sinAngle;
        gCameraEyePos.y = gMovementState.pos.y + D_803AE4D8_54E8E8.y;
        gCameraEyePos.z = gMovementState.pos.z - D_803AE4D8_54E8E8.x * sinAngle + D_803AE4D8_54E8E8.z * cosAngle;

        D_803AE4E8_54E8F8.x += sp110 * spE0.x;
        D_803AE4E8_54E8F8.y += sp110 * spE0.y;
        D_803AE4E8_54E8F8.z += sp110 * spE0.z;

        gCameraAtPos.x = gMovementState.pos.x + D_803AE4E8_54E8F8.x * cosAngle + D_803AE4E8_54E8F8.z * sinAngle;
        gCameraAtPos.y = gMovementState.pos.y + D_803AE4E8_54E8F8.y;
        gCameraAtPos.z = gMovementState.pos.z - D_803AE4E8_54E8F8.x * sinAngle + D_803AE4E8_54E8F8.z * cosAngle;

        dx2 = gCameraAtPos.x - gCameraEyePos.x;
        dz2 = gCameraAtPos.z - gCameraEyePos.z;
        if ((SQ(dx2) + SQ(dz2)) < 0.1f) {
            gCameraAtPos.x = gCameraEyePos.x + gCameraViewVector.x;
            gCameraAtPos.z = gCameraEyePos.z + gCameraViewVector.z;
        } else {
            gCameraViewVector.x = dx2;
            gCameraViewVector.z = dz2;
        }

        x1 -= 2;
        y1 -= 2;
        x2 += 2;
        y2 += 2;

        gMainCamera->viewMtx.lookAt.eye.x = gCameraEyePos.x;
        gMainCamera->viewMtx.lookAt.eye.y = gCameraEyePos.y + sCameraVibrationDeltaY;
        gMainCamera->viewMtx.lookAt.eye.z = gCameraEyePos.z;
        gMainCamera->viewMtx.lookAt.at.x = gCameraAtPos.x;
        gMainCamera->viewMtx.lookAt.at.y = gCameraAtPos.y + sCameraVibrationDeltaY;
        gMainCamera->viewMtx.lookAt.at.z = gCameraAtPos.z;

        func_80007C20(&gMainCamera->vp, x1, y1, x2, y2);

        x3 += 3;
        y3 += 2;
        x4 -= 3;
        y4 -= 2;

        gMainCamera->perspMtx.persp.aspect = (f32)(x2 - x1) / (f32)(y2 - y1);
        gMainCamera->perspMtx.persp.fovy = 55.0f - i * 1.5f;

        setMainCameraViewport(x3, y3, x4, y4);
        i++;
        ohWait(1);
        if (ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG)) {
            break;
        }

        updateDashEngine();
        if (i >= 10) {
            break;
        }
    }

    gDirectionIndex = -1;
    sTargetDirectionZoomedIn = 0;
    omCreateProcess(obj, updateCameraZoomedIn, 1, 9);
    omEndProcess(NULL);
}

void processZoomingOut(GObj* obj) {
    f32 unused3;
    f32 angle1;
    s32 x2, y2, x1, y1;
    s32 direction;
    Vec3f viewVector;
    s32 unused[13];
    s32 y3, y4, x3, x4;
    f32 temp_f14;
    f32 temp_f18;
    f32 temp_f20;
    f32 dx;
    f32 dz;
    s32 unused2[2];
    s32 i = 0;

    auPlaySound(SOUND_ID_6);
    D_80382CF8_523108 = 0;
    D_80382CFC_52310C = 0;
    sStickXAccum = 0.0f;

    y1 = -25;
    y2 = 265;
    x1 = -25;
    x2 = 345;

    y3 = 22;
    y4 = 216;
    x3 = 30;
    x4 = 289;
    sStickYAccum = 0.0f;

    while (i++ < 10) {
        if (ZoomSwitchMode == 0 && (gContInputPressedButtons & Z_TRIG)) { break; }

        temp_f14 = gMovementState.pos.x - gCameraEyePos.x;
        temp_f18 = gMovementState.pos.y + 100.0f + sCameraShakingDeltaY - gCameraEyePos.y;
        temp_f20 = gMovementState.pos.z - gCameraEyePos.z;

        gCameraEyePos.x = gMovementState.pos.x;
        gCameraEyePos.y = gMovementState.pos.y + 100.0f + sCameraShakingDeltaY;
        gCameraEyePos.z = gMovementState.pos.z;

        gCameraAtPos.x += temp_f14;
        gCameraAtPos.y += temp_f18;
        gCameraAtPos.z += temp_f20;

        dx = gCameraAtPos.x - gCameraEyePos.x;
        dz = gCameraAtPos.z - gCameraEyePos.z;
        if (SQ(dx) + SQ(dz) < 0.1f) {
            gCameraAtPos.x = gCameraEyePos.x + gCameraViewVector.x;
            gCameraAtPos.z = gCameraEyePos.z + gCameraViewVector.z;
        } else {
            gCameraViewVector.x = dx;
            gCameraViewVector.z = dz;
        }

        gMainCamera->viewMtx.lookAt.eye.x = gCameraEyePos.x;
        gMainCamera->viewMtx.lookAt.eye.y = gCameraEyePos.y;
        gMainCamera->viewMtx.lookAt.eye.z = gCameraEyePos.z;
        gMainCamera->viewMtx.lookAt.at.x = gCameraAtPos.x;
        gMainCamera->viewMtx.lookAt.at.y = gCameraAtPos.y;
        gMainCamera->viewMtx.lookAt.at.z = gCameraAtPos.z;
        gMainCamera->viewMtx.lookAt.eye.y += sCameraVibrationDeltaY;
        gMainCamera->viewMtx.lookAt.at.y += sCameraVibrationDeltaY;

        x1 += 2;
        y1 += 2;
        x2 -= 2;
        y2 -= 2;
        func_80007C20(&gMainCamera->vp, x1, y1, x2, y2);

        gMainCamera->perspMtx.persp.aspect = (f32) (x2 - x1) / (f32) (y2 - y1);
        gMainCamera->perspMtx.persp.fovy = 55.0f - (10.0f - i) * 1.5f;

        y4 += 2;
        x4 += 3;
        y3 -= 2;
        x3 -= 3;
        setMainCameraViewport(x3, y3, x4, y4);
        ohWait(1);
        if (ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG)) {
            break;
        }
        updateDashEngine();
    }

    resetMainCameraSettings();
    viewVector.x = gCameraAtPos.x - gCameraEyePos.x;
    viewVector.y = gCameraAtPos.y - gCameraEyePos.y;
    viewVector.z = gCameraAtPos.z - gCameraEyePos.z;
    Vec3fNormalize(&viewVector);
    Vec3fGetEulerRotation(&viewVector, 4, -gMovementState.rotation.z);
    Vec3fGetEulerRotation(&viewVector, 2, -gMovementState.rotation.y);
    Vec3fGetEulerRotation(&viewVector, 1, -gMovementState.rotation.x);
    sViewPitch = asinf(viewVector.y);
    angle1 = acosf(viewVector.z / cosf(sViewPitch));
    if (viewVector.x > 0.0f) {
        angle1 = TAU - angle1;
    }

    if (angle1 < 0.7853982f) {
        direction = 2;
    } else if (angle1 < 2.3561945f) {
        direction = 3;
    } else if (angle1 < 3.926991f) {
        direction = 0;
    } else if (angle1 < 5.4977875f) {
        direction = 1;
    } else {
        direction = 2;
    }

    gCurrentDirectionYaw = sDirections[direction];
    if (gCurrentDirectionYaw < 0.0f) {
        gCurrentDirectionYaw += TAU;
    }
    if (direction == 2) {
        if (angle1 > 3.1415927f) {
            gViewYaw = angle1 - TAU;
        } else {
            gViewYaw = angle1;
        }
        gCurrentDirectionYaw = sDirections[direction];
    } else {
        gViewYaw = angle1 - gCurrentDirectionYaw;
        gCurrentDirectionYaw = sDirections[direction];
    }
    gMainCamera->viewMtx.lookAt.eye.x = gCameraEyePos.x;
    gMainCamera->viewMtx.lookAt.eye.y = gCameraEyePos.y + sCameraVibrationDeltaY;
    gMainCamera->viewMtx.lookAt.eye.z = gCameraEyePos.z;
    gMainCamera->viewMtx.lookAt.at.x = gCameraAtPos.x;
    gMainCamera->viewMtx.lookAt.at.y = gCameraAtPos.y + sCameraVibrationDeltaY;
    gMainCamera->viewMtx.lookAt.at.z = gCameraAtPos.z;
    Icons_ProcessZoom(FALSE);
    sReticleScreenX = 0;
    gDirectionIndex = direction;
    ohResumeProcessByFunction(obj, handleCButtons);
    ohResumeProcessByFunction(obj, handleItemButtonsPress);
    ohResumeProcessByFunction(obj, updateCameraZoomedOut);
    omEndProcess(NULL);
}

s32 strcmp2(u8* arg0, u8* arg1) {
    if (arg0 == NULL || arg1 == NULL) {
        return 0;
    }

    while (TRUE) {
        s32 diff = *arg0 - *arg1;
        if (diff != 0) {
            return diff;
        }
        if (*arg0 == 0 || *arg1 == 0) {
            break;
        }
        arg0++;
        arg1++;
    }
    return 0;
}

void showPokemonLabel(s32 pokemonID, s32 arg1, s32* arg2) {
    char sp40[32];
    char* pokemonName;

    if (D_803AE516_54E926) {
        return;
    }

    if (arg1 == 0) {
        if (*arg2 == 0) {
            *arg2 = 1;
            func_80365E34_506244();
        }
    } else if (*arg2 != 0) {
        *arg2 = 0;
        pokemonName = getPokemonName(pokemonID);
        if (pokemonName != NULL) {
            if (func_80350200_4F0610(pokemonID) && strcmp2(pokemonName, "？")) {
                sprintf(sp40, "%s%s", pokemonName, D_80382D68_523178);
                pokemonName = sp40;
            }
        } else {
            pokemonName = "？";
        }
        showMessage(pokemonName, 160, 200, 255, 255, 255, 255, 0, 2);
    }
}

void func_80352F20_4F3330(GObj* arg0) {
    s32 i;
    s32 pokemonID;
    s32 sp3C;

    pokemonID = D_803AE408_54E818;
    sp3C = 0;

    if (pokemonID != 0) {
        if (func_80350200_4F0610(pokemonID)) {
            auPlaySound(SOUND_ID_2);
        }

        for (i = 48; i > 0; i--) {
            if (D_803AE408_54E818 != pokemonID ||
               ZoomSwitchMode == 0 && !(gContInputCurrentButtons & Z_TRIG) ||
               ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG))
            {
                goto END;
            }
            showPokemonLabel(pokemonID, i & 0xC, &sp3C);
            ohWait(1);
        }

        showPokemonLabel(pokemonID, 1, &sp3C);

        for (i = 60; i > 0; i--) {
            if (D_803AE408_54E818 != pokemonID ||
               ZoomSwitchMode == 0 && !(gContInputCurrentButtons & Z_TRIG) ||
               ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG))
            {
                goto END;
            }
            ohWait(1);
        }
    }
END:
    if (!D_803AE516_54E926) {
        if (&sp3C) {
        } // required to match
        func_80365E34_506244();
    }
    omEndProcess(NULL);
}

void Camera_EndProcessByFunction(GObj* obj, GObjFunc func) {
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

void func_80353118_4F3528(GObj* obj) {
    if (!gIsPaused && D_80382D44_523154 == 0 && D_80382D78_523188 != gtlDrawnFrameCounter) {
        spSetAttribute(&gObjPauseMenu->data.sobj->sprite, SP_HIDDEN);
    }
}

void updateCameraZoomedIn(GObj* obj) {
    s32 unused[2];
    f32 sinCartYaw, cosCartYaw;
    Vec3f unused2;
    Vec3f eyePos;
    f32 viewVectorZ;
    f32 viewVectorY;
    f32 viewVectorX;
    s32 sp38;
    GObj* camera;
    f32 dz;
    f32 dx;

    static s32 sTimerAfterPhotoTaken = -1;

    if (D_80382D08_523118 == 0) {
        if (sTargetDirectionZoomedIn == 1) {
            gViewYaw += 0.1f;
            if (sTargetDirectionYawZommedIn < gViewYaw) {
                sTargetDirectionZoomedIn = 0;
                gViewYaw = sTargetDirectionYawZommedIn;
            }
        } else if (sTargetDirectionZoomedIn == 2) {
            gViewYaw -= 0.1f;
            if (gViewYaw < sTargetDirectionYawZommedIn) {
                sTargetDirectionZoomedIn = 0;
                gViewYaw = sTargetDirectionYawZommedIn;
            }
        } else {
            gViewYaw = gViewYaw + sStickXValue * 0.025;
            if (gViewYaw > TAU) {
                gViewYaw -= TAU;
            } else if (gViewYaw < 0.0f) {
                gViewYaw += TAU;
            }
        }
        sinCartYaw = sinf(gMovementState.rotation.y);
        cosCartYaw = cosf(gMovementState.rotation.y);

        eyePos.x = gCameraEyePos.x = gMovementState.pos.x;
        eyePos.y = gCameraEyePos.y = gMovementState.pos.y + 100.0f + sCameraVibrationDeltaY;
        eyePos.z = gCameraEyePos.z = gMovementState.pos.z;

        viewVectorX = -20.0f * cosf(sViewPitch) * sinf(gViewYaw);
        viewVectorY = 20.0f * sinf(sViewPitch);
        viewVectorZ = 20.0f * cosf(sViewPitch) * cosf(gViewYaw);

        gCameraAtPos.x = viewVectorX * cosCartYaw + viewVectorZ * sinCartYaw + eyePos.x;
        gCameraAtPos.y = viewVectorY + eyePos.y;
        gCameraAtPos.z = viewVectorZ * cosCartYaw - viewVectorX * sinCartYaw + eyePos.z;

        dx = gCameraAtPos.x - gCameraEyePos.x;
        dz = gCameraAtPos.z - gCameraEyePos.z;
        if (SQ(dx) + SQ(dz) < 0.1f) {
            gCameraAtPos.x = gCameraEyePos.x + gCameraViewVector.x;
            gCameraAtPos.z = gCameraEyePos.z + gCameraViewVector.z;
        } else {
            gCameraViewVector.x = dx;
            gCameraViewVector.z = dz;
        }

        gMainCamera->viewMtx.lookAt.eye.x = gCameraEyePos.x;
        gMainCamera->viewMtx.lookAt.eye.y = gCameraEyePos.y;
        gMainCamera->viewMtx.lookAt.eye.z = gCameraEyePos.z;
        gMainCamera->viewMtx.lookAt.at.x = gCameraAtPos.x;
        gMainCamera->viewMtx.lookAt.at.y = gCameraAtPos.y;
        gMainCamera->viewMtx.lookAt.at.z = gCameraAtPos.z;
    }
    if (ZoomSwitchMode == 1 || (gContInputCurrentButtons & Z_TRIG)) {
        if (D_803AE768_54EB78 == 1 && gPokemonInFocus != NULL && GET_POKEMON(gPokemonInFocus) == NULL) {
            D_803AE768_54EB78 = 0;
        }
        if (D_803AE768_54EB78 == 1 && (D_803AE774_54EB84 & 4)) {
            if (D_80382C40_523050 == gPokemonInFocus) {
                D_80382CF8_523108++;
            } else {
                D_80382CF8_523108 = 0;
                D_80382C3C_52304C = 0;
            }
            D_80382CFC_52310C = 2;
            if ((D_80382C3C_52304C == 0 || D_803AE474_54E884 != (D_803AE774_54EB84 & 8)) && gDirectionIndex == -1) {
                omCreateProcess(D_80382C38_523048, func_80356074_4F6484, 0, 9);
                auPlaySound(SOUND_ID_1);
                D_80382C3C_52304C = 1;
                D_80382C40_523050 = gPokemonInFocus;
                D_803AE470_54E880 = D_803AE770_54EB80;
                D_803AE474_54E884 = D_803AE774_54EB84 & 8;
            }
        } else if (D_80382CFC_52310C != 0) {
            D_80382CFC_52310C--;
        } else {
            D_80382CF8_523108 = 0;
            D_80382C3C_52304C = 0;
        }
        if (sTimerAfterPhotoTaken < 0) {
            if (sTargetDirectionZoomedIn == 0 && (gContInputPressedButtons & A_BUTTON)) {
                camera = ohFindByLinkAndId(LINK_0, OBJID_MAIN_CAMERA);
                if (camera != NULL) {
                    if (D_80382D00_523110 == 2) {
                        spColor(&gObjPauseMenu->data.sobj->sprite, 0, 0, 0, D_80382D54_523164);
                        spClearAttribute(&gObjPauseMenu->data.sobj->sprite, SP_HIDDEN);
                        D_80382D78_523188 = gtlDrawnFrameCounter;
                    } else if (D_80382D00_523110 == 1) {
                        cmdSendCommand(camera, CAMERA_CMD_BLINK, 0);
                    }
                }
                if (func_8035E508_4FE918() > 0) {
                    if (func_8035E508_4FE918() > 10) {
                        auPlaySound(SOUND_ID_TAKE_PHOTO);
                    } else {
                        auPlaySound(SOUND_ID_TAKE_PHOTO_2);
                    }
                    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_18, obj);
                    if (D_803AE768_54EB78 != 0 && gPokemonInFocus != NULL) {
                        cmdSendCommand(gPokemonInFocus, POKEMON_CMD_24, obj);
                    }
                    D_803AEF30_54F340 = D_803AEF38_54F348;
                    if (D_803AE768_54EB78 != 0 && (D_803AE774_54EB84 & 4)) {
                        makePhoto(gPokemonInFocus);
                        sp38 = D_803AE770_54EB80;
                        if (D_803AE774_54EB84 & 8) {
                            sp38 = 500;
                        }
                    } else {
                        makePhoto(NULL);
                        sp38 = 0;
                    }

                    Camera_EndProcessByFunction(obj, func_80352F20_4F3330);
                    D_803AE408_54E818 = sp38;
                    omCreateProcess(obj, func_80352F20_4F3330, 0, 9);
                    if (D_803AE768_54EB78 != 0 && gPokemonInFocus != NULL) {
                        GET_POKEMON(gPokemonInFocus)->flags |= 0x80;
                    }
                    if (func_8035E52C_4FE93C() == 0) {
                        omCreateProcess(obj, processOutOfFilm, 0, 9);
                        omEndProcess(NULL);
                    }
                    Icons_ProcessTakePhotoPressed();
                }
                sTimerAfterPhotoTaken = sMinTimeBetweenPhotos;
            }
        } else {
            sTimerAfterPhotoTaken--;
        }
        if (!IsInputDisabled) {
            updateDashEngine();
            if (gContInputPressedButtons & U_CBUTTONS) {
                auPlaySound(SOUND_ID_4);
                if (gViewYaw > 3.1415927f) {
                    sTargetDirectionZoomedIn = 1;
                    sTargetDirectionYawZommedIn = TAU;
                } else {
                    sTargetDirectionZoomedIn = 2;
                    sTargetDirectionYawZommedIn = 0.0f;
                }
            } else if (gContInputPressedButtons & R_CBUTTONS) {
                auPlaySound(SOUND_ID_4);
                sTargetDirectionZoomedIn = 1;
                if (gViewYaw > 6.282185482025146) {
                    gViewYaw -= TAU;
                    sTargetDirectionYawZommedIn = PI_2;
                } else if (gViewYaw > 4.7023889923095705) {
                    sTargetDirectionYawZommedIn = TAU;
                } else if (gViewYaw > 3.1315927410125735) {
                    sTargetDirectionYawZommedIn = 4.712389f;
                } else if (gViewYaw > 1.5607963705062866) {
                    sTargetDirectionYawZommedIn = 3.1415927f;
                } else {
                    sTargetDirectionYawZommedIn = PI_2;
                }
            } else if (gContInputPressedButtons & L_CBUTTONS) {
                auPlaySound(SOUND_ID_4);
                sTargetDirectionZoomedIn = 2;
                if (gViewYaw < 0.001f) {
                    gViewYaw += TAU;
                    sTargetDirectionYawZommedIn = 4.712389f;
                } else if (gViewYaw < 1.5717964f) {
                    sTargetDirectionYawZommedIn = 0.0f;
                } else if (gViewYaw < 3.1425927f) {
                    sTargetDirectionYawZommedIn = PI_2;
                } else if (gViewYaw < 4.713389f) {
                    sTargetDirectionYawZommedIn = 3.1415927f;
                } else {
                    sTargetDirectionYawZommedIn = 4.712389f;
                }
            }
        }
        if (ZoomSwitchMode != 1 || !(gContInputPressedButtons & Z_TRIG)) {
            return;
        }
    }

    gDirectionIndex = -2;
    sTimerAfterPhotoTaken = -1;
    omCreateProcess(obj, processZoomingOut, 0, 9);
    omEndProcess(NULL);
}

s32 Pause_StickReleased = 0;
GObjFunc D_80382D84_523194[] = {
    processTurnToDirection,
    updateMovementState,
    handleAnalogStick,
    handleCButtons,
    handleItemButtonsPress,
    NULL,
};
s32 D_80382D9C_5231AC = 0;
s32 MainCameraBlinkTimeout = 0;
s32 D_80382DA4_5231B4 = 0;
s32 D_80382DA8_5231B8 = 0;
s32 D_80382DAC_5231BC = 0;
s32 D_80382DB0_5231C0 = 0;

void vibrateCamera(GObj* obj) {
    f32 phase = 0.0f;
    f32 blockPart;
    s32 blockCount;
    s32 levelID = getLevelId();

    if (levelID == SCENE_BEACH) {
        while (TRUE) {
            getLevelProgress(&blockCount, &blockPart);
            if (blockCount + blockPart >= 4.15f) {
                break;
            }
            ohWait(1);
        }
    }

    while (TRUE) {
        sCameraVibrationDeltaY = sinf(phase) * sCameraVibrationAmplitude;
        phase += sCameraVibrationSpeed * 3.1415927f / 180.0f;
        if (levelID == SCENE_BEACH) {
            getLevelProgress(&blockCount, &blockPart);
            if (blockCount + blockPart >= 4.45f) {
                break;
            }
        }
        ohWait(1);
    }

    sCameraVibrationDeltaY = 0.0f;
    omEndProcess(NULL);
}

void setEndLevelCallback(void (*cb)(s32)) {
    EndLevelCb = cb;
}

void setPauseCallback(void (*cb)(s32)) {
    PauseCb = cb;
}

// `int` is required to match
int func_80353D68_4F4178(void) {
    return gIsPaused == 0 && D_80382D44_523154 == 0;
}

void Pause_UpdateSelection(GObj* obj) {
    if (Pause_ButtonPressTimeout > 0) {
        Pause_StickReleased = FALSE;
    } else if (ABS(gContInputStickY) > 20 && Pause_StickReleased) {
        Pause_StickReleased = FALSE;
        if (gContInputStickY > 0) {
            if (Pause_CurrentSelection > 0) {
                Pause_CurrentSelection--;
                auPlaySound(SOUND_ID_65);
            }
        } else {
            if (Pause_CurrentSelection < 2) {
                Pause_CurrentSelection++;
                auPlaySound(SOUND_ID_65);
            }
        }

        switch (Pause_CurrentSelection) {
            case PAUSE_OPTION_CONTINUE:
                spSetAttribute(&Pause_QuitCourseSelected->sprite, SP_HIDDEN);
                spClearAttribute(&Pause_QuitCourse->sprite, SP_HIDDEN);

                spClearAttribute(&Pause_ContinueSelected->sprite, SP_HIDDEN);
                spSetAttribute(&Pause_Continue->sprite, SP_HIDDEN);

                spSetAttribute(&Pause_RetrySelected->sprite, SP_HIDDEN);
                spClearAttribute(&Pause_Retry->sprite, SP_HIDDEN);
                break;
            case PAUSE_OPTION_QUIT:
                spClearAttribute(&Pause_QuitCourseSelected->sprite, SP_HIDDEN);
                spSetAttribute(&Pause_QuitCourse->sprite, SP_HIDDEN);

                spSetAttribute(&Pause_ContinueSelected->sprite, SP_HIDDEN);
                spClearAttribute(&Pause_Continue->sprite, SP_HIDDEN);

                spSetAttribute(&Pause_RetrySelected->sprite, SP_HIDDEN);
                spClearAttribute(&Pause_Retry->sprite, SP_HIDDEN);
                break;
            case PAUSE_OPTION_RETRY:
                spSetAttribute(&Pause_QuitCourseSelected->sprite, SP_HIDDEN);
                spClearAttribute(&Pause_QuitCourse->sprite, SP_HIDDEN);

                spSetAttribute(&Pause_ContinueSelected->sprite, SP_HIDDEN);
                spClearAttribute(&Pause_Continue->sprite, SP_HIDDEN);

                spClearAttribute(&Pause_RetrySelected->sprite, SP_HIDDEN);
                spSetAttribute(&Pause_Retry->sprite, SP_HIDDEN);
                break;
        }
        Pause_StickReleased += 0; // required to match
    } else if (ABS(gContInputStickY) < 5) {
        Pause_StickReleased = TRUE;
    }
    if (!gIsPaused) {
        omEndProcess(NULL);
    }
}

void func_8035403C_4F444C(GObj* obj) {
    SObj* sobj = obj->data.sobj;
    Sprite* sprite = &sobj->sprite;

    D_80382D28_523138 = 0;
    spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 0);
    spClearAttribute(sprite, SP_HIDDEN);

    while (TRUE) {
        if (D_80382D28_523138 > 153) {
            D_80382D28_523138 = 153;
            spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 153);
            break;
        }
        spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, D_80382D28_523138);
        D_80382D28_523138 += 15;
        ohWait(1);
    }

    omEndProcess(NULL);
}

void Pause_ShowUI(GObj* obj) {
    SObj* sobj = obj->data.sobj;
    Sprite* sprite = &sobj->sprite;

    D_80382D28_523138 = 0;
    spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 0);
    spClearAttribute(sprite, SP_HIDDEN);
    spMove(&Pause_LabelPause->sprite, 360, 94);
    spClearAttribute(&Pause_LabelPause->sprite, SP_HIDDEN);
    D_80382D38_523148 = 360;

    while (TRUE) {
        if (D_80382D28_523138 > 153) {
            D_80382D28_523138 = 153;
            spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 153);
            spMove(&Pause_LabelPause2->sprite, 111, 94);
            spClearAttribute(&Pause_LabelPause2->sprite, SP_HIDDEN);
            spSetAttribute(&Pause_LabelPause->sprite, SP_HIDDEN);
            spSetAttribute(&Pause_QuitCourseSelected->sprite, SP_HIDDEN);
            spClearAttribute(&Pause_QuitCourse->sprite, SP_HIDDEN);
            spClearAttribute(&Pause_ContinueSelected->sprite, SP_HIDDEN);
            spSetAttribute(&Pause_Continue->sprite, SP_HIDDEN);
            spSetAttribute(&Pause_RetrySelected->sprite, SP_HIDDEN);
            spClearAttribute(&Pause_Retry->sprite, SP_HIDDEN);
            omCreateProcess(obj, Pause_UpdateSelection, 1, 9);
            omEndProcess(NULL);
        } else {
            spMove(&Pause_LabelPause->sprite, D_80382D38_523148, 94);
            spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, D_80382D28_523138);
            D_80382D28_523138 += 15;
            D_80382D38_523148 -= 24;
        }
        if (gIsPaused == 0) {
            omEndProcess(NULL);
        }
        ohWait(1);
    }
}

void Pause_HideUI(GObj* obj) {
    SObj* sobj = obj->data.sobj;

    spSetAttribute(&Pause_LabelPause2->sprite, SP_HIDDEN);
    spMove(&Pause_LabelPause->sprite, D_80382D38_523148, 94);
    spClearAttribute(&Pause_LabelPause->sprite, SP_HIDDEN);
    spSetAttribute(&Pause_QuitCourseSelected->sprite, SP_HIDDEN);
    spSetAttribute(&Pause_QuitCourse->sprite, SP_HIDDEN);
    spSetAttribute(&Pause_ContinueSelected->sprite, SP_HIDDEN);
    spSetAttribute(&Pause_Continue->sprite, SP_HIDDEN);
    spSetAttribute(&Pause_RetrySelected->sprite, SP_HIDDEN);
    spSetAttribute(&Pause_Retry->sprite, SP_HIDDEN);

    while (TRUE) {
        if (D_80382D38_523148 < -103) {
            spSetAttribute(&sobj->sprite, SP_HIDDEN);
            spSetAttribute(&Pause_LabelPause->sprite, SP_HIDDEN);
            omEndProcess(NULL);
        } else {
            spMove(&Pause_LabelPause->sprite, D_80382D38_523148, 94);
            sobj->sprite.alpha = D_80382D28_523138;
            D_80382D28_523138 -= 15;
            if (D_80382D28_523138 < 0) {
                sobj->sprite.alpha = 0;
            }
            D_80382D38_523148 -= 24;
        }
        ohWait(1);
    }
}

void func_8035453C_4F494C(void) {
    func_80365E34_506244();
    func_80358994_4F8DA4(1);
    stopLevelProcesses();
    freezePokemons(NULL);
    func_80350458_4F0868(10, 1);
    func_800A7470(0, 0, 0);
    func_800A7918(0, 0.5f);
    ohWait(1);
    while (func_800A7460() == 1) {
        ohWait(1);
    }
}

void quitCourse(GObj* arg0) {
    func_8035453C_4F494C();
    EndLevelCb(END_LEVEL_REASON_QUIT);
    omEndProcess(NULL);
}

void retryCourse(GObj* arg0) {
    func_8035453C_4F494C();
    EndLevelCb(END_LEVEL_REASON_RETRY);
    omEndProcess(NULL);
}

void func_8035464C_4F4A5C(GObj* arg0) {
    f32 var_f20, var_f22, var_f24;
    s32 i;
    s32 duration = 20;

    if (D_80382D3C_52314C < 1.0f) {
        var_f20 = 1.0f;
        var_f22 = 0.5f;
        var_f24 = -0.5f / duration;
    } else {
        var_f20 = 0.5f;
        var_f22 = 1.0f;
        var_f24 = 0.5f / duration;
    }
    for (i = duration; i > 0; i--) {
        var_f20 += var_f24;
        var_f22 += var_f24;
        auSetBGMVolume(BGM_PLAYER_MAIN, 32512.0f * var_f20);
        auSetBGMVolume(BGM_PLAYER_AUX, 32512.0f * var_f20);
        auSetCurrentSoundsGlobalVolume(127.0f * var_f20);
        ohWait(1);
    }
    omEndProcess(NULL);
}

void func_80354860_4F4C70(GObj* arg0) {
    ohWait(21);
    gIsPaused = 1 - gIsPaused;
    func_80357170_4F7580();
    Icons_UnFreeze();
    PauseCb(FALSE);
    func_80359064_4F9474();
    ohResumeProcessByFunction(gObjPlayer, func_80352F20_4F3330);
    if (gDirectionIndex < 0) {
        ohResumeProcessByFunction(gObjPlayer, processZoomingIn);
        ohResumeProcessByFunction(gObjPlayer, processZoomingOut);
        ohResumeProcessByFunction(gObjPlayer, updateCameraZoomedIn);
        ohResumeProcessByFunction(gObjPlayer, updateMovementState);
        ohResumeProcessByFunction(gObjPlayer, handleAnalogStick);
    } else {
        ohResumeProcessByFunction(gObjPlayer, updateMovementState);
        ohResumeProcessByFunction(gObjPlayer, handleAnalogStick);
        ohResumeProcessByFunction(gObjPlayer, handleCButtons);
        ohResumeProcessByFunction(gObjPlayer, handleItemButtonsPress);
    }
    ohResumeProcessByFunction(gObjPlayer, vibrateCamera);
    omEndProcess(NULL);
}

void updatePauseMenu(GObj* arg0) {
    if (IsInputDisabled != TRUE) {
        if (Pause_ButtonPressTimeout > 0) {
            Pause_ButtonPressTimeout--;
            return;
        }
        if (gIsPaused) {
            if (gContInputPressedButtons & B_BUTTON) {
                omCreateProcess(arg0, Pause_HideUI, 0, 9);
                Pause_ButtonPressTimeout = 30;
                D_80382D3C_52314C = 1.0f;
                omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
                omCreateProcess(arg0, func_80354860_4F4C70, 0, 9);
                gContInputPressedButtons = 0;
            } else if ((gContInputPressedButtons & A_BUTTON) || (gContInputPressedButtons & CONT_START)) {
                if (Pause_CurrentSelection == PAUSE_OPTION_CONTINUE) {
                    omCreateProcess(arg0, Pause_HideUI, 0, 9);
                    Pause_ButtonPressTimeout = 30;
                    D_80382D3C_52314C = 1.0f;
                    omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
                    omCreateProcess(arg0, func_80354860_4F4C70, 0, 9);
                } else if (Pause_CurrentSelection == PAUSE_OPTION_QUIT) {
                    auPlaySound(SOUND_ID_66);
                    omCreateProcess(arg0, quitCourse, 0, 9);
                    gIsPaused = FALSE;
                    D_80382D44_523154 = 1;
                    omEndProcess(NULL);
                } else {
                    // retry
                    auPlaySound(SOUND_ID_66);
                    omCreateProcess(arg0, retryCourse, 0, 9);
                    gIsPaused = FALSE;
                    D_80382D44_523154 = 1;
                    omEndProcess(NULL);
                }
                gContInputPressedButtons = 0;
            }
        } else if (gContInputPressedButtons & CONT_START) {
            gIsPaused = 1 - gIsPaused;
            Pause_CurrentSelection = 0;
            func_80357120_4F7530(arg0);
            Icons_Freeze();
            PauseCb(TRUE);
            func_80359074_4F9484();
            ohPauseProcessByFunction(gObjPlayer, func_80352F20_4F3330);
            func_80365E34_506244();
            if (gDirectionIndex < 0) {
                ohPauseProcessByFunction(gObjPlayer, processZoomingIn);
                ohPauseProcessByFunction(gObjPlayer, processZoomingOut);
                ohPauseProcessByFunction(gObjPlayer, updateCameraZoomedIn);
                ohPauseProcessByFunction(gObjPlayer, updateMovementState);
                ohPauseProcessByFunction(gObjPlayer, handleAnalogStick);
            } else {
                ohPauseProcessByFunction(gObjPlayer, updateMovementState);
                ohPauseProcessByFunction(gObjPlayer, handleAnalogStick);
                ohPauseProcessByFunction(gObjPlayer, handleCButtons);
                ohPauseProcessByFunction(gObjPlayer, handleItemButtonsPress);
            }
            ohPauseProcessByFunction(gObjPlayer, vibrateCamera);
            omCreateProcess(arg0, Pause_ShowUI, 0, 9);
            auPlaySound(SOUND_ID_11);
            Pause_ButtonPressTimeout = 30;
            D_80382D3C_52314C = 0.5f;
            omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
        }
    }
}

void func_80354D38_4F5148(s32* arg0) {
    GObjProcess* proc;
    s32 i;

    for (proc = gObjPlayer->processListHead; proc != NULL; proc = proc->next) {
        if (!proc->paused) {
            for (i = 0; D_80382D84_523194[i] != NULL; i++) {
                if (proc->function == D_80382D84_523194[i]) {
                    ohPauseProcessByFunction(gObjPlayer, D_80382D84_523194[i]);
                    *arg0 |= 1 << i;
                    break;
                }
            }
        }
    }
}

void func_80354E04_4F5214(s32 arg0) {
    s32 i = 0;

    while (arg0) {
        if (arg0 & 1) {
            ohResumeProcessByFunction(gObjPlayer, D_80382D84_523194[i]);
        }
        arg0 >>= 1;
        i++;
    }
}

void func_80354E7C_4F528C(s32* arg0, GObjFunc arg1) {
    s32 i;

    for (i = 0; D_80382D84_523194[i] != NULL; i++) {
        if (arg1 == D_80382D84_523194[i]) {
            *arg0 &= ~(1 << i);
            break;
        }
    }
}

void Tutorial_ShowMessage(s32 msgID) {
    char* message = NULL;

    if (D_803AE516_54E926 == TRUE) {
        return;
    }
    if (msgID != 0) {
        switch (msgID) {
            case MESSAGE_PRESS_Z:
                message = "Press \\z to aim.";
                break;
            case MESSAGE_PRESS_A:
                message = "Press \\a to shoot.";
                break;
            case MESSAGE_TAKE_PICTURES:
                message = "Try to take a lot of Pokεmon pictures!";
                break;
            case MESSAGE_USE_CONTROL_STICK:
                message = "Please use the Control Stick.";
                break;
        }

        if (message != NULL) {
            showMessage(message, 160, 150, 255, 255, 255, 255, 0, 2);
        }
    } else {
        func_80365E34_506244();
    }
}

s32 func_80354FB8_4F53C8(s32 duration) {
    s32 s1 = FALSE;

    while (duration > 0) {
        if (ABS(gContInputStickX) >= 6 || ABS(gContInputStickY) >= 6) {
            s1 = TRUE;
        }
        if (!gIsPaused) {
            duration--;
        }
        ohWait(1);
    }
    return s1;
}

void Tutorial_PauseAll(GObj* arg0, s32* arg1) {
    *arg1 = 0;
    func_80357120_4F7530(arg0);
    func_80354D38_4F5148(arg1);
    ohPauseProcessByFunction(gObjPlayer, processZoomingIn);
    ohPauseProcessByFunction(gObjPlayer, processZoomingOut);
    ohPauseProcessByFunction(gObjPlayer, updateCameraZoomedIn);
    ohPauseProcessByFunction(gObjPauseMenu, updatePauseMenu);
    ohPauseProcessByFunction(D_80382C38_523048, updateReticleScreenPos);
}

void Tutorial_UnPauseAll(GObj* arg0, s32* arg1) {
    func_80357170_4F7580();
    func_80354E04_4F5214(*arg1);
    ohResumeProcessByFunction(gObjPlayer, processZoomingIn);
    ohResumeProcessByFunction(gObjPlayer, processZoomingOut);
    ohResumeProcessByFunction(gObjPlayer, updateCameraZoomedIn);
    ohResumeProcessByFunction(gObjPauseMenu, updatePauseMenu);
    ohResumeProcessByFunction(D_80382C38_523048, updateReticleScreenPos);
}

void Tutorial_ShowMessageAndWait(s32 msgID) {
    s32 i;

    for (i = 240; i > 0; i--) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            break;
        }
        if (!(i & 0x70)) {
            Tutorial_ShowMessage(MESSAGE_NONE);
        } else {
            Tutorial_ShowMessage(msgID);
        }
        ohWait(1);
    }
}

void func_80355228_4F5638(GObj* arg0) {
    s32 sp1C;

    func_80354FB8_4F53C8(90);
    Tutorial_PauseAll(arg0, &sp1C);
    Tutorial_ShowMessageAndWait(MESSAGE_TAKE_PICTURES);
    Tutorial_ShowMessage(MESSAGE_NONE);
    Tutorial_UnPauseAll(arg0, &sp1C);
    if (!func_80354FB8_4F53C8(600)) {
        Tutorial_PauseAll(arg0, &sp1C);
        Tutorial_ShowMessageAndWait(MESSAGE_USE_CONTROL_STICK);
        Tutorial_ShowMessage(MESSAGE_NONE);
        Tutorial_UnPauseAll(arg0, &sp1C);
    }
    omEndProcess(NULL);
}

void func_803552B0_4F56C0(GObj* obj) {
    s32 i;
    s32 sp30;

    sp30 = 0;
    func_80357120_4F7530(obj);
    func_80354D38_4F5148(&sp30);

    for (i = 120;; i--) {
        if (D_803AE768_54EB78 == 0) {
            break;
        }

        if (ZoomSwitchMode == 0) {
            if (gDirectionIndex < 0) {
                if (!(gContInputCurrentButtons & Z_TRIG)) {
                    break;
                }
            } else {
                if (gContInputPressedButtons & Z_TRIG) {
                    break;
                }
            }
        } else {
            if (gContInputPressedButtons & Z_TRIG) {
                break;
            }
        }

        if (D_803AE770_54EB80 <= 0 || D_803AE770_54EB80 > 151 || (GET_POKEMON(gPokemonInFocus)->flags & 0x80)) {
            break;
        }

        if (!(i & 0x70)) {
            Tutorial_ShowMessage(MESSAGE_NONE);
        } else if (gDirectionIndex < 0) {
            Tutorial_ShowMessage(MESSAGE_PRESS_A);
        } else {
            Tutorial_ShowMessage(MESSAGE_PRESS_Z);
        }

        ohWait(1);
    }

    func_80365E34_506244();
    D_80382D08_523118 = 0;
    if (D_80382D04_523114 == 1) {
        if (ZoomSwitchMode == 0 && (gContInputPressedButtons & Z_TRIG) ||
            ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG) && gDirectionIndex >= 0)
        {
            D_80382C3C_52304C = 0;
            auPlaySound(SOUND_ID_5);
            gDirectionIndex = -2;
            omCreateProcess(gObjPlayer, processZoomingIn, 0, 9);
            func_80354E7C_4F528C(&sp30, handleCButtons);
            func_80354E7C_4F528C(&sp30, handleItemButtonsPress);
            ohPauseProcessByFunction(gObjPlayer, updateCameraZoomedOut);
        }
    }
    ohWait(1);
    func_80354E04_4F5214(sp30);
    if (D_80382D08_523118 == 0) {
        func_80357170_4F7580();
    }
    omEndProcess(NULL);
}

void updateTutorialMain(GObj* arg0) {
    if (func_8009BBF4() >= 3) {
        IsInputDisabled = FALSE;
        omCreateProcess(arg0, func_80355228_4F5638, 0, 9);
        omEndProcess(NULL);
    } else if (D_803AE768_54EB78 == 1 &&
               D_80382D08_523118 == 0 &&
               D_803AE770_54EB80 > 0 &&
               D_803AE770_54EB80 <= 151 &&
               !(GET_POKEMON(gPokemonInFocus)->flags & 0x80))
    {
        D_80382D08_523118 = 1;
        omCreateProcess(arg0, func_803552B0_4F56C0, 0, 9);
    }
}

void func_803555B0_4F59C0(u8 arg0, u8 arg1, u8 arg2) {
    D_80382D2C_52313C = arg0;
    D_80382D30_523140 = arg1;
    D_80382D34_523144 = arg2;
    omCreateProcess(gObjPauseMenu, func_8035403C_4F444C, 0, 9);
}

void freezePokemons(GObj* obj) {
    GObj* pokemonObj;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        if (pokemonObj != obj) {
            ohPauseObjectProcesses(pokemonObj);
        }
    }
}

void Camera_StartStopCutscene(GObj* pokemon, s32 arg1, AnimCmd* animation, f32 time) {
    Icons_Hide();
    func_8035E4D0_4FE8E0();
    if (D_80382C38_523048 != NULL) {
        omDeleteGObj(D_80382C38_523048);
        D_80382C38_523048 = NULL;
    }
    func_80365E34_506244();
    func_80358994_4F8DA4(arg1);
    scRemovePostProcessFunc();
    stopLevelProcesses();
    ohPauseProcessByFunction(gObjPlayer, func_80352F20_4F3330);
    freezePokemons(pokemon);
    func_800E1A78_5F228(0);
    if (animation != NULL) {
        animSetCameraAnimation(gMainCamera, animation, time);
        animUpdateCameraAnimation(gMainCamera->obj);
    } else {
        Vec3f sp34;
        Vec3f sp28;

        sp34.x = 0;
        sp34.y = 0;
        sp34.z = 1.0f;
        sp28.x = 0;
        sp28.y = 0.5f;
        sp28.z = 0;
        Vec3fGetEulerRotation(&sp34, AXIS_Y, gMovementState.rotation.y);
        Vec3fAdd(&sp34, &sp28);
        Vec3fNormalize(&sp28);
        Vec3f_func_8001A8B8(&sp34, &sp28, -30.0f);
        gMainCamera->viewMtx.lookAt.at.x = gMovementState.pos.x;
        gMainCamera->viewMtx.lookAt.at.y = gMovementState.pos.y;
        gMainCamera->viewMtx.lookAt.at.z = gMovementState.pos.z;
        gMainCamera->viewMtx.lookAt.eye.x = gMovementState.pos.x + sp34.x * 80.0f;
        gMainCamera->viewMtx.lookAt.eye.y = gMovementState.pos.y + sp34.y * 80.0f;
        gMainCamera->viewMtx.lookAt.eye.z = gMovementState.pos.z + sp34.z * 80.0f;
    }
    gMainCamera->perspMtx.persp.aspect = 4.0f / 3.0f;
    func_80007C20(&gMainCamera->vp, 0.0f, 0.0f, 320.0f, 240.0f);
}

#ifdef NON_MATCHING
// stack diff
void processOutOfFilm(GObj* arg0) {
    s32 var_s2;
    SObj* sobj1;
    s32 i;
    SObj* sobj2;

    var_s2 = 0;
    D_80382D44_523154 = 1;
    D_803AE516_54E926 = TRUE;
    stopLevelProcesses();
    ohPauseProcessByFunction(gObjPlayer, func_80355228_4F5638);
    func_80357120_4F7530(NULL);
    func_803555B0_4F59C0(0, 0, 255);
    scRemovePostProcessFunc();
    playDashEngineSounds(0);
    Icons_SetDashEngineEnabled(0);
    sobj1 = omGObjAddSprite(gObjPauseMenu, &D_80388E00_529210);
    spMove(&sobj1->sprite, 125, 97);
    spColor(&sobj1->sprite, 255, 255, 255, 0);
    sobj2 = omGObjAddSprite(gObjPauseMenu, &D_80381B58_521F68);
    spMove(&sobj2->sprite, 149, 103);
    spColor(&sobj2->sprite, 255, 255, 255, 0);

    for (i = 59; i != 0; i--) {
        var_s2 += 10;
        if (var_s2 > 255) {
            var_s2 = 255;
        }
        spColor(&sobj1->sprite, 255, 255, 255, var_s2);
        spColor(&sobj2->sprite, 255, 255, 255, var_s2);
        ohWait(1);
    }
    showMessage("You're out of film!", 160, 130, 255, 255, 255, 255, 5, 2);
    auStopBGM();
    auStopAllSounds();
    for (i = 0; i < 16; i++) {
        auSetBGMChannelVolume(0, i, 127);
    }
    auPlaySong(0, 17);
    while (func_80365E70_506280() == 0) {
        ohWait(1);
    }
    for (i = 180; i != 0; i--) {
        if (gContInputPressedButtons & A_BUTTON) {
            break;
        }
        ohWait(1);
    }
    func_80350458_4F0868(10, 1);
    func_800A7F40(0.0f, 0.0f, 0, 2.0f);
    ohWait(1);
    while (func_800A7460() == 1) {
        ohWait(1);
    }
    EndLevelCb(END_LEVEL_REASON_OUT_OF_FILM);
    omEndProcess(NULL);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F0610/processOutOfFilm.s")
void processOutOfFilm(GObj* arg0);
#endif

void func_80355B24_4F5F34(GObj* arg0) {
    s32 i;

    auPlaySound(SOUND_ID_20);
    D_80382C64_523074 = TRUE;
    for (i = 0; i < 180; i++) {
        if (D_80382DC0_5231D0 == -1) {
            i = 0;
        }
        ohWait(1);
    }
    D_80382C64_523074 = FALSE;
    cmdSendCommand(gObjPlayer, PLAYER_CMD_5, arg0);
    omEndProcess(NULL);
}

void finishLevel(GObj* arg0) {
    f32 volume = 1.0f;
    f32 duration = 120.0f;

    func_80350458_4F0868(10, 1);
    func_800A7470(255, 255, 255);
    func_800A7918(0, 2.0f);
    auSetBGMVolumeSmooth(BGM_PLAYER_MAIN, 0, 120);
    auSetBGMVolumeSmooth(BGM_PLAYER_AUX, 0, 120);
    ohWait(1);
    while (func_800A7460() == 1) {
        volume += -(1.0f / duration);
        auSetSoundGlobalVolume(127.0f * volume);
        ohWait(1);
    }
    auSetSoundGlobalVolume(0);
    EndLevelCb(END_LEVEL_REASON_FINISH);
    omEndProcess(NULL);
}

void func_80355D54_4F6164(GObj* obj) {
    EndLevelCb(END_LEVEL_REASON_3);
    omEndProcess(NULL);
}

void handlePlayerCmd(GObjCmdData cmdData) {
    switch (cmdData.cmd) {
        case PLAYER_CMD_SHAKE_CAMERA:
            omCreateProcess(omCurrentObject, shakeCamera, 0, 9);
            break;
        case PLAYER_CMD_4:
            if (D_80382D9C_5231AC == 0) {
                omCreateProcess(omCurrentObject, func_80355B24_4F5F34, 0, 9);
                D_80382D9C_5231AC = 1;
            }
            break;
        case PLAYER_CMD_5:
            D_80382D9C_5231AC = 0;
            break;
        case PLAYER_CMD_FINISH:
            if (D_80382D9C_5231AC == 0) {
                omCreateProcess(omCurrentObject, finishLevel, 0, 9);
                D_80382D9C_5231AC = 1;
            }
            break;
        case PLAYER_CMD_7:
            if (D_80382D9C_5231AC == 0) {
                omCreateProcess(omCurrentObject, func_80355D54_4F6164, 1, 9);
                D_80382D9C_5231AC = 1;
            }
            break;
        case PLAYER_CMD_8:
            Camera_StartStopCutscene(cmdData.source, 1, NULL, 0.0f);
            break;
        case PLAYER_CMD_9:
            sForceDashEngineDisabled = 1;
            playDashEngineSounds(0);
            break;
        case PLAYER_CMD_10:
            sForceDashEngineDisabled = 1;
            playDashEngineSounds(0);
            break;
    }
}

void updatePlayer(GObj* arg0) {
    cmdProcessCommands(handlePlayerCmd);
}

void updateReticleScreenPos(GObj* arg0) {
    if (!gIsPaused && IsInputDisabled != TRUE) {
        if (ABS(sStickXValue) > 0.0005f) {
            if (gDirectionIndex > 0) {
                sReticleScreenX += (s32) (5.0f * sStickXValue);
            } else {
                sReticleScreenX -= (s32) (5.0f * sStickXValue);
            }
            if (sReticleScreenX > 60) {
                sReticleScreenX = 60;
            } else if (sReticleScreenX < -60) {
                sReticleScreenX = -60;
            }
        } else if (sReticleScreenX > 50) {
            sReticleScreenX -= 3;
        } else if (sReticleScreenX < -50) {
            sReticleScreenX += 3;
        }
        sReticleScreenY = sStickYAccum * 100.0;
    }
}

void func_80356074_4F6484(GObj* arg0) {
    s32 i = 0;

    while (TRUE) {
        spSetAttribute(&sMainCameraReticles[i + 1]->sprite, SP_HIDDEN);
        spClearAttribute(&sMainCameraReticles[1 - (i - 1)]->sprite, SP_HIDDEN);
        i++;
        if (i >= 2) {
            omEndProcess(NULL);
        }
        ohWait(2);
    }
}

void func_80356118_4F6528(GObjCmdData cmdData) {

}

void updateReticleSpritesPos(GObj* arg0) {
    SObj* sobj = arg0->data.sobj;

    if (gDirectionIndex >= 0) {
        gCamTargetX = (f32)sReticleScreenX / 160.0f;
        gCamTargetY = -(f32)sReticleScreenY / 120.0f;
        gCamTargetZ = 0.99f;
        screenCoorsToWorld(&gCamTargetX, &gCamTargetY, &gCamTargetZ);
        spMove(&sobj->sprite, sReticleScreenX + 152, sReticleScreenY + 112);
        spClearAttribute(&sMainCameraReticles[0]->sprite, SP_HIDDEN);
        spSetAttribute(&sMainCameraReticles[1]->sprite, SP_HIDDEN);
        spSetAttribute(&sMainCameraReticles[2]->sprite, SP_HIDDEN);
        spSetAttribute(&sMainCameraReticles[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[4]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[5]->sprite, SP_HIDDEN);
    } else if (gDirectionIndex == -1) {
        spMove(&sobj->sprite, 152, 112);
        spSetAttribute(&sMainCameraReticles[0]->sprite, SP_HIDDEN);
        spClearAttribute(&sMainCameraReticles[1]->sprite, SP_HIDDEN);
    } else {
        // hide everything
        spSetAttribute(&sMainCameraReticles[0]->sprite, SP_HIDDEN);
        spSetAttribute(&sMainCameraReticles[1]->sprite, SP_HIDDEN);
        spSetAttribute(&sMainCameraReticles[2]->sprite, SP_HIDDEN);
        spSetAttribute(&sMainCameraReticles[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[4]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[5]->sprite, SP_HIDDEN);
    }
    cmdProcessCommands(func_80356118_4F6528);
}

GObj* initUI(void (*exitBlockCB)(WorldBlock*), void (*updateMovementCB)(s32), GObjFunc fnUpdateItems, u8 fnUpdateItemsKind, void (*fnCollide)(GObj*, GroundResult*)) {
    GObj* objPlayer;
    GObj* obj;
    DObj* playerDObj;
    SObj* sp40;

    obj = omAddGObj(OBJID_PLAYER, updatePlayer, LINK_PLAYER, 0x80000000);
    omGObjAddDObj(obj, NULL);
    playerDObj = obj->data.dobj;

    sPlayerMatrixStore.kinds[0] = 1;
    sPlayerMatrixStore.kinds[1] = 2;
    sPlayerMatrixStore.kinds[2] = 3;
    playerDObj->unk_4C = &sPlayerMatrixStore;
    omDObjAddMtx(playerDObj, MTX_TYPE_62, 0, 0);

    gIdleScript = getIdleScript();
    gProgressFlags = 0;
    if (checkPlayerFlag(PFID_ZOOM_SWITCH) == 1) {
        gProgressFlags |= PF_ZOOM_SWITCH;
    }
    if (checkPlayerFlag(PFID_INVERTED_Y) == 1) {
        gProgressFlags |= PF_INVERTED_Y;
    }
    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE) == 1) {
        gProgressFlags |= PF_HAS_DASH_ENGINE;
    }
    if (checkPlayerFlag(PFID_HAS_APPLE) == 1) {
        gProgressFlags |= PF_HAS_APPLE;
    }
    if (checkPlayerFlag(PFID_HAS_PESTER_BALL) == 1) {
        gProgressFlags |= PF_HAS_PESTER_BALL;
    }
    if (checkPlayerFlag(PFID_HAS_FLUTE) == 1) {
        gProgressFlags |= PF_HAS_FLUTE;
    }
    if (func_800BF864_5C704() >= 4) {
        gProgressFlags |= PF_TUTORIAL_PASSED;
    }
    if (gIdleScript != NULL) {
        initIdle(obj);
    }
    if (gProgressFlags & PF_ZOOM_SWITCH) {
        ZoomSwitchMode = 1;
    } else {
        ZoomSwitchMode = 0;
    }
    if (gProgressFlags & PF_INVERTED_Y) {
        IsAxisYInverted = TRUE;
    } else {
        IsAxisYInverted = FALSE;
    }
    if (gProgressFlags & PF_HAS_DASH_ENGINE) {
        IsDashEngineAvailable = 1;
    } else {
        IsDashEngineAvailable = 0;
    }
    if (gProgressFlags & PF_TUTORIAL_PASSED) {
        IsTutorialEnabled = 0;
    } else {
        IsTutorialEnabled = 1;
    }
    sForceDashEngineDisabled = FALSE;
    D_803AE516_54E926 = FALSE;
    omCreateProcess(obj, updateMovementState, 1, 11);
    omCreateProcess(obj, handleAnalogStick, 1, 9);
    omCreateProcess(obj, handleItemButtonsPress, 1, 9);
    omCreateProcess(obj, handleCButtons, 1, 9);
    omCreateProcess(obj, processTurnToDirection, 1, 9);
    ohPauseProcessByFunction(obj, processTurnToDirection);
    omCreateProcess(obj, updateCameraZoomedOut, 1, 9);
    omCreateProcess(obj, updateMusic, 0, 9);
    gMovementState.moveTime = 0.0f;
    gMovementState.cpTime = 0.5f;
    gMovementState.speedMult = 0.0005f;
    Movement_Init(&gMovementState, 0, exitBlockCB, updateMovementCB);
    updateCameraZoomedOut(obj);
    GET_TRANSFORM(playerDObj)->pos.v.x = gMovementState.pos.x;
    GET_TRANSFORM(playerDObj)->pos.v.y = gMovementState.pos.y;
    GET_TRANSFORM(playerDObj)->pos.v.z = gMovementState.pos.z;
    GET_TRANSFORM(playerDObj)->rot.f[1] = gMovementState.rotation.x;
    GET_TRANSFORM(playerDObj)->rot.f[2] = gMovementState.rotation.x; // BUG
    GET_TRANSFORM(playerDObj)->rot.f[3] = gMovementState.rotation.z;
    objPlayer = gObjPlayer = obj;
    gPlayerDObj = playerDObj;
    gTotalSpeedMult = 0.0005f;
    gPlayerPos = GET_TRANSFORM(playerDObj)->pos.v;

    obj = ohCreateSprite(OBJID_UI_RETICLE, updateReticleSpritesPos, 0, 0x80000000, renDrawSprite, DL_LINK_1, 0x80000000, -1, &D_80366DF0_507200, 1, updateReticleScreenPos, 9);
    D_80382C38_523048 = obj;
    sMainCameraReticles[0] = obj->data.sobj;

    sMainCameraReticles[1] = sp40 = omGObjAddSprite(obj, &D_80367580_507990);
    spMove(&sp40->sprite, 143, 103);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);

    sMainCameraReticles[2] = sp40 = omGObjAddSprite(obj, &D_80367D10_508120);
    spMove(&sp40->sprite, 143, 103);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);

    sMainCameraReticles[3] = sp40 = omGObjAddSprite(obj, &D_80367DC0_5081D0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 157, 117);

    D_803AE458_54E868[0] = sp40 = omGObjAddSprite(obj, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 78, 58);
    spScale(&sp40->sprite, 82.0f, 1.0f);

    D_803AE458_54E868[1] = sp40 = omGObjAddSprite(obj, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 78, 180);
    spScale(&sp40->sprite, 82.0f, 1.0f);

    D_803AE458_54E868[2] = sp40 = omGObjAddSprite(obj, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 78, 60);
    spScale(&sp40->sprite, 1.0f, 60.0f);

    D_803AE458_54E868[3] = sp40 = omGObjAddSprite(obj, &D_80368038_508448);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);
    spMove(&sp40->sprite, 240, 60);
    spScale(&sp40->sprite, 1.0f, 60.0f);

    D_803AE458_54E868[4] = sp40 = omGObjAddSprite(obj, &D_803706E0_510AF0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 0, 0);

    D_803AE458_54E868[5] = sp40 = omGObjAddSprite(obj, &D_80378D88_519198);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 0, 187);

    Items_Init();
    Items_SetCustomFunctions(fnUpdateItems, fnUpdateItemsKind, fnCollide);
    Icons_Init();
    func_8035E37C_4FE78C();
    func_803588D4_4F8CE4();

    gMainCamera->perspMtx.persp.fovy = 55.0f;
    D_803AE478_54E888 = 1.0f;
    D_803AE47C_54E88C = 0.0f;

    obj = omAddGObj(OBJID_UI_PAUSE, ohUpdateDefault, LINK_0, 0x80000000);
    omLinkGObjDL(obj, renDrawSprite, DL_LINK_1, 0x80000000, -1);
    gObjPauseMenu = obj;

    D_80382C70_523080 = sp40 = omGObjAddSprite(obj, &D_80378ED8_5192E8);
    spMove(&sp40->sprite, 0, 0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    sp40->sprite.scalex = 32.0f;
    sp40->sprite.scaley = 24.0f;

    Pause_LabelPause2 = sp40 = omGObjAddSprite(obj, &D_8037A9A0_51ADB0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);

    Pause_LabelPause = sp40 = omGObjAddSprite(obj, &D_8037C468_51C878);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);

    Pause_QuitCourseSelected = sp40 = omGObjAddSprite(obj, &D_8037D2A0_51D6B0);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 156);

    Pause_QuitCourse = sp40 = omGObjAddSprite(obj, &D_8037E0D8_51E4E8);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 156);

    Pause_ContinueSelected = sp40 = omGObjAddSprite(obj, &D_8037EF10_51F320);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 133);

    Pause_Continue = sp40 = omGObjAddSprite(obj, &D_8037FD48_520158);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 133);

    Pause_RetrySelected = sp40 = omGObjAddSprite(obj, &D_80380B80_520F90);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 179);

    Pause_Retry = sp40 = omGObjAddSprite(obj, &D_803819B8_521DC8);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spMove(&sp40->sprite, 116, 179);

    if (gIdleScript == NULL) {
        omCreateProcess(obj, updatePauseMenu, 1, 9);
    }
    omCreateProcess(obj, func_80353118_4F3528, 1, 9);
    switch (getLevelId()) {
        case SCENE_BEACH:
            if (IsTutorialEnabled == TRUE) {
                omCreateProcess(objPlayer, updateTutorialMain, 1, 9);
                IsInputDisabled = TRUE;
            } else {
                setPlayerFlag(PFID_TUTORIAL_PASSED, 1);
            }
            sCameraVibrationAmplitude = 2.0f;
            sCameraVibrationSpeed = 25.0f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_CAVE:
            sCameraVibrationAmplitude = 40.0f;
            sCameraVibrationSpeed = 1.5f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_RAINBOW:
            sCameraVibrationAmplitude = 35.0f;
            sCameraVibrationSpeed = 1.5f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_VALLEY:
            sCameraVibrationAmplitude = 10.0f;
            sCameraVibrationSpeed = 2.0f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_RIVER:
            sCameraVibrationAmplitude = 15.0f;
            sCameraVibrationSpeed = 1.5f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
    }
    func_80365B24_505F34();
    return objPlayer;
}

void func_80356FBC_4F73CC(void) {
    omDeleteGObj(gObjPlayer);
}

void func_80356FE0_4F73F0(void) {
    omCreateProcess(gObjPlayer, func_80351114_4F1524, 1, 9);
}

void getMovementTimes(f32* arg0, f32* arg1) {
    *arg0 = gMovementState.moveTime;
    *arg1 = gMovementState.cpTime;
}

GObj* getPlayerObject(void) {
    return gObjPlayer;
}

DObj* getPlayerModel(void) {
    return gPlayerDObj;
}

u32 getProgressFlags(void) {
    return gProgressFlags;
}

void setPitchLimits(f32 minValue, f32 maxValue) {
    sMinPitch = minValue;
    sMaxPitch = maxValue;
}

void func_80357068_4F7478(void) {
    if (D_80382D10_523120 != NULL) {
        D_80382D10_523120->flags |= 0xFFFF0000;
    }
    if (D_80382D14_523124 != NULL) {
        D_80382D14_523124->flags |= 0xFFFF0000;
    }
}

void func_803570B0_4F74C0(void) {
    if (D_80382D10_523120 != NULL) {
        D_80382D10_523120->flags &= ~0xFFFF0000;
    }
    if (D_80382D14_523124 != NULL) {
        D_80382D14_523124->flags &= ~0xFFFF0000;
    }
}

void Camera_StartCutScene(GObj* pokemon, AnimCmd* camAnim, f32 time) {
    Camera_StartStopCutscene(pokemon, 1, camAnim, time);
}

void func_80357120_4F7530(GObj* arg0) {
    freezePokemons(arg0);
    Items_Pause();
    func_80357068_4F7478();
}

void func_80357150_4F7560(GObj* arg0) {
    ohResumeObjectProcesses(arg0);
}

void func_80357170_4F7580(void) {
    GObj* pokemonObj;

    for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
        ohResumeObjectProcesses(pokemonObj);
    }
    Items_UnPause();
    func_803570B0_4F74C0();
}

void func_803571C4_4F75D4(void) {
    Icons_Hide();
    func_8035E764_4FEB74();
    D_80382C38_523048->flags |= GOBJ_FLAG_HIDDEN;
    ohPauseProcessByFunction(gObjPlayer, updateMovementState);
    ohPauseProcessByFunction(gObjPlayer, handleAnalogStick);
    ohPauseProcessByFunction(gObjPlayer, handleCButtons);
    ohPauseProcessByFunction(gObjPlayer, handleItemButtonsPress);
    ohPauseProcessByFunction(gObjPlayer, updateCameraZoomedOut);
    ohPauseProcessByFunction(gObjPauseMenu, updatePauseMenu);
}

void func_80357278_4F7688(GObj* arg0) {
    ohWait(2);
    D_80382D04_523114 = 1;
    omEndProcess(NULL);
}

void func_803572B0_4F76C0(void) {
    Icons_Show();
    func_8035E754_4FEB64();
    D_80382C38_523048->flags &= ~GOBJ_FLAG_HIDDEN;
    ohResumeProcessByFunction(gObjPlayer, updateMovementState);
    ohResumeProcessByFunction(gObjPlayer, handleAnalogStick);
    ohResumeProcessByFunction(gObjPlayer, handleCButtons);
    ohResumeProcessByFunction(gObjPlayer, handleItemButtonsPress);
    ohResumeProcessByFunction(gObjPlayer, updateCameraZoomedOut);
    ohResumeProcessByFunction(gObjPauseMenu, updatePauseMenu);
    omCreateProcess(gObjPlayer, func_80357278_4F7688, 0, 9);
}

MovementState* func_80357378_4F7788(void) {
    return &gMovementState;
}

void getLevelProgress(s32* blockCount, f32* blockPart) {
    *blockCount = gMovementState.block->index;
    *blockPart = gMovementState.moveTime;
}

u8 getIsPaused(void) {
    return gIsPaused;
}

DObj* func_803573B0_4F77C0(void) {
    return gPlayerDObj;
}

void resetMainCameraSettings(void) {
    func_80007C20(&gMainCamera->vp, 0.0f, 0.0f, 320.0f, 240.0f);
    gMainCamera->perspMtx.persp.fovy = 55.0f;
    setMainCameraViewport(0, 0, 320, 240);
}

void func_80357428_4F7838(GObj* arg0) {
    if (D_80382C3C_52304C != 0 && arg0 == D_80382C40_523050) {
        D_80382C40_523050 = 0;
        D_80382C3C_52304C = 0;
    }
}

f32 isInScreenCenter(OMCamera* cam, f32 x, f32 y, f32 z) {
    Mtx4f viewMatrix;
    Mtx4f projMatrix;
    u16 sp5E;
    f32 outX, outY, outZ, outS;

    if (cam == NULL) {
        return -1.0f;
    }
    hal_look_at_f(viewMatrix,
                  cam->viewMtx.lookAt.eye.x, cam->viewMtx.lookAt.eye.y, cam->viewMtx.lookAt.eye.z,
                  cam->viewMtx.lookAt.at.x, cam->viewMtx.lookAt.at.y, cam->viewMtx.lookAt.at.z,
                  0.0f, 1.0f, 0.0f);
    hal_perspective_fast_f(projMatrix, &sp5E,
                           cam->perspMtx.persp.fovy,
                           cam->perspMtx.persp.aspect,
                           cam->perspMtx.persp.near,
                           cam->perspMtx.persp.far,
                           cam->perspMtx.persp.scale);
    guMtxCatF(viewMatrix, projMatrix, projMatrix);

    outX = projMatrix[0][0] * x + projMatrix[1][0] * y + projMatrix[2][0] * z + projMatrix[3][0];
    outY = projMatrix[0][1] * x + projMatrix[1][1] * y + projMatrix[2][1] * z + projMatrix[3][1];
    outZ = projMatrix[0][2] * x + projMatrix[1][2] * y + projMatrix[2][2] * z + projMatrix[3][2];
    outS = projMatrix[0][3] * x + projMatrix[1][3] * y + projMatrix[2][3] * z + projMatrix[3][3];
    outS = 1.0f / outS;
    outX *= outS;
    outY *= outS;
    outZ *= outS;

    if (ABS(outX) < 0.2f && ABS(outY) < 0.2f && outS > 0.0f && outZ > 0.0f) {
        return outZ;
    }
    return -1.0f;
}

f32 matrixDeterminant(Mtx3f m) {
    f32 det = m[0][0] * m[1][1] * m[2][2]
            + m[1][0] * m[2][1] * m[0][2]
            + m[2][0] * m[0][1] * m[1][2]
            - m[0][2] * m[1][1] * m[2][0]
            - m[1][2] * m[2][1] * m[0][0]
            - m[2][2] * m[0][1] * m[1][0];

    return det;
}


f32 worldCoorsToScreen(f32 x, f32 y, f32 z, f32* outX, f32* outY, f32* outZ) {
    Mtx4f viewMatrix;
    Mtx4f projMatrix;
    u16 perspNorm;
    f32 w;

    if (gMainCamera == NULL) {
        return -1.0f;
    }

    hal_look_at_f(viewMatrix,
                  gMainCamera->viewMtx.lookAt.eye.x, gMainCamera->viewMtx.lookAt.eye.y, gMainCamera->viewMtx.lookAt.eye.z,
                  gMainCamera->viewMtx.lookAt.at.x, gMainCamera->viewMtx.lookAt.at.y, gMainCamera->viewMtx.lookAt.at.z,
                  0.0f, 1.0f, 0.0f);
    hal_perspective_fast_f(projMatrix, &perspNorm,
                           gMainCamera->perspMtx.persp.fovy,
                           gMainCamera->perspMtx.persp.aspect,
                           gMainCamera->perspMtx.persp.near,
                           gMainCamera->perspMtx.persp.far,
                           gMainCamera->perspMtx.persp.scale);
    guMtxCatF(viewMatrix, projMatrix, projMatrix);

    *outX = projMatrix[0][0] * x + projMatrix[1][0] * y + projMatrix[2][0] * z + projMatrix[3][0];
    *outY = projMatrix[0][1] * x + projMatrix[1][1] * y + projMatrix[2][1] * z + projMatrix[3][1];
    *outZ = projMatrix[0][2] * x + projMatrix[1][2] * y + projMatrix[2][2] * z + projMatrix[3][2];
    w = projMatrix[0][3] * x + projMatrix[1][3] * y + projMatrix[2][3] * z + projMatrix[3][3];
    w = 1.0f / w;
    *outX *= w;
    *outY *= w;
    *outZ *= w;

    if (ABS(*outX) < 1.0f && ABS(*outY) < 1.0f && *outZ > 0.0f) {
        return *outZ;
    }

    return -1.0f;
}

void screenCoorsToWorld(f32* X, f32* Y, f32* Z) {
    Mtx4f viewMatrix;
    Mtx4f projMatrix;
    Mtx3f minor;
    Mtx4f invMatrix;
    s32 i, j, k, l, p;
    u16 perspNorm;
    s32 q;
    f32 f0, f2;
    f32 x1, y1, z1, w1;
    f32 invS;

    hal_look_at_f(viewMatrix,
                  gMainCamera->viewMtx.lookAt.eye.x, gMainCamera->viewMtx.lookAt.eye.y, gMainCamera->viewMtx.lookAt.eye.z,
                  gMainCamera->viewMtx.lookAt.at.x, gMainCamera->viewMtx.lookAt.at.y, gMainCamera->viewMtx.lookAt.at.z,
                  gMainCamera->viewMtx.lookAt.up.x, gMainCamera->viewMtx.lookAt.up.y, gMainCamera->viewMtx.lookAt.up.z);
    hal_perspective_fast_f(projMatrix, &perspNorm,
                           gMainCamera->perspMtx.persp.fovy,
                           gMainCamera->perspMtx.persp.aspect,
                           gMainCamera->perspMtx.persp.near,
                           gMainCamera->perspMtx.persp.far,
                           gMainCamera->perspMtx.persp.scale);
    guMtxCatF(viewMatrix, projMatrix, projMatrix);

    // calculate inverse matrix
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            for (l = 0, k = 0; k < 4; k++) {
                p = 0;
                if (k != i) {
                    for (q = 0; q < 4; q++) {
                        if (j != q) {
                            minor[l][p++] = projMatrix[k][q];
                        }
                    }
                    l++;
                }
            }

            f0 = matrixDeterminant(minor);
            if (((i + j) % 2) == 0) {
                f2 = 1.0f;
            } else {
                f2 = -1.0f;
            }
            invMatrix[j][i] = f2 * f0;
        }
    }

    x1 = invMatrix[0][0] * *X + invMatrix[1][0] * *Y + invMatrix[2][0] * *Z + invMatrix[3][0];
    y1 = invMatrix[0][1] * *X + invMatrix[1][1] * *Y + invMatrix[2][1] * *Z + invMatrix[3][1];
    z1 = invMatrix[0][2] * *X + invMatrix[1][2] * *Y + invMatrix[2][2] * *Z + invMatrix[3][2];
    w1 = invMatrix[0][3] * *X + invMatrix[1][3] * *Y + invMatrix[2][3] * *Z + invMatrix[3][3];
    w1 = 1.0f / w1;
    *X = x1 * w1;
    *Y = y1 * w1;
    *Z = z1 * w1;
}

void setMainCameraViewport(s32 xmin, s32 ymin, s32 xmax, s32 ymax) {
    MainCameraBorderXmin = xmin;
    MainCameraBorderYmin = ymin;
    MainCameraBorderXmax = xmax;
    MainCameraBorderYmax = ymax;

    if (MainCameraBorderXmin < viScreenWidth / SCREEN_WIDTH * D_80382DAC_5231BC) {
        MainCameraBorderXmin = viScreenWidth / SCREEN_WIDTH * D_80382DAC_5231BC;
    }
    if (MainCameraBorderYmin < viScreenHeight / SCREEN_HEIGHT * D_80382DA4_5231B4) {
        MainCameraBorderYmin = viScreenHeight / SCREEN_HEIGHT * D_80382DA4_5231B4;
    }
    if (MainCameraBorderXmax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80382DB0_5231C0) {
        MainCameraBorderXmax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80382DB0_5231C0;
    }
    if (MainCameraBorderYmax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80382DA8_5231B8) {
        MainCameraBorderYmax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80382DA8_5231B8;
    }
}

void mainCameraSetScissor(Gfx** gfxPtr) {
    Gfx* gfxPos = *gfxPtr;

    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE, MainCameraBorderXmin, MainCameraBorderYmin, MainCameraBorderXmax, MainCameraBorderYmax);

    *gfxPtr = gfxPos;
}

void mainCameraPreRender(OMCamera* cam, s32 mode) {
    mainCameraSetScissor(&gMainGfxPos[mode]);
}

void fillBorderBlack(Gfx** gfxPtr, s32 xmin, s32 ymin, s32 xmax, s32 ymax) {
    Gfx* gfxPos = *gfxPtr;

    gDPFillRectangle(gfxPos++, 0, 0, 319, ymin);
    gDPPipeSync(gfxPos++);
    gDPFillRectangle(gfxPos++, 0, ymax, 319, 239);
    gDPPipeSync(gfxPos++);
    gDPFillRectangle(gfxPos++, 0, ymin - 1, xmin, ymax);
    gDPPipeSync(gfxPos++);
    gDPFillRectangle(gfxPos++, xmax, ymin - 1, 319, ymax);
    gDPPipeSync(gfxPos++);

    *gfxPtr = gfxPos;
}

void func_80357FD4_4F83E4(GObj* obj) {
    OMCamera* cam  = obj->data.cam;
    Vec3f sp20;
    f32 f2;

    sp20.x = cam->viewMtx.lookAt.eye.x - cam->viewMtx.lookAt.at.x;
    sp20.z = cam->viewMtx.lookAt.eye.z - cam->viewMtx.lookAt.at.z;
    f2 = 1.0f / sqrtf(SQ(sp20.x) + SQ(sp20.z));
    sp20.x *= f2;
    sp20.y = 1.0f;
    sp20.z *= f2;
    Vec3fNormalize(&sp20);
    func_800A1E6C(&sp20);
}

void mainCameraHandleCmd(GObjCmdData cmdData) {
    if (cmdData.cmd == CAMERA_CMD_BLINK) {
        MainCameraBlinkTimeout = 1;
    }
}

void mainCameraUpdate(GObj* arg0) {
    cmdProcessCommands(mainCameraHandleCmd);
}

void mainCameraRender(GObj* obj) {
    if (MainCameraBlinkTimeout > 0) {
        MainCameraBlinkTimeout--;
        renInitCamera(&gMainGfxPos[0], obj->data.cam, 0);
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_FILL);
        gDPSetRenderMode(gMainGfxPos[0]++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetScissor(gMainGfxPos[0]++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        gDPSetFillColor(gMainGfxPos[0]++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gMainGfxPos[0]++, 0, 0, 319, 239);
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
        gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
        gDPPipeSync(gMainGfxPos[0]++);
        renCameraPostRender(obj->data.cam);
        D_80382D10_523120->flags |= GOBJ_FLAG_HIDDEN;
        return;
    }

    D_80382D10_523120->flags &= ~GOBJ_FLAG_HIDDEN;

    if (MainCameraBorderXmin > 0) {
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
        gDPSetRenderMode(gMainGfxPos[0]++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetScissor(gMainGfxPos[0]++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
        gDPSetColorImage(gMainGfxPos[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, viScreenWidth, viZBuffer);
        gDPSetFillColor(gMainGfxPos[0]++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
        fillBorderBlack(&gMainGfxPos[0], MainCameraBorderXmin, MainCameraBorderYmin, MainCameraBorderXmax, MainCameraBorderYmax);
        gDPPipeSync(gMainGfxPos[0]++);
        gDPSetColorImage(gMainGfxPos[0]++, G_IM_FMT_RGBA, viBitDepth, viScreenWidth, 0x0F000000);
        gDPSetFillColor(gMainGfxPos[0]++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        fillBorderBlack(&gMainGfxPos[0], MainCameraBorderXmin, MainCameraBorderYmin, MainCameraBorderXmax, MainCameraBorderYmax);
    }
    mainCameraSetScissor(&gMainGfxPos[0]);
    ren_func_800192DC(obj);
    func_80359034_4F9444();
}

GObj* createMainCameras(s32 bgColor) {
    GObj* camObj;
    OMCamera* cam;

    camObj = ohCreateCamera(OBJID_MAIN_CAMERA, mainCameraUpdate, LINK_0, 0x80000000, mainCameraRender, 5,
                            CAM_MASK_DL_LINK_3 | CAM_MASK_DL_LINK_4 | CAM_MASK_DL_LINK_5, -1, FALSE, 1, NULL, 0, 0);
    if (camObj == NULL) {
        return NULL;
    }
    omCreateProcess(camObj, func_80357FD4_4F83E4, 1, 1);
    cam = camObj->data.cam;
    gMainCamera = cam;
    cam->flags |= CAMERA_FLAG_1 | CAMERA_FLAG_4;
    cam->bgColor = bgColor;
    gMainCameraViewport[0] = 14;
    gMainCameraViewport[1] = 12;
    gMainCameraViewport[2] = 304;
    gMainCameraViewport[3] = 232;
    func_80007C20(&cam->vp, gMainCameraViewport[0], gMainCameraViewport[1], gMainCameraViewport[2], gMainCameraViewport[3]);
    setMainCameraViewport(cam->vp.vp.vtrans[0] / 4 - cam->vp.vp.vscale[0] / 4,
                         cam->vp.vp.vtrans[1] / 4 - cam->vp.vp.vscale[1] / 4,
                         cam->vp.vp.vtrans[0] / 4 + cam->vp.vp.vscale[0] / 4,
                         cam->vp.vp.vtrans[1] / 4 + cam->vp.vp.vscale[1] / 4);
    cam->fnPreRender = mainCameraPreRender;
    omCameraAddMtx(cam, MTX_TYPE_PERSP_FAST, 0);
    omCameraAddMtx(cam, MTX_TYPE_LOOKAT_REFLECT_ROLL, 0);
    cam->vp = cam->vp; // required to match
    cam->perspMtx.persp.fovy = 60.0f;
    cam->perspMtx.persp.near = 10.0f;
    cam->perspMtx.persp.far = 25600.0f;

    cam->viewMtx.lookAt.at.x = 0.0f;
    cam->viewMtx.lookAt.at.y = 1600.0f;
    cam->viewMtx.lookAt.eye.x = 0.0f;
    cam->viewMtx.lookAt.at.z = 0.0f;
    cam->viewMtx.lookAt.eye.y = 1600.0f;
    cam->viewMtx.lookAt.eye.z = 60.0f;
    cam->viewMtx.lookAt.up.x = 0.0f;
    cam->viewMtx.lookAt.up.y = 1.0f;
    cam->viewMtx.lookAt.up.z = 0.0f;

    gCameraEyePos.x = cam->viewMtx.lookAt.eye.x;
    gCameraEyePos.y = cam->viewMtx.lookAt.eye.y;
    gCameraEyePos.z = cam->viewMtx.lookAt.eye.z;
    gCameraAtPos.x = cam->viewMtx.lookAt.at.x;
    gCameraAtPos.y = cam->viewMtx.lookAt.at.y;
    gCameraAtPos.z = cam->viewMtx.lookAt.at.z;

    return ohCreateCamera(OBJID_UI_CAMERA, ohUpdateDefault, LINK_0, 0x80000000, renSpriteCameraRender, 3,
                          CAM_MASK_DL_LINK_1, -1, FALSE, 0, NULL, 1, 0);
}

void removeMainCamera(void) {
    omDeleteGObj(gMainCamera->obj);
}

GObj* getMainCameraObj(void) {
    return gMainCamera->obj;
}

OMCamera* getMainCamera(void) {
    return gMainCamera;
}
