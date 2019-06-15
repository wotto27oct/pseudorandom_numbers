#include <stdio.h>
#include "my_random.h"

int main(){
	printf("LCGs\n");
	for (int i = 0; i < 10; i++) {
		printf("%u\n", PMrand());
	}

	printf("\nMersenne twister\n");
	for (int i = 0; i < 10; i++) {
		printf("%u\n", MTrand());
	}
	
	printf("\nxorshift\n");
	for (int i = 0; i < 10; i++) {
		printf("%u\n", XORrand());
	}
	return 0;
}
