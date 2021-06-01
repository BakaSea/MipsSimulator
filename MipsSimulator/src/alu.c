#include "../include/alu.h"
#include "../include/types.h"
#include "../include/cpu.h"

extern uint32_t hi;

int32_t alu_add(int32_t rs, int32_t rt) {
	int32_t rd = rs + rt;
	return rd;
}

uint32_t alu_addu(uint32_t rs, uint32_t rt) {
	uint32_t rd = rs + rt;
	return rd;
}

int32_t alu_sub(int32_t rs, int32_t rt) {
	int32_t rd = rs - rt;
	return rd;
}

uint32_t alu_subu(uint32_t rs, uint32_t rt) {
	uint32_t rd = rs - rt;
	return rd;
}

uint32_t alu_and(uint32_t rs, uint32_t rt) {
	uint32_t rd = rs & rt;
	return rd;
}

uint32_t alu_or(uint32_t rs, uint32_t rt) {
	uint32_t rd = rs | rt;
	return rd;
}

uint32_t alu_nor(uint32_t rs, uint32_t rt) {
	uint32_t rd = ~(rs | rt);
	return rd;
}

uint32_t alu_xor(uint32_t rs, uint32_t rt) {
	uint32_t rd = rs ^ rt;
	return rd;
}

uint32_t alu_slt(int32_t rs, int32_t rt) {
	uint32_t rd = 0;
	if (rs < rt) rd = 1;
	else rd = 0;
	return rd;
}

uint32_t alu_sltu(uint32_t rs, uint32_t rt) {
	uint32_t rd = 0;
	if (rs < rt) rd = 1;
	else rd = 0;
	return rd;
}

uint32_t alu_sll(uint32_t rt, uint32_t shamt) {
	uint32_t rd = rt << shamt;
	return rd;
}

uint32_t alu_srl(uint32_t rt, uint32_t shamt) {
	uint32_t rd = rt >> shamt;
	return rd;
}

int32_t alu_sra(int32_t rt, uint32_t shamt) {
	int32_t rd = rt >> shamt;
	return rd;
}

uint32_t alu_sllv(uint32_t rs, uint32_t rt) {
	uint32_t rd = rt << rs;
	return rd;
}

uint32_t alu_srlv(uint32_t rs, uint32_t rt) {
	uint32_t rd = rt >> rs;
	return rd;
}

int32_t alu_srav(uint32_t rs, int32_t rt) {
	int32_t rd = rt >> rs;
	return rd;
}

int32_t alu_mul(int32_t rs, int32_t rt) {
	int64_t rd = (int64_t)rs * (int64_t)rt;
	hi = rd >> 32;
	return (int32_t)rd;
}

uint32_t alu_mulu(uint32_t rs, uint32_t rt) {
	uint64_t rd = (uint64_t)rs * (uint64_t)rt;
	hi = rd >> 32;
	return (uint32_t)rd;
}

int32_t alu_div(int32_t rs, int32_t rt) {
	hi = (int32_t)(rs % rt);
	return rs / rt;
}

uint32_t alu_divu(uint32_t rs, uint32_t rt) {
	hi = rs % rt;
	return rs / rt;
}
