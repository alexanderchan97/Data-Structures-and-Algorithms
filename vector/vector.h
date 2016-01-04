#ifndef __VECTOR_H__
#define __VECTOR_H__

struct Vector {
	int size;
	int capacity;
	double *contents;
};

/** 
 * Initializes an empty vector with default capacity.
 *
 * @return a pointer to the empty vector
 */
struct Vector *vector_init();

/**
 * Increases the vector capacity by the default factor of 2.
 *
 * @param v pointer to the vector
 */
void vector_inc_capacity(struct Vector *);

/**
 * Returns the vector size.
 *
 * @param v pointer to the vector
 * @return the size of the vector
 */
int vector_size(struct Vector *);

/**
 * Returns the vector's capacity.
 *
 * @param v pointer to the vector
 * @return the capacity of the vector
 */
int vector_capacity(struct Vector *);

/**
 * Indicates whether or not the vector is empty.
 *
 * @param v pointer to the vector
 * @return 1 if the vector is empty, 0 otherwise
 */
int vector_is_empty(struct Vector *);

/**
 * Returns the value at the specified index of the vector.
 *
 * @param v pointer to the vector
 * @param i index of the element to be returned
 * @return the value at index i
 */
double vector_get(struct Vector *, int);

/**
 * Returns the value of the first element of the vector.
 *
 * @param v pointer to the vector
 * @return the value of the first element
 */
double vector_front(struct Vector *);

/**
 * Returns the value of the last element of the vector.
 *
 * @param v pointer to the vector
 * @return the value of the last element
 */
double vector_back(struct Vector *);

/**
 * Adds the specified value to the end of the vector,
 * increasing the capacity of the vector if necessary.
 *
 * @param v pointer to the vector
 * @param x value to append to the vector
 */
void vector_push_back(struct Vector *, double);

/**
 * Removes and returns the last element of the vector.
 *
 * @param v pointer to the vector
 * @return the value of the last element
 */
double vector_pop_back(struct Vector *);

/**
 * Inserts the specified value at the specified index
 * of the vector.
 *
 * @param v pointer to the vector
 * @param x value to insert
 * @param i index to insert the value x
 */
void vector_insert(struct Vector *, double, int);

/**
 * Removes the element at the specified index
 *
 * @param v pointer to the vector
 * @param i index to remove
 */
void vector_remove_element(struct Vector *, int);

/**
 * Replaces the value at the specified index with
 * the specified value.
 *
 * @param v pointer to the vector
 * @param x new value to replace old value with
 * @param i index of the old value to replace
 */
void vector_set_element(struct Vector *, double, int);

/**
 * Empties the vector, resulting in a vector with
 * size 0.
 *
 * @param v pointer to the vector
 */
void vector_clear(struct Vector *);

/**
 * Destructs the vector, freeing any allocated
 * memory blocks.
 *
 * @param v pointer to the vector
 */
void *vector_destroy(struct Vector *);

/**
 * Prints to standard output the contents of the vector.
 *
 * @param v pointer to the vector
 */
void vector_print(struct Vector *);

#endif // __VECTOR_H__
