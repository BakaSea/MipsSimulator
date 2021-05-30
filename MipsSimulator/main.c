#include <stdio.h>
#include <string.h>
#include "include/kvm.h"

int main(int argc, char *argv[]) {
	if (argc > 1) {
		loadMain(argv[1]);
	} else {
		printf("No file!\n");
	}
	return 0;
}