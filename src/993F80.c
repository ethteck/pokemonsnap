#include "common.h"

typedef struct Foo_Sub {
    s32 unk4_25 : 7;
} Foo_Sub;

typedef struct Foo {
    Foo_Sub* var_0;
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
} Foo; // size: 0x8

typedef struct Bar {
    /* 0x00 */ u32 unk0; // confirmed
    /* 0x04 */ u32 unk4;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ s16 unkA; // confirmed
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s8 unk1A_15 : 1; // confirmed
    /* 0x1A */ s8 unk1A_14 : 1; // confirmed
    /* 0x1A */ s8 unk1A_13 : 1; // confirmed
    /* 0x1A */ s8 unk1A_12 : 1;
    /* 0x1A */ s8 unk1A_11 : 1;
    /* 0x1A */ s8 unk1A_10 : 1;
    /* 0x1A */ s8 unk1A_9 : 1;
    /* 0x1A */ s8 unk1A_8 : 1;
    /* 0x1A */ s8 unk1A_7 : 1;
    /* 0x1A */ s8 unk1A_6 : 1;
    /* 0x1A */ s8 unk1A_5 : 1;
    /* 0x1A */ s8 unk1A_4 : 1;
    /* 0x1A */ s8 unk1A_3 : 1;
    /* 0x1A */ s8 unk1A_2 : 1;
    /* 0x1A */ s8 unk1A_1 : 1;
    /* 0x1A */ s8 unk1A_0 : 1;
} Bar; // size: 0x1C

typedef struct Fizz {
    /*   0 */ u8 pad[0x3a0];
    /* 3a0 */ u32 unk3A0;
    /* 3a4 */ s16 unk3A4;
    /* 3a6 */ u8 unk3A6;
    /* 3a7 */ u8 unk3A7;
    /* 3a8 */ u8 unk3A8;
    /* 3a9 */ u8 unk3A9;
    /* 3aa */ s16 unk3AA;
    /* 3ac */ u16 unk3AC;
    /* 3ae */ u16 unk3AE;
    /* 3b0 */ u16 unk3B0;
    /* 3b2 */ u16 unk3B2;
    /* 3b4 */ u8 unk3B4;
} Fizz;

extern s32 D_801F4194_9A3C04;
extern s32 D_80229838_9D92A8;
extern Bar D_802291A0_9D8C10[60];
extern int (*D_801F4198_9A3C08)(const void*, const void*);

char* func_8009B9D0(s16);
void func_8001A094(void* base, s32 nitems, u32 size, int (*compar)(const void*, const void*)); // Probably qsort
s32 func_800BFB84_5CA24(void);
int func_801E4704_994174(const void*, const void*);
int func_801E47F0_994260(const void*, const void*);
int func_801E48CC_99433C(const void*, const void*);
int func_801E49A8_994418(const void*, const void*);
int func_801E4AA4_994514(const void*, const void*);

#if 0
s32 func_800BF574_5C414(s32);
void func_800BF5D8_5C478(s32, u32);
void func_800BF690_5C530(s16, u32);
void func_800BF7D4_5C674(s16, u32);
void func_800BF954_5C7F4(s32, s32, int);
Foo* func_800BFB50_5C9F0(s32);
void* func_8037452C(void*);
#endif

s32 func_801E4510_993F80(void) {
    return D_801F4194_9A3C04;
}

u32 func_801E452C_993F9C(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= func_800BFB84_5CA24())) {
        return 0;
    }
    return D_802291A0_9D8C10[arg0].unk0;
}

void* func_801E459C_99400C(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= func_800BFB84_5CA24())) {
        return NULL;
    }
    return &D_802291A0_9D8C10[arg0];
}

s32 func_801E460C_99407C(char* arg0, char* arg1) {
    s32 sp4;

    if ((arg0 == NULL) || (arg1 == NULL)) {
        return 0;
    }

    for (;; arg0++, arg1++) {
        sp4 = *arg0 - *arg1;
        if (sp4 != 0) {
            return sp4;
        }
        if ((*arg0 == 0) || (*arg1 == 0)) {
            break;
        }
    }

    return 0;
}

