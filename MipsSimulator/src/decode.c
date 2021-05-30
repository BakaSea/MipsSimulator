#include "../include/decode.h"
#include "../include/types.h"
#include "../include/utils.h"

typedef void (*instr_func)(uint32_t instr);

instr_func opcode_entry[64] = {
	op0, inv, j, jal, beq, bne, inv, inv,
	addi, addiu, slti, sltiu, andi, ori, xori, lui,
	inv, inv, inv, inv, inv, inv, inv, inv,
	inv, inv, inv, inv, mul, inv, inv, inv,
	inv, inv, inv, lw, inv, inv, inv, inv,
	inv, inv, inv, sw, inv, inv, inv, inv,
	inv, inv, inv, inv, inv, inv, inv, inv,
	inv, inv, inv, inv, inv, inv, inv, inv
};

void decode(uint32_t instr) {
	uint32_t opcode = get_opcode(instr);
	opcode_entry[opcode](instr);
}