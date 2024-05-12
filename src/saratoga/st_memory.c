#include "st_memory.h"

#include <stdlib.h>
#include "st_assert.h"
#include "st_except.h"

const Except_T Mem_Failed = { "Allocation Failed" };

void *mem_alloc(usize nbytes, const char *file, int line) {
    void *ptr;

    assert(nbytes > 0);
    ptr = malloc(nbytes);
    if (ptr == NULL) {
        if (file == NULL)
            RAISE(Mem_Failed);
        else
            except_raise(&Mem_Failed, file, line);
    }
    return ptr;
}

void *mem_calloc(usize count, usize nbytes, const char *file, int line) {
    void *ptr;

    assert(count > 0);
    assert(nbytes > 0);
    ptr = calloc(count, nbytes);
    if (ptr == NULL) {
        if (file == NULL)
            RAISE(Mem_Failed);
        else
            except_raise(&Mem_Failed, file, line);
    }
    return ptr;
}

void *mem_realloc(void *ptr, usize nbytes, const char *file, int line) {
    assert(ptr);
    assert(nbytes > 0);
    ptr = realloc(ptr, nbytes);
    if (ptr == NULL) {
        if (file == NULL)
            RAISE(Mem_Failed);
        else
            except_raise(&Mem_Failed, file, line);
    }
    return ptr;
}

void mem_free(void *ptr, const char *file, int line) {
    if (ptr)
        free(ptr);
}
