#include "valley.h"

typedef struct SomeC {
    /* 0x00 */ char* unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[0x2];
    /* 0x08 */ s32 unk_08;
} SomeC; // size = 0xC

extern AnimationHeader D_802D4168_7AD6F8;
extern AnimationHeader D_802D417C_7AD70C;
extern AnimationHeader D_802D4190_7AD720;
extern GObj* D_802D41A4_7AD734;
extern InteractionHandler D_802D41A8_7AD738[];
extern Vec3f D_802D41C8_7AD758;
extern PokemonInitData D_802D41E8_7AD778;
extern AnimationHeader D_802D4220_7AD7B0;
extern Sprite D_802E6B18_7C00A8;
extern Sprite D_802EC4D8_7C5A68;
extern SomeC D_802EC51C_7C5AAC[];
extern SomeC D_802EC5D0_7C5B60[];
extern s32 D_802EC5E8_7C5B78;
extern s32 D_802EC5EC_7C5B7C;
extern s32 D_802EC5F0_7C5B80;
extern s32 D_802EC608_7C5B98;
extern Sprite* D_802EC620_7C5BB0[6];
extern f32 D_802EC638_7C5BC8[3];
extern GObj* D_802EC644_7C5BD4;
extern OMCamera* D_802EC648_7C5BD8;
extern s32 D_802EC64C_7C5BDC;
extern f32 D_802EC650_7C5BE0;
extern f32 D_802EC654_7C5BE4;
extern InteractionHandler D_802EC658_7C5BE8[];
extern PokemonInitData D_802EC68C_7C5C1C;

extern u8 D_8034C8C8_825E58;
extern char D_8034E080_827610[20]; // player name
extern SObj* D_8034E0A0_827630;
extern SObj* D_8034E0A4_827634;
extern GObj* D_8034E0A8_827638;
extern s32 D_8034E0AC_82763C;
extern u8 D_8034E0B0_827640;
extern u8 D_8034E0B1_827641;

void func_802CF864_7A8DF4(GObj*);
void func_802D0344_7A98D4(GObj*);

void func_802CF840_7A8DD0(GObj* obj) {
    Pokemon_SetState(obj, func_802CF864_7A8DF4);
}

POKEMON_FUNC(func_802CF864_7A8DF4)
    Pokemon_SetAnimation(obj, &D_802D4168_7AD6F8);
    pokemon->transitionGraph = D_802D41A8_7AD738;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CF8BC_7A8E4C)
    Vec3f sp54;
    Vec3f sp48 = D_802D41C8_7AD758;
    DObj* temp_s1 = pokemon->interactionTarget->data.dobj;
    f32 something = FLOAT_MAX;

    while (something > 100.0f) {
        func_800A5E98(&sp54, &sp48, temp_s1);
        sp54.x -= position->v.x;
        sp54.z -= position->v.z;
        something = SQ(sp54.x) + SQ(sp54.z);
        ohWait(1);
    }
    Pokemon_SetAnimation(obj, &D_802D4190_7AD720);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D417C_7AD70C);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802CFA00_7A8F90(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802D41A4_7AD734 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802D41E8_7AD778);

    return D_802D41A4_7AD734;
}

void func_802CFA40_7A8FD0(GObj*);
#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802CFA40_7A8FD0.s")

void func_802CFC6C_7A91FC(GObj* arg0) {
    s32 idx = 0;
    s32 waitFrames;

    while (true) {
        switch (D_802EC5E8_7C5B78) {
            case 0:
                D_8034E0A4_827634->sprite = *D_802EC620_7C5BB0[idx + 3];
                waitFrames = 8;
                break;
            case 1:
                D_8034E0A4_827634->sprite = *D_802EC620_7C5BB0[3];
                waitFrames = 1;
                break;
            case 2:
                D_8034E0A4_827634->sprite = *D_802EC620_7C5BB0[idx];
                waitFrames = 8;
                break;
            case 3:
                D_8034E0A4_827634->sprite = *D_802EC620_7C5BB0[0];
                waitFrames = 1;
                break;
        }
        spX2Move(&D_8034E0A4_827634->sprite, 140, 84);

        idx++;
        if (idx >= ARRAY_COUNT(D_802EC620_7C5BB0) - 3) {
            idx = 0;
        }

        ohWait(waitFrames);
    }
}

