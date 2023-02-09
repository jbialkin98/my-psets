#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __LIFE_H__
#define __LIFE_H__

int inputChecks(int argc, char* argv[]);
int numberChecks(int time_steps, int game_size);
bool isAlive(int array[], size_t index, size_t size);
bool shouldDie(int array[], size_t index, size_t size);
void printArray(int array[], size_t size, int step_number);
void advanceTime(int game_array[], int next_array[], size_t game_size, int step_number);

#endif