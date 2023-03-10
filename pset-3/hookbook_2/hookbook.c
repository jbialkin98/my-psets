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

void print_skills(pirate *p);

int main(int argc, char **argv) {
    // if there are fewer than four input arguments
    if (argc < 4) {
        fprintf(stderr, "Invalid arguments\n");
        return 1;
    }

    // steps to read in first file
    char *file_name = argv[1];
    // if the file containing pirate information does not exist
    if (access(file_name, F_OK) != 0) {
        fprintf(stderr, "Invalid filename: %s\n", file_name);
        return 1;
    }

    FILE *infile = fopen(file_name, "r");
    pirate_list *lst = list_create();
    // label and value each have a max of 64 characters, add 1 for ':' and 
    // 1 for '\0' or '\n' to get max length of 130
    char s[130];
    size_t idx = 0;
    const char separator[2] = ":";
    char *separated_strings;

    pirate *new_pirate;
    pirate *p;
    char *selected_field;
    char *field_details;
    int number_of_times_looped = 0;
    // until there are no more lines in the file, read the file to 
    // get the listed information
    while (fgets(s, sizeof(s), infile) != NULL) {
        char *new_line_found = strchr(s, '\n');
        // if the pirate has a new line character at the end,
        // replace it with '0' to terminate the string
        if (new_line_found) {
            *new_line_found = '\0';
        }
        int time = 1;
        // get the string before and after the ":"
        separated_strings = strtok(s, separator);
        while (separated_strings != NULL) {
            // first time (before the ":")
            if (time % 2 != 0) {
                selected_field = separated_strings;
                // if we get to the next pirate, add the previous pirate
                // to the list and create a new one
                if (strcmp(selected_field, "name") == 0) {
                    // doesn't insert the first instance of name
                    if (number_of_times_looped > 0) {
                        p = list_insert(lst, new_pirate, idx);
                        if (p == NULL) {
                            idx++;
                        }
                    }
                    new_pirate = create_pirate();
                }
            } else {
                // second time (after the ":")
                field_details = separated_strings;
                p = add_to_pirate(new_pirate, selected_field, field_details);
                selected_field = NULL;
                field_details = NULL;
            }
            separated_strings = strtok(NULL, separator);
            time++;
            number_of_times_looped++;
        }
        time = 1;
    }
    // insert the last pirate of the file
    p = list_insert(lst, new_pirate, idx);
    fclose(infile);

    // steps to read in second file
    char *captain_file = argv[2];
    char c[130];
    // if the captain file does not exist
    if (access(captain_file, F_OK) != 0) {
        fprintf(stderr, "Invalid filename: %s\n", captain_file);
        return 1;
    }
    FILE *captain_pairs = fopen(captain_file, "r");
    
    number_of_times_looped = 0;
    const char slash_separator[2] = "/";

    while (fgets(c, sizeof(c), captain_pairs) != NULL) {
        char *pirate_to_add_to = NULL;
        char *captain_to_add = NULL;
        char *new_line_found = strchr(c, '\n');
        // if the line has a new line character at the end,
        // replace it with '0' to terminate the string
        if (new_line_found) {
            *new_line_found = '\0';
        }
        int time = 1;
        char *separated_strings = strtok(c, slash_separator);
        while (separated_strings != NULL) {
            // first time (before "/")
            if (time % 2 != 0) {
                pirate_to_add_to = separated_strings;
            } else {
                // second time (after "/")
                captain_to_add = separated_strings;
                size_t length = list_length(lst);
                for (int i = 0; i < length; i++) {
                    // pirate at i
                    pirate *p = list_access(lst, i);
                    // if the pirate from the string is the pirate at i
                    if (strcmp(pirate_to_add_to, p->name) == 0) {
                        size_t length = list_length(lst);
                        for (int i = 0; i < length; i++) {
                            pirate *potential_captain = list_access(lst, i);
                            // if the pirate at i is the pirate that needs to 
                            // become the pirate p's captain, set the pirate
                            // as the captain
                            if (strcmp(potential_captain->name, 
                                captain_to_add) == 0) {
                                    p->captain = potential_captain;
                            }
                        }
                    }
                }
                p = add_to_pirate(new_pirate, pirate_to_add_to, 
                    captain_to_add);
                pirate_to_add_to = NULL;
                captain_to_add = NULL;
            }
            separated_strings = strtok(NULL, slash_separator);
            time++;
            number_of_times_looped++;
        }
        time = 1;
    }
    fclose(captain_pairs);

    // ensure the third input argument is valid
    char *sort_arg = argv[3];
    if ((strcmp(sort_arg, "-n") != 0) &&
        (strcmp(sort_arg, "-v") != 0) &&
        (strcmp(sort_arg, "-t") != 0)) {
            fprintf(stderr, "Invalid argument: %s\n", sort_arg);
            return 1;
        }

    list_sort(lst, sort_arg);

    size_t length = list_length(lst);
    //print the list of pirates
    for (size_t i = 0; i < length; i++) {
        pirate *p = list_access(lst, i);
        char *pirate_name = p->name;
        char *pirate_title = p->title;
        if (pirate_title == NULL) {
            pirate_title = "(None)";
        }
        char *pirate_captain_name = NULL;
        char *pirate_captain_title = NULL;
        char *pirate_captain_port = NULL;
        if (p->captain != NULL) {
            pirate_captain_name = p->captain->name;
            pirate_captain_title = p->captain->title;
            if (pirate_captain_title == NULL) {
                pirate_captain_title = "(None)";
            }
            pirate_captain_port = p->captain->port;
            if (pirate_captain_port == NULL) {
                pirate_captain_port = "(None)";
            }
        }
        if (pirate_captain_name == NULL) {
            pirate_captain_name = "(None)";
        }
        char *pirate_vessel = p->vessel;
        if (pirate_vessel == NULL) {
            pirate_vessel = "(None)";
        }
        char *pirate_port = p->port;
        if (pirate_port == NULL) {
            pirate_port = "(None)";
        }
        size_t pirate_treasure = p->treasure;

        printf("Pirate: %s\n", pirate_name);
        printf("    Title: %s\n", pirate_title);
        printf("    Captain: %s\n", pirate_captain_name);
        if (strcmp(pirate_captain_name, "(None)") != 0) {
            printf("        Captain's Title: %s\n", pirate_captain_title);
            printf("        Captain's Favorite Port of Call: %s\n", 
                pirate_captain_port);
        }
        printf("    Vessel: %s\n", pirate_vessel);
        printf("    Treasure: %zu\n", pirate_treasure);
        printf("    Favorite Port of Call: %s\n", pirate_port);
        printf("    Skills: ");
        print_skills(p);
        printf("\n");
    }

    //free the list of pirates
    for (size_t i = 0; i < length; i++) {
        pirate *p = list_access(lst, i);
        if (p->name) {  
            free(p->name);
        }
        if (p->title != NULL) {
            free(p->title);
        }
        if ((p->vessel != NULL) && strcmp(p->vessel, "(None)") != 0) {
            free(p->vessel);
        }
        if (p->port != NULL) {
            free(p->port);
        }
        if (p->skills_length != 0) {
            for (int j = 0; j < p->skills_length; j++) {
                free(p->skills[j]->skill_name);
                free(p->skills[j]);
            }
            free(p->skills);
        }
        free(p);
    }

    list_destroy(lst);
    return 0;
}

/*
 * Parameters: pointer to pirate
 * Returns: nothing
 * Purpose: goes through a pirate's skills list and prints out each skill
 *          with its proper spacing. It then prints out the correct number
 *          of asterics for the number of times the skill appears in the
 *          input file
 */
void print_skills(pirate *p) {
    if (p->skills_length == 0) {
        printf("(None)\n");
    } else {
        for (size_t i = 0; i < p->skills_length; i++) {
            if (i == 0) {
                printf("%s ", p->skills[i]->skill_name);
            } else {
                printf("            %s ", p->skills[i]->skill_name);
                
            }
            for (size_t j = 0; j < p->skills[i]->number_of_occurances; j++) {
                printf("*");
                if (j == (p->skills[i]->number_of_occurances - 1)) {
                    printf("\n");
                }
            }
        }
    }
}