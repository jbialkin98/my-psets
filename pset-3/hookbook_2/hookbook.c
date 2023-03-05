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
    // label and value each have a max of 64 characters, add 1 for ':' and 
    // 1 for '\0' or '\n' to get max length of 130
    char s[130];
    size_t idx = 0;
    const char separater[2] = ":";
    char *separated_strings;
    // until there are no more lines in the file, read the file to 
    // create new pirates with the correct name
    while (fgets(s, sizeof(s), infile) != NULL) {
        
        char *new_line_found = strchr(s, '\n');
        // if the pirate has a new line character at the end,
        // replace it with '0' to terminate the string
        if (new_line_found) {
            *new_line_found = '\0';
        }
        separated_strings = strtok(s, separater);
        while (separated_strings != NULL) {
            printf("%s\n", separated_strings);
            separated_strings = strtok(NULL, separater);
        }

        // pirate *new_pirate = create_pirate(s);
        // pirate *p = list_insert(lst, new_pirate, idx);
        // if (p == NULL) {
        //     idx++;
        // }
    }

    // list_sort(lst);
    // print_list(lst);
    // list_destroy(lst);
    return 0;
}