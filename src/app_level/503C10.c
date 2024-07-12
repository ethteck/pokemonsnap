#include "common.h"
#include "world/world.h"
#include "app_level.h"

typedef struct PokemonListEntry {
    /* 0x00 */ GObj* pokemonObj;
    /* 0x04 */ struct PokemonListEntry* next;
} PokemonListEntry; // size = 0x08

extern s32 D_8038A460_52A870;
// file split
s32 sMinPokemonObjId = 0;
s32 sMaxPokemonObjId = 0;
s32 sPokemonLink = 0;
s32 D_8038A47C_52A88C = 0;
s32 D_8038A480_52A890 = 0; // unused
s32 sPokemonCounter = 0;

// bss
extern u8 padding_503C10[8];
extern PokemonListEntry sPokemonListEntries[100];
extern PokemonListEntry* sPokemonLists[MAX_BLOCKS];

void EnvSound_FixParams(GObj* arg0);
void func_803638E8_503CF8(void);

void func_80363800_503C10(void) {
    D_8038A460_52A870 = 1 - D_8038A460_52A870;
}

s32 func_8036381C_503C2C(void) {
    return D_8038A460_52A870;
}

void func_80363828_503C38(GObj* arg0) {
    EnvSound_FixParams(arg0);
}

f32 func_80363848_503C58(GObj* arg0, Vec3f* arg1) {
    Pokemon* pokemon = GET_POKEMON(arg0);

    if (arg1 != NULL) {
        arg1->x = pokemon->collPosition.x;
        arg1->y = pokemon->collPosition.y;
        arg1->z = pokemon->collPosition.z;
    }
    return pokemon->collisionRadius;
}

// file split here ?

PokemonListEntry* getPokemonListEntry(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sPokemonListEntries); i++) {
        if (sPokemonListEntries[i].pokemonObj == NULL) {
            return &sPokemonListEntries[i];
        }
    }
    return NULL;
}

void func_803638E8_503CF8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(sPokemonListEntries); i++) {
        sPokemonListEntries[i].pokemonObj = 0;
        sPokemonListEntries[i].next = 0;
    }
}

void func_80363928_503D38(s32 minObjId, s32 maxObjId, s32 link, s32 arg3) {
    sMinPokemonObjId = minObjId;
    sMaxPokemonObjId = maxObjId;
    sPokemonLink = link;
    D_8038A47C_52A88C = arg3;
    func_803638E8_503CF8();
}

static void nullsub() {

}

