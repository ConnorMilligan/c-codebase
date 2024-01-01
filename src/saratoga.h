#ifndef BASE_H
#define BASE_H

#include "saratoga/st_defines.h"

// ------------
// Debugging
// ------------

// Debugging malloc, free and realloc (Inspired by Eskil Steenburg's method)
// void* st_debug_malloc(uint64 size, char *file, int line);
// void st_debug_free(uint64 size, char *file, int line);
// void* st_debug_realloc(uint64 size, char *file, int line);

// #ifdef ST_DEBUG_MEMORY
// # define ST_MALLOC(size) st_debug_malloc(size, __FILE__, __LINE__)
// # define ST_FREE(size) st_debug_free(size, __FILE__, __LINE__)
// # define ST_REALLOC(size) st_debug_realloc(size, __FILE__, __LINE__)
// #endif

// ------------
// Double linked list
// ------------

typedef struct STListNode {
    void *data;
    struct STListNode *next;
    struct STListNode *prev;
} STListNode;

typedef struct STList {
    STListNode *next;
    STListNode *prev;
    uint64 size;
} STList;

void STListInit(STList *list);
void STListPush(STList *list, void *data);
void STListPushFront(STList *list, void *data);
void* STListPop(STList *list);
void* STListPopFront(STList *list);
void* STListPeek(STList *list);
void* STListPeekFront(STList *list);
void STListRemove(STList *list, STListNode *node);
void STListDestroy(STList *list);

void STListPrint(STList *list, void (*print)(void *data));
void STListSort(STList *list, int (*compare)(void *a, void *b));

// ------------
// Primitive type print & compare
// ------------

void STPrintInt(void *data);
void STPrintFloat(void *data);
void STPrintChar(void *data);
void STPrintString(void *data);

int STCompareNum(void *a, void *b);


#endif //BASE_H
