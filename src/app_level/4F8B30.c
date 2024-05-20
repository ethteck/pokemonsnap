#include "common.h"
#include "app_level.h"

typedef struct UnkGoldCheetah {
    /* 0x000 */ char unk_000[0x3A0];
    /* 0x3A0 */ s32 unk_3A0;
    /* 0x3A4 */ s32 unk_3A4[12];
} UnkGoldCheetah; // size 0x3D4

extern s32 D_80382DC0_5231D0;
extern s8 D_80382DC4_5231D4;
extern f32 D_80382DC8_5231D8[];

extern GObj* D_803AE558_54E968;
extern s32 D_803AE758_54EB68;
extern s32 D_803AE75C_54EB6C;
extern s32 D_803AE760_54EB70;
extern u16 D_803AE764_54EB74;
extern UnkGoldCheetah D_803AE788_54EB98[];
extern u16 D_803AEF36_54F346;
extern OSMesgQueue D_803AEF48_54F358;

void func_80359244_4F9654(void);

void func_80358720_4F8B30(GObj* arg0) {
    GObj* pokemonObj;
    u8 s2 = 0;

    while (TRUE) {
        f32 f20 = FLOAT_MAX;
        for (pokemonObj = omGObjListHead[LINK_POKEMON]; pokemonObj != NULL; pokemonObj = pokemonObj->next) {
            Pokemon* pokemon = GET_POKEMON(pokemonObj);
            if (pokemon->tangible && pokemon->flags & 0x20) {
                if (f20 > pokemon->playerDist - pokemon->collisionRadius) {
                    f20 = pokemon->playerDist - pokemon->collisionRadius;
                }
            }
        }

        if (f20 > D_80382DC8_5231D8[0]) {
            D_80382DC0_5231D0 = 0;
        } else if (f20 > D_80382DC8_5231D8[1]) {
            D_80382DC0_5231D0 = 1;
        } else if (f20 > D_80382DC8_5231D8[2]) {
            D_80382DC0_5231D0 = 2;
        } else if (f20 > D_80382DC8_5231D8[3]) {
            D_80382DC0_5231D0 = 3;
        } else {
            D_80382DC0_5231D0 = -1;
            cmdSendCommand(gObjPlayer, PLAYER_CMD_4, arg0);
        }

        if (D_80382DC0_5231D0 > 0) {
            s2 = 1 - s2;
        }
        ohWait(1);
    }
}

void func_803588D4_4F8CE4(void) {
    D_80382DC0_5231D0 = 0;
    D_803AE558_54E968 = omAddGObj(8, &ohUpdateDefault, 0, 0x80000000);
    omCreateProcess(D_803AE558_54E968, func_80358720_4F8B30, 0, 9);
    D_80382DC4_5231D4 = 1;
}

void func_80358938_4F8D48(void) {
    D_80382DC4_5231D4 = 0;
    ohPauseObjectProcesses(D_803AE558_54E968);
}

void func_80358964_4F8D74(void) {
    D_80382DC4_5231D4 = 1;
    ohResumeObjectProcesses(D_803AE558_54E968);
}

void func_80358994_4F8DA4(s32 arg0) {
    if (D_803AE558_54E968 != NULL) {
        omDeleteGObj(D_803AE558_54E968);
        D_803AE558_54E968 = NULL;
    }
}

void func_803589D0_4F8DE0(u16* arg0) {
    s32 i, j;
    s32 unused;
    OSMesg sp38;

    if (osRecvMesg(&D_803AEF48_54F358, &sp38, OS_MESG_NOBLOCK) == -1) {
        return;
    }

    D_803AEF36_54F346 = (u16)sp38;
    func_80359244_4F9654();

    if (D_803AE758_54EB68 != 0 && D_803AE75C_54EB6C != 0) {
        if (D_803AE760_54EB70 == 0x3EC || D_803AE760_54EB70 == 0x3FA || D_803AE760_54EB70 == 0x3FE || D_803AE760_54EB70 == 0x40B) {
            D_803AE788_54EB98[D_803AEF36_54F346].unk_3A0 = D_803AE75C_54EB6C;
        } else {
            for (i = 0; i < 12; i++) {
                if (D_803AE788_54EB98[D_803AEF36_54F346].unk_3A4[i] == D_803AE75C_54EB6C) {
                    D_803AE788_54EB98[D_803AEF36_54F346].unk_3A0 = D_803AE75C_54EB6C;
                    break;
                }
            }
            if (i >= 12) {
                D_803AE758_54EB68 = 0;
                D_803AE75C_54EB6C = 0;                
            }
        }
    } else {
        D_803AE788_54EB98[D_803AEF36_54F346].unk_3A0 = 0;
        D_803AE75C_54EB6C = 0;
        D_803AE758_54EB68 = 0;        
    }

    if (D_803AE758_54EB68 != 0 && gDirectionIndex == -1 && (D_803AE764_54EB74 & 4)) {
        osInvalDCache(arg0, 0x25800);
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (i != 0 && i != 4 || j != 0 && j != 4) {
                    // all except corners
                    arg0[(117 + i) * 320 + (157 + j)] = GPACK_RGBA5551(255, 0, 0, 255);
                }
            }
        }
        osWritebackDCacheAll();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80358C38_4F9048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80358E98_4F92A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80358F14_4F9324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359034_4F9444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359064_4F9474.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359074_4F9484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359080_4F9490.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359244_4F9654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359420_4F9830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_8035942C_4F983C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359484_4F9894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_803594DC_4F98EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359534_4F9944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_8035958C_4F999C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_803595E4_4F99F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_8035963C_4F9A4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_level/4F8B30/func_80359694_4F9AA4.s")