#ifdef NON_MATCHING
s32 func_8036396C_503D7C(void) {
    s32 i;

    sPokemonCounter++;
    if (sPokemonCounter > sMaxPokemonObjId - sMinPokemonObjId) {
        sPokemonCounter = 0;
    }

    for (i = sMinPokemonObjId + sPokemonCounter; i < sMaxPokemonObjId; i++) {
        if (ohFindByLinkAndId(sPokemonLink, i) == NULL) {
            return i;
        }
    }

    for (i = sMinPokemonObjId; i < sMinPokemonObjId + sPokemonCounter; i++) {
        if (ohFindByLinkAndId(sPokemonLink, i) == NULL) {
            return i;
        }
    }

    return sMaxPokemonObjId;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_8036396C_503D7C.s")
s32 func_8036396C_503D7C(void);
#endif

void pokemonAdd(WorldBlock* block, WorldBlock* blockB, PokemonDef* def) {
    ObjectSpawn* spawn;
    PokemonDef* defPtr;
    GObj* pokemonObj;

    if (block == NULL ||
        block->descriptor == NULL ||
        block->descriptor->spawn == NULL ||
        block->index >= MAX_BLOCKS)
    {
        return;
    }

    sPokemonLists[block->index] = NULL;

    spawn = block->descriptor->spawn;

    while (spawn->id != 0xFFFFFFFF) {
        s32 objId = func_8036396C_503D7C();
        if (!inRange_DEBUG(objId, sMinPokemonObjId, sMaxPokemonObjId, "animalAdd()")) {
            return;
        }

        pokemonObj = NULL;
        defPtr = def;
        while (defPtr->id != 0) {
            if (spawn->id == defPtr->id && defPtr->init != NULL) {
                pokemonObj = defPtr->init(objId, spawn->id, block, blockB, spawn);
                if (!notNull_DEBUG(pokemonObj, "animalAdd()")) {
                    return;
                }
                break;
            }
            defPtr++;
        }

        if (pokemonObj != NULL) {
            PokemonListEntry* entry = getPokemonListEntry();
            entry->pokemonObj = pokemonObj;
            entry->next = sPokemonLists[block->index];
            sPokemonLists[block->index] = entry;
        }

        spawn++;
    }
}

GObj* pokemonAddOne(WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonDef* def) {
    s32 objId;
    GObj* pokemonObj = NULL;

    if (block == NULL || block->descriptor == NULL) {
        return NULL;
    }
    if (block->index >= MAX_BLOCKS) {
        return NULL;
    }
    if (def == NULL) {
        return NULL;
    }

    objId = func_8036396C_503D7C();
    if (!inRange_DEBUG(objId, sMinPokemonObjId, sMaxPokemonObjId, "animalAddOne()")) {
        return NULL;
    }

    if (def->init != NULL) {
        pokemonObj = def->init(objId, def->id, block, blockB, spawn);
    }
    if (!notNull_DEBUG(pokemonObj, "animalAddOne()")) {
        return NULL;
    }

    if (pokemonObj != NULL) {
        PokemonListEntry* entry = getPokemonListEntry();
        entry->pokemonObj = pokemonObj;
        entry->next = sPokemonLists[block->index];
        sPokemonLists[block->index] = entry;
    }

    return pokemonObj;
}

f32 func_80363D8C_50419C(f32 x, f32 z) {
    GroundResult result;

    if (getGroundAt(x, z, &result)) {
        return result.height;
    }
    return 0.0f;
}

void pokemonChangeBlock(GObj* pokemonObj, f32 prevBlockX, f32 prevBlockY, f32 prevBlockZ, f32 currBlockX, f32 currBlockY, f32 currBlockZ) {
    s32 i;
    struct Mtx3Float* mtxPtr;
    Pokemon* pokemon = GET_POKEMON(pokemonObj);
    f32 dx = (prevBlockX - currBlockX) * 100.0f;
    f32 dy = (prevBlockY - currBlockY) * 100.0f;
    f32 dz = (prevBlockZ - currBlockZ) * 100.0f;

    mtxPtr = (struct Mtx3Float*)pokemonObj->data.dobj->unk_4C->data;
    for (i = 0; i < 3; i++) {
        if (pokemonObj->data.dobj->unk_4C->kinds[i] == 1) {
            mtxPtr->v.x += dx;
            mtxPtr->v.y += dy;
            mtxPtr->v.z += dz;
            mtxPtr++;
        }
    }

    pokemon->pos1.x += dx;
    pokemon->pos1.y += dy;
    pokemon->pos1.z += dz;
    pokemon->targetPos.x += dx;
    pokemon->targetPos.y += dy;
    pokemon->targetPos.z += dz;
}

void pokemonChangeBlockOnGround(GObj* pokemonObj, f32 prevBlockX, f32 prevBlockY, f32 prevBlockZ, f32 currBlockX, f32 currBlockY, f32 currBlockZ) {
    s32 i;
    f32 dx, dz;
    struct Mtx3Float* mtxPtr;
    Pokemon* pokemon;

    if (pokemonObj->data.dobj->unk_4C != NULL) {
        dx = (prevBlockX - currBlockX) * 100.0f;
        dz = (prevBlockZ - currBlockZ) * 100.0f;
        mtxPtr = (struct Mtx3Float*)pokemonObj->data.dobj->unk_4C->data;

        for (i = 0; i < 3; i++) {
            if (pokemonObj->data.dobj->unk_4C->kinds[i] == 1) {
                struct Mtx3Float* mtxPtr2 = mtxPtr;
                if (1) {} // required for match
                mtxPtr2->v.x += dx;
                mtxPtr2->v.z += dz;
                mtxPtr2->v.y = func_80363D8C_50419C(mtxPtr2->v.x, mtxPtr2->v.z);
                mtxPtr++;
            }
        }
    } else {
        dx = (prevBlockX - currBlockX) * 100.0f;
        dz = (prevBlockZ - currBlockZ) * 100.0f;
        pokemonObj->data.dobj->position.v.x += dx;
        pokemonObj->data.dobj->position.v.z += dz;
        pokemonObj->data.dobj->position.v.y = func_80363D8C_50419C(pokemonObj->data.dobj->position.v.x, pokemonObj->data.dobj->position.v.z);
    }
    pokemon = GET_POKEMON(pokemonObj);
    pokemon->pos1.x += dx;
    pokemon->pos1.z += dz;
    pokemon->pos1.y = func_80363D8C_50419C(pokemon->pos1.x, pokemon->pos1.z);
    pokemon->targetPos.x += dx;
    pokemon->targetPos.z += dz;
    pokemon->targetPos.y = func_80363D8C_50419C(pokemon->targetPos.x, pokemon->targetPos.z);
}

void pokemonsChangeBlock(WorldBlock* baseBlock, WorldBlock* currentBlock, PokemonDef* def) {
    PokemonListEntry* entry;
    PokemonDef* defPtr;
    s32 blockIndex;
    WorldBlock* prevBlock;

    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_19, NULL);
    if (baseBlock == NULL || currentBlock == NULL || currentBlock->descriptor == NULL || currentBlock->prev == NULL || currentBlock->prev->descriptor == NULL) {
        return;
    }
    prevBlock = currentBlock->prev;

    blockIndex = baseBlock->index;
    for (entry = sPokemonLists[blockIndex]; entry != NULL;) {
        if (entry->pokemonObj != NULL && entry->pokemonObj->data.dobj != NULL) {
            Pokemon* pokemon = GET_POKEMON(entry->pokemonObj);
            for (defPtr = def; defPtr->id != 0; defPtr++) {
                if (pokemon->id == defPtr->id && defPtr->update != NULL) {
                    defPtr->update(entry->pokemonObj,
                                   prevBlock->descriptor->worldPos.x,
                                   prevBlock->descriptor->worldPos.y,
                                   prevBlock->descriptor->worldPos.z,
                                   currentBlock->descriptor->worldPos.x,
                                   currentBlock->descriptor->worldPos.y,
                                   currentBlock->descriptor->worldPos.z);
                    break;
                }
            }
            entry = entry->next; // BUG: this should be outside 'if { }' check, infinite loop is possible
        }
    }
}

