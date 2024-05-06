#include "common.h"
#include "world/world.h"

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E780_4FEB90.s")
void func_8035E780_4FEB90(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E7DC_4FEBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E868_4FEC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E8A4_4FECB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E944_4FED54.s")
struct DObjDynamicStore* func_8035E944_4FED54(void);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E9A4_4FEDB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035E9E0_4FEDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EA80_4FEE90.s")
Animal* func_8035EA80_4FEE90(void);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EAE0_4FEEF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EB1C_4FEF2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EBBC_4FEFCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EC1C_4FF02C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/updateAnimalState.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/weightedRandomStaightTransition.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035ED90_4FF1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EDC8_4FF1D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/runPathProcess.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EE64_4FF274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035EF2C_4FF33C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/animalUVStuff.s")

void setAnimalAnimation(GObj* obj, animationHeader* header) {
    animalUVStuff(obj, header, 0, 0);
}

void forceAnimalAnimation(GObj* obj, animationHeader* header) {
    animalUVStuff(obj, header, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F180_4FF590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F1A8_4FF5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F1D0_4FF5E0.s")

f32 func_8035F21C_4FF62C(f32 arg0, f32 arg1) {
    GroundResult sp1C;

    if (getGroundAt(arg0, arg1, &sp1C) != 0) {
        return sp1C.height;
    }
    return 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F24C_4FF65C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F2A4_4FF6B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F390_4FF7A0.s")
void func_8035F390_4FF7A0(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F430_4FF840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F51C_4FF92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F648_4FFA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F784_4FFB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035F900_4FFD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/runInteractionsAndWaitForFlags.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FC54_500064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FCA0_5000B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FD00_500110.s")
void func_8035FD00_500110(GObj*);

void runAnimalCleanup(GObj* obj) {
    omCreateProcess(obj, func_8035FD00_500110, 1, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FD9C_5001AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/addAnimalAtGeo.s")
// GObj* addAnimalAtGeo(GObj *gobj, AnimalID id, AnimalDef *def) {
//     ObjectSpawn spawn;
//     WorldBlock* roomA;
//     Animal* animalTmp;
//     GObj* animalObj;

//     animalTmp = GET_ANIMAL(gobj);
//     roomA = getCurrentRoom();
//     spawn.id = id;
//     spawn.translation.x = 0.0f;
//     spawn.translation.y = 0.0f;
//     spawn.translation.z = 0.0f;
//     spawn.euler.x = 0.0f;
//     spawn.euler.y = 0.0f;
//     spawn.euler.z = 0.0f;
//     spawn.scale.x = 1.0f;
//     spawn.scale.y = 1.0f;
//     spawn.scale.z = 1.0f;
//     spawn.path = animalTmp->path;
//     spawn.behavior = animalTmp->behavior;

//     animalObj = animalAddOne(roomA, roomA, &spawn, def);

//     if (animalObj != NULL) {
//         xformData* pxVar1 = gobj->data.dobj->unk4C; // TODO type issue
//         xformData* pxVar2 = animalObj->data.dobj->unk4C; // TODO type issue

//         pxVar2->translation.x = pxVar1->translation.x;
//         pxVar2->translation.y = pxVar1->translation.y;
//         pxVar2->translation.z = pxVar1->translation.z;
//     }

//     return animalObj;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FEEC_5002FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FF1C_50032C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8035FF44_500354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360074_500484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036010C_50051C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360144_500554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803601FC_50060C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036026C_50067C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360300_500710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036044C_50085C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360590_5009A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803606E8_500AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036082C_500C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360AB8_500EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360BEC_500FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360D18_501128.s")
s32 func_80360D18_501128(GObj* arg0, f32 arg1, f32 arg2, s32 arg3);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360E78_501288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360F1C_50132C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80360FC8_5013D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361110_501520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361410_501820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361440_501850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036148C_50189C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803615D0_5019E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361720_501B30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361748_501B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036194C_501D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B20_501F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B50_501F60.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361B68_501F78.s")
s32 func_80361B68_501F78(GObj* arg0, f32 arg1, s32 arg2) {
    f32 dx, dz;
    f32 sp4C;
    f32 sp48; 
    f32 unused;
    f32 f122;
    f32 sp3C;
    f32 sign;
    f32 delta;
    f32 sp30;    
    Animal* pokemon = GET_ANIMAL(arg0);
    DObj* model = arg0->data.dobj;

    sp30 = pokemon->hSpeed * 0.033;
    dx = pokemon->targetPos.x - GET_TRANSFORM(model)->pos.v.x;
    dz = pokemon->targetPos.z - GET_TRANSFORM(model)->pos.v.z;    

    if (SQ(dx) + SQ(dz) < SQ(sp30)) {
        pokemon->processFlags |= 0x10;
        return 1;
    }

    sp3C = atan2f(dx, dz);
    if (sp3C < 0.0f) {
        sp3C += TAU;
    } else if (sp3C > TAU){
        sp3C -= (s32)(sp3C / TAU) * TAU;
    }

    sp4C = sinf(sp3C) * sp30;
    sp48 = cosf(sp3C) * sp30;
    if (func_80360D18_501128(arg0, sp4C, sp48, arg2)) {
        return 2;
    }

    f122 = GET_TRANSFORM(model)->rot.f[2];
    f122 -= (s32)(f122 / TAU) * TAU;
    if (f122 < 0.0f) {
        f122 += TAU;
    }

    delta = sp3C - f122;
    if (ABS(delta) > arg1) {
        if (ABS(delta) < M_PI_F) {
            sign = SIGN(delta);
        } else {
            sign = -SIGN(delta);
        }
        GET_TRANSFORM(model)->rot.f[2] = f122 + sign * arg1;
    } else {
        GET_TRANSFORM(model)->rot.f[2] = sp3C;
    }

    dx = pokemon->targetPos.x - GET_TRANSFORM(model)->pos.v.x;
    dz = pokemon->targetPos.z - GET_TRANSFORM(model)->pos.v.z;
    if (SQ(dx) + SQ(dz) < SQ(sp30)) {
        pokemon->processFlags |= 0x10;
        return 1;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361E58_502268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361EB8_5022C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361EE8_5022F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80361FBC_5023CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/setNodePosToNegRoom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/animalPathLoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803623F4_502804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362414_502824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362480_502890.s")
void func_80362480_502890(struct DObj*, s32, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_803625B4_5029C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362C50_503060.s")
void func_80362C50_503060(GObj* arg0);

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362D2C_50313C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362DC4_5031D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80362E10_503220.s")

void spawnAnimalUsingDeltaHeight(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = func_80362EE0_5032F0(objID, id, block, blockB, spawn, initData);
    GET_TRANSFORM(pokemonObj->data.dobj)->pos.v.y = spawn->translation.y * 100.0f + (block->descriptor->unk_04.y - blockB->descriptor->unk_04.y) * 100.0f;
}

GObj* func_80362EE0_5032F0(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    f32 blockBX, blockBY, blockBZ;
    s32 unused;
    GObj* pokemonObj;
    DObj* model;    
    struct DObjDynamicStore* matrixStore;
    Animal* pokemon;

    if (block == NULL || block->descriptor == NULL) {
        return NULL;
    }

    blockBX = blockB->descriptor->unk_04.x;
    blockBZ = blockB->descriptor->unk_04.z;

    pokemonObj = omAddGObj(objID, func_80362C50_503060, 3, 0x80000000);

    if (initData->fnRender != NULL && initData->tree != NULL) {
        omLinkGObjDL(pokemonObj, initData->fnRender, 5, 0x80000000, -1);
        if (initData->flags & 0x10) {
            anim_func_80010230(pokemonObj, initData->tree, initData->textures, NULL, initData->matrix1, initData->matrix2, initData->matrix3);
        } else {
            anim_func_80010230(pokemonObj, initData->tree, initData->textures, NULL, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
        }
        model = pokemonObj->data.dobj;
    } else {
        model = omGObjAddDObj(pokemonObj, NULL);
        if (initData->flags & 0x10) {
            anim_func_8000FDA0(model, initData->matrix1, initData->matrix2, initData->matrix3);
        } else {
            anim_func_8000FDA0(model, MTX_TYPE_ROTATE_RPY_TRANSLATE_SCALE, 0, 0);
        }
    }

    matrixStore = func_8035E944_4FED54();
    matrixStore->kinds[0] = 1;
    matrixStore->kinds[1] = 2;
    matrixStore->kinds[2] = 3;
    model->unk_4C = matrixStore;
    omDObjAddMtx(model, MTX_TYPE_63, 0, 0);

    GET_TRANSFORM(model)->pos.v.x = spawn->translation.x * 100.0f + (block->descriptor->unk_04.x - blockBX) * 100.0f;
    GET_TRANSFORM(model)->pos.v.z = spawn->translation.z * 100.0f + (block->descriptor->unk_04.z - blockBZ) * 100.0f;
    GET_TRANSFORM(model)->pos.v.y = func_8035F21C_4FF62C(GET_TRANSFORM(model)->pos.v.x, GET_TRANSFORM(model)->pos.v.z);
    GET_TRANSFORM(model)->rot.f[1] = spawn->euler.x;
    GET_TRANSFORM(model)->rot.f[2] = spawn->euler.y;
    GET_TRANSFORM(model)->rot.f[3] = spawn->euler.z;
    GET_TRANSFORM(model)->scale.v.x = initData->scale.x * 0.1f;
    GET_TRANSFORM(model)->scale.v.y = initData->scale.y * 0.1f;
    GET_TRANSFORM(model)->scale.v.z = initData->scale.z * 0.1f;

    pokemonObj->userData = pokemon = func_8035EA80_4FEE90();
    pokemon->initData = initData;
    pokemon->pos1.x = GET_TRANSFORM(model)->pos.v.x;
    pokemon->pos1.y = GET_TRANSFORM(model)->pos.v.y;
    pokemon->pos1.z = GET_TRANSFORM(model)->pos.v.z;
    pokemon->targetPos.x = GET_TRANSFORM(model)->pos.v.x;
    pokemon->targetPos.y = GET_TRANSFORM(model)->pos.v.y;
    pokemon->targetPos.z = GET_TRANSFORM(model)->pos.v.z;
    pokemon->euler.x = GET_TRANSFORM(model)->rot.f[1];
    pokemon->euler.y = GET_TRANSFORM(model)->rot.f[2];
    pokemon->euler.z = GET_TRANSFORM(model)->rot.f[3];
    pokemon->collisionOffset.x = initData->scaleNumerator.x / initData->scale.x;
    pokemon->collisionOffset.y = initData->scaleNumerator.y / initData->scale.y;
    pokemon->collisionOffset.z = initData->scaleNumerator.z / initData->scale.z;
    pokemon->collisionRadius = initData->radius * initData->scale.y;
    pokemon->flags = initData->flags;
    pokemon->id = id;
    pokemon->tangible = TRUE;    
    pokemon->animSetup = initData->animSetup;
    pokemon->someRoom = block;
    pokemon->forbiddenGround = NULL;
    pokemon->loopCount = 0;
    pokemon->playerDist = FLOAT_MAX;    
    pokemon->interactionDist = FLOAT_MAX;    
    pokemonObj->fnAnimCallback = func_80362480_502890;
    pokemon->animators = NULL;
    omCreateProcess(pokemonObj, animUpdateModelTreeAnimation, 1, 3);
    forceAnimalAnimation(pokemonObj, initData->animSetup->animations);
    omCreateProcess(pokemonObj, func_8035F390_4FF7A0, 1, 8);

    pokemon->interactionProc = omCreateProcess(pokemonObj, initData->animSetup->func, initData->animSetup->kind, 7);
    pokemon->unk_18 = -1;
    pokemon->processFlags = 0;
    pokemon->counter = 0;
    pokemon->pathProcess = NULL;
    pokemon->transitionGraph = NULL;
    pokemon->animalLoopTarget = 0;
    pokemon->lastAnimationFrame = 0.0f;
    pokemon->jumpVel = 0.0f;
    pokemon->hSpeed = 0.0f;
    pokemon->facingYaw = 0.0f;
    pokemon->transitionGraph = initData->animSetup->idfuncs;
    pokemon->unk_E4 = 255;
    pokemon->path = spawn->path;
    pokemon->pathParam = 0.0f;
    pokemon->behavior = spawn->behavior;
    pokemon->eggGeo = NULL;
    pokemon->unk_10C = 0;
    pokemon->field_0x10e = 0;    
    pokemon->playerDist = FLOAT_MAX;
    func_8035E780_4FEB90(pokemonObj);
    return pokemonObj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036334C_50375C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_8036345C_50386C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/4FEB90/func_80363738_503B48.s")
