/******************************************************************************

Stack (Singly Linked List)

Supports two operations:
    - push(double x, struct Stack *stack)
        adds value x onto the top of the stack

    - pop(struct Stack *stack)
        removes head element from the stack and returns its associated
        data value

*******************************************************************************/

struct Node;

struct Stack;

struct Stack *create_stack();

int is_empty(struct Stack *);

void push(double, struct Stack *);

double pop(struct Stack *);

struct Stack *remove_stack(struct Stack *);
