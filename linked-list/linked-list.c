/*
 * linked-list.c
 *
 * Linked List Data Structure
 *
 * Author: Alexander Chan <alechan@seas.upenn.edu>
 *
 * This file implements a linked list data structure. It supports
 * prepend, adding an element to the beginning of the list, append,
 * adding an element to the end of the list, and elete, finding and
 * deleting the first occurence of an element.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "linked-list.h"

struct Node {
	int data;
	struct Node *next;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

struct List *list_init() {
    struct List *list = malloc (sizeof *list);
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int list_prepend(struct List *list, int x) {
    if (list == NULL) {
        return 0;
    }
    struct Node *node = malloc (sizeof *node);
    node->data = x;
    node->next = list->head;
    if (list->head == NULL) {
        list->tail = node;
    }
    list->head = node;
    return 1;
}

int list_append(struct List *list, int x) {
    if (list == NULL) {
        return 0;
    }
    struct Node *node = malloc (sizeof *node);
    node->data = x;
    node->next = NULL;
    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    return 1;
}

int del_helper(struct Node *n, int x) {
    if (n->next == NULL) {
        return 0;
    }
    if (n->next->data == x) {
        struct Node *rest = n->next->next;
        free(n->next);
        n->next = rest;
        return 1;
    } else {
        return del_helper(n->next, x);
    }
    return 0;
}

int list_delete(struct List *list, int x) {
    if (list == NULL) {
        return 0;
    }
    if (list->head == NULL) {
        return 0;
    }
    if (list->head == list->tail && list->head->data == x) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else if (list->head->data == x) {
        free(list->head);
        list->head = list->head->next;
    } else {
        return del_helper(list->head, x);
    }
    return 0;
}

char *list_toString(struct List *list) {
    if (list == NULL || list->head == NULL) {
        return "";
    }
    static char ret[250];
    ret[0] = '\0';
    strcat(ret, "[");
    struct Node *curr = list->head;
    while (curr) {
        char tmp[50];
        sprintf(tmp, "%d, ", curr->data);
        strcat(ret, tmp);
        curr = curr->next;
    }
    ret[strlen(ret) - 2] = ']';
    ret[strlen(ret) - 1] = 0;
    return ret;
}

void list_free(struct List *list) {
    if (list == NULL) {
        return;
    }
    struct Node *n = list->head;
    while (n) {
        struct Node *next = n->next;
        free(n);
        n = next;
    }
    free(list);
    return;
}
