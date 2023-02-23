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

// pirate* create_pirate(char* name){
//     pirate *new_pirate = malloc(sizeof(pirate));
//     strcpy(new_pirate->name, name);
//     return new_pirate;
// }

/*TO DELETE!*/
// pirate* copy_pirate(pirate* p){
//     pirate* copy = malloc(sizeof(pirate));
//     copy->name = malloc(65*sizeof(char));
//     strcpy(copy->name, p->name);
//     return copy;
// }

void list_expand_if_necessary(pirate_list* pirates) {
    if (pirates->length >= pirates->capacity) {
        pirates->capacity *= RESIZE_FACTOR;
        pirates->collection_of_pirates = realloc(pirates->collection_of_pirates, pirates->capacity * sizeof(pirate*));
        fprintf(stderr, "Expand to %d\n", pirates->capacity);
    }
}

void list_contract_if_necessary(pirate_list* pirates) {
    if (pirates->length < pirates->capacity / RESIZE_FACTOR) {
        pirates->capacity /= RESIZE_FACTOR;
        pirates->collection_of_pirates = realloc(pirates->collection_of_pirates, pirates->capacity * sizeof(pirate*));
        fprintf(stderr, "Contract to %d\n", pirates->capacity);
    }
}

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
    

    /*TO DELETE?*/
    // printf("%d", list_index_of(pirates, p));
    // printf("curlength %d\n", pirates->length);
    // printf("Pirate name for input to loop%s\n", p->name);
    // if(idx != 0) {
    //     printf("Hopefully not will: %s\n", pirates->collection_of_pirates[0]->name);
    // }

    // if the pirate is not already in the list
    if (list_index_of(pirates, p) == pirates->length) {
        list_expand_if_necessary(pirates);
        // move every pirate from the idx on one to the right
        // for (int j = pirates->length - 1; j > idx; j--) {
        //     printf("j = %i\n", j);
        //     pirates->collection_of_pirates[j + 1] = pirates->collection_of_pirates[j];
        // }

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

pirate* list_access(pirate_list* pirates, size_t idx) {
    if (idx < pirates->length) {
        return pirates->collection_of_pirates[idx];
    } else {
        return NULL;
    }
}

void print_list(pirate_list* pirates) {
    printf("Initial Pirate List: \n");
    for (int i = 0; i < pirates->length; i++) {
        printf("%s", pirates->collection_of_pirates[i]->name);
    }
    printf("\n\n");
}

void list_sort(pirate_list* pirates) {
    for (int i = 0; i < (pirates->length - 1); i++) {
        char *current_name = pirates->collection_of_pirates[i]->name;
        char *next_name = pirates->collection_of_pirates[i + 1]->name;

        int j = i;
        // while they are in the wrong order, swap them
        while(strcmp(current_name, next_name) > 0) {
            current_name = pirates->collection_of_pirates[j]->name;
            next_name = pirates->collection_of_pirates[j + 1]->name;

            pirates->collection_of_pirates[j]->name = next_name;
            pirates->collection_of_pirates[j + 1]->name = current_name;
        // }
        // if they are the same or in the correct order
        // if (strcmp(current_name, next_name) <= 0) {
        //     // leave them because they are in the right place
        //     continue;
        // } else if (strcmp(current_name, next_name) > 0) {
        //     // swap them because current name needs to come after next name
        //     pirates->collection_of_pirates[i]->name = next_name;
        //     pirates->collection_of_pirates[i + 1]->name = current_name;

            // strcpy(pirates->collection_of_pirates[i]->name, next_name);
            // strcpy(pirates->collection_of_pirates[i + 1]->name, current_name);
        }
    }
    printf("Sorted array: \n");
    for (int i = 0; i < (pirates->length); i++) {
        printf("%s\n", pirates->collection_of_pirates[i]->name);
    }
    printf("\n");

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

size_t list_length(pirate_list* pirates) {
    return pirates->length;
}

void list_destroy(pirate_list* pirates) {
    for (int i = 0; i < pirates->length; i++) {
        free(pirates->collection_of_pirates[i]->name);
        free(pirates->collection_of_pirates[i]);
    }
    free(pirates->collection_of_pirates);
    free(pirates);
}