#ifndef INSTR_H
#define INSTR_H

#include <stdint.h>

/* The instruction type is 32 bits long */
typedef uint32_t instr ;

/* The list of opcodes */
typedef enum {
    NOP,
    MOVE,
    LOAD,
    INCR,
    DECR,
} opcode;

/* bit lengths and positions of various parts of an instruction.
 * NOTE: should add up to 32 bits */
const int SIZE_OP = 5;
const int SIZE_A = 9;
const int SIZE_B = 9;
const int SIZE_C = 9;

const int POS_OP = 0;
const int POS_A = 5;
const int POS_B = 14;
const int POS_C = 23;

/* create a mask of 1's or 0's respectively, of length x.
 * starts with 0, inverts all bits to 1, shifts in x 0's.
 * invert again for mask1, leave as is for mask0. */
static inline instr mask1(int x) { return ~(~(instr)0 << x); }
static inline instr mask0(int x) { return ~(instr)0 << x; }

/* functions for creating and decoding instructions */
static inline instr make_instr(opcode op, int A, int B, int C) {
    return ((instr) op << POS_OP) | 
           ((instr) A << POS_A) | 
           ((instr) B << POS_B) | 
           ((instr) C << POS_C);
}

static inline opcode get_op(instr i) { return (opcode) ((i >> POS_OP) & mask1(SIZE_OP)); }
static inline int getarg_A(instr i) { return (int) ((i >> POS_A) & mask1(SIZE_A)); }
static inline int getarg_B(instr i) { return (int) ((i >> POS_B) & mask1(SIZE_B)); }
static inline int getarg_C(instr i) { return (int) ((i >> POS_C) & mask1(SIZE_C)); }

#endif
