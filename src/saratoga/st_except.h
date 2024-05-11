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
#define RERAISE except_raise(Except_frame.exception, Except_frame.file, Except_frame.line)
/* RETURN
 *
 * Returns from a TRY block.
 *
 * @category Exceptions
*/
#define RETURN switch (Except_frame.exception = NULL) default: return
/* TRY
 *
 * Begins a TRY block.
 *
 * @category Exceptions
*/
#define TRY do { \
    volatile int Except_flag; \
    Except_Frame Except_frame; \
    Except_frame.prev = Except_stack; \
    Except_stack = &Except_frame; \
    Except_flag = setjmp(Except_frame.env); \
    if (Except_flag == 0) {
/* EXCEPT
 *
 * Begins an EXCEPT block.
 *
 * @category Exceptions
 * @param e The exception to catch.
*/
#define EXCEPT(e) \
    if (Except_flag == 0) Except_stack = Except_stack->prev; \
    else if (Except_frame.exception == &(e)) { Except_flag = Except_entered;
/* ELSE
 *
 * Begins an ELSE block.
 *
 * @category Exceptions
*/
#define ELSE \
    if (Except_flag == Except_entered) Except_stack = Except_stack->prev; \
    else Except_flag = Except_handled;
/* FINALLY
 *
 * Begins a FINALLY block.
 *
 * @category Exceptions
*/
#define FINALLY \
    if (Except_flag == Except_entered) Except_stack = Except_stack->prev; \
    { \
        if (Except_flag == Except_entered) Except_flag = Except_finalized;
/* END_TRY
 *
 * Ends a TRY block.
 *
 * @category Exceptions
*/
#define END_TRY \
    if (Except_flag == Except_entered) Except_stack = Except_stack->prev; \
    } if (Except_flag == Except_raised) RERAISE; \
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

extern Except_Frame exceptFrame;

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