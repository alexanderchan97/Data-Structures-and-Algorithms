/*
 * linked-list.h
 *
 * Linked List Data Structure
 *
 * Author: Alexander Chan <alechan@seas.upenn.edu>
 *
 * This file is a header file for linked-list.c, the implementation
 * of a linked list data structure.
 */

struct Node;

struct Node *ll_prepend(struct Node *list, double x);

void ll_append(struct Node *list, double x);

void ll_delete(struct Node *list, double x);

void ll_print(struct Node *list);

void ll_apply(struct Node *list, double (*f)(double));
