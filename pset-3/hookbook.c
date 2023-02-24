#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char *file_name = argv[1];
    FILE *infile = fopen(file_name, "r");
    pirate_list *lst = list_create();
    char s[65];
    size_t idx = 0;
    
    while (fgets(s, sizeof(s), infile) != NULL) {
        // pirate* new_pirate = malloc(sizeof(pirate));
        // new_pirate->name = malloc(65*sizeof(char));
        // strcpy(new_pirate->name, s);
        pirate *new_pirate = create_pirate(s);
        printf("Name to insert: ");
        printf("%s", new_pirate->name);
        list_insert(lst, new_pirate, idx);
        idx++;
    }

    printf("\n\n");
    printf("Initial List:\n");
    print_list(lst);
    list_sort(lst);
}