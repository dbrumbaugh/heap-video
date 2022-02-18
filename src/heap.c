/*
 * An implementation of a Binary Heap.
 * Copyright 2022, Douglas B. Rumbaugh
 */

#include "heap.h"


#define LEFT(x) (2*(x) + 1)
#define RIGHT(x) (2*(x) + 2)
#define PARENT(x) ((x-1) / 2)

static void swap(size_t *a, size_t *b);
static ssize_t min_child(minheap *heap, size_t idx);


struct minheap {
    size_t *data;
    size_t n;
    size_t max;
};

minheap *create_heap(size_t size)
{
    minheap *heap = malloc(sizeof(minheap));
    if (!heap) {
        return NULL;
    }

    heap->n = 0;
    heap->max = size;
    heap->data = malloc(sizeof(size_t) * size);
    if (!heap->data) {
        return NULL;
    }

    return heap;
}


void destroy_heap(minheap *heap)
{
    free(heap->data);
    free(heap);
}


int insert_heap(minheap *heap, size_t value)
{
    if (heap->n >= heap->max) {
        return 0; // too large to fit
    }

    size_t new_idx = heap->n++;
    heap->data[new_idx] = value;

    // up-heap
    while (new_idx != 0 && heap->data[PARENT(new_idx)] > heap->data[new_idx]) {
        swap(heap->data + PARENT(new_idx), heap->data + new_idx);
        new_idx = PARENT(new_idx);
    }

    return 1;
}


bool check_heap(minheap *heap)
{
    for (size_t i=1; i<heap->n; i++) {
        if (heap->data[PARENT(i)] > heap->data[i]) {
            return false;
        }
    }

    return true;
}

int remove_heap(minheap *heap, size_t *result)
{
    if (heap->n == 0) {
        return 0;
    }

    *result = heap->data[0];
    swap(heap->data, heap->data + --heap->n);

    ssize_t idx = 0;
    ssize_t child_idx;

    // down-heap
    while ((child_idx = min_child(heap, idx)) != -1 && heap->data[idx] > heap->data[child_idx]) {
        swap(heap->data + idx, heap->data + child_idx);
        idx = child_idx;
    }

    return 1;
}


static void swap(size_t *a, size_t *b)
{
    if (a == b) return;

    size_t c = *a;
    *a = *b;
    *b = c;
}


static ssize_t min_child(minheap *heap, size_t idx)
{
    ssize_t left = LEFT(idx) < heap->n ? LEFT(idx) : -1;
    ssize_t right = RIGHT(idx) < heap->n ? RIGHT(idx) : -1;

    if (left == -1 && right == -1) {
            return -1;
    } else if (left == -1) {
        return right;
    } else if (right == -1) {
        return left;
    }

    if (heap->data[left] < heap->data[right]) {
        return left;
    }

    return right;
}


