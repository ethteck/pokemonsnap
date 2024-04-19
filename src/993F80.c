#include "common.h"

extern s32 D_801F4194_9A3C04;

typedef struct Bar {
    /*0x00*/ u32 var_0;
    /*0x00*/ u8 pad_04[0xA - 4];
    /*0x0A*/ s16 unkA;
    /*0x0C*/ u8 pad_0C[0x1A - 0xC];
    /*0x1A*/ s16 unk1A;
} Bar;

s32 func_800BFB84_5CA24(void);
extern Bar D_802291A0_9D8C10[60];

extern int (*D_801F4198_9A3C08)(const void*, const void*);

// Probably qsort
void func_8001A094(void* base, s32 nitems, u32 size, int (*compar)(const void*, const void*));
int func_801E4704_994174(const void*, const void*);
int func_801E47F0_994260(const void*, const void*);
int func_801E48CC_99433C(const void*, const void*);
int func_801E49A8_994418(const void*, const void*);
int func_801E4AA4_994514(const void*, const void*);

s32 func_801E4510_993F80(void) {
    return D_801F4194_9A3C04;
}

s32 func_801E452C_993F9C(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= func_800BFB84_5CA24())) {
        return 0;
    }
    return D_802291A0_9D8C10[arg0].var_0;
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

    if (lhs->var_0 > rhs->var_0) {
        return 1;
    } else if (lhs->var_0 < rhs->var_0) {
        return -1;
    }

    return 0;
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E4704_994174.s")
#else
extern s32 (*D_801F4198_9A3C08)(Bar*, Bar*);

s32 func_801E4704_994174(Bar* arg0, Bar* arg1) {
    Bar* lhs = arg0;
    Bar* rhs = arg1;

    if ((lhs->unk1A >> 0xF) < (rhs->unk1A >> 0xF)) {
        return 1;
    } else if ((lhs->unk1A >> 0xF) > (rhs->unk1A >> 0xF)) {
        return -1;
    }

    if ((D_801F4198_9A3C08 != NULL) && (func_801E4704_994174 != D_801F4198_9A3C08)) {
        return D_801F4198_9A3C08(arg0, arg1);
    }

    return func_801E4690_994100(arg0, arg1);
}
#endif

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E47F0_994260.s")
#else
int func_801E47F0_994260(const void* arg0, const void* arg1) {
    const Bar* sp10 = arg0;
    const Bar* sp18 = arg1;

    if (sp10->unkA < sp18->unkA) {
        return 1;
    } else if (sp10->unkA > sp18->unkA) {
        return -1;
    }

    if ((D_801F4198_9A3C08 != NULL) && (func_801E47F0_994260 != D_801F4198_9A3C08)) {
        return D_801F4198_9A3C08(arg0, arg1);
    }
    return func_801E4690_994100(arg0, arg1);
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E48CC_99433C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E49A8_994418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E4AA4_994514.s")

void func_801E4BA0_994610(u32 arg0) {
    switch (arg0) {
        case 0:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E4690_994100);
            if (&func_801E4690_994100 != D_801F4198_9A3C08) {
                D_801F4198_9A3C08 = &func_801E4690_994100;
            }
            break;
        case 1:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), func_801E4704_994174);
            if (&func_801E4704_994174 != D_801F4198_9A3C08) {
                D_801F4198_9A3C08 = &func_801E4704_994174;
            }
            break;
        case 2:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), &func_801E47F0_994260);
            if (&func_801E47F0_994260 != D_801F4198_9A3C08) {
                D_801F4198_9A3C08 = &func_801E47F0_994260;
            }
            break;
        case 3:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), &func_801E48CC_99433C);
            if (&func_801E48CC_99433C != D_801F4198_9A3C08) {
                D_801F4198_9A3C08 = &func_801E48CC_99433C;
            }
            break;
        case 4:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), &func_801E49A8_994418);
            if (&func_801E49A8_994418 != D_801F4198_9A3C08) {
                D_801F4198_9A3C08 = &func_801E49A8_994418;
            }
            break;
        case 5:
            func_8001A094(D_802291A0_9D8C10, func_800BFB84_5CA24(), sizeof(Bar), &func_801E4AA4_994514);
            if (&func_801E4AA4_994514 != D_801F4198_9A3C08) {
                D_801F4198_9A3C08 = &func_801E4AA4_994514;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E4E04_994874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/993F80/func_801E5030_994AA0.s")
