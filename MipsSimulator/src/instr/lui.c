#include "../../include/instr/lui.h"
#include "../../include/types.h"
#include "../../include/utils.h"

make_instr_func(lui) {
	uint32_t rt = get_rt(instr);
	uint32_t imm = get_i_imm(instr);
	reg_write(rt, imm << 16, 4);
}