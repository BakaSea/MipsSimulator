#include "../include/memory.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/types.h"

uint32_t mmu_size = 0x8000;
uint8_t* mmu = NULL;

void init_memory(uint32_t size) {
	mmu_size = size;
	mmu = (uint8_t*)malloc(mmu_size * sizeof(uint8_t));
	if (mmu == NULL) {
		assert(0);
	} else {
		memset(mmu, 0, mmu_size * sizeof(uint8_t));
	}
}

void release_memory() {
	free(mmu);
}

void mmu_write(uint32_t addr, uint32_t data, size_t len) {
	assert(0 <= addr && addr + len <= mmu_size);
	assert(len == 1 || len == 2 || len == 4);
	memcpy(mmu + addr, &data, len);
}

uint32_t mmu_read(uint32_t addr, size_t len) {
	assert(0 <= addr && addr + len <= mmu_size);
	assert(len == 1 || len == 2 || len == 4);
	uint32_t res = 0;
	memcpy(&res, mmu + addr, len);
	return res;
}
