#include "common.h"

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
    if (D_800AE7C4)  {
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
                if (1) {} // required to match
            }
        }
        bitMask >>= 1;
        unk_38 >>= 1;
        dllink++;
    }

    renCameraPostRender(cam);
    cam->flags &= ~CAMERA_FLAG_10;
    if (D_800AE7C4)  {
        cam->perspMtx.persp.fovy /= 2.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A007C.s")

f32 func_800A0504(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return (arg4 - arg3) * (arg0 - arg1) / (arg2 - arg1) + arg3;
}

void func_800A0534(void* arg0, UnkThing* arg1, s32 arg2, s32 arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A0534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A081C.s")

void func_800A0E9C(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A0EA4.s")
