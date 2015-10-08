// Binary Search Trees

#include <stdio.h>
#include <stdlib.h>

struct Node {
	double data;
	struct Node *left;
	struct Node *right;
};

struct Node *add(struct Node *root, double x) {
	if (root == NULL) {
		struct Node *node = (struct Node *) malloc (sizeof (struct Node));
		node -> data = x;
		node -> left = NULL;
		node -> right = NULL;
	} else if (x < root -> data) {
		root -> left = add(root -> left, x);
	} else if (x > root -> data) {
		root -> right = add(root -> right, x);
	}
	return root;
}

struct Node *lookup(struct Node *root, double x) {
	if (x == root -> data) {
		return root;
	} else if (x < root -> data) {
		return lookup(root -> left, x);
	} else if (x > root -> data) {
		return lookup(root -> right, x);
	}
	return NULL;
}

struct Node *tree_max(struct Node *root) {
	if (root == NULL) {
		return NULL;
	}
	struct Node *node = root;
	while (node -> right) {
		node = node -> right;
	}
	return node;
}

struct Node *tree_min(struct Node *root) {
	if (root == NULL) {
		return NULL;
	}
	struct Node *node = root;
	while (node -> left) {
		node = node -> left;
	}
	return node;
}

struct Node *delete(struct Node *root, double x) {
	if (x == root -> data) {
		if (root -> right == NULL && root -> left == NULL) {
			return NULL;
		} else if (root -> right && root -> left == NULL) {
			return root -> right;
		} else if (root -> left && root -> right == NULL) {
			return root -> left;
		} else {
			struct Node *min_right = tree_min(root -> right);
			min_right -> right = delete(root -> right, min_right -> data);
			min_right -> left = root -> left;
			return min_right;
		}
	} else if (x < root -> data) {
		root -> left = delete(root -> left, x);
		return root;
	} else {
		root -> right = delete(root -> right, x);
	}
}