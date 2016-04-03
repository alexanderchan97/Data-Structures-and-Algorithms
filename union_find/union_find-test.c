#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "union_find.h"

int main(int argc, char **argv) {
    struct UnionFind *uf = union_find_init(5);
    int i;
    for (i = 0; i < 5; ++i) {
        assert(union_find_find(uf, i + 1) == i + 1);
    }
    union_find_union(uf, 1, 2);
    assert(union_find_find(uf, 1) == 1);
    assert(union_find_find(uf, 2) == 1);

    union_find_union(uf, 1, 3);
    assert(union_find_find(uf, 1) == 1);
    assert(union_find_find(uf, 2) == 1);
    assert(union_find_find(uf, 3) == 1);

    printf("All tests passed.\n");
    return 0;
}
