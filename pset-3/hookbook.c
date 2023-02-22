#include "pirate.h"
#include "pirate_list.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char *file_name = argv[1];
    FILE *infile = fopen(file_name, "r");
    // pirate_list *lst = list_create();
    int x = 1;
    while (x == 1) {
        char s[50];
        printf("%s\n",s);
        x = fscanf(infile, "%s", s);
    }
}