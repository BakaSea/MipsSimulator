#include <stdio.h>
#include <string.h>
#include "include/kvm.h"

int main(int argc, char *argv[]) {
	if (argc > 1) {
		if (argc == 2) loadMain(argc-1, argv[1], "");
		else if (argc == 3) loadMain(argc-1, argv[1], argv[2]);
		else printf("Parameters error!\n");
	} else {
		printf("No file!\n");
	}
	return 0;
}