/*
 * Testcode for heap.c
 */

#include <assert.h>
#include <stdio.h>

#include "heap.h"


int main(int argc, char *argv[]) 
{

    minheap *heap = create_heap(15);
    assert(check_heap(heap));

    for (size_t i=15; i>0; i--) {
        assert(insert_heap(heap, i));
        if (!check_heap(heap)) {
            printf("insert: %ld\n", i);
        }
    }

    for (size_t i=0; i<15; i++) {
        size_t val;
        assert(remove_heap(heap, &val));
        if (!check_heap(heap)) {
            printf("remove: %ld\n", i);
        }
    }
    
    destroy_heap(heap);
}
