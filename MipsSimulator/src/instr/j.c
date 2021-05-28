#include "../../include/instr/j.h"
#include "../../include/types.h"
#include "../../include/utils.h"

make_instr_func(j) {
	uint32_t imm = get_j_imm(instr);
	pc = imm - 4;
}