#include "../saratoga.h"

void* st_debug_malloc(uint64 size, char *file, int line) {
    printf("DEBUG: MALLOC: %s:%d: %llu\n", file, line, size);
}
