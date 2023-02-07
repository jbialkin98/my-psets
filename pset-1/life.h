#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef __LIFE_H__
#define __LIFE_H__

bool isAlive(int array[], size_t index, size_t size);
bool shouldDie(int array[], size_t index, size_t size);

#endif