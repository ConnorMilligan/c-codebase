#include "../saratoga.h"

#include <stdlib.h>

void STListInit(STList *list) {
    list->next = NULL;
    list->prev = NULL;
    list->size = 0;
}

void STListPush(STList *list, void *data) {
    STListNode *node = malloc(sizeof(STListNode));
    node->data = data;
    node->next = NULL;
    node->prev = list->prev;
    if (list->prev != NULL) {
        list->prev->next = node;
    }
    list->prev = node;
    if (list->next == NULL) {
        list->next = node;
    }
    list->size++;
}

void STListPushFront(STList *list, void *data);
void* STListPop(STList *list);
void* STListPopFront(STList *list);
void* STListPeek(STList *list);
void* STListPeekFront(STList *list);
void STListRemove(STList *list, STListNode *node);
void STListRemoveData(STList *list, void *data);

void STListDestroy(STList *list) {
    STListNode *node = list->next;
    while (node != NULL) {
        STListNode *next = node->next;
        free(node);
        node = next;
    }
    list->next = NULL;
    list->prev = NULL;
    list->size = 0;
}

void STListPrint(STList *list, void (*print)(void *data)) {
    STListNode *node = list->next;
    while (node != NULL) {
        print(node->data);
        node = node->next;
    }
}

void STListSort(STList *list, int (*compare)(void *a, void *b));