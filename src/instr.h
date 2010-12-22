#ifndef INSTR_H
#define INSTR_H

#include <stdint.h>

/* bit lengths and positions of various parts of an instruction.
 * NOTE: shouldn't add up to more than 32 bits */
#define SIZE_OP 5
#define SIZE_A  9
#define SIZE_B  9
#define SIZE_C  9

#define POS_OP 0
#define POS_A  (POS_OP + SIZE_OP)
#define POS_B  (POS_A + SIZE_A)
#define POS_C  (POS_B + SIZE_B)

typedef uint32_t instr ;
typedef enum {
    NOP,
    MOVE,
    LOAD,
    INCR,
    DECR,
} opcode;

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
