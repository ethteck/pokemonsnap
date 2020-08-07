#include "ultra64.h"
#include "functions.h"
#include "variables.h"

void osYieldThread() {
    register u32 prevInt = __osDisableInt();
    
    __osRunningThread->state = OS_STATE_RUNNABLE;
    __osEnqueueAndYield(&__osRunQueue);
    __osRestoreInt(prevInt);
}
