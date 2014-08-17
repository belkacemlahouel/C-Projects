/***
 * @author Belkacem LAHOUEL
 * UTBM: University of Technology of Belfort-Montbeliard
 * 08/2014
 * belkacem.lahouel@utbm.fr
 *
 * Code for classic sorting algorithms.
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***
 * Constant definition for maximal array size
 ***/

#define MAX_SIZE 25

/***
 * Definition of a new data-type: Boolean.
 ***/

typedef enum _Boolean {
    TRUE,
    FALSE
} Boolean;

/***
 * Fills the array with numbers in order between 1 and MAX_SIZE
 ***/

void fill_order(int _array[MAX_SIZE]) {
    int i = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        _array[i] = (i+1);
    }
}

/***
 * Fills the array with random numbers between 1 and 99
 ***/

void fill_randomly(int _array[MAX_SIZE]) {
    int i;
    for (i = 0; i < MAX_SIZE; ++i) {
        _array[i] = rand()%100 + 1;
    }
}

/***
 * Swaps two integers using their indexes in this array
 ***/

void swap(int _array[MAX_SIZE], int _a, int _b) {
    int tmp = _array[_a];
    _array[_a] = _array[_b];
    _array[_b] = tmp;
}

/***
 * Shuffles the array properly using Fisher-Yates' algorithm
 ***/

void shuffle(int _array[MAX_SIZE]) {
    int i;
    for (i = MAX_SIZE-1; i >= 0; --i) {
        int tmp = rand()%(i+1);
        swap(_array, tmp, i);
    }
}

/***
 * Prints the whole array
 ***/

void print_array(int _array[]) {
    int i;
    printf("::");
    for (i = 0; i < MAX_SIZE; ++i) {
        printf(" %d", _array[i]);
    }
    printf("\n");
}

/***
 * Main function used to test those algorithms on an array of int.
 ***/

int main(int argc, char** argv) {
    int tmp[MAX_SIZE];

    srand(time(NULL));

    fill_randomly(tmp);
    print_array(tmp);
    fill_order(tmp);
    print_array(tmp);
    shuffle(tmp);
    print_array(tmp);

    return EXIT_SUCCESS;
}
