/*******************************************************************************

Queue (Doubly Linked List)

Supports two operations:
    - push(double x, struct Queue *list)
        adds value x onto the end of the queue

    - pop(struct Queue *list)
        removes head element from the queue and returns its associated
        data value

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

struct Queue *create_queue() {
    struct Queue *queue = (struct Queue *) malloc (sizeof (struct Queue));
    queue -> head = NULL;
    queue -> tail = NULL;
    return queue;
}

int is_empty(struct Queue *list) {
    if (list -> head == NULL && list -> tail == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(double x, struct Queue *list) {
	
	struct Node *node = (struct Node *) malloc (sizeof (struct Node));
	node -> data = x;

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

    assert(!is_empty(list));
    struct Node *elem_to_pop = list -> head;
	list -> head = elem_to_pop -> next;
	if (!list -> head) {
		list -> tail = NULL;
	} else {
		list -> head -> prev = NULL;
	}
	double ret_data = elem_to_pop -> data;
	free(elem_to_pop);
	return ret_data;
}

struct Queue *remove_queue(struct Queue *queue) {
    while (!is_empty(queue)) {
        pop(queue);
    }
    free(queue);
    return NULL;
}

int main(int argc, char **argv) {

    struct Queue *queue = create_queue();
	push(1, queue);
	push(2, queue);
	push(3, queue);
	assert(pop(queue) == 1);
	assert(pop(queue) == 2);
	push(1, queue);
	assert(pop(queue) == 3);
	assert(pop(queue) == 1);
    
    assert(remove_queue(queue) == NULL);

	printf("All tests passed.\n");
	return 0;

}
