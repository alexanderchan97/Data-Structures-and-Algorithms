#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

struct UnionFind;
struct Node;

struct UnionFind *union_find_init(int);

void union_find_union(struct UnionFind *, int, int);

int union_find_find(struct UnionFind *, int);

#endif // __UNION_FIND_H__
