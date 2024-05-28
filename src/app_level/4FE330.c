#include "common.h"
#include "world/world.h"
#include "app_level.h"

extern AnimCmd* D_800EAFB0[];
extern AnimCmd** D_800EB0C0[];
extern UnkEC64Arg3 D_800EB430[];
extern Texture** D_800EB510[];

void pokemonChangeBlock(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void pokemonRemoveOne(GObj* obj);

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

    pokemon->tangible = FALSE;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->miscVars[0].field1 = 0;
    do {
        ohWait(1);
    } while (pokemon->miscVars[0].field1 == 0);
    pokemon->tangible = TRUE;
    obj->flags = 0;
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

void func_8035E238_4FE648(GObj* obj) {
    GET_POKEMON(func_8035E1D4_4FE5E4(obj))->behavior = 1;
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
    while (TRUE) {
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

extern s32 D_8038A028_52A438;

s32 func_8035E370_4FE780(void) {
    return D_8038A028_52A438;
}

extern s32 D_8038A024_52A434;
extern s32 D_8038A02C_52A43C;
extern s32 D_8038A030_52A440;
extern GObj* D_803B09D8_550DE8;
extern Sprite D_80388E00_529210;
extern Sprite D_80388F60_529370;
extern Sprite D_803890C0_5294D0;
extern Sprite D_80389220_529630;
extern SObj* D_803B0A14_550E24;
extern SObj* D_803B0A18_550E28;
extern SObj* D_803B0A1C_550E2C;

s32 func_8035E52C_4FE93C(void);

void func_8035E37C_4FE78C(void) {
    GObj* obj;
    SObj* sobj;

    D_8038A024_52A434 = 0;
    D_8038A028_52A438 = 1;
    D_8038A02C_52A43C = 0;
    D_8038A030_52A440 = 6;

    obj = omAddGObj(28, ohUpdateDefault, 0, 0x80000000);
    omLinkGObjDL(obj, renDrawSprite, 1, 0x80000000, -1);
    D_803B09D8_550DE8 = obj;
    
    sobj = omGObjAddSprite(obj, &D_80388E00_529210);
    spMove(&sobj->sprite, 257, 22);

    D_803B0A14_550E24 = sobj = omGObjAddSprite(obj, &D_80388F60_529370);
    spMove(&sobj->sprite, 286, 24);

    D_803B0A18_550E28 = sobj = omGObjAddSprite(obj, &D_803890C0_5294D0);
    spMove(&sobj->sprite, 278, 24);
    spSetAttribute(&sobj->sprite, SP_HIDDEN);

    D_803B0A1C_550E2C = sobj = omGObjAddSprite(obj, &D_80389220_529630);
    spMove(&sobj->sprite, 270, 24);
    spSetAttribute(&sobj->sprite, SP_HIDDEN);

    func_8035E52C_4FE93C();
}

void func_8035E4D0_4FE8E0(void) {
    if (D_803B09D8_550DE8 != NULL) {
        omDeleteGObj(D_803B09D8_550DE8);
        D_803B09D8_550DE8 = NULL;
    }
}

s32 func_8035E508_4FE918(void) {
    return 60 - func_8009BC68();
}

extern UNK_TYPE D_8038A034_52A444[];
extern UNK_TYPE D_80388F58_529368;
extern UNK_TYPE D_803890B8_5294C8;
extern UNK_TYPE D_80389218_529628;

s32 func_8035E52C_4FE93C(void) {
    s32 ones, tens, hundreds;
    s32 value = 60 - func_8009BC68();    
    
    ones = value % 10;
    tens = (value % 100) / 10;
    hundreds = value / 100;    

    D_80388F58_529368 = D_8038A034_52A444[ones];

    if (hundreds == 0) {
        if (tens == 0) {
            spSetAttribute(&D_803B0A18_550E28->sprite, SP_HIDDEN);
        } else {
            D_803890B8_5294C8 = D_8038A034_52A444[tens];
            spClearAttribute(&D_803B0A18_550E28->sprite, SP_HIDDEN);
        }
        spSetAttribute(&D_803B0A1C_550E2C->sprite, SP_HIDDEN);
    } else {
        D_803890B8_5294C8 = D_8038A034_52A444[tens];
        spClearAttribute(&D_803B0A18_550E28->sprite, SP_HIDDEN);
        D_80389218_529628 = D_8038A034_52A444[hundreds];
        spClearAttribute(&D_803B0A1C_550E2C->sprite, SP_HIDDEN);
    }

    if (value == 10) {
        spColor(&D_803B0A14_550E24->sprite, 255, 0, 0, 255);
        spColor(&D_803B0A18_550E28->sprite, 255, 0, 0, 255);
    }

    return value;
}

void func_8035E754_4FEB64(void) {
    D_803B09D8_550DE8->flags = 0;
}

void func_8035E764_4FEB74(void) {
    D_803B09D8_550DE8->flags |= GOBJ_FLAG_HIDDEN;
}
