/*
 * pirate.h
 * Josh Bialkin
 * CPSC 223, pset 3
 * 3/5/23
 * Initializes the pirate struct
*/

#ifndef __PIRATE_H__
#define __PIRATE_H__

#include <stdlib.h>

typedef struct skill {
    char *skill_name;
    size_t number_of_occurances;
} skill;

// Type of a pirate.
typedef struct pirate {
    char *name;
    char *title;
    char *vessel;
    char *port;
    size_t treasure;
    skill **skills;
    size_t skills_length;
    size_t skills_capacity;
} pirate;

#endif