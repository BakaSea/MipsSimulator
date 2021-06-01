#include "../../include/instr/bgtz.h"
#include "../../include/types.h"
#include "../../include/utils.h"

extern uint32_t pc;

make_instr_func(bgtz) {
	int32_t rs = get_rs_val(instr, 4);
	int32_t imm = sign_ext(get_i_imm(instr), 16);
	if (rs > 0) {
		pc += imm << 2;
	}
}