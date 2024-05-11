#undef assert
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
#include "st_except.h"
extern const Except_T Assert_Failed;
void assert(int e);
#define assert(e) ((void)((e) || (RAISE(Assert_Failed), 0)))
#endif

