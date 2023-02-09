#include <stdio.h>
#include <stdlib.h>
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

// void advanceTime(arr[], n) {
    // if it should die, set to 0
    // else, next[i] = array[i]

    //if the right neighbor is in bounds and the right neighbor is 0 and current number is 1
    // set the right neighbor to 1
    // do the same for the left neighbor
// }


// return true;
// }

// int newArray(int num) {

// }