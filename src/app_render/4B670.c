#include "common.h"
#include "app_render.h"
#include "photo_check/photo_check.h"

extern u16 D_800AE7C4;
extern u16 D_800AE7C8;
extern Gfx D_800AE7D0[];
extern Gfx D_800AE8F8[];

extern GObj* D_800BDF30[];
extern s32 D_800BDF60;
extern GObj* D_800BDFA8;
extern PhotoData* D_800BDFAC;
extern s32 D_800BDFB0;
extern s32 D_800BDFB4;
extern s32 D_800BDFB8[];
extern s32 D_800BDFE8[];
extern u16 D_800BE01A;
extern s32 D_800BE0B0[];
extern s32 D_800BE110[];
extern s32 D_800BE140[];
extern SubUnk803A6C18 D_800BE170;
extern s8 D_800BE178;

s32 func_8009FCC0(void) {
    return 0xA4;
}

void func_8009FCC8(GObj* obj) {
    OMCamera* cam;
    GObj* it;
    s32 dllink;
    u32 bitMask;
    u32 unk_38;
    f32 aspect;

    if (D_800AE7C8 == 0) {
        return;
    }

    func_8009FA68(D_800BDFA8->data.cam, D_800BDFAC);
    D_800AE7C8 = 0;
    omCurrentCamera = obj;
    cam = obj->data.cam;
    cam->flags |= CAMERA_FLAG_10;
    if (D_800AE7C4) {
        cam->perspMtx.persp.fovy *= 2.0f;
    }

    cam->vp.vp.vscale[0] = 128;
    cam->vp.vp.vscale[1] = 96;
    cam->vp.vp.vtrans[0] = 128;
    cam->vp.vp.vtrans[1] = 96;

    gSPViewport(gMainGfxPos[0]++, &cam->vp);
    gSPSegment(gMainGfxPos[0]++, 0x0F, D_800BDFB0);
    gSPSegment(gMainGfxPos[0]++, 0x0C, D_800BDFB4);
    gSPDisplayList(gMainGfxPos[0]++, D_800AE8F8);

    aspect = cam->perspMtx.persp.aspect;
    cam->perspMtx.persp.aspect = 4.0f / 3.0f;
    renPrepareCameraMatrix(&gMainGfxPos[0], cam);
    cam->perspMtx.persp.aspect = aspect;

    D_800BE01A = 0;
    dllink = 0;
    bitMask = obj->dlLinkBitMask;
    unk_38 = obj->unk_38;
    while (bitMask != 0) {
        if (bitMask & 1) {
            for (it = omGObjListDlHead[dllink]; it != NULL; it = it->nextDl) {
                if ((it->flags & GOBJ_FLAG_HIDDEN) || !(obj->cameraTag & it->cameraTag)) {
                    continue;
                }
                omRenderedObject = it;
                if (it == D_800BDF30[D_800BE01A] && D_800BE01A < D_800BDF60) {
                    gSPSegment(gMainGfxPos[0]++, 0x0A, D_800BDFB8[D_800BE01A]);
                    gSPSegment(gMainGfxPos[0]++, 0x0B, D_800BDFE8[D_800BE01A]);
                    D_800BE01A++;
                    gSPDisplayList(gMainGfxPos[0]++, D_800AE7D0);
                    it->fnRender(it);
                    gDPPipeSync(gMainGfxPos[0]++);
                    gDPSetDepthImage(gMainGfxPos[0]++, 0x0C000000);
                }
                it->fnRender(it);
                it->lastDrawFrame = gtlDrawnFrameCounter;
                if (1) {
                } // required to match
            }
        }
        bitMask >>= 1;
        unk_38 >>= 1;
        dllink++;
    }

    renCameraPostRender(cam);
    cam->flags &= ~CAMERA_FLAG_10;
    if (D_800AE7C4) {
        cam->perspMtx.persp.fovy /= 2.0f;
    }
}

void func_800A007C(GObj*, PhotoData*, u16, u16*);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A007C.s")

f32 func_800A0504(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return (arg4 - arg3) * (arg0 - arg1) / (arg2 - arg1) + arg3;
}

