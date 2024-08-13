#include "volcano/volcano.h"

extern UnkEC64Arg3 D_8032A688[];
extern Texture** D_80323FD0[];

extern AnimCmd* D_80143E20[];
extern AnimCmd* D_801429B0[];
extern AnimCmd* D_80143110[];
extern AnimCmd* D_80141CF0[];
extern AnimCmd* D_80142370[];

extern AnimCmd** D_8014C300[];
extern AnimCmd** D_80147770[];
extern AnimCmd** D_801491B0[];
extern AnimCmd** D_80144470[];
extern AnimCmd** D_80145D30[];

void func_802DE26C_72F46C(GObj*);
void func_802DDF00_72F100(GObj*);
void func_802DDF7C_72F17C(GObj*);
void func_802DE1F0_72F3F0(GObj*);
void func_802DE1B0_72F3B0(GObj*);
void func_802DE144_72F344(GObj*);
void func_802DE0DC_72F2DC(GObj*);

s32 D_802E30C0_7342C0[] = { 0, SOUND_ID_120 };
s32 D_802E30C8_7342C8[] = { 0, SOUND_ID_120 };
s32 D_802E30D0_7342D0[] = { SOUND_ID_189, SOUND_ID_139, SOUND_ID_120 };
s32 D_802E30DC_7342DC[] = { SOUND_ID_189 };
s32 D_802E30E0_7342E0[] = { SOUND_ID_189, SOUND_ID_120 };

AnimationHeader D_802E30E8_7342E8 = {
    0.6,
    60,
    D_80143E20,
    D_8014C300,
    D_802E30C0_7342C0
};

AnimationHeader D_802E30FC_7342FC = {
    0.6,
    60,
    D_801429B0,
    D_80147770,
    D_802E30C8_7342C8
};

AnimationHeader D_802E3110_734310 = {
    0.6,
    117,
    D_80143110,
    D_801491B0,
    D_802E30D0_7342D0
};

AnimationHeader D_802E3124_734324 = {
    0.6,
    57,
    D_80141CF0,
    D_80144470,
    D_802E30DC_7342DC
};

AnimationHeader D_802E3138_734338 = {
    0.6,
    60,
    D_80142370,
    D_80145D30,
    D_802E30E0_7342E0
};

InteractionHandler D_802E314C_73434C[] = {
    { POKEMON_CMD_30, func_802DDF7C_72F17C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E317C_73437C[] = {
    { POKEMON_CMD_16, func_802DE1F0_72F3F0, 4000, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E319C_73439C = {
    &D_802E3124_734324,
    func_802DDF00_72F100,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E31B0_7343B0 = {
    D_8032A688,
    D_80323FD0,
    func_802DE26C_72F46C,
    &D_802E319C_73439C,
    { 1.5, 1.5, 1.5 },
    { 0, 3.5, 0 },
    87,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802DDF00_72F100(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802DE1B0_72F3B0);
    }
    pokemon->transitionGraph = D_802E314C_73434C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DDF7C_72F17C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    DObj* targetModel = pokemon->interactionTarget->data.dobj;

    GET_TRANSFORM(model)->pos.v.x = GET_TRANSFORM(targetModel)->pos.v.x;
    GET_TRANSFORM(model)->pos.v.y = GET_TRANSFORM(targetModel)->pos.v.y;
    GET_TRANSFORM(model)->pos.v.z = GET_TRANSFORM(targetModel)->pos.v.z;
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_802E3124_734324);
    Pokemon_StartPathProc(obj, func_802DE144_72F344);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E30E8_7342E8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802E3110_734310);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802E30FC_7342FC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetAnimation(obj, &D_802E3138_734338);
    Pokemon_StartPathProc(obj, func_802DE0DC_72F2DC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

// clang-format off
void func_802DE0DC_72F2DC(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
// clang-format on
    pokemon->hSpeed = pokemon->jumpVel = 400.0f;
    Pokemon_Jump(obj, 5000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DE144_72F344(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DE1B0_72F3B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = D_802E317C_73437C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DE1F0_72F3F0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &D_802E30FC_7342FC);
    Pokemon_StartPathProc(obj, func_802DE144_72F344);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DE26C_72F46C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_2CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

    renderPokemonModelTypeI(obj);

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
}

GObj* func_802DE34C_72F54C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E31B0_7343B0);
}
