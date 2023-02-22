#include "pirate.h"
#include "pirate_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 25
#define RESIZE_FACTOR 2

typedef struct implementation {
    pirate **collection_of_pirates;
    int length;
    int capacity;
} pirate_list;

pirate_list *list_create() {
    pirate_list *lst = malloc(sizeof(pirate_list));
    lst->collection_of_pirates = malloc(INITIAL_CAPACITY * sizeof(pirate*));
    lst->length = 0;
    lst->capacity = INITIAL_CAPACITY;
    return lst;
}

size_t list_index_of(pirate_list *pirates, pirate *p) {
    for (int i = 0; i < pirates->length; i++) {
        char *name_1 = p->name;
        char *name_2 = pirates->collection_of_pirates[i]->name;
        // if the pirate is in the list, return the index
        if (strcmp(name_1, name_2) == 0) {
            return i;
        } 
    }
    // if the pirate is not in the list, return the length of the list
    return pirates->length;
}

pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx) {
    // if the pirate is not already in the list
    if (list_index_of(pirates, p) == pirates->length) {
        list_expand_if_necessary(pirates);
        // move every pirate from the idx on one to the right
        for (int j = pirates->length; j > idx; j--) {
            printf("%i\n", j);
            pirates->collection_of_pirates[idx + 1] = pirates->collection_of_pirates[idx];
        }
        // add the pirate to the index
        pirates->collection_of_pirates[idx] = p;
        // increase the length of the array by 1
        pirates->length++;
        return NULL;
    } else {
        // if the pirate is already in the list, return the pointer to the pirate
        return p;
    }
}

pirate* list_remove(pirate_list* pirates, pirate* p) {
    size_t pirate_index = list_index_of(pirates, p);
    if (pirate_index == pirates->length) {
        return NULL;
    } else {
        // remove p from list
        pirate *pirate_to_remove = pirates->collection_of_pirates[pirate_index];
        for (int i = pirate_index; i < (pirates->length - 1); i++) {
            pirates->collection_of_pirates[i] = pirates->collection_of_pirates[i + 1];
        }
        pirates->length--;
        list_contract_if_necessary(pirates);
        return pirate_to_remove;
    }
}

void list_expand_if_necessary(pirate_list* pirates) {
    if (pirates->length >= pirates->capacity) {
        pirates->capacity *= RESIZE_FACTOR;
        pirates->collection_of_pirates = realloc(pirates->collection_of_pirates, pirates->capacity * sizeof(pirate*));
        fprintf(stderr, "Expand to %zu\n", pirates->capacity);
    }
}

void list_contract_if_necessary(pirate_list* pirates) {
    if (pirates->length < pirates->capacity / RESIZE_FACTOR) {
        pirates->capacity /= RESIZE_FACTOR;
        pirates->collection_of_pirates = realloc(pirates->collection_of_pirates, pirates->capacity * sizeof(pirate*));
        fprintf(stderr, "Contract to %zu\n", pirates->capacity);
    }
}

pirate* list_access(pirate_list* pirates, size_t idx) {
    if (idx < pirates->length) {
        return pirates->collection_of_pirates[idx];
    } else {
        return NULL;
    }
}

void list_sort(pirate_list* pirates) {
    for (int i = 0; i < (pirates->length - 1); i++) {
        char *current_name = pirates->collection_of_pirates[i]->name;
        char *next_name = pirates->collection_of_pirates[i + 1]->name;

        // if they are the same or in the correct order
        if (strcmp(current_name, next_name) == 0 || strcmp(current_name, next_name) < 0) {
            // leave them because they are in the right place
            continue;
        } else if (strcmp(current_name, next_name) > 0) {
            // swap them because current name needs to come after next name
        }

        // if (current_name[0] < next_name[0]) {
        //     continue;
        // } else if (current_name[0] > next_name[0]) {
        //     pirates->collection_of_pirates[i]->name = next_name;
        //     pirates->collection_of_pirates[i + 1]->name = current_name;
        // } else if (current_name[0] == next_name[0]) {
        //     // find shorter length of name to compare alphabetically in loop
        //     int current_name_length = strlen(current_name);
        //     int next_name_length = strlen(next_name);
        //     int shorter_name_length = 0;
        //     if (current_name_length < next_name_length) {
        //         shorter_name_length = current_name_length;
        //     } else {
        //         shorter_name_length = next_name_length;
        //     }
        //     for (int j = 1; j < shorter_name_length; j++) {
        //         if (current_name[j] > next_name[j]) {
        //             pirates->collection_of_pirates[i]->name = next_name;
        //             pirates->collection_of_pirates[i + 1]->name = current_name;
        //             break;
        //         }
        //     }
        // }
    }
    for (int i = 0; i < (pirates->length - 1); i++) {
        printf("%s\n", pirates->collection_of_pirates[i]->name);
    }
}

size_t list_length(pirate_list* pirates) {
    return pirates->length;
}

void list_destroy(pirate_list* pirates) {
    free(pirates->collection_of_pirates);
    free(pirates);
}