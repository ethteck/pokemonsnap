#include "sys/gtl.h"
#include "sys/om.h"
#include "sys/oh.h"

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
    objCmd->data.cmd = cmd;
    objCmd->data.source = source;

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

void cmdSendSignal(GObj* obj, GObjCmdData* param) {
    cmdSendCommand(obj, param->cmd, param->source);
}

void cmdSendCommandToLink(s32 link, s32 cmd, GObj* source) {
    GObjCmdData param;

    if (source != 0) {
        param.source = source;
    } else {
        param.source = omCurrentObject;
    }
    param.cmd = cmd;
    ohApplyByLinkEx(link, (GObj * (*)(GObj*, void*)) cmdSendSignal, (void*)&param, FALSE);
}

s32 cmdProcessCommands(void (*handler)(GObjCmdData)) {
    GObjCmdList* entry = &omCurrentObject->cmdList;
    GObjCmd* cur = entry->head;

    while (cur != NULL) {
        switch (cur->data.cmd) {
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
                omCurrentObject->flags |= GOBJ_FLAG_HIDDEN;
                break;
            case -5:
                omCurrentObject->flags &= ~GOBJ_FLAG_HIDDEN;
                break;
            default:
                if (handler != NULL) {
                    handler(cur->data);
                }
                break;
        }
        cur = cur->next;
    }

    cmdFreeObjCmd(entry);
    entry->count = 0;
    return 0;
}

void cmdReset(void) {
    cmdObjCmdList = NULL;
}
