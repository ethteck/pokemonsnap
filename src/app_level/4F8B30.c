#include "common.h"
#include "app_level.h"
#include "world/world.h"

extern s32 D_80382DC0_5231D0;
extern s8 D_80382DC4_5231D4;
extern f32 D_80382DC8_5231D8[];

extern s32 D_80382DE0_5231F0;
extern s32 D_80382DE4_5231F4;
extern s32 D_80382DE8_5231F8;
extern s32 D_80382DEC_5231FC;

extern GObj* D_803AE558_54E968;

extern s32 D_803AE568_54E978;
extern s32 D_803AE570_54E980[2];
extern u16* D_803AE578_54E988[20];
extern GObj* D_803AE5C8_54E9D8[2][20];
extern s32 D_803AE668_54EA78[2][20];
extern u16 D_803AE708_54EB18[2][20];
extern s32 D_803AE758_54EB68;
extern GObj* D_803AE75C_54EB6C;
extern s32 D_803AE760_54EB70;
extern u16 D_803AE764_54EB74;
extern s32 D_803AE768_54EB78;
extern GObj* gPokemonInFocus;
extern s32 D_803AE770_54EB80;
extern u16 D_803AE774_54EB84;
extern s32 D_803AE778_54EB88;
extern s32 D_803AE77C_54EB8C;
extern s32 D_803AE780_54EB90;
extern s32 D_803AE784_54EB94;
extern UnkThing D_803AE788_54EB98[];
extern s32 D_803AEF30_54F340;
extern u16 D_803AEF34_54F344;
extern u16 D_803AEF36_54F346;
extern u16 D_803AEF38_54F348;
extern OSMesg D_803AEF40_54F350[2];
extern OSMesgQueue D_803AEF48_54F358;

void func_80359080_4F9490(GObj* arg0);

void func_80359244_4F9654(void);
void func_8009C8E4(OMCamera* arg0, MovementState* arg1, UnkThing* arg2);

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
                D_803AE75C_54EB6C = NULL;                
            }
        }
    } else {
        D_803AE788_54EB98[D_803AEF36_54F346].unk_3A0 = NULL;
        D_803AE75C_54EB6C = NULL;
        D_803AE758_54EB68 = 0;        
    }

    if (D_803AE758_54EB68 != 0 && gDirectionIndex == -1 && (D_803AE764_54EB74 & 4)) {
        osInvalDCache(arg0, 0x25800);
        // red circle in the center of the screen
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (i != 0 && i != 4 || j != 0 && j != 4) {
                    arg0[(117 + i) * 320 + (157 + j)] = GPACK_RGBA5551(255, 0, 0, 255);
                }
            }
        }
        osWritebackDCacheAll();
    }
}

void func_80358C38_4F9048(GObj* arg0) {
    OMCamera* cam = omCurrentCamera->data.cam;
    Vp* vp = &cam->vp;
    
    D_803AEF34_54F344 = 1 - D_803AEF34_54F344;
    func_8009C8E4(gMainCamera, &gMovementState, &D_803AE788_54EB98[D_803AEF34_54F344]);
    D_803AE570_54E980[D_803AEF34_54F344] = 0;

    D_803AE778_54EB88 = vp->vp.vtrans[0] / 4 - vp->vp.vscale[0] / 4;
    D_803AE77C_54EB8C = vp->vp.vtrans[1] / 4 - vp->vp.vscale[1] / 4;
    D_803AE780_54EB90 = vp->vp.vtrans[0] / 4 + vp->vp.vscale[0] / 4;
    D_803AE784_54EB94 = vp->vp.vtrans[1] / 4 + vp->vp.vscale[1] / 4;

    if (D_803AE778_54EB88 < viScreenWidth / SCREEN_WIDTH * D_80382DE8_5231F8) {
        D_803AE778_54EB88 = viScreenWidth / SCREEN_WIDTH * D_80382DE8_5231F8;
    }
    if (D_803AE77C_54EB8C < viScreenHeight / SCREEN_HEIGHT * D_80382DE0_5231F0) {
        D_803AE77C_54EB8C = viScreenHeight / SCREEN_HEIGHT * D_80382DE0_5231F0;
    }
    if (D_803AE780_54EB90 > viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80382DEC_5231FC) {
        D_803AE780_54EB90 = viScreenWidth - viScreenWidth / SCREEN_WIDTH * D_80382DEC_5231FC;
    }
    if (D_803AE784_54EB94 > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80382DE4_5231F4) {
        D_803AE784_54EB94 = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * D_80382DE4_5231F4;
    }

    func_80359080_4F9490(NULL);
}

