#ifndef SYS_MAIN_H
#define SYS_MAIN_H

#include <PR/os.h>
#include <PR/ultratypes.h>

extern OSMesgQueue gThreadingQueue;
extern u64 gRspBootCode[0x20];

extern u8 gSPImemOkay;
extern u8 gSPDmemOkay;

void check_stack_probes(void);

#endif /* SYS_MAIN_H */
