#include <stdio.h>
#include <stdlib.h>

struct UnionFind {
    struct Node *sets;
};

struct Node {
    struct Node *parent;
    int rank;
    int val;
};

struct UnionFind *union_find_init(int i) {
    struct UnionFind *uf = malloc (sizeof (*uf));
    uf->sets = malloc (sizeof (struct Node) * i);
    int j = 0;
    for (j = 0; j < i; ++j) {
        uf->sets[j].val = j;
        uf->sets[j].parent = NULL;
        uf->sets[j].rank = 0;
    }
    return uf;
}

int union_find_find(struct UnionFind *uf, int s) {
    if (uf->sets[s].parent == NULL) {
        return s;
    }
    uf->sets[s].parent = &uf->sets[union_find_find(uf, uf->sets[s].parent->val)];
    return uf->sets[s].parent->val;
}

void union_find_union(struct UnionFind *uf, int s, int t) {
    int sRoot = union_find_find(uf, s);
    int tRoot = union_find_find(uf, t);
    if (sRoot == tRoot) {
        return;
    }
    if (uf->sets[sRoot].rank < uf->sets[tRoot].rank) {
        uf->sets[sRoot].parent = &uf->sets[tRoot];
    } else if (uf->sets[tRoot].rank < uf->sets[sRoot].rank) {
        uf->sets[tRoot].parent = &uf->sets[sRoot];
    } else {
        uf->sets[tRoot].parent = &uf->sets[sRoot];
        uf->sets[sRoot].rank = uf->sets[sRoot].rank + 1;
    }
}
