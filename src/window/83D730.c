#include "common.h"
#include "window.h"

#define NEXT_CHUNK(x) (HeapChunk*) ((uintptr_t) (x) + x->size)
#define PREV_CHUNK(x) (x)->prev
#define GET_CHUNK(x) (HeapChunk*) ((u32) (x) - offsetof(HeapChunk, v.data))

typedef struct HeapChunk HeapChunk;
struct HeapChunk {
    /* 0x00 */ HeapChunk* prev;
    /* 0x04 */ s32 size;
    /* 0x08 */ s32 allocated;
    /* 0x0C */ u8 pad_0C[4];
    /* 0x10 */ union {
        struct {
            /* 0x10 */ struct HeapChunk* next;
            /* 0x14 */ struct HeapChunk* prev;
        } link;
        u8 data[1];
    } v;
}; // size >= 0x18

static HeapChunk* D_803A6900_87A0B0;
static s32 D_803A6904_87A0B4;
static HeapChunk* D_803A6908_87A0B8;
static HeapChunk D_803A6910_87A0C0;

void UIMem_Link(HeapChunk* prev, HeapChunk* curr, HeapChunk* next) {
    prev->v.link.next = curr;
    curr->v.link.next = next;
    next->v.link.prev = curr;
    curr->v.link.prev = prev;
}

void UIMem_AddChunk(HeapChunk* arg0) {
    UIMem_Link(D_803A6910_87A0C0.v.link.prev, arg0, &D_803A6910_87A0C0);
}

void UIMem_Unlink(HeapChunk* chunk) {
    HeapChunk* prev = chunk->v.link.prev;
    HeapChunk* next = chunk->v.link.next;

    prev->v.link.next = next;
    next->v.link.prev = prev;
}

void UIMem_InitHeap(u8* base, s32 size) {
    HeapChunk* header;

    D_803A6904_87A0B4 = size;
    D_803A6900_87A0B0 = (HeapChunk*) base;
    D_803A6908_87A0B8 = (HeapChunk*) ((uintptr_t) D_803A6900_87A0B0 + size);

    header = D_803A6900_87A0B0;
    header->prev = NULL;
    header->size = size;
    header->allocated = FALSE;

    UIMem_Link(&D_803A6910_87A0C0, header, &D_803A6910_87A0C0);
}

HeapChunk* UIMem_FindChunk(s32 size) {
    HeapChunk* cur;

    for (cur = D_803A6910_87A0C0.v.link.next; cur != &D_803A6910_87A0C0; cur = cur->v.link.next) {
        if (cur->size >= size) {
            return cur;
        }
    }

    return NULL;
}

HeapChunk* UIMem_SplitChunk(HeapChunk* chunk, u32 offset) {
    HeapChunk* child;
    HeapChunk* next;

    child = (HeapChunk*) ((u32) chunk + offset);

    child->prev = chunk;
    child->size = chunk->size - offset;
    child->allocated = FALSE;

    next = NEXT_CHUNK(child);
    if (next < D_803A6908_87A0B8) {
        PREV_CHUNK(next) = child;
    }

    chunk->size = offset;
    return child;
}

void UIMem_MergeChunks(HeapChunk* chunk) {
    HeapChunk* prev;
    HeapChunk* next;
    HeapChunk* afterNext;

    prev = PREV_CHUNK(chunk);
    next = NEXT_CHUNK(chunk);

    if (prev != NULL && !prev->allocated) {
        // merge with previous
        prev->size += chunk->size;
        if (next < D_803A6908_87A0B8) {
            next->prev = prev;
        }
        chunk = prev;
    } else {
        UIMem_AddChunk(chunk);
        chunk->allocated = FALSE;
    }
    if (next < D_803A6908_87A0B8 && !next->allocated) {
        afterNext = NEXT_CHUNK(next);
        if (afterNext < D_803A6908_87A0B8) {
            afterNext->prev = chunk;
        }
        chunk->size += next->size;
        UIMem_Unlink(next);
    }
}

void* UIMem_Allocate(u32 size) {
    u32 size_with_header;
    HeapChunk* chunk;

    if (size < sizeof(chunk->v)) {
        size = sizeof(chunk->v);
    }

    size_with_header = ALIGN(size + offsetof(HeapChunk, v.data), 8);
    chunk = UIMem_FindChunk(size_with_header);
    if (chunk == NULL) {
        return NULL;
    }
    if (chunk->size - size_with_header > sizeof(HeapChunk)) {
        UIMem_AddChunk(UIMem_SplitChunk(chunk, size_with_header));
    }
    UIMem_Unlink(chunk);
    chunk->allocated = true;

    return chunk->v.data;
}

void UIMem_Deallocate(void* data) {
    UIMem_MergeChunks(GET_CHUNK(data));
}

#ifdef NON_MATCHING
u8* UIMem_Reallocate(u8* data_, u32 size) {
    u8* data = data_;
    HeapChunk* chunk;
    HeapChunk* next;
    HeapChunk* afterNext;
    u8* newData;
    s32 size_with_header;
    s32 oldSize;
    s32 i;

    while (true) {
        HeapChunk* chunk = GET_CHUNK(data);
        if (size < sizeof(chunk->v)) {
            size = sizeof(chunk->v);
        }

        size_with_header = ALIGN(size + offsetof(HeapChunk, v.data), 8);
        if (chunk->size > size_with_header) {
            if (chunk->size - size_with_header > sizeof(HeapChunk)) {
                UIMem_MergeChunks(UIMem_SplitChunk(chunk, size_with_header));
            }
            return data;
        }

        if (chunk->size >= size_with_header) {
            return data;
        }

        next = NEXT_CHUNK(chunk);
        if (next >= D_803A6908_87A0B8 || next->allocated) {
            break;
        }

        afterNext = NEXT_CHUNK(next);
        if (chunk->size + next->size < size_with_header) {
            break;
        }

        if (afterNext < D_803A6908_87A0B8) {
            PREV_CHUNK(afterNext) = chunk;
        }
        chunk->size += next->size;
        UIMem_Unlink(next);
    }

    oldSize = chunk->size;

    newData = UIMem_Allocate(size);
    if (newData == NULL) {
        return NULL;
    }

    for (i = 0; i < oldSize; i++) {
        newData[i] = data[i];
    }
    UIMem_Deallocate(data);
    return newData;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/window/83D730/UIMem_Reallocate.s")
#endif

void UIMem_CreateHeap(u8* buffer, s32 size) {
    UIMem_InitHeap(buffer, size);
}

s32 UIMem_GetTotalAllocatedMemory(void) {
    s32 total_size;
    HeapChunk* cur;

    total_size = 0;
    for (cur = D_803A6900_87A0B0; cur < D_803A6908_87A0B8; cur = (HeapChunk*) ((uintptr_t) cur + cur->size)) {
        if (cur->allocated) {
            total_size += cur->size;
        }
    }

    return total_size;
}
