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

// Type of a pirate.
typedef struct pirate {
    char *name;
    char *title;
    char *vessel;
    char *port;
    size_t treasure;
    // should be char **
    char *skill;
} pirate;

#endif
