/***
 * @author Belkacem LAHOUEL
 * UTBM: University of Technology of Belfort-Montbeliard
 * 08/2014
 * belkacem.lahouel@utbm.fr
 *
 * C implementation of classic sorting algorithms and other functions.
 * Works on an array of size MAX_SIZE (pre-processor constant defined).
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***
 * Constant definition for maximal array size.
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
 * Fills the array with numbers in order between 1 and MAX_SIZE.
 * This is more convenient when checking if an array is sorted.
 ***/

void fill_order(int _array[MAX_SIZE]) {
    int i = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        _array[i] = (i+1);
    }
}

/***
 * Fills the array with random numbers between 1 and 99.
 ***/

void fill_randomly(int _array[MAX_SIZE]) {
    int i;
    for (i = 0; i < MAX_SIZE; ++i) {
        _array[i] = rand()%100 + 1;
    }
}

/***
 * Swaps two integers using their indexes in this array.
 ***/

void swap(int _array[MAX_SIZE], int _a, int _b) {
    int tmp = _array[_a];
    _array[_a] = _array[_b];
    _array[_b] = tmp;
}

/***
 * Shuffles the array properly using Fisher-Yates' algorithm.
 * (aka Knuth Shuffle).
 ***/

void shuffle(int _array[MAX_SIZE]) {
    int i;
    for (i = MAX_SIZE-1; i >= 0; --i) {
        int tmp = rand()%(i+1);
        swap(_array, tmp, i);
    }
}

/***
 * Prints the whole array.
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
 * Insertion sort implementation.
 ***/

void insertion_sort(int _a[]) {

}

/***
 * Selection sort implementation.
 * We perfom MAX_SIZE iterations.
 * And each time we put the smallest element at the beginning.
 * Works fine but is that the best solution for this sort?
 ***/

void selection_sort(int _a[]) {
    for (int limit = 0; limit < MAX_SIZE; ++limit) {
        int smallest_index = limit;
        for (int iter = limit; iter < MAX_SIZE; ++iter) {
            if (_a[smallest_index] > _a[iter]) {
                smallest_index = iter;
            }
        }
        swap(_a, smallest_index, limit);
    }
}

/***
 * Bubble sort implementation.
 * We compare neighbours together and we swap them if necessary.
 * If there is no swapping, the array is sorted.
 ***/

void bubble_sort(int _a[]) {
    Boolean swapped = TRUE;
    while (swapped == TRUE) {
        swapped = FALSE;
        for (int i = 0; i < MAX_SIZE-1; ++i) {
            if (_a[i] > _a[i+1]) {
                swap(_a, i, i+1);
                swapped = TRUE;
            }
        }
    }
}

/***
 * Main function used to test those algorithms on an array of int.
 ***/

int main(int argc, char** argv) {
    int tmp[MAX_SIZE];

    srand(time(NULL));

    fill_order(tmp);

    shuffle(tmp);
    selection_sort(tmp); // OK
    print_array(tmp);

    shuffle(tmp);
    insertion_sort(tmp); // TODO
    print_array(tmp);


    shuffle(tmp);
    bubble_sort(tmp); // NOT OK!!
    print_array(tmp);

    return EXIT_SUCCESS;
}
