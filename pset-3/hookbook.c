#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    char *file_name = argv[1];
    // if the file does not exist
    if (access(file_name, F_OK) != 0) {
        return 1;
    }
    FILE *infile = fopen(file_name, "r");
    pirate_list *lst = list_create();
    char s[65];
    size_t idx = 0;
    
    while (fgets(s, sizeof(s), infile) != NULL) {
        // pirate* new_pirate = malloc(sizeof(pirate));
        // new_pirate->name = malloc(65*sizeof(char));
        // strcpy(new_pirate->name, s);

        char *new_line_found = strchr(s, '\n');
        if (new_line_found) {
            *new_line_found = '\0';
        }
        pirate *new_pirate = create_pirate(s);
        printf("Name to insert: ");
        printf("%s\n", new_pirate->name);
        pirate *p = list_insert(lst, new_pirate, idx);
        if (p == NULL) {
            idx++;
        }
    }

    printf("\n\n");
    printf("Initial List:\n");
    print_list(lst);
    list_sort(lst);
    list_destroy(lst);
    return 0;
}