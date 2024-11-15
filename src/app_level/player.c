#include "common.h"
#include "world/world.h"
#include "app_level.h"

enum CamMessageIds {
    MESSAGE_NONE = 0,
    MESSAGE_PRESS_Z = 1,
    MESSAGE_PRESS_A = 2,
    MESSAGE_TAKE_PICTURES = 3,
    MESSAGE_USE_CONTROL_STICK = 4
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
f32 ViewPitch = 0.0f;
f32 D_80382C10_523020_unused = 0.0f;
s32 ReticleScreenX = 0;
s32 ReticleScreenY = 0;
f32 gCamTargetX = 0.0f;
f32 gCamTargetY = 0.0f;
f32 gCamTargetZ = -500.0f;
f32 StickXAccum = 0.0f;
f32 StickYAccum = 0.0f;
OMCamera* gMainCamera = NULL;
s32 D_80382C34_523044_unused = 0;
GObj* D_80382C38_523048 = NULL;
s32 D_80382C3C_52304C = false;
GObj* gPreviousPokemonInFocus = NULL;
f32 TotalSpeedMult = 0.0005f;
f32 CameraShakingDeltaY = 0.0f;
s32 TargetDirectionZoomedIn = 0;
f32 TargetDirectionYawZommedIn = 0.0f;
f32 D_80382C54_523064_unused = 0.0f;
f32 CameraVibrationDeltaY = 0.0f;
f32 CameraVibrationAmplitude = 20.0f;
f32 CameraVibrationSpeed = 3.0f;
s32 IsCartStopped = 0;
f32 DashEngineSpeedMult = 1.0f;
GObj* ObjectPauseMenu = NULL;
SObj* D_80382C70_523080 = NULL;
SObj* Pause_LabelPause2 = NULL;
SObj* Pause_LabelPause = NULL;
SObj* Pause_QuitCourseSelected = NULL;
SObj* Pause_QuitCourse = NULL;
SObj* Pause_ContinueSelected = NULL;
SObj* Pause_Continue = NULL;
SObj* Pause_RetrySelected = NULL;
SObj* Pause_Retry = NULL;
Vec3f PlayerPos = { 0.0f, 0.0f, 0.0f };
Vec3f PlayerVelocity = { 0.0f, 0.0f, 0.0f };
s32 D_80382CAC_5230BC_unused[2] = { 0, 0 };
s32 ThrowItemTimeout = 3;
s32 PressPokeFluteTimeout = 3;
s32 DashEngineSoundTimeout = 3;
f32 StickXValue = 0.0f;
f32 StickYValue = 0.0f;
f32 PlayerViewYaw = 0.0f; // relative to forward direction
f32 TurnToDirSpeed = 0.0f;
f32 CurrentDirectionYaw = 0.0f;
f32 D_80382CD4_5230E4 = 0.0f;
f32 DirectionsList[5] = {
    -PI,
    -PI / 2,
    0.0f,
    PI / 2,
    PI,
};
f32 MinPitch = -PI / 8;
f32 MaxPitch = PI / 4;
s32 LastItemId = 0;
u32 sTimerInFocus = 0;
s32 D_80382CFC_52310C = 0;
s8 D_80382D00_523110 = 2;
s8 D_80382D04_523114 = 0;
s32 D_80382D08_523118 = 0;
s32 IsInputDisabled = false;
GObj* D_80382D10_523120 = NULL;
GObj* D_80382D14_523124 = NULL;
void (*EndLevelCb)(s32) = NULL;
void (*PauseCb)(s32) = NULL;
u8 IsPaused = false;
u8 PauseCurrentSelection = 0;
s32 D_80382D28_523138 = 153;
u8 D_80382D2C_52313C = 0;
u8 D_80382D30_523140 = 0;
u8 D_80382D34_523144 = 0;
s32 D_80382D38_523148 = 360;
f32 D_80382D3C_52314C = 1.0f;
u8 PauseButtonPressTimeout = 0;
u8 D_80382D44_523154 = false;
s32 LevelBGMSongID = -1;

extern s32 BumpDetector_ProximityLevel;
extern Sprite D_80388E00_529210;

// bss
extern s32 D_803AE408_54E818;
extern Vec3f CameraEyePos;
extern Vec3f CameraAtPos;
extern Vec3f CameraViewVector;
extern SObj* MainCameraReticles[4];
extern SObj* D_803AE458_54E868[6];
extern s32 D_803AE470_54E880;
extern s32 D_803AE474_54E884;
extern f32 D_803AE478_54E888;
extern f32 D_803AE47C_54E88C;
extern struct DObjDynamicStore PlayerMatrixStore; // size 0x38
extern Vec3f D_803AE4D8_54E8E8;
extern Vec3f D_803AE4E8_54E8F8;
extern Vec3f D_803AE4F8_54E908;
extern Vec3f D_803AE508_54E918;
extern s8 ForceDashEngineDisabled;
extern s8 IsTutorialEnabled;
extern s8 D_803AE516_54E926;
extern IdleScript* gIdleScript;
extern u32 ProgressFlags;
extern s8 ZoomSwitchMode;
extern s8 IsAxisYInverted;
extern s8 IsDashEngineAvailable;
extern s32 MainCameraViewport[4]; // Rect?
extern s32 MainCameraBorderXmin;
extern s32 MainCameraBorderYmin;
extern s32 MainCameraBorderXmax;
extern s32 MainCameraBorderYmax;

extern s32 gHasPokemonInFocus;
extern GObj* gPokemonInFocus;
extern s32 gPokemonIdInFocus;
extern u16 gPokemonFlagsInFocus;
extern s32 PokemonDetector_TakenPhotoIndex;
extern u16 gCurrentPhotoContext;

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
void BumpDetector_Init(void);
void func_8035E37C_4FE78C(void);
GObj* Msg_InitCamera(void);
void Msg_ShowMessage(char*, s32, s32, u8, u8, u8, u8, s32, u8);
s32 Msg_IsMessagePrinted(void);
IdleScript* getIdleScript(void);
void func_800A7918(s32, f32);
void func_800A7F40(f32, f32, s32, f32);
void setMainCameraViewport(s32, s32, s32, s32);
void Msg_Reset(void);
void BumpDetector_Delete(s32);
void freezePokemons(GObj*);
void func_80357170_4F7580(void);
void PokemonDetector_Enable(void);
void updateReticleScreenPos(GObj* arg0);
s32 func_8009BBF4(void);
void func_8035E4D0_4FE8E0(void);
void func_8035E764_4FEB74(void);
void func_8035E754_4FEB64(void);
void PokemonDetector_ProcessImage(void);
void func_800A1E6C(Vec3f* arg0);
void func_80356074_4F6484(GObj* arg0);
void processOutOfFilm(GObj*);
s32 func_8035E508_4FE918(void);
s32 makePhoto(GObj* gobj);
s32 func_8035E52C_4FE93C(void);

s32 func_80350200_4F0610(s32 pokemonID) {
    return !func_800BF3D4_5C274(pokemonID);
}

void updateMovementState(GObj* obj) {
    Movement_Update(&gMovementState);
}

void bindCameraNextBlock(f32 dx, f32 dy, f32 dz) {
    PlayerPos.x += dx;
    PlayerPos.y += dy;
    PlayerPos.z += dz;

    gMainCamera->viewMtx.lookAt.eye.x += dx;
    gMainCamera->viewMtx.lookAt.eye.y += dy;
    gMainCamera->viewMtx.lookAt.eye.z += dz;

    gMainCamera->viewMtx.lookAt.at.x += dx;
    gMainCamera->viewMtx.lookAt.at.y += dy;
    gMainCamera->viewMtx.lookAt.at.z += dz;

    // clang-format off
    CameraEyePos.x += dx; CameraEyePos.y += dy; CameraEyePos.z += dz;
    CameraAtPos.x += dx; CameraAtPos.y += dy; CameraAtPos.z += dz;
    gCamTargetX += dx; gCamTargetY += dy; gCamTargetZ += dz;
    // clang-format on
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
    ohPauseProcessByFunction(ObjectPauseMenu, updatePauseMenu);
}

void func_80350458_4F0868(s32 arg0, s32 arg1) {
    scRemovePostProcessFunc();
    func_800A7F68(arg0, arg1);
}

void updateIdle(GObj* obj) {
    f32 var_f20;
    s32 i;
    f32 duration = 120.0f;
    ControllerInput* input = gIdleScript->inputs;

    for (i = gIdleScript->dataSize / sizeof(ControllerInput); i > 0; i--, input++) {
        gContInputCurrentButtons = input->buttons;
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
    ProgressFlags = unk->playerFlags;
    omCreateProcess(obj, updateIdle, 0, 10);
}

void setBackgroundMusic(s32 songID) {
    LevelBGMSongID = songID;
}

void updateMusic(GObj* obj) {
    s32 timerAfterFluteStopped = 2;

    while (true) {
        if (Items_GetPokeFluteState() == 0) {
            if (--timerAfterFluteStopped < 0) {
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                timerAfterFluteStopped = 2;
                auStopSong(BGM_PLAYER_MAIN);
                if (gIdleScript == NULL) {
                    auPlaySong(BGM_PLAYER_MAIN, LevelBGMSongID);
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
        CameraShakingDeltaY = cosf(phase) * 15.0f;
        phase += 0.3f;
        if (phase > TAU) {
            phase -= TAU;
        }
        ohWait(1);
    }
    CameraShakingDeltaY = 0.0f;
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
                Items_SpawnPesterBall(&gMainCamera->viewMtx.lookAt.eye, &PlayerVelocity);
                Icons_ProcessButtonPress(ITEM_ID_PESTER_BALL);
                Items_StopPokeFlute();
                Icons_ProcessButtonPress(-1);
                PressPokeFluteTimeout = 0;
            } else if ((gContInputPressedButtons & A_BUTTON) && Icons_NumItemsAvailable >= 1) {
                LastItemId = ITEM_ID_APPLE;
                ThrowItemTimeout = 45;
                Items_SpawnApple(&gMainCamera->viewMtx.lookAt.eye, &PlayerVelocity);
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
        StickXValue = (f32) gContInputStickX / 80.0;
        StickXAccum += 0.014f * StickXValue;
        if (StickXAccum > 1.0f) {
            StickXAccum = 1.0f;
        } else if (StickXAccum < -1.0f) {
            StickXAccum = -1.0f;
        }
    } else {
        StickXValue = 0.0f;
        if (StickXAccum > 0.8) {
            StickXAccum -= 0.03;
        } else if (StickXAccum < -0.8) {
            StickXAccum += 0.03;
        }
    }

    if (ABS(gContInputStickY) >= 6 && !IsInputDisabled) {
        StickYValue = (f32) gContInputStickY / 80.0;
        if (IsAxisYInverted == true) {
            StickYValue = -StickYValue;
        }

        if (StickYValue < 0.0f && ViewPitch <= MaxPitch + PI / 180.0f ||
            StickYValue > 0.0f && ViewPitch >= MinPitch - PI / 180.0f) {
            StickYAccum += 0.02f * StickYValue;
        }

        if (StickYAccum > 0.2f) {
            StickYAccum = 0.2f;
        } else if (StickYAccum < -0.9f) {
            StickYAccum = -0.9f;
        }

        if (StickYValue < 0.0f && ViewPitch <= MaxPitch ||
            StickYValue > 0.0f && ViewPitch > MinPitch) {
            ViewPitch -= 0.015f * StickYValue;
        }
    } else {
        if (StickYAccum > 0.0) {
            StickYAccum -= 0.03;
        } else if (StickYAccum < -0.7) {
            StickYAccum += 0.03;
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

    if (!IsCartStopped) {
        gMovementState.cpTime += D_803AE47C_54E88C * 0.005f;
        if (gMovementState.cpTime > 1.0f) {
            gMovementState.cpTime = 1.0f;
        } else if (gMovementState.cpTime < 0.0f) {
            gMovementState.cpTime = 0.0f;
        }
        gMovementState.speedMult = TotalSpeedMult;
    } else {
        gMovementState.speedMult = 0.0f;
    }

    GET_TRANSFORM(model)->pos.v.x = gMovementState.pos.x;
    GET_TRANSFORM(model)->pos.v.y = gMovementState.pos.y;
    GET_TRANSFORM(model)->pos.v.z = gMovementState.pos.z;
    GET_TRANSFORM(model)->rot.f[1] = gMovementState.rotation.x;
    GET_TRANSFORM(model)->rot.f[2] = gMovementState.rotation.y + D_80382CD4_5230E4;
    GET_TRANSFORM(model)->rot.f[3] = gMovementState.rotation.z;

    Vec3fDiff(&PlayerVelocity, &GET_TRANSFORM(model)->pos.v, &PlayerPos);

    PlayerPos = GET_TRANSFORM(model)->pos.v;

    if (D_80382D04_523114 == 1) {
        if (ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG) && gDirectionIndex >= 0 ||
            ZoomSwitchMode == 0 && (gContInputCurrentButtons & Z_TRIG) && gDirectionIndex >= 0) {
            D_80382C3C_52304C = false;
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
    if (TotalSpeedMult > 0.0f) {
        TotalSpeedMult -= 0.0005f / 200.0f;
    } else {
        TotalSpeedMult = 0.0f;
    }
}

void playDashEngineSounds(s32 enabled) {
    static s32 dashEngineSoundHandle = -1;
    if (enabled == true) {
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
        DashEngineSoundTimeout = 10;
    }
}

s32 IsDashEngineOn = 0;
s32 D_80382D54_523164 = 100;

void updateDashEngine(void) {
    DashEngineSpeedMult = 1.0f;
    if (!IsInputDisabled && IsDashEngineAvailable == 1) {
        if ((gContInputCurrentButtons & R_TRIG) && ForceDashEngineDisabled == 0) {
            DashEngineSpeedMult *= 3.0f;
            Icons_SetDashEngineEnabled(true);
            if (DashEngineSoundTimeout == 0) {
                playDashEngineSounds(true);
            }
        } else {
            playDashEngineSounds(false);
            IsDashEngineOn = 0;
            Icons_SetDashEngineEnabled(false);
        }
    }
    if (DashEngineSoundTimeout > 0) {
        DashEngineSoundTimeout--;
    }
    TotalSpeedMult = DashEngineSpeedMult * 0.0005f * (1.0f + D_803AE478_54E888 * 0.25f);
}

void handleCButtons(GObj* obj) {
    s32 CButtonPressed = false;

    if (gDirectionIndex < 0) {
        return;
    }

    if (!IsInputDisabled) {
        if (gContInputPressedButtons & U_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            if (gDirectionIndex == 0) {
                TurnToDirSpeed = 0.2f;
            } else if (gDirectionIndex == 1) {
                TurnToDirSpeed = 0.1f;
            } else {
                TurnToDirSpeed = -0.1f;
            }
            gDirectionIndex = 2;
            CButtonPressed = true;
            ReticleScreenX = 0;
        } else if (gContInputPressedButtons & R_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            gDirectionIndex++;
            if (gDirectionIndex >= 4) {
                gDirectionIndex -= 4;
            }
            CButtonPressed = true;
            TurnToDirSpeed = 0.1f;
            ReticleScreenX = 0;
        } else if (gContInputPressedButtons & L_CBUTTONS) {
            auPlaySound(SOUND_ID_4);
            gDirectionIndex--;
            if (gDirectionIndex < 0) {
                gDirectionIndex += 4;
            }
            CButtonPressed = true;
            TurnToDirSpeed = -0.1f;
            ReticleScreenX = 0;
        }
    }

    updateDashEngine();
    if (CButtonPressed) {
        StickXAccum = 0.0f;
        PlayerViewYaw = 0.0f;
        ohResumeProcessByFunction(obj, processTurnToDirection);
        ohPauseProcessByFunction(obj, updateMovementState);
        ohPauseProcessByFunction(obj, handleAnalogStick);
        ohPauseProcessByFunction(obj, handleCButtons);
        return;
    }

    if (ABS(ReticleScreenX) > 50) {
        PlayerViewYaw += StickXValue * 0.03 * 0.8;
    }
}

void processTurnToDirection(GObj* obj) {
    f32 currentYaw;
    f32 targetYaw;
    s32 v0 = 0;

    if (IsPaused) {
        return;
    }

    targetYaw = DirectionsList[gDirectionIndex];
    currentYaw = CurrentDirectionYaw;

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

    if (ABS(targetYaw - currentYaw) > ABS(TurnToDirSpeed)) {
        CurrentDirectionYaw += TurnToDirSpeed;
    } else {
        CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        v0++;
    }
    targetYaw = 0.015f * PI; // need var reuse for matching
    if (ABS(ViewPitch) > targetYaw) {
        if (ViewPitch > 0.0f) {
            ViewPitch -= targetYaw;
        } else {
            ViewPitch += targetYaw;
        }
    } else {
        ViewPitch = 0.0f;
        v0++;
    }

    if (v0 >= 2) {
        TurnToDirSpeed = 0.0f;
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
        if (PlayerViewYaw > 0.3f * PI) {
            gDirectionIndex = 1;
            PlayerViewYaw = -0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        } else if (PlayerViewYaw < -0.3f * PI) {
            gDirectionIndex = 3;
            PlayerViewYaw = 0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        }
    } else if (gDirectionIndex == 1) {
        if (PlayerViewYaw > 0.3f * PI) {
            gDirectionIndex = 2;
            PlayerViewYaw = -0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        } else if (PlayerViewYaw < -0.3f * PI) {
            gDirectionIndex = 0;
            PlayerViewYaw = 0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        }
    } else if (gDirectionIndex == 2) {
        if (PlayerViewYaw > 0.3f * PI) {
            gDirectionIndex = 3;
            PlayerViewYaw = -0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        } else if (PlayerViewYaw < -0.3f * PI) {
            gDirectionIndex = 1;
            PlayerViewYaw = 0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        }
    } else if (gDirectionIndex == 3) {
        if (PlayerViewYaw > 0.3f * PI) {
            gDirectionIndex = 0;
            PlayerViewYaw = -0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        } else if (PlayerViewYaw < -0.3f * PI) {
            gDirectionIndex = 2;
            PlayerViewYaw = 0.2f * PI;
            CurrentDirectionYaw = DirectionsList[gDirectionIndex];
        }
    }

    if (gDirectionIndex == 0) {
        StickXValue *= -1.0f;
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

    sp94 = CurrentDirectionYaw + PlayerViewYaw;
    D_803AE478_54E888 = cosf(sp94);
    D_803AE47C_54E88C = sinf(sp94);

    if (!IsCartStopped) {
        TotalSpeedMult = DashEngineSpeedMult * 0.0005f * (1.0f + D_803AE478_54E888 * 0.25f);
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

    eyePos.x = CameraEyePos.x = gMovementState.pos.x;
    eyePos.y = CameraEyePos.y = gMovementState.pos.y + oneHundred + CameraShakingDeltaY + CameraVibrationDeltaY;
    eyePos.z = CameraEyePos.z = gMovementState.pos.z;

    sp64.x = -20.0f * cosf(ViewPitch) * sinf(sp94);
    sp64.y = 20.0f * sinf(ViewPitch);
    sp64.z = 20.0f * cosf(ViewPitch) * cosf(sp94);

    Vec3fGetEulerRotation(&sp64, AXIS_X, gMovementState.rotation.x);
    Vec3fGetEulerRotation(&sp64, AXIS_Y, gMovementState.rotation.y);
    Vec3fGetEulerRotation(&sp64, AXIS_Z, gMovementState.rotation.z);

    CameraAtPos.x = sp64.x + eyePos.x;
    CameraAtPos.y = sp64.y + eyePos.y;
    CameraAtPos.z = sp64.z + eyePos.z;

    dx = CameraAtPos.x - CameraEyePos.x;
    dz = CameraAtPos.z - CameraEyePos.z;
    if (SQ(dx) + SQ(dz) < 0.1f) {
        CameraAtPos.x = CameraEyePos.x + CameraViewVector.x;
        CameraAtPos.z = CameraEyePos.z + CameraViewVector.z;
    } else {
        CameraViewVector.x = dx;
        CameraViewVector.z = dz;
    }

    gMainCamera->viewMtx.lookAt.eye.x = CameraEyePos.x;
    gMainCamera->viewMtx.lookAt.eye.y = CameraEyePos.y;
    gMainCamera->viewMtx.lookAt.eye.z = CameraEyePos.z;
    gMainCamera->viewMtx.lookAt.at.x = CameraAtPos.x;
    gMainCamera->viewMtx.lookAt.at.y = CameraAtPos.y;
    gMainCamera->viewMtx.lookAt.at.z = CameraAtPos.z;
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

    Icons_ProcessZoom(true);

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

    PlayerViewYaw = atanf(spD4.x / spD4.z);
    ViewPitch = atanf(spD4.y / f28);
    if (spD4.z > 0.0f) {
        PlayerViewYaw = TAU - PlayerViewYaw;
    } else {
        PlayerViewYaw = PI - PlayerViewYaw;
    }
    if (PlayerViewYaw > TAU) {
        PlayerViewYaw -= TAU;
    } else if (PlayerViewYaw < 0.0f) {
        PlayerViewYaw += TAU;
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
    D_803AE4D8_54E8E8.x = CameraEyePos.x;
    D_803AE4D8_54E8E8.y = CameraEyePos.y;
    D_803AE4D8_54E8E8.z = CameraEyePos.z;
    D_803AE4E8_54E8F8.x = CameraAtPos.x;
    D_803AE4E8_54E8F8.y = CameraAtPos.y;
    D_803AE4E8_54E8F8.z = CameraAtPos.z;
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

    while (true) {
        if (ZoomSwitchMode == 0 && (gContInputReleasedButtons & Z_TRIG)) {
            break;
        }

        sinAngle = sinf(gMovementState.rotation.y);
        cosAngle = cosf(gMovementState.rotation.y);

        D_803AE4D8_54E8E8.x += sp114 * spEC.x;
        D_803AE4D8_54E8E8.y += sp114 * spEC.y;
        D_803AE4D8_54E8E8.z += sp114 * spEC.z;

        CameraEyePos.x = gMovementState.pos.x + D_803AE4D8_54E8E8.x * cosAngle + D_803AE4D8_54E8E8.z * sinAngle;
        CameraEyePos.y = gMovementState.pos.y + D_803AE4D8_54E8E8.y;
        CameraEyePos.z = gMovementState.pos.z - D_803AE4D8_54E8E8.x * sinAngle + D_803AE4D8_54E8E8.z * cosAngle;

        D_803AE4E8_54E8F8.x += sp110 * spE0.x;
        D_803AE4E8_54E8F8.y += sp110 * spE0.y;
        D_803AE4E8_54E8F8.z += sp110 * spE0.z;

        CameraAtPos.x = gMovementState.pos.x + D_803AE4E8_54E8F8.x * cosAngle + D_803AE4E8_54E8F8.z * sinAngle;
        CameraAtPos.y = gMovementState.pos.y + D_803AE4E8_54E8F8.y;
        CameraAtPos.z = gMovementState.pos.z - D_803AE4E8_54E8F8.x * sinAngle + D_803AE4E8_54E8F8.z * cosAngle;

        dx2 = CameraAtPos.x - CameraEyePos.x;
        dz2 = CameraAtPos.z - CameraEyePos.z;
        if ((SQ(dx2) + SQ(dz2)) < 0.1f) {
            CameraAtPos.x = CameraEyePos.x + CameraViewVector.x;
            CameraAtPos.z = CameraEyePos.z + CameraViewVector.z;
        } else {
            CameraViewVector.x = dx2;
            CameraViewVector.z = dz2;
        }

        x1 -= 2;
        y1 -= 2;
        x2 += 2;
        y2 += 2;

        gMainCamera->viewMtx.lookAt.eye.x = CameraEyePos.x;
        gMainCamera->viewMtx.lookAt.eye.y = CameraEyePos.y + CameraVibrationDeltaY;
        gMainCamera->viewMtx.lookAt.eye.z = CameraEyePos.z;
        gMainCamera->viewMtx.lookAt.at.x = CameraAtPos.x;
        gMainCamera->viewMtx.lookAt.at.y = CameraAtPos.y + CameraVibrationDeltaY;
        gMainCamera->viewMtx.lookAt.at.z = CameraAtPos.z;

        func_80007C20(&gMainCamera->vp, x1, y1, x2, y2);

        x3 += 3;
        y3 += 2;
        x4 -= 3;
        y4 -= 2;

        gMainCamera->perspMtx.persp.aspect = (f32) (x2 - x1) / (f32) (y2 - y1);
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
    TargetDirectionZoomedIn = 0;
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
    sTimerInFocus = 0;
    D_80382CFC_52310C = 0;
    StickXAccum = 0.0f;

    y1 = -25;
    y2 = 265;
    x1 = -25;
    x2 = 345;

    y3 = 22;
    y4 = 216;
    x3 = 30;
    x4 = 289;
    StickYAccum = 0.0f;

    while (i++ < 10) {
        // clang-format off
        if (ZoomSwitchMode == 0 && (gContInputPressedButtons & Z_TRIG)) { break; }
        // clang-format on

        temp_f14 = gMovementState.pos.x - CameraEyePos.x;
        temp_f18 = gMovementState.pos.y + 100.0f + CameraShakingDeltaY - CameraEyePos.y;
        temp_f20 = gMovementState.pos.z - CameraEyePos.z;

        CameraEyePos.x = gMovementState.pos.x;
        CameraEyePos.y = gMovementState.pos.y + 100.0f + CameraShakingDeltaY;
        CameraEyePos.z = gMovementState.pos.z;

        CameraAtPos.x += temp_f14;
        CameraAtPos.y += temp_f18;
        CameraAtPos.z += temp_f20;

        dx = CameraAtPos.x - CameraEyePos.x;
        dz = CameraAtPos.z - CameraEyePos.z;
        if (SQ(dx) + SQ(dz) < 0.1f) {
            CameraAtPos.x = CameraEyePos.x + CameraViewVector.x;
            CameraAtPos.z = CameraEyePos.z + CameraViewVector.z;
        } else {
            CameraViewVector.x = dx;
            CameraViewVector.z = dz;
        }

        gMainCamera->viewMtx.lookAt.eye.x = CameraEyePos.x;
        gMainCamera->viewMtx.lookAt.eye.y = CameraEyePos.y;
        gMainCamera->viewMtx.lookAt.eye.z = CameraEyePos.z;
        gMainCamera->viewMtx.lookAt.at.x = CameraAtPos.x;
        gMainCamera->viewMtx.lookAt.at.y = CameraAtPos.y;
        gMainCamera->viewMtx.lookAt.at.z = CameraAtPos.z;
        gMainCamera->viewMtx.lookAt.eye.y += CameraVibrationDeltaY;
        gMainCamera->viewMtx.lookAt.at.y += CameraVibrationDeltaY;

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
    viewVector.x = CameraAtPos.x - CameraEyePos.x;
    viewVector.y = CameraAtPos.y - CameraEyePos.y;
    viewVector.z = CameraAtPos.z - CameraEyePos.z;
    Vec3fNormalize(&viewVector);
    Vec3fGetEulerRotation(&viewVector, 4, -gMovementState.rotation.z);
    Vec3fGetEulerRotation(&viewVector, 2, -gMovementState.rotation.y);
    Vec3fGetEulerRotation(&viewVector, 1, -gMovementState.rotation.x);
    ViewPitch = asinf(viewVector.y);
    angle1 = acosf(viewVector.z / cosf(ViewPitch));
    if (viewVector.x > 0.0f) {
        angle1 = TAU - angle1;
    }

    if (angle1 < PI / 4.0f) {
        direction = 2;
    } else if (angle1 < PI * 3.0f / 4.0f) {
        direction = 3;
    } else if (angle1 < PI * 5.0f / 4.0f) {
        direction = 0;
    } else if (angle1 < PI * 7.0f / 4.0f) {
        direction = 1;
    } else {
        direction = 2;
    }

    CurrentDirectionYaw = DirectionsList[direction];
    if (CurrentDirectionYaw < 0.0f) {
        CurrentDirectionYaw += TAU;
    }
    if (direction == 2) {
        if (angle1 > PI) {
            PlayerViewYaw = angle1 - TAU;
        } else {
            PlayerViewYaw = angle1;
        }
        CurrentDirectionYaw = DirectionsList[direction];
    } else {
        PlayerViewYaw = angle1 - CurrentDirectionYaw;
        CurrentDirectionYaw = DirectionsList[direction];
    }
    gMainCamera->viewMtx.lookAt.eye.x = CameraEyePos.x;
    gMainCamera->viewMtx.lookAt.eye.y = CameraEyePos.y + CameraVibrationDeltaY;
    gMainCamera->viewMtx.lookAt.eye.z = CameraEyePos.z;
    gMainCamera->viewMtx.lookAt.at.x = CameraAtPos.x;
    gMainCamera->viewMtx.lookAt.at.y = CameraAtPos.y + CameraVibrationDeltaY;
    gMainCamera->viewMtx.lookAt.at.z = CameraAtPos.z;
    Icons_ProcessZoom(false);
    ReticleScreenX = 0;
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

    while (true) {
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
            Msg_Reset();
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
        Msg_ShowMessage(pokemonName, 160, 200, 255, 255, 255, 255, 0, MSG_ALIGN_CENTER);
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
                ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG)) {
                goto END;
            }
            showPokemonLabel(pokemonID, i & 0xC, &sp3C);
            ohWait(1);
        }

        showPokemonLabel(pokemonID, 1, &sp3C);

        for (i = 60; i > 0; i--) {
            if (D_803AE408_54E818 != pokemonID ||
                ZoomSwitchMode == 0 && !(gContInputCurrentButtons & Z_TRIG) ||
                ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG)) {
                goto END;
            }
            ohWait(1);
        }
    }
END:
    if (!D_803AE516_54E926) {
        if (&sp3C) {
        } // required to match
        Msg_Reset();
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
    if (!IsPaused && D_80382D44_523154 == 0 && D_80382D78_523188 != gtlDrawnFrameCounter) {
        spSetAttribute(&ObjectPauseMenu->data.sobj->sprite, SP_HIDDEN);
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
        if (TargetDirectionZoomedIn == 1) {
            PlayerViewYaw += 0.1f;
            if (TargetDirectionYawZommedIn < PlayerViewYaw) {
                TargetDirectionZoomedIn = 0;
                PlayerViewYaw = TargetDirectionYawZommedIn;
            }
        } else if (TargetDirectionZoomedIn == 2) {
            PlayerViewYaw -= 0.1f;
            if (PlayerViewYaw < TargetDirectionYawZommedIn) {
                TargetDirectionZoomedIn = 0;
                PlayerViewYaw = TargetDirectionYawZommedIn;
            }
        } else {
            PlayerViewYaw = PlayerViewYaw + StickXValue * 0.025;
            if (PlayerViewYaw > TAU) {
                PlayerViewYaw -= TAU;
            } else if (PlayerViewYaw < 0.0f) {
                PlayerViewYaw += TAU;
            }
        }
        sinCartYaw = sinf(gMovementState.rotation.y);
        cosCartYaw = cosf(gMovementState.rotation.y);

        eyePos.x = CameraEyePos.x = gMovementState.pos.x;
        eyePos.y = CameraEyePos.y = gMovementState.pos.y + 100.0f + CameraVibrationDeltaY;
        eyePos.z = CameraEyePos.z = gMovementState.pos.z;

        viewVectorX = -20.0f * cosf(ViewPitch) * sinf(PlayerViewYaw);
        viewVectorY = 20.0f * sinf(ViewPitch);
        viewVectorZ = 20.0f * cosf(ViewPitch) * cosf(PlayerViewYaw);

        CameraAtPos.x = viewVectorX * cosCartYaw + viewVectorZ * sinCartYaw + eyePos.x;
        CameraAtPos.y = viewVectorY + eyePos.y;
        CameraAtPos.z = viewVectorZ * cosCartYaw - viewVectorX * sinCartYaw + eyePos.z;

        dx = CameraAtPos.x - CameraEyePos.x;
        dz = CameraAtPos.z - CameraEyePos.z;
        if (SQ(dx) + SQ(dz) < 0.1f) {
            CameraAtPos.x = CameraEyePos.x + CameraViewVector.x;
            CameraAtPos.z = CameraEyePos.z + CameraViewVector.z;
        } else {
            CameraViewVector.x = dx;
            CameraViewVector.z = dz;
        }

        gMainCamera->viewMtx.lookAt.eye.x = CameraEyePos.x;
        gMainCamera->viewMtx.lookAt.eye.y = CameraEyePos.y;
        gMainCamera->viewMtx.lookAt.eye.z = CameraEyePos.z;
        gMainCamera->viewMtx.lookAt.at.x = CameraAtPos.x;
        gMainCamera->viewMtx.lookAt.at.y = CameraAtPos.y;
        gMainCamera->viewMtx.lookAt.at.z = CameraAtPos.z;
    }
    if (ZoomSwitchMode == 1 || (gContInputCurrentButtons & Z_TRIG)) {
        if (gHasPokemonInFocus == true && gPokemonInFocus != NULL && GET_POKEMON(gPokemonInFocus) == NULL) {
            gHasPokemonInFocus = false;
        }
        if (gHasPokemonInFocus == true && (gPokemonFlagsInFocus & POKEMON_FLAG_4)) {
            if (gPreviousPokemonInFocus == gPokemonInFocus) {
                sTimerInFocus++;
            } else {
                sTimerInFocus = 0;
                D_80382C3C_52304C = false;
            }
            D_80382CFC_52310C = 2;
            if ((!D_80382C3C_52304C || D_803AE474_54E884 != (gPokemonFlagsInFocus & POKEMON_FLAG_8)) && gDirectionIndex == -1) {
                omCreateProcess(D_80382C38_523048, func_80356074_4F6484, 0, 9);
                auPlaySound(SOUND_ID_1);
                D_80382C3C_52304C = true;
                gPreviousPokemonInFocus = gPokemonInFocus;
                D_803AE470_54E880 = gPokemonIdInFocus;
                D_803AE474_54E884 = gPokemonFlagsInFocus & POKEMON_FLAG_8;
            }
        } else if (D_80382CFC_52310C != 0) {
            D_80382CFC_52310C--;
        } else {
            sTimerInFocus = 0;
            D_80382C3C_52304C = false;
        }
        if (sTimerAfterPhotoTaken < 0) {
            if (TargetDirectionZoomedIn == 0 && (gContInputPressedButtons & A_BUTTON)) {
                camera = ohFindByLinkAndId(LINK_0, OBJID_MAIN_CAMERA);
                if (camera != NULL) {
                    if (D_80382D00_523110 == 2) {
                        spColor(&ObjectPauseMenu->data.sobj->sprite, 0, 0, 0, D_80382D54_523164);
                        spClearAttribute(&ObjectPauseMenu->data.sobj->sprite, SP_HIDDEN);
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
                    if (gHasPokemonInFocus && gPokemonInFocus != NULL) {
                        cmdSendCommand(gPokemonInFocus, POKEMON_CMD_24, obj);
                    }
                    PokemonDetector_TakenPhotoIndex = gCurrentPhotoContext;
                    if (gHasPokemonInFocus && (gPokemonFlagsInFocus & POKEMON_FLAG_4)) {
                        makePhoto(gPokemonInFocus);
                        sp38 = gPokemonIdInFocus;
                        if (gPokemonFlagsInFocus & POKEMON_FLAG_8) {
                            sp38 = 500;
                        }
                    } else {
                        makePhoto(NULL);
                        sp38 = 0;
                    }

                    Camera_EndProcessByFunction(obj, func_80352F20_4F3330);
                    D_803AE408_54E818 = sp38;
                    omCreateProcess(obj, func_80352F20_4F3330, 0, 9);
                    if (gHasPokemonInFocus && gPokemonInFocus != NULL) {
                        GET_POKEMON(gPokemonInFocus)->flags |= POKEMON_FLAG_80;
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
                if (PlayerViewYaw > PI) {
                    TargetDirectionZoomedIn = 1;
                    TargetDirectionYawZommedIn = TAU;
                } else {
                    TargetDirectionZoomedIn = 2;
                    TargetDirectionYawZommedIn = 0.0f;
                }
            } else if (gContInputPressedButtons & R_CBUTTONS) {
                auPlaySound(SOUND_ID_4);
                TargetDirectionZoomedIn = 1;
                if (PlayerViewYaw > TAU - 0.001) {
                    PlayerViewYaw -= TAU;
                    TargetDirectionYawZommedIn = PI_2;
                } else if (PlayerViewYaw > PI * 1.5f - 0.01) {
                    TargetDirectionYawZommedIn = TAU;
                } else if (PlayerViewYaw > PI - 0.01) {
                    TargetDirectionYawZommedIn = 1.5f * PI;
                } else if (PlayerViewYaw > PI / 2.0f - 0.01) {
                    TargetDirectionYawZommedIn = PI;
                } else {
                    TargetDirectionYawZommedIn = PI_2;
                }
            } else if (gContInputPressedButtons & L_CBUTTONS) {
                auPlaySound(SOUND_ID_4);
                TargetDirectionZoomedIn = 2;
                if (PlayerViewYaw < 0.001f) {
                    PlayerViewYaw += TAU;
                    TargetDirectionYawZommedIn = 1.5f * PI;
                } else if (PlayerViewYaw < PI / 2.0f + 0.001f) {
                    TargetDirectionYawZommedIn = 0.0f;
                } else if (PlayerViewYaw < PI + 0.001f) {
                    TargetDirectionYawZommedIn = PI_2;
                } else if (PlayerViewYaw < 1.5f * PI + 0.001f) {
                    TargetDirectionYawZommedIn = PI;
                } else {
                    TargetDirectionYawZommedIn = 1.5f * PI;
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
        while (true) {
            getLevelProgress(&blockCount, &blockPart);
            if (blockCount + blockPart >= 4.15f) {
                break;
            }
            ohWait(1);
        }
    }

    while (true) {
        CameraVibrationDeltaY = sinf(phase) * CameraVibrationAmplitude;
        phase += CameraVibrationSpeed * PI / 180.0f;
        if (levelID == SCENE_BEACH) {
            getLevelProgress(&blockCount, &blockPart);
            if (blockCount + blockPart >= 4.45f) {
                break;
            }
        }
        ohWait(1);
    }

    CameraVibrationDeltaY = 0.0f;
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
    return IsPaused == 0 && D_80382D44_523154 == 0;
}

void Pause_UpdateSelection(GObj* obj) {
    if (PauseButtonPressTimeout > 0) {
        Pause_StickReleased = false;
    } else if (ABS(gContInputStickY) > 20 && Pause_StickReleased) {
        Pause_StickReleased = false;
        if (gContInputStickY > 0) {
            if (PauseCurrentSelection > 0) {
                PauseCurrentSelection--;
                auPlaySound(SOUND_ID_65);
            }
        } else {
            if (PauseCurrentSelection < 2) {
                PauseCurrentSelection++;
                auPlaySound(SOUND_ID_65);
            }
        }

        switch (PauseCurrentSelection) {
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
        Pause_StickReleased = true;
    }
    if (!IsPaused) {
        omEndProcess(NULL);
    }
}

void func_8035403C_4F444C(GObj* obj) {
    SObj* sobj = obj->data.sobj;
    Sprite* sprite = &sobj->sprite;

    D_80382D28_523138 = 0;
    spColor(sprite, D_80382D2C_52313C, D_80382D30_523140, D_80382D34_523144, 0);
    spClearAttribute(sprite, SP_HIDDEN);

    while (true) {
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

    while (true) {
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
        if (IsPaused == 0) {
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

    while (true) {
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
    Msg_Reset();
    BumpDetector_Delete(1);
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
    IsPaused = 1 - IsPaused;
    func_80357170_4F7580();
    Icons_UnFreeze();
    PauseCb(false);
    PokemonDetector_Enable();
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
    if (IsInputDisabled != true) {
        if (PauseButtonPressTimeout > 0) {
            PauseButtonPressTimeout--;
            return;
        }
        if (IsPaused) {
            if (gContInputPressedButtons & B_BUTTON) {
                omCreateProcess(arg0, Pause_HideUI, 0, 9);
                PauseButtonPressTimeout = 30;
                D_80382D3C_52314C = 1.0f;
                omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
                omCreateProcess(arg0, func_80354860_4F4C70, 0, 9);
                gContInputPressedButtons = 0;
            } else if ((gContInputPressedButtons & A_BUTTON) || (gContInputPressedButtons & CONT_START)) {
                if (PauseCurrentSelection == PAUSE_OPTION_CONTINUE) {
                    omCreateProcess(arg0, Pause_HideUI, 0, 9);
                    PauseButtonPressTimeout = 30;
                    D_80382D3C_52314C = 1.0f;
                    omCreateProcess(arg0, func_8035464C_4F4A5C, 0, 9);
                    omCreateProcess(arg0, func_80354860_4F4C70, 0, 9);
                } else if (PauseCurrentSelection == PAUSE_OPTION_QUIT) {
                    auPlaySound(SOUND_ID_66);
                    omCreateProcess(arg0, quitCourse, 0, 9);
                    IsPaused = false;
                    D_80382D44_523154 = 1;
                    omEndProcess(NULL);
                } else {
                    // retry
                    auPlaySound(SOUND_ID_66);
                    omCreateProcess(arg0, retryCourse, 0, 9);
                    IsPaused = false;
                    D_80382D44_523154 = 1;
                    omEndProcess(NULL);
                }
                gContInputPressedButtons = 0;
            }
        } else if (gContInputPressedButtons & CONT_START) {
            IsPaused = 1 - IsPaused;
            PauseCurrentSelection = 0;
            func_80357120_4F7530(arg0);
            Icons_Freeze();
            PauseCb(true);
            PokemonDetector_Disable();
            ohPauseProcessByFunction(gObjPlayer, func_80352F20_4F3330);
            Msg_Reset();
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
            PauseButtonPressTimeout = 30;
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

    if (D_803AE516_54E926 == true) {
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
            Msg_ShowMessage(message, 160, 150, 255, 255, 255, 255, 0, MSG_ALIGN_CENTER);
        }
    } else {
        Msg_Reset();
    }
}

s32 func_80354FB8_4F53C8(s32 duration) {
    s32 s1 = false;

    while (duration > 0) {
        if (ABS(gContInputStickX) >= 6 || ABS(gContInputStickY) >= 6) {
            s1 = true;
        }
        if (!IsPaused) {
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
    ohPauseProcessByFunction(ObjectPauseMenu, updatePauseMenu);
    ohPauseProcessByFunction(D_80382C38_523048, updateReticleScreenPos);
}

void Tutorial_UnPauseAll(GObj* arg0, s32* arg1) {
    func_80357170_4F7580();
    func_80354E04_4F5214(*arg1);
    ohResumeProcessByFunction(gObjPlayer, processZoomingIn);
    ohResumeProcessByFunction(gObjPlayer, processZoomingOut);
    ohResumeProcessByFunction(gObjPlayer, updateCameraZoomedIn);
    ohResumeProcessByFunction(ObjectPauseMenu, updatePauseMenu);
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
        if (!gHasPokemonInFocus) {
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

        if (gPokemonIdInFocus <= 0 || gPokemonIdInFocus > 151 || (GET_POKEMON(gPokemonInFocus)->flags & 0x80)) {
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

    Msg_Reset();
    D_80382D08_523118 = 0;
    if (D_80382D04_523114 == 1) {
        if (ZoomSwitchMode == 0 && (gContInputPressedButtons & Z_TRIG) ||
            ZoomSwitchMode == 1 && (gContInputPressedButtons & Z_TRIG) && gDirectionIndex >= 0) {
            D_80382C3C_52304C = false;
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
        IsInputDisabled = false;
        omCreateProcess(arg0, func_80355228_4F5638, 0, 9);
        omEndProcess(NULL);
    } else if (gHasPokemonInFocus == true &&
               D_80382D08_523118 == 0 &&
               gPokemonIdInFocus > 0 &&
               gPokemonIdInFocus <= POKEDEX_MAX &&
               !(GET_POKEMON(gPokemonInFocus)->flags & POKEMON_FLAG_80)) {
        D_80382D08_523118 = 1;
        omCreateProcess(arg0, func_803552B0_4F56C0, 0, 9);
    }
}

void func_803555B0_4F59C0(u8 arg0, u8 arg1, u8 arg2) {
    D_80382D2C_52313C = arg0;
    D_80382D30_523140 = arg1;
    D_80382D34_523144 = arg2;
    omCreateProcess(ObjectPauseMenu, func_8035403C_4F444C, 0, 9);
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
    Msg_Reset();
    BumpDetector_Delete(arg1);
    scRemovePostProcessFunc();
    stopLevelProcesses();
    ohPauseProcessByFunction(gObjPlayer, func_80352F20_4F3330);
    freezePokemons(pokemon);
    setSkyBoxAnimationSpeed(0);
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

void processOutOfFilm(GObj* arg0) {
    UNUSED s32 pad;
    UNUSED s32 pad2;
    UNUSED s32 pad3;
    s32 var_s2;
    SObj* sobj1;
    s32 i;
    SObj* sobj2;

    var_s2 = 0;
    D_80382D44_523154 = 1;
    D_803AE516_54E926 = true;
    stopLevelProcesses();
    ohPauseProcessByFunction(gObjPlayer, func_80355228_4F5638);
    func_80357120_4F7530(NULL);
    func_803555B0_4F59C0(0, 0, 255);
    scRemovePostProcessFunc();
    playDashEngineSounds(0);
    Icons_SetDashEngineEnabled(0);
    sobj1 = omGObjAddSprite(ObjectPauseMenu, &D_80388E00_529210);
    spMove(&sobj1->sprite, 125, 97);
    spColor(&sobj1->sprite, 255, 255, 255, var_s2);
    sobj2 = omGObjAddSprite(ObjectPauseMenu, &D_80381B58_521F68);
    spMove(&sobj2->sprite, 149, 103);
    spColor(&sobj2->sprite, 255, 255, 255, var_s2);

    for (i = 59; i != 0; i--) {
        var_s2 += 10;
        if (var_s2 > 255) {
            var_s2 = 255;
        }
        spColor(&sobj1->sprite, 255, 255, 255, var_s2);
        spColor(&sobj2->sprite, 255, 255, 255, var_s2);
        ohWait(1);
    }
    Msg_ShowMessage("You're out of film!", 160, 130, 255, 255, 255, 255, 5, MSG_ALIGN_CENTER);
    auStopBGM();
    auStopAllSounds();
    for (i = 0; i < 16; i++) {
        auSetBGMChannelVolume(0, i, 127);
    }
    auPlaySong(0, 17);
    while (Msg_IsMessagePrinted() == 0) {
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

void processBump(GObj* arg0) {
    s32 i;

    auPlaySound(SOUND_ID_20);
    IsCartStopped = true;
    for (i = 0; i < 180; i++) {
        if (BumpDetector_ProximityLevel == -1) {
            i = 0;
        }
        ohWait(1);
    }
    IsCartStopped = false;
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
        case PLAYER_CMD_BUMP:
            if (D_80382D9C_5231AC == 0) {
                omCreateProcess(omCurrentObject, processBump, 0, 9);
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
            ForceDashEngineDisabled = 1;
            playDashEngineSounds(0);
            break;
        case PLAYER_CMD_10:
            ForceDashEngineDisabled = 1;
            playDashEngineSounds(0);
            break;
    }
}

void updatePlayer(GObj* arg0) {
    cmdProcessCommands(handlePlayerCmd);
}

void updateReticleScreenPos(GObj* arg0) {
    if (!IsPaused && IsInputDisabled != true) {
        if (ABS(StickXValue) > 0.0005f) {
            if (gDirectionIndex > 0) {
                ReticleScreenX += (s32) (5.0f * StickXValue);
            } else {
                ReticleScreenX -= (s32) (5.0f * StickXValue);
            }
            if (ReticleScreenX > 60) {
                ReticleScreenX = 60;
            } else if (ReticleScreenX < -60) {
                ReticleScreenX = -60;
            }
        } else if (ReticleScreenX > 50) {
            ReticleScreenX -= 3;
        } else if (ReticleScreenX < -50) {
            ReticleScreenX += 3;
        }
        ReticleScreenY = StickYAccum * 100.0;
    }
}

void func_80356074_4F6484(GObj* arg0) {
    s32 i = 0;

    while (true) {
        spSetAttribute(&MainCameraReticles[i + 1]->sprite, SP_HIDDEN);
        spClearAttribute(&MainCameraReticles[1 - (i - 1)]->sprite, SP_HIDDEN);
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
        gCamTargetX = (f32) ReticleScreenX / 160.0f;
        gCamTargetY = -(f32) ReticleScreenY / 120.0f;
        gCamTargetZ = 0.99f;
        screenCoorsToWorld(&gCamTargetX, &gCamTargetY, &gCamTargetZ);
        spMove(&sobj->sprite, ReticleScreenX + 152, ReticleScreenY + 112);
        spClearAttribute(&MainCameraReticles[0]->sprite, SP_HIDDEN);
        spSetAttribute(&MainCameraReticles[1]->sprite, SP_HIDDEN);
        spSetAttribute(&MainCameraReticles[2]->sprite, SP_HIDDEN);
        spSetAttribute(&MainCameraReticles[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[4]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[5]->sprite, SP_HIDDEN);
    } else if (gDirectionIndex == -1) {
        spMove(&sobj->sprite, 152, 112);
        spSetAttribute(&MainCameraReticles[0]->sprite, SP_HIDDEN);
        spClearAttribute(&MainCameraReticles[1]->sprite, SP_HIDDEN);
    } else {
        // hide everything
        spSetAttribute(&MainCameraReticles[0]->sprite, SP_HIDDEN);
        spSetAttribute(&MainCameraReticles[1]->sprite, SP_HIDDEN);
        spSetAttribute(&MainCameraReticles[2]->sprite, SP_HIDDEN);
        spSetAttribute(&MainCameraReticles[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[0]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[1]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[2]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[3]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[4]->sprite, SP_HIDDEN);
        spSetAttribute(&D_803AE458_54E868[5]->sprite, SP_HIDDEN);
    }
    cmdProcessCommands(func_80356118_4F6528);
}

GObj* initUI(void (*exitBlockCB)(WorldBlock*), void (*updateMovementCB)(s32, f32), GObjFunc fnUpdateItems, u8 fnUpdateItemsKind, void (*fnCollide)(GObj*, GroundResult*)) {
    GObj* objPlayer;
    GObj* obj;
    DObj* playerDObj;
    SObj* sp40;

    obj = omAddGObj(OBJID_PLAYER, updatePlayer, LINK_PLAYER, 0x80000000);
    omGObjAddDObj(obj, NULL);
    playerDObj = obj->data.dobj;

    PlayerMatrixStore.kinds[0] = 1;
    PlayerMatrixStore.kinds[1] = 2;
    PlayerMatrixStore.kinds[2] = 3;
    playerDObj->unk_4C = &PlayerMatrixStore;
    omDObjAddMtx(playerDObj, MTX_TYPE_62, 0, 0);

    gIdleScript = getIdleScript();
    ProgressFlags = 0;
    if (checkPlayerFlag(PFID_ZOOM_SWITCH) == true) {
        ProgressFlags |= PF_ZOOM_SWITCH;
    }
    if (checkPlayerFlag(PFID_INVERTED_Y) == true) {
        ProgressFlags |= PF_INVERTED_Y;
    }
    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE) == true) {
        ProgressFlags |= PF_HAS_DASH_ENGINE;
    }
    if (checkPlayerFlag(PFID_HAS_APPLE) == true) {
        ProgressFlags |= PF_HAS_APPLE;
    }
    if (checkPlayerFlag(PFID_HAS_PESTER_BALL) == true) {
        ProgressFlags |= PF_HAS_PESTER_BALL;
    }
    if (checkPlayerFlag(PFID_HAS_FLUTE) == true) {
        ProgressFlags |= PF_HAS_FLUTE;
    }
    if (func_800BF864_5C704() >= 4) {
        ProgressFlags |= PF_HAS_FINISHED_TUTORIAL;
    }
    if (gIdleScript != NULL) {
        initIdle(obj);
    }
    if (ProgressFlags & PF_ZOOM_SWITCH) {
        ZoomSwitchMode = 1;
    } else {
        ZoomSwitchMode = 0;
    }
    if (ProgressFlags & PF_INVERTED_Y) {
        IsAxisYInverted = true;
    } else {
        IsAxisYInverted = false;
    }
    if (ProgressFlags & PF_HAS_DASH_ENGINE) {
        IsDashEngineAvailable = true;
    } else {
        IsDashEngineAvailable = false;
    }
    if (ProgressFlags & PF_HAS_FINISHED_TUTORIAL) {
        IsTutorialEnabled = false;
    } else {
        IsTutorialEnabled = true;
    }
    ForceDashEngineDisabled = false;
    D_803AE516_54E926 = false;
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
    TotalSpeedMult = 0.0005f;
    PlayerPos = GET_TRANSFORM(playerDObj)->pos.v;

    obj = ohCreateSprite(OBJID_UI_RETICLE, updateReticleSpritesPos, 0, 0x80000000, renDrawSprite, DL_LINK_1, 0x80000000, -1, &D_80366DF0_507200, 1, updateReticleScreenPos, 9);
    D_80382C38_523048 = obj;
    MainCameraReticles[0] = obj->data.sobj;

    MainCameraReticles[1] = sp40 = omGObjAddSprite(obj, &D_80367580_507990);
    spMove(&sp40->sprite, 143, 103);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);

    MainCameraReticles[2] = sp40 = omGObjAddSprite(obj, &D_80367D10_508120);
    spMove(&sp40->sprite, 143, 103);
    spSetAttribute(&sp40->sprite, SP_HIDDEN);
    spColor(&sp40->sprite, 255, 255, 255, 127);

    MainCameraReticles[3] = sp40 = omGObjAddSprite(obj, &D_80367DC0_5081D0);
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
    BumpDetector_Init();

    gMainCamera->perspMtx.persp.fovy = 55.0f;
    D_803AE478_54E888 = 1.0f;
    D_803AE47C_54E88C = 0.0f;

    obj = omAddGObj(OBJID_UI_PAUSE, ohUpdateDefault, LINK_0, 0x80000000);
    omLinkGObjDL(obj, renDrawSprite, DL_LINK_1, 0x80000000, -1);
    ObjectPauseMenu = obj;

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
            if (IsTutorialEnabled == true) {
                omCreateProcess(objPlayer, updateTutorialMain, 1, 9);
                IsInputDisabled = true;
            } else {
                setPlayerFlag(PFID_HAS_FINISHED_TUTORIAL, 1);
            }
            CameraVibrationAmplitude = 2.0f;
            CameraVibrationSpeed = 25.0f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_CAVE:
            CameraVibrationAmplitude = 40.0f;
            CameraVibrationSpeed = 1.5f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_RAINBOW:
            CameraVibrationAmplitude = 35.0f;
            CameraVibrationSpeed = 1.5f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_VALLEY:
            CameraVibrationAmplitude = 10.0f;
            CameraVibrationSpeed = 2.0f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
        case SCENE_RIVER:
            CameraVibrationAmplitude = 15.0f;
            CameraVibrationSpeed = 1.5f;
            omCreateProcess(objPlayer, vibrateCamera, 0, 9);
            break;
    }
    Msg_InitCamera();
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
    return ProgressFlags;
}

void setPitchLimits(f32 minValue, f32 maxValue) {
    MinPitch = minValue;
    MaxPitch = maxValue;
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
    ohPauseProcessByFunction(ObjectPauseMenu, updatePauseMenu);
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
    ohResumeProcessByFunction(ObjectPauseMenu, updatePauseMenu);
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
    return IsPaused;
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
    if (D_80382C3C_52304C && arg0 == gPreviousPokemonInFocus) {
        gPreviousPokemonInFocus = NULL;
        D_80382C3C_52304C = false;
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
    f32 det = m[0][0] * m[1][1] * m[2][2] + m[1][0] * m[2][1] * m[0][2] + m[2][0] * m[0][1] * m[1][2] - m[0][2] * m[1][1] * m[2][0] - m[1][2] * m[2][1] * m[0][0] - m[2][2] * m[0][1] * m[1][0];

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
    OMCamera* cam = obj->data.cam;
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
    PokemonDetector_ProcessImage();
}

GObj* createMainCameras(s32 bgColor) {
    GObj* camObj;
    OMCamera* cam;

    camObj = ohCreateCamera(OBJID_MAIN_CAMERA, mainCameraUpdate, LINK_0, 0x80000000, mainCameraRender, 5,
                            CAM_MASK_DL_LINK_3 | CAM_MASK_DL_LINK_4 | CAM_MASK_DL_LINK_5, -1, false, 1, NULL, 0, 0);
    if (camObj == NULL) {
        return NULL;
    }
    omCreateProcess(camObj, func_80357FD4_4F83E4, 1, 1);
    cam = camObj->data.cam;
    gMainCamera = cam;
    cam->flags |= CAMERA_FLAG_1 | CAMERA_FLAG_4;
    cam->bgColor = bgColor;
    MainCameraViewport[0] = 14;
    MainCameraViewport[1] = 12;
    MainCameraViewport[2] = 304;
    MainCameraViewport[3] = 232;
    func_80007C20(&cam->vp, MainCameraViewport[0], MainCameraViewport[1], MainCameraViewport[2], MainCameraViewport[3]);
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

    CameraEyePos.x = cam->viewMtx.lookAt.eye.x;
    CameraEyePos.y = cam->viewMtx.lookAt.eye.y;
    CameraEyePos.z = cam->viewMtx.lookAt.eye.z;
    CameraAtPos.x = cam->viewMtx.lookAt.at.x;
    CameraAtPos.y = cam->viewMtx.lookAt.at.y;
    CameraAtPos.z = cam->viewMtx.lookAt.at.z;

    return ohCreateCamera(OBJID_UI_CAMERA, ohUpdateDefault, LINK_0, 0x80000000, renSpriteCameraRender, 3,
                          CAM_MASK_DL_LINK_1, -1, false, 0, NULL, 1, 0);
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
