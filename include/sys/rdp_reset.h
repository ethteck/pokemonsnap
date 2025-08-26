#ifndef SYS_RDP_RESET_H
#define SYS_RDP_RESET_H

#include <PR/gbi.h>

extern Mtx gIdentityMatrix;

extern void rdpSetPreRenderFunc(void (*func)(Gfx**));
void rdpReset(Gfx** pGfxPos);
void func_80007CBC(Vp* vp);
void syRdpSetViewport(Vp* vp, f32 ulx, f32 uly, f32 lrx, f32 lry);

#endif /* SYS_RDP_RESET_H */