void func_802CFE8C_7A941C(void) {
    s32 i;
    GObj* gobj;
    SObj* sprite;
    char msg[0x100];
    char* playerName;
    char* it;

    gobj = omAddGObj(0x1F, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, renDrawSprite, 1, 0x80000000, -1);
    spX2Move(&omGObjAddSprite(gobj, &D_802E6B18_7C00A8)->sprite, 100, 34);
    D_8034E0A0_827630 = omGObjAddSprite(gobj, NULL);
    omCreateProcess(gobj, func_802CFA40_7A8FD0, 0, 1);
    D_8034E0A4_827634 = omGObjAddSprite(gobj, NULL);
    omCreateProcess(gobj, func_802CFC6C_7A91FC, 0, 1);
    sprite = omGObjAddSprite(gobj, &D_802EC4D8_7C5A68);
    spX2Move(&sprite->sprite, 51, 158);
    spScale(&sprite->sprite, 17.0f, 5.0f);
    spColor(&sprite->sprite, 0, 0, 0, 127);

    it = D_8034E080_827610;
    playerName = getPlayerName();

    i = 20;
    while (i > 0) {
        *it++ = *playerName++;
        i--;
    }
    *it = 0;

    Msg_SetInteractive();

    for (i = 0; D_802EC51C_7C5AAC[i].unk_00 != NULL; i++) {
    start:
        sprintf(msg, D_802EC51C_7C5AAC[i].unk_00, D_802EC51C_7C5AAC[i].unk_08);
        Msg_ShowMessage(msg, 62, 169, 255, 255, 255, 255, 4, 0);

        while (true) {
            ohWait(1);

            if (Msg_IsMessagePrinted()) {
                if (D_802EC51C_7C5AAC[i].unk_05 == 0) {
                    D_802EC5E8_7C5B78 = 1;
                    D_802EC5EC_7C5B7C = 0;
                } else {
                    D_802EC5E8_7C5B78 = 3;
                    D_802EC5EC_7C5B7C = 1;
                }

                if (gContInputPressedButtons & B_BUTTON) {
                    auPlaySound(SOUND_ID_77);
                    break;
                } else if (gContInputPressedButtons & A_BUTTON) {
                    if (D_802EC51C_7C5AAC[i].unk_04 == 1) {
                        i = 2;
                        auPlaySound(SOUND_ID_83);
                        goto start;
                    } else {
                        auPlaySound(SOUND_ID_77);
                    }
                    break;
                }
            } else {
                if (D_802EC51C_7C5AAC[i].unk_05 == 0) {
                    D_802EC5E8_7C5B78 = 0;
                    D_802EC5EC_7C5B7C = 0;
                } else {
                    D_802EC5E8_7C5B78 = 2;
                    D_802EC5EC_7C5B7C = 1;
                }
            }
        }
    }

    Msg_Reset();
    Msg_SetNonInteractive();
}

