/*******************************************************************************

Vector (Dynamic Array)

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define VECTOR_INIT_CAP 10
#define INC_FACTOR 2

struct Vector {
    int size;
    int capacity;
    int *contents;
};

struct Vector *create_vector() {
    struct Vector *vector = (struct Vector *) malloc (sizeof (struct Vector));
    vector -> size = 0;
    vector -> capacity = VECTOR_INIT_CAP;
    vector -> contents = (int *) malloc (sizeof (int) * (vector -> capacity));
    return vector;
}

void inc_capacity(struct Vector *v) {
    v -> capacity = (v -> capacity) * INC_FACTOR;
    v -> contents = (int *) realloc (v -> contents, sizeof (int) * (v -> capacity));
}

void append(int x, struct Vector *v) {
    if ((v -> size) == (v -> capacity)) {
        inc_capacity(v);
    }
    (v -> contents)[(v -> size)++] = x;
}

int get(int i, struct Vector *v) {
    if (i < 0 || i > (v -> size)) {
        exit(1);
    }
    return (v -> contents)[i];
}

void set(int i, int x, struct Vector *v) {
    if (i < 0 || i > (v -> size)) {
        exit(1);
    }
    (v -> contents)[i] = x;
}

struct Vector *remove_vector(struct Vector *v) {
    free(v -> contents);
    return NULL;
}

int main(int argc, char **argv) {
    
    return 0;
}