#ifdef NON_MATCHING
void func_800A0534(SubUnk803A6C18* arg0, UnkThing* arg1, s32 arg2, s32 arg3) {
    f32 var_f2;
    u16 new_var;
    s32 temp_lo;
    s32 new_var2;
    s32 var_v1;
    s32* temp_a0;
    s32* temp_a1;

    if (arg3 == PokemonID_SHELLDER || arg3 == PokemonID_603) {
        if (arg1->main.unk_20[D_800BDF68[arg2]].pokemonID != PokemonID_SHELLDER &&
            arg1->main.unk_20[D_800BDF68[arg2]].pokemonID != PokemonID_603) {
            return;
        }
    } else if (arg3 != arg1->main.unk_20[D_800BDF68[arg2]].pokemonID) {
        return;
    }

    temp_a1 = &D_800BE0B0[arg2];
    temp_a0 = &D_800BE110[arg2];
    var_v1 = *temp_a1;
    if (var_v1 > 0x300) {
        var_v1 = 0x300;
    }
    if (var_v1 >= 4 && (*temp_a0) > 0) {
        // TODO remove dumb
        if (1) {
        }
        new_var2 = 10;
        new_var = ((func_800A0504(var_v1, 4.0f, 768.0f, 0.2f, 1.0f) * 1000.0f) + 5.0f) / 10.0f;
        new_var2 = new_var * new_var2;
        var_f2 = ((f32) (*temp_a1)) / ((f32) (*temp_a0));
        if (var_f2 > 1.0) {
            var_f2 = 1.0f;
        }
        arg0->unk_04 += ((u16) (((var_f2 * new_var2) + 5.0f) / 10.0f)) * 10;
        arg0->unk_00 += ((u16) (((var_f2 * new_var2) + 5.0f) / 10.0f)) * 10;
        arg0->unk_06++;
    }
}
#else
void func_800A0534(SubUnk803A6C18*, UnkThing* arg1, s32 arg2, s32 arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A0534.s")
#endif

void func_800A081C(SubUnk803A6C18*, PhotoData*, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A081C.s")

void func_800A0E9C(SubUnk803A6C18* arg0) {
}

#ifdef NON_MATCHING
struct SubUnk803A6C18* func_800A0EA4(GObj* arg0, PhotoData* arg1, u16* arg2, s32 arg3, s32 arg4, u16* arg5) {
    s32 sp40;
    s32 sp3C;
    s32 sp24;
    f32 temp_f0;
    s32 temp_v0;
    s32 id;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 photoIdx;
    s32 var_a2;
    s32 var_ra;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t1;
    s32 var_t2;
    s32 var_t3;
    s32 var_v1;
    s32* temp_a1;
    s32* var_a3;

    D_800BE170.unk_00 = 0;
    D_800BE170.unk_0A = 0;
    D_800BE170.unk_14 = 0;
    D_800BE170.unk_0C = 0;
    D_800BE170.unk_0E = 0;
    D_800BE170.unk_12 = 0;
    D_800BE170.unk_08 = 0;
    D_800BE170.unk_08 = 0;
    D_800BE170.unk_10 = 0;
    D_800BE178 = 0;
    D_800BE170.unk_07 = 0;
    D_800BE170.unk_04 = 0;
    D_800BE170.unk_06 = 0;

    temp_v0 = func_8009BCC4(arg1);
    if (temp_v0 > 0) {
        switch (temp_v0) {
            case PokemonID_1004:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.unk_00 = 0;
                    D_800BE170.unk_0A = temp_v0;
                } else {
                    D_800BE170.unk_0A = 500;
                }
                break;
            case PokemonID_1010:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.unk_00 = 0;
                    D_800BE170.unk_0A = temp_v0;
                } else {
                    D_800BE170.unk_0A = 500;
                }
                break;
            case PokemonID_1018:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.unk_00 = 0;
                    D_800BE170.unk_0A = temp_v0;
                } else {
                    D_800BE170.unk_0A = 500;
                }
                break;
            case PokemonID_1022:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.unk_00 = 0;
                    D_800BE170.unk_0A = temp_v0;
                } else {
                    D_800BE170.unk_0A = 500;
                }
                break;
            case PokemonID_KOFFING_SMOKE:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.unk_00 = 0;
                    D_800BE170.unk_0A = temp_v0;
                } else {
                    D_800BE170.unk_0A = 500;
                }
                break;
            case PokemonID_1035:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.unk_00 = 0;
                    D_800BE170.unk_0A = temp_v0;
                } else {
                    D_800BE170.unk_0A = 500;
                }
                break;
            case PokemonID_MOLTRES_EGG:
            case PokemonID_601:
            case PokemonID_602:
                D_800BE170.unk_0A = temp_v0;
                break;
            default:
                if (func_8009BDDC(arg1->unk_20[0].pokemonID, arg1->unk_20[0].unk_00_13) < 0.0f) {
                    D_800BE170.unk_0A = 500;
                }
                break;
        }

        if (D_800BE170.unk_0A > 0) {
            func_800A0E9C(&D_800BE170);

            return &D_800BE170;
        }
    }

    var_t0 = 0;
    for (var_v1 = 0; var_v1 < 12; var_v1++) {
        id = arg1->unk_20[var_v1].pokemonID;
        if (id == -1) {
            break;
        }

        if ((id > 0 && id <= POKEDEX_MAX) ||
            id == PokemonID_603 || id == PokemonID_MOLTRES_EGG ||
            id == PokemonID_601 || id == PokemonID_602) {
            var_t0++;
        }
    }

    func_800A007C(arg0, arg1, var_t0, arg2);
    if (temp_v0 > 0 && D_800BE0B0[0] >= 12 && D_800BE110[0] > 0 && (((f32) D_800BE0B0[0] / (f32) D_800BE110[0]) >= 0.05f)) {
        func_800A081C(&D_800BE170, arg1, 0);
        func_800A0E9C(&D_800BE170);
    } else {
        temp_v0 = -1;
        sp3C = -1;
        sp40 = -1;
        sp24 = -1;
        var_t0_2 = -1;
        var_t1 = -1;
        var_t2 = -1;
        var_t3 = -1;
        var_ra = -1;
        photoIdx = 0;

        var_a3 = D_800BE0B0;
        var_a2 = 0;
        while (var_a2 < D_800BE01A) {

            temp_v1 = *var_a3;
            var_a3++;
            if (temp_v1 >= 0xC) {
                temp_v0_3 = D_800BE110[var_a2];
                if (temp_v0_3 != 0) {
                    temp_f0 = (f32) temp_v1 / (f32) temp_v0_3;
                    if (!(temp_f0 < 0.2f)) {
                        id = arg1->unk_20[photoIdx].pokemonID;
                        temp_a1 = &D_800BE140[var_a2];
                        if ((id > POKEDEX_MAX && id != PokemonID_603) || temp_f0 < 0.65f) {
                            if (*temp_a1 == 0) {
                                if (var_t2 < temp_v1) {
                                    var_t2 = temp_v1;
                                    sp3C = photoIdx;
                                }
                            } else if (var_t0_2 < temp_v1) {
                                var_t0_2 = temp_v1;
                                var_ra = photoIdx;
                            }
                        } else if (*temp_a1 == 0) {
                            if (var_t3 < temp_v1) {
                                var_t3 = temp_v1;
                                temp_v0 = photoIdx;
                            }
                        } else if (var_t1 < temp_v1) {
                            var_t1 = temp_v1;
                            sp40 = photoIdx;
                        }
                    }
                }
            }
            photoIdx++;
            var_a2++;
        }
        arg1->unk_00_10 = 0;
        if (sp40 >= 0) {
            sp24 = sp40;
        } else if (var_ra >= 0) {
            sp24 = var_ra;
        } else if (temp_v0 >= 0) {
            sp24 = temp_v0;
        } else if (sp3C >= 0) {
            sp24 = sp3C;
        }
        if (sp24 == -1) {
            func_800A0E9C(&D_800BE170);
        } else {
            func_800A081C(&D_800BE170, arg1, sp24);
            func_800A0E9C(&D_800BE170);
        }
    }
    return &D_800BE170;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A0EA4.s")
#endif
