#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

typedef struct {
    u16 data[9];
} Unk6CBA74;

extern AnimationHeader D_802E3800_6CB5E0;
extern AnimationHeader D_802E3814_6CB5F4;
extern AnimationHeader D_802E3828_6CB608;
extern AnimationHeader D_802E383C_6CB61C;
extern AnimationHeader D_802E3850_6CB630;
extern AnimationHeader D_802E3864_6CB644;
extern AnimationHeader D_802E3878_6CB658;
extern AnimationHeader D_802E388C_6CB66C;
extern AnimationHeader D_802E38A0_6CB680;
extern AnimationHeader D_802E38B4_6CB694;
extern AnimationHeader D_802E38C8_6CB6A8;
extern AnimationHeader D_802E38DC_6CB6BC;
extern AnimationHeader D_802E38F0_6CB6D0;
extern AnimationHeader D_802E3904_6CB6E4;
extern AnimationHeader D_802E3918_6CB6F8;
extern AnimationHeader D_802E392C_6CB70C;
extern AnimationHeader D_802E3940_6CB720;
extern AnimationHeader D_802E3954_6CB734;
extern AnimationHeader D_802E3968_6CB748;
extern AnimationHeader D_802E397C_6CB75C;
extern AnimationHeader D_802E3990_6CB770;
extern AnimationHeader D_802E39A4_6CB784;
extern InteractionHandler D_802E39B8_6CB798[];
extern InteractionHandler D_802E39E8_6CB7C8[];
extern InteractionHandler D_802E3A38_6CB818[];
extern InteractionHandler D_802E3A88_6CB868[];
extern InteractionHandler D_802E3AD8_6CB8B8[];
extern InteractionHandler D_802E3B28_6CB908[];
extern InteractionHandler D_802E3B78_6CB958[];
extern RandomState D_802E3BC8_6CB9A8;
extern RandomState D_802E3BE8_6CB9C8;
extern RandomState D_802E3C08_6CB9E8;
extern InteractionHandler3 D_802E3C28_6CBA08;
extern InteractionHandler3 D_802E3C58_6CBA38;
extern Vec3f D_802E3C88_6CBA68;
extern Unk6CBA74 D_802E3C94_6CBA74;
extern PokemonInitData D_802E3CBC_6CBA9C;
extern GObj* D_802E4B00_6CC8E0;
extern GObj* D_8033F5C8_7273A8;

void func_802DD2BC_6C509C(GObj*);
void func_802DD398_6C5178(GObj*);
void func_802DD4AC_6C528C(GObj*);
void func_802DD53C_6C531C(GObj*);
void func_802DD6F0_6C54D0(GObj*);
void func_802DD7CC_6C55AC(GObj*);
void func_802DD8A8_6C5688(GObj*);
void func_802DDAA0_6C5880(GObj*);
void func_802DDAEC_6C58CC(GObj*);
void func_802DDB70_6C5950(GObj*);
void func_802DDC28_6C5A08(GObj*);
void func_802DDC94_6C5A74(GObj*);
void func_802DDCB8_6C5A98(GObj*);
void func_802DDF54_6C5D34(GObj*);
void func_802DDFA0_6C5D80(GObj*);
void func_802DE024_6C5E04(GObj*);
void func_802DE0DC_6C5EBC(GObj*);
void func_802DE100_6C5EE0(GObj*);
void func_802DE39C_6C617C(GObj*);
void func_802DE3E8_6C61C8(GObj*);
void func_802DE46C_6C624C(GObj*);
void func_802DE524_6C6304(GObj*);
void func_802DE870_6C6650(GObj*);

void func_802DD0E0_6C4EC0(GObj* obj) {
    s32 temp_a2;
    DObj* model = obj->data.dobj;
    Mtx3Float* position = &GET_TRANSFORM(model)->pos;
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->pos1.x = position->v.x;
    pokemon->pos1.y = position->v.y;
    pokemon->pos1.z = position->v.z;
    pokemon->flags |= POKEMON_FLAG_8;

    switch (pokemon->behavior) {
        case 1:
            Pokemon_SetAnimation(obj, &D_802E392C_6CB70C);
            break;
        case 2:
            Pokemon_SetAnimation(obj, &D_802E388C_6CB66C);
            break;
        default:
            Pokemon_SetAnimation(obj, &D_802E388C_6CB66C);
            break;
    }

    pokemon->transitionGraph = D_802E39B8_6CB798;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DD1D4_6C4FB4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (Pokemon_GetDistance(obj, pokemon->interactionTarget) < 1000.0f) {
        switch (pokemon->behavior) {
            case 1:
                cmdSendCommandToLink(3, 0x1F, obj);
                Pokemon_SetState(obj, func_802DD2BC_6C509C);
                break;
            case 2:
                cmdSendCommandToLink(3, 0x1E, obj);
                Pokemon_SetState(obj, func_802DD398_6C5178);
                break;
            default:
                cmdSendCommandToLink(3, 0x20, obj);
                Pokemon_SetState(obj, func_802DD398_6C5178);
                break;
        }
    }
    Pokemon_SetState(obj, func_802DD0E0_6C4EC0);
}

