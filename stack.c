/******************************************************************************

Stack (Singly Linked List)

Supports two operations:
    - push(double x, struct Stack *stack)
        adds value x onto the top of the stack

    - pop(struct Stack *stack)
        removes head element from the stack and returns its associated
        data value

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Node {
    double data;
    struct Node *next;
};

struct Stack {
    struct Node *head;
};

struct Stack *create_stack() {
    struct Stack *stack = (struct Stack *) malloc (sizeof (struct Stack));
    stack -> head = NULL;
    return stack;
}

int is_empty(struct Stack *stack) {
    if (stack -> head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(double x, struct Stack *stack) {

    struct Node *node = (struct Node *) malloc (sizeof (struct Node));
    node -> data = x;
    node -> next = stack -> head;
    stack -> head = node;

}

double pop(struct Stack *stack) {

    assert(!is_empty(stack));
    struct Node *elem_to_pop = stack -> head;
    stack -> head = elem_to_pop -> next;
    double ret_data = elem_to_pop -> data;
    free(elem_to_pop);
    return ret_data;

}

struct Stack *remove_stack(struct Stack *stack) {

    while(!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
    return NULL;

}

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
