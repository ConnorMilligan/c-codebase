#include "st_except.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define T Except_T

Except_Frame *exceptStack = NULL;

void except_raise(const T *e, const char *file, int line)
{
    Except_Frame *p = exceptStack;
    assert(e);
    if (p == NULL) {
        fprintf(stderr, "Uncaught exception");
        if (e->reason)
            fprintf(stderr, " %s", e->reason);
        else
            fprintf(stderr, " at 0x%p", e);
        if (file && line > 0)
            fprintf(stderr, " raised at %s:%d\n", file, line);
        fprintf(stderr, "aborting...\n");
        fflush(stderr);
        abort();
    }
    p->exception = e;
    p->file = file;
    p->line = line;
    exceptStack = exceptStack->prev;
    longjmp(p->env, Except_raised);
}