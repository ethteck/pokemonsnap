#include "common.h"
#include "string.h"

typedef struct Struct_800BEFD8 {
    /* 0x00 */ GObj* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u32 unk_08;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u32 unk_10;
    /* 0x14 */ u32 unk_14;
} Struct_800BEFD8; // size = 0x18

static Struct_800BEFD8 D_800BEF60[5];
static Struct_800BEFD8 D_800BEFD8[5];

void func_800AAF20(void) {
    s32 i;

    auSetSoundGlobalReverb(0);
    auSetBGMExtraReverb(BGM_PLAYER_MAIN, 0);
    auSetBGMExtraReverb(BGM_PLAYER_AUX, 0);
    auStopBGM();
    auSetBGMVolume(BGM_PLAYER_MAIN, 0x7F00);
    auSetBGMVolume(BGM_PLAYER_AUX, 0x7F00);
    auSetSoundGlobalVolume(0x7F);
    for (i = 0; i < 16; i++)
        auSetBGMChannelVolume(BGM_PLAYER_MAIN, i, 0x7F);
}

s8 func_800AAFB0(s16 arg0, s16 arg1, f32 arg2) {
    return ((f32) arg1 - (f32) arg0) * arg2 + arg0;
}

s16 func_800AB000(s16 arg0, s16 arg1, f32 arg2) {
    return ((f32) arg1 - (f32) arg0) * arg2 + arg0;
}

void func_800AB050(f32 arg0, s32 arg1, Struct_800AB050* arg2, Struct_800AB050* arg3, Struct_800AB050* arg4) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg2[i].unk_00 = func_800AB000(arg3[i].unk_00, arg4[i].unk_00, arg0);
        arg2[i].unk_02 = func_800AB000(arg3[i].unk_02, arg4[i].unk_02, arg0);
        arg2[i].unk_04 = func_800AB000(arg3[i].unk_04, arg4[i].unk_04, arg0);
        arg2[i].unk_0C = func_800AAFB0(arg3[i].unk_0C, arg4[i].unk_0C, arg0);
        arg2[i].unk_0D = func_800AAFB0(arg3[i].unk_0D, arg4[i].unk_0D, arg0);
        arg2[i].unk_0E = func_800AAFB0(arg3[i].unk_0E, arg4[i].unk_0E, arg0);
    }
}

s32 func_800AB138(EggStruct* arg0, f32 arg1) {
    s32 n;
    Struct_800AB050* next;

    n = arg0->timer;
    next = arg0->tempBuffer[n + 1];
    func_800AB050(arg0->timer - n, arg0->vertexCount, arg0->data, arg0->tempBuffer[n], next);
    arg0->timer += arg1;
    if ((s32) arg0->timer >= arg0->end - 1) {
        arg0->timer = arg0->end - 2 + 0.9999f;
        return false;
    } else {
        return true;
    }
}

void func_800AB1F8(EggStruct* arg0) {
    memcpy(arg0->tempBuffer[0], arg0->data, arg0->vertexCount * sizeof(Struct_800AB050));
    arg0->timer = 0.0f;
}

void func_800AB240(GObj* obj) {
    f32 tmp;
    f32 tmp2;
    u32 pan;

    while (true) {
        Struct_800BEFD8* entry = &D_800BEFD8[(s32) obj->userData];

        tmp = entry->unk_08;
        tmp2 = entry->unk_0C;

        pan = ((entry->unk_10 * (tmp2 - tmp)) / entry->unk_14) + tmp;

        auSetSoundPan(entry->unk_04, pan);
        if (entry->unk_10 >= entry->unk_14) {
            entry->unk_04 = 0;
            entry->unk_08 = 0;
            entry->unk_0C = 0;
            entry->unk_10 = 0;
            entry->unk_14 = 0;
            omDeleteGObj(obj);
            entry->unk_00 = NULL;
            ohWait(1);
        } else {
            entry->unk_10++;
        }
        ohWait(1);
    }
}

