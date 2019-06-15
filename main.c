#include <stdio.h>
#include "my_random.h"

int main(){
	for (int i = 0; i < 10; i++) {
		printf("%lld\n", PMrand());
	}
	
	for (int i = 0; i < 10; i++) {
		printf("%lu\n", MTrand());
	}
	return 0;
}
