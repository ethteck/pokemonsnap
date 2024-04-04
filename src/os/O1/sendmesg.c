#include "variables.h"

#include "PR/os_internal_reg.h"
#include "os/osint.h"

s32 osSendMesg(OSMesgQueue* mq, OSMesg mesg, s32 flag) {
    register u32 s0 = __osDisableInt();
    register u32 index;

    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_BLOCK) {
            __osRunningThread->state = OS_STATE_WAITING;
            __osEnqueueAndYield(&mq->fullqueue);
        } else {
            __osRestoreInt(s0);
            return -1;
        }
    }

    index = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[index] = mesg;
    mq->validCount++;

    if (mq->mtqueue->next != NULL) {
        osStartThread(__osPopThread(&mq->mtqueue));
    }

    __osRestoreInt(s0);

    return 0;
}
