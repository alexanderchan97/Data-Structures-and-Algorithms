/*******************************************************************************

Vector Tests
 - Contains test cases for vector.c

*******************************************************************************/

 #include <assert.h>
 #include <stdio.h>

 #include "vector.h"

 int main(int argc, char **argv) {

 	struct Vector *v = vector_init();
 	int capacity = vector_capacity(v);

 	assert(vector_size(v) == 0);
 	assert(vector_is_empty(v));

 	vector_push_back(v, 5);
 	vector_print(v);
 	printf("\n");
 	assert(vector_size(v) == 1);
 	assert(!vector_is_empty(v));
 	assert(vector_front(v) == 5);
 	assert(vector_back(v) == 5);

 	vector_insert(v, 1, 0);
 	vector_insert(v, 2, 1);
 	vector_push_back(v, 6);
 	vector_push_back(v, 7);
 	vector_push_back(v, 8);
 	vector_print(v);
 	printf("\n");
 	assert(vector_size(v) == 6);
 	assert(vector_front(v) == 1);
 	assert(vector_back(v) == 8);
 	assert(vector_capacity(v) == capacity);

 	vector_set_element(v, 3, 2);
 	assert(vector_get(v, 2) == 3);
 	assert(vector_size(v) == 6);
 	vector_print(v);
 	printf("\n");

 	vector_push_back(v, 9);
 	vector_push_back(v, 10);
 	vector_push_back(v, 11);
 	vector_push_back(v, 12);
 	vector_push_back(v, 13);
 	assert(vector_capacity(v) != capacity);

 	assert(vector_pop_back(v) == 13);
 	assert(vector_size(v) == 10);

 	vector_remove_element(v, 3);
 	vector_print(v);
 	printf("\n");
 	assert(vector_size(v) == 9);

 	vector_clear(v);
 	assert(vector_size(v) == 0);
 	assert(vector_is_empty(v));

 	assert(vector_destroy(v) == NULL);

 	printf("All tests passed.\n");
 	return 0;
 }