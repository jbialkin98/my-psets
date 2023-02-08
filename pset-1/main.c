#include <stdio.h>
#include <stdlib.h>
#include "life.h"

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
    
    // Print contents of game_array
    for (int i = 0; i < game_size; i++) {                
        if (i == 0) {
            printf("[");
        }
        if (i == game_size - 1) {
            printf("%i]\n", game_array[i]);
            break;
        }
        
        printf("%i, ", game_array[i]);
    }

    int next_array[game_size];

    for (int i = 0; i < game_size; i++) {
        if (isAlive(game_array, i, game_size) == true) {
            if (shouldDie(game_array, i, game_size) == true) {
                next_array[i] = 0;
            } else {
                next_array[i] = 0;
            }
        } else {
            next_array[i] = game_array[i];
        }
    }
    // for (int i = 0; i< game_size; i++) {
    //     if (isAlive(game_array, i, game_size) == true) {
    //         game_array[i] = 1;
    //     } else {
    //         game_array[i] = 0;
    //     }
    // }
    return 0;
}