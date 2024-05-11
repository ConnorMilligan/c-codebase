#ifndef EXCEPT_H
#define EXCEPT_H

#include <setjmp.h>

/* RAISE
 *
 * Raises an exception.
 *
 * @category Exceptions
 * @param e The exception to raise.
*/
#define RAISE(e) except_raise(&(e), __FILE__, __LINE__)
/* RERAISE
 *
 * Reraises an exception.
 *
 * @category Exceptions
*/
#define RERAISE except_raise(exceptFrame.exception, exceptFrame.file, exceptFrame.line)
/* RETURN
 *
 * Returns from a TRY block.
 *
 * @category Exceptions
*/
#define RETURN switch (exceptFrame.exception = NULL) default: return
/* TRY
 *
 * Begins a TRY block.
 *
 * @category Exceptions
*/
#define TRY do { \
    volatile int exceptFlag; \
    Except_Frame exceptFrame; \
    exceptFrame.prev = exceptStack; \
    exceptStack = &exceptFrame; \
    exceptFlag = setjmp(exceptFrame.env); \
    if (exceptFlag == Except_entered) {
/* EXCEPT
 *
 * Begins an EXCEPT block.
 *
 * @category Exceptions
 * @param e The exception to catch.
*/
#define EXCEPT(e) \
    if (exceptFlag == 0) exceptStack = exceptStack->prev; \
    else if (exceptFrame.exception == &(e)) { exceptFlag = Except_entered;
/* ELSE
 *
 * Begins an ELSE block.
 *
 * @category Exceptions
*/
#define ELSE \
    if (exceptFlag == Except_entered) exceptStack = exceptStack->prev; \
    else exceptFlag = Except_handled;
/* FINALLY
 *
 * Begins a FINALLY block.
 *
 * @category Exceptions
*/
#define FINALLY \
    if (exceptFlag == Except_entered) exceptStack = exceptStack->prev; \
    { \
        if (exceptFlag == Except_entered) exceptFlag = Except_finalized;
/* END_TRY
 *
 * Ends a TRY block.
 *
 * @category Exceptions
*/
#define END_TRY \
    if (exceptFlag == Except_entered) exceptStack = exceptStack->prev; \
    } if (exceptFlag == Except_raised) RERAISE; \
} while (0)


enum { Except_entered = 0, Except_raised, Except_handled, Except_finalized };

/* Except_T
 *
 * Represents an exception.
 *
 * @category Exceptions
 * @param reason The reason for the exception.
*/
#define T Except_T
typedef struct T {
    const char *reason;
} T;

/* Except_Frame
 *
 * Represents a frame in the exception stack.
 *
 * @category Exceptions
 * @param prev The previous frame.
 * @param env The environment to jump back to.
 * @param file The file the exception was raised in.
 * @param line The line the exception was raised on.
 * @param exception The exception that was raised.
*/
typedef struct Except_Frame {
    struct Except_Frame *prev;
    jmp_buf env;
    const char *file;
    int line;
    const T *exception;
} Except_Frame;

extern Except_Frame *exceptStack;

/* except_raise
 *
 * Raises an exception.
 *
 * @category Exceptions
 * @param e The exception to raise.
 * @param file The file the exception was raised in.
 * @param line The line the exception was raised on.   
*/
void except_raise(const T *e, const char *file, int line);

/* except_push
 *
 * Pushes an exception frame onto the stack.
 *
 * @category Exceptions
 * @param frame The frame to push.
*/
void except_push(Except_Frame *frame);

/* except_pop
 *
 * Pops an exception frame off the stack.
 *
 * @category Exceptions
*/
void except_pop(void);

#undef T
#endif // EXCEPT_H