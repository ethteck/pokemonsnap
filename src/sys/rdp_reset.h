#ifndef SYS_RDP_RESET_H
#define SYS_RDP_RESET_H

#include <PR/gbi.h>

extern void rdpSetPreRenderFunc(void (*func)(Gfx**));
void rdpReset(Gfx** pGfxPos);

#endif /* SYS_RDP_RESET_H */
