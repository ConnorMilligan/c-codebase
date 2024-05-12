#ifndef ST_ATOM_H
#define ST_ATOM_H

#include "st_defines.h"

/*
* Atom_new
* 
* Creates a new atom from a string.
* 
* @category Atoms
* @note For a null-terminated string, use Atom_string().
* @param str The string to create the atom from.
* @param len The length of the string.
* 
* @return The new atom.
*/
const char* atom_new(const char *str, usize len);

/* Atom_string
*
* Creates a new atom from a null-terminated string.
*
* @category Atoms
* @note For a non-null-terminated string, use Atom_new().
* @param str The null-terminated string to create the atom from.
* @return The new atom.
*/
const char* atom_string(const char *str);

/* Atom_int
*
* Creates a new atom from an integer.
*
* @category Atoms
* @param n The integer to create the atom from.
* @return The new atom.
*/
const char *atom_int(uint32 n);

/* Atom_length
*
* Returns the length of an atom.
*
* @category Atoms
* @param str The atom to get the length of.
* @return The length of the atom.
*/
usize atom_length(const char *str);

#endif // ST_ATOM_H