POKEMON_FUNC(func_802DD2BC_6C509C)
    InteractionHandler3 sp20 = D_802E3C28_6CBA08;

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802E39A4_6CB784);
    SHOW_POKEMON();
    Pokemon_StartAuxProc(obj, func_802DD53C_6C531C);
    Pokemon_StartPathProc(obj, func_802DD4AC_6C528C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DDC94_6C5A74);
}

POKEMON_FUNC(func_802DD398_6C5178)
    InteractionHandler3 sp20 = D_802E3C58_6CBA38;
    s32 blockCount;
    f32 blockPart;

    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802E3904_6CB6E4);
    SHOW_POKEMON();
    Pokemon_StartAuxProc(obj, func_802DD53C_6C531C);
    Pokemon_StartPathProc(obj, func_802DD4AC_6C528C);
    if (pokemon->behavior == 2) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount == 4) {
            Pokemon_SetState(obj, func_802DE524_6C6304);
        }
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DE0DC_6C5EBC);
}

void func_802DD4AC_6C528C(GObj* obj) {
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    UNUSED s32 pad[1];
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 prevY = transform->pos.v.y;

    Pokemon_ResetPathPos(obj);
    transform->pos.v.y = prevY;
    Pokemon_FollowPath(obj, 0, 1.0f, 0.1f, 0.0f, MOVEMENT_FLAG_FIXED_HEIGHT);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DD53C_6C531C(GObj* obj) {
    UNUSED s32 pad[2];
    f32 x;
    f32 z;
    Vec3f pos;
    GroundResult ground;
    f32 new_var;
    WorldBlockDescriptor* descriptor;
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 yTemp;
    f32 yDiff;
    f32 temp_f24_2;
    f32 temp_f26;
    f32 var_f20;

    pos = D_802E3C88_6CBA68;
    pokemon->miscVars[0].field1 = false;
    descriptor = getCurrentWorldBlock()->descriptor;

    x = -(descriptor->worldPos.x * 100.0f);
    z = -(descriptor->worldPos.z * 100.0f);
    yTemp = transform->pos.v.y;

    GetInterpolatedPosition(&pos, pokemon->path, 0.99999f);

    x += pos.x * 100.0f;
    z += pos.z * 100.0f;

    getGroundAt(x, z, &ground);
    yDiff = yTemp - ground.height;
    temp_f26 = yDiff + 50.0f;
    yTemp = yDiff / temp_f26;
    var_f20 = asinf(yTemp);
    new_var = (1.0f / pokemon->path->duration) * 0.1f;
    temp_f24_2 = (PI - var_f20) / (1 / new_var);

    while (var_f20 < PI && !pokemon->miscVars[0].field1) {
        transform->pos.v.y += temp_f26 * (__sinf(var_f20) - __sinf(var_f20 - temp_f24_2));
        var_f20 += temp_f24_2;
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

void func_802DD6F0_6C54D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3800_6CB5E0);
    pokemon->transitionGraph = D_802E39E8_6CB7C8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E3BC8_6CB9A8);
}

void func_802DD74C_6C552C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3814_6CB5F4);
    pokemon->pokemonLoopTarget = 3;
    Pokemon_StartPathProc(obj, func_802DD7CC_6C55AC);
    pokemon->transitionGraph = D_802E39E8_6CB7C8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E3BC8_6CB9A8);
}

void func_802DD7CC_6C55AC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 50.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DD828_6C5608(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3828_6CB608);
    pokemon->pokemonLoopTarget = 3;
    Pokemon_StartPathProc(obj, func_802DD8A8_6C5688);
    pokemon->transitionGraph = D_802E39E8_6CB7C8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E3BC8_6CB9A8);
}

