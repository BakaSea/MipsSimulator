#pragma once
#include "types.h"

#define MAX_MEMORY_SIZE 512*1024*1024
uint8_t mmu[MAX_MEMORY_SIZE];

void init_memory();
void mmu_write(uint32_t addr, uint32_t data, size_t len);
uint32_t mmu_read(uint32_t addr, size_t len);