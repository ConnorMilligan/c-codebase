#ifndef ST_MEMORY_H
#define ST_MEMORY_H
#include "st_except.h"
#include "st_defines.h"

/* ALLOC
 *
 * Allocates memory.
 *
 * @category Memory
 * @brief Expands to a call to mem_alloc() with file and line.
 * @param size The size of the memory to allocate.
 * @return The allocated memory.
*/
#define ALLOC(nbytes) mem_alloc((nbytes), __FILE__, __LINE__)

/* CALLOC
 *
 * Allocates zeroed memory.
 *
 * @category Memory
 * @brief Expands to a call to mem_calloc() with file and line.
 * @param count The number of elements to allocate.
 * @param size The size of each element.
 * @return The allocated memory.
*/
#define CALLOC(count, nbytes) mem_calloc((count), (nbytes), __FILE__, __LINE__)

/* REALLOC
 *
 * Reallocates memory.
 *
 * @category Memory
 * @brief Expands to a call to mem_realloc() with file and line.
 * @param ptr The memory to reallocate.
 * @param size The new size of the memory.
 * @return The reallocated memory.
*/
#define REALLOC(ptr, nbytes) mem_realloc((ptr), (nbytes), __FILE__, __LINE__)

/* FREE
 *
 * Frees memory.
 *
 * @category Memory
 * @brief Expands to a call to mem_free() with file and line.
 * @param ptr The memory to free.
*/
#define FREE(ptr) ((void)(mem_free((ptr), __FILE__, __LINE__), (ptr) = 0))

/* NEW
 *
 * Allocates memory for a pointer.
 *
 * @category Memory
 * @brief Expands to a call to ALLOC() with the size of the pointer.
 * @param p The pointer to allocate memory for.
*/
#define NEW(p) ((p) = ALLOC((usize)sizeof *(p)))

/* NEW0
 *
 * Allocates zeroed memory for a pointer.
 *
 * @category Memory
 * @brief Expands to a call to CALLOC() with the size of the pointer.
 * @param p The pointer to allocate memory for.
*/
#define NEW0(p) ((p) = CALLOC(1, (usize)sizeof *(p))

extern const Except_T Mem_Failed;

/* mem_alloc
 *
 * Allocates memory.
 *
 * @category Memory
 * @param size The size of the memory to allocate.
 * @param file The file the allocation is in.
 * @param line The line the allocation is on.
 * @return The allocated memory.
*/
void *mem_alloc(usize nbytes, const char *file, int line);

/* mem_calloc
 *
 * Allocates zeroed memory.
 *
 * @category Memory
 * @param count The number of elements to allocate.
 * @param size The size of each element.
 * @param file The file the allocation is in.
 * @param line The line the allocation is on.
 * @return The allocated memory.
*/
void *mem_calloc(usize nbytes, usize size, const char *file, int line);

/* mem_realloc
 *
 * Reallocates memory.
 *
 * @category Memory
 * @param ptr The memory to reallocate.
 * @param size The new size of the memory.
 * @param file The file the reallocation is in.
 * @param line The line the reallocation is on.
 * @return The reallocated memory.
*/
void *mem_realloc(void *ptr, usize nbytes, const char *file, int line);

/* mem_free
 *
 * Frees memory.
 *
 * @category Memory
 * @param ptr The memory to free.
 * @param file The file the free is in.
 * @param line The line the free is on.
*/
void mem_free(void *ptr, const char *file, int line);


#endif // ST_MEMORY_H