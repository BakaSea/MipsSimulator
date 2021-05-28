#include "../include/cpu.h"
#include <string.h>
#include <assert.h>
#include "../include/types.h"

void init_reg() {
	int i = 0;
	for (i = 0; i < MAX_REG_SIZE; ++i) {
		reg[i] = 0;
	}
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