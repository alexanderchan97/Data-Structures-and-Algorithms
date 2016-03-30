/*******************************************************************************

Red-Black Tree

*******************************************************************************/

#include <stdio.h>

#include "rb_tree.h"

enum color_type { RED, BLACK };

struct RB_Node {
	enum color_type color;
	struct RB_Node *parent;
	struct RB_Node *left;
	struct RB_Node *right;
};