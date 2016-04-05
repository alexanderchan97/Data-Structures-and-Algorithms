#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(int argc, char **argv) {
    struct Stack *stack = stack_init();
	stack_push(stack, 1);
	stack_push(stack, 2);
	stack_push(stack, 3);
	assert(stack_pop(stack) == 3);
	assert(stack_pop(stack) == 2);
	stack_push(stack, 1);
	assert(stack_pop(stack) == 1);
	assert(stack_pop(stack) == 1);

    assert(stack_free(stack) == NULL);

    printf("All tests passed.\n");
    return 0;
}
