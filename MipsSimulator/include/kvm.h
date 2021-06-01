#pragma once
#include <string.h>
#include "types.h"

#define MAX_BUFFER_SIZE 512

void loadMain(uint32_t text_addr, char* text_path, uint32_t data_addr, char* data_path, uint32_t mmu_size, uint32_t pc_start, uint32_t gp_start, uint32_t sp_start);
void run();