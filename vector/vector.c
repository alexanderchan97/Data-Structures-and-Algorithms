/*******************************************************************************

Vector (Dynamic Array)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

#define VECTOR_INIT_CAP 10
#define INC_FACTOR 2

struct Vector {
    int size;
    int capacity;
    double *contents;
};

struct Vector *vector_init() {
    struct Vector *vector = malloc (sizeof (*vector));
    vector -> size = 0;
    vector -> capacity = VECTOR_INIT_CAP;
    vector -> contents = malloc (sizeof (*(vector -> contents)) * (vector -> capacity));
    return vector;
}

void vector_inc_capacity(struct Vector *v) {
    if (v == NULL) { exit(1); }
    v -> capacity = (v -> capacity) * INC_FACTOR;
    v -> contents = realloc (v -> contents,
        sizeof (*(v -> contents)) * (v -> capacity));
}

int vector_size(struct Vector *v) {
    if (v == NULL) { exit(1); }
    return (v -> size);
}

int vector_capacity(struct Vector *v) {
    if (v == NULL) { exit(1); }
    return (v -> capacity);
}

int vector_is_empty(struct Vector *v) {
    if (v == NULL) { exit(1); }
    return ((v -> size) == 0);
}

double vector_get(struct Vector *v, int i) {
    if (v == NULL) { exit(1); }
    if (i < 0 || i > (v -> size)) {
        exit(1);
    }
    return (v -> contents)[i];
}

double vector_front(struct Vector *v) {
    if (v == NULL) { exit(1); }
    if ((v -> size) == 0) {
        exit(1);
    }
    return (v -> contents)[0];
}

double vector_back(struct Vector *v) {
    if (v == NULL) { exit(1); }
    if ((v -> size) == 0) {
        exit(1);
    }
    return (v -> contents)[(v -> size) - 1];
}

void vector_push_back(struct Vector *v, double x) {
    if (v == NULL) { exit(1); }
    if ((v -> size) == (v -> capacity)) {
        vector_inc_capacity(v);
    }
    (v -> contents)[(v -> size)++] = x;
}

double vector_pop_back(struct Vector *v) {
    if (v == NULL) { exit(1); }
    if ((v -> size) == 0) {
        exit(1);
    }
    double retval = vector_back(v);
    --(v -> size);
    return retval;
}

void vector_insert(struct Vector *v, double x, int i) {
    if (v == NULL) { exit(1); }
    if (i < 0 || i > (v -> size)) {
        exit(1);
    }
    if ((v -> size) == (v -> capacity)) {
        vector_inc_capacity(v);
    }
    int j;
    for (j = (v -> size); j > i; --j) {
        (v -> contents)[j] = (v -> contents)[j - 1];
    }
    (v -> contents)[i] = x;
    ++(v -> size);
}

void vector_remove_element(struct Vector *v, int i) {
    if (v == NULL) { exit(1); }
    if (i < 0 || i > (v -> size)) {
        exit(1);
    }
    int j;
    for (j = i; j < (v -> size) - 1; ++j) {
        (v -> contents)[j] = (v -> contents)[j + 1];
    }
    --(v -> size);
}

void vector_set_element(struct Vector *v, double x, int i) {
    if (v == NULL) { exit(1); }
    if (i < 0 || i > (v -> size)) {
        exit(1);
    }
    (v -> contents)[i] = x;
}

void vector_clear(struct Vector *v) {
    v -> size = 0;
}

void *vector_destroy(struct Vector *v) {
    free(v -> contents);
    free(v);
    return NULL;
}

void vector_print(struct Vector *v) {
    int i;
    for (i = 0; i < (v -> size); ++i) {
        printf("%f ", (v -> contents)[i]);
    }
}