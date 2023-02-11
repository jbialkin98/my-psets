/*
* life.c
* Josh Bialkin
* CPSC 223 pset-2
* 2/11/23
* Contains all the functions and logic for the game.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "life.h"

/*
* Parameters: number of command line inputs and what they are
* Returns: 1 if there is an error with the input, 0 if there is not
* Purpose: checks that there are enough inputs to run the program, whether 
           the inputs that are supposed to be numbers are actually numbers,
           and whether the inputted array only has 1's and 0's
*/ 
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
        if ((c != '0') && (c != '1')){
            return 1;
        }
    }
    return 0;
}

/*
* Parameters: number of times to run the game, listed size of the gamme array,
              and the inputted array with which the game should be played
* Returns: 1 if there is an error with the input, 2 if there is not
* Purpose: ensures that the number of times to run the game is not negative
           and that the listed size of the array is not larger than the
           actual length of the inputted array
*/ 
int numberChecks(int time_steps, int game_size, char* initial_values_input) {
    if ((time_steps < 0) || (game_size <= 0)) {
        return 1;
    } else if (game_size > strlen(initial_values_input)) {
        return 1;
    } else {
        return 0;
    }
}

/*
* Parameters: the array for the game, current index of the loop, and size of
              the array
* Returns: true if the current cell is 1, false if it is 0
* Purpose: determines whether the current cell in the loop is alive or dead
*/ 
bool isAlive(int array[], size_t index, size_t size) {
    if (array[index] == 1) {
        return true;
    } else {
        return false;
    }
}

/*
* Parameters: the array for the game, current index of the loop, and size of
              the array
* Returns: true if both neighbors are 1, false if they are not
* Purpose: check to see if the cell in the current loop should change to 0
           or stay 1 in the next array
*/ 
bool shouldDie(int array[], size_t index, size_t size) {
    // First and last elements can't die
    if ((index == 0) || (index == size - 1)) {
        return false;
    } else if ((array[index - 1] == 1) && (array[index + 1] == 1)) {
        // if the left and right neighbors are alive, the cell should die
        return true;
    } else {
        return false;
    }
}

/*
* Parameters: the array for the game, the size of the array, and the 
              current step of the the game 
* Returns: nothing
* Purpose: handles all of the printing in the program 
*/ 
void printArray(int array[], size_t size, size_t step_number) {
    // the first time the array is printed
    if (step_number == 0) {
        printf("Initial values                   ");
    } else {
        // every other time the array is printed
        // ensures the array is printed always starting on column 34
        printf("Values after timestep %-11li", step_number);
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

/*
* Parameters: the array for the game, a second array for the next round,
              the size of the game array, and the current step of the game
* Returns: nothing
* Purpose: plays each round of the game. checks to see if the current cell
           is alive, and if so, if it should die. if not, it should stay 
           the same in the next array.

           if the cell is not alive, it checks whether its neighbors are 
           alive. if so, they bring the current cell to life. if not, 
           the cell stays dead. 

           the function then calls the printArray function to print it,
           and then sets the game_array to the updated next_array for the
           next loop of the function.
*/ 
void advanceTime(int game_array[], int next_array[], 
    size_t game_size, size_t step_number) {
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
                    // if the right neighbor is in bounds and equal to 1, bring it to life
                    next_array[i] = 1;
                } else if ((i - 1 >= 0) && (game_array[i-1] == 1)) {
                    // if the left neighbor is in bounds and equal to 1, bring it to life
                    next_array[i] = 1;
                } else {
                    // if neither neighbor is 1, keep it as 0
                    next_array[i] = 0;
                }
            }
        }
        printArray(next_array, game_size, step_number);
        // make the next iteration of game_array the updated next_array
        for (int i = 0; i < game_size; i++) {
            game_array[i] = next_array[i];
        }
}