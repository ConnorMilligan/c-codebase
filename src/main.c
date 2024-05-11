#include "saratoga.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
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


    const char *str = atom_string("Hello, World!");
    printf("Atom: %s\n", str);
    const char *num = atom_int(12345);
    printf("Atom: %s\n", num);

    TRY
        printf("This is a test\n");
    ELSE
        fprintf(stderr, "An error occurred\n");
    END_TRY;

    // Print the version of the compiler and the version of the library
    printf("Compiled on %s at %s",
        __DATE__, 
        __TIME__);
    printf(" with %s %s", 
        COMPILER_CLANG ? "Clang" : COMPILER_GCC ? "GCC" : COMPILER_CL ? "MSVC" : "Unknown",
        COMPILER_VERSION);
    printf(" on %s using libSaratoga %d.%d\n",
        OS_WINDOWS ? "Windows" : OS_LINUX ? "Linux" : OS_MAC ? "Mac" : "Unknown",
        ST_VERSION_MAJOR, ST_VERSION_MINOR);

    return 0;
}
