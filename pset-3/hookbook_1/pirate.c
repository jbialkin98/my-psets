/*
 * pirate_list.c
 * Josh Bialkin
 * CPSC 223, pset 3
 * 3/9/23
 * Creates each pirate
 */

#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Parameters: name of pirate
 * Returns: pointer to pirate
 * Purpose: allocates space in memory for the pirate and its name,
 *          then assigns the name to the pirate
 */
pirate *create_pirate(char name[65]){
    pirate *new_pirate = malloc(sizeof(pirate));
    new_pirate->name = malloc(65*sizeof(char));
    strcpy(new_pirate->name, name);
    return new_pirate;
}