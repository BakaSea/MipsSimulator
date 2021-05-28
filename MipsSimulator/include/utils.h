#pragma once
#include "types.h"
#include "cpu.h"

#define make_instr_func(instr_name) void instr_name(uint32_t instr)

#define get_opcode(instr) ((instr >> 26) & 0x3F)
#define get_rs(instr) (((instr) >> 21) & 0x1F)
#define get_rs_val(instr, len) (reg_read(get_rs(instr), len))
#define get_rt(instr) (((instr) >> 16) & 0x1F)
#define get_rt_val(instr, len) (reg_read(get_rt(instr), len))
#define get_rd(instr) (((instr) >> 11) & 0x1F)
#define get_shamt(instr) (((instr) >> 6) & 0x1F)
#define get_funct(instr) ((instr) & 0x3F)
#define get_i_imm(instr) ((instr) & 0xFFFF)
#define get_j_imm(instr) ((instr) & 0x3FFFFFF)

inline int32_t sign_ext(int32_t data, size_t size) {
	int32_t sign = data >> (size - 1);
	if (sign) {
		return (0xFFFFFFFF << size) | data;
	} else {
		return data;
	}
}