#include "../include/memory.h"
#include <string.h>
#include <assert.h>
#include "../include/types.h"

void init_memory() {
	int i = 0;
	for (i = 0; i < MAX_MEMORY_SIZE; ++i) {
		mmu[i] = 0;
	}
}

void mmu_write(uint32_t addr, uint32_t data, size_t len) {
	assert(0 <= addr && addr + len <= MAX_MEMORY_SIZE);
	assert(len == 1 || len == 2 || len == 4);
	memcpy(mmu + addr, &data, len);
}

uint32_t mmu_read(uint32_t addr, size_t len) {
	assert(0 <= addr && addr + len <= MAX_MEMORY_SIZE);
	assert(len == 1 || len == 2 || len == 4);
	uint32_t res = 0;
	memcpy(&res, mmu + addr, len);
	return res;
}
