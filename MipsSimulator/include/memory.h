#pragma once
#include "types.h"
#include <stdlib.h>

void init_memory(uint32_t size);
void release_memory();
void mmu_write(uint32_t addr, uint32_t data, size_t len);
uint32_t mmu_read(uint32_t addr, size_t len);