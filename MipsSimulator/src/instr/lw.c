#include "../../include/instr/lw.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include "../../include/memory.h"

make_instr_func(lw) {
	int32_t rs_val = get_rs_val(instr, 4);
	uint32_t rt = get_rt(instr);
	int32_t imm = sign_ext(get_i_imm(instr), 16);
	reg_write(rt, mmu_read(rs_val + imm, 4), 4);
}