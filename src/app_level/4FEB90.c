#include "common.h"
#include "world/world.h"

extern DObj* D_80382C04_523014;

u8 func_803573A4_4F77B4(void);
void func_80366864_506C74(GObj*, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035E780_4FEB90.s")
void func_8035E780_4FEB90(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035E7DC_4FEBEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035E868_4FEC78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035E8A4_4FECB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035E944_4FED54.s")
struct DObjDynamicStore* func_8035E944_4FED54(void);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035E9A4_4FEDB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035E9E0_4FEDF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035EA80_4FEE90.s")
Pokemon* func_8035EA80_4FEE90(void);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035EAE0_4FEEF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035EB1C_4FEF2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035EBBC_4FEFCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035EC1C_4FF02C.s")

void updatePokemonState(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->interactionProc;

    pokemon->transitionGraph = NULL;
    if (func != NULL) {
        pokemon->interactionProc = omCreateProcess(obj, func, 0, 7);
    } else {
        pokemon->interactionProc = NULL;
    }
    omEndProcess(oldProc);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/weightedRandomStaightTransition.s")

void func_8035ED90_4FF1A0(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~0x8;
    omCreateProcess(obj, func, 0, 6);
}

void func_8035EDC8_4FF1D8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= 0x8;
    omEndProcess(NULL);
}

void runPathProcess(GObj* obj, GObjFunc func) {
    Pokemon* pokemon = GET_POKEMON(obj);
    GObjProcess* oldProc = pokemon->pathProcess;

    if (func != NULL) {
        pokemon->pathProcess = omCreateProcess(obj, func, 0, 5);
        pokemon->processFlags &= ~0x32;
    } else {
        pokemon->pathProcess = NULL;
    }
    if (oldProc != NULL) {
        omEndProcess(oldProc);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035EE64_4FF274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035EF2C_4FF33C.s")
void func_8035EF2C_4FF33C(GObj* arg0, Texture*** arg1);

void pokemonUVStuff(GObj* obj, AnimationHeader* header, f32 startTime, s32 force) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (header != NULL) {
        if (pokemon->animators == NULL) {
            ohResumeProcessByFunction(obj, animUpdateModelTreeAnimation);
        }

        if (pokemon->animators != header->animList || force) {
            func_80366864_506C74(obj, 0);
            anim_func_8000F8E4(obj, header->animList, startTime, pokemon->initData->tree);
            pokemon->animators = header->animList;
        }

        if (header->matAnims != NULL) {
            if (pokemon->matAnims != header->matAnims || force) {
                animSetModelTreeTextureAnimation(obj, header->matAnims, 0.0f);
                pokemon->matAnims = header->matAnims;
            }
            animSetModelAndTextureAnimationSpeed(obj, header->speed);
        } else {
            if (pokemon->initData->textures != NULL) {
                func_8035EF2C_4FF33C(obj, pokemon->initData->textures);
            }
            animSetModelAnimationSpeed(obj, header->speed);
            pokemon->matAnims = NULL;
        }

        pokemon->animHeader = header;
        animUpdateModelTreeAnimation(obj);
    } else {
        ohPauseProcessByFunction(obj, animUpdateModelTreeAnimation);
        pokemon->animHeader = NULL;
        pokemon->matAnims = NULL;
        pokemon->animators = NULL;
    }

    pokemon->loopCount = 0;
    pokemon->processFlags &= ~1;
    pokemon->pokemonLoopTarget = 1;
    pokemon->lastAnimationFrame = 0.0f;
}

void setPokemonAnimation(GObj* obj, AnimationHeader* header) {
    pokemonUVStuff(obj, header, 0, 0);
}

void forcePokemonAnimation(GObj* obj, AnimationHeader* header) {
    pokemonUVStuff(obj, header, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F180_4FF590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F1A8_4FF5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F1D0_4FF5E0.s")

f32 func_8035F21C_4FF62C(f32 arg0, f32 arg1) {
    GroundResult sp1C;

    if (getGroundAt(arg0, arg1, &sp1C) != 0) {
        return sp1C.height;
    }
    return 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F24C_4FF65C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F2A4_4FF6B4.s")
f32 func_8035F2A4_4FF6B4(GObj* arg0, GObj* arg1);

void func_8035F390_4FF7A0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    if (D_80382C04_523014 != NULL) {
        Vec3f sp34;
        Vec3f sp28;
        Vec3f sp1C;

        sp28.x = GET_TRANSFORM(model)->pos.v.x;
        sp28.y = GET_TRANSFORM(model)->pos.v.y;
        sp28.z = GET_TRANSFORM(model)->pos.v.z;

        sp34.x = GET_TRANSFORM(D_80382C04_523014)->pos.v.x;
        sp34.y = GET_TRANSFORM(D_80382C04_523014)->pos.v.y;
        sp34.z = GET_TRANSFORM(D_80382C04_523014)->pos.v.z;

        pokemon->playerDist = Vec3fDirection(&sp1C, &sp34, &sp28);
    } else {
        pokemon->playerDist = FLOAT_MAX;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F430_4FF840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F51C_4FF92C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F648_4FFA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F784_4FFB94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035F900_4FFD10.s")
void func_8035F900_4FFD10(GObj*);

void runInteractionsAndWaitForFlags(GObj* obj, u32 flags) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (TRUE) {
        func_8035F900_4FFD10(obj);
        if (pokemon->processFlags & flags) {
            break;
        }
        ohWait(1);
    }
    pokemon->transitionGraph = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035FC54_500064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035FCA0_5000B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035FD00_500110.s")
void func_8035FD00_500110(GObj*);

void runPokemonCleanup(GObj* obj) {
    omCreateProcess(obj, func_8035FD00_500110, 1, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035FD9C_5001AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/addPokemonAtGeo.s")
// GObj* addPokemonAtGeo(GObj *gobj, PokemonID id, PokemonDef *def) {
//     ObjectSpawn spawn;
//     WorldBlock* roomA;
//     Pokemon* pokemonTmp;
//     GObj* pokemonObj;

//     pokemonTmp = GET_POKEMON(gobj);
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
//     spawn.path = pokemonTmp->path;
//     spawn.behavior = pokemonTmp->behavior;

//     pokemonObj = pokemonAddOne(roomA, roomA, &spawn, def);

//     if (pokemonObj != NULL) {
//         xformData* pxVar1 = gobj->data.dobj->unk4C; // TODO type issue
//         xformData* pxVar2 = pokemonObj->data.dobj->unk4C; // TODO type issue

//         pxVar2->translation.x = pxVar1->translation.x;
//         pxVar2->translation.y = pxVar1->translation.y;
//         pxVar2->translation.z = pxVar1->translation.z;
//     }

//     return pokemonObj;
// }

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035FEEC_5002FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035FF1C_50032C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8035FF44_500354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360074_500484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036010C_50051C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360144_500554.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_803601FC_50060C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036026C_50067C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360300_500710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036044C_50085C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360590_5009A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_803606E8_500AF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036082C_500C3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360AB8_500EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360BEC_500FFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360D18_501128.s")
s32 func_80360D18_501128(GObj* arg0, f32 arg1, f32 arg2, s32 arg3);

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360E78_501288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360F1C_50132C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80360FC8_5013D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361110_501520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361410_501820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361440_501850.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036148C_50189C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_803615D0_5019E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361720_501B30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361748_501B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036194C_501D5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361B20_501F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361B50_501F60.s")

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
    Pokemon* pokemon = GET_POKEMON(arg0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361E58_502268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361EB8_5022C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361EE8_5022F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80361FBC_5023CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/setNodePosToNegRoom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/pokemonPathLoop.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_803623F4_502804.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80362414_502824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80362480_502890.s")
void func_80362480_502890(struct DObj*, s32, f32);

#ifdef NON_MATCHING
void func_803625B4_5029C4(GObj* source, s32 cmd) {
    idFuncStruct* a2;
    f32 distance;
    Pokemon* pokemon;
    GObjFunc sp24;
    GObjFunc sp20;
    GObj* sp1C;
    idFuncStruct* ptr;

    sp1C = omCurrentObject;
    pokemon = GET_POKEMON(omCurrentObject);
    sp24 = NULL;
    sp20 = NULL;
    a2 = pokemon->transitionGraph;

    switch(cmd) {
        case 14:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == cmd) {
                        distance = func_8035F2A4_4FF6B4(sp1C, source);
                        if (distance < 600.0f) {
                            pokemon->apple = source;
                            pokemon->interactionDist = distance;
                            pokemon->interactionTarget = source;
                            sp24 = ptr->state;
                            sp20 = ptr->aux;
                        }
                        break;
                    }
                }
            }
            break;
        case 10:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == cmd) {
                        distance = func_8035F2A4_4FF6B4(sp1C, source);
                        if (distance < 150.0) {
                            pokemon->apple = source;
                            pokemon->interactionDist = distance;
                            pokemon->interactionTarget = source;
                            sp24 = ptr->state;
                            sp20 = ptr->aux;
                        }
                        break;
                    }
                }
            }
            break;
        case 9:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == 9) {
                        pokemon->interactionTarget = source;
                        sp24 = ptr->state;
                        sp20 = ptr->aux;
                        break;
                    }
                }
            }
            break;
        case 13:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == 13) {
                        pokemon->interactionTarget = source;
                        sp24 = ptr->state;
                        sp20 = ptr->aux;
                        break;
                    }
                }
            }
            break;
        case 8:
        case 12:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == cmd) {
                        pokemon->interactionTarget = source;
                        sp24 = ptr->state;
                        sp20 = ptr->aux;
                        break;
                    }
                }
            }
            break;
        case 21:
            if (pokemon->apple == source) {
                pokemon->apple = NULL;
                if (a2 != NULL) {
                    for (ptr = a2; ptr->id != 58; ptr++) {
                        if (ptr->id == 21) {
                            sp24 = ptr->state;
                            sp20 = ptr->aux;
                            break;
                        }
                    }
                }
            }
            break;
        case 18:
            if (pokemon->playerDist < 400.0f) {
                if (a2 != NULL) {
                    for (ptr = a2; ptr->id != 58; ptr++) {
                        if (ptr->id == 18) {
                            pokemon->interactionTarget = source;
                            sp24 = ptr->state;
                            sp20 = ptr->aux;
                            break;
                        }
                    }
                }
            }
            break;
        case 24:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == 24) {
                        pokemon->interactionTarget = source;
                        sp24 = ptr->state;
                        sp20 = ptr->aux;
                        break;
                    }
                }
            }
            break;
        case 19:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == 19) {
                        if (getCurrentWorldBlock() == pokemon->baseBlock) {
                            sp24 = ptr->state;
                            sp20 = ptr->aux;
                        }
                    }
                }
            }
            break;
        case 20:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == 20) {
                        distance = func_8035F2A4_4FF6B4(sp1C, source);
                        if (distance < 600.0f) {
                            pokemon->interactionTarget = source;
                            sp24 = ptr->state;
                            sp20 = ptr->aux;
                        }
                        break;
                    }
                }
            }
            break;
        case 22:
            if (pokemon->interactionTarget == source) {
                pokemon->interactionTarget = NULL;
                if (a2 != NULL) {
                    for (ptr = a2; ptr->id != 58; ptr++) {
                        if (ptr->id == 22) {
                            sp24 = ptr->state;
                            sp20 = ptr->aux;
                            break;
                        }
                    }
                }
            }
            break;
        case 26:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == 26) {
                        pokemon->interactionTarget = source;
                        sp24 = ptr->state;
                        sp20 = ptr->aux;
                        break;
                    }
                }
            }
            break;
        case 27:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == 27) {
                        pokemon->interactionTarget = source;
                        sp24 = ptr->state;
                        sp20 = ptr->aux;
                        break;
                    }
                }
            }
            break;
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
            if (a2 != NULL) {
                for (ptr = a2; ptr->id != 58; ptr++) {
                    if (ptr->id == cmd) {
                        if (source != NULL) {
                            pokemon->interactionTarget = source;
                        }
                        sp24 = ptr->state;
                        sp20 = ptr->aux;
                        break;
                    }
                }
            }
            break;
    }

    if (sp20 != NULL) {
        func_8035ED90_4FF1A0(omCurrentObject, sp20);
    }
    if (sp24 != NULL) {
        updatePokemonState(omCurrentObject, sp24);
    }
    if (func_80353D68_4F4178() == 0) {
        ohPauseObjectProcesses(omCurrentObject);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_803625B4_5029C4.s")
void func_803625B4_5029C4(GObj* source, s32 cmd);
#endif

void updatePokemonDefault(GObj* obj) {
    Pokemon* pokemon;
    if (obj == NULL) {
        return;
    }

    pokemon = GET_POKEMON(obj);
    if (func_803573A4_4F77B4() == 0 && !(pokemon->processFlags & 0x4)) {
        if (pokemon->counter > 0) {
            pokemon->counter--;
            if (pokemon->counter <= 0) {
                pokemon->processFlags |= 0x4;
            }
        }
    }
    if (!(pokemon->processFlags & 0x1)) {
        if (pokemon->loopCount >= pokemon->pokemonLoopTarget) {
            pokemon->processFlags |= 0x1;
        } else if (pokemon->lastAnimationFrame > 0.0f && pokemon->lastAnimationFrame < obj->animationTime) {
            pokemon->processFlags |= 0x1;
        }
    }
    cmdProcessCommands(&func_803625B4_5029C4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80362D2C_50313C.s")

GObj* func_80362DC4_5031D4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = spawnPokemon(objID, id, block, blockB, spawn, initData);
    omMoveGObjDL(pokemonObj, 4, 0x80000000);
    return pokemonObj;
}

GObj* func_80362E10_503220(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = spawnPokemonOnGround(objID, id, block, blockB, spawn, initData);
    omMoveGObjDL(pokemonObj, 4, 0x80000000);
    return pokemonObj;
}

GObj* spawnPokemon(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    GObj* pokemonObj = spawnPokemonOnGround(objID, id, block, blockB, spawn, initData);
    GET_TRANSFORM(pokemonObj->data.dobj)->pos.v.y = spawn->translation.y * 100.0f + (block->descriptor->worldPos.y - blockB->descriptor->worldPos.y) * 100.0f;
    return pokemonObj;
}

GObj* spawnPokemonOnGround(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    f32 blockBX, blockBY, blockBZ;
    s32 unused;
    GObj* pokemonObj;
    DObj* model;
    struct DObjDynamicStore* matrixStore;
    Pokemon* pokemon;

    if (block == NULL || block->descriptor == NULL) {
        return NULL;
    }

    blockBX = blockB->descriptor->worldPos.x;
    blockBZ = blockB->descriptor->worldPos.z;

    pokemonObj = omAddGObj(objID, updatePokemonDefault, 3, 0x80000000);

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

    GET_TRANSFORM(model)->pos.v.x = spawn->translation.x * 100.0f + (block->descriptor->worldPos.x - blockBX) * 100.0f;
    GET_TRANSFORM(model)->pos.v.z = spawn->translation.z * 100.0f + (block->descriptor->worldPos.z - blockBZ) * 100.0f;
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
    pokemon->baseBlock = block;
    pokemon->forbiddenGround = NULL;
    pokemon->loopCount = 0;
    pokemon->playerDist = FLOAT_MAX;
    pokemon->interactionDist = FLOAT_MAX;
    pokemonObj->fnAnimCallback = func_80362480_502890;
    pokemon->animators = NULL;
    omCreateProcess(pokemonObj, animUpdateModelTreeAnimation, 1, 3);
    forcePokemonAnimation(pokemonObj, initData->animSetup->animations);
    omCreateProcess(pokemonObj, func_8035F390_4FF7A0, 1, 8);

    pokemon->interactionProc = omCreateProcess(pokemonObj, initData->animSetup->func, initData->animSetup->kind, 7);
    pokemon->unk_18 = -1;
    pokemon->processFlags = 0;
    pokemon->counter = 0;
    pokemon->pathProcess = NULL;
    pokemon->transitionGraph = NULL;
    pokemon->pokemonLoopTarget = 0;
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036334C_50375C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_8036345C_50386C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4FEB90/func_80363738_503B48.s")
