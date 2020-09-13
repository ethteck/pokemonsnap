#include "common.h"

// Works with -O2 as well

OSPri osGetThreadPri(OSThread* thread) {
    if (thread == NULL) {
        thread = __osRunningThread;
    }
    
    return thread->priority;
}