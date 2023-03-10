/*
* life.h
* Josh Bialkin
* CPSC 223 pset-2
* 2/11/23
* Header file, declaring all functions used in main.c and life.c.
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __LIFE_H__
#define __LIFE_H__

int inputChecks(int argc, char* argv[]);
int numberChecks(int time_steps, int game_size, char* initial_values_input);
bool isAlive(int array[], size_t index, size_t size);
bool shouldDie(int array[], size_t index, size_t size);
void printArray(int array[], size_t size, size_t step_number);
void advanceTime(int game_array[], int next_array[], 
    size_t game_size, size_t step_number);

#endif