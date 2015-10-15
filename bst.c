// Binary Search Trees

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
        return node;
	} else if (x < root -> data) {
		root -> left = add(root -> left, x);
	} else if (x > root -> data) {
		root -> right = add(root -> right, x);
	}
	return root;
}

struct Node *lookup(struct Node *root, double x) {
	if (root == NULL) {
        return NULL;
    } else if (x == root -> data) {
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
            struct Node *right_tree = root -> right;
            return right_tree;
		} else if (root -> left && root -> right == NULL) {
            struct Node *left_tree = root -> left;
            return left_tree;
		} else {
            // Promote the minimum element of the right subtree
			struct Node *min_right = tree_min(root -> right);
			min_right -> right = delete(root -> right, min_right -> data);
			min_right -> left = root -> left;
            return min_right;
		}
	} else if (x < root -> data) {
		root -> left = delete(root -> left, x);
		return root;
	} else if (x > root -> data) {
		root -> right = delete(root -> right, x);
        return root;
	}
    return NULL;
}

int tree_size(struct Node *root) {
    if (root) {
        return 1 + tree_size(root -> left) + tree_size(root -> right);
    } else {
        return 0;
    }
}

void inorder_traversal(struct Node *root) {
    if (root) {
        //printf("%g LEFT TREE\n", root-> data);
        inorder_traversal(root -> left);
        printf(" %g ", root -> data);
        //printf("%g RIGHT TREE\n", root -> data);
        inorder_traversal(root -> right);
    }
}

void tree_clear(struct Node *root) {
    if (root) {
        tree_clear(root -> left);
        tree_clear(root -> right);
        free(root);
    }
}

int main(int argc, char **argv) {
    struct Node *bst = add(NULL, 10);
    assert(tree_size(bst) == 1);
    assert(tree_min(bst) -> data == 10);
    assert(tree_max(bst) -> data == 10);
    assert(tree_size(delete(bst, 10)) == 0);
    inorder_traversal(bst);
    printf("\n");

    bst = add(bst, 8);
    assert(tree_size(bst) == 2);
    assert(tree_min(bst) -> data == 8);
    assert(tree_max(bst) -> data == 10);
    inorder_traversal(bst);
    printf("\n");

    bst = add(bst, 12);
    assert(tree_size(bst) == 3);
    assert(tree_min(bst) -> data == 8);
    assert(tree_max(bst) -> data == 12);
    inorder_traversal(bst);
    printf("\n");

    bst = add(bst, 9);
    assert(tree_size(bst) == 4);
    assert(tree_min(bst) -> data == 8);
    assert(tree_max(bst) -> data == 12);
    assert(lookup(bst, 9) -> data == 9);
    assert(lookup(bst, 15) == NULL);
    inorder_traversal(bst);
    printf("\n");

    bst = add(bst, 11);
    inorder_traversal(bst);
    printf("\n");

    bst = delete(bst, 10);
    inorder_traversal(bst);
    printf("\n");

    tree_clear(bst);

    printf("All tests passed.\n");
    return 0;
}
