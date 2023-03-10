/*
 * pirate.c
 * Josh Bialkin
 * CPSC 223, pset 3
 * 3/9/23
 * Contains functions for creating and altering pirates
 */

#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SKILL_INITIAL_CAPACITY 25
#define RESIZE_FACTOR 2

/*
 * Parameters: none
 * Returns: pointer to pirate
 * Purpose: allocates space in memory for the pirate, initializes its
 *          values, and sets up its skill array list
 */
pirate *create_pirate() {
    pirate *new_pirate = malloc(sizeof(pirate));
    new_pirate->treasure = 0;
    new_pirate->skills = malloc(SKILL_INITIAL_CAPACITY * sizeof(skill));
    new_pirate->skills_length = 0;
    new_pirate->skills_capacity = SKILL_INITIAL_CAPACITY;
    return new_pirate;
}

/*
 * Parameters: pirate
 * Returns: pointer to pirate
 * Purpose: sorts the skills alphabetically. ensures the two skills
 *          are in the correct order before moving on to the next. Uses
 *          insertion sort. 
 */
pirate *sort_skills(pirate *p) {
    for (int i = 1; i < p->skills_length; i++) {
        int j = i;
        char *previous_skill = p->skills[j - 1]->skill_name;
        char *current_skill = p->skills[j]->skill_name;
        // while they are in the wrong order, swap them
        while((j >= 1) && (strcmp(previous_skill, current_skill)) > 0) {
            char *temp_skill = previous_skill;

            p->skills[j - 1]->skill_name = current_skill;
            p->skills[j]->skill_name = temp_skill;

            if (j > 1) {
                --j;    
            }

            previous_skill = p->skills[j - 1]->skill_name;
            current_skill = p->skills[j]->skill_name;
        }
    }
    return p;
}

/*
 * Parameters: pirate
 * Returns: nothing
 * Purpose: increases the amount of memory allocated for a pirate's skill
 *          list if it becomes too large.
 */
void skill_expand_if_necessary(pirate *p) {
    if (p->skills_length >= p->skills_capacity) {
        p->skills_capacity *= RESIZE_FACTOR;
        p->skills = realloc(p->skills, 
            p->skills_capacity * sizeof(pirate*));
        fprintf(stderr, "Expand skills to %zu\n", p->skills_capacity);
    }
}

/*
 * Parameters: pirate, string of pirate skill
 * Returns: pointer to pirate
 * Purpose: adds the skill from the string to the pirate's skill list. If the
 *          skill is already in the list, it increases the skill's number of
 *          occurances. Otherwise, it adds the skill to the list and then 
 *          ensures the skills are sorted by calling the sort_skills function.
 *          There is also a check see if the list needs to be expanded.
 */
pirate *add_to_skills(pirate *p, char* pirate_skill) {
    size_t idx = p->skills_length;
    
    if (idx > 0) {
        for (int i = 0; i < idx; i++) {
            if (strcmp(p->skills[i]->skill_name, pirate_skill) == 0) {
                p->skills[i]->number_of_occurances++;
                return p;
            }
        }
    }
    p->skills[idx] = malloc(sizeof(skill));
    p->skills[idx]->skill_name = malloc(65 * sizeof(char));
    strcpy(p->skills[idx]->skill_name, pirate_skill);
    p->skills[idx]->number_of_occurances++;
    p->skills_length++;
    skill_expand_if_necessary(p);
    if (p->skills_length > 1) {
        sort_skills(p);
    }
    return p;
}

/*
 * Parameters: pirate, string of pirate field, string of field details
 * Returns: pointer to pirate
 * Purpose: determines which field the new trait needs to be added to,
 *          allocates memory as needed, and then adds the field details
 *          to the correct field
 */
pirate *add_to_pirate(pirate *p, char *pirate_field, char *field_details) {
    if (strcmp(pirate_field, "name") == 0) {
        p->name = malloc(65*sizeof(char));
        strcpy(p->name, field_details);
    } else if (strcmp(pirate_field, "title") == 0) {
        p->title = malloc(65*sizeof(char));
        strcpy(p->title, field_details);
    } else if (strcmp(pirate_field, "vessel") == 0) {
        p->vessel = malloc(65*sizeof(char));
        strcpy(p->vessel, field_details);
    } else if (strcmp(pirate_field, "port") == 0) {
        p->port = malloc(65*sizeof(char));
        strcpy(p->port, field_details);
    } else if (strcmp(pirate_field, "treasure") == 0) {
        size_t treasure = atoi(field_details);
        p->treasure = treasure;
    } else if (strcmp(pirate_field, "skill") == 0) {
        add_to_skills(p, field_details);
    }
    return p;
}