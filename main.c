#include <stdio.h>
#include "my_random.h"

int main(){
	for (int i = 0; i < 10; i++) {
		printf("%lld\n", PMrand());
	}
	return 0;
}
