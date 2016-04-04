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

struct Stack *create_stack();

int is_empty(struct Stack *);

void push(double, struct Stack *);

double pop(struct Stack *);

struct Stack *remove_stack(struct Stack *);
