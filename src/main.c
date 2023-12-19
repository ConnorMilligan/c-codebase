#include "base.h"

#include <stdio.h>

int main(int argc, char **argv) {

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
    printf("arm64 = %d\n", ARCH_ARM64);

    // Color test
    printf("\nColor test:\n");
    printf("This is %sred%s.\n", TERM_COLOR_RED, TERM_COLOR_RESET);
    printf("This is %sgreen%s.\n", TERM_COLOR_GREEN, TERM_COLOR_RESET);
    printf("This is %syellow%s.\n", TERM_COLOR_YELLOW, TERM_COLOR_RESET);
    printf("This is %sblue%s.\n", TERM_COLOR_BLUE, TERM_COLOR_RESET);
    printf("This is %smagenta%s.\n", TERM_COLOR_MAGENTA, TERM_COLOR_RESET);
    printf("This is %scyan%s.\n", TERM_COLOR_CYAN, TERM_COLOR_RESET);

    return 0;
}
