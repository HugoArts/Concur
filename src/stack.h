#ifndef STACK_H
#define STACK_H

const int INITIAL_STACKSIZE = 20;

/* temporary typedef to get it to compile */
typedef int gcobject;

typedef struct {
    gcobject * bottom;
    gcobject * top;
    int size;
} stack;

int init_stack(stack * s);
void free_stack(stack * s);

#endif