#ifdef NON_MATCHING
void func_802D017C_7A970C(void) {
    UNUSED s32 pad[2];
    s32 i;
    char message[0x100];
    GObj* gobj;
    SObj* sprite;
    s32 j;

    gobj = omAddGObj(0x1F, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, renDrawSprite, 1, 0x80000000, -1);
    sprite = omGObjAddSprite(gobj, &D_802EC4D8_7C5A68);
    spX2Move(&sprite->sprite, 51, 158);
    spScale(&sprite->sprite, 17.0f, 5.0f);
    spColor(&sprite->sprite, 0, 0, 0, 0x7F);
    Msg_SetInteractive();

    for (i = 0; D_802EC5D0_7C5B60[i].unk_00 != NULL; i++) {
        j = 0;
        sprintf(message, D_802EC5D0_7C5B60[i].unk_00, D_802EC5D0_7C5B60[i].unk_08);
        Msg_ShowMessage(message, 62, 169, 255, 255, 255, 255, 4, 0);

        while (true) {
            ohWait(1);
            if (!Msg_IsMessagePrinted()) {
                continue;
            }
            if (gContInputPressedButtons & (B_BUTTON | A_BUTTON)) {
                auPlaySound(SOUND_ID_77);
                break;
            }

            j += 1;
            if (((j < 0xB5) ^ 1) != 0) {
                break;
            }
        }
    }

    Msg_Reset();
    Msg_SetNonInteractive();
}
#else
void func_802D017C_7A970C(void);
#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D017C_7A970C.s")
#endif

void func_802D0320_7A98B0(GObj* obj) {
    Pokemon_SetState(obj, func_802D0344_7A98D4);
}

POKEMON_FUNC(func_802D0344_7A98D4)
    Pokemon_SetAnimation(obj, &D_802D4220_7AD7B0);
    pokemon->transitionGraph = D_802EC658_7C5BE8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802D039C_7A992C(f32 speed) {
    if (D_802EC648_7C5BD8 != NULL) {
        D_802EC648_7C5BD8->animSpeed = speed;
    }
    PlayerModel_SetAnimationSpeed(speed);
}

void func_802D03D0_7A9960(f32 skipFrames) {
    if (D_802EC648_7C5BD8 != NULL) {
        animSetCameraAnimation(D_802EC648_7C5BD8, &D_801204A0, skipFrames);
    }
    PlayerModel_ChangeAnimation(&D_8011DA60, &D_8011EA20, skipFrames);
}

void func_802D0420_7A99B0(DObj* arg0, s32 arg1, f32 arg2) {
    s32 trunc;

    switch (arg1) {
        case -2:
        case -1:
            D_802EC64C_7C5BDC = 1;
            break;
        case 4:
            if (arg2 >= 0.0f) {
                D_802EC650_7C5BE0 = arg2;
            }
            break;
        case 5:
            trunc = arg2;
            if (trunc >= 0 && trunc < ARRAY_COUNT(D_802EC638_7C5BC8)) {
                D_802EC654_7C5BE4 = D_802EC638_7C5BC8[trunc];
            }
            break;
    }
}

void func_802D04BC_7A9A4C(DObj* arg0, s32 arg1, f32 arg2) {
    switch (arg1) {
        case 0:
        case 1:
            break;
    }
}

