#include "sys/gtl.h"
#include "sys/om.h"
#include "sys/oh.h"

struct SignalParam {
    GObj* obj;
    s32 cmd; 
};

s32 padding1[4];
GObjCmd* cmdObjCmdList;

GObjCmd* cmdGetObjCmd(void) {
    GObjCmd* ret;

    if (cmdObjCmdList != NULL) {
        ret = cmdObjCmdList;
        cmdObjCmdList = cmdObjCmdList->next;
    } else {
        ret = gtlMalloc(sizeof(GObjCmd), 4);
    }
    return ret;
}

void cmdFreeObjCmd(GObjCmdList* entry) {
    GObjCmd* last = entry->tail;
    if (last != NULL) {
        last->next = cmdObjCmdList;
        cmdObjCmdList = entry->head;
        entry->head = NULL;
        entry->tail = NULL;
    }
}

s32 cmdSendCommand(GObj* obj, s32 cmd, GObj* source) {
    GObjCmd* objCmd;

    if (obj == NULL) {
        obj = omCurrentObject;
    }
    if (source == NULL) {
        source = omCurrentObject;
    }
    objCmd = cmdGetObjCmd();
    objCmd->cmd = cmd;
    objCmd->source = source;

    if (obj->cmdList.head == NULL) {
        obj->cmdList.tail = objCmd;
        obj->cmdList.head = objCmd;
    } else {
        obj->cmdList.tail->next = objCmd;
        obj->cmdList.tail = objCmd;
    }
    objCmd->next = NULL;
    obj->cmdList.count++;
    return 0;
}

void cmdSendSignal(GObj* obj, struct SignalParam* param) {
    cmdSendCommand(obj, param->cmd, param->obj);
}

void cmdSendCommandToLink(s32 link, s32 cmd, GObj* source) {
    struct SignalParam param;

    if (source != 0) {
        param.obj = source;
    } else {
        param.obj = omCurrentObject;
    }
    param.cmd = cmd;
    ohApplyByLinkEx(link, (GObj* (*)(GObj*, void*))cmdSendSignal, (void*)&param, FALSE);
}

#ifdef NON_MATCHING
s32 cmdProcessCommands(void (*handler)(GObj*, s32)) {
    GObjCmdList* entry = &omCurrentObject->cmdList;
    GObjCmd* cur = entry->head;

    while (cur != NULL) {
        switch (cur->cmd) {
            case -1:
                omDeleteGObj(NULL);
                return 1;
            case -2:
                ohPauseObjectProcesses(NULL);
                break;
            case -3:
                ohResumeObjectProcesses(NULL);
                break;
            case -4:
                omCurrentObject->flags |= GOBJ_FLAG_1;
                break;
            case -5:
                omCurrentObject->flags &= ~GOBJ_FLAG_1;
                break;
            default:
                if (handler != NULL) {
                    handler(cur->source, cur->cmd);
                }
                break;
        }
        cur = cur->next;
    }

    cmdFreeObjCmd(entry);
    entry->count = 0;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/cmd/cmdProcessCommands.s")
s32 cmdProcessCommands(void (*handler)(GObj*, s32));
#endif

void cmdReset(void) {
    cmdObjCmdList = NULL;
}
