#ifndef DEFINES_H
#define DEFINES_H

#include <stdbool.h>

// ------------------- 
// Data type aliases.
// -------------------

// Unsigned int types.
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;

// Regular int types.
typedef char int8;
typedef short int16;
typedef int int32;
typedef long long int64;

// Floating point types
typedef float f32;
typedef double f64;

// ------------------- 
// Platform detection.
// -------------------

#if defined(__clang__)
#  define COMPILER_CLANG 1
#elif defined(_MSC_VER)
#  define COMPILER_CL 1
#elif defined(__GNUC__)
#  define COMPILER_GCC 1
#endif

# if defined(_WIN32)
#  define OS_WINDOWS 1
# elif defined(__gnu_linux__)
#  define OS_LINUX 1
# elif defined(__APPLE__) && defined(__MACH__)
#  define OS_MAC 1
# else
#  error missing OS detection
# endif

# if defined(__amd64__) || defined(_M_X64)
#  define ARCH_X64 1
# elif defined(__i386__) || defined(_M_IX86) || defined(_X86_)
#  define ARCH_X86 1
# elif defined(__arm__) || defined(_M_ARM)
#  define ARCH_ARM 1
# elif defined(__aarch64__) || defined(_M_ARM64) || defined(__arm64__)
#  define ARCH_ARM64 1
# else
#  error missing ARCH detection
# endif

// Zero fill missing context macros
#if !defined(COMPILER_CL)
# define COMPILER_CL 0
#endif
#if !defined(COMPILER_CLANG)
# define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
# define COMPILER_GCC 0
#endif
#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif
#if !defined(OS_MAC)
# define OS_MAC 0
#endif
#if !defined(ARCH_X64)
# define ARCH_X64 0
#endif
#if !defined(ARCH_X86)
# define ARCH_X86 0
#endif
#if !defined(ARCH_ARM)
# define ARCH_ARM 0
#endif
#if !defined(ARCH_ARM64)
# define ARCH_ARM64 0
#endif

// -------------------
// Terminal colors.
// -------------------

#if OS_WINDOWS
# define TERM_COLOR_RED ""
# define TERM_COLOR_GREEN ""
# define TERM_COLOR_YELLOW ""
# define TERM_COLOR_BLUE ""
# define TERM_COLOR_MAGENTA ""
# define TERM_COLOR_CYAN ""
# define TERM_COLOR_RESET ""
#else
# define TERM_COLOR_RED "\033[0;31m"
# define TERM_COLOR_GREEN "\033[0;32m"
# define TERM_COLOR_YELLOW "\033[0;33m"
# define TERM_COLOR_BLUE "\033[0;34m"
# define TERM_COLOR_MAGENTA "\033[0;35m"
# define TERM_COLOR_CYAN "\033[0;36m"
# define TERM_COLOR_RESET "\033[0m"
#endif

#endif // DEFINES_H
