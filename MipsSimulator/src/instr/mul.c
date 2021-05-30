#include "../../include/instr/inv.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include "../../include/alu.h"

make_instr_func(mul) {
	int32_t rs_val = get_rs_val(instr, 4);
	int32_t rt_val = get_rt_val(instr, 4);
	uint32_t rd = get_rd(instr);
	reg_write(rd, alu_mul(rs_val, rt_val), 4);
}