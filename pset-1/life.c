#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

bool isAlive(int array[], size_t index, size_t size) {
    if (array[index] == 1) {
        return true;
    } else {
        return false;
    }
}

bool shouldDie(int array[], size_t index, size_t size) {
    if (index == 0 || index == size - 1) {
        return false;
    } else if (array[index - 1] == 1 && array[index + 1] == 1) {
        return true;
    } else {
        return false;
    }
}

void printArray(int array[], size_t size, int step_number) {
    if (step_number == 0) {
        printf("Initial values                  ");
    } else {
        printf("Values after timestep %i         ", step_number);
    }
    for (int i = 0; i < size; i++) {                
        if (i == 0) {
            printf("[");
        }
        if (i == size - 1) {
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
                // if it shouldn't, keep it the same
                next_array[i] = game_array[i];
             }
        } else {
            // if cell is not alive, keep it the same in next_array
            next_array[i] = game_array[i];
        }
        // if the right neighbor is in bounds and equal to 0, bring it to life
        if (i + 1 < game_size && game_array[i+1] == 0 && game_array[i] == 1) {
            next_array[i+1] = 1;
        }
        // if the left neighbor is in bounds and equal to 0, bring it to life
        if (i - 1 >= 0 && game_array[i-1] == 0 && game_array[i] == 1) {
            next_array[i-1] = 1;
        }
        // allows the last cell to become 1 if the cell next to it is alive
        if (i == game_size-1 && game_array[i-1] == 1) {
            next_array[i] = 1;
        }
        // brings dead cell to life if the cell to the left is alive
        if (i - 1 >= 0 && game_array[i] == 0 && game_array[i-1] == 1) {
            next_array[i] = 1;
        }
    }
    printArray(next_array, game_size, step_number);
    for (int i = 0; i < game_size; i++) {
        game_array[i] = next_array[i];
    }
}