#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UnionFind {
    struct Node *sets;
    int size;
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
    uf->size = i;
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

int getSize(struct UnionFind *uf) {
    return uf->size;
}

char *toString(struct UnionFind *uf) {
    int size = getSize(uf);
    char tmp[80][size];
    int exists[size];
    int i = 0;
    for (i = 0; i < size; ++i) {
        tmp[0][i] = 0;
        exists[i] = 0;
    }
    for (i = 0; i < size; ++i) {
        int currRoot = union_find_find(uf, i);
        if (exists[currRoot] == 0) {
            exists[currRoot] = 1;
            sprintf(tmp[currRoot], "%d", i);
        } else {
            char tmpStr[80];
            sprintf(tmpStr, " %d", i);
            strcat(tmp[currRoot], tmpStr);
        }
    }
    static char ret[250];
    for (i = 0; i < size; ++i) {
        if (tmp[i][0] == 0) {
            continue;
        } else {
            strcat(ret, tmp[i]);
            strcat(ret, "; ");
        }
    }
    ret[strlen(ret) - 2] = 0;
    return ret;
}
