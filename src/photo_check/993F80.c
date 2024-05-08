#include "common.h"

#include "photo_check.h"

typedef struct Foo2 {
    PhotoData* var_0;
    u32 unk4_31 : 1;
    u32 unk4_30 : 1;
    u32 unk4_29 : 1;
    u32 unk4_28 : 1;
    u32 unk4_27 : 1;
    u32 unk4_26 : 1;
    u32 unk4_25 : 1;
    u32 unk4_24 : 1;
    u32 unk4_23 : 1;
    u32 unk4_22 : 1;
    u32 unk4_21 : 1;
    u32 unk4_20 : 1;
    u32 unk4_19 : 1;
    u32 unk4_18 : 1;
    u32 unk4_17 : 1;
    u32 unk4_16 : 1;
    u32 unk4_15 : 1;
    u32 unk4_14 : 1;
    u32 unk4_13 : 1;
    u32 unk4_12 : 1;
    u32 unk4_11 : 1;
    u32 unk4_10 : 1;
    u32 unk4_9 : 1;
    u32 unk4_8 : 1;
    u32 unk4_7 : 1;
    u32 unk4_6 : 1;
    u32 unk4_5 : 1;
    u32 unk4_4 : 1;
    u32 unk4_3 : 1;
    u32 unk4_2 : 1;
    u32 unk4_1 : 1;
    u32 unk4_0 : 1;
} Foo2; // size = 0x8


extern s32 D_801F4194_9A3C04;
extern s32 (*D_801F4198_9A3C08)(const void*, const void*);

Photo D_802291A0_9D8C10[60];
s32 D_80229838_9D92A8;

void qsort(void* base, s32 nitems, u32 size, s32 (*compar)(const void*, const void*)); // Probably qsort
void func_800BF5D8_5C478(s32, PhotoData*);
void func_800BF690_5C530(s16, PhotoData*);
void func_800BF7D4_5C674(s16, u32);
void func_800BF954_5C7F4(s32, PhotoData*, s32);
Foo2* func_800BFB50_5C9F0(s32);
s32 func_800BFB84_5CA24(void);
s32 func_801E4704_994174(const void*, const void*);
s32 func_801E47F0_994260(const void*, const void*);
s32 func_801E48CC_99433C(const void*, const void*);
s32 func_801E49A8_994418(const void*, const void*);
s32 func_801E4AA4_994514(const void*, const void*);

s32 func_801E4510_993F80(void) {
    return D_801F4194_9A3C04;
}

PhotoData* func_801E452C_993F9C(s32 idx) {
    if (idx < 0 || idx >= func_800BFB84_5CA24()) {
        return 0;
    }
    return D_802291A0_9D8C10[idx].unk_0;
}

Photo* func_801E459C_99400C(s32 idx) {
    if (idx < 0 || idx >= func_800BFB84_5CA24()) {
        return NULL;
    }
    return &D_802291A0_9D8C10[idx];
}

s32 func_801E460C_99407C(char* arg0, char* arg1) {
    s32 sp4;

    if (arg0 == NULL || arg1 == NULL) {
        return 0;
    }

    for (; TRUE; arg0++, arg1++) {
        sp4 = *arg0 - *arg1;
        if (sp4 != 0) {
            return sp4;
        }
        if (*arg0 == 0 || *arg1 == 0) {
            break;
        }
    }

    return 0;
}

s32 func_801E4690_994100(const void* arg0, const void* arg1) {
    const Photo* lhs = arg0;
    const Photo* rhs = arg1;

    if (lhs->unk_0 > rhs->unk_0) {
        return 1;
    } else if (lhs->unk_0 < rhs->unk_0) {
        return -1;
    }

    return 0;
}

s32 func_801E4704_994174(const void* arg0, const void* arg1) {
    const Photo* lhs;
    const Photo* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->unk_1A_15 < rhs->unk_1A_15) {
        return 1;
    } else if (lhs->unk_1A_15 > rhs->unk_1A_15) {
        return -1;
    }

    if (D_801F4198_9A3C08 != NULL && D_801F4198_9A3C08 != func_801E4704_994174) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

