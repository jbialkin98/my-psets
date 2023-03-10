/*
 * hookbook.c
 * Josh Bialkin
 * CPSC 223, pset 3
 * 3/5/23
 * Driver file of the program
 */

#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // if there are fewer than two input arguments
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
    // until there are no more lines in the file, read the file to 
    // create new pirates with the correct name
    while (fgets(s, sizeof(s), infile) != NULL) {
        char *new_line_found = strchr(s, '\n');
        // if the pirate has a new line character at the end,
        // replace it with '0' to terminate the string
        if (new_line_found) {
            *new_line_found = '\0';
        }
        pirate *new_pirate = create_pirate(s);
        pirate *p = list_insert(lst, new_pirate, idx);
        if (p == NULL) {
            idx++;
        }
    }
    fclose(infile);

    list_sort(lst);

    //print each pirate, then free it
    size_t length = list_length(lst);
    for (size_t i = 0; i < length; i++) {
        pirate *p = list_access(lst, i);
        printf("%s\n", p->name);
        free(p->name);
        free(p);
    }
    list_destroy(lst);
    return 0;
}