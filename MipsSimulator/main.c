#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "include/kvm.h"
#include "include/types.h"

int main(int argc, char *argv[]) {
	int i = 0;
	char* text_path = NULL, * data_path = NULL;
	uint32_t text_addr = 0x0, data_addr = 0x2000, mmu_size = 0x8000, gp_start = 0x1800, sp_start = 0x3FFC;
	for (i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "-t") == 0) {
			if (i + 1 < argc) {
				text_path = argv[++i];
			} else {
				printf(".text missing!\n");
				return 0;
			}
		} else if (strcmp(argv[i], "-d") == 0) {
			if (i + 1 < argc) {
				data_path = argv[++i];
			} else {
				printf(".data missing!\n");
				return 0;
			}
		} else if (strcmp(argv[i], "-ta") == 0) {
			if (i + 1 < argc) {
				sscanf(argv[++i], "%x", &text_addr);
			} else {
				printf(".text address missing!\n");
				return 0;
			}
		} else if (strcmp(argv[i], "-da") == 0) {
			if (i + 1 < argc) {
				sscanf(argv[++i], "%x", &data_addr);
			} else {
				printf(".data address missing!\n");
				return 0;
			}
		} else if (strcmp(argv[i], "-m") == 0) {
			if (i + 1 < argc) {
				sscanf(argv[++i], "%x", &mmu_size);
			} else {
				printf("Memory size missing!\n");
				return 0;
			}
		} else if (strcmp(argv[i], "-gp") == 0) {
			if (i + 1 < argc) {
				sscanf(argv[++i], "%x", &gp_start);
			} else {
				printf("$gp missing!\n");
				return 0;
			}
		} else if (strcmp(argv[i], "-sp") == 0) {
			if (i + 1 < argc) {
				sscanf(argv[++i], "%x", &sp_start);
			} else {
				printf("$sp missing!\n");
				return 0;
			}
		} else {
			printf("Parameters error!\n");
			return 0;
		}
	}
	if (text_path == NULL) {
		printf(".text missing!\n");
	} else {
		loadMain(text_addr, text_path, data_addr, data_path, mmu_size, text_addr, gp_start, sp_start);
	}
	return 0;
}