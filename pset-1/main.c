#include <stdio.h>
#include <stdlib.h>
// #include "life.h"

int main(int argc, char* argv[]) {
    int time_steps = atoi(argv[1]);
    int game_size = atoi(argv[2]);
    char* start = argv[3];
    int game_array[game_size];

    printf("Initial values                  ");

    // Create array of ints from start input
    for (int i = 0; i < game_size; i++) {
        char letter_num = start[i];
        int num = letter_num - '0';
        game_array[i] = num;
    }
    
    for (int i = 0; i < game_size; i++) {                
        if (i == 0) {
            printf("[");
        }
        if (i == game_size - 1) {
            printf("%i]\n", game_array[i]);
            break;
        }
        
        printf("%i,", game_array[i]);
    }
}