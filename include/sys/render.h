#ifndef SYS_RENDER_H
#define SYS_RENDER_H

s32 renPrepareModelMatrix(Gfx** gfxPtr, DObj* dobj);
void renLoadTextures(DObj* dobj, Gfx** gfxPtr);
void ren_func_800191D8(GObj*);
void ren_func_80015448(void);
void ren_func_800177D8(Gfx** gfxPtr, OMCamera* cam, s32 mode);
void ren_func_80018CD0(s32);
void renCameraPreRender(OMCamera* cam, s32 arg1);
void renSpriteCameraRender(GObj* obj);
void renDrawSprite(GObj* arg0);
void renRenderModelTypeA(GObj* arg0);
void renRenderModelTypeB(GObj* arg0);
void renRenderModelTypeC(GObj* arg0);
void renRenderModelTypeD(GObj* arg0);
void renRenderModelTypeI(GObj* arg0);
void renRenderModelTypeJ(GObj* arg0);
void renInitCamera(Gfx** gfxPtr, OMCamera* cam, s32 mode);
void renCameraRenderObjects(GObj* camObj, s32 mode);
void renCameraPostRender(OMCamera* cam);
void renInitCameraEx(Gfx** gfxPtr, OMCamera* cam, s32 mode, u16* buffer, s32 width, s32 height, u16* zbuffer);
void renPrepareCameraMatrix(Gfx** gfxPtr, OMCamera* cam);

#endif /* SYS_RENDER_H */
