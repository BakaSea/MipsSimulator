#include "../../include/instr/bltz.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include <assert.h>

extern uint32_t pc;

make_instr_func(bltz) {
	int32_t rs = get_rs_val(instr, 4);
	uint32_t rd = get_rd(instr);
	int32_t imm = sign_ext(get_i_imm(instr), 16);
	if (rd == 0x00000) {
		if (rs < 0) {
			pc += imm << 2;
		}
	} else if (rd == 0x00001) {
		if (rs >= 0) {
			pc += imm << 2;
		}
	} else {
		assert(0);
	}
}