int func_801E4690_994100(const void* arg0, const void* arg1) {
    const Bar* lhs = arg0;
    const Bar* rhs = arg1;

    if (lhs->unk0 > rhs->unk0) {
        return 1;
    } else if (lhs->unk0 < rhs->unk0) {
        return -1;
    }

    return 0;
}

int func_801E4704_994174(const void* arg0, const void* arg1) {
    const Bar* lhs;
    const Bar* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->unk1A_15 < rhs->unk1A_15) {
        return 1;
    } else if (lhs->unk1A_15 > rhs->unk1A_15) {
        return -1;
    }

    if ((D_801F4198_9A3C08 != NULL) && (func_801E4704_994174 != D_801F4198_9A3C08)) {
        return D_801F4198_9A3C08(arg0, arg1);
    }

    return func_801E4690_994100(arg0, arg1);
}

int func_801E47F0_994260(const void* arg0, const void* arg1) {
    const Bar* lhs;
    const Bar* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->unkA < rhs->unkA) {
        return 1;
    } else if (lhs->unkA > rhs->unkA) {
        return -1;
    }

    if ((D_801F4198_9A3C08 != NULL) && (func_801E47F0_994260 != D_801F4198_9A3C08)) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

int func_801E48CC_99433C(const void* arg0, const void* arg1) {
    const Bar* lhs;
    const Bar* rhs;
    s32 sp2C;

    lhs = arg0, rhs = arg1;
    sp2C = func_801E460C_99407C(func_8009B9D0(lhs->unkA), func_8009B9D0(rhs->unkA));
    if (sp2C != 0) {
        return sp2C;
    }
    if ((D_801F4198_9A3C08 != NULL) && (func_801E48CC_99433C != D_801F4198_9A3C08)) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

int func_801E49A8_994418(const void* arg0, const void* arg1) {
    const Bar* lhs;
    const Bar* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->unk1A_14 > rhs->unk1A_14) {
        return 1;
    } else if (lhs->unk1A_14 < rhs->unk1A_14) {
        return -1;
    }

    if ((D_801F4198_9A3C08 != NULL) && (func_801E49A8_994418 != D_801F4198_9A3C08)) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}

