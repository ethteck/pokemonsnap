#include "common.h"
#include "world/world.h"

typedef struct UnkAzureCobra {
    /* 0x00 */ GObj* pokemonObj;
    /* 0x04 */ struct UnkAzureCobra* next;
} UnkAzureCobra; // size = 0x08

extern s32 D_8038A460_52A870;
extern s32 D_8038A470_52A880;
extern s32 D_8038A474_52A884;
extern s32 D_8038A478_52A888;
extern s32 D_8038A47C_52A88C;
extern s32 D_8038A484_52A894;

extern UnkAzureCobra D_803B0F68_551378[100];
extern UnkAzureCobra* D_803B1288_551698[];

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
    Animal* pokemon = GET_ANIMAL(arg0);

    if (arg1 != NULL) {
        arg1->x = pokemon->collPosition.x;
        arg1->y = pokemon->collPosition.y;
        arg1->z = pokemon->collPosition.z;
    }
    return pokemon->collisionRadius;
}

UnkAzureCobra* func_80363870_503C80(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803B0F68_551378); i++) {
        if (D_803B0F68_551378[i].pokemonObj == NULL) {
            return &D_803B0F68_551378[i];
        }
    }
    return NULL;
}

void func_803638E8_503CF8(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803B0F68_551378); i++) {
        D_803B0F68_551378[i].pokemonObj = 0;
        D_803B0F68_551378[i].next = 0;
    }
}

void func_80363928_503D38(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_8038A470_52A880 = arg0;
    D_8038A474_52A884 = arg1;
    D_8038A478_52A888 = arg2;
    D_8038A47C_52A88C = arg3;
    func_803638E8_503CF8();
}

static void nullsub() {

}

#ifdef NON_MATCHING
s32 func_8036396C_503D7C(void) {
    s32 i;

    D_8038A484_52A894++;
    if (D_8038A484_52A894 > D_8038A474_52A884 - D_8038A470_52A880) {
        D_8038A484_52A894 = 0;
    }

    for (i = D_8038A470_52A880 + D_8038A484_52A894; i < D_8038A474_52A884; i++) {
        if (ohFindByLinkAndId(D_8038A478_52A888, i) == NULL) {
            return i;
        }
    }

    for (i = D_8038A470_52A880; i < D_8038A470_52A880 + D_8038A484_52A894; i++) {
        if (ohFindByLinkAndId(D_8038A478_52A888, i) == NULL) {
            return i;
        }
    }

    return D_8038A474_52A884;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_8036396C_503D7C.s")
s32 func_8036396C_503D7C(void);
#endif

void animalAdd(WorldBlock* block, WorldBlock* blockB, AnimalDef* def) {
    ObjectSpawn* spawn;
    AnimalDef* defPtr;
    GObj* pokemonObj;

    if (block == NULL ||
        block->descriptor == NULL ||
        block->descriptor->unk_1C == NULL ||
        block->index >= MAX_BLOCKS)
    {
        return;
    }

    D_803B1288_551698[block->index] = NULL;

    spawn = block->descriptor->unk_1C;

    while (spawn->id != 0xFFFFFFFF) {
        s32 objId = func_8036396C_503D7C();
        if (!inRange_DEBUG(objId, D_8038A470_52A880, D_8038A474_52A884, "animalAdd()")) {
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
            UnkAzureCobra* uac = func_80363870_503C80();
            uac->pokemonObj = pokemonObj;
            uac->next = D_803B1288_551698[block->index];
            D_803B1288_551698[block->index] = uac;
        }

        spawn++;
    }
}

GObj* animalAddOne(WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, AnimalDef* def) {
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
    if (!inRange_DEBUG(objId, D_8038A470_52A880, D_8038A474_52A884, "animalAddOne()")) {
        return NULL;
    }

    if (def->init != NULL) {
        pokemonObj = def->init(objId, def->id, block, blockB, spawn);
    }
    if (!notNull_DEBUG(pokemonObj, "animalAddOne()")) {
        return NULL;
    }

    if (pokemonObj != NULL) {
        UnkAzureCobra* uac = func_80363870_503C80();
        uac->pokemonObj = pokemonObj;
        uac->next = D_803B1288_551698[block->index];
        D_803B1288_551698[block->index] = uac;
    }

    return pokemonObj;
}

f32 func_80363D8C_50419C(f32 arg0, f32 arg1) {
    GroundResult sp1C;

    if (getGroundAt(arg0, arg1, &sp1C)) {
        return sp1C.height;
    }
    return 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_80363DBC_5041CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_80363EB4_5042C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_8036406C_50447C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_803641B8_5045C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_80364280_504690.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/503C10/func_803642A0_5046B0.s")
