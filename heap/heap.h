#ifndef __HEAP_H__
#define __HEAP_H__

struct Heap;

/**
 * Initializes an empty min-heap.
 *
 * @return a pointer to the empty heap
 */
struct Heap *heap_init();

/**
 * Creates a min-heap from an array of doubles.
 *
 * @param d an array of doubles
 * @return a pointer to the heap
 */
struct Heap *heapify(double *);

/**
 * Returns the number of elements in the heap.
 *
 * @param h pointer to the heap
 * @return the number of elements in the heap
 */
int heap_size(struct Heap *);

/**
 * Returns the minimum element in the heap.
 *
 * @param h pointer to the heap
 * @return the minimum element in the heap
 */
double heap_min(struct Heap *);

/**
 * Inserts an element into a heap.
 *
 * @param h pointer to the heap
 * @param d the element to insert
 */
void heap_insert(struct Heap *, double);

/**
 * Removes the minimum element in the heap and returns it.
 *
 * @param h pointer to the heap
 * @return the minimum element in the heap
 */
double heap_extract_min(struct Heap *);

/**
 * Decreases the value of an element in the heap.
 *
 * @param h pointer to the heap
 * @param o the original element
 * @param n the new key
 */
void heap_decrease_key(struct Heap *, double, double);

/**
 * Deletes an element in the heap.
 *
 * @param h pointer to the heap
 * @param d element to remove
 */
void heap_delete(struct Heap *, double);

/**
 * Moves an element up in the heap.
 *
 * @param h pointer to the heap
 * @param i index of the element to sift up
 */
void heap_sift_up(struct Heap *, int);

/**
 * Moves an element down in the heap.
 *
 * @param h pointer to the heap
 * @param i index of the element to sift down
 */
void heap_sift_down(struct Heap *, int);

#endif // __HEAP_H__ 

