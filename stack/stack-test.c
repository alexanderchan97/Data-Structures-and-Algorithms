#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(int argc, char **argv) {
    struct Stack *stack = create_stack();
	push(1, stack);
	push(2, stack);
	push(3, stack);
	assert(pop(stack) == 3);
	assert(pop(stack) == 2);
	push(1, stack);
	assert(pop(stack) == 1);
	assert(pop(stack) == 1);

    assert(remove_stack(stack) == NULL);

    printf("All tests passed.\n");
    return 0;
}
