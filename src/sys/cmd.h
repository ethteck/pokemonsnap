#ifndef SYS_CMD_H
#define SYS_CMD_H

#include <PR/ultratypes.h>

struct GObj;

typedef struct GObjCmd {
    /* 0x00 */ struct GObjCmd* next;
    /* 0x04 */ struct GObj* source;
    /* 0x08 */ s32 cmd;
} GObjCmd; // size = 0xC

typedef struct GObjCmdList {
    /* 0x00 */ GObjCmd* head;
    /* 0x04 */ GObjCmd* tail;
    /* 0x08 */ s32 count;
} GObjCmdList; // size = 0xC

void cmdFreeObjCmd(GObjCmdList*);
void cmdReset(void);

#endif /* SYS_CMD_H */
