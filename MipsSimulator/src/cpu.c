#include "../include/cpu.h"
#include <string.h>
#include <assert.h>
#include "../include/types.h"

uint32_t reg[MAX_REG_SIZE];
uint32_t pc;
uint32_t hi;
uint32_t lo;

void init_reg(uint32_t pc_start, uint32_t gp_start, uint32_t sp_start) {
	int i = 0;
	for (i = 0; i < MAX_REG_SIZE; ++i) {
		reg[i] = 0;
	}
	pc = pc_start;
	hi = 0;
	lo = 0;
	//gp
	reg[28] = gp_start;
	//sp
	reg[29] = sp_start;
}

void reg_write(uint32_t index, uint32_t data, size_t len) {
	assert(0 <= index && index < MAX_REG_SIZE);
	assert(len == 1 || len == 2 || len == 4);
	memcpy(&reg[index], &data, len);
}

uint32_t reg_read(uint32_t index, size_t len) {
	assert(0 <= index && index < MAX_REG_SIZE);
	assert(len == 1 || len == 2 || len == 4);
	uint32_t res = 0;
	memcpy(&res, &reg[index], len);
	return res;
}