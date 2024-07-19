#include "common.h"
#include "app_level.h"

s32 BumpDetector_ProximityLevel = 0;
s8 BumpDetector_IsEnabled = 0;
f32 BumpDetector_Thresholds[4] = { 90.0f, 60.0f, 30.0f, 5.0f };
// bss
extern GObj* BumpDetector_Object;

void BumpDetector_Update(GObj* arg0) {
    GObj* pokemonObj;
    u8 unk = 0;

    while (true) {
        f32 minDistance = FLOAT_MAX;
        for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
            Pokemon* pokemon = GET_POKEMON(pokemonObj);
            if (pokemon->tangible && pokemon->flags & POKEMON_FLAG_20) {
                if (minDistance > pokemon->playerDist - pokemon->collisionRadius) {
                    minDistance = pokemon->playerDist - pokemon->collisionRadius;
                }
            }
        }

        if (minDistance > BumpDetector_Thresholds[0]) {
            BumpDetector_ProximityLevel = 0;
        } else if (minDistance > BumpDetector_Thresholds[1]) {
            BumpDetector_ProximityLevel = 1;
        } else if (minDistance > BumpDetector_Thresholds[2]) {
            BumpDetector_ProximityLevel = 2;
        } else if (minDistance > BumpDetector_Thresholds[3]) {
            BumpDetector_ProximityLevel = 3;
        } else {
            BumpDetector_ProximityLevel = -1;
            cmdSendCommand(gObjPlayer, PLAYER_CMD_BUMP, arg0);
        }

        if (BumpDetector_ProximityLevel > 0) {
            unk = 1 - unk;
        }
        ohWait(1);
    }
}

void BumpDetector_Init(void) {
    BumpDetector_ProximityLevel = 0;
    BumpDetector_Object = omAddGObj(OBJID_BUMP_DETECTOR, ohUpdateDefault, LINK_0, 0x80000000);
    omCreateProcess(BumpDetector_Object, BumpDetector_Update, 0, 9);
    BumpDetector_IsEnabled = true;
}

void BumpDetector_Disable(void) {
    BumpDetector_IsEnabled = false;
    ohPauseObjectProcesses(BumpDetector_Object);
}

void BumpDetector_Enable(void) {
    BumpDetector_IsEnabled = true;
    ohResumeObjectProcesses(BumpDetector_Object);
}

void BumpDetector_Delete(s32 arg0) {
    if (BumpDetector_Object != NULL) {
        omDeleteGObj(BumpDetector_Object);
        BumpDetector_Object = NULL;
    }
}
