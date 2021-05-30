#define _CRT_SECURE_NO_WARNINGS
#include "../../include/instr/syscall.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include "../../include/memory.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

make_instr_func(syscall) {
	uint32_t v0 = reg_read(2, 4);
	switch (v0) {
	case 1: {
		//print integer
		int x = reg_read(4, 4);
		printf("%d", x);
		break;
	}
	case 4: {
		//print string
		uint32_t addr = reg_read(4, 4);
		printf("%s", mmu + addr);
		break;
	}
	case 5: {
		//read integer
		int x = 0;
		scanf("%d", &x);
		reg_write(2, x, 4);
		break;
	}
	case 8: {
		//read string
		uint32_t addr = reg_read(4, 4);
		size_t size = reg_read(5, 4);
		scanf("%s", mmu + addr);
		break;
	}
	case 10: {
		exit(0);
		break;
	}
	case 11: {
		//print character
		char c = reg_read(4, 4);
		printf("%c", c);
		break;
	}
	case 12: {
		//read character
		char c = 0;
		while ((c = getchar()) != EOF && c != '\n');
		c = getchar();
		reg_write(2, c, 4);
		break;
	}
	case 17: {
		int32_t res = reg_read(4, 4);
		exit(res);
	}
	default:
		assert(0);
		break;
	}
}