#pragma once
#include "types.h"

int32_t alu_add(int32_t rs, int32_t rt);
uint32_t alu_addu(uint32_t rs, uint32_t rt);
int32_t alu_sub(int32_t rs, int32_t rt);
uint32_t alu_subu(uint32_t rs, uint32_t rt);
uint32_t alu_and(uint32_t rs, uint32_t rt);
uint32_t alu_or(uint32_t rs, uint32_t rt);
uint32_t alu_nor(uint32_t rs, uint32_t rt);
uint32_t alu_xor(uint32_t rs, uint32_t rt);
uint32_t alu_slt(int32_t rs, int32_t rt);
uint32_t alu_sltu(uint32_t rs, uint32_t rt);
uint32_t alu_sll(uint32_t rt, uint32_t shamt);
uint32_t alu_srl(uint32_t rt, uint32_t shamt);
int32_t alu_sra(int32_t rt, uint32_t shamt);
uint32_t alu_sllv(uint32_t rs, uint32_t rt);
uint32_t alu_srlv(uint32_t rs, uint32_t rt);
int32_t alu_srav(uint32_t rs, int32_t rt);