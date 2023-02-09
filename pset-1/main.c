#include <stdio.h>
#include <stdlib.h>
#include "life.h"

int main(int argc, char* argv[]) {
    if (inputChecks(argc, argv) == 1) {
        return 1;
    }

    int time_steps = atoi(argv[1]);
    int step_number = 0;
    int game_size = atoi(argv[2]);
    char* start = argv[3];
    int game_array[game_size];

    // Create array of ints from start input
    for (int i = 0; i < game_size; i++) {
        char letter_num = start[i];
        int num = letter_num - '0';
        game_array[i] = num;
    }
    
    // Print contents of game_array
    printArray(game_array, game_size, step_number);

    int next_array[game_size];

    for (step_number = 1; step_number <= time_steps; step_number++) {
        advanceTime(game_array, next_array, game_size, step_number);
    }

    return 0;
}