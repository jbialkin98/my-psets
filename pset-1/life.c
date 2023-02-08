#include <stdio.h>
#include <stdlib.h>
#include "life.h"

bool isAlive(int array[], size_t index, size_t size) {
    printf("%i", array[index]);
    if (array[index] == 1) {
        return true;
    } else {
        return false;
    }
}

bool shouldDie(int array[], size_t index, size_t size) {
    // if (index == 0) {
    //     if (array[index + 1] == 1) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // } else if (index == size - 1) {
    //     if (array[index - 1] == 1) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }


    if (array[index - 1] == 1 && array[index + 1] == 1) {
        return true;
    } else {
        return false;
    }
}


// return true;
// }

// int newArray(int num) {

// }