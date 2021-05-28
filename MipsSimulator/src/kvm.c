#define _CRT_SECURE_NO_WARNINGS
#include "../include/kvm.h"
#include <stdio.h>
#include <string.h>
#include "../include/types.h"
#include "../include/memory.h"
#include "../include/cpu.h"
#include "../include/decode.h"

void loadMain(char* path) {
	FILE* fp = fopen(path, "r");
	if (fp != NULL) {
		init_memory();
		init_reg();
		uint8_t buffer[MAX_BUFFER_SIZE];
		size_t size = 0;
		int i = 0;
		uint32_t addr = 0;
		do {
			memset(buffer, 0, MAX_BUFFER_SIZE);
			size = fread(buffer, sizeof(uint8_t), MAX_BUFFER_SIZE, fp);
			memcpy(mmu + addr, buffer, size);
			addr += size;
		} while (size == MAX_BUFFER_SIZE);
		fclose(fp);
		pc = 0;
		run();
	} else {
		printf("文件不存在！\n");
	}
}

void run() {
	uint32_t instr = mmu_read(pc, 4);
	while (instr) {
		decode(instr);
		pc += 4;
	}
}
