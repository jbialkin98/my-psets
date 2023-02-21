#include "pirate.h"
#include "pirate_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INITIAL_CAPACITY 25
#define RESIZE_FACTOR 2

typedef struct implementation {
    pirate* names;
    int length;
    int capacity;
} pirate_list;

pirate_list *list_create() {
    pirate_list *lst = malloc(sizeof(pirate_list));
    lst->names = malloc(INITIAL_CAPACITY * sizeof(pirate));
    lst->length = 0;
    lst->capacity = INITIAL_CAPACITY;
    return lst;
}

size_t list_index_of(pirate_list *pirates, pirate *p) {
    for (int i = 0; i < pirates->length; i++) {
        char *name_1 = p->name;
        char *name_2 = pirates->names->name[i];
        if (strcmp(name_1, name_2) == 0) {
            return i;
        }
    }
    return 0;
}

pirate *list_insert(pirate_list *pirates, pirate *p, size_t idx) {
    
}
