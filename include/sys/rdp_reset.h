#ifndef SYS_RDP_RESET_H
#define SYS_RDP_RESET_H

#include <PR/gbi.h>

extern void rdpSetPreRenderFunc(void (*func)(Gfx**));
void rdpReset(Gfx** pGfxPos);
void func_80007CBC(Vp *vp);
void func_80007C20(Vp *vp, f32 arg1, f32 arg2, f32 arg3, f32 arg4);

#endif /* SYS_RDP_RESET_H */
