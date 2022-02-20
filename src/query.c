/*
 * A demonstration of the minheap data structure
 *
 * Accepts and integer k <= 9 and prints the k
 * smallest elements from the array, in sorted
 * order.
 *
 * Copyright Douglas B. Rumbaugh, 2022
 */

#include <stdio.h>
#include "heap.h"

int main(int argc, char *argv[])
{
    size_t x[9] = {6, 9, 1, 2, 3, 5, 8, 15, 11};
    size_t k = atoi(argv[1]);

    minheap *heap = create_heap(15);

    for (size_t i=0; i<9; i++) {
        insert_heap(heap, x[i]);
    }

    for (size_t i=1; i<=k; i++) {
        size_t val;
        remove_heap(heap, &val);

        printf("%ld ", val);
    }

    printf("\n");

    destroy_heap(heap);
}
