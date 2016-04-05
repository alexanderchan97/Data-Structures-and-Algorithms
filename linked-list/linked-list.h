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
struct List;

struct List *list_init();

int list_prepend(struct List *list, int x);

int list_append(struct List *list, int x);

int list_delete(struct List *list, int x);

char *list_toString(struct List *list);

void list_free(struct List *list);
