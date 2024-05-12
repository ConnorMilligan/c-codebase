#ifndef ST_UTIL_H
#define ST_UTIL_H

// -------------------
// Handy macros.
// -------------------

/* NUM_ELEMS
 *
 * Returns the number of elements in an array.
 *
 * @category Macros
 * @param x The array to get the number of elements of.
 * @return The number of elements in the array.
*/
#define NUM_ELEMS(x) ((sizeof (x))/(sizeof ((x)[0])))

/* MIN
 *
 * Returns the minimum of two values.
 *
 * @category Macros
 * @param a The first value.
 * @param b The second value.
 * @return The minimum of the two values.
*/
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* MAX
 *
 * Returns the maximum of two values.
 *
 * @category Macros
 * @param a The first value.
 * @param b The second value.
 * @return The maximum of the two values.
*/
#define MAX(a, b) ((a) > (b) ? (a) : (b))



#endif // ST_UTIL_H