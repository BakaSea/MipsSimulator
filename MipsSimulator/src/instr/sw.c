#include "../../include/instr/sw.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include "../../include/memory.h"

make_instr_func(sw) {
	int32_t rs_val = get_rs_val(instr, 4);
	uint32_t rt_val = get_rt_val(instr, 4);
	int32_t imm = sign_ext(get_i_imm(instr), 16);
	mmu_write(rs_val + imm, rt_val, 4);
}