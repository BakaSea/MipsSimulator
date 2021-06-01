#include "../../include/instr/beq.h"
#include "../../include/types.h"
#include "../../include/utils.h"

extern uint32_t pc;

make_instr_func(beq) {
	uint32_t rs_val = get_rs_val(instr, 4);
	uint32_t rt_val = get_rt_val(instr, 4);
	int32_t imm = sign_ext(get_i_imm(instr), 16);
	if (rs_val == rt_val) {
		pc += imm << 2;
	}
}