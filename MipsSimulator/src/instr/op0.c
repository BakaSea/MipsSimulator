#include "../../include/instr/op0.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include "../../include/alu.h"
#include "../../include/instr/syscall.h"
#include <assert.h>

extern uint32_t pc;
extern uint32_t hi;
extern uint32_t lo;

make_instr_func(op0) {
	uint32_t rs_val = get_rs_val(instr, 4);
	uint32_t rt_val = get_rt_val(instr, 4);
	uint32_t rd = get_rd(instr);
	uint32_t shamt = get_shamt(instr);
	uint32_t funct = get_funct(instr);
	switch (funct) {
	case 0x18:
		lo = alu_mul(rs_val, rt_val);
		break;
	case 0x19:
		lo = alu_mulu(rs_val, rt_val);
		break;
	case 0x1a:
		lo = alu_div(rs_val, rt_val);
		break;
	case 0x1b:
		lo = alu_divu(rs_val, rt_val);
		break;
	case 0x20:
		reg_write(rd, alu_add(rs_val, rt_val), 4);
		break;
	case 0x21:
		reg_write(rd, alu_addu(rs_val, rt_val), 4);
		break;
	case 0x22:
		reg_write(rd, alu_sub(rs_val, rt_val), 4);
		break;
	case 0x23:
		reg_write(rd, alu_subu(rs_val, rt_val), 4);
		break;
	case 0x24:
		reg_write(rd, alu_and(rs_val, rt_val), 4);
		break;
	case 0x25:
		reg_write(rd, alu_or(rs_val, rt_val), 4);
		break;
	case 0x26:
		reg_write(rd, alu_xor(rs_val, rt_val), 4);
		break;
	case 0x27:
		reg_write(rd, alu_nor(rs_val, rt_val), 4);
		break;
	case 0x2A:
		reg_write(rd, alu_slt(rs_val, rt_val), 4);
		break;
	case 0x2B:
		reg_write(rd, alu_sltu(rs_val, rt_val), 4);
		break;
	case 0x0:
		reg_write(rd, alu_sll(rt_val, shamt), 4);
		break;
	case 0x2:
		reg_write(rd, alu_srl(rt_val, shamt), 4);
		break;
	case 0x3:
		reg_write(rd, alu_sra(rt_val, shamt), 4);
		break;
	case 0x4:
		reg_write(rd, alu_sllv(rs_val, rt_val), 4);
		break;
	case 0x6:
		reg_write(rd, alu_srlv(rs_val, rt_val), 4);
		break;
	case 0x7:
		reg_write(rd, alu_srav(rs_val, rt_val), 4);
		break;
	case 0x8:
		pc = rs_val - 4;
		break;
	case 0xc:
		syscall(instr);
		break;
	case 0x10:
		reg_write(rd, hi, 4);
		break;
	case 0x12:
		reg_write(rd, lo, 4);
		break;
	default:
		assert(0);
		break;
	}
}