void func_802DD8A8_6C5688(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 100.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DD904_6C56E4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E383C_6CB61C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DD6F0_6C54D0);
}

void func_802DD96C_6C574C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E383C_6CB61C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E39E8_6CB7C8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DD6F0_6C54D0);
}

void func_802DD9DC_6C57BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3850_6CB630);
    Pokemon_StartPathProc(obj, func_802DDAA0_6C5880);
    pokemon->transitionGraph = D_802E3A38_6CB818;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_802DDAEC_6C58CC);
    pokemon->transitionGraph = D_802E3A38_6CB818;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802DD6F0_6C54D0);
    }
    Pokemon_SetState(obj, func_802DDB70_6C5950);
}

void func_802DDAA0_6C5880(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DDAEC_6C58CC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3828_6CB608);
    pokemon->hSpeed = 100.0f;
    Pokemon_RunToTarget(obj, 80.0f, 0.1f, 3);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DDB70_6C5950(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802DD6F0_6C54D0);
    }
    Pokemon_SetAnimation(obj, &D_802E3864_6CB644);
    Pokemon_StartPathProc(obj, func_802DDC28_6C5A08);
    pokemon->transitionGraph = D_802E3A38_6CB818;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802DDB70_6C5950);
    }
    Pokemon_SetState(obj, func_802DD6F0_6C54D0);
}

void func_802DDC28_6C5A08(GObj* obj) {
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

void func_802DDC94_6C5A74(GObj* obj) {
    Pokemon_SetState(obj, func_802DDCB8_6C5A98);
}

void func_802DDCB8_6C5A98(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3940_6CB720);
    pokemon->pokemonLoopTarget = 3;
    Pokemon_StartPathProc(obj, func_802DD7CC_6C55AC);
    pokemon->transitionGraph = D_802E3B28_6CB908;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E3BE8_6CB9C8);
}

void func_802DDD38_6C5B18(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3954_6CB734);
    pokemon->pokemonLoopTarget = 3;
    Pokemon_StartPathProc(obj, func_802DD8A8_6C5688);
    pokemon->transitionGraph = D_802E3B28_6CB908;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E3BE8_6CB9C8);
}

void func_802DDDB8_6C5B98(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3878_6CB658);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DD6F0_6C54D0);
}

void func_802DDE20_6C5C00(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3968_6CB748);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3B28_6CB908;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DDC94_6C5A74);
}

void func_802DDE90_6C5C70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E397C_6CB75C);
    Pokemon_StartPathProc(obj, func_802DDF54_6C5D34);
    pokemon->transitionGraph = D_802E3A88_6CB868;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_802DDFA0_6C5D80);
    pokemon->transitionGraph = D_802E3A88_6CB868;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802DDC94_6C5A74);
    }
    Pokemon_SetState(obj, func_802DE024_6C5E04);
}

void func_802DDF54_6C5D34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DDFA0_6C5D80(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3954_6CB734);
    pokemon->hSpeed = 100.0f;
    Pokemon_RunToTarget(obj, 80.0f, 0.1f, 3);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DE024_6C5E04(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802DDC94_6C5A74);
    }
    Pokemon_StartPathProc(obj, func_802DDC28_6C5A08);
    Pokemon_SetAnimation(obj, &D_802E3990_6CB770);
    pokemon->transitionGraph = D_802E3A88_6CB868;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802DE024_6C5E04);
    }
    Pokemon_SetState(obj, func_802DDC94_6C5A74);
}

void func_802DE0DC_6C5EBC(GObj* obj) {
    Pokemon_SetState(obj, func_802DE100_6C5EE0);
}

void func_802DE100_6C5EE0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E38A0_6CB680);
    pokemon->pokemonLoopTarget = 3;
    Pokemon_StartPathProc(obj, func_802DD7CC_6C55AC);
    pokemon->transitionGraph = D_802E3B78_6CB958;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E3C08_6CB9E8);
}

void func_802DE180_6C5F60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E38B4_6CB694);
    pokemon->pokemonLoopTarget = 3;
    Pokemon_StartPathProc(obj, func_802DD8A8_6C5688);
    pokemon->transitionGraph = D_802E3B78_6CB958;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E3C08_6CB9E8);
}

void func_802DE200_6C5FE0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3918_6CB6F8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DD6F0_6C54D0);
}