s32 func_800AB41C(s32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    s32 i;
    Struct_800BEFD8* ptr = D_800BEFD8;

    for (i = 0; i < 5; i++) {
        if (ptr->unk_00 != NULL) {
            ptr++;
            continue;
        }

        if (arg1 > 127) {
            arg1 = 127;
        }
        if (arg2 > 127) {
            arg2 = 127;
        }

        ptr->unk_04 = arg0;
        ptr->unk_08 = arg1;
        ptr->unk_0C = arg2;
        ptr->unk_10 = 0;
        ptr->unk_14 = arg3;
        ptr->unk_00 = omAddGObj(14, NULL, LINK_0, 0x80000000);
        ptr->unk_00->userData = (void*) i;
        omCreateProcess(ptr->unk_00, func_800AB240, 0, 1);
        return 0;
    }
    return -1;
}

void func_800AB518(GObj* obj) {
    f32 tmp;
    f32 tmp2;
    u32 vol;

    while (true) {
        Struct_800BEFD8* entry = &D_800BEF60[(s32) obj->userData];

        tmp = entry->unk_08;
        tmp2 = entry->unk_0C;

        vol = ((entry->unk_10 * (tmp2 - tmp)) / entry->unk_14) + tmp;
        if (vol > 0x7FFF) {
            vol = 0x7FFF;
        }
        auSetSoundVolume(entry->unk_04, vol);
        if (entry->unk_10 >= entry->unk_14) {
            entry->unk_04 = 0;
            entry->unk_08 = 0;
            entry->unk_0C = 0;
            entry->unk_10 = 0;
            entry->unk_14 = 0;
            omDeleteGObj(obj);
            entry->unk_00 = NULL;
            ohWait(1);
        } else {
            entry->unk_10++;
        }
        ohWait(1);
    }
}

s32 func_800AB700(s32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    s32 i;
    Struct_800BEFD8* ptr = D_800BEF60;

    for (i = 0; i < 5; i++) {
        if (ptr->unk_00 != NULL) {
            ptr++;
            continue;
        }

        if (arg1 > 0x7FFF) {
            arg1 = 0x7FFF;
        }
        if (arg2 > 0x7FFF) {
            arg2 = 0x7FFF;
        }

        ptr->unk_04 = arg0;
        ptr->unk_08 = arg1;
        ptr->unk_0C = arg2;
        ptr->unk_10 = 0;
        ptr->unk_14 = arg3;
        ptr->unk_00 = omAddGObj(14, NULL, LINK_0, 0x80000000);
        ptr->unk_00->userData = (void*) i;
        omCreateProcess(ptr->unk_00, func_800AB518, 0, 1);
        return 0;
    }
    return -1;
}

void func_800AB7FC(s32 arg0) {
    s32 i;
    Struct_800BEFD8* ptr;

    if (arg0 == 0) {
        ptr = D_800BEF60;
    } else if (arg0 == 1) {
        ptr = D_800BEFD8;
    }

    for (i = 0; i < 5; i++, ptr++) {
        ptr->unk_0C = 0;
        ptr->unk_10 = ptr->unk_14;
    }
}

void func_800AB874(void) {
    s32 i;
    Struct_800BEFD8* ptr = D_800BEF60;
    Struct_800BEFD8* ptr2 = D_800BEFD8;

    for (i = 0; i < 5; i++, ptr++, ptr2++) {
        ptr->unk_10 = ptr->unk_14;
        ptr->unk_0C = 0;
        ptr2->unk_10 = ptr2->unk_14;
        ptr->unk_0C = 0; // BUG: should be ptr2->unk_0C = 0;
    }
}

void func_800AB918(s32 arg0) {
    s32 i;
    Struct_800BEFD8* ptr = D_800BEF60;
    Struct_800BEFD8* ptr2 = D_800BEFD8;

    for (i = 0; i < 5; i++, ptr++, ptr2++) {
        ptr->unk_10 = 0;
        ptr->unk_14 = arg0;
        ptr->unk_0C = 0;
        ptr2->unk_10 = 0;
        ptr2->unk_14 = arg0;
        ptr->unk_0C = 0; // BUG: should be ptr2->unk_0C = 0;
    }
}

void func_800AB9A4(void) {
    s32 i;
    Struct_800BEFD8* ptr = D_800BEF60;
    Struct_800BEFD8* ptr2 = D_800BEFD8;

    for (i = 0; i < 5; i++, ptr++, ptr2++) {
        ptr->unk_00 = 0;
        ptr->unk_04 = 0;
        ptr->unk_08 = 0;
        ptr->unk_0C = 0;
        ptr->unk_10 = 0;
        ptr->unk_14 = 0;

        *ptr2 = *ptr;
    }
}