s32 func_801E47F0_994260(const void* arg0, const void* arg1) {
    const Photo* lhs;
    const Photo* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->pkmnID < rhs->pkmnID) {
        return 1;
    } else if (lhs->pkmnID > rhs->pkmnID) {
        return -1;
    }

    if (D_801F4198_9A3C08 != NULL && D_801F4198_9A3C08 != func_801E47F0_994260) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

s32 func_801E48CC_99433C(const void* arg0, const void* arg1) {
    const Photo* lhs;
    const Photo* rhs;
    s32 sp2C;

    lhs = arg0, rhs = arg1;
    sp2C = func_801E460C_99407C(getPokemonName(lhs->pkmnID), getPokemonName(rhs->pkmnID));
    if (sp2C != 0) {
        return sp2C;
    }
    if (D_801F4198_9A3C08 != NULL && D_801F4198_9A3C08 != func_801E48CC_99433C) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

s32 func_801E49A8_994418(const void* arg0, const void* arg1) {
    const Photo* lhs;
    const Photo* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->unk_1A_14 > rhs->unk_1A_14) {
        return 1;
    } else if (lhs->unk_1A_14 < rhs->unk_1A_14) {
        return -1;
    }

    if (D_801F4198_9A3C08 != NULL && D_801F4198_9A3C08 != func_801E49A8_994418) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

s32 func_801E4AA4_994514(const void* arg0, const void* arg1) {
    const Photo* lhs;
    const Photo* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->unk_1A_13 > rhs->unk_1A_13) {
        return 1;
    } else if (lhs->unk_1A_13 < rhs->unk_1A_13) {
        return -1;
    }

    if ((D_801F4198_9A3C08 != NULL) && (func_801E4AA4_994514 != D_801F4198_9A3C08)) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

void func_801E4BA0_994610(u32 arg0) {
    switch (arg0) {
        case 0:
            qsort(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Photo), func_801E4690_994100);
            if (D_801F4198_9A3C08 != func_801E4690_994100) {
                D_801F4198_9A3C08 = func_801E4690_994100;
            }
            break;
        case 1:
            qsort(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Photo), func_801E4704_994174);
            if (D_801F4198_9A3C08 != func_801E4704_994174) {
                D_801F4198_9A3C08 = func_801E4704_994174;
            }
            break;
        case 2:
            qsort(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Photo), func_801E47F0_994260);
            if (D_801F4198_9A3C08 != func_801E47F0_994260) {
                D_801F4198_9A3C08 = func_801E47F0_994260;
            }
            break;
        case 3:
            qsort(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Photo), func_801E48CC_99433C);
            if (D_801F4198_9A3C08 != func_801E48CC_99433C) {
                D_801F4198_9A3C08 = func_801E48CC_99433C;
            }
            break;
        case 4:
            qsort(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Photo), func_801E49A8_994418);
            if (D_801F4198_9A3C08 != func_801E49A8_994418) {
                D_801F4198_9A3C08 = func_801E49A8_994418;
            }
            break;
        case 5:
            qsort(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Photo), func_801E4AA4_994514);
            if (D_801F4198_9A3C08 != func_801E4AA4_994514) {
                D_801F4198_9A3C08 = func_801E4AA4_994514;
            }
            break;
    }
}

