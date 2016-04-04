/*
 * union_find.h
 *
 * Union Find (Disjoint Sets) Data Structure
 *
 * Author: Alexander Chan <alechan@seas.upenn.edu>
 *
 * This file is a header file for union_find.c, the implementation
 * of a union find/disjoint set data structure.
 */

#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

struct UnionFind;
struct Node;

struct UnionFind *union_find_init(int);

void union_find_union(struct UnionFind *, int, int);

int union_find_find(struct UnionFind *, int);

char *toString(struct UnionFind *);

#endif // __UNION_FIND_H__
