// Linked List
#include <stdlib.h>
#include <stdio.h>

struct Node {
	double data;
	struct Node *next;
};

struct ListHead {
	struct Node *next;
}

struct Node *prepend(struct Node *list, double x) {
	struct Node *node = (struct Node *) malloc (sizeof (struct Node));

	node -> data = x;
	node -> next = list;
	return node;
}

void append(struct Node *list, double x) {
	if (list -> next == NULL) {
		struct Node *node = (struct Node *) malloc (sizeof (struct Node));
		list -> next = node;
		node -> data = x;
		node -> next = NULL;
	} else {
		append(list -> next, x);
	}
}

void delete(struct Node *list, double x) {
	if (list -> next -> data == x) {
		struct Node *rest = list -> next -> next;
		free(list -> next);
		list -> next = rest;
	} else {
		delete(list -> next, x);
	}
}

void print(struct Node *list) {
	struct Node *node = list;
	while (node) {
		printf(" %g ", node -> data);
		node = node -> next;
	}
}

void apply(struct Node *list, double (*f)(double)) {
	if (list) {
		list -> data = f(list -> data);
		apply(list -> next, f)
	}
}

void apply(struct Node *list, double (*f)(double)) {
	struct Node *node = list;
	while (node) {
		node -> data = f(node -> data);
		node = node -> next;
	}
}