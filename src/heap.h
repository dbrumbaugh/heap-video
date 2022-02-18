/*
 * An implementation of a Binary Heap.
 * Copyright 2022, Douglas B. Rumbaugh
 */

#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct minheap minheap;

minheap *create_heap(size_t size);
void     destroy_heap(minheap *heap);

int      insert_heap(minheap *heap, size_t value);
int      remove_heap(minheap *heap, size_t *result);

bool     check_heap(minheap *heap);
#endif