void func_80358E98_4F92A8(GObj* arg0) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);
    D_803AE768_54EB78 = D_803AE758_54EB68;
    gPokemonInFocus = D_803AE75C_54EB6C;
    D_803AE770_54EB80 = D_803AE760_54EB70;
    D_803AE774_54EB84 = D_803AE764_54EB74;
    D_803AEF38_54F348 = D_803AEF36_54F346;
    osSetIntMask(mask);
}

void func_80358F14_4F9324(void) {
    s32 i;

    D_803AEF30_54F340 = 0;
    D_803AE788_54EB98[0].unk_3A0 = D_803AE788_54EB98[1].unk_3A0 = NULL;

    for (i = 0; i < 12; i++) {
        D_803AE788_54EB98[0].unk_3A4[i] = D_803AE788_54EB98[1].unk_3A4[i] = NULL;
    }

    for (i = 0; i < 20; i++) {
        D_803AE578_54E988[i] = gtlMalloc(0x80, 0x40);
    }
    omLinkGObjDL(omAddGObj(0, NULL, 9, 0x80000000), func_80358C38_4F9048, 5, 0x80000001, -1);
    osCreateMesgQueue(&D_803AEF48_54F358, D_803AEF40_54F350, 2);
    scSetPostProcessFunc((void(*)(void*))func_803589D0_4F8DE0);
    D_803AEF34_54F344 = 1;
    D_803AE768_54EB78 = D_803AE758_54EB68 = 0;
    omAddGObj(0, func_80358E98_4F92A8, 0, 0x80000001);
}

void func_80359034_4F9444(void) {
    osSendMesg(&D_803AEF48_54F358, (OSMesg)D_803AEF34_54F344, OS_MESG_NOBLOCK);
}

void func_80359064_4F9474(void) {
    D_803AE568_54E978 = 1;
}

void func_80359074_4F9484(void) {
    D_803AE568_54E978 = 0;
}

extern Gfx D_80382E38_523248[];
extern Gfx D_80382DF0_523200[];

