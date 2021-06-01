#pragma once
#include "types.h"

#define MAX_REG_SIZE 32
void init_reg(uint32_t pc_start, uint32_t gp_start, uint32_t sp_start);
void reg_write(uint32_t index, uint32_t data, size_t len);
uint32_t reg_read(uint32_t index, size_t len);
