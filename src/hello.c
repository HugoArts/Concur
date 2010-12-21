/* Testing Makefile */

#include <stdio.h>
#include <assert.h>

#include "instr.h"

void sanity_checks(void);

int main(void) {
    sanity_checks();
    return 0;
}

void sanity_checks(void) {
    printf("Running sanity checks..\n");

    /* make sure opcode and arguments fit in instruction */
    assert((SIZE_OP + SIZE_A + SIZE_B + SIZE_C) <= sizeof(instr) * 8);
}
