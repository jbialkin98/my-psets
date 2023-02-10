#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "life.h"

int inputChecks(int argc, char* argv[]) {
    // if there aren't enough inputs in the command line
    if (argc < 4) {
        return 1;
    }
    // if there is a letter input where it should only contain numbers
    int input_length = strlen(argv[1]);
    for (int i = 0; i < input_length; i++) {
        if (isdigit(argv[1][i]) == 0) {
            return 1;
        }
    }

    input_length = strlen(argv[2]);
    for (int i = 0; i < input_length; i++) {
        if (isdigit(argv[2][i]) == 0) {
            return 1;
        }
    }
    // if initial values input contains anything other than a 0 or 1
    input_length = strlen(argv[3]);
    for (int i = 0; i < input_length; i++) {
        char c = argv[3][i];
        if (c != '0' && c != '1'){
            return 1;
        }
    }
    return 0;
}

int numberChecks(int time_steps, int game_size, char* initial_values_input) {
    // if the number of times to loop the game is 0 or negative
    // or if the size of the array is 0 or less
    if (time_steps < 0 || game_size <= 0) {
        return 1;
    } else if (game_size > strlen(initial_values_input)) {
        // if the listed size of the array is greater than the actual size of the array
        return 1;
    } else {
        return 0;
    }
}


bool isAlive(int array[], size_t index, size_t size) {
    if (array[index] == 1) {
        return true;
    } else {
        return false;
    }
}

bool shouldDie(int array[], size_t index, size_t size) {
    // First and last elememnts can't die
    if (index == 0 || index == size - 1) {
        return false;
    } else if (array[index - 1] == 1 && array[index + 1] == 1) {
        // if the left and right neighbors are alive, the cell should die
        return true;
    } else {
        return false;
    }
}

void printArray(int array[], size_t size, int step_number) {
    // the first time the array is printed
    if (step_number == 0) {
        printf("Initial values                  ");
    } else {
        // every other time the array is printed
        printf("Values after timestep %i         ", step_number);
    }
    for (int i = 0; i < size; i++) {                
        if (i == 0) {
            // before the first number of the array is printed
            printf("[");
        }
        if (i == size - 1) {
            // the last number of the array printed with the closing bracket
            printf("%i]\n", array[i]);
            break;
        }
        printf("%i, ", array[i]);
    }
}

void advanceTime(int game_array[], int next_array[], size_t game_size, int step_number) {
    for (int i = 0; i < game_size; i++) {
        if (isAlive(game_array, i, game_size) == true) {
            // if it's alive, check if it should die
            if (shouldDie(game_array, i, game_size) == true) {
            // if it should die, set it to 0
                next_array[i] = 0;
            } else {
                // if it shouldn't die, keep it the same
                next_array[i] = game_array[i];
            }
        } else {
            // if the cell is dead, check its neighbors
            if (i + 1 < game_size && game_array[i+1] == 1) {
                // if the right neighbor is in bounds and equal to 0, bring it to life
                next_array[i] = 1;
            } else if (i - 1 >= 0 && game_array[i-1] == 1) {
                // if the left neighbor is in bounds and equal to 0, bring it to life
                next_array[i] = 1;
            } else {
                // if neither neighbor is one, keep it as 0
                next_array[i] = 0;
            }
        }
            // brings dead cell to life if the cell to the left is alive
            
        //     // if cell is not alive, keep it the same in next_array
        //     next_array[i] = game_array[i];
        // }
        // // if the right neighbor is in bounds and equal to 0, bring it to life
        // if (i + 1 < game_size && game_array[i+1] == 0 && game_array[i] == 1) {
        //     next_array[i+1] = 1;
        // }
        // // if the left neighbor is in bounds and equal to 0, bring it to life
        // if (i - 1 >= 0 && game_array[i-1] == 0 && game_array[i] == 1) {
        //     next_array[i-1] = 1;
        // }
        // allows the last cell to become 1 if the cell next to it is alive
        // if (i == game_size-1 && game_array[i-1] == 1) {
        //     next_array[i] = 1;
        // }
        // // brings dead cell to life if the cell to the left is alive
        // if (i - 1 >= 0 && game_array[i] == 0 && game_array[i-1] == 1) {
        //     next_array[i] = 1;
        // }
    }
    printArray(next_array, game_size, step_number);
    // make the next iteration of game_array the updated next_array
    for (int i = 0; i < game_size; i++) {
        game_array[i] = next_array[i];
    }
}