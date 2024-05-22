#include "common.h"
#include "world/world.h"

extern AnimCmd* D_800EAFB0[];
extern AnimCmd** D_800EB0C0[];
extern UnkEC64Arg3 D_800EB430[];
extern Texture** D_800EB510[];

void pokemonChangeBlock(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void pokemonRemoveOne(GObj* obj);

void func_8035DF20_4FE330(GObj* arg0);
GObj* func_8035E0D4_4FE4E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* arg3, ObjectSpawn* arg4);

AnimationHeader D_80388310_528720 = {
    0.9f,
    60.0f,
    D_800EAFB0,
    D_800EB0C0,
    NULL
};

idFuncStruct D_80388324_528734[] = {
    {
        0x3A,
        NULL,
        NULL,
        NULL
    },
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
    0, 0, 0,
    { 0, 0, 0 },
};

PokemonDef D_8038837C_52878C = {
    1003,
    func_8035E0D4_4FE4E4,
    pokemonChangeBlock,
    pokemonRemoveOne
};

Vec3f D_8038838C_52879C = { 0.0f, 0.0f, 0.0f };

void func_800A5E98(Vec3f*, Vec3f*, DObj*);

void func_8035E034_4FE444(GObj*);
void func_8035DFB0_4FE3C0(GObj*);

void func_8035DF20_4FE330(GObj* arg0) {
    s32 unused[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    if (pokemon->behavior == 1) {
        updatePokemonState(arg0, func_8035E034_4FE444);
    }
    setPokemonAnimation(arg0, &D_80388310_528720);
    runPathProcess(arg0, func_8035DFB0_4FE3C0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(arg0, 1);
    runPokemonCleanup(arg0);
    updatePokemonState(arg0, NULL);
}

void func_8035DFB0_4FE3C0(GObj* arg0) {
    s32 unused[2];
    DObj* model = arg0->data.dobj;
    Pokemon* pokemon = GET_POKEMON(arg0);
    s32 i;

    for (i = 59; i > 0; i--) {
        model->position.v.y -= 0.2f;
        ohWait(1);
    }

    pokemon->processFlags |= 2;
    pokemon->pathProcess = NULL;
    omEndProcess(NULL);
}

void func_8035E034_4FE444(GObj* arg0) {
    s32 unused[3];
    Pokemon* pokemon = GET_POKEMON(arg0);

    pokemon->tangible = FALSE;
    arg0->flags |= 3;
    pokemon->miscVars[0].field1 = 0;
    do {
        ohWait(1);
    } while (pokemon->miscVars[0].field1 == 0);
    pokemon->tangible = TRUE;
    arg0->flags = 0;
    forcePokemonAnimation(arg0, &D_80388310_528720);
    runPathProcess(arg0, &func_8035DFB0_4FE3C0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(arg0, 1);
    updatePokemonState(arg0, func_8035E034_4FE444);
}

GObj* func_8035E0D4_4FE4E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* arg3, ObjectSpawn* arg4) {
    return func_80362E10_503220(objID, id, block, arg3, arg4, &D_80388348_528758);
}

void func_8035E10C_4FE51C(GObj* arg0) {
    s32 unused;
    GObj* sp30;
    PokemonTransformBase* sp2C;
    GroundResult sp18;

    sp30 = addPokemonAtGeo(arg0, 1003, &D_8038837C_52878C);
    sp2C = GET_TRANSFORM_BASE(sp30->data.dobj);
    getGroundAt(sp2C->xform.pos.v.x, sp2C->xform.pos.v.z, &sp18);
    sp2C->xform.pos.v.y = sp18.height;
    GET_POKEMON(sp30)->behavior = 0;
    omEndProcess(NULL);
}

void func_8035E174_4FE584(GObj* arg0, Vec3f* arg1) {
    s32 unused;
    GObj* sp30;
    PokemonTransform* sp2C;

    sp30 = addPokemonAtGeo(arg0, 1003, &D_8038837C_52878C);
    sp2C = GET_TRANSFORM(sp30->data.dobj);
    sp2C->pos.v.x = arg1->x;
    sp2C->pos.v.y = arg1->y;
    sp2C->pos.v.z = arg1->z;
    GET_POKEMON(sp30)->behavior = 0;
}

GObj* func_8035E1D4_4FE5E4(GObj* arg0) {
    GObj* sp30;
    GroundResult sp18;
    PokemonTransform* sp2C;    

    sp30 = addPokemonAtGeo(arg0, 1003, &D_8038837C_52878C);
    sp2C = GET_TRANSFORM(sp30->data.dobj);
    getGroundAt(sp2C->pos.v.x, sp2C->pos.v.z, &sp18);
    sp2C->pos.v.y = sp18.height;
    GET_POKEMON(sp30)->behavior = 0;
    return sp30;
}

void func_8035E238_4FE648(GObj* arg0) {
    GET_POKEMON(func_8035E1D4_4FE5E4(arg0))->behavior = 1;
}

void func_8035E264_4FE674(GObj* arg0, Vec3f* arg1) {
    PokemonTransform* sp2C;
    Pokemon* pokemon = GET_POKEMON(arg0);

    sp2C = GET_TRANSFORM(arg0->data.dobj);
    sp2C->pos.v.x = arg1->x;
    sp2C->pos.v.y = arg1->y;
    sp2C->pos.v.z = arg1->z;
    pokemon->miscVars[0].field1 = 1;
}

void func_8035E298_4FE6A8(GObj* arg0) {
    Vec3f sp4C;
    Vec3f sp40;
    DObj* s1;
    GroundResult sp28;

    sp40 = D_8038838C_52879C;
    s1 = arg0->data.dobj->firstChild->firstChild->next;

    ohWait(10);
    while (TRUE) {
        func_800A5E98(&sp4C, &sp40, s1);
        getGroundAt(sp4C.x, sp4C.z, &sp28);
        if (sp4C.y < sp28.height) {
            break;
        }
        ohWait(1);
    }
    sp4C.y = sp28.height;
    func_8035E174_4FE584(arg0, &sp4C);
}

extern s32 D_8038A028_52A438;

s32 func_8035E370_4FE780(void) {
    return D_8038A028_52A438;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E37C_4FE78C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E4D0_4FE8E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E508_4FE918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E52C_4FE93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E754_4FEB64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FE330/func_8035E764_4FEB74.s")
