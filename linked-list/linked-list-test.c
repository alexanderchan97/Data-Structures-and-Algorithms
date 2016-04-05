#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked-list.h"

int main(int argc, char **argv) {

    struct List *list = list_init();
    assert(1 == list_append(list, 0));
    assert(1 == list_append(list, 1));
    printf("Current state is %s. Should be [0, 1].\n", list_toString(list));

    assert(0 == list_delete(list, 5));
    printf("Current state is %s. Should be [0, 1].\n", list_toString(list));

    assert(1 == list_prepend(list, 2));
    printf("Current state is %s. Should be [2, 0, 1].\n", list_toString(list));

    assert(1 == list_delete(list, 0));
    printf("Current state is %s. Should be [2, 1].\n", list_toString(list));

    list_free(list);

    printf("All tests passed.\n");
    return 0;
}
