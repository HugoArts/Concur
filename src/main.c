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

    /* check that make_instr and get_ funcs work ok */
    instr i = make_instr(NOP, 1, 2, 3);
    assert(get_op(i) == NOP);
    assert(getarg_A(i) == 1);
    assert(getarg_B(i) == 2);
    assert(getarg_C(i) == 3);

    printf("yay! All checks passed successfully\n");
}