void func_801E4E04_994874(void) {
    s32 sp3C;
    s32 loop_i;
    s32 loop_end;
    s32 sp30;
    s32 sp2C;
    Photo* sp28;
    Foo2* sp24;

    sp30 = !!func_800BFA44_5C8E4(0x3B);
    sp2C = 0;
    if (sp30 == 0) {
        for (loop_i = 0; loop_i < 0x3B; loop_i++) {
            if (func_800BFA44_5C8E4(loop_i) != 0) {
                sp2C = loop_i + 1;
            }
        }
    } else {
        for (loop_i = 0; func_800BFA44_5C8E4(loop_i) != 0; loop_i++) {}
        sp2C = loop_i;
    }

    loop_end = func_800BFB84_5CA24();

    for (loop_i = 0, sp28 = &D_802291A0_9D8C10[0]; loop_i < loop_end; sp28++, loop_i++) {
        if (sp28->unk_1A_14 || sp28->unk_1A_13) {
            func_800BF690_5C530(sp28->pkmnID, sp28->unk_0);
            func_800BF7D4_5C674(sp28->pkmnID, sp28->unk_4);
            if (D_80229838_9D92A8 < 3) {
                // D_80229838_9D92A8 is being pre-incremented here. It seems to match better this way so far. Weird though...
                func_800BF5D8_5C478(++D_80229838_9D92A8, sp28->unk_0);
            }
        }
        sp24 = func_800BFB50_5C9F0(loop_i);
        if (sp24->unk4_29 == 1) {
            func_800BF954_5C7F4(sp2C, sp24->var_0, 0);
            if (sp2C == 0x3B) {
                sp30 = 1;
            }
            if (sp30 != 0) {
                for (sp3C = 0; func_800BFA44_5C8E4(sp3C) != 0; sp3C++) {}
                sp2C = sp3C;
            } else {
                sp2C++;
            }
        }
    }
}

s32 func_801E5030_994AA0(void) {
    s32 i;
    UNUSED s32 pad;
    s32 loopEnd;
    UNUSED s32 pad2;
    s32 sp34;
    Unk803A6C18* sp30;
    Photo* photo;
    UNUSED s32 pad3;
    Foo2* sp24;

    sp34 = 0;
    D_801F4194_9A3C04 = -1;
    loopEnd = func_800BFB84_5CA24();
    for (i = 0, photo = &D_802291A0_9D8C10[0]; i < loopEnd; photo++, i++) {
        sp24 = func_800BFB50_5C9F0(i);
        D_801F4194_9A3C04 = sp24->var_0->levelID;
        photo->unk_1A_14 = sp24->unk4_31;
        photo->unk_1A_13 = sp24->unk4_30;
        photo->unk_1A_12 = sp24->unk4_29;
        if (!sp24->unk4_31 && !sp24->unk4_30) {

        } else {
            sp30 = func_8037452C_847CDC(sp24->var_0);
            photo->unk_0 = sp24->var_0;
            if (sp30->unk_3AA == 0) {
                photo->unk_4 = 0;
                photo->pkmnID = 9999;
                photo->unk_1A_15 = 0;
                photo->unk_1A_11 = 1;
                photo->specialID = 0;
                photo->isWellFramed = FALSE;
                photo->posePts = 0;
                photo->sizeParam1 = 0;
                photo->commentID = 0;
                photo->sizeParam2 = 0;
                photo->specialBonus = 0;
                photo->unk_9 = 0;
                photo->samePkmnBonus = 0;
            } else {
                photo->unk_4 = sp30->unk_3A0;
                photo->pkmnID = sp30->unk_3AA;
                photo->unk_1A_15 = !func_800BF3D4_5C274(photo->pkmnID);
                photo->unk_1A_11 = 0;
                photo->specialID = sp30->unk_3B4;
                photo->isWellFramed = sp30->unk_3A7;
                photo->sizeParam1 = sp30->unk_3AE;
                photo->sizeParam2 = sp30->unk_3AC;
                photo->commentID = sp30->unk_3A8;
                photo->posePts = sp30->unk_3B0;
                photo->specialBonus = sp30->unk_3B2;
                photo->samePkmnBonus = sp30->unk_3A4;
                photo->unk_9 = sp30->unk_3A6;
                sp34++;
            }
        }
    }

    D_80229838_9D92A8 = -1;
    for (i = 0; i < 4; i++) {
        if (func_800BF574_5C414(i)) {
            D_80229838_9D92A8 = i;
        }
    }

    return sp34;
}
