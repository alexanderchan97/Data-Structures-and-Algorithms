/*******************************************************************************

Queue (Doubly Linked List)

Supports two operations:
    - push(double x, struct Queue *list)
    - pop(struct Queue *list)

*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Node {
	double data;
	struct Node *next;
	struct Node *prev;
};

struct Queue {
	struct Node *head;
	struct Node *tail;
};

void push(double x, struct Queue *list) {
	
	struct Node *node = (struct Node *) malloc (sizeof (struct Node));
	node -> data = x;

	if (!list) {
		struct Queue *queue = (struct Queue *) malloc (sizeof (struct Queue));
		push(x, queue);
	}

	if (list -> tail) {
		list -> tail -> next = node;
		node -> prev = list -> tail;
		node -> next = NULL;
		list -> tail = node;
	} else {
		node -> next = NULL;
		node -> prev = NULL;
		list -> head = node;
		list -> tail = node;
	}
}

double pop(struct Queue *list) {
	if (struct Node elem_to_pop = list -> head) {
		list -> head = elem_to_pop -> next;
		if (!list -> head) {
			list -> tail = NULL;
		} else {
			list -> head -> prev = NULL;
		}
		double ret_data = elem_to_pop -> data;
		free(elem_to_pop);
		return ret_data;
	} else {
		return NULL;
	}
}

int main(int argc, char **argv) {

	struct Queue *queue = NULL;
	push(1, queue);
	push(2, queue);
	push(3, queue);
	assert(pop(queue) == 1);
	assert(pop(queue) == 2);
	push(1, queue);
	assert(pop(queue) == 3);
	assert(pop(queue) == 1);
	assert(pop(queue) == NULL);

	printf("All tests passed.\n");
	return 0;

}