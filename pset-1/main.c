#include <stdio.h>
#include <stdlib.h>
#include "life.h"

int main(int argc, char* argv[]) {
    // ensure the inputs are valid
    if (inputChecks(argc, argv) == 1) {
        return 1;
    }
    // number of times the program needs to loop converted to int
    int time_steps           = atoi(argv[1]);
    size_t size_t_time_steps = time_steps;
    size_t current_step_number = 0;
    // listed size of the array converted to int
    int game_size           = atoi(argv[2]);
    size_t size_t_game_size = game_size;
    char* initial_values_array = argv[3];

    // ensures the numbers fall within the spec
    if (numberChecks(time_steps, game_size, initial_values_array) == 1) {
        return 1;
    }

    int game_array[game_size];

    // convert initial values input string to an int array
    for (int i = 0; i < size_t_game_size; i++) {
        char letter_num = initial_values_array[i];
        int num = letter_num - '0';
        game_array[i] = num;
    }
    
    // Print contents of game_array
    printArray(game_array, size_t_game_size, current_step_number);

    int next_array[game_size];

    // loop the advance time function the number of times listed 
    // in the user's input
    for (current_step_number = 1; current_step_number <= size_t_time_steps; 
            current_step_number++) {
        advanceTime(game_array, next_array, 
            size_t_game_size, current_step_number);
    }

    return 0;
}