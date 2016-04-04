/*
 * linked-list.c
 *
 * Linked List Data Structure
 *
 * Author: Alexander Chan <alechan@seas.upenn.edu>
 *
 * This file implements a linked list data structure. It supports
 * prepend, adding an element to the beginning of the list, append,
 * adding an element to the end of the list, delete, finding and
 * deleting an element, and apply, applying a function to every element
 * in the list.
 */

#include <stdlib.h>
#include <stdio.h>

#include "linked-list.h"

struct Node {
	double data;
	struct Node *next;
};

struct Node *ll_prepend(struct Node *list, double x) {
	struct Node *node = malloc (sizeof *node);
	node->data = x;
	node->next = list;
	return node;
}

void ll_append(struct Node *list, double x) {
	if (list->next == NULL) {
		struct Node *node = malloc (sizeof *node);
		list->next = node;
		node->data = x;
		node->next = NULL;
	} else {
		ll_append(list->next, x);
	}
}

void ll_delete(struct Node *list, double x) {
	if (list->next->data == x) {
		struct Node *rest = list->next->next;
		free(list->next);
		list->next = rest;
	} else {
		ll_delete(list->next, x);
	}
}

void ll_print(struct Node *list) {
	struct Node *node = list;
	while (node) {
		printf(" %g ", node->data);
		node = node->next;
	}
}

void ll_apply(struct Node *list, double (*f)(double)) {
	if (list) {
		list->data = f(list->data);
		ll_apply(list->next, f);
	}
}
