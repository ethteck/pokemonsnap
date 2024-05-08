#include "common.h"
#include "world/world.h"

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

void func_803668DC_506CEC(void);
void func_803638E8_503CF8(void);

void func_80363800_503C10(void) {
    D_8038A460_52A870 = 1 - D_8038A460_52A870;
}

s32 func_8036381C_503C2C(void) {
    return D_8038A460_52A870;
}

void func_80363828_503C38(void) {
    func_803668DC_506CEC();
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

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_80363DBC_5041CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_80363EB4_5042C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_8036406C_50447C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_803641B8_5045C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_80364280_504690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_803642A0_5046B0.s")