#ifdef NON_MATCHING
void func_802D04CC_7A9A5C(GObj* arg0) {
    func_800AB9A4();
    D_8034E0AC_82763C = 0;

    while (true) {
        switch (D_8034E0AC_82763C) {
            case 1:
                D_8034E0B0_827640 = auPlaySoundWithParams(SOUND_ID_36, 0x7000, 0x40, 1.0f, 30);
                break;
            case 200:
                auStopBGM();
                auPlaySoundWithParams(0x25, 0x6800, 0x40, 0.5f, 10);
                auStopSound(D_8034E0B0_827640);
                D_8034E0B1_827641 = auPlaySoundWithParams(SOUND_ID_33, 0x2800, 0x40, 1.0f, 30);
                break;
            case 210:
                func_800AB700(D_8034E0B1_827641, 0x2800, 0x5000, 90);
                auSetBGMVolume(1, 0x7F00);
                auPlaySong(1, SONG_ID_20);
                break;
            case 410:
                func_800AB700(D_8034E0B1_827641, 0x5000, 0x2800, 240);
                break;
            case 480:
                auSetBGMVolume(0, 0x7F00);
                auPlaySong(0, SONG_ID_19);
                break;
            case 720:
            case 900:
                break;
            case 830:
                func_800AB700(D_8034E0B1_827641, 0x2800, 0x1800, 60);
                func_800AB700(D_8034C8C8_825E58, 0x3800, 0x1C00, 60);
                auSetBGMVolumeSmooth(1, 0x6000, 60);
                break;
        }

        if (D_802EC64C_7C5BDC == 1) {
            if (checkPlayerFlag(PFID_HAS_DASH_ENGINE) == 1) {
                auSetBGMVolumeSmooth(0, 0, 120);
            }
            auSetBGMVolumeSmooth(1, 0, 120);
        }
        ohWait(1);
        D_8034E0AC_82763C++;
    }
}
#else
void func_802D04CC_7A9A5C(GObj* arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D04CC_7A9A5C.s")
#endif

void func_802D0700_7A9C90(void) {
    D_8034E0A8_827638 = omAddGObj(0xE, ohUpdateDefault, 0, 0x80000000);
    omCreateProcess(D_8034E0A8_827638, func_802D04CC_7A9A5C, 0, 1);
}

void func_802D0754_7A9CE4(s32 arg0) {
    u32 soundID = 0;

    switch (arg0) {
        case 0x42:
            soundID = SOUND_ID_162;
            break;
        case 0x51:
            soundID = SOUND_ID_174;
            break;
    }
    if (soundID != 0) {
        auPlaySoundWithParams(soundID, 0x7FFF, 0x40, 0.75f, 0);
    }
}

void func_802D07BC_7A9D4C(GObj* obj) {
    UNUSED s32 pad[6];
    f32 sp38;
    GObj* camObj;
    GObj* playerObj;
    f32 var_f20;
    s32 i;

    auSetBGMVolumeSmooth(0, 0, 240);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    cmdSendCommand(gObjPlayer, 0xA, NULL);
    setSkyBoxAnimationSpeed(D_80100730);
    D_802EC648_7C5BD8 = getMainCamera();
    camObj = D_802EC648_7C5BD8->obj;
    ohPauseObjectProcesses(camObj);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    playerObj = PlayerModel_Init();
    obj->fnAnimCallback = func_802D04BC_7A9A4C;
    animSetModelAnimationSpeed(obj, 0.5f);
    func_802D03D0_7A9960(0.0f);
    func_802D039C_7A992C(0.5f);
    func_802D0700_7A9C90();
    D_802EC64C_7C5BDC = 0;
    playerObj->fnAnimCallback = func_802D0420_7A99B0;

    for (i = 0; D_802EC64C_7C5BDC == 0 && i != 10800; i++) {
        if (D_802EC650_7C5BE0 >= 0.0f && D_802EC654_7C5BE4 >= 0.0f) {
            func_802D039C_7A992C(3.0f);
            ohWait(1);
            func_802D039C_7A992C(D_802EC654_7C5BE4);
            ohWait(1);
            D_802EC654_7C5BE4 = -1.0f;
            D_802EC650_7C5BE0 = D_802EC654_7C5BE4;
        }
        ohWait(1);
    }

    Msg_SetSpecialHandler((void (*)(u8)) func_802D0754_7A9CE4);
    if (!checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
        func_802CFE8C_7A941C();
        func_800AAED0(0x800);
        setPlayerFlag(5, 1);
    } else {
        func_802D017C_7A970C();
    }
    Msg_SetSpecialHandler(NULL);
    var_f20 = 1.0f;
    func_800A7F68(10, 1);
    func_800A7F40(0.0f, 0.0f, 0.0f, 1.0f);
    auSetBGMVolumeSmooth(1, 0, 60);
    ohWait(1);
    sp38 = 60.0f;
    while (func_800A7460() == 1) {
        var_f20 += -(1.0f / sp38);
        auSetSoundGlobalVolume((u8) (127.0f * var_f20));
        ohWait(1);
    }
    auSetSoundGlobalVolume(0);
    cmdSendCommand(gObjPlayer, 7, NULL);
    omEndProcess(NULL);
    omDeleteGObj(D_8034E0A8_827638);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802D0B3C_7AA0CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802EC644_7C5BD4 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802EC68C_7C5C1C);

    return D_802EC644_7C5BD4;
}
