#include <stdio.h>
#include <stdlib.h>
// #include "life.h"

int main(int argc, char* argv[]) {
    int time_steps = atoi(argv[1]);
    printf("%i\n", time_steps);

    int game_size = atoi(argv[2]);

    char* start = argv[3];

    for (int i = 0; i <= game_size - 2; i++) {
        if (i == 0) {
            printf("[");
        }
        if (i == game_size - 2) {
            printf("%c]\n", start[i]);
            break;
        }
        
        printf("%c,", start[i]);

    }
}