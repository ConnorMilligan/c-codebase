#ifndef DEFINES_H
#define DEFINES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// -------------------
// Library Info.
// -------------------
#define ST_VERSION_MAJOR 0
#define ST_VERSION_MINOR 2

// ------------------- 
// Data type aliases.
// -------------------

// Unsigned int types.
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

// Regular int types.
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

// Floating point types
typedef float f32;
typedef double f64;

// Size
typedef size_t usize;

// Undefine the data type aliases.
#undef uint8_t
#undef uint16_t
#undef uint32_t
#undef uint64_t
#undef int8_t
#undef int16_t
#undef int32_t
#undef int64_t

// ------------------- 
// Platform detection.
// -------------------

#if defined(__clang__)
#  define COMPILER_CLANG 1
#  define COMPILER_VERSION __VERSION__
#elif defined(_MSC_VER)
#  define COMPILER_CL 1
#  define COMPILER_VERSION _MSC_FULL_VER
#elif defined(__GNUC__)
#  define COMPILER_GCC 1
#  define COMPILER_VERSION __VERSION__
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
// Compiler
#if !defined(COMPILER_CL)
# define COMPILER_CL 0
#endif
#if !defined(COMPILER_CLANG)
# define COMPILER_CLANG 0
#endif
#if !defined(COMPILER_GCC)
# define COMPILER_GCC 0
#endif
# if !defined(COMPILER_VERSION)
#  define COMPILER_VERSION "Unknown"
# endif

// OS
#if !defined(OS_WINDOWS)
# define OS_WINDOWS 0
#endif
#if !defined(OS_LINUX)
# define OS_LINUX 0
#endif
#if !defined(OS_MAC)
# define OS_MAC 0
#endif

// Architecture
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


#endif // DEFINES_H
