/*******************************************************************************
 *
 * Binary Min-Heap
 *
 * ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "../vector/vector.h"

struct Heap {
    struct Vector *v;
};

struct Heap *heap_init() {
    struct Heap *heap = malloc (sizeof (*heap));
    struct Vector *vector = malloc (sizeof (*vector));
    heap -> v = vector;
    return heap;
}

