#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802D1190(GObj* pokemon) {
    Pokemon_SetState(pokemon, NULL);
}

void func_802D11B0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802EC7B8_7C5D48);
}