void func_80359080_4F9490(GObj* arg0) {
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    gSPDisplayList(gMainGfxPos[0]++, D_80382DF0_523200);
    gDPSetColorImage(gMainGfxPos[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, D_803AE578_54E988[D_803AE570_54E980[D_803AEF34_54F344]]);
    gSPDisplayList(gMainGfxPos[0]++, D_80382E38_523248);
    mainCameraSetScissor(&gMainGfxPos[0]);
    D_803AE5C8_54E9D8[D_803AEF34_54F344][D_803AE570_54E980[D_803AEF34_54F344]] = arg0;
    if (arg0 != NULL && GET_POKEMON(arg0) != NULL) {
        D_803AE668_54EA78[D_803AEF34_54F344][D_803AE570_54E980[D_803AEF34_54F344]] = GET_POKEMON(arg0)->id;
        D_803AE708_54EB18[D_803AEF34_54F344][D_803AE570_54E980[D_803AEF34_54F344]] = GET_POKEMON(arg0)->flags;
    } else {
        D_803AE668_54EA78[D_803AEF34_54F344][D_803AE570_54E980[D_803AEF34_54F344]] = -1;
        D_803AE708_54EB18[D_803AEF34_54F344][D_803AE570_54E980[D_803AEF34_54F344]] = 0;
    }
    if (D_803AE570_54E980[D_803AEF34_54F344] < 20) {
        D_803AE570_54E980[D_803AEF34_54F344]++;
    }
}

void func_80359244_4F9654(void) {
    s32 i, j;
    s32 cnt;

    for (i = 0; i < 20; i++) {
        osInvalDCache(D_803AE578_54E988[i], 0x80);
    }
    D_803AE758_54EB68 = 0;

    for (i = 1; i < D_803AE570_54E980[D_803AEF36_54F346]; i++) {
        do { } while (0); // required to match
        if (D_803AE5C8_54E9D8[D_803AEF36_54F346][i] != NULL) {
            cnt = 0;
            for (j = 0; j < 64; j++) {
                if (D_803AE578_54E988[i - 1][j] != D_803AE578_54E988[i][j]) {
                    cnt++;
                }
            }
            if (cnt >= 32) {
                D_803AE758_54EB68 = 1;
                D_803AE75C_54EB6C = D_803AE5C8_54E9D8[D_803AEF36_54F346][i];
                D_803AE760_54EB70 = D_803AE668_54EA78[D_803AEF36_54F346][i];
                D_803AE764_54EB74 = D_803AE708_54EB18[D_803AEF36_54F346][i];
            }
        }
    }
}

s32 func_80359420_4F9830(GObj* arg0) {
    return 0;
}

s32 func_8035FF1C_50032C(GObj*);

void func_8035942C_4F983C(GObj* arg0) {
    if (func_8035FF1C_50032C(arg0) == 0 && func_80359420_4F9830(arg0) == 0) {
        renderModelTypeIFogged(arg0);
        if (D_803AE568_54E978) {
            func_80359080_4F9490(arg0);
        }
    }
}

void func_80359484_4F9894(GObj* arg0) {
    if (func_8035FF1C_50032C(arg0) == 0 && func_80359420_4F9830(arg0) == 0) {
        renderModelTypeJFogged(arg0);
        if (D_803AE568_54E978) {
            func_80359080_4F9490(arg0);
        }
    }
}

void func_803594DC_4F98EC(GObj* arg0) {
    if (func_8035FF1C_50032C(arg0) == 0 && func_80359420_4F9830(arg0) == 0) {
        renderModelTypeBFogged(arg0);
        if (D_803AE568_54E978) {
            func_80359080_4F9490(arg0);
        }
    }
}

void func_80359534_4F9944(GObj* arg0) {
    if (func_8035FF1C_50032C(arg0) == 0 && func_80359420_4F9830(arg0) == 0) {
        renderModelTypeDFogged(arg0);
        if (D_803AE568_54E978) {
            func_80359080_4F9490(arg0);
        }
    }
}

void func_8035958C_4F999C(GObj* arg0) {
    if (func_8035FF1C_50032C(arg0) == 0 && func_80359420_4F9830(arg0) == 0) {
        renRenderModelTypeI(arg0);
        if (D_803AE568_54E978) {
            func_80359080_4F9490(arg0);
        }
    }
}

void func_803595E4_4F99F4(GObj* arg0) {
    if (func_8035FF1C_50032C(arg0) == 0 && func_80359420_4F9830(arg0) == 0) {
        renRenderModelTypeB(arg0);
        if (D_803AE568_54E978) {
            func_80359080_4F9490(arg0);
        }
    }
}

void func_8035963C_4F9A4C(GObj* arg0) {
    if (func_8035FF1C_50032C(arg0) == 0 && func_80359420_4F9830(arg0) == 0) {
        renRenderModelTypeD(arg0);
        if (D_803AE568_54E978) {
            func_80359080_4F9490(arg0);
        }
    }
}

void func_80359694_4F9AA4(GObj* arg0) {
    s32 i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 20; j++) {
            if (D_803AE5C8_54E9D8[i][j] == arg0) {
                D_803AE5C8_54E9D8[i][j] = NULL;
            }
        }
    }

    if (D_803AE758_54EB68 == 1 && arg0 == D_803AE75C_54EB6C) {
        D_803AE758_54EB68 = 0;
    }
}
