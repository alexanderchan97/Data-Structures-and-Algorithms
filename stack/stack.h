/*
 * stack.h
 *
 * Stack Abstract Data Structure
 *
 * Author: Alexander Chan <alechan@seas.upenn.edu>
 *
 * This file is a header file for stack.c, the implementation
 * of a stack data structure.
 */

struct Node;
struct Stack;

struct Stack *stack_init();

int stack_isEmpty(struct Stack *s);

void stack_push(struct Stack *stack, int x);

int stack_pop(struct Stack *s);

struct Stack *stack_free(struct Stack *s);
