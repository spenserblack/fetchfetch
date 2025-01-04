#include <stdio.h>
#include "art.h"

int main(int argc, char *argv[]) {
	for (int i = 0; i < ART_HEIGHT; i++) {
		printf("%s\n", art[i]);
	}
	return 0;
}
