#ifndef __RB_TREE_H__
#define __RB_TREE_H__

struct RB_Node;

struct RB_Node *rb_init();
int rb_size(struct RB_Node *);
int rb_height(struct RB_Node *);
int rb_is_empty(struct RB_Node *);
int rb_is_valid(struct RB_Node *);
int rb_exists(struct RB_Node *, double);
struct RB_Node *rb_grandparent(struct RB_Node *);
struct RB_Node *rb_uncle(struct RB_Node *);
void rb_insert(struct RB_Node *, double);
void rb_delete(struct RB_Node *, double);
void rb_rotate_left(struct RB_Node *);
void rb_rotate_right(struct RB_Node *);
void rb_in_order_print(struct RB_Node *);

#endif // __RB_TREE_H__