#include "common.h"
#include "PR/ultratypes.h"
#include "sys/ml.h"
#include "sys/crash.h"
#include "types.h"

void mlHeapClear(DynamicBuffer* heap) {
    heap->ptr = heap->start;
}

void* mlHeapAlloc(DynamicBuffer* heap, u32 size, u32 alignment) {
    u8* aligned;
    u32 offset;

    if (alignment != 0) {
        offset = alignment - 1;
        aligned = (u8*) (((uintptr_t) heap->ptr + (offset)) & ~(offset));
    } else {
        aligned = heap->ptr;
    }

    heap->ptr = (void*) (aligned + size);
    if (heap->end < heap->ptr) {
        error_printf("ml : alloc overflow #%d\n", heap->id);
        PANIC();
    }

    return aligned;
}

void mlHeapInit(DynamicBuffer* heap, u32 id, void* start, u32 size) {
    heap->id = id;
    heap->ptr = start;
    heap->start = start;
    heap->end = (void*) ((uintptr_t) start + size);
    bzero(start, size);
}
