#define _CRT_SECURE_NO_WARNINGS
#include "../include/kvm.h"
#include <stdio.h>
#include <string.h>
#include "../include/types.h"
#include "../include/memory.h"
#include "../include/cpu.h"
#include "../include/decode.h"

extern uint8_t* mmu;
extern uint32_t pc;

void loadMain(uint32_t text_addr, char* text_path, uint32_t data_addr, char* data_path, uint32_t mmu_size, uint32_t pc_start, uint32_t gp_start, uint32_t sp_start) {
	FILE* fp = fopen(text_path, "rb");
	if (fp != NULL) {
		init_memory(mmu_size);
		init_reg(pc_start, sp_start, gp_start);
		uint8_t buffer[MAX_BUFFER_SIZE];
		size_t size = 0;
		int i = 0;
		uint32_t addr = text_addr;
		do {
			memset(buffer, 0, MAX_BUFFER_SIZE);
			size = fread(buffer, sizeof(uint8_t), MAX_BUFFER_SIZE, fp);
			memcpy(mmu + addr, buffer, size);
			addr += size;
		} while (size == MAX_BUFFER_SIZE);
		fclose(fp);
		if (data_path != NULL) {
			fp = fopen(data_path, "rb");
			if (fp != NULL) {
				fseek(fp, 0, SEEK_END);
				if (ftell(fp) > 0x1000) {
					fclose(fp);
					printf("Data file is too large!\n");
					return;
				}
				fseek(fp, 0, SEEK_SET);
				addr = data_addr;
				do {
					memset(buffer, 0, MAX_BUFFER_SIZE);
					size = fread(buffer, sizeof(uint8_t), MAX_BUFFER_SIZE, fp);
					memcpy(mmu + addr, buffer, size);
					addr += size;
				} while (size == MAX_BUFFER_SIZE);
				fclose(fp);
			} else {
				printf("%s does not exist!\n", data_path);
				return;
			}
		}
		run();
		release_memory();
	} else {
		printf("%s does not exist!\n", text_path);
	}
}

void run() {
	uint32_t instr = mmu_read(pc, 4);
	while (instr) {
		decode(instr);
		pc += 4;
		instr = mmu_read(pc, 4);
	}
}
