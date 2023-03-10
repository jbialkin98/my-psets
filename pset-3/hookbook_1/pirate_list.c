/*
 * pirate_list.c
 * Josh Bialkin
 * CPSC 223, pset 3
 * 3/5/23
 * Contains the function implementations for the program
 */

#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 25
#define RESIZE_FACTOR 2

// define a pirate list consisting of a collection of pirates, the length of 
// the list, and the capacity of the list
typedef struct implementation {
    pirate **collection_of_pirates;
    size_t length;
    size_t capacity;
} pirate_list;

/*
 * Parameters: pirate list
 * Returns: nothing
 * Purpose: if the length of the pirate list is greater than or equal to the 
 *          capacity of the list, the capacity is increased by the resize 
 *          factor, in this case multiplied by 2. The list is reallocated
 *          using the new, doubled capacity, and a message is printed to 
 *          stderr
 */
void list_expand_if_necessary(pirate_list *pirates) {
    if (pirates->length >= pirates->capacity) {
        pirates->capacity *= RESIZE_FACTOR;
        pirates->collection_of_pirates = realloc(
            pirates->collection_of_pirates, 
            pirates->capacity * sizeof(pirate*));
        fprintf(stderr, "Expand to %zu\n", pirates->capacity);
    }
}

/*
 * Parameters: pirate list
 * Returns: nothing
 * Purpose: if the lenght of the pirate list is less than half of the capacity
 *          of the list, the capacity is halved using the resize factor of 2
 *          and the list is reallocated using the new capacity. A message is
 *          printed to stderr
 */
void list_contract_if_necessary(pirate_list *pirates) {
    if (pirates->length < pirates->capacity / RESIZE_FACTOR) {
        pirates->capacity /= RESIZE_FACTOR;
        pirates->collection_of_pirates = realloc(
            pirates->collection_of_pirates, 
            pirates->capacity * sizeof(pirate*));
        fprintf(stderr, "Contract to %zu\n", pirates->capacity);
    }
}

/*
 * Parameters: none
 * Returns: pointer to a pirate list
 * Purpose: allocates memory for pirate list and its collection of pirates.
 *          Sets the initial length to 0 and the initial capacity to 25,
 *          defined as INITIAL_CAPACITY
 */
pirate_list *list_create() {
    pirate_list *lst = malloc(sizeof(pirate_list));
    lst->collection_of_pirates = malloc(INITIAL_CAPACITY * sizeof(pirate*));
    lst->length = 0;
    lst->capacity = INITIAL_CAPACITY;
    return lst;
}

/*
 * Parameters: pirate list, pirate
 * Returns: index of the pirate if it is found in the pirate list, length
 *          of the pirate list if the pirate is not already in the list
 * Purpose: determines whether the pirate is in the list or not
 */
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

/*
 * Parameters: pirate list, pirate, current index
 * Returns: NULL if the pirate is added to list, pointer to pirate if the
 *          pirate is found to be already in the list
 * Purpose: attempts to add the pirate to the list. If the pirate is found
 *          to not be in the list, checks to see if the list capacity needs 
 *          to be increased. Moves every pirate in the the list from the 
 *          index over to the right one, then inserts the pirate at the
 *          specified index and increases the length
 */
pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx) {
    // if the pirate is not already in the list
    if (list_index_of(pirates, p) == pirates->length) {
        list_expand_if_necessary(pirates);
        // if the idx is not the last element in the array, move every 
        // pirate from the idx on one to the right
        size_t length = pirates->length;
        if (length > 0 && idx < length - 1) {
            for (int j = pirates->length - 1; j >= idx; --j) {
            pirates->collection_of_pirates[j + 1] = 
                pirates->collection_of_pirates[j];
            }  
        }

        pirates->collection_of_pirates[idx] = p;
        pirates->length++;
        return NULL;
    } else {
        // if p is already in the list, return a pointer to p
        return p;
    }
}

/*
 * Parameters: pirate list, pirate
 * Returns: NULL if the pirate is not found to be in the list, pointer to
 *          the removed pirate if it is removed
 * Purpose: checks to see if the pirate is in the list, then removes it. 
 *          Shifts each pirate from the index of the pirate to be removed
 *          one to the left, than decreases the length of the list by one.
 */
pirate *list_remove(pirate_list *pirates, pirate *p) {
    size_t pirate_index = list_index_of(pirates, p);
    // if the p is not found in the list
    if (pirate_index == pirates->length) {
        return NULL;
    } else {
        // remove p from list
        pirate *pirate_to_remove = pirates->
            collection_of_pirates[pirate_index];
        for (int i = pirate_index; i < (pirates->length - 1); i++) {
            pirates->collection_of_pirates[i] = pirates->
                collection_of_pirates[i + 1];
        }
        pirates->length--;
        list_contract_if_necessary(pirates);
        return pirate_to_remove;
    }
}

/*
 * Parameters: pirate list, index
 * Returns: pointer to pirate if the index is valid, NULL if it is not
 * Purpose: returns the pirate at the supplied index if the index is
 *          not larger than the length of the list or smaller than 0
 */
pirate *list_access(pirate_list *pirates, size_t idx) {
    if (idx < pirates->length && idx >= 0) {
        return pirates->collection_of_pirates[idx];
    } else {
        return NULL;
    }
}

/*
 * Parameters: pirate list
 * Returns: nothing
 * Purpose: alphabetically sorts the pirates from left to right. If the 
 *          two pirates are in the wrong order, they are switched. In this
 *          case, the pirate on the left of the two is checked with the pirate
 *          to the left of that one, and they switch if necessary. This is 
 *          repeated until that pirate is correctly sorted, and then it moves
 *          on to the next pirate. This function uses insertion sort.
 */
void list_sort(pirate_list *pirates) {
    for (int i = 1; i < pirates->length; i++) {
        int j = i;
        char *previous_name = pirates->collection_of_pirates[j - 1]->name;
        char *current_name = pirates->collection_of_pirates[j]->name;
        // while they are in the wrong order, swap them
        while((j >= 1) && (strcmp(previous_name, current_name)) > 0) {
            char *temp_name = previous_name;

            pirates->collection_of_pirates[j - 1]->name = current_name;
            pirates->collection_of_pirates[j]->name = temp_name;

            if (j > 1) {
                --j;    
            }

            previous_name = pirates->collection_of_pirates[j - 1]->name;
            current_name = pirates->collection_of_pirates[j]->name;
        }
    }
}

/*
 * Parameters: pirate list
 * Returns: length of the pirate list
 * Purpose: allows hookbook.c to access the length of the pirate 
 *          list if necesary
 */
size_t list_length(pirate_list *pirates) {
    return pirates->length;
}

/*
 * Parameters: pirate list
 * Returns: nothing
 * Purpose: if the list is not empty, frees the collection of pirates and then
 *          the list. As specified in the README, it does not free the memory
 *          associated with the pirates in the list
 */
void list_destroy(pirate_list *pirates) {
    if (pirates != NULL) {
        free(pirates->collection_of_pirates);
        free(pirates);
    }
}