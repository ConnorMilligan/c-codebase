#ifndef DEFINES_H
#define DEFINES_H

#include <stdbool.h>

// ------------------- 
// Data type aliases.
// -------------------

// Unsigned int types.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types.
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

// Regular int types.
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

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

#endif // DEFINES_H