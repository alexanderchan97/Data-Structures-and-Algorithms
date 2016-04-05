/*
 * stack.c
 * 
 * Stack Abstract Data Structure
 *
 * Author: Alexander Chan <alechan@seas.upenn.edu>
 *
 * This file implements a stack data structure. This structure
 * supports two operations. First, a push, adding a value to the
 * top of the stack, and second, a pop, removing the top most element
 * and returning its value.
 */

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *head;
};

struct Stack *stack_init() {
    struct Stack *stack = malloc (sizeof *stack);
    stack->head = NULL;
    return stack;
}

int stack_isEmpty(struct Stack *s) {
    if (s->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void stack_push(struct Stack *stack, int x) {
    struct Node *node = malloc (sizeof *node);
    node->data = x;
    node->next = stack->head;
    stack->head = node;
}

int stack_pop(struct Stack *s) {
    struct Node *elem_to_pop = s->head;
    s->head = elem_to_pop->next;
    int ret = elem_to_pop->data;
    free(elem_to_pop);
    return ret;
}

struct Stack *stack_free(struct Stack *s) {
    while (!stack_isEmpty(s)) {
        stack_pop(s);
    }
    free(s);
    return NULL;
}
