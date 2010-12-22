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

    /* check that make_instr works ok */
    instr i = make_instr(NOP, 1, 2, 3);
    printf("instruction(%d, %d, %d, %d)\n", get_op(i), getarg_A(i), getarg_B(i), getarg_C(i));
}
