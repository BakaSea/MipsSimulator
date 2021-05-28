#include "../../include/instr/addiu.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include "../../include/alu.h"

make_instr_func(addiu) {
	uint32_t rs_val = get_rs_val(instr, 4);
	uint32_t rt = get_rt(instr);
	uint32_t imm = get_i_imm(instr);
	reg_write(rt, alu_addu(rs_val, imm), 4);
}