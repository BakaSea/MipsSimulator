#pragma once
#include "types.h"

#define MAX_REG_SIZE 32
uint32_t reg[MAX_REG_SIZE];
void init_reg();
void reg_write(uint32_t index, uint32_t data, size_t len);
uint32_t reg_read(uint32_t index, size_t len);

uint32_t pc;
uint32_t hi;
uint32_t lo;