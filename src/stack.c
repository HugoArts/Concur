#include <stdlib.h>
#include <stddef.h>
#include "stack.h"

int init_stack(stack * s) {
    s->bottom = malloc(INITIAL_STACKSIZE * sizeof *(s->bottom));
    if (s->bottom == NULL) {
        return -1;
    } else {
        s->size = INITIAL_STACKSIZE;
        s->top = s->bottom;
        return 0;
    }
}

void free_stack(stack * s) {
    free(s->bottom);
    s->size = 0;
    s->bottom = s->top = NULL;
}

int grow_stack(stack * s) {
    gcobject * bottom_tmp = s->bottom;
    ptrdiff_t top_tmp = s->top - s->bottom;

    s->bottom = realloc(s->bottom, s->size * 2);
    if (s->bottom == NULL) {
        s->bottom = bottom_tmp;
        return -1;
    }

    s->size *= 2;
    s->top = s->bottom + top_tmp;
    return 0;
}
