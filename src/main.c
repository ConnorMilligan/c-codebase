#include "saratoga.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    STList list;
    STListInit(&list);
    {
    int int1 = 1;
    int int2 = 2;
    int int3 = 3;

    STListPush(&list, &int1);
    STListPush(&list, &int2);
    STListPush(&list, &int3);
    }
    STListPrint(&list, STPrintInt);

    STListDestroy(&list);

    printf("Welcome to LibSaratoga!\n\n");

    // Print the values of the macros
    printf("Compiler Definitions:\n");
    printf("cl    = %d\n", COMPILER_CL);
    printf("clang = %d\n", COMPILER_CLANG);
    printf("gcc   = %d\n", COMPILER_GCC);
    printf("windows = %d\n", OS_WINDOWS);
    printf("linux   = %d\n", OS_LINUX);
    printf("mac     = %d\n", OS_MAC);
    printf("x64   = %d\n", ARCH_X64);
    printf("x86   = %d\n", ARCH_X86);
    printf("arm   = %d\n", ARCH_ARM);
    printf("arm64 = %d\n\n", ARCH_ARM64);

    // Color test
#if OS_WINDOWS
    printf(" ~ This system (Windows) does not support colored output with this framework. ~ \n");
#endif
    printf("Color test:\n");
    printf("This is %sred%s.\n", TERM_COLOR_RED, TERM_COLOR_RESET);
    printf("This is %sgreen%s.\n", TERM_COLOR_GREEN, TERM_COLOR_RESET);
    printf("This is %syellow%s.\n", TERM_COLOR_YELLOW, TERM_COLOR_RESET);
    printf("This is %sblue%s.\n", TERM_COLOR_BLUE, TERM_COLOR_RESET);
    printf("This is %smagenta%s.\n", TERM_COLOR_MAGENTA, TERM_COLOR_RESET);
    printf("This is %scyan%s.\n", TERM_COLOR_CYAN, TERM_COLOR_RESET);

    return 0;
}
