#include "st_memory.h"

#include <stdlib.h>
#include <string.h>
#include "st_assert.h"
#include "st_except.h"
#include "st_util.h"

#define NDESCRIPTORS 512

#define hash(p, t) (((usize)(p) >> 3) & (NUM_ELEMS(t) - 1))
#define NALLOC ((4096 + sizeof (union align) - 1)/ \
       (sizeof (union align)))*(sizeof (union align))

static struct descriptor {
    struct descriptor *free;
    struct descriptor *link;
    const void *ptr;
    usize size;
    const char *file;
    int line;
} *htab[2048];

union align {
    int i;
    long l;
    long *lp;
    void *p;
    void (*fp)(void);
    float f;
    double d;
    long double ld;
};

static struct descriptor freelist = { &freelist };

/* find
 *
 * Finds a descriptor in the hash table.
 *
 * @param ptr The pointer to find.
 * @return The descriptor.
*/
static struct descriptor *find(const void *ptr) {
    struct descriptor *bp = htab[hash(ptr, htab)];

    while (bp && bp->ptr != ptr)
        bp = bp->link;
    return bp;
}

/* dalloc
 *
 * Allocates a descriptor.
 *
 * @param ptr The pointer to allocate memory for.
 * @param size The size of the memory to allocate.
 * @param file The file where the memory is allocated.
 * @param line The line where the memory is allocated.
 * @return The allocated descriptor.
*/
static struct descriptor *dalloc(void *ptr, usize size, const char *file, int line) {
    static struct descriptor *avail;
    static int nleft;

    if (nleft <= 0) {
        avail = malloc(NDESCRIPTORS * sizeof(*avail));
        if (avail == NULL) {
            return NULL;
        }
        nleft = NDESCRIPTORS;
    }
    avail->ptr = ptr;
    avail->size = size;
    avail->file = file;
    avail->line = line;
    avail->free = avail->link = NULL;
    nleft--;

    return avail++;
}

void *mem_alloc(usize nbytes, const char *file, int line) {
    struct descriptor *bp;
    void *ptr;

    assert(nbytes > 0);
    nbytes = ((nbytes + sizeof(union align) - 1) / (sizeof(union align))) * (sizeof(union align));

    for (bp = freelist.free; bp; bp = bp->free) {
        if (bp->size > nbytes) {
            bp->size -= nbytes;
            ptr = (void *)((usize)bp->ptr + bp->size);

            if ((bp = dalloc(ptr, nbytes, file, line)) != NULL) {
                usize h = hash(ptr, htab);
                bp->link = htab[h];
                htab[h] = bp;

                return ptr;
            } else {
                except_raise(&Mem_Failed, file, line);
            }
        }

        if (bp == &freelist) {
            struct descriptor *newptr;

            if ((ptr = malloc(nbytes + NALLOC)) == NULL || (newptr = dalloc(ptr, nbytes + NALLOC, file, line)) == NULL) {
                except_raise(&Mem_Failed, file, line);
            }
            newptr->free = freelist.free;
            freelist.free = newptr;
        }
    }

    assert(0);
    return NULL;
}

void *mem_calloc(usize count, usize nbytes, const char *file, int line) {
    void *ptr;

    assert(count > 0);
    assert(nbytes > 0);
    ptr = mem_alloc(count * nbytes, file, line);
    memset(ptr, '\0', count * nbytes);

    return ptr;
}

void *mem_realloc(void *ptr, usize nbytes, const char *file, int line) {
    struct descriptor *bp;
    void *newptr;

    assert(ptr);
    assert(nbytes > 0);
    if (((usize)ptr) % (sizeof(union align)) != 0 || (bp = find(ptr)) == NULL || bp->free) {
        except_raise(&Assert_Failed, file, line);
    }
    newptr = mem_alloc(nbytes, file, line);

    memcpy(newptr, ptr, nbytes < bp->size ? nbytes : bp->size);
    mem_free(ptr, file, line);

    return newptr;
}

void mem_free(void *ptr, const char *file, int line) {
    if (ptr) {
        struct descriptor *bp;

        if (((usize)ptr) % (sizeof(union align)) != 0 || (bp = find(ptr)) == NULL || bp->free) {
            except_raise(&Assert_Failed, file, line);
        }
        bp->free = freelist.free;
        freelist.free = bp;
    }
}
