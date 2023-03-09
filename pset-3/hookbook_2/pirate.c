#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SKILL_INITIAL_CAPACITY 25
#define RESIZE_FACTOR 2

pirate *create_pirate() {
    pirate *new_pirate = malloc(sizeof(pirate));
    new_pirate->treasure = 0;
    new_pirate->skills = malloc(SKILL_INITIAL_CAPACITY * sizeof(skill));
    new_pirate->skills_length = 0;
    new_pirate->skills_capacity = SKILL_INITIAL_CAPACITY;
    return new_pirate;
}

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

void skill_expand_if_necessary(pirate *p) {
    if (p->skills_length >= p->skills_capacity) {
        p->skills_capacity *= RESIZE_FACTOR;
        p->skills = realloc(p->skills, 
            p->skills_capacity * sizeof(pirate*));
        fprintf(stderr, "Expand skills to %zu\n", p->skills_capacity);
    }
}

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