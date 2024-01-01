#include "../saratoga.h"

#include <stdio.h>

void STPrintInt(void *data) {
    printf("%d\n", *(int*)data);
}

void STPrintFloat(void *data) {
    printf("%f\n", *(float*)data);
}

void STPrintChar(void *data) {
    printf("%c\n", *(char*)data);
}

void STPrintString(void *data) {
    printf("%s\n", (char*)data);
}

int STCompareNum(void *a, void *b) {
    return *(float*)a - *(float*)b;
}