void func_802DE268_6C6048(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E38C8_6CB6A8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E3B78_6CB958;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DE0DC_6C5EBC);
}

void func_802DE2D8_6C60B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E38DC_6CB6BC);
    Pokemon_StartPathProc(obj, func_802DE39C_6C617C);
    pokemon->transitionGraph = D_802E3AD8_6CB8B8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_802DE3E8_6C61C8);
    pokemon->transitionGraph = D_802E3AD8_6CB8B8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802DE0DC_6C5EBC);
    }
    Pokemon_SetState(obj, func_802DE46C_6C624C);
}

void func_802DE39C_6C617C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DE3E8_6C61C8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E38B4_6CB694);
    pokemon->hSpeed = 100.0f;
    Pokemon_RunToTarget(obj, 80.0f, 0.1f, 3);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DE46C_6C624C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802DE0DC_6C5EBC);
    }
    Pokemon_StartPathProc(obj, func_802DDC28_6C5A08);
    Pokemon_SetAnimation(obj, &D_802E38F0_6CB6D0);
    pokemon->transitionGraph = D_802E3AD8_6CB8B8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802DE46C_6C624C);
    }
    Pokemon_SetState(obj, func_802DE0DC_6C5EBC);
}

void func_802DE524_6C6304(GObj* obj) {
    UNUSED s32 pad[1];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);
    Mtx3Float* position = &transform->pos;
    WorldBlock* block;
    Vec3f* point;
    InterpData* path;
    s32 i;
    f32 x, y, z;
    Unk6CBA74 sp54 = D_802E3C94_6CBA74;

    pokemon->counter = 30;
    pokemon->transitionGraph = NULL;
    pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->miscVars[0].field1 = true;
    Pokemon_RemovePokemons(sp54.data);
    cmdSendCommand(gObjPlayer, 8, obj);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    func_80357150_4F7560(D_8033F5C8_7273A8);

    path = GET_POKEMON(D_8033F5C8_7273A8)->path;

    for (i = 1; i < path->numPoints; i++) {
        do {
            // TODO required to match
        } while (0);
        block = getCurrentWorldBlock();
        point = path->points;

        gMainCamera->viewMtx.lookAt.at.x = -(block->descriptor->worldPos.x * 100.0f);
        gMainCamera->viewMtx.lookAt.at.y = -(block->descriptor->worldPos.y * 100.0f);
        gMainCamera->viewMtx.lookAt.at.z = -(block->descriptor->worldPos.z * 100.0f);

        gMainCamera->viewMtx.lookAt.at.x += point->x * 100.0f;
        gMainCamera->viewMtx.lookAt.at.y += point->y * 100.0f;
        gMainCamera->viewMtx.lookAt.at.z += point->z * 100.0f;

        point = &path->points[i];

        x = -(block->descriptor->worldPos.x * 100.0f);
        y = -(block->descriptor->worldPos.y * 100.0f);
        z = -(block->descriptor->worldPos.z * 100.0f);
        x += point->x * 100.0f;
        y += point->y * 100.0f;
        z += point->z * 100.0f;
        gMainCamera->viewMtx.lookAt.eye.x = x;
        gMainCamera->viewMtx.lookAt.eye.y = y;
        gMainCamera->viewMtx.lookAt.eye.z = z;

        position->v.x = pokemon->pos1.x;
        position->v.y = pokemon->pos1.y;
        position->v.z = pokemon->pos1.z;

        Pokemon_ForceAnimation(obj, &D_802E3904_6CB6E4);
        Pokemon_StartAuxProc(obj, func_802DD53C_6C531C);
        Pokemon_StartPathProc(obj, func_802DD4AC_6C528C);

        if (i + 1 != path->numPoints) {
            pokemon->counter = 30;
            pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
            pokemon->transitionGraph = NULL;
            Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
            pokemon->miscVars[0].field1 = true;
        } else {
            break;
        }
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    cmdSendCommand(D_8033F5C8_7273A8, 0x21, obj);
    if (i) {
        // TODO required to match
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DE870_6C6650);
}

void func_802DE870_6C6650(GObj* obj) {
    if (D_802E4B00_6CC8E0 != NULL) {
        ohResumeObjectProcesses(D_802E4B00_6CC8E0);
        cmdSendCommandToLink(3, 0x2B, obj);
    }
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DE8BC_6C669C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802E3CBC_6CBA9C);
}
