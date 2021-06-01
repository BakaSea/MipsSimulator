#include "../../include/instr/jal.h"
#include "../../include/types.h"
#include "../../include/utils.h"

extern uint32_t pc;

make_instr_func(jal) {
	uint32_t imm = get_j_imm(instr);
	reg_write(31, pc + 4, 4);
	pc = (imm << 2) - 4;
}