void pokemonRemove(WorldBlock* block, PokemonDef* def) {
    PokemonListEntry* entry;
    Pokemon* pokemon;
    PokemonDef* defPtr;
    s32 blockIndex;

    if (block == NULL || block->descriptor == NULL || block->descriptor->spawn == NULL) {
        return;
    }
    blockIndex = block->index;
    for (entry = sPokemonLists[blockIndex]; entry != NULL; entry = entry->next) {
        if (entry->pokemonObj == NULL) {
            continue;
        }
        pokemon = GET_POKEMON(entry->pokemonObj);
        for (defPtr = def; defPtr->id != 0; defPtr++) {
            if (pokemon->id == defPtr->id && defPtr->kill != NULL) {
                defPtr->kill(entry->pokemonObj);
                break;
            }
        }
    }
}

void pokemonRemoveOne(GObj* obj) {
    Pokemon_RunCleanup(obj);
}

void deletePokemon(GObj* pokemonObj) {
    s32 unused;
    PokemonListEntry* entry;
    PokemonListEntry* prevEntry;
    s32 blockIndex;
    Pokemon* pokemon = GET_POKEMON(pokemonObj);
    WorldBlock* block = pokemon->baseBlock;
    s32 unused2;

    if (block == NULL) {
        return;
    }
    blockIndex = block->index;
    entry = sPokemonLists[blockIndex];
    prevEntry = entry;
    while (entry != NULL) {
        if (entry->pokemonObj == pokemonObj) {
            func_80363828_503C38(pokemonObj);
            omDeleteGObj(pokemonObj);
            entry->pokemonObj = NULL;
            if (entry == sPokemonLists[blockIndex]) {
                sPokemonLists[blockIndex] = entry->next;
            } else {
                prevEntry->next = entry->next;
            }
            break;
        }
        prevEntry = entry;
        entry = entry->next;
    }
}