int func_801E4AA4_994514(const void* arg0, const void* arg1) {
    const Bar* lhs;
    const Bar* rhs;

    lhs = arg0, rhs = arg1;
    if (lhs->unk1A_13 > rhs->unk1A_13) {
        return 1;
    } else if (lhs->unk1A_13 < rhs->unk1A_13) {
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
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E4690_994100);
            if (D_801F4198_9A3C08 != func_801E4690_994100) {
                D_801F4198_9A3C08 = func_801E4690_994100;
            }
            break;
        case 1:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E4704_994174);
            if (D_801F4198_9A3C08 != func_801E4704_994174) {
                D_801F4198_9A3C08 = func_801E4704_994174;
            }
            break;
        case 2:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E47F0_994260);
            if (D_801F4198_9A3C08 != func_801E47F0_994260) {
                D_801F4198_9A3C08 = func_801E47F0_994260;
            }
            break;
        case 3:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E48CC_99433C);
            if (D_801F4198_9A3C08 != func_801E48CC_99433C) {
                D_801F4198_9A3C08 = func_801E48CC_99433C;
            }
            break;
        case 4:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E49A8_994418);
            if (D_801F4198_9A3C08 != func_801E49A8_994418) {
                D_801F4198_9A3C08 = func_801E49A8_994418;
            }
            break;
        case 5:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E4AA4_994514);
            if (D_801F4198_9A3C08 != func_801E4AA4_994514) {
                D_801F4198_9A3C08 = func_801E4AA4_994514;
            }
            break;
    }
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E4E04_994874.s")
#else
void func_801E4E04_994874(void) {
    s32 sp3C;
    s32 loop_i;
    u32 loop_end;
    s32 sp30;
    s32 sp2C;
    Bar* sp28;
    Foo* sp24;
    s32 temp_t6;
    u32 temp_t7;
    s32 temp_t8;

    sp30 = func_800BFA44_5C8E4(0x3B) != 0;
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
    loop_i = 0;
    for (; loop_i < loop_end; loop_i++) {
        sp28 = &D_802291A0_9D8C10[loop_i];
        if (((sp28->unk18 * 0x20000) >> 0x1F) || ((sp28->unk18 * 0x40000) >> 0x1F)) {
            func_800BF690_5C530(sp28->unkA, sp28->unk0);
            func_800BF7D4_5C674(sp28->unkA, sp28->unk4);
            if (D_80229838_9D92A8 < 3) {
                temp_t6 = D_80229838_9D92A8 + 1;
                D_80229838_9D92A8 = temp_t6;
                func_800BF5D8_5C478(temp_t6, sp28->unk0);
            }
        }
        sp24 = func_800BFB50_5C9F0(loop_i);
        if (((u32)(sp24->unk4 * 4) >> 0x1F) == 1) {
            func_800BF954_5C7F4(sp2C, sp24->unk0, 0);
            if (sp2C == 0x3B) {
                sp30 = 1;
            }
            if (sp30 != 0) {
                sp3C = 0;
                if (func_800BFA44_5C8E4(0) != 0) {
                    do {
                        temp_t8 = sp3C + 1;
                        sp3C = temp_t8;
                    } while (func_800BFA44_5C8E4(temp_t8) != 0);
                }
                sp2C = sp3C;
            } else {
                sp2C += 1;
            }
        }
    }
}
#endif

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E5030_994AA0.s")
#else
s32 func_801E5030_994AA0(void) {
    u8 stack[0x10];
    s32 i;
    s32 sp3C;
    s32 sp34;
    Fizz* sp30;
    Bar* sp2C;
    Foo* sp24;
    s32 temp_t1;
    s32 temp_t2;

    sp34 = 0;
    D_801F4194_9A3C04 = -1;
    sp3C = func_800BFB84_5CA24();
    sp2C = &D_802291A0_9D8C10;
    i = 0;
    if (sp3C > 0) {
        do {
            sp24 = func_800BFB50_5C9F0(i);
            D_801F4194_9A3C04 = sp24->var_0->unk4_25;
            sp2C->unk1A_14 = sp24->unk4_31 * 1;
            sp2C->unk1A_13 = sp24->unk4_30 * 1;
            sp2C->unk1A_12 = sp24->unk4_2 * 1;
            if (!sp24->unk4_31 && !sp24->unk4_30) {
            } else {
                sp30 = func_8037452C(sp24->var_0);
                sp2C->unk0 = (u32)&sp24->var_0;
                if (sp30->unk3AA == 0) {
                    sp2C->unk4 = 0;
                    sp2C->unkA = 9999;
                    sp2C->unk1A_15 = 0;
                    sp2C->unk1A_11 = 1;
                    sp2C->unkC = 0;
                    sp2C->unkE = 0;
                    sp2C->unk10 = 0;
                    sp2C->unk12 = 0;
                    sp2C->unk8 = 0;
                    sp2C->unk14 = 0;
                    sp2C->unk16 = 0;
                    sp2C->unk9 = 0U;
                    sp2C->unk18 = 0;
                } else {
                    sp2C->unk4 = sp30->unk3A0;
                    sp2C->unkA = sp30->unk3AA;
                    sp2C->unk1A_15 = (func_800BF3D4_5C274(sp2C->unkA) == 0);
                    sp2C->unk1A_11 = 0;
                    sp2C->unkC = sp30->unk3B4;
                    sp2C->unkE = sp30->unk3A7;
                    sp2C->unk12 = sp30->unk3AE;
                    sp2C->unk14 = sp30->unk3AC;
                    sp2C->unk8 = sp30->unk3A8;
                    sp2C->unk10 = sp30->unk3B0;
                    sp2C->unk16 = sp30->unk3B2;
                    sp2C->unk18 = sp30->unk3A4;
                    sp2C->unk9 = sp30->unk3A6;
                    sp34 += 1;
                }
            }

            temp_t1 = i + 1;
            sp2C++;
            i = temp_t1;
        } while (temp_t1 < sp3C);
    }

    D_80229838_9D92A8 = -1;
    for (i = 0; i < 4; i++) {
        if (func_800BF574_5C414(i)) {
            D_80229838_9D92A8 = i;
        }
    }

    return sp34;
}
#endif
