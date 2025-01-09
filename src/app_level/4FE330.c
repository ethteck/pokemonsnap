#include "common.h"
#include "world/world.h"
#include "app_level.h"
#include "app_render/app_render.h"

extern AnimCmd* D_800EAFB0[];
extern AnimCmd** D_800EB0C0[];
extern UnkEC64Arg3 D_800EB430[];
extern Texture** D_800EB510[];

void func_8035DF20_4FE330(GObj* obj);
GObj* func_8035E0D4_4FE4E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* arg3, ObjectSpawn* arg4);

AnimationHeader D_80388310_528720 = {
    0.9f,
    60.0f,
    D_800EAFB0,
    D_800EB0C0,
    NULL
};

InteractionHandler D_80388324_528734[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_80388334_528744 = {
    &D_80388310_528720,
    func_8035DF20_4FE330,
    0,
    { 0, 0, 0 },
    NULL,
    NULL,
};

PokemonInitData D_80388348_528758 = {
    D_800EB430,
    D_800EB510,
    renderModelTypeDFogged,
    &D_80388334_528744,
    { 2.0f, 2.0f, 2.0f },
    { 0.0f, 0.0f, 0.0f },
    0.0f,
    0,
    0,
    0,
    0,
    { 0, 0, 0 },
};

PokemonDef D_8038837C_52878C = {
    1003,
    func_8035E0D4_4FE4E4,
    pokemonChangeBlock,
    pokemonRemoveOne
};

Vec3f D_8038838C_52879C = { 0.0f, 0.0f, 0.0f };

void func_8035E034_4FE444(GObj*);
void func_8035DFB0_4FE3C0(GObj*);

void func_8035DF20_4FE330(GObj* obj) {
    s32 unused[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_8035E034_4FE444);
    }
    Pokemon_SetAnimation(obj, &D_80388310_528720);
    Pokemon_StartPathProc(obj, func_8035DFB0_4FE3C0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_8035DFB0_4FE3C0(GObj* obj) {
    s32 unused[2];
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 i;

    for (i = 59; i > 0; i--) {
        model->position.v.y -= 0.2f;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_8035E034_4FE444(GObj* obj) {
    s32 unused[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    pokemon->miscVars[0].field1 = 0;
    do {
        ohWait(1);
    } while (pokemon->miscVars[0].field1 == 0);
    SHOW_POKEMON();
    Pokemon_ForceAnimation(obj, &D_80388310_528720);
    Pokemon_StartPathProc(obj, func_8035DFB0_4FE3C0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_8035E034_4FE444);
}

GObj* func_8035E0D4_4FE4E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* arg3, ObjectSpawn* arg4) {
    return Pokemon_SpawnOnGroundDlLink4(objID, id, block, arg3, arg4, &D_80388348_528758);
}

void func_8035E10C_4FE51C(GObj* obj) {
    s32 unused;
    GObj* sp30;
    PokemonTransformBase* sp2C;
    GroundResult sp18;

    sp30 = Pokemon_AddAtGeo(obj, PokemonID_1003, &D_8038837C_52878C);
    sp2C = GET_TRANSFORM_BASE(sp30->data.dobj);
    getGroundAt(sp2C->xform.pos.v.x, sp2C->xform.pos.v.z, &sp18);
    sp2C->xform.pos.v.y = sp18.height;
    GET_POKEMON(sp30)->behavior = 0;
    omEndProcess(NULL);
}

void func_8035E174_4FE584(GObj* obj, Vec3f* arg1) {
    s32 unused;
    GObj* sp30;
    PokemonTransform* sp2C;

    sp30 = Pokemon_AddAtGeo(obj, PokemonID_1003, &D_8038837C_52878C);
    sp2C = GET_TRANSFORM(sp30->data.dobj);
    sp2C->pos.v.x = arg1->x;
    sp2C->pos.v.y = arg1->y;
    sp2C->pos.v.z = arg1->z;
    GET_POKEMON(sp30)->behavior = 0;
}

GObj* func_8035E1D4_4FE5E4(GObj* obj) {
    GObj* sp30;
    GroundResult sp18;
    PokemonTransform* sp2C;

    sp30 = Pokemon_AddAtGeo(obj, PokemonID_1003, &D_8038837C_52878C);
    sp2C = GET_TRANSFORM(sp30->data.dobj);
    getGroundAt(sp2C->pos.v.x, sp2C->pos.v.z, &sp18);
    sp2C->pos.v.y = sp18.height;
    GET_POKEMON(sp30)->behavior = 0;
    return sp30;
}

GObj* func_8035E238_4FE648(GObj* obj) {
    GObj* ret = func_8035E1D4_4FE5E4(obj);

    GET_POKEMON(ret)->behavior = 1;

    return ret;
}

void func_8035E264_4FE674(GObj* obj, Vec3f* arg1) {
    PokemonTransform* sp2C;
    Pokemon* pokemon = GET_POKEMON(obj);

    sp2C = GET_TRANSFORM(obj->data.dobj);
    sp2C->pos.v.x = arg1->x;
    sp2C->pos.v.y = arg1->y;
    sp2C->pos.v.z = arg1->z;
    pokemon->miscVars[0].field1 = 1;
}

void func_8035E298_4FE6A8(GObj* obj) {
    Vec3f sp4C;
    Vec3f sp40;
    DObj* s1;
    GroundResult sp28;

    sp40 = D_8038838C_52879C;
    s1 = obj->data.dobj->firstChild->firstChild->next;

    ohWait(10);
    while (true) {
        func_800A5E98(&sp4C, &sp40, s1);
        getGroundAt(sp4C.x, sp4C.z, &sp28);
        if (sp4C.y < sp28.height) {
            break;
        }
        ohWait(1);
    }
    sp4C.y = sp28.height;
    func_8035E174_4FE584(obj, &sp4C);
}
