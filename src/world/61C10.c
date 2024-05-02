#include "world.h"

#ifdef NON_MATCHING
void func_800E4460_61C10(UnkCoralFossa* arg0, UnkCoralFossa* arg1, UnkFuchsiaKomodo* arg2) {
    while (TRUE) {
        if ((uintptr_t)arg1->unk_14 != -1 && ((uintptr_t)arg1->unk_14 & 0xFF000000) == 0) {
            arg1->unk_14 = &arg2[(uintptr_t)arg1->unk_14];
        }
        if ((uintptr_t)arg1->unk_18 != -1 && ((uintptr_t)arg1->unk_18 & 0xFF000000) == 0) {
            arg1->unk_18 = &arg2[(uintptr_t)arg1->unk_18];
        }
        if ((uintptr_t)arg1->unk_0C != -1 && ((uintptr_t)arg1->unk_0C & 0xFF000000) == 0) {
            arg1->unk_0C = &arg0[(uintptr_t)arg1->unk_0C];
        }
        if ((uintptr_t)arg1->unk_10 != -1 && ((uintptr_t)arg1->unk_10 & 0xFF000000) == 0) {
            arg1->unk_10 = &arg0[(uintptr_t)arg1->unk_10];
        }

        if ((uintptr_t)arg1->unk_0C != -1) {
            func_800E4460_61C10(arg0, arg1->unk_0C, arg2);
        }
        if ((uintptr_t)arg1->unk_10 != -1) {
            arg1 = arg1->unk_10;
        } else {
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/world/61C10/func_800E4460_61C10.s")
void func_800E4460_61C10(UnkCoralFossa* arg0, UnkCoralFossa* arg1, UnkFuchsiaKomodo* arg2);
#endif

#ifdef NON_MATCHING
void func_800E4584_61D34(UnkCoralFossa* arg0, UnkCoralFossa* arg1, UnkFuchsiaKomodo* arg2) {
    while (TRUE) {
        if ((uintptr_t)arg1->unk_14 == -1) {
            arg1->unk_14 = NULL;
        }
        if ((uintptr_t)arg1->unk_18 == -1) {
            arg1->unk_18 = NULL;
        }
        if ((uintptr_t)arg1->unk_0C == -1) {
            arg1->unk_0C = NULL;
        }
        if ((uintptr_t)arg1->unk_10 == -1) {
            arg1->unk_10 = NULL;
        }

        if (arg1->unk_0C != NULL) {
            func_800E4584_61D34(arg0, arg1->unk_0C, arg2);
        }
        if (arg1->unk_10 != NULL) {
            arg1 = arg1->unk_10;
        } else {
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/world/61C10/func_800E4584_61D34.s")
void func_800E4584_61D34(UnkCoralFossa* arg0, UnkCoralFossa* arg1, UnkFuchsiaKomodo* arg2);
#endif

void func_800E4634_61DE4(UnkCoralFossa* arg0, UnkFuchsiaKomodo* arg1) {
    func_800E4460_61C10(arg0, arg0, arg1);
    func_800E4584_61D34(arg0, arg0, arg1);
}

UnkFuchsiaKomodo* func_800E4670_61E20(UnkCoralFossa* arg0, f32 arg1, f32 arg2) {
    while (TRUE) {
        if (arg0->unk_00 * arg1 + arg0->unk_04 * arg2 + arg0->unk_08 <= 0.0f) {
            if (arg0->unk_18 != NULL) {
                return arg0->unk_18;
            }
            if (arg0->unk_10 != NULL) {
                arg0 = arg0->unk_10;
            } else {
                break;
            }
        } else {
            if (arg0->unk_14 != NULL) {
                return arg0->unk_14;
            }
            if (arg0->unk_0C != NULL) {
                arg0 = arg0->unk_0C;
            } else {
                break;
            }
        }
    }

    return NULL;
}

UnkFuchsiaKomodo* func_800E470C_61EBC(UnkCoralFossa* arg0, f32* arg1) {
    return func_800E4670_61E20(arg0, arg1[0], arg1[1]);
}

f32 func_800E4734_61EE4(UnkFuchsiaKomodo* arg0, f32 arg1, f32 arg2) {
    if (arg0 == NULL) {
        return 0.0f;
    }
    if (arg0->unk_08 == 0.0f) {
        return 0.0f;
    }
    return -(arg0->unk_00 * arg1 + arg0->unk_04 * arg2 + arg0->unk_0C) / arg0->unk_08;
}

f32 func_800E479C_61F4C(UnkFuchsiaKomodo* arg0, f32* arg1) {
    return func_800E4734_61EE4(arg0, arg1[0], arg1[1]);
}

Vec3f* func_800E47C4_61F74(UnkFuchsiaKomodo* arg0) {
    static f32 padding1;
    static Vec3f D_800F5D48_734F8;
    if (arg0 == NULL) {
        return NULL;
    }

    D_800F5D48_734F8.x = arg0->unk_00;
    D_800F5D48_734F8.y = arg0->unk_04;
    D_800F5D48_734F8.z = arg0->unk_08;
    Vec3fNormalize(&D_800F5D48_734F8);
    return &D_800F5D48_734F8;
}

s32 func_800E4820_61FD0(UnkFuchsiaKomodo* arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return (arg0->unk_10 >> 8) & 0xFFFFFF;
}

static char padding[